// This file was generated by the following script:
//
//  $ ../../../tools/tzcompiler.py --input_dir /home/brian/dev/tz --output_dir /home/brian/dev/AceTime/src/ace_time/zonedbx --tz_version 2018i --zonedb --arduinox
//
// using the TZ Database files
//
//  africa, antarctica, asia, australasia, europe, northamerica, southamerica
//
// from https://github.com/eggert/tz/releases/tag/2018i
//
// DO NOT EDIT

#ifndef ACE_TIME_ZONEDBX_ZONE_POLICIES_H
#define ACE_TIME_ZONEDBX_ZONE_POLICIES_H

#include "../common/ZonePolicy.h"

namespace ace_time {
namespace zonedbx {

// numPolicies: 83
extern const ZonePolicy kPolicyAN;
extern const ZonePolicy kPolicyAQ;
extern const ZonePolicy kPolicyAS;
extern const ZonePolicy kPolicyAT;
extern const ZonePolicy kPolicyAV;
extern const ZonePolicy kPolicyAW;
extern const ZonePolicy kPolicyArg;
extern const ZonePolicy kPolicyArmenia;
extern const ZonePolicy kPolicyAus;
extern const ZonePolicy kPolicyAzer;
extern const ZonePolicy kPolicyBarb;
extern const ZonePolicy kPolicyBelize;
extern const ZonePolicy kPolicyBrazil;
extern const ZonePolicy kPolicyCO;
extern const ZonePolicy kPolicyCR;
extern const ZonePolicy kPolicyCanada;
extern const ZonePolicy kPolicyChatham;
extern const ZonePolicy kPolicyChile;
extern const ZonePolicy kPolicyCook;
extern const ZonePolicy kPolicyCuba;
extern const ZonePolicy kPolicyDhaka;
extern const ZonePolicy kPolicyE_EurAsia;
extern const ZonePolicy kPolicyEU;
extern const ZonePolicy kPolicyEUAsia;
extern const ZonePolicy kPolicyEcuador;
extern const ZonePolicy kPolicyEgypt;
extern const ZonePolicy kPolicyEire;
extern const ZonePolicy kPolicyFalk;
extern const ZonePolicy kPolicyFiji;
extern const ZonePolicy kPolicyGhana;
extern const ZonePolicy kPolicyGuam;
extern const ZonePolicy kPolicyGuat;
extern const ZonePolicy kPolicyHK;
extern const ZonePolicy kPolicyHaiti;
extern const ZonePolicy kPolicyHoliday;
extern const ZonePolicy kPolicyHond;
extern const ZonePolicy kPolicyIran;
extern const ZonePolicy kPolicyIraq;
extern const ZonePolicy kPolicyJapan;
extern const ZonePolicy kPolicyJordan;
extern const ZonePolicy kPolicyKyrgyz;
extern const ZonePolicy kPolicyLH;
extern const ZonePolicy kPolicyLebanon;
extern const ZonePolicy kPolicyLibya;
extern const ZonePolicy kPolicyMacau;
extern const ZonePolicy kPolicyMauritius;
extern const ZonePolicy kPolicyMexico;
extern const ZonePolicy kPolicyMoldova;
extern const ZonePolicy kPolicyMoncton;
extern const ZonePolicy kPolicyMongol;
extern const ZonePolicy kPolicyMorocco;
extern const ZonePolicy kPolicyNC;
extern const ZonePolicy kPolicyNT_YK;
extern const ZonePolicy kPolicyNZ;
extern const ZonePolicy kPolicyNamibia;
extern const ZonePolicy kPolicyNic;
extern const ZonePolicy kPolicyPRC;
extern const ZonePolicy kPolicyPakistan;
extern const ZonePolicy kPolicyPalestine;
extern const ZonePolicy kPolicyPara;
extern const ZonePolicy kPolicyPeru;
extern const ZonePolicy kPolicyPhil;
extern const ZonePolicy kPolicyROK;
extern const ZonePolicy kPolicyRussia;
extern const ZonePolicy kPolicyRussiaAsia;
extern const ZonePolicy kPolicySA;
extern const ZonePolicy kPolicySalv;
extern const ZonePolicy kPolicySanLuis;
extern const ZonePolicy kPolicyStJohns;
extern const ZonePolicy kPolicySudan;
extern const ZonePolicy kPolicySyria;
extern const ZonePolicy kPolicyTaiwan;
extern const ZonePolicy kPolicyThule;
extern const ZonePolicy kPolicyTonga;
extern const ZonePolicy kPolicyTroll;
extern const ZonePolicy kPolicyTunisia;
extern const ZonePolicy kPolicyTurkey;
extern const ZonePolicy kPolicyUS;
extern const ZonePolicy kPolicyUruguay;
extern const ZonePolicy kPolicyVanuatu;
extern const ZonePolicy kPolicyWS;
extern const ZonePolicy kPolicyWinn;
extern const ZonePolicy kPolicyZion;


// The following zone policies are not supported in this database.
//
// numPolicies: 56
//
// kPolicyAlbania (unused)
// kPolicyAlgeria (unused)
// kPolicyAustria (unused)
// kPolicyBahamas (unused)
// kPolicyBelgium (unused)
// kPolicyBulg (unused)
// kPolicyC-Eur (unused)
// kPolicyCA (unused)
// kPolicyChicago (unused)
// kPolicyCyprus (unused)
// kPolicyCzech (unused)
// kPolicyDR (unused)
// kPolicyDenmark (unused)
// kPolicyDenver (unused)
// kPolicyDetroit (unused)
// kPolicyE-Eur (unused)
// kPolicyEdm (unused)
// kPolicyEgyptAsia (unused)
// kPolicyFinland (unused)
// kPolicyFrance (unused)
// kPolicyGB-Eire (unused)
// kPolicyGermany (unused)
// kPolicyGreece (unused)
// kPolicyHalifax (unused)
// kPolicyHungary (unused)
// kPolicyIceland (unused)
// kPolicyIndianapolis (unused)
// kPolicyItaly (unused)
// kPolicyLatvia (unused)
// kPolicyLouisville (unused)
// kPolicyLux (unused)
// kPolicyMalta (unused)
// kPolicyMarengo (unused)
// kPolicyMenominee (unused)
// kPolicyNBorneo (unused)
// kPolicyNYC (unused)
// kPolicyNeth (unused)
// kPolicyNorway (unused)
// kPolicyPerry (unused)
// kPolicyPike (unused)
// kPolicyPoland (unused)
// kPolicyPort (unused)
// kPolicyPulaski (unused)
// kPolicyRegina (unused)
// kPolicyRomania (unused)
// kPolicyShang (unused)
// kPolicySovietZone (unused)
// kPolicySpain (unused)
// kPolicySpainAfrica (unused)
// kPolicyStarke (unused)
// kPolicySwift (unused)
// kPolicySwiss (unused)
// kPolicyToronto (unused)
// kPolicyVanc (unused)
// kPolicyVincennes (unused)
// kPolicyW-Eur (unused)


// The following zone policies may have inaccuracies due to the following
// reasons:
//
// numPolicies: 3
//
// kPolicyMoncton (AT time '0:01' truncated to '900' seconds)
// kPolicyPalestine (AT time '0:01' truncated to '900' seconds)
// kPolicyStJohns (AT time '0:01' truncated to '900' seconds)


}
}

#endif
