# Copyright 2018 Brian T. Park
#
# MIT License
"""
Generate the internal versions of zone_infos.py and zone_policies.py directly
instead of creating files. These maps can be used for further processing.
"""

import logging
from typing import Dict
from typing import List
from typing import Tuple
from typing import Union
from typing_extensions import TypedDict
from zonedb.data_types import ZonesMap
from zonedb.data_types import PoliciesMap
from tzdb.transformer import normalize_name

# These are the data structures written out to 'zone_policies.py' and
# 'zone_infos.py' by pygenerator.py.

ZoneRule = TypedDict(
    'ZoneRule', {
        'fromYear': int,
        'toYear': int,
        'inMonth': int,
        'onDayOfWeek': int,
        'onDayOfMonth': int,
        'atSeconds': int,
        'atTimeSuffix': str,
        'deltaSeconds': int,
        'letter': str,
    })

ZonePolicy = TypedDict(
    'ZonePolicy', {
        'name': str,
        'rules': List[ZoneRule],
    })

ZonePolicyMap = Dict[str, ZonePolicy]

ZoneEra = TypedDict(
    'ZoneEra', {
        'offsetSeconds': int,
        'zonePolicy': Union[ZonePolicy, str],  # '-', ':', or ZonePolicy
        'rulesDeltaSeconds': int,
        'format': str,
        'untilYear': int,
        'untilMonth': int,
        'untilDay': int,
        'untilSeconds': int,
        'untilTimeSuffix': str,
    })

ZoneInfo = TypedDict(
    'ZoneInfo', {
        'name': str,
        'eras': List[ZoneEra],
    })

ZoneInfoMap = Dict[str, ZoneInfo]


class InlineZoneInfo:
    """Generate Python zone infos and policies maps inlined (instead of files).
    """

    def __init__(self, zones_map: ZonesMap, policies_map: PoliciesMap):
        """
        Args:
            zones_map (dict): {full_name -> ZoneEra[]}
            policies_map (dict): {policy_name -> ZoneRules[]}
        """
        self.zones_map = zones_map
        self.policies_map = policies_map

        self.zone_infos: ZoneInfoMap = {}
        self.zone_policies: ZonePolicyMap = {}

    def generate_zonedb(self) -> Tuple[ZoneInfoMap, ZonePolicyMap]:
        """Return the zone_infos and zone_policies maps which look identical
        to the zone_infos.py and zone_policies.py generated by PythonGenerator.
        """
        logging.info('Generating inlined zone_policies and zone_infos')
        self._generate_policies()
        self._generate_infos()
        return (self.zone_infos, self.zone_policies)

    def _generate_policies(self) -> None:
        for name, rules in self.policies_map.items():
            policy_rules: List[ZoneRule] = []
            for rule in rules:
                # yapf: disable
                policy_rules.append({
                    'fromYear': rule['fromYear'],
                    'toYear': rule['toYear'],
                    'inMonth': rule['inMonth'],
                    'onDayOfWeek': rule['onDayOfWeek'],
                    'onDayOfMonth': rule['onDayOfMonth'],
                    'atSeconds': rule['atSecondsTruncated'],
                    'atTimeSuffix': rule['atTimeSuffix'],
                    'deltaSeconds': rule['deltaSecondsTruncated'],
                    'letter': rule['letter']
                })
                # yapf: enable

            normalized_name = normalize_name(name)
            self.zone_policies[normalized_name] = {
                'name': name,  # policy name
                'rules': policy_rules
            }

    def _generate_infos(self) -> None:
        for zone_name, eras in self.zones_map.items():
            zone_eras: List[ZoneEra] = []
            for era in eras:
                policy_name = era['rules']
                zone_policy: Union[ZonePolicy, str]
                if policy_name in ['-', ':']:
                    zone_policy = policy_name
                else:
                    policy_name = normalize_name(policy_name)
                    zone_policy = self.zone_policies[policy_name]

                # yapf: disable
                zone_eras.append({
                    'offsetSeconds': era['offsetSecondsTruncated'],
                    'zonePolicy': zone_policy,
                    'rulesDeltaSeconds': era['rulesDeltaSecondsTruncated'],
                    'format': era['format'],
                    'untilYear': era['untilYear'],
                    'untilMonth': era['untilMonth'],
                    'untilDay': era['untilDay'],
                    'untilSeconds': era['untilSecondsTruncated'],
                    'untilTimeSuffix': era['untilTimeSuffix'],
                })
                # yapf: enable
            self.zone_infos[zone_name] = {'name': zone_name, 'eras': zone_eras}
