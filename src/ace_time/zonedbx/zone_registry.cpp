// This file was generated by the following script:
//
//   $ ../../../tools/tzcompiler.py
//     --input_dir /home/brian/dev/tz
//     --output_dir /home/brian/src/AceTime/src/ace_time/zonedbx
//     --tz_version 2020f
//     --action zonedb
//     --language arduino
//     --scope extended
//     --start_year 2000
//     --until_year 2050
//
// using the TZ Database files
//
//   africa
//   antarctica
//   asia
//   australasia
//   backward
//   etcetera
//   europe
//   northamerica
//   southamerica
//
// from https://github.com/eggert/tz/releases/tag/2020f
//
// DO NOT EDIT

#include <ace_time/common/compat.h>
#include "zone_infos.h"
#include "zone_registry.h"

namespace ace_time {
namespace zonedbx {

//---------------------------------------------------------------------------
// Zone registry. Sorted by zoneId.
//---------------------------------------------------------------------------
const extended::ZoneInfo* const kZoneRegistry[386] ACE_TIME_PROGMEM = {
  &kZoneAsia_Kuala_Lumpur, // Asia/Kuala_Lumpur - 0x014763c4
  &kZoneIndian_Cocos, // Indian/Cocos - 0x021e86de
  &kZoneAmerica_St_Johns, // America/St_Johns - 0x04b14e6e
  &kZoneAmerica_North_Dakota_New_Salem, // America/North_Dakota/New_Salem - 0x04f9958e
  &kZoneAsia_Jakarta, // Asia/Jakarta - 0x0506ab50
  &kZoneAmerica_Mazatlan, // America/Mazatlan - 0x0532189e
  &kZonePacific_Fakaofo, // Pacific/Fakaofo - 0x06532bba
  &kZoneAmerica_Hermosillo, // America/Hermosillo - 0x065d21c4
  &kZoneAsia_Tbilisi, // Asia/Tbilisi - 0x0903e442
  &kZoneAmerica_Indiana_Tell_City, // America/Indiana/Tell_City - 0x09263612
  &kZoneAmerica_Boa_Vista, // America/Boa_Vista - 0x0a7b7efe
  &kZoneAsia_Colombo, // Asia/Colombo - 0x0af0e91d
  &kZoneCET, // CET - 0x0b87d921
  &kZoneEET, // EET - 0x0b87e1a3
  &kZoneEST, // EST - 0x0b87e371
  &kZoneHST, // HST - 0x0b87f034
  &kZoneMET, // MET - 0x0b8803ab
  &kZoneMST, // MST - 0x0b880579
  &kZoneWET, // WET - 0x0b882e35
  &kZoneAmerica_Guatemala, // America/Guatemala - 0x0c8259f7
  &kZoneAfrica_Monrovia, // Africa/Monrovia - 0x0ce90385
  &kZoneAntarctica_Rothera, // Antarctica/Rothera - 0x0e86d203
  &kZoneAmerica_Yellowknife, // America/Yellowknife - 0x0f76c76f
  &kZoneAustralia_Melbourne, // Australia/Melbourne - 0x0fe559a3
  &kZoneAmerica_Sao_Paulo, // America/Sao_Paulo - 0x1063bfc9
  &kZoneEurope_Amsterdam, // Europe/Amsterdam - 0x109395c2
  &kZoneAmerica_Indiana_Vevay, // America/Indiana/Vevay - 0x10aca054
  &kZoneAmerica_Scoresbysund, // America/Scoresbysund - 0x123f8d2a
  &kZoneAsia_Samarkand, // Asia/Samarkand - 0x13ae5104
  &kZoneAsia_Amman, // Asia/Amman - 0x148d21bc
  &kZoneAsia_Aqtau, // Asia/Aqtau - 0x148f710e
  &kZoneAsia_Chita, // Asia/Chita - 0x14ae863b
  &kZoneAsia_Dhaka, // Asia/Dhaka - 0x14c07b8b
  &kZoneAsia_Dubai, // Asia/Dubai - 0x14c79f77
  &kZoneAmerica_Bahia_Banderas, // America/Bahia_Banderas - 0x14f6329a
  &kZoneAsia_Kabul, // Asia/Kabul - 0x153b5601
  &kZoneAsia_Macau, // Asia/Macau - 0x155f88b9
  &kZoneAsia_Qatar, // Asia/Qatar - 0x15a8330b
  &kZoneAsia_Seoul, // Asia/Seoul - 0x15ce82da
  &kZoneAsia_Tokyo, // Asia/Tokyo - 0x15e606a8
  &kZoneAsia_Tomsk, // Asia/Tomsk - 0x15e60e60
  &kZoneAsia_Thimphu, // Asia/Thimphu - 0x170380d1
  &kZoneAmerica_Guayaquil, // America/Guayaquil - 0x17e64958
  &kZoneAmerica_Kentucky_Louisville, // America/Kentucky/Louisville - 0x1a21024b
  &kZoneAsia_Pontianak, // Asia/Pontianak - 0x1a76c057
  &kZoneAtlantic_Reykjavik, // Atlantic/Reykjavik - 0x1c2b4f74
  &kZoneAmerica_New_York, // America/New_York - 0x1e2a7654
  &kZoneEurope_Luxembourg, // Europe/Luxembourg - 0x1f8bc6ce
  &kZoneAsia_Baku, // Asia/Baku - 0x1fa788b5
  &kZoneAsia_Dili, // Asia/Dili - 0x1fa8c394
  &kZoneAsia_Gaza, // Asia/Gaza - 0x1faa4875
  &kZoneAsia_Hovd, // Asia/Hovd - 0x1fab0fe3
  &kZoneAsia_Omsk, // Asia/Omsk - 0x1faeddac
  &kZoneAsia_Oral, // Asia/Oral - 0x1faef0a0
  &kZoneAsia_Ho_Chi_Minh, // Asia/Ho_Chi_Minh - 0x20f2d127
  &kZoneAsia_Damascus, // Asia/Damascus - 0x20fbb063
  &kZonePacific_Apia, // Pacific/Apia - 0x23359b5e
  &kZonePacific_Fiji, // Pacific/Fiji - 0x23383ba5
  &kZonePacific_Guam, // Pacific/Guam - 0x2338f9ed
  &kZonePacific_Niue, // Pacific/Niue - 0x233ca014
  &kZonePacific_Wake, // Pacific/Wake - 0x23416c2b
  &kZoneAustralia_Adelaide, // Australia/Adelaide - 0x2428e8a3
  &kZonePacific_Auckland, // Pacific/Auckland - 0x25062f86
  &kZonePacific_Tongatapu, // Pacific/Tongatapu - 0x262ca836
  &kZoneAmerica_Monterrey, // America/Monterrey - 0x269a1deb
  &kZoneAustralia_Darwin, // Australia/Darwin - 0x2876bdff
  &kZonePacific_Pohnpei, // Pacific/Pohnpei - 0x28929f96
  &kZoneAsia_Famagusta, // Asia/Famagusta - 0x289b4f8b
  &kZoneAmerica_Indiana_Vincennes, // America/Indiana/Vincennes - 0x28a0b212
  &kZoneAmerica_Indiana_Indianapolis, // America/Indiana/Indianapolis - 0x28a669a4
  &kZoneAsia_Vladivostok, // Asia/Vladivostok - 0x29de34a8
  &kZoneAmerica_Fortaleza, // America/Fortaleza - 0x2ad018ee
  &kZoneAmerica_Vancouver, // America/Vancouver - 0x2c6f6b1f
  &kZoneAmerica_Pangnirtung, // America/Pangnirtung - 0x2d999193
  &kZoneAmerica_Iqaluit, // America/Iqaluit - 0x2de310bf
  &kZonePacific_Chatham, // Pacific/Chatham - 0x2f0de999
  &kZoneAmerica_Indiana_Marengo, // America/Indiana/Marengo - 0x2feeee72
  &kZoneEurope_Tallinn, // Europe/Tallinn - 0x30c4e096
  &kZoneAsia_Ulaanbaatar, // Asia/Ulaanbaatar - 0x30f0cc4e
  &kZoneAmerica_Argentina_Ushuaia, // America/Argentina/Ushuaia - 0x320dcdde
  &kZoneAustralia_Hobart, // Australia/Hobart - 0x32bf951a
  &kZoneAsia_Dushanbe, // Asia/Dushanbe - 0x32fc5c3c
  &kZoneAtlantic_South_Georgia, // Atlantic/South_Georgia - 0x33013174
  &kZoneAmerica_Phoenix, // America/Phoenix - 0x34b5af01
  &kZoneAntarctica_Mawson, // Antarctica/Mawson - 0x399cd863
  &kZoneAmerica_Caracas, // America/Caracas - 0x3be064f4
  &kZoneAmerica_Cayenne, // America/Cayenne - 0x3c617269
  &kZoneAtlantic_Bermuda, // Atlantic/Bermuda - 0x3d4bb1c4
  &kZoneAmerica_Managua, // America/Managua - 0x3d5e7600
  &kZoneAmerica_Argentina_San_Juan, // America/Argentina/San_Juan - 0x3e1009bd
  &kZoneAmerica_Argentina_San_Luis, // America/Argentina/San_Luis - 0x3e11238c
  &kZoneEurope_Volgograd, // Europe/Volgograd - 0x3ed0f389
  &kZoneAmerica_Fort_Nelson, // America/Fort_Nelson - 0x3f437e0f
  &kZoneEtc_GMT_PLUS_10, // Etc/GMT+10 - 0x3f8f1cc4
  &kZoneEtc_GMT_PLUS_11, // Etc/GMT+11 - 0x3f8f1cc5
  &kZoneEtc_GMT_PLUS_12, // Etc/GMT+12 - 0x3f8f1cc6
  &kZoneEtc_GMT_10, // Etc/GMT-10 - 0x3f8f2546
  &kZoneEtc_GMT_11, // Etc/GMT-11 - 0x3f8f2547
  &kZoneEtc_GMT_12, // Etc/GMT-12 - 0x3f8f2548
  &kZoneEtc_GMT_13, // Etc/GMT-13 - 0x3f8f2549
  &kZoneEtc_GMT_14, // Etc/GMT-14 - 0x3f8f254a
  &kZoneAntarctica_Palmer, // Antarctica/Palmer - 0x40962f4f
  &kZoneEurope_Athens, // Europe/Athens - 0x4318fa27
  &kZoneIndian_Kerguelen, // Indian/Kerguelen - 0x4351b389
  &kZoneAmerica_Indiana_Winamac, // America/Indiana/Winamac - 0x4413fa69
  &kZoneEurope_Berlin, // Europe/Berlin - 0x44644c20
  &kZoneIndian_Chagos, // Indian/Chagos - 0x456f7c3c
  &kZoneIndian_Mahe, // Indian/Mahe - 0x45e725e2
  &kZoneAsia_Ust_Nera, // Asia/Ust-Nera - 0x4785f921
  &kZoneEurope_Dublin, // Europe/Dublin - 0x4a275f62
  &kZoneAsia_Nicosia, // Asia/Nicosia - 0x4b0fcf78
  &kZoneAmerica_Chicago, // America/Chicago - 0x4b92b5d4
  &kZoneAustralia_Sydney, // Australia/Sydney - 0x4d1e9776
  &kZoneAntarctica_Vostok, // Antarctica/Vostok - 0x4f966fd4
  &kZoneAustralia_Brisbane, // Australia/Brisbane - 0x4fedc9c0
  &kZoneAmerica_Asuncion, // America/Asuncion - 0x50ec79a6
  &kZoneAsia_Karachi, // Asia/Karachi - 0x527f5245
  &kZonePacific_Gambier, // Pacific/Gambier - 0x53720c3a
  &kZoneAmerica_Whitehorse, // America/Whitehorse - 0x54e0e3e8
  &kZoneAmerica_Martinique, // America/Martinique - 0x551e84c5
  &kZoneAmerica_Jamaica, // America/Jamaica - 0x565dad6c
  &kZoneAsia_Hong_Kong, // Asia/Hong_Kong - 0x577f28ac
  &kZonePacific_Marquesas, // Pacific/Marquesas - 0x57ca7135
  &kZoneAmerica_Miquelon, // America/Miquelon - 0x59674330
  &kZoneAntarctica_DumontDUrville, // Antarctica/DumontDUrville - 0x5a3c656c
  &kZoneAmerica_Anchorage, // America/Anchorage - 0x5a79260e
  &kZoneAsia_Jerusalem, // Asia/Jerusalem - 0x5becd23a
  &kZoneEurope_Stockholm, // Europe/Stockholm - 0x5bf6fbb8
  &kZoneEurope_Lisbon, // Europe/Lisbon - 0x5c00a70b
  &kZoneAtlantic_Cape_Verde, // Atlantic/Cape_Verde - 0x5c5e1772
  &kZoneEurope_London, // Europe/London - 0x5c6a84ae
  &kZoneEurope_Madrid, // Europe/Madrid - 0x5dbd1535
  &kZoneAmerica_Moncton, // America/Moncton - 0x5e07fe24
  &kZonePacific_Bougainville, // Pacific/Bougainville - 0x5e10f7a4
  &kZoneEurope_Monaco, // Europe/Monaco - 0x5ebf9f01
  &kZoneEurope_Moscow, // Europe/Moscow - 0x5ec266fc
  &kZoneAmerica_Argentina_Jujuy, // America/Argentina/Jujuy - 0x5f2f46c5
  &kZoneAmerica_Argentina_Salta, // America/Argentina/Salta - 0x5fc73403
  &kZonePacific_Pago_Pago, // Pacific/Pago_Pago - 0x603aebd0
  &kZonePacific_Enderbury, // Pacific/Enderbury - 0x61599a93
  &kZoneAfrica_Sao_Tome, // Africa/Sao_Tome - 0x61b319d1
  &kZoneAmerica_Creston, // America/Creston - 0x62a70204
  &kZoneAmerica_Costa_Rica, // America/Costa_Rica - 0x63ff66be
  &kZoneAsia_Qostanay, // Asia/Qostanay - 0x654fe522
  &kZoneAmerica_Indiana_Knox, // America/Indiana/Knox - 0x6554adc9
  &kZoneEurope_Prague, // Europe/Prague - 0x65ee5d48
  &kZoneAmerica_Puerto_Rico, // America/Puerto_Rico - 0x6752ca31
  &kZoneIndian_Christmas, // Indian/Christmas - 0x68c207d5
  &kZoneAsia_Novokuznetsk, // Asia/Novokuznetsk - 0x69264f93
  &kZoneAmerica_Curacao, // America/Curacao - 0x6a879184
  &kZoneAmerica_Tijuana, // America/Tijuana - 0x6aa1df72
  &kZoneAsia_Makassar, // Asia/Makassar - 0x6aa21c85
  &kZoneEurope_Helsinki, // Europe/Helsinki - 0x6ab2975b
  &kZoneAmerica_Porto_Velho, // America/Porto_Velho - 0x6b1aac77
  &kZoneEurope_Samara, // Europe/Samara - 0x6bc0b139
  &kZoneAmerica_Edmonton, // America/Edmonton - 0x6cb9484a
  &kZoneAmerica_Dawson_Creek, // America/Dawson_Creek - 0x6cf24e5b
  &kZoneAmerica_Grand_Turk, // America/Grand_Turk - 0x6e216197
  &kZoneAmerica_Blanc_Sablon, // America/Blanc-Sablon - 0x6e299892
  &kZoneEurope_Tirane, // Europe/Tirane - 0x6ea95b47
  &kZoneAmerica_Araguaina, // America/Araguaina - 0x6f9a3aef
  &kZoneIndian_Reunion, // Indian/Reunion - 0x7076c047
  &kZoneAsia_Qyzylorda, // Asia/Qyzylorda - 0x71282e81
  &kZoneAsia_Kolkata, // Asia/Kolkata - 0x72c06cd9
  &kZoneEurope_Vienna, // Europe/Vienna - 0x734cc2e5
  &kZoneAsia_Kamchatka, // Asia/Kamchatka - 0x73baf9d7
  &kZoneAmerica_Santarem, // America/Santarem - 0x740caec1
  &kZoneAmerica_Santiago, // America/Santiago - 0x7410c9bc
  &kZoneEurope_Warsaw, // Europe/Warsaw - 0x75185c19
  &kZoneAmerica_El_Salvador, // America/El_Salvador - 0x752ad652
  &kZoneAfrica_Bissau, // Africa/Bissau - 0x75564141
  &kZoneAmerica_Santo_Domingo, // America/Santo_Domingo - 0x75a0d177
  &kZoneAfrica_Accra, // Africa/Accra - 0x77d5b054
  &kZoneAfrica_Cairo, // Africa/Cairo - 0x77f8e228
  &kZoneAfrica_Ceuta, // Africa/Ceuta - 0x77fb46ec
  &kZoneAfrica_Lagos, // Africa/Lagos - 0x789bb5d0
  &kZoneAfrica_Windhoek, // Africa/Windhoek - 0x789c9bd3
  &kZoneAmerica_Toronto, // America/Toronto - 0x792e851b
  &kZoneAfrica_Tunis, // Africa/Tunis - 0x79378e6d
  &kZoneIndian_Mauritius, // Indian/Mauritius - 0x7b09c02a
  &kZoneAtlantic_Stanley, // Atlantic/Stanley - 0x7bb3e1c4
  &kZoneEurope_Zurich, // Europe/Zurich - 0x7d8195b9
  &kZoneAsia_Kuching, // Asia/Kuching - 0x801b003b
  &kZoneAtlantic_Madeira, // Atlantic/Madeira - 0x81b5c037
  &kZoneAmerica_Atikokan, // America/Atikokan - 0x81b92098
  &kZonePacific_Kiritimati, // Pacific/Kiritimati - 0x8305073a
  &kZoneAmerica_Metlakatla, // America/Metlakatla - 0x84de2686
  &kZoneAsia_Yakutsk, // Asia/Yakutsk - 0x87bb3a9e
  &kZoneAmerica_Chihuahua, // America/Chihuahua - 0x8827d776
  &kZonePacific_Pitcairn, // Pacific/Pitcairn - 0x8837d8bd
  &kZonePacific_Chuuk, // Pacific/Chuuk - 0x8a090b23
  &kZonePacific_Efate, // Pacific/Efate - 0x8a2bce28
  &kZonePacific_Nauru, // Pacific/Nauru - 0x8acc41ae
  &kZoneEST5EDT, // EST5EDT - 0x8adc72a3
  &kZonePacific_Palau, // Pacific/Palau - 0x8af04a36
  &kZoneAmerica_Winnipeg, // America/Winnipeg - 0x8c7dafc7
  &kZoneAustralia_Eucla, // Australia/Eucla - 0x8cf99e44
  &kZoneAmerica_Argentina_Catamarca, // America/Argentina/Catamarca - 0x8d40986b
  &kZoneAustralia_Perth, // Australia/Perth - 0x8db8269d
  &kZonePacific_Kwajalein, // Pacific/Kwajalein - 0x8e216759
  &kZoneAmerica_Port_au_Prince, // America/Port-au-Prince - 0x8e4a7bdc
  &kZoneAfrica_Maputo, // Africa/Maputo - 0x8e6ca1f0
  &kZonePacific_Norfolk, // Pacific/Norfolk - 0x8f4eb4be
  &kZoneAsia_Yerevan, // Asia/Yerevan - 0x9185c8cc
  &kZoneAmerica_Detroit, // America/Detroit - 0x925cfbc1
  &kZoneAsia_Choibalsan, // Asia/Choibalsan - 0x928aa4a6
  &kZoneAntarctica_Macquarie, // Antarctica/Macquarie - 0x92f47626
  &kZoneAmerica_Belize, // America/Belize - 0x93256c81
  &kZoneAmerica_Bogota, // America/Bogota - 0x93d7bc62
  &kZoneAsia_Pyongyang, // Asia/Pyongyang - 0x93ed1c8e
  &kZoneAmerica_Indiana_Petersburg, // America/Indiana/Petersburg - 0x94ac7acc
  &kZoneAmerica_Cancun, // America/Cancun - 0x953331be
  &kZoneAmerica_Glace_Bay, // America/Glace_Bay - 0x9681f8dd
  &kZoneAsia_Khandyga, // Asia/Khandyga - 0x9685a4d9
  &kZoneAmerica_Cuiaba, // America/Cuiaba - 0x969a52eb
  &kZoneAmerica_Dawson, // America/Dawson - 0x978d8d12
  &kZoneAmerica_Denver, // America/Denver - 0x97d10b2a
  &kZoneAmerica_Bahia, // America/Bahia - 0x97d815fb
  &kZoneAmerica_Belem, // America/Belem - 0x97da580b
  &kZoneAmerica_Boise, // America/Boise - 0x97dfc8d8
  &kZoneEurope_Andorra, // Europe/Andorra - 0x97f6764b
  &kZoneAmerica_Adak, // America/Adak - 0x97fe49d7
  &kZoneAmerica_Lima, // America/Lima - 0x980468c9
  &kZoneAmerica_Nome, // America/Nome - 0x98059b15
  &kZoneAmerica_Nuuk, // America/Nuuk - 0x9805b5a9
  &kZoneIndian_Maldives, // Indian/Maldives - 0x9869681c
  &kZoneAmerica_Sitka, // America/Sitka - 0x99104ce2
  &kZoneAmerica_Thule, // America/Thule - 0x9921dd68
  &kZonePacific_Rarotonga, // Pacific/Rarotonga - 0x9981a3b0
  &kZoneAsia_Kathmandu, // Asia/Kathmandu - 0x9a96ce6f
  &kZoneAmerica_North_Dakota_Beulah, // America/North_Dakota/Beulah - 0x9b52b384
  &kZoneAmerica_Rainy_River, // America/Rainy_River - 0x9cd58a10
  &kZoneEurope_Budapest, // Europe/Budapest - 0x9ce0197c
  &kZoneAsia_Baghdad, // Asia/Baghdad - 0x9ceffbed
  &kZoneEtc_GMT_PLUS_1, // Etc/GMT+1 - 0x9d13da14
  &kZoneEtc_GMT_PLUS_2, // Etc/GMT+2 - 0x9d13da15
  &kZoneEtc_GMT_PLUS_3, // Etc/GMT+3 - 0x9d13da16
  &kZoneEtc_GMT_PLUS_4, // Etc/GMT+4 - 0x9d13da17
  &kZoneEtc_GMT_PLUS_5, // Etc/GMT+5 - 0x9d13da18
  &kZoneEtc_GMT_PLUS_6, // Etc/GMT+6 - 0x9d13da19
  &kZoneEtc_GMT_PLUS_7, // Etc/GMT+7 - 0x9d13da1a
  &kZoneEtc_GMT_PLUS_8, // Etc/GMT+8 - 0x9d13da1b
  &kZoneEtc_GMT_PLUS_9, // Etc/GMT+9 - 0x9d13da1c
  &kZoneEtc_GMT_1, // Etc/GMT-1 - 0x9d13da56
  &kZoneEtc_GMT_2, // Etc/GMT-2 - 0x9d13da57
  &kZoneEtc_GMT_3, // Etc/GMT-3 - 0x9d13da58
  &kZoneEtc_GMT_4, // Etc/GMT-4 - 0x9d13da59
  &kZoneEtc_GMT_5, // Etc/GMT-5 - 0x9d13da5a
  &kZoneEtc_GMT_6, // Etc/GMT-6 - 0x9d13da5b
  &kZoneEtc_GMT_7, // Etc/GMT-7 - 0x9d13da5c
  &kZoneEtc_GMT_8, // Etc/GMT-8 - 0x9d13da5d
  &kZoneEtc_GMT_9, // Etc/GMT-9 - 0x9d13da5e
  &kZoneAmerica_Nipigon, // America/Nipigon - 0x9d2a8b1a
  &kZoneAmerica_Rio_Branco, // America/Rio_Branco - 0x9d352764
  &kZoneAsia_Bangkok, // Asia/Bangkok - 0x9d6e3aaf
  &kZoneAfrica_El_Aaiun, // Africa/El_Aaiun - 0x9d6fb118
  &kZoneAmerica_North_Dakota_Center, // America/North_Dakota/Center - 0x9da42814
  &kZoneAsia_Barnaul, // Asia/Barnaul - 0x9dba4997
  &kZoneAfrica_Tripoli, // Africa/Tripoli - 0x9dfebd3d
  &kZoneEurope_Istanbul, // Europe/Istanbul - 0x9e09d6e6
  &kZoneAfrica_Ndjamena, // Africa/Ndjamena - 0x9fe09898
  &kZoneAmerica_Guyana, // America/Guyana - 0x9ff7bd0b
  &kZoneAmerica_Havana, // America/Havana - 0xa0e15675
  &kZoneAsia_Novosibirsk, // Asia/Novosibirsk - 0xa2a435cb
  &kZoneEurope_Kiev, // Europe/Kiev - 0xa2c19eb3
  &kZoneEurope_Oslo, // Europe/Oslo - 0xa2c3fba1
  &kZoneEurope_Riga, // Europe/Riga - 0xa2c57587
  &kZoneEurope_Rome, // Europe/Rome - 0xa2c58fd7
  &kZoneAmerica_Inuvik, // America/Inuvik - 0xa42189fc
  &kZoneAmerica_Argentina_La_Rioja, // America/Argentina/La_Rioja - 0xa46b7eef
  &kZoneAsia_Almaty, // Asia/Almaty - 0xa61f41fa
  &kZoneAsia_Anadyr, // Asia/Anadyr - 0xa63cebd1
  &kZoneAsia_Aqtobe, // Asia/Aqtobe - 0xa67dcc4e
  &kZoneAsia_Atyrau, // Asia/Atyrau - 0xa6b6e068
  &kZoneAmerica_Juneau, // America/Juneau - 0xa6f13e2e
  &kZoneAustralia_Lord_Howe, // Australia/Lord_Howe - 0xa748b67d
  &kZonePacific_Port_Moresby, // Pacific/Port_Moresby - 0xa7ba7f68
  &kZoneAsia_Beirut, // Asia/Beirut - 0xa7f3d5fd
  &kZoneAfrica_Nairobi, // Africa/Nairobi - 0xa87ab57e
  &kZoneAsia_Brunei, // Asia/Brunei - 0xa8e595f7
  &kZonePacific_Galapagos, // Pacific/Galapagos - 0xa952f752
  &kZoneAmerica_Argentina_Mendoza, // America/Argentina/Mendoza - 0xa9f72d5c
  &kZoneAmerica_La_Paz, // America/La_Paz - 0xaa29125d
  &kZoneAmerica_Noronha, // America/Noronha - 0xab5116fb
  &kZoneAmerica_Maceio, // America/Maceio - 0xac80c6d4
  &kZoneAmerica_Manaus, // America/Manaus - 0xac86bf8b
  &kZoneAmerica_Merida, // America/Merida - 0xacd172d8
  &kZoneEurope_Chisinau, // Europe/Chisinau - 0xad58aa18
  &kZoneAmerica_Nassau, // America/Nassau - 0xaedef011
  &kZoneEurope_Uzhgorod, // Europe/Uzhgorod - 0xb066f5d6
  &kZoneAustralia_Broken_Hill, // Australia/Broken_Hill - 0xb06eada3
  &kZoneAsia_Bishkek, // Asia/Bishkek - 0xb0728553
  &kZoneAmerica_Paramaribo, // America/Paramaribo - 0xb319e4c4
  &kZoneAmerica_Panama, // America/Panama - 0xb3863854
  &kZoneAsia_Hebron, // Asia/Hebron - 0xb5eef250
  &kZoneAmerica_Goose_Bay, // America/Goose_Bay - 0xb649541e
  &kZoneAmerica_Los_Angeles, // America/Los_Angeles - 0xb7f7e8f2
  &kZoneAmerica_Recife, // America/Recife - 0xb8730494
  &kZoneAmerica_Regina, // America/Regina - 0xb875371c
  &kZoneAsia_Ashgabat, // Asia/Ashgabat - 0xba87598d
  &kZoneAmerica_Halifax, // America/Halifax - 0xbc5b7183
  &kZoneAsia_Srednekolymsk, // Asia/Srednekolymsk - 0xbf8e337d
  &kZoneAmerica_Argentina_Cordoba, // America/Argentina/Cordoba - 0xbfccc308
  &kZoneAmerica_Tegucigalpa, // America/Tegucigalpa - 0xbfd6fd4c
  &kZoneAsia_Manila, // Asia/Manila - 0xc156c944
  &kZoneAfrica_Abidjan, // Africa/Abidjan - 0xc21305a3
  &kZoneAmerica_Punta_Arenas, // America/Punta_Arenas - 0xc2c3bce7
  &kZoneAfrica_Casablanca, // Africa/Casablanca - 0xc59f1b33
  &kZoneAmerica_Argentina_Rio_Gallegos, // America/Argentina/Rio_Gallegos - 0xc5b0f565
  &kZoneAsia_Jayapura, // Asia/Jayapura - 0xc6833c2f
  &kZoneAmerica_Resolute, // America/Resolute - 0xc7093459
  &kZoneAmerica_Rankin_Inlet, // America/Rankin_Inlet - 0xc8de4984
  &kZoneAmerica_Barbados, // America/Barbados - 0xcbbc3b04
  &kZoneAsia_Riyadh, // Asia/Riyadh - 0xcd973d93
  &kZonePacific_Easter, // Pacific/Easter - 0xcf54f7e7
  &kZoneAsia_Singapore, // Asia/Singapore - 0xcf8581fa
  &kZoneAsia_Krasnoyarsk, // Asia/Krasnoyarsk - 0xd0376c6a
  &kZoneAmerica_Mexico_City, // America/Mexico_City - 0xd0d93f43
  &kZoneAsia_Taipei, // Asia/Taipei - 0xd1a844ae
  &kZoneAsia_Tehran, // Asia/Tehran - 0xd1f02254
  &kZoneEurope_Kaliningrad, // Europe/Kaliningrad - 0xd33b2f28
  &kZoneAmerica_Argentina_Buenos_Aires, // America/Argentina/Buenos_Aires - 0xd43b4c0d
  &kZoneAfrica_Juba, // Africa/Juba - 0xd51b395c
  &kZoneAsia_Urumqi, // Asia/Urumqi - 0xd5379735
  &kZoneAmerica_Cambridge_Bay, // America/Cambridge_Bay - 0xd5a44aff
  &kZoneAfrica_Johannesburg, // Africa/Johannesburg - 0xd5d157a0
  &kZoneAmerica_Port_of_Spain, // America/Port_of_Spain - 0xd8b28d59
  &kZoneEtc_GMT, // Etc/GMT - 0xd8e2de58
  &kZoneEtc_UTC, // Etc/UTC - 0xd8e31abc
  &kZoneAmerica_Yakutat, // America/Yakutat - 0xd8ee31e9
  &kZoneAfrica_Algiers, // Africa/Algiers - 0xd94515c1
  &kZonePST8PDT, // PST8PDT - 0xd99ee2dc
  &kZoneEurope_Simferopol, // Europe/Simferopol - 0xda9eb724
  &kZonePacific_Funafuti, // Pacific/Funafuti - 0xdb402d65
  &kZoneAmerica_Matamoros, // America/Matamoros - 0xdd1b0259
  &kZoneAsia_Yangon, // Asia/Yangon - 0xdd54a8be
  &kZoneEurope_Vilnius, // Europe/Vilnius - 0xdd63b8ce
  &kZonePacific_Kosrae, // Pacific/Kosrae - 0xde5139a8
  &kZoneAmerica_Kentucky_Monticello, // America/Kentucky/Monticello - 0xde71c439
  &kZoneEurope_Brussels, // Europe/Brussels - 0xdee07337
  &kZoneAmerica_Swift_Current, // America/Swift_Current - 0xdef98e55
  &kZoneAsia_Irkutsk, // Asia/Irkutsk - 0xdfbf213f
  &kZoneEurope_Ulyanovsk, // Europe/Ulyanovsk - 0xe03783d0
  &kZoneAustralia_Lindeman, // Australia/Lindeman - 0xe05029e2
  &kZoneEurope_Belgrade, // Europe/Belgrade - 0xe0532b3a
  &kZoneAmerica_Menominee, // America/Menominee - 0xe0e9c583
  &kZoneEurope_Copenhagen, // Europe/Copenhagen - 0xe0ed30bc
  &kZoneAtlantic_Faroe, // Atlantic/Faroe - 0xe110a971
  &kZonePacific_Majuro, // Pacific/Majuro - 0xe1f95371
  &kZoneAntarctica_Casey, // Antarctica/Casey - 0xe2022583
  &kZoneAntarctica_Davis, // Antarctica/Davis - 0xe2144b45
  &kZoneEurope_Astrakhan, // Europe/Astrakhan - 0xe22256e1
  &kZoneAntarctica_Syowa, // Antarctica/Syowa - 0xe330c7e1
  &kZoneAntarctica_Troll, // Antarctica/Troll - 0xe33f085b
  &kZoneEurope_Saratov, // Europe/Saratov - 0xe4315da4
  &kZonePacific_Noumea, // Pacific/Noumea - 0xe551b788
  &kZonePacific_Honolulu, // Pacific/Honolulu - 0xe6e70af9
  &kZoneAmerica_Argentina_Tucuman, // America/Argentina/Tucuman - 0xe96399eb
  &kZoneEurope_Zaporozhye, // Europe/Zaporozhye - 0xeab9767f
  &kZoneAsia_Magadan, // Asia/Magadan - 0xebacc19b
  &kZoneAmerica_Ojinaga, // America/Ojinaga - 0xebfde83f
  &kZoneCST6CDT, // CST6CDT - 0xf0e87d00
  &kZonePacific_Tahiti, // Pacific/Tahiti - 0xf24c2446
  &kZonePacific_Tarawa, // Pacific/Tarawa - 0xf2517e63
  &kZoneMST7MDT, // MST7MDT - 0xf2af9375
  &kZoneAsia_Tashkent, // Asia/Tashkent - 0xf3924254
  &kZoneAsia_Sakhalin, // Asia/Sakhalin - 0xf4a1c9bd
  &kZonePacific_Guadalcanal, // Pacific/Guadalcanal - 0xf4dd25f0
  &kZoneAmerica_Danmarkshavn, // America/Danmarkshavn - 0xf554d204
  &kZoneAsia_Shanghai, // Asia/Shanghai - 0xf895a7f5
  &kZoneEurope_Gibraltar, // Europe/Gibraltar - 0xf8e325fc
  &kZoneAtlantic_Azores, // Atlantic/Azores - 0xf93ed918
  &kZonePacific_Wallis, // Pacific/Wallis - 0xf94ddb0f
  &kZoneAmerica_Thunder_Bay, // America/Thunder_Bay - 0xf962e71b
  &kZoneAmerica_Eirunepe, // America/Eirunepe - 0xf9b29683
  &kZoneAmerica_Montevideo, // America/Montevideo - 0xfa214780
  &kZoneEurope_Kirov, // Europe/Kirov - 0xfaf5abef
  &kZoneEurope_Malta, // Europe/Malta - 0xfb1560f3
  &kZoneEurope_Minsk, // Europe/Minsk - 0xfb19cc66
  &kZoneEurope_Bucharest, // Europe/Bucharest - 0xfb349ec5
  &kZoneAfrica_Khartoum, // Africa/Khartoum - 0xfb3d4205
  &kZoneEurope_Paris, // Europe/Paris - 0xfb4bc2a3
  &kZoneAsia_Yekaterinburg, // Asia/Yekaterinburg - 0xfb544c6e
  &kZoneEurope_Sofia, // Europe/Sofia - 0xfb898656
  &kZoneAtlantic_Canary, // Atlantic/Canary - 0xfc23f2c2
  &kZoneAmerica_Campo_Grande, // America/Campo_Grande - 0xfec3e7a6

};

}
}
