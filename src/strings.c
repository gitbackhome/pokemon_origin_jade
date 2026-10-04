#include "global.h"
#include "strings.h"
#include "battle_pyramid_bag.h"
#include "item_menu.h"

ALIGNED(4)
const u8 gText_ExpandedPlaceholder_Empty[] = _("");
const u8 gText_ExpandedPlaceholder_Kun[] = _("");
const u8 gText_ExpandedPlaceholder_Chan[] = _("");
#if GERMAN
const u8 gText_ExpandedPlaceholder_Sapphire[] = _("Saphir");
#else
const u8 gText_ExpandedPlaceholder_Sapphire[] = _("SAPPHIRE");
#endif
#if GERMAN
const u8 gText_ExpandedPlaceholder_Ruby[] = _("Rubin");
#else
const u8 gText_ExpandedPlaceholder_Ruby[] = _("RUBY");
#endif
#if GERMAN
const u8 gText_ExpandedPlaceholder_Emerald[] = _("Smaragd");
#else
const u8 gText_ExpandedPlaceholder_Emerald[] = _("EMERALD");
#endif
#if GERMAN
const u8 gText_ExpandedPlaceholder_Aqua[] = _("Aqua");
#else
const u8 gText_ExpandedPlaceholder_Aqua[] = _("AQUA");
#endif
#if GERMAN
const u8 gText_ExpandedPlaceholder_Magma[] = _("Magma");
#else
const u8 gText_ExpandedPlaceholder_Magma[] = _("MAGMA");
#endif
#if GERMAN
const u8 gText_ExpandedPlaceholder_Archie[] = _("Adrian");
#else
const u8 gText_ExpandedPlaceholder_Archie[] = _("ARCHIE");
#endif
#if GERMAN
const u8 gText_ExpandedPlaceholder_Maxie[] = _("Marc");
#else
const u8 gText_ExpandedPlaceholder_Maxie[] = _("MAXIE");
#endif
#if GERMAN
const u8 gText_ExpandedPlaceholder_Kyogre[] = _("Kyogre");
#else
const u8 gText_ExpandedPlaceholder_Kyogre[] = _("KYOGRE");
#endif
#if GERMAN
const u8 gText_ExpandedPlaceholder_Groudon[] = _("Groudon");
#else
const u8 gText_ExpandedPlaceholder_Groudon[] = _("GROUDON");
#endif
#if GERMAN
const u8 gText_ExpandedPlaceholder_Brendan[] = _("Brix");
#else
const u8 gText_ExpandedPlaceholder_Brendan[] = _("BRENDAN");
#endif
#if GERMAN
const u8 gText_ExpandedPlaceholder_May[] = _("Maike");
#else
const u8 gText_ExpandedPlaceholder_May[] = _("MAY");
#endif
#if GERMAN
const u8 gText_ExpandedPlaceholder_Red[] = _("Rot");
#else
const u8 gText_ExpandedPlaceholder_Red[] = _("RED");
#endif
#if GERMAN
const u8 gText_ExpandedPlaceholder_Green[] = _("Gary");
#else
const u8 gText_ExpandedPlaceholder_Green[] = _("GARY");
#endif
#if GERMAN
const u8 gText_ExpandedPlaceholder_Silver[] = _("Silber");
#else
const u8 gText_ExpandedPlaceholder_Silver[] = _("SILVER");
#endif
const u8 gText_EggNickname[POKEMON_NAME_LENGTH + 1] = _("Ei");
const u8 gText_Pokemon[POKEMON_NAME_LENGTH + 1] = _("Pokémon");
#if GERMAN
const u8 gText_Player[] = _("Player");
#else
const u8 gText_Player[] = _("PLAYER");
#endif // Unused
#if GERMAN
const u8 gText_Pokedex[] = _("Pokédex");
#else
const u8 gText_Pokedex[] = _("POKéDEX");
#endif // Unused
#if GERMAN
const u8 gText_Time[] = _("Spielzeit");
#else
const u8 gText_Time[] = _("TIME");
#endif
#if GERMAN
const u8 gText_Badges[] = _("Badges");
#else
const u8 gText_Badges[] = _("BADGES");
#endif // Unused
const u8 gText_AButton[] = _("A Button"); // Unused
const u8 gText_BButton[] = _("B Button"); // Unused
const u8 gText_RButton[] = _("R Button"); // Unused
const u8 gText_LButton[] = _("L Button"); // Unused
#if GERMAN
const u8 gText_Start[] = _("Start");
#else
const u8 gText_Start[] = _("START");
#endif // Unused
const u8 gText_Select[] = _("SELECT"); // Unused
const u8 gText_ControlPad[] = _("+ Control Pad"); // Unused
const u8 gText_LButtonRButton[] = _("L Button  R Button"); // Unused
#if GERMAN
const u8 gText_Controls[] = _("Controls");
#else
const u8 gText_Controls[] = _("CONTROLS");
#endif // Unused
#if GERMAN
ALIGNED(4) const u8 gText_PickOk[] = _("{DPAD_UPDOWN}Info {A_BUTTON}OK");
#else
ALIGNED(4) const u8 gText_PickOk[] = _("{DPAD_UPDOWN}PICK {A_BUTTON}OK");
#endif // Unused
#if GERMAN
ALIGNED(4) const u8 gText_Next[] = _("{A_BUTTON}Weiter");
#else
ALIGNED(4) const u8 gText_Next[] = _("{A_BUTTON}NEXT");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_NextBack[] = _("{A_BUTTON}Weiter {B_BUTTON}Zurück");
#else
ALIGNED(4) const u8 gText_NextBack[] = _("{A_BUTTON}NEXT {B_BUTTON}BACK");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_PickNextCancel[] = _("{DPAD_UPDOWN}Info{A_BUTTON}Weiter {B_BUTTON}Zur.");
#else
ALIGNED(4) const u8 gText_PickNextCancel[] = _("{DPAD_UPDOWN}PICK {A_BUTTON}NEXT {B_BUTTON}CANCEL");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_PickCancel[] = _("{DPAD_UPDOWN}Info{A_BUTTON}{B_BUTTON}Zurück");
#else
ALIGNED(4) const u8 gText_PickCancel[] = _("{DPAD_UPDOWN}PICK {A_BUTTON}{B_BUTTON}CANCEL");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_AButtonExit[] = _("{A_BUTTON}Zurück");
#else
ALIGNED(4) const u8 gText_AButtonExit[] = _("{A_BUTTON}EXIT");
#endif
#if GERMAN
const u8 gText_Boy[] = _("Junge");
#else
const u8 gText_Boy[] = _("BOY");
#endif
#if GERMAN
const u8 gText_Girl[] = _("Mädel");
#else
const u8 gText_Girl[] = _("GIRL");
#endif
#if GERMAN
const u8 gText_ThisIsAPokemon[] = _("Dies ist ein sogenanntes\n“Pokémon.”{PAUSE 96}\p");
#else
const u8 gText_ThisIsAPokemon[] = _("This is what we call a “POKéMON.”{PAUSE 96}\p");
#endif
#if GERMAN
const u8 gText_5MarksPokemon[] = _("?????");
#else
const u8 gText_5MarksPokemon[] = _("????? POKéMON");
#endif
const u8 gText_UnkHeight[] = _("{CLEAR_TO 0x0C}??'??”");
const u8 gText_UnkHeightMetric[] = _("???.? m");
const u8 gText_UnkWeight[] = _("????.? lbs.");
#if GERMAN
const u8 gText_UnkWeightMetric[] = _("???.? kg");
#else
const u8 gText_UnkWeightMetric[] = _("???.? kg.");
#endif
#if GERMAN
const u8 gText_EmptyPkmnCategory[] = _("                       Pokémon");
#else
const u8 gText_EmptyPkmnCategory[] = _("                       POKéMON");
#endif // Unused
const u8 gText_EmptyHeight[] = _("{CLEAR_TO 0x0C}    '    ”"); // Unused
const u8 gText_EmptyWeight[] = _("        .   lbs."); // Unused
const u8 gText_EmptyPokedexInfo1[] = _(""); // Unused
#if GERMAN
const u8 gText_CryOf[] = _("Ruf von");
#else
const u8 gText_CryOf[] = _("CRY OF");
#endif
const u8 gText_EmptyPokedexInfo2[] = _(""); // Unused
#if GERMAN
const u8 gText_SizeComparedTo[] = _("Größe im Vergleich zu ");
#else
const u8 gText_SizeComparedTo[] = _("SIZE COMPARED TO ");
#endif
#if GERMAN
const u8 gText_PokedexRegistration[] = _("Neuer Eintrag aufgenommen.");
#else
const u8 gText_PokedexRegistration[] = _("POKéDEX registration completed.");
#endif
#if GERMAN
const u8 gText_HTHeight[] = _("Gr.");
#else
const u8 gText_HTHeight[] = _("HT");
#endif
#if GERMAN
const u8 gText_WTWeight[] = _("Gew.");
#else
const u8 gText_WTWeight[] = _("WT");
#endif
#if GERMAN
const u8 gText_SearchingPleaseWait[] = _("Suche läuft.\nBitte warten…");
#else
const u8 gText_SearchingPleaseWait[] = _("Searching…\nPlease wait.");
#endif
#if GERMAN
const u8 gText_SearchCompleted[] = _("Suche beendet.");
#else
const u8 gText_SearchCompleted[] = _("Search completed.");
#endif
#if GERMAN
const u8 gText_NoMatchingPkmnWereFound[] = _("Es wurde keine Übereinstimmung ermittelt.");
#else
const u8 gText_NoMatchingPkmnWereFound[] = _("No matching POKéMON were found.");
#endif
#if GERMAN
const u8 gText_SearchForPkmnBasedOnParameters[] = _("Suche nach Pokémon anhand\nausgewählter Parameter.");
#else
const u8 gText_SearchForPkmnBasedOnParameters[] = _("Search for POKéMON based on\nselected parameters.");
#endif
#if GERMAN
const u8 gText_SwitchPokedexListings[] = _("Ordnungssystem des Pokédex ändern.");
#else
const u8 gText_SwitchPokedexListings[] = _("Switch POKéDEX listings.");
#endif
#if GERMAN
const u8 gText_ReturnToPokedex[] = _("Kehre zurück zum Pokédex.");
#else
const u8 gText_ReturnToPokedex[] = _("Return to the POKéDEX.");
#endif
#if GERMAN
const u8 gText_SelectPokedexMode[] = _("Wähle einen Pokédex.");
#else
const u8 gText_SelectPokedexMode[] = _("Select the POKéDEX mode.");
#endif
#if GERMAN
const u8 gText_SelectPokedexListingMode[] = _("Wähle ein Ordnungssystem des Pokédex.");
#else
const u8 gText_SelectPokedexListingMode[] = _("Select the POKéDEX listing mode.");
#endif
#if GERMAN
const u8 gText_ListByFirstLetter[] = _("Nach Anfangsbuchstaben suchen.\n(Alle gesehenen Pokémon.)");
#else
const u8 gText_ListByFirstLetter[] = _("List by the first letter in the name.\nSpotted POKéMON only.");
#endif
#if GERMAN
const u8 gText_ListByBodyColor[] = _("Nach Körperfarbe suchen.\n(Alle gesehenen Pokémon.)");
#else
const u8 gText_ListByBodyColor[] = _("List by body color.\nSpotted POKéMON only.");
#endif
#if GERMAN
const u8 gText_ListByType[] = _("Nach Elementklasse suchen.\n(Nur gefangene Pokémon.)");
#else
const u8 gText_ListByType[] = _("List by type.\nOwned POKéMON only.");
#endif
#if GERMAN
const u8 gText_ExecuteSearchSwitch[] = _("Suche/Änderung ausführen.");
#else
const u8 gText_ExecuteSearchSwitch[] = _("Execute search/switch.");
#endif
#if IS_HNS
#if GERMAN
const u8 gText_DexHoennTitle[] = _("Johto Dex");
#else
const u8 gText_DexHoennTitle[] = _("HOENN DEX");
#endif
#else
#if GERMAN
const u8 gText_DexHoennTitle[] = _("Hoenn Dex");
#else
const u8 gText_DexHoennTitle[] = _("HOENN DEX");
#endif
#endif
#if GERMAN
const u8 gText_DexNatTitle[] = _("Nationaler Dex");
#else
const u8 gText_DexNatTitle[] = _("NATIONAL DEX");
#endif
#if GERMAN
const u8 gText_DexSortNumericalTitle[] = _("Numerisch");
#else
const u8 gText_DexSortNumericalTitle[] = _("NUMERICAL MODE");
#endif
#if GERMAN
const u8 gText_DexSortAtoZTitle[] = _("Von A bis Z");
#else
const u8 gText_DexSortAtoZTitle[] = _("A TO Z MODE");
#endif
#if GERMAN
const u8 gText_DexSortHeaviestTitle[] = _("Nach Gewicht >");
#else
const u8 gText_DexSortHeaviestTitle[] = _("HEAVIEST MODE");
#endif
#if GERMAN
const u8 gText_DexSortLightestTitle[] = _("Nach Gewicht <");
#else
const u8 gText_DexSortLightestTitle[] = _("LIGHTEST MODE");
#endif
#if GERMAN
const u8 gText_DexSortTallestTitle[] = _("Nach Größe >");
#else
const u8 gText_DexSortTallestTitle[] = _("TALLEST MODE");
#endif
#if GERMAN
const u8 gText_DexSortSmallestTitle[] = _("Nach Größe <");
#else
const u8 gText_DexSortSmallestTitle[] = _("SMALLEST MODE");
#endif
const u8 gText_DexSearchAlphaABC[] = _("ABC");
const u8 gText_DexSearchAlphaDEF[] = _("DEF");
const u8 gText_DexSearchAlphaGHI[] = _("GHI");
const u8 gText_DexSearchAlphaJKL[] = _("JKL");
const u8 gText_DexSearchAlphaMNO[] = _("MNO");
const u8 gText_DexSearchAlphaPQR[] = _("PQR");
const u8 gText_DexSearchAlphaSTU[] = _("STU");
const u8 gText_DexSearchAlphaVWX[] = _("VWX");
const u8 gText_DexSearchAlphaYZ[] = _("YZ");
#if GERMAN
const u8 gText_DexSearchColorRed[] = _("Rot");
#else
const u8 gText_DexSearchColorRed[] = _("RED");
#endif
#if GERMAN
const u8 gText_DexSearchColorBlue[] = _("Blau");
#else
const u8 gText_DexSearchColorBlue[] = _("BLUE");
#endif
#if GERMAN
const u8 gText_DexSearchColorYellow[] = _("Gelb");
#else
const u8 gText_DexSearchColorYellow[] = _("YELLOW");
#endif
#if GERMAN
const u8 gText_DexSearchColorGreen[] = _("Grün");
#else
const u8 gText_DexSearchColorGreen[] = _("GREEN");
#endif
#if GERMAN
const u8 gText_DexSearchColorBlack[] = _("Schwarz");
#else
const u8 gText_DexSearchColorBlack[] = _("BLACK");
#endif
#if GERMAN
const u8 gText_DexSearchColorBrown[] = _("Braun");
#else
const u8 gText_DexSearchColorBrown[] = _("BROWN");
#endif
#if GERMAN
const u8 gText_DexSearchColorPurple[] = _("Lila");
#else
const u8 gText_DexSearchColorPurple[] = _("PURPLE");
#endif
#if GERMAN
const u8 gText_DexSearchColorGray[] = _("Grau");
#else
const u8 gText_DexSearchColorGray[] = _("GRAY");
#endif
#if GERMAN
const u8 gText_DexSearchColorWhite[] = _("Weiß");
#else
const u8 gText_DexSearchColorWhite[] = _("WHITE");
#endif
#if GERMAN
const u8 gText_DexSearchColorPink[] = _("Rosa");
#else
const u8 gText_DexSearchColorPink[] = _("PINK");
#endif
#if IS_HNS
#if GERMAN
const u8 gText_DexHoennDescription[] = _("Johto Pokédex");
#else
const u8 gText_DexHoennDescription[] = _("HOENN region's POKéDEX");
#endif
#else
#if GERMAN
const u8 gText_DexHoennDescription[] = _("Hoenn Pokédex");
#else
const u8 gText_DexHoennDescription[] = _("HOENN region's POKéDEX");
#endif
#endif
#if GERMAN
const u8 gText_DexNatDescription[] = _("Nationaler Pokédex");
#else
const u8 gText_DexNatDescription[] = _("National edition POKéDEX");
#endif
#if GERMAN
const u8 gText_DexSortNumericalDescription[] = _("Pokémon werden anhand ihrer\nNummer sortiert.");
#else
const u8 gText_DexSortNumericalDescription[] = _("POKéMON are listed according to their\nnumber.");
#endif
#if GERMAN
const u8 gText_DexSortAtoZDescription[] = _("Gesehene und gefangene Pokémon\nwerden alphabetisch geordnet.");
#else
const u8 gText_DexSortAtoZDescription[] = _("Spotted and owned POKéMON are listed\nalphabetically.");
#endif
#if GERMAN
const u8 gText_DexSortHeaviestDescription[] = _("Gefangene Pokémon werden nach Gewicht\nsortiert, beginnend mit dem schwersten.");
#else
const u8 gText_DexSortHeaviestDescription[] = _("Owned POKéMON are listed from the\nheaviest to the lightest.");
#endif
#if GERMAN
const u8 gText_DexSortLightestDescription[] = _("Gefangene Pokémon werden nach Gewicht\nsortiert, beginnend mit dem leichtesten.");
#else
const u8 gText_DexSortLightestDescription[] = _("Owned POKéMON are listed from the\nlightest to the heaviest.");
#endif
#if GERMAN
const u8 gText_DexSortTallestDescription[] = _("Gefangene Pokémon werden nach Größe\nsortiert, beginnend mit dem größten.");
#else
const u8 gText_DexSortTallestDescription[] = _("Owned POKéMON are listed from the\ntallest to the smallest.");
#endif
#if GERMAN
const u8 gText_DexSortSmallestDescription[] = _("Gefangene Pokémon werden nach Größe\nsortiert, beginnend mit dem kleinsten.");
#else
const u8 gText_DexSortSmallestDescription[] = _("Owned POKéMON are listed from the\nsmallest to the tallest.");
#endif
const u8 gText_DexEmptyString[] = _("");
#if GERMAN
const u8 gText_DexSearchDontSpecify[] = _("Keine Angabe");
#else
const u8 gText_DexSearchDontSpecify[] = _("DON'T SPECIFY.");
#endif
#if GERMAN
const u8 gText_DexSearchTypeNone[] = _("Keiner");
#else
const u8 gText_DexSearchTypeNone[] = _("NONE");
#endif
const u8 gText_SelectorArrow[] = _("▶");
const u8 gText_EmptySpace[] = _(" "); // Unused
#if GERMAN
const u8 gText_WelcomeToHOF[] = _("Willkommen in der Ruhmeshalle!");
#else
const u8 gText_WelcomeToHOF[] = _("Welcome to the HALL OF FAME!");
#endif
#if GERMAN
const u8 gText_HOFDexRating[] = _("Gesichtete Pokémon: {STR_VAR_1}!\nBesitz an Pokémon: {STR_VAR_2}!\pProf. Birks Pokédex-Bewertung!\pProf. Birk: Mal sehen…\p");
#else
const u8 gText_HOFDexRating[] = _("Spotted POKéMON: {STR_VAR_1}!\nOwned POKéMON: {STR_VAR_2}!\pPROF. BIRCH's POKéDEX rating!\pPROF. BIRCH: Let's see…\p");
#endif
#if GERMAN
const u8 gText_HOFDexSaving[] = _("Sichern…\nGerät Nicht Ausschalten!");
#else
const u8 gText_HOFDexSaving[] = _("SAVING…\nDON'T TURN OFF THE POWER.");
#endif
#if GERMAN
const u8 gText_HOFCorrupted[] = _("Die RH-Daten sind beschädigt.");
#else
const u8 gText_HOFCorrupted[] = _("The HALL OF FAME data is corrupted.");
#endif
#if GERMAN
const u8 gText_HOFNumber[] = _("Ruhmeshalle, Nr. {STR_VAR_1}");
#else
const u8 gText_HOFNumber[] = _("HALL OF FAME No. {STR_VAR_1}");
#endif
#if GERMAN
const u8 gText_LeagueChamp[] = _("Champ der Pokémon Liga!\nHerzlichen Glückwunsch!");
#else
const u8 gText_LeagueChamp[] = _("LEAGUE CHAMPION!\nCONGRATULATIONS!");
#endif
#if GERMAN
const u8 gText_Number[] = _("Nr. ");
#else
const u8 gText_Number[] = _("No. ");
#endif
#if GERMAN
const u8 gText_Level[] = _("Lv.");
#else
const u8 gText_Level[] = _("Lv. ");
#endif
#if GERMAN
const u8 gText_IdNumberSlash[] = _("Idno. /");
#else
const u8 gText_IdNumberSlash[] = _("IDNo. /");
#endif // Unused
#if GERMAN
const u8 gText_Name[] = _("Trainer");
#else
const u8 gText_Name[] = _("NAME");
#endif
#if GERMAN
const u8 gText_IDNumber[] = _("ID.Nr.");
#else
const u8 gText_IDNumber[] = _("IDNo.");
#endif
#if GERMAN
const u8 gText_BirchInTrouble[] = _("Prof. Birk ist in Schwierigkeiten!\nSchnapp’ dir ein Pokémon und hilf ihm!");
#else
const u8 gText_BirchInTrouble[] = _("PROF. BIRCH is in trouble!\nRelease a POKéMON and rescue him!");
#endif
#if GERMAN
const u8 gText_ConfirmStarterChoice[] = _("Wählst du dieses Pokémon?");
#else
const u8 gText_ConfirmStarterChoice[] = _("Do you choose this POKéMON?");
#endif
#if GERMAN
const u8 gText_Pokemon4[] = _("Pokémon");
#else
const u8 gText_Pokemon4[] = _("POKéMON");
#endif // Unused
#if GERMAN
const u8 gText_FlyToWhere[] = _("Wohin?");
#else
const u8 gText_FlyToWhere[] = _("FLY to where?");
#endif
#if GERMAN
const u8 gMenuText_Use[] = _("Benutzen");
#else
const u8 gMenuText_Use[] = _("USE");
#endif
#if GERMAN
const u8 gMenuText_Toss[] = _("Müll");
#else
const u8 gMenuText_Toss[] = _("TOSS");
#endif
#if GERMAN
const u8 gMenuText_Register[] = _("Regist.");
#else
const u8 gMenuText_Register[] = _("REGISTER");
#endif
#if GERMAN
const u8 gMenuText_Give[] = _("Geben");
#else
const u8 gMenuText_Give[] = _("GIVE");
#endif
#if GERMAN
const u8 gMenuText_Confirm[] = _("O.K.");
#else
const u8 gMenuText_Confirm[] = _("CONFIRM");
#endif
#if GERMAN
const u8 gText_Cancel[] = _("Zurück");
#else
const u8 gText_Cancel[] = _("CANCEL");
#endif
#if GERMAN
const u8 gText_Cancel2[] = _("Zurück");
#else
const u8 gText_Cancel2[] = _("CANCEL");
#endif
const u8 gText_EmptyString2[] = _("");
#if GERMAN
const u8 gText_None[] = _("Keines");
#else
const u8 gText_None[] = _("NONE");
#endif
const u8 gText_FiveMarks[] = _("?????");
const u8 gText_Slash[] = _("/");
const u8 gText_OneDash[] = _("-");
const u8 gText_TwoDashes[] = _("--");
const u8 gText_ThreeDashes[] = _("---");
const u8 gText_MaleSymbol[] = _("♂");
const u8 gText_FemaleSymbol[] = _("♀");
#if GERMAN
const u8 gText_LevelSymbol[] = _("Lv.");
#else
const u8 gText_LevelSymbol[] = _("{LV}");
#endif
#if GERMAN
const u8 gText_NumberClear01[] = _("{NO} {CLEAR 0x01}");
#else
const u8 gText_NumberClear01[] = _("{NO}{CLEAR 0x01}");
#endif
const u8 gText_RightArrow[] = _("{RIGHT_ARROW}"); // Unused
const u8 gText_IDNumber2[] = _("{ID}{NO}");
const u8 gText_Space[] = _(" ");
const u8 gText_SelectorArrow2[] = _("▶");
#if GERMAN
const u8 gText_GoBackPrevMenu[] = _("Kehre zurück zum\nvorherigen Menü.");
#else
const u8 gText_GoBackPrevMenu[] = _("Go back to the\nprevious menu.");
#endif
#if GERMAN
const u8 gText_WhatWouldYouLike[] = _("Was möchtest du tun?");
#else
const u8 gText_WhatWouldYouLike[] = _("What would you like to do?");
#endif
#if GERMAN
const u8 gMenuText_Give2[] = _("Geben");
#else
const u8 gMenuText_Give2[] = _("GIVE");
#endif
const u8 gText_xVar1[] = _("×{STR_VAR_1}");
#if GERMAN
const u8 gText_Berry2[] = _(" Beere");
#else
const u8 gText_Berry2[] = _(" BERRY");
#endif // Unused
#if GERMAN
const u8 gText_Coins[] = _("{STR_VAR_1} Münz.");
#else
const u8 gText_Coins[] = _("{STR_VAR_1} COINS");
#endif
#if GERMAN
const u8 gText_CloseBag[] = _("Beutel Schliessen");
#else
const u8 gText_CloseBag[] = _("CLOSE BAG");
#endif
#if GERMAN
const u8 gText_Var1IsSelected[] = _("Was möchtest\ndu tun?");
#else
const u8 gText_Var1IsSelected[] = _("{STR_VAR_1}\nis selected.");
#endif
#if GERMAN
const u8 gText_CantWriteMail[] = _("Du kannst keinen\nBrief schreiben.");
#else
const u8 gText_CantWriteMail[] = _("You can't write\nMAIL here.");
#endif
#if GERMAN
const u8 gText_NoPokemon[] = _("Hier ist kein\nPokémon.");
#else
const u8 gText_NoPokemon[] = _("There is no\nPOKéMON.");
#endif
#if GERMAN
const u8 gText_MoveVar1Where[] = _("Gegen welches Item\naustauschen?");
#else
const u8 gText_MoveVar1Where[] = _("Move the\n{STR_VAR_1}\nwhere?");
#endif
#if GERMAN
const u8 gText_Var1CantBeHeld[] = _("{STR_VAR_1} ist nicht zu geben.");
#else
const u8 gText_Var1CantBeHeld[] = _("The {STR_VAR_1} can't be held.");
#endif
#if GERMAN
const u8 gText_TossHowManyVar1s[] = _("Wie viel in den Müll?");
#else
const u8 gText_TossHowManyVar1s[] = _("Toss out how many\n{STR_VAR_1}?");
#endif
#if GERMAN
const u8 gText_ThrewAwayVar2Var1s[] = _("{STR_VAR_2} × {STR_VAR_1}\nweggeworfen.");
#else
const u8 gText_ThrewAwayVar2Var1s[] = _("Threw away {STR_VAR_2}\n{STR_VAR_1}.");
#endif
#if GERMAN
const u8 gText_ConfirmTossItems[] = _("Willst du wirklich\n{STR_VAR_2} × {STR_VAR_1}\nwegwerfen?");
#else
const u8 gText_ConfirmTossItems[] = _("Is it okay to\nthrow away {STR_VAR_2}\n{STR_VAR_1}?");
#endif
#if IS_HNS
    const u8 gText_DadsAdvice[] = _("Lind sagt immer…\n{PLAYER}, dies ist weder der rechte\lOrt noch der rechte Zeitpunkt dafür!{PAUSE_UNTIL_PRESS}");
#else
    const u8 gText_DadsAdvice[] = _("Vati sagt immer……\n{PLAYER}, dies ist weder der rechte\lOrt noch der rechte Zeitpunkt dafür!{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PlayerUsedVar2[] = _("{PLAYER} setzt\n{STR_VAR_2} ein.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PlayerUsedVar2[] = _("{PLAYER} used the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_RepelEffectsLingered[] = _("Aber Schutz wirkt doch\nnoch!{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_RepelEffectsLingered[] = _("But the effects of a REPEL\nlingered from earlier.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_LureEffectsLingered[] = _("Doch die Wirkung eines Lockmittels\nhielt noch an.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_LureEffectsLingered[] = _("But the effects of a Lure\nlingered from earlier.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_BoxFull[] = _("Die Boxen sind voll.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_BoxFull[] = _("The BOX is full.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_TheField[] = _("zum Hauptmenü");
#else
const u8 gText_TheField[] = _("the field");
#endif
#if GERMAN
const u8 gText_TheBattle[] = _("zum Kampf");
#else
const u8 gText_TheBattle[] = _("the battle");
#endif
#if GERMAN
const u8 gText_ThePokemonList[] = _("zur Pokémon-Liste");
#else
const u8 gText_ThePokemonList[] = _("the POKéMON LIST");
#endif
#if GERMAN
const u8 gText_TheShop[] = _("zum Geschäft");
#else
const u8 gText_TheShop[] = _("the shop");
#endif
#if GERMAN
const u8 gText_ThePC[] = _("zum PC");
#else
const u8 gText_ThePC[] = _("the PC");
#endif

const u8 *const gBagMenu_ReturnToStrings[] =
{
    [ITEMMENULOCATION_FIELD]               = gText_TheField,
    [ITEMMENULOCATION_BATTLE]              = gText_TheBattle,
    [ITEMMENULOCATION_PARTY]               = gText_ThePokemonList,
    [ITEMMENULOCATION_SHOP]                = gText_TheShop,
    [ITEMMENULOCATION_BERRY_TREE]          = gText_TheField,
    [ITEMMENULOCATION_BERRY_BLENDER_CRUSH] = gText_TheField,
    [ITEMMENULOCATION_ITEMPC]              = gText_ThePC,
    [ITEMMENULOCATION_FAVOR_LADY]          = gText_TheField,
    [ITEMMENULOCATION_QUIZ_LADY]           = gText_TheField,
    [ITEMMENULOCATION_APPRENTICE]          = gText_TheField,
    [ITEMMENULOCATION_WALLY]               = gText_TheBattle,
    [ITEMMENULOCATION_PCBOX]               = gText_ThePC,
    [ITEMMENULOCATION_BERRY_TREE_MULCH]    = gText_TheField,
};

const u8 *const gPyramidBagMenu_ReturnToStrings[] =
{
    [PYRAMIDBAG_LOC_FIELD]       = gText_TheField,
    [PYRAMIDBAG_LOC_BATTLE]      = gText_TheBattle,
    [PYRAMIDBAG_LOC_PARTY]       = gText_ThePokemonList,
    [PYRAMIDBAG_LOC_CHOOSE_TOSS] = gText_TheField
};

#if GERMAN
const u8 gText_ReturnToVar1[] = _("Zurück\n{STR_VAR_1}.");
#else
const u8 gText_ReturnToVar1[] = _("Return to\n{STR_VAR_1}.");
#endif

const u8 *const gPocketNamesStringsTable[] =
{
    [POCKET_ITEMS] =        COMPOUND_STRING("Items"),
    [POCKET_POKE_BALLS] =   COMPOUND_STRING("Pokébälle"),
    [POCKET_TM_HM]  =       COMPOUND_STRING("TMs & VMs"),
    [POCKET_BERRIES] =      COMPOUND_STRING("Beeren"),
    [POCKET_KEY_ITEMS] =    COMPOUND_STRING("Basis Items"),
    [POCKET_MEDICINE] =     COMPOUND_STRING("Medizin"),
#if I_COMBINE_BAG_POCKETS == FALSE
    [POCKET_BATTLE_ITEMS] = COMPOUND_STRING("Kampf"),
    [POCKET_TREASURES] =    COMPOUND_STRING("Schätze"),
#endif
};

const u8 gText_NumberItem_TMBerry[] = _("{NO}{STR_VAR_1}{CLEAR 0x03}{STR_VAR_2}");
const u8 gText_NumberItem_HM[] = _("{CLEAR_TO 0x11}{STR_VAR_1}{CLEAR 0x05}{STR_VAR_2}");

#if GERMAN
const u8 gText_ShopBuy[] = _("Kaufen");
#else
const u8 gText_ShopBuy[] = _("BUY");
#endif
#if GERMAN
const u8 gText_ShopSell[] = _("Verkaufen");
#else
const u8 gText_ShopSell[] = _("SELL");
#endif
#if GERMAN
const u8 gText_ShopQuit[] = _("Tschüss!");
#else
const u8 gText_ShopQuit[] = _("QUIT");
#endif
#if GERMAN
const u8 gText_ThatItemIsSoldOut[] = _("Tut mir leid, dieses Item ist\nausverkauft.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_ThatItemIsSoldOut[] = _("I'm sorry, but that item is sold out.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_SoldOut[] = _("Ausverkauft");
#else
const u8 gText_SoldOut[] = _("SOLD OUT");
#endif
#if GERMAN
const u8 gText_InBagVar1[] = _("Besitz: {STR_VAR_1}");
#else
const u8 gText_InBagVar1[] = _("IN BAG: {STR_VAR_1}");
#endif
#if GERMAN
const u8 gText_QuitShopping[] = _("Einkauf beenden.");
#else
const u8 gText_QuitShopping[] = _("Quit shopping.");
#endif
#if GERMAN
const u8 gText_Var1CertainlyHowMany[] = _("{STR_VAR_1}? Aber gerne.\nWie viele möchtest du?");
#else
const u8 gText_Var1CertainlyHowMany[] = _("{STR_VAR_1}? Certainly.\nHow many would you like?");
#endif
#if GERMAN
const u8 gText_Var1CertainlyHowMany2[] = _("{STR_VAR_1} ist {STR_VAR_2}!\nGerne. Wie viele möchtest du?");
#else
const u8 gText_Var1CertainlyHowMany2[] = _("{STR_VAR_1}? Certainly.\nHow many would you like?");
#endif
#if GERMAN
const u8 gText_Var1AndYouWantedVar2[] = _("{STR_VAR_1}? Und du möchtest {STR_VAR_2}?\nDas macht dann ¥{STR_VAR_3}.");
#else
const u8 gText_Var1AndYouWantedVar2[] = _("{STR_VAR_1}? And you wanted {STR_VAR_2}?\nThat will be ¥{STR_VAR_3}.");
#endif
#if GERMAN
const u8 gText_Var1AndYouWantedVar2BP[] = _("{STR_VAR_1}? Und du möchtest {STR_VAR_2}?\nDas macht dann {STR_VAR_3}GP.");
#else
const u8 gText_Var1AndYouWantedVar2BP[] = _("{STR_VAR_1}? And you wanted {STR_VAR_2}?\nThat will be {STR_VAR_3}BP.");
#endif
#if GERMAN
const u8 gText_Var1IsItThatllBeVar2[] = _("{STR_VAR_1} soll es sein?\nDas kostet ¥{STR_VAR_2}. Einverstanden?");
#else
const u8 gText_Var1IsItThatllBeVar2[] = _("{STR_VAR_1}, is it?\nThat'll be ¥{STR_VAR_2}. Do you want it?");
#endif
#if GERMAN
const u8 gText_YouWantedVar1ThatllBeVar2[] = _("Du wolltest {STR_VAR_1}?\nDas kostet ¥{STR_VAR_2}. Einverstanden?");
#else
const u8 gText_YouWantedVar1ThatllBeVar2[] = _("You wanted {STR_VAR_1}?\nThat'll be ¥{STR_VAR_2}. Will that be okay?");
#endif
#if GERMAN
const u8 gText_YouWantedVar1ThatllBeVar2BP[] = _("Du möchtest {STR_VAR_1}?\nDas macht {STR_VAR_2}GP. Ist das in Ordnung?");
#else
const u8 gText_YouWantedVar1ThatllBeVar2BP[] = _("You wanted {STR_VAR_1}?\nThat'll be {STR_VAR_2}BP. Will that be okay?");
#endif
#if GERMAN
const u8 gText_HereYouGoThankYou[] = _("Bitte sehr!\nUnd vielen Dank.");
#else
const u8 gText_HereYouGoThankYou[] = _("Here you go!\nThank you very much.");
#endif
#if GERMAN
const u8 gText_ThankYouIllSendItHome[] = _("Vielen Dank!\nEs wird auf deinen PC übertragen.");
#else
const u8 gText_ThankYouIllSendItHome[] = _("Thank you!\nI'll send it to your home PC.");
#endif
#if GERMAN
const u8 gText_ThanksIllSendItHome[] = _("Danke!\nEs wird auf deinen PC übertragen.");
#else
const u8 gText_ThanksIllSendItHome[] = _("Thanks!\nI'll send it to your PC at home.");
#endif
#if GERMAN
const u8 gText_YouDontHaveMoney[] = _("Du hast nicht genug Geld.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_YouDontHaveMoney[] = _("You don't have enough money.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_YouDontHaveEnoughBP[] = _("Du hast nicht genug\nGP.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_YouDontHaveEnoughBP[] = _("You don't have enough\nBP.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_DontHaveEnoughVar1[] = _("Du hast nicht genug\n{STR_VAR_1}.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_DontHaveEnoughVar1[] = _("You don't have enough\n{STR_VAR_1}s.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_Var1SureHowMany[] = _("{STR_VAR_1}? Sicher.\nWie viele möchtest du?");
#else
const u8 gText_Var1SureHowMany[] = _("{STR_VAR_1}s? Sure.\nHow many would you like?");
#endif
const u8 gText_xOne[] = _("x1");
const u8 gText_xFive[] = _("x5");
#if GERMAN
const u8 gText_KurtVar1AndYouWantedVar2Plural[] = _("Du möchtest {STR_VAR_2} davon?\nDas macht {STR_VAR_3} Beeren.");
#else
const u8 gText_KurtVar1AndYouWantedVar2Plural[] = _("And you wanted {STR_VAR_2} of 'em?\nThat will be {STR_VAR_3} berries.");
#endif
#if GERMAN
const u8 gText_KurtVar1AndYouWantedVar2Singular[] = _("Du möchtest {STR_VAR_2} davon?\nDas macht {STR_VAR_3} Beeren.");
#else
const u8 gText_KurtVar1AndYouWantedVar2Singular[] = _("And you wanted {STR_VAR_2} of 'em?\nThat will be {STR_VAR_3} berry.");
#endif
#if GERMAN
const u8 gText_KurtGettingStarted[] = _("Kurt: Ich fange sofort an!");
#else
const u8 gText_KurtGettingStarted[] = _("KURT: I'll get started right now!");
#endif
#if GERMAN
const u8 gText_ExitMenu[] = _("Menü Verlassen");
#else
const u8 gText_ExitMenu[] = _("EXIT MENU");
#endif
#if GERMAN
const u8 gText_NoMoreRoomForThis[] = _("Du hast keinen Platz für weitere Items.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_NoMoreRoomForThis[] = _("You have no more room for this\nitem.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_SpaceForVar1Full[] = _("Es ist kein Platz für {STR_VAR_1}.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_SpaceForVar1Full[] = _("The space for {STR_VAR_1} is full.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_AnythingElseICanHelp[] = _("Gibt es noch etwas, womit\nich dienen kann?");
#else
const u8 gText_AnythingElseICanHelp[] = _("Is there anything else I can help\nyou with?");
#endif
#if GERMAN
const u8 gText_CanIHelpWithAnythingElse[] = _("Kann ich dir sonst noch dienlich sein?");
#else
const u8 gText_CanIHelpWithAnythingElse[] = _("Can I help you with anything else?");
#endif
#if GERMAN
const u8 gText_ThrowInPremierBall[] = _("Ich gebe dir noch einen Premierball.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_ThrowInPremierBall[] = _("I'll throw in a PREMIER BALL, too.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_ThrowInPremierBalls[] = _("Ich gebe dir noch {STR_VAR_1} Premierbälle.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_ThrowInPremierBalls[] = _("I'll throw in {STR_VAR_1} PREMIER BALLS, too.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_CantBuyKeyItem[] = _("{STR_VAR_2}? Es tut mir Leid, aber\ndas kann ich nicht kaufen.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_CantBuyKeyItem[] = _("{STR_VAR_2}? Oh, no.\nI can't buy that.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_HowManyToSell[] = _("{STR_VAR_2}?\nWie viele möchtest du verkaufen?");
#else
const u8 gText_HowManyToSell[] = _("{STR_VAR_2}?\nHow many would you like to sell?");
#endif
#if GERMAN
const u8 gText_ICanPayVar1[] = _("Ich gebe dir ¥{STR_VAR_1}.\nBist du damit einverstanden?");
#else
const u8 gText_ICanPayVar1[] = _("I can pay ¥{STR_VAR_1}.\nWould that be okay?");
#endif
#if GERMAN
const u8 gText_TurnedOverVar1ForVar2[] = _("{STR_VAR_2} wurde übergeben\nim Tausch gegen ¥{STR_VAR_1}.");
#else
const u8 gText_TurnedOverVar1ForVar2[] = _("Turned over the {STR_VAR_2}\nand received ¥{STR_VAR_1}.");
#endif
const u8 gText_PokedollarVar1[] = _("¥{STR_VAR_1}");
#if GERMAN
const u8 gText_HP3[] = _("KP");
#else
const u8 gText_HP3[] = _("HP");
#endif
#if GERMAN
const u8 gText_SpAtk3[] = _("Sp. Ang.");
#else
const u8 gText_SpAtk3[] = _("SP. ATK");
#endif
#if GERMAN
const u8 gText_SpDef3[] = _("Sp. Ver.");
#else
const u8 gText_SpDef3[] = _("SP. DEF");
#endif
#if GERMAN
const u8 gText_WontHaveEffect[] = _("Es wird keine Wirkung haben.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_WontHaveEffect[] = _("It won't have any effect.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_NextFusionMon[] = _("Wähle das {PKMN} zum Fusionieren.");
#else
const u8 gText_NextFusionMon[] = _("Choose {PKMN} to fuse with.");
#endif
#if GERMAN
const u8 gText_CantBeUsedOnPkmn[] = _("Das kann nicht bei diesem\nPokémon eingesetzt werden.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_CantBeUsedOnPkmn[] = _("This can't be used on\nthat POKéMON.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnCantSwitchOut[] = _("{STR_VAR_1} kann nicht ausge-\ntauscht werden!{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnCantSwitchOut[] = _("{STR_VAR_1} can't be switched\nout!{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnAlreadyInBattle[] = _("{STR_VAR_1}\nkämpft bereits!{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnAlreadyInBattle[] = _("{STR_VAR_1} is already\nin battle!{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnAlreadySelected[] = _("{STR_VAR_1} ist\nbereits ausgewählt.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnAlreadySelected[] = _("{STR_VAR_1} has already been\nselected.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnHasNoEnergy[] = _("{STR_VAR_1} kann\nnicht kämpfen!{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnHasNoEnergy[] = _("{STR_VAR_1} has no energy\nleft to battle!{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_CantSwitchWithAlly[] = _("Ein Pokémon von {STR_VAR_1} ist\nnicht gegen deins eintauschbar!{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_CantSwitchWithAlly[] = _("You can't switch {STR_VAR_1}'s\nPOKéMON with one of yours!{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_EggCantBattle[] = _("Ein Ei kann nicht kämpfen!{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_EggCantBattle[] = _("An EGG can't battle!{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_CantUseUntilNewBadge[] = _("Das ist erst einsetzbar, wenn\nein neuer Orden errungen wurde.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_CantUseUntilNewBadge[] = _("This can't be used until a new\nBADGE is obtained.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_NoMoreThanVar1Pkmn[] = _("Es können nicht mehr als\n{STR_VAR_1} Pokémon teilnehmen.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_NoMoreThanVar1Pkmn[] = _("No more than {STR_VAR_1} POKéMON\nmay enter.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_SendMailToPC[] = _("Den abgenommenen Brief\nauf deinen PC übertragen?");
#else
const u8 gText_SendMailToPC[] = _("Send the removed MAIL to\nyour PC?");
#endif
#if GERMAN
const u8 gText_MailSentToPC[] = _("Der Brief wurde auf deinen\nPC übertragen.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_MailSentToPC[] = _("The MAIL was sent to your PC.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PCMailboxFull[] = _("Du kannst keine weiteren Briefe\nauf deinen PC übertragen.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PCMailboxFull[] = _("Your PC's MAILBOX is full.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_MailMessageWillBeLost[] = _("Wird der Brief entfernt, geht\nder Inhalt verloren, okay?");
#else
const u8 gText_MailMessageWillBeLost[] = _("If the MAIL is removed, the\nmessage will be lost. Okay?");
#endif
#if GERMAN
const u8 gText_RemoveMailBeforeItem[] = _("Der Brief muss entfernt werden,\num ein Item tragen zu können.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_RemoveMailBeforeItem[] = _("MAIL must be removed before\nholding an item.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnWasGivenItem[] = _("{STR_VAR_1} erhält\n{STR_VAR_2} zum Tragen.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnWasGivenItem[] = _("{STR_VAR_1} was given the\n{STR_VAR_2} to hold.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnAlreadyHoldingItemSwitch[] = _("{STR_VAR_1} trägt bereits\n{STR_VAR_2}.\pSollen die Items ausge-\ntauscht werden?");
#else
const u8 gText_PkmnAlreadyHoldingItemSwitch[] = _("{STR_VAR_1} is already holding\none {STR_VAR_2}.\pWould you like to switch the\ntwo items?");
#endif
#if GERMAN
const u8 gText_PkmnNotHolding[] = _("{STR_VAR_1} trägt\nkein Item.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnNotHolding[] = _("{STR_VAR_1} isn't holding\nanything.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_ReceivedItemFromPkmn[] = _("{STR_VAR_2} von\n{STR_VAR_1} erhalten.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_ReceivedItemFromPkmn[] = _("Received the {STR_VAR_2}\nfrom {STR_VAR_1}.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_MailTakenFromPkmn[] = _("Der Brief wurde dem\nPokémon abgenommen.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_MailTakenFromPkmn[] = _("MAIL was taken from the\nPOKéMON.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_SwitchedPkmnItem[] = _("{STR_VAR_2} wurde gegen\n{STR_VAR_1} ausgetauscht.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_SwitchedPkmnItem[] = _("The {STR_VAR_2} was taken and\nreplaced with the {STR_VAR_1}.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnHoldingItemCantHoldMail[] = _("Dieses Pokémon trägt ein Item.\nEs kann keinen Brief tragen.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnHoldingItemCantHoldMail[] = _("This POKéMON is holding an\nitem. It cannot hold MAIL.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_MailTransferredFromMailbox[] = _("Der Brief wurde von deinem\nPC heruntergeladen.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_MailTransferredFromMailbox[] = _("MAIL was transferred from\nthe MAILBOX.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_BagFullCouldNotRemoveItem[] = _("Der Beutel ist voll. Das Item\ndes Pokémon wurde nicht entfernt.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_BagFullCouldNotRemoveItem[] = _("The BAG is full. The POKéMON's\nitem could not be removed.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnLearnedMove3[] = _("{STR_VAR_1} erlernt\n{STR_VAR_2}!");
#else
const u8 gText_PkmnLearnedMove3[] = _("{STR_VAR_1} learned\n{STR_VAR_2}!");
#endif
#if GERMAN
const u8 gText_PkmnLearnedMove4[] = _("{STR_VAR_1} erlernt\n{STR_VAR_2}!{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnLearnedMove4[] = _("{STR_VAR_1} learned\n{STR_VAR_2}!{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnCantLearnMove[] = _("{STR_VAR_1} und {STR_VAR_2}\nsind nicht kompatibel.\p{STR_VAR_2} kann nicht \nerlernt werden.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnCantLearnMove[] = _("{STR_VAR_1} and {STR_VAR_2}\nare not compatible.\p{STR_VAR_2} can't be\nlearned.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnNeedsToReplaceMove[] = _("{STR_VAR_1} versucht,\n{STR_VAR_2} zu erlernen.\pAber {STR_VAR_1} kann maximal\nvier Attacken erlernen.\pSoll eine andere Attacke durch\n{STR_VAR_2} ersetzt werden?");
#else
const u8 gText_PkmnNeedsToReplaceMove[] = _("{STR_VAR_1} wants to learn the\nmove {STR_VAR_2}.\pHowever, {STR_VAR_1} already\nknows four moves.\pShould a move be deleted and\nreplaced with {STR_VAR_2}?");
#endif
#if GERMAN
const u8 gText_StopLearningMove2[] = _("{STR_VAR_2} nicht\nerlernen?");
#else
const u8 gText_StopLearningMove2[] = _("Stop trying to teach\n{STR_VAR_2}?");
#endif
#if GERMAN
const u8 gText_MoveNotLearned[] = _("{STR_VAR_1} hat {STR_VAR_2}\nnicht erlernt.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_MoveNotLearned[] = _("{STR_VAR_1} did not learn the\nmove {STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_WhichMoveToForget[] = _("Welche Attacke soll vergessen\nwerden?{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_WhichMoveToForget[] = _("Which move should be forgotten?{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_12PoofForgotMove[] = _("1, {PAUSE 15}2 und{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1} Schwupp!\p{STR_VAR_1} hat\n{STR_VAR_2} vergessen.\pUnd…{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_12PoofForgotMove[] = _("1, {PAUSE 15}2, and{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Poof!\p{STR_VAR_1} forgot how to\nuse {STR_VAR_2}.\pAnd…{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnAlreadyKnows[] = _("{STR_VAR_1} kennt\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnAlreadyKnows[] = _("{STR_VAR_1} already knows\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnHPRestoredByVar2[] = _("Die KP von {STR_VAR_1} wurden\num {STR_VAR_2} Punkt(e) aufgefüllt.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnHPRestoredByVar2[] = _("{STR_VAR_1}'s HP was restored\nby {STR_VAR_2} point(s).{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnCuredOfPoison[] = _("Die Vergiftung von {STR_VAR_1}\nwurde geheilt.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnCuredOfPoison[] = _("{STR_VAR_1} was cured of its\npoisoning.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnCuredOfParalysis[] = _("Die Paralyse von {STR_VAR_1}\nwurde aufgehoben.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnCuredOfParalysis[] = _("{STR_VAR_1} was cured of\nparalysis.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnWokeUp2[] = _("{STR_VAR_1} ist aufgewacht.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnWokeUp2[] = _("{STR_VAR_1} woke up.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnBurnHealed[] = _("Verbrennung von {STR_VAR_1}\nwurde geheilt.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnBurnHealed[] = _("{STR_VAR_1}'s burn was healed.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnFrostbiteHealed[] = _("{STR_VAR_1}s Erfrierung wurde geheilt.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnFrostbiteHealed[] = _("{STR_VAR_1}'s frostbite was healed.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnThawedOut[] = _("{STR_VAR_1} wurde aufgetaut.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnThawedOut[] = _("{STR_VAR_1} was thawed out.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PPWasRestored[] = _("AP wurden aufgefüllt.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PPWasRestored[] = _("PP was restored.{PAUSE_UNTIL_PRESS}");
#endif
const u8 gText_PkmnRegainhedHealth[] = _("{STR_VAR_1} regained health.{PAUSE_UNTIL_PRESS}"); // Unused
#if GERMAN
const u8 gText_PkmnBecameHealthy[] = _("{STR_VAR_1} erholte sich.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnBecameHealthy[] = _("{STR_VAR_1} became healthy.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_MovesPPIncreased[] = _("AP von {STR_VAR_1}\nwurden angehoben.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_MovesPPIncreased[] = _("{STR_VAR_1}'s PP increased.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnElevatedToLvVar2[] = _("{STR_VAR_1} erreicht\nLv. {STR_VAR_2}.");
#else
const u8 gText_PkmnElevatedToLvVar2[] = _("{STR_VAR_1} was elevated to\nLv. {STR_VAR_2}.");
#endif
const u8 gText_PkmnGainedExp[] = _("{STR_VAR_1} gained {STR_VAR_2} Exp. Points!{PAUSE_UNTIL_PRESS}");
#if GERMAN
const u8 gText_PkmnGainedExpAndElevatedToLvVar3[] = _("{STR_VAR_1} erreicht\nLv. {STR_VAR_3}.");
#else
const u8 gText_PkmnGainedExpAndElevatedToLvVar3[] = _("{STR_VAR_1} gained {STR_VAR_2} Exp. Points\nand was elevated to Lv. {STR_VAR_3}!");
#endif
#if GERMAN
const u8 gText_PkmnBaseVar2StatIncreased[] = _("{STR_VAR_2} von\n{STR_VAR_1} wurde angehoben.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnBaseVar2StatIncreased[] = _("{STR_VAR_1}'s base {STR_VAR_2}\nstat was raised.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnFriendlyBaseVar2Fell[] = _("{STR_VAR_1} wird zahm.\nDer Grundwert {STR_VAR_2} sinkt.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnFriendlyBaseVar2Fell[] = _("{STR_VAR_1} turned friendly.\nThe base {STR_VAR_2} fell!{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnAdoresBaseVar2Fell[] = _("{STR_VAR_1} vergöttert dich!\nDer Grundwert {STR_VAR_2} sinkt.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnAdoresBaseVar2Fell[] = _("{STR_VAR_1} adores you!\nThe base {STR_VAR_2} fell!{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnFriendlyBaseVar2CantFall[] = _("{STR_VAR_1} wird zahm. Grund-\nwert {STR_VAR_2} sinkt nicht mehr.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnFriendlyBaseVar2CantFall[] = _("{STR_VAR_1} turned friendly.\nThe base {STR_VAR_2} can't fall!{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnSnappedOutOfConfusion[] = _("{STR_VAR_1} ist nicht\nmehr verwirrt.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnSnappedOutOfConfusion[] = _("{STR_VAR_1} snapped out of its\nconfusion.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_PkmnGotOverInfatuation[] = _("{STR_VAR_1} fühlt sich nicht\nmehr angezogen.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnGotOverInfatuation[] = _("{STR_VAR_1} got over its\ninfatuation.{PAUSE_UNTIL_PRESS}");
#endif
const u8 gText_PkmnTransformed[] = _("{STR_VAR_1} transformed!{PAUSE_UNTIL_PRESS}");
#if GERMAN
const u8 gText_ThrowAwayItem[] = _("{STR_VAR_1}\nwegwerfen?");
#else
const u8 gText_ThrowAwayItem[] = _("Throw away this\n{STR_VAR_1}?");
#endif
#if GERMAN
const u8 gText_ItemThrownAway[] = _("{STR_VAR_1}\nwurde weggeworfen.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_ItemThrownAway[] = _("The {STR_VAR_1}\nwas thrown away.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_TeachWhichPokemon2[] = _("Teach which Pokémon?");
#else
const u8 gText_TeachWhichPokemon2[] = _("Teach which POKéMON?");
#endif // Unused
#if GERMAN
const u8 gText_ChoosePokemon[] = _("Wähle ein Pokémon.");
#else
const u8 gText_ChoosePokemon[] = _("Choose a POKéMON.");
#endif
#if GERMAN
const u8 gText_MoveToWhere[] = _("An wessen Stelle setzen?");
#else
const u8 gText_MoveToWhere[] = _("Move to where?");
#endif
#if GERMAN
const u8 gText_TeachWhichPokemon[] = _("Welches Pokémon lehren?");
#else
const u8 gText_TeachWhichPokemon[] = _("Teach which POKéMON?");
#endif
#if GERMAN
const u8 gText_UseOnWhichPokemon[] = _("Welches Pokémon?");
#else
const u8 gText_UseOnWhichPokemon[] = _("Use on which POKéMON?");
#endif
#if GERMAN
const u8 gText_GiveToWhichPokemon[] = _("Welchem Pokémon geben?");
#else
const u8 gText_GiveToWhichPokemon[] = _("Give to which POKéMON?");
#endif
#if GERMAN
const u8 gText_DoWhatWithPokemon[] = _("Was tun mit {STR_VAR_1}?");
#else
const u8 gText_DoWhatWithPokemon[] = _("Do what with this {PKMN}?");
#endif
#if GERMAN
const u8 gText_NothingToCut[] = _("Hier nicht einsetzbar.");
#else
const u8 gText_NothingToCut[] = _("There's nothing to CUT.");
#endif
#if GERMAN
const u8 gText_CantSurfHere[] = _("Surfer nicht einsetzbar.");
#else
const u8 gText_CantSurfHere[] = _("You can't SURF here.");
#endif
#if GERMAN
const u8 gText_AlreadySurfing[] = _("Surfer ist eingesetzt.");
#else
const u8 gText_AlreadySurfing[] = _("You're already SURFING.");
#endif
#if GERMAN
const u8 gText_CantUseHere[] = _("Hier nicht einsetzbar.");
#else
const u8 gText_CantUseHere[] = _("Can't use that here.");
#endif
#if GERMAN
const u8 gText_RestoreWhichMove[] = _("Welche Att. auffüllen?");
#else
const u8 gText_RestoreWhichMove[] = _("Restore which move?");
#endif
#if GERMAN
const u8 gText_BoostPp[] = _("AP welcher Att. heben?");
#else
const u8 gText_BoostPp[] = _("Boost PP of which move?");
#endif
#if GERMAN
const u8 gText_DoWhatWithItem[] = _("Was willst du mit dem Item?");
#else
const u8 gText_DoWhatWithItem[] = _("Do what with an item?");
#endif
#if GERMAN
const u8 gText_NoPokemonForBattle[] = _("Kein Pokémon kampfbereit!");
#else
const u8 gText_NoPokemonForBattle[] = _("No POKéMON for battle!");
#endif
#if GERMAN
const u8 gText_ChoosePokemon2[] = _("Wähle ein Pokémon.");
#else
const u8 gText_ChoosePokemon2[] = _("Choose a POKéMON.");
#endif
#if GERMAN
const u8 gText_NotEnoughHp[] = _("Nicht genügend KP…");
#else
const u8 gText_NotEnoughHp[] = _("Not enough HP…");
#endif
#if GERMAN
const u8 gText_PokemonAreNeeded[] = _("{STR_VAR_1} Pokémon sind nötig.");
#else
const u8 gText_PokemonAreNeeded[] = _("{STR_VAR_1} POKéMON are needed.");
#endif
#if GERMAN
const u8 gText_PokemonCantBeSame[] = _("Nicht dieselben Pokémon!");
#else
const u8 gText_PokemonCantBeSame[] = _("POKéMON can't be the same.");
#endif
#if GERMAN
const u8 gText_NoIdenticalHoldItems[] = _("Nicht dieselben Items!");
#else
const u8 gText_NoIdenticalHoldItems[] = _("No identical hold items.");
#endif
#if GERMAN
const u8 gText_CurrentIsTooFast[] = _("Die Strömung ist zu stark!");
#else
const u8 gText_CurrentIsTooFast[] = _("The current is much too fast!");
#endif
#if GERMAN
const u8 gText_DoWhatWithMail[] = _("Was ist mit dem Brief?");
#else
const u8 gText_DoWhatWithMail[] = _("Do what with the MAIL?");
#endif
#if GERMAN
const u8 gText_ChoosePokemonCancel[] = _("Wähle Pkmn oder Zurück.");
#else
const u8 gText_ChoosePokemonCancel[] = _("Choose POKéMON or CANCEL.");
#endif
#if GERMAN
const u8 gText_ChoosePokemonConfirm[] = _("Wähle ein Pkmn und bestätige.");
#else
const u8 gText_ChoosePokemonConfirm[] = _("Choose POKéMON and confirm.");
#endif
#if GERMAN
const u8 gText_SendWhichMonToPC[] = _("Welches Pokémon zum PC senden?");
#else
const u8 gText_SendWhichMonToPC[] = _("Send which POKéMON to the PC?");
#endif
#if GERMAN
const u8 gText_MoveItemWhere[] = _("Item wohin bewegen?");
#else
const u8 gText_MoveItemWhere[] = _("Move item to where?");
#endif
#if GERMAN
const u8 gText_XsYAnd[] = _("{STR_VAR_1}'s {STR_VAR_2} und\n");
#else
const u8 gText_XsYAnd[] = _("{STR_VAR_1}'s {STR_VAR_2} and\n");
#endif
#if GERMAN
const u8 gText_XsYWereSwapped[] = _("{STR_VAR_1}'s {STR_VAR_2} wurden getauscht!{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_XsYWereSwapped[] = _("{STR_VAR_1}'s {STR_VAR_2} were swapped!{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_EnjoyCycling[] = _("Lass uns Rad fahren!");
#else
const u8 gText_EnjoyCycling[] = _("Let's enjoy cycling!");
#endif
#if GERMAN
const u8 gText_InUseAlready_PM[] = _("Das wird bereits benutzt.");
#else
const u8 gText_InUseAlready_PM[] = _("This is in use already.");
#endif
#if GERMAN
const u8 gText_AlreadyHoldingOne[] = _("{STR_VAR_1} trägt bereits\n{STR_VAR_2}.");
#else
const u8 gText_AlreadyHoldingOne[] = _("{STR_VAR_1} is already holding\none {STR_VAR_2}.");
#endif
#if GERMAN
const u8 gText_WhichAppliance[] = _("Welches Haushaltsgerät\nmöchtest du bestellen?");
#else
const u8 gText_WhichAppliance[] = _("Order which\nappliance?");
#endif
#if GERMAN
const u8 gText_NoUse[] = _("Unnütz!");
#else
const u8 gText_NoUse[] = _("No use.");
#endif
#if GERMAN
const u8 gText_Able[] = _("O.K.");
#else
const u8 gText_Able[] = _("ABLE");
#endif
#if GERMAN
const u8 gText_First_PM[] = _("Erstes");
#else
const u8 gText_First_PM[] = _("FIRST");
#endif
#if GERMAN
const u8 gText_Second_PM[] = _("Zweites");
#else
const u8 gText_Second_PM[] = _("SECOND");
#endif
#if GERMAN
const u8 gText_Third_PM[] = _("Drittes");
#else
const u8 gText_Third_PM[] = _("THIRD");
#endif
#if GERMAN
const u8 gText_Able2[] = _("O.K.");
#else
const u8 gText_Able2[] = _("ABLE");
#endif
#if GERMAN
const u8 gText_NotAble[] = _("Nein");
#else
const u8 gText_NotAble[] = _("NOT ABLE");
#endif
#if GERMAN
const u8 gText_Able3[] = _("O.K.");
#else
const u8 gText_Able3[] = _("ABLE!");
#endif
#if GERMAN
const u8 gText_NotAble2[] = _("Nein");
#else
const u8 gText_NotAble2[] = _("NOT ABLE!");
#endif
#if GERMAN
const u8 gText_Learned[] = _("Kennt Att.");
#else
const u8 gText_Learned[] = _("LEARNED");
#endif
#if GERMAN
const u8 gText_Have[] = _("Haben");
#else
const u8 gText_Have[] = _("HAVE");
#endif
#if GERMAN
const u8 gText_DontHave[] = _("Nix Haben");
#else
const u8 gText_DontHave[] = _("DON'T HAVE");
#endif
#if GERMAN
const u8 gText_Fourth[] = _("Viertes");
#else
const u8 gText_Fourth[] = _("FOURTH");
#endif
#if GERMAN
const u8 gText_PkmnCantParticipate[] = _("Dieses Pkmn kann nicht teilnehmen.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_PkmnCantParticipate[] = _("That POKéMON can't participate.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_CancelParticipation[] = _("Teilnahme absagen?");
#else
const u8 gText_CancelParticipation[] = _("Cancel participation?");
#endif
#if GERMAN
const u8 gText_CancelBattle[] = _("Kampf absagen?");
#else
const u8 gText_CancelBattle[] = _("Cancel the battle?");
#endif
#if GERMAN
const u8 gText_ReturnToWaitingRoom[] = _("Zurück ins Wartezimmer?");
#else
const u8 gText_ReturnToWaitingRoom[] = _("Return to the WAITING ROOM?");
#endif
#if GERMAN
const u8 gText_CancelChallenge[] = _("Herausforderung widerrufen?");
#else
const u8 gText_CancelChallenge[] = _("Cancel the challenge?");
#endif
#if GERMAN
const u8 gText_EscapeFromHere[] = _("Von hier fliehen und nach\n{STR_VAR_1} zurückkehren?");
#else
const u8 gText_EscapeFromHere[] = _("Want to escape from here and return\nto {STR_VAR_1}?");
#endif
#if GERMAN
const u8 gText_ReturnToHealingSpot[] = _("Zum heilenden Ort in {STR_VAR_1}\nzurückkehren?");
#else
const u8 gText_ReturnToHealingSpot[] = _("Want to return to the healing spot\nused last in {STR_VAR_1}?");
#endif
const u8 gText_PauseUntilPress[] = _("{PAUSE_UNTIL_PRESS}");
const u8 gJPText_AreYouSureYouWantToSpinTradeMon[] = _("{STR_VAR_1}を ぐるぐるこうかんに\nだして よろしいですか？");
#if GERMAN
ALIGNED(4) const u8 gText_OnlyPkmnForBattle[] = _("Das ist das einzige\nPokémon zum Kampf.");
#else
ALIGNED(4) const u8 gText_OnlyPkmnForBattle[] = _("That's your only\nPOKéMON for battle.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_PkmnCantBeTradedNow[] = _("Dieses Pokémon kann jetzt\nnicht getauscht werden.");
#else
ALIGNED(4) const u8 gText_PkmnCantBeTradedNow[] = _("That POKéMON can't be traded\nnow.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_PkmnCantBeTraded[] = _("Dieses Pokémon kann nicht\ngetauscht werden.");
#else
ALIGNED(4) const u8 gText_PkmnCantBeTraded[] = _("That POKéMON can't be traded.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_EggCantBeTradedNow[] = _("Ei jetzt nicht tauschbar.");
#else
ALIGNED(4) const u8 gText_EggCantBeTradedNow[] = _("An EGG can't be traded now.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_OtherTrainersPkmnCantBeTraded[] = _("Pkmn des anderen Trainers kann\njetzt nicht getauscht werden.");
#else
ALIGNED(4) const u8 gText_OtherTrainersPkmnCantBeTraded[] = _("The other TRAINER's POKéMON\ncan't be traded now.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_OtherTrainerCantAcceptPkmn[] = _("Der andere Trainer kann das\nPkmn jetzt nicht akzeptieren.");
#else
ALIGNED(4) const u8 gText_OtherTrainerCantAcceptPkmn[] = _("The other TRAINER can't accept\nthat POKéMON now.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_CantTradeWithTrainer[] = _("Du kannst mit diesem Trainer\njetzt keine Pkmn tauschen.");
#else
ALIGNED(4) const u8 gText_CantTradeWithTrainer[] = _("You can't trade with that\nTRAINER now.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_NotPkmnOtherTrainerWants[] = _("Diese Art von Pokémon möchte\nder andere Trainer nicht.");
#else
ALIGNED(4) const u8 gText_NotPkmnOtherTrainerWants[] = _("That isn't the type of POKéMON\nthat the other TRAINER wants.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_ThatIsntAnEgg[] = _("Dies ist kein Ei!");
#else
ALIGNED(4) const u8 gText_ThatIsntAnEgg[] = _("That isn't an EGG.");
#endif
#if GERMAN
const u8 gText_Register[] = _("Wählen");
#else
const u8 gText_Register[] = _("REGISTER");
#endif
#if GERMAN
const u8 gText_Attack3[] = _("Angriff");
#else
const u8 gText_Attack3[] = _("ATTACK");
#endif
#if GERMAN
const u8 gText_Defense3[] = _("Vert.");
#else
const u8 gText_Defense3[] = _("DEFENSE");
#endif
#if GERMAN
const u8 gText_SpAtk4[] = _("Sp.Ang.");
#else
const u8 gText_SpAtk4[] = _("SP. ATK");
#endif
#if GERMAN
const u8 gText_SpDef4[] = _("Sp.Ver.");
#else
const u8 gText_SpDef4[] = _("SP. DEF");
#endif
#if GERMAN
const u8 gText_Speed2[] = _("Init.");
#else
const u8 gText_Speed2[] = _("SPEED");
#endif
#if GERMAN
const u8 gText_HP4[] = _("KP");
#else
const u8 gText_HP4[] = _("HP");
#endif
const u8 gText_EmptyString8[] = _(""); // Unused
#if GERMAN
const u8 gText_OTSlash[] = _("OT:");
#else
const u8 gText_OTSlash[] = _("OT/");
#endif
#if GERMAN
const u8 gText_RentalPkmn[] = _("Leih-Pokémon");
#else
const u8 gText_RentalPkmn[] = _("RENTAL POKéMON");
#endif
#if GERMAN
const u8 gText_TypeSlash[] = _("Typ:");
#else
const u8 gText_TypeSlash[] = _("TYPE/");
#endif
#if GERMAN
const u8 gText_Power[] = _("Stärke");
#else
const u8 gText_Power[] = _("POWER");
#endif
#if GERMAN
const u8 gText_Accuracy2[] = _("Genau.");
#else
const u8 gText_Accuracy2[] = _("ACCURACY");
#endif
#if GERMAN
const u8 gText_Appeal[] = _("Ausdr.");
#else
const u8 gText_Appeal[] = _("APPEAL");
#endif
#if GERMAN
const u8 gText_Jam[] = _("Eindr.");
#else
const u8 gText_Jam[] = _("JAM");
#endif
#if GERMAN
const u8 gText_Status[] = _("Status");
#else
const u8 gText_Status[] = _("STATUS");
#endif
#if GERMAN
const u8 gText_ExpPoints[] = _("E.-Punkte");
#else
const u8 gText_ExpPoints[] = _("EXP. POINTS");
#endif
#if GERMAN
const u8 gText_NextLv[] = _("Nächst. Lv.");
#else
const u8 gText_NextLv[] = _("NEXT LV.");
#endif
#if GERMAN
const u8 gText_RibbonsVar1[] = _("Bänder: {STR_VAR_1}");
#else
const u8 gText_RibbonsVar1[] = _("RIBBONS: {STR_VAR_1}");
#endif
const u8 gText_EmptyString5[] = _("");
#if GERMAN
const u8 gText_Events[] = _("Events");
#else
const u8 gText_Events[] = _("EVENTS");
#endif // Unused
#if GERMAN
const u8 gText_Switch[] = _("Tausch");
#else
const u8 gText_Switch[] = _("SWITCH");
#endif
#if GERMAN
const u8 gText_PkmnInfo[] = _("Pokémon-Info");
#else
const u8 gText_PkmnInfo[] = _("POKéMON INFO");
#endif
#if GERMAN
const u8 gText_PkmnSkills[] = _("Pokémon-Fähig.");
#else
const u8 gText_PkmnSkills[] = _("POKéMON SKILLS");
#endif
#if GERMAN
const u8 gText_BattleMoves[] = _("Attacken");
#else
const u8 gText_BattleMoves[] = _("BATTLE MOVES");
#endif
#if GERMAN
const u8 gText_ContestMoves[] = _("Wett.-Attacken");
#else
const u8 gText_ContestMoves[] = _("CONTEST MOVES");
#endif
#if GERMAN
const u8 gText_Info[] = _("Info");
#else
const u8 gText_Info[] = _("INFO");
#endif
#if GERMAN
const u8 gText_EggWillTakeALongTime[] = _("Dieses Ei braucht sicher\nnoch sehr viel Zeit.");
#else
const u8 gText_EggWillTakeALongTime[] = _("It looks like this EGG will\ntake a long time to hatch.");
#endif
#if GERMAN
const u8 gText_EggWillTakeSomeTime[] = _("Was da wohl schlüpfen wird?\nEs wird sicher lange dauern.");
#else
const u8 gText_EggWillTakeSomeTime[] = _("What will hatch from this?\nIt will take some time.");
#endif
#if GERMAN
const u8 gText_EggWillHatchSoon[] = _("Bewegungen… Da wird\nwohl bald etwas schlüpfen.");
#else
const u8 gText_EggWillHatchSoon[] = _("It moves occasionally.\nIt should hatch soon.");
#endif
#if GERMAN
const u8 gText_EggAboutToHatch[] = _("Geräusche! Da schlüpft\nsicher bald etwas!");
#else
const u8 gText_EggAboutToHatch[] = _("It's making sounds.\nIt's about to hatch!");
#endif
#if GERMAN
const u8 gText_EggReadyToHatch_Nuzlocke[] = _("Würde schlüpfen, aber\nvon Nuzlocke blockiert!");
#else
const u8 gText_EggReadyToHatch_Nuzlocke[] = _("Ready to hatch, but blocked\nby Nuzlocke encounter!");
#endif
#if GERMAN
const u8 gText_HMMovesCantBeForgotten2[] = _("VM-Attacken können jetzt\nnicht vergessen werden.");
#else
const u8 gText_HMMovesCantBeForgotten2[] = _("HM moves can't be\nforgotten now.");
#endif
#if GERMAN
const u8 gText_XNatureMetAtYZ[] = _("Wesen: {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7},\n{LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1},\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}.");
#else
const u8 gText_XNatureMetAtYZ[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7} nature,\nmet at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1},\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}.");
#endif
#if GERMAN
const u8 gText_XNatureHatchedAtYZ[] = _("Wesen: {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7},\ngeschlüpft mit {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1},\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}.");
#else
const u8 gText_XNatureHatchedAtYZ[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7} nature,\nhatched at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1},\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}.");
#endif
#if GERMAN
const u8 gText_XNatureObtainedInTrade[] = _("Wesen: {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7},\nin einem Tausch erhalten.");
#else
const u8 gText_XNatureObtainedInTrade[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7} nature,\nobtained in a trade.");
#endif
#if GERMAN
const u8 gText_XNatureFatefulEncounter[] = _("Wesen: {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7},\nin schicksalhafter Begeg-\nnung mit {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1} erhalten.");
#else
const u8 gText_XNatureFatefulEncounter[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7} nature,\nobtained in a fateful\nencounter at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}.");
#endif
#if GERMAN
const u8 gText_XNatureProbablyMetAt[] = _("Wesen: {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7}, gefangen\nvermutlich mit {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1},\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}.");
#else
const u8 gText_XNatureProbablyMetAt[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7} nature,\nprobably met at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1},\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}.");
#endif
#if GERMAN
const u8 gText_XNature[] = _("Wesen: {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7}");
#else
const u8 gText_XNature[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7} nature");
#endif
#if GERMAN
const u8 gText_XNatureMetSomewhereAt[] = _("Wesen: {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7},\nirgendwo getroffen\nmit {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}.");
#else
const u8 gText_XNatureMetSomewhereAt[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7} nature,\nmet somewhere at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}.");
#endif
#if GERMAN
const u8 gText_XNatureHatchedSomewhereAt[] = _("Wesen: {DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7}, irgendwo\ngeschlüpft mit {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}.");
#else
const u8 gText_XNatureHatchedSomewhereAt[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}{DYNAMIC 6}{DYNAMIC 7} nature,\nhatched somewhere at {LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}.");
#endif
#if GERMAN
const u8 gText_OddEggFoundByCouple[] = _("Seltsames Pokémon-Ei, das\ndie Pensionsleitung fand.");
#else
const u8 gText_OddEggFoundByCouple[] = _("An odd POKéMON EGG found\nby the DAY CARE couple.");
#endif
#if GERMAN
const u8 gText_PeculiarEggNicePlace[] = _("Kurioses Pokémon-Ei, an\nhübschem Ort erhalten.");
#else
const u8 gText_PeculiarEggNicePlace[] = _("A peculiar POKéMON EGG\nobtained at the nice place.");
#endif
#if GERMAN
const u8 gText_PeculiarEggTrade[] = _("Kurioses Pokémon-Ei, im\nTausch erhalten.");
#else
const u8 gText_PeculiarEggTrade[] = _("A peculiar POKéMON EGG\nobtained in a trade.");
#endif
#if GERMAN
const u8 gText_EggFromHotSprings[] = _("Ein Pokémon-Ei, an den\nHeißen Quellen erhalten.");
#else
const u8 gText_EggFromHotSprings[] = _("A POKéMON EGG obtained\nat the hot springs.");
#endif
#if GERMAN
const u8 gText_OddEggFromDaycare[] = _("Ein seltsames Pokémon-Ei\nvon der Pension.");
#else
const u8 gText_OddEggFromDaycare[] = _("An odd POKéMON EGG\nobtained at the daycare.");
#endif
#if GERMAN
const u8 gText_EggFromTraveler[] = _("Ein seltsames Pokémon-Ei\nvon einem Reisenden.");
#else
const u8 gText_EggFromTraveler[] = _("An odd POKéMON EGG\nobtained from a traveler.");
#endif
#if GERMAN
const u8 gText_ApostropheSBase[] = _("Basis v. {STR_VAR_1}");
#else
const u8 gText_ApostropheSBase[] = _("'s BASE");
#endif
#if GERMAN
const u8 gText_OkayToDeleteFromRegistry[] = _("Soll {STR_VAR_1} aus dem Grundbuch\ngelöscht werden?");
#else
const u8 gText_OkayToDeleteFromRegistry[] = _("Is it okay to delete {STR_VAR_1}\nfrom the REGISTRY?");
#endif
#if GERMAN
const u8 gText_RegisteredDataDeleted[] = _("Eingetragene Daten wurden gelöscht.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_RegisteredDataDeleted[] = _("The registered data was deleted.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_NoRegistry[] = _("Es gibt kein Grundbuch.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_NoRegistry[] = _("There is no REGISTRY.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_DelRegist[] = _("Eintr. Löschen");
#else
const u8 gText_DelRegist[] = _("DEL REGIST.");
#endif
const u8 gText_Var3Var1SlashVar2[] = _("{STR_VAR_3}{STR_VAR_1}/{STR_VAR_2}"); // Unused
#if GERMAN
const u8 gText_Decorate[] = _("Dekorieren");
#else
const u8 gText_Decorate[] = _("DECORATE");
#endif
#if GERMAN
const u8 gText_PutAway[] = _("Wegnehmen");
#else
const u8 gText_PutAway[] = _("PUT AWAY");
#endif
#if GERMAN
const u8 gText_Toss2[] = _("Wegwerfen");
#else
const u8 gText_Toss2[] = _("TOSS");
#endif
const u8 gText_Color161Shadow161[] = _("{COLOR 161}{SHADOW 161}");
#if GERMAN
const u8 gText_PutOutSelectedDecorItem[] = _("Wähle eine Dekoration \nund stelle sie auf.");
#else
const u8 gText_PutOutSelectedDecorItem[] = _("Put out the selected decoration item.");
#endif
#if GERMAN
const u8 gText_StoreChosenDecorInPC[] = _("Wähle eine Dekoration und \nübertrage sie auf deinen PC.");
#else
const u8 gText_StoreChosenDecorInPC[] = _("Store the chosen decoration in the PC.");
#endif
#if GERMAN
const u8 gText_ThrowAwayUnwantedDecors[] = _("Wähle eine Dekoration\nund wirf sie weg.");
#else
const u8 gText_ThrowAwayUnwantedDecors[] = _("Throw away unwanted decorations.");
#endif
#if GERMAN
const u8 gText_NoDecorations[] = _("Es gibt keine Dekoration.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_NoDecorations[] = _("There are no decorations.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_Desk[] = _("Tisch");
#else
const u8 gText_Desk[] = _("DESK");
#endif
#if GERMAN
const u8 gText_Chair[] = _("Stuhl");
#else
const u8 gText_Chair[] = _("CHAIR");
#endif
#if GERMAN
const u8 gText_Plant[] = _("Pflanze");
#else
const u8 gText_Plant[] = _("PLANT");
#endif
#if GERMAN
const u8 gText_Ornament[] = _("Ornament");
#else
const u8 gText_Ornament[] = _("ORNAMENT");
#endif
#if GERMAN
const u8 gText_Mat[] = _("Matte");
#else
const u8 gText_Mat[] = _("MAT");
#endif
#if GERMAN
const u8 gText_Poster[] = _("Poster");
#else
const u8 gText_Poster[] = _("POSTER");
#endif
#if GERMAN
const u8 gText_Doll[] = _("Puppe");
#else
const u8 gText_Doll[] = _("DOLL");
#endif
#if GERMAN
const u8 gText_Cushion[] = _("Kissen");
#else
const u8 gText_Cushion[] = _("CUSHION");
#endif
#if GERMAN
const u8 gText_Gold[] = _("Gold");
#else
const u8 gText_Gold[] = _("GOLD");
#endif
#if GERMAN
const u8 gText_Silver[] = _("Silber");
#else
const u8 gText_Silver[] = _("SILVER");
#endif
#if GERMAN
const u8 gText_PlaceItHere[] = _("Hierhin platzieren?");
#else
const u8 gText_PlaceItHere[] = _("Place it here?");
#endif
#if GERMAN
const u8 gText_CantBePlacedHere[] = _("Kann hier nicht platziert werden.");
#else
const u8 gText_CantBePlacedHere[] = _("It can't be placed here.");
#endif
#if GERMAN
const u8 gText_CancelDecorating[] = _("Dekorieren beenden?");
#else
const u8 gText_CancelDecorating[] = _("Cancel decorating?");
#endif
#if GERMAN
const u8 gText_InUseAlready[] = _("Das wurde bereits platziert.");
#else
const u8 gText_InUseAlready[] = _("This is in use already.");
#endif
#if GERMAN
const u8 gText_NoMoreDecorations[] = _("Mehr kann nicht dekoriert werden. Es\nist nur Platz für {STR_VAR_1} Dekorationen.");
#else
const u8 gText_NoMoreDecorations[] = _("No more decorations can be placed.\nThe most that can be placed are {STR_VAR_1}.");
#endif
#if GERMAN
const u8 gText_NoMoreDecorations2[] = _("Mehr kann nicht dekoriert werden. Es\nist nur Platz für {STR_VAR_1} Dekorationen.");
#else
const u8 gText_NoMoreDecorations2[] = _("No more decorations can be placed.\nThe most that can be placed are {STR_VAR_1}.");
#endif
#if GERMAN
const u8 gText_MustBePlacedOnDesk[] = _("Das kann hier nicht stehen.\nEs muss auf einem Tisch o. Ä. stehen.");
#else
const u8 gText_MustBePlacedOnDesk[] = _("This can't be placed here.\nIt must be on a DESK, etc.");
#endif // Unused
#if GERMAN
const u8 gText_CantPlaceInRoom[] = _("Die Dekoration kann nicht in deinem\neigenen Zimmer aufgestellt werden.");
#else
const u8 gText_CantPlaceInRoom[] = _("This decoration can't be placed in\nyour own room.");
#endif
#if GERMAN
const u8 gText_CantThrowAwayInUse[] = _("Diese Dekoration wurde platziert.\nDu kannst sie nicht wegwerfen.");
#else
const u8 gText_CantThrowAwayInUse[] = _("This decoration is in use.\nIt can't be thrown away.");
#endif
#if GERMAN
const u8 gText_DecorationWillBeDiscarded[] = _("{STR_VAR_1} wird weggeworfen.\nEinverstanden?");
#else
const u8 gText_DecorationWillBeDiscarded[] = _("This {STR_VAR_1} will be discarded.\nIs that okay?");
#endif
#if GERMAN
const u8 gText_DecorationThrownAway[] = _("Die Dekoration wurde weggeworfen.");
#else
const u8 gText_DecorationThrownAway[] = _("The decoration item was thrown away.");
#endif
#if GERMAN
const u8 gText_StopPuttingAwayDecorations[] = _("Wegnehmen von Dekoration beenden?");
#else
const u8 gText_StopPuttingAwayDecorations[] = _("Stop putting away decorations?");
#endif
#if GERMAN
const u8 gText_NoDecorationHere[] = _("Hier ist keine Dekoration.");
#else
const u8 gText_NoDecorationHere[] = _("There is no decoration item here.");
#endif
#if GERMAN
const u8 gText_ReturnDecorationToPC[] = _("Diese Dekoration auf \nden PC übertragen?");
#else
const u8 gText_ReturnDecorationToPC[] = _("Return this decoration to the PC?");
#endif
#if GERMAN
const u8 gText_DecorationReturnedToPC[] = _("Die Dekoration wurde auf\nden PC übertragen.");
#else
const u8 gText_DecorationReturnedToPC[] = _("The decoration was returned to the PC.");
#endif
#if GERMAN
const u8 gText_NoDecorationsInUse[] = _("Es sind keine Dekorationen platziert.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_NoDecorationsInUse[] = _("There are no decorations in use.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_NoItems[] = _("Es gibt keine Items.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_NoItems[] = _("There are no items.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_NoMailHere[] = _("Hier ist kein Brief.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_NoMailHere[] = _("There's no MAIL here.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_WhatToDoWithVar1sMail[] = _("Was soll mit dem Brief von\n{STR_VAR_1} geschehen?");
#else
const u8 gText_WhatToDoWithVar1sMail[] = _("What would you like to do with\n{STR_VAR_1}'s MAIL?");
#endif
#if GERMAN
const u8 gText_MessageWillBeLost[] = _("Der Inhalt geht verloren.\nIst das in Ordnung für dich?");
#else
const u8 gText_MessageWillBeLost[] = _("The message will be lost.\nIs that okay?");
#endif
#if GERMAN
const u8 gText_BagIsFull[] = _("Der Beutel ist voll.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_BagIsFull[] = _("The BAG is full.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_MailToBagMessageErased[] = _("Der Brief, dessen Inhalt gelöscht\nist, wurde im Beutel gelagert.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_MailToBagMessageErased[] = _("The MAIL was returned to the BAG\nwith its message erased.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_Dad[] = _("Vati");
#else
const u8 gText_Dad[] = _("DAD");
#endif
#if GERMAN
const u8 gText_Mom[] = _("Mutti");
#else
const u8 gText_Mom[] = _("MOM");
#endif
#if GERMAN
const u8 gText_MomHowMuchDeposit[] = _("Wieviel möchtest du\nbei Mutti einzahlen?");
#else
const u8 gText_MomHowMuchDeposit[] = _("How much would you like to\ndeposit with your MOM?");
#endif
#if GERMAN
const u8 gText_MomHowMuchWithdraw[] = _("Wieviel möchtest du\nbei Mutti entnehmen?");
#else
const u8 gText_MomHowMuchWithdraw[] = _("How much would you like to\nwithdraw from your MOM?");
#endif
#if GERMAN
const u8 gText_MomMatchCallDesc[] = _("Ruhig & Nett");
#else
const u8 gText_MomMatchCallDesc[] = _("CALM & KIND");
#endif
#if GERMAN
const u8 gText_MomMatchCallName[] = _("Mutti");
#else
const u8 gText_MomMatchCallName[] = _("MOM");
#endif
#if GERMAN
const u8 gText_MomMenuCheckSavings[] = _("Konto");
#else
const u8 gText_MomMenuCheckSavings[] = _("CHECK SAVINGS");
#endif
#if GERMAN
const u8 gText_MomMenuDeposit[] = _("Einzahlen");
#else
const u8 gText_MomMenuDeposit[] = _("DEPOSIT");
#endif
#if GERMAN
const u8 gText_MomMenuWithdraw[] = _("Nehmen");
#else
const u8 gText_MomMenuWithdraw[] = _("WITHDRAW");
#endif
#if GERMAN
const u8 gText_MomMenuToggleSaving[] = _("Sparen");
#else
const u8 gText_MomMenuToggleSaving[] = _("SAVING");
#endif
#if GERMAN
const u8 gText_MomMenuExit[] = _("Verlassen");
#else
const u8 gText_MomMenuExit[] = _("EXIT");
#endif
#if GERMAN
const u8 gText_Info2[] = _("Info");
#else
const u8 gText_Info2[] = _("INFO");
#endif
#if GERMAN
const u8 gText_CoolnessContest[] = _("Cool.");
#else
const u8 gText_CoolnessContest[] = _("COOLNESS CONTEST");
#endif
#if GERMAN
const u8 gText_BeautyContest[] = _("Schön.");
#else
const u8 gText_BeautyContest[] = _("BEAUTY CONTEST");
#endif
#if GERMAN
const u8 gText_CutenessContest[] = _("Anmut");
#else
const u8 gText_CutenessContest[] = _("CUTENESS CONTEST");
#endif
#if GERMAN
const u8 gText_SmartnessContest[] = _("Klug.");
#else
const u8 gText_SmartnessContest[] = _("SMARTNESS CONTEST");
#endif
#if GERMAN
const u8 gText_ToughnessContest[] = _("Stärke");
#else
const u8 gText_ToughnessContest[] = _("TOUGHNESS CONTEST");
#endif
#if GERMAN
const u8 gText_Decoration2[] = _("Dekoration");
#else
const u8 gText_Decoration2[] = _("DECORATION");
#endif
#if GERMAN
const u8 gText_PackUp[] = _("Einpacken");
#else
const u8 gText_PackUp[] = _("PACK UP");
#endif
#if GERMAN
const u8 gText_Registry[] = _("Register");
#else
const u8 gText_Registry[] = _("REGISTRY");
#endif
#if GERMAN
const u8 gText_Information[] = _("Information");
#else
const u8 gText_Information[] = _("INFORMATION");
#endif
#if GERMAN
const u8 gText_Yes[] = _("Ja");
#else
const u8 gText_Yes[] = _("YES");
#endif
#if GERMAN
const u8 gText_No[] = _("Nein");
#else
const u8 gText_No[] = _("NO");
#endif
const u8 gText_Lv50[] = _("LV. 50");
#if GERMAN
const u8 gText_OpenLevel[] = _("Offene Kämpfe");
#else
const u8 gText_OpenLevel[] = _("OPEN LEVEL");
#endif
#if GERMAN
const u8 gText_RedShard[] = _("Purpurstück");
#else
const u8 gText_RedShard[] = _("RED SHARD");
#endif
#if GERMAN
const u8 gText_YellowShard[] = _("Gelbstück");
#else
const u8 gText_YellowShard[] = _("YELLOW SHARD");
#endif
#if GERMAN
const u8 gText_BlueShard[] = _("Indigostück");
#else
const u8 gText_BlueShard[] = _("BLUE SHARD");
#endif
#if GERMAN
const u8 gText_GreenShard[] = _("Grünstück");
#else
const u8 gText_GreenShard[] = _("GREEN SHARD");
#endif
#if GERMAN
const u8 gText_BattleFrontier[] = _("Kampfzone");
#else
const u8 gText_BattleFrontier[] = _("BATTLE FRONTIER");
#endif
#if GERMAN
const u8 gText_Cool[] = _("Cool.");
#else
const u8 gText_Cool[] = _("COOL");
#endif
#if GERMAN
const u8 gText_Beauty[] = _("Schön.");
#else
const u8 gText_Beauty[] = _("BEAUTY");
#endif
#if GERMAN
const u8 gText_Cute[] = _("Anmut");
#else
const u8 gText_Cute[] = _("CUTE");
#endif
#if GERMAN
const u8 gText_Smart[] = _("Klug.");
#else
const u8 gText_Smart[] = _("SMART");
#endif
#if GERMAN
const u8 gText_Tough[] = _("Stärke");
#else
const u8 gText_Tough[] = _("TOUGH");
#endif
#if GERMAN
const u8 gText_Normal[] = _("Normal");
#else
const u8 gText_Normal[] = _("NORMAL");
#endif
#if GERMAN
const u8 gText_Super[] = _("Super");
#else
const u8 gText_Super[] = _("SUPER");
#endif
#if GERMAN
const u8 gText_Hyper[] = _("Hyper");
#else
const u8 gText_Hyper[] = _("HYPER");
#endif
#if GERMAN
const u8 gText_Master[] = _("Master");
#else
const u8 gText_Master[] = _("MASTER");
#endif
#if GERMAN
const u8 gText_Cool2[] = _("Cool.");
#else
const u8 gText_Cool2[] = _("COOL");
#endif
#if GERMAN
const u8 gText_Beauty2[] = _("Schön.");
#else
const u8 gText_Beauty2[] = _("BEAUTY");
#endif
#if GERMAN
const u8 gText_Cute2[] = _("Anmut");
#else
const u8 gText_Cute2[] = _("CUTE");
#endif
#if GERMAN
const u8 gText_Smart2[] = _("Klug.");
#else
const u8 gText_Smart2[] = _("SMART");
#endif
#if GERMAN
const u8 gText_Tough2[] = _("Stärke");
#else
const u8 gText_Tough2[] = _("TOUGH");
#endif
#if GERMAN
const u8 gText_Items[] = _("Item");
#else
const u8 gText_Items[] = _("OTHER ITEMS");
#endif
#if GERMAN
const u8 gText_Key_Items[] = _("Basis-Item");
#else
const u8 gText_Key_Items[] = _("KEY ITEMS");
#endif
#if GERMAN
const u8 gText_Poke_Balls[] = _("Ball");
#else
const u8 gText_Poke_Balls[] = _("POKé BALLS");
#endif
#if GERMAN
const u8 gText_TMs_Hms[] = _("TM/VM");
#else
const u8 gText_TMs_Hms[] = _("TMs & HMs");
#endif
#if GERMAN
const u8 gText_Berries2[] = _("Beeren");
#else
const u8 gText_Berries2[] = _("BERRIES");
#endif
#if GERMAN
const u8 gText_Medicine[] = _("Medizin");
#else
const u8 gText_Medicine[] = _("MEDICINE");
#endif
#if I_COMBINE_BAG_POCKETS == FALSE
#if GERMAN
const u8 gText_BattleItems[] = _("Kampfitems");
#else
const u8 gText_BattleItems[] = _("BATTLE ITEMS");
#endif
#if GERMAN
const u8 gText_Treasures[] = _("Schätze");
#else
const u8 gText_Treasures[] = _("TREASURES");
#endif
#endif
#if IS_HNS
// Origin Jade: Vor der Begegnung mit Bill (Sea Cottage) heisst der PC
// "Jemandes PC"; das Kennenlernen setzt FLAG_SYS_PC_LANETTE, danach
// traegt er Bills Namen (statt Lanettes).
#if GERMAN
const u8 gText_SomeonesPC[] = _("Jemandes PC");
const u8 gText_LanettesPC[] = _("Bills PC");
#else
const u8 gText_SomeonesPC[] = _("SOMEONE'S PC");
const u8 gText_LanettesPC[] = _("BILL's PC");
#endif
#else
#if GERMAN
const u8 gText_SomeonesPC[] = _("Jemandes PC");
#else
const u8 gText_SomeonesPC[] = _("SOMEONE'S PC");
#endif
#if GERMAN
const u8 gText_LanettesPC[] = _("Lanettes PC");
#else
const u8 gText_LanettesPC[] = _("LANETTE'S PC");
#endif
#endif
#if GERMAN
const u8 gText_BillsPc[] = _("Bills PC");
#else
const u8 gText_BillsPc[] = _("BILL'S PC");
#endif
#if GERMAN
const u8 gText_PlayersPC[] = _("PC von {PLAYER}");
#else
const u8 gText_PlayersPC[] = _("{PLAYER}'s PC");
#endif
#if GERMAN
const u8 gText_HallOfFame[] = _("Ruhmeshalle");
#else
const u8 gText_HallOfFame[] = _("HALL OF FAME");
#endif
#if GERMAN
const u8 gText_LogOff[] = _("Ausloggen");
#else
const u8 gText_LogOff[] = _("LOG OFF");
#endif
#if GERMAN
const u8 gText_Challenges[] = _("Einstellung");
#else
const u8 gText_Challenges[] = _("CHALLENGES");
#endif
#if GERMAN
const u8 gText_Opponent[] = _("Gegner");
#else
const u8 gText_Opponent[] = _("OPPONENT");
#endif
#if GERMAN
const u8 gText_Tourney_Tree[] = _("Turniertafel");
#else
const u8 gText_Tourney_Tree[] = _("TOURNEY TREE");
#endif
#if GERMAN
const u8 gText_ReadyToStart[] = _("Bereit");
#else
const u8 gText_ReadyToStart[] = _("READY TO START");
#endif
#if GERMAN
const u8 gText_Single2[] = _("Einzel");
#else
const u8 gText_Single2[] = _("SINGLE");
#endif
#if GERMAN
const u8 gText_Double2[] = _("Doppel");
#else
const u8 gText_Double2[] = _("DOUBLE");
#endif
#if GERMAN
const u8 gText_Multi[] = _("Multi");
#else
const u8 gText_Multi[] = _("MULTI");
#endif
#if GERMAN
const u8 gText_MultiLink[] = _("Multi-Link");
#else
const u8 gText_MultiLink[] = _("MULTI-LINK");
#endif
#if GERMAN
const u8 gText_MenuOptionPokedex[] = _("Pokédex");
#else
const u8 gText_MenuOptionPokedex[] = _("POKéDEX");
#endif
#if GERMAN
const u8 gText_MenuOptionPokemon[] = _("Pokémon");
#else
const u8 gText_MenuOptionPokemon[] = _("POKéMON");
#endif
#if GERMAN
const u8 gText_MenuOptionBag[] = _("Beutel");
#else
const u8 gText_MenuOptionBag[] = _("BAG");
#endif
#if IS_HNS
#if GERMAN
const u8 gText_MenuOptionPokenav[] = _("PokéCom");
#else
const u8 gText_MenuOptionPokenav[] = _("POKéNAV");
#endif
#else
#if GERMAN
const u8 gText_MenuOptionPokenav[] = _("PokéCom");
#else
const u8 gText_MenuOptionPokenav[] = _("POKéNAV");
#endif
#endif
const u8 gText_Blank[] = _("");
#if GERMAN
const u8 gText_MenuOptionSave[] = _("Sichern");
#else
const u8 gText_MenuOptionSave[] = _("SAVE");
#endif
#if GERMAN
const u8 gText_MenuOptionOption[] = _("Option.");
#else
const u8 gText_MenuOptionOption[] = _("OPTION");
#endif
#if GERMAN
const u8 gText_MenuOptionExit[] = _("Beenden");
#else
const u8 gText_MenuOptionExit[] = _("EXIT");
#endif
#if GERMAN
const u8 gText_SouthernIsland[] = _("Insel im Süden");
#else
const u8 gText_SouthernIsland[] = _("SOUTHERN ISLAND");
#endif
#if GERMAN
const u8 gText_BirthIsland[] = _("Entstehungsinsel");
#else
const u8 gText_BirthIsland[] = _("BIRTH ISLAND");
#endif
#if GERMAN
const u8 gText_FarawayIsland[] = _("Ferneiland");
#else
const u8 gText_FarawayIsland[] = _("FARAWAY ISLAND");
#endif
#if GERMAN
const u8 gText_HoennRegion[] = _("Hoenn");
#else
const u8 gText_HoennRegion[] = _("HOENN");
#endif
#if GERMAN
const u8 gText_NavelRock[] = _("Nabelfels");
#else
const u8 gText_NavelRock[] = _("NAVEL ROCK");
#endif
#if GERMAN
const u8 gText_NormalTagMatch[] = _("Basisteamkampf");
#else
const u8 gText_NormalTagMatch[] = _("NORMAL TAG MATCH");
#endif
#if GERMAN
const u8 gText_VarietyTagMatch[] = _("Hürdenteamkampf");
#else
const u8 gText_VarietyTagMatch[] = _("VARIETY TAG MATCH");
#endif
#if GERMAN
const u8 gText_UniqueTagMatch[] = _("Unikatteamkampf");
#else
const u8 gText_UniqueTagMatch[] = _("UNIQUE TAG MATCH");
#endif
#if GERMAN
const u8 gText_ExpertTagMatch[] = _("Profiteamkampf");
#else
const u8 gText_ExpertTagMatch[] = _("EXPERT TAG MATCH");
#endif
#if GERMAN
const u8 gText_TradeCenter[] = _("Handelscenter");
#else
const u8 gText_TradeCenter[] = _("TRADE CENTER");
#endif
#if GERMAN
const u8 gText_Colosseum[] = _("Kolosseum");
#else
const u8 gText_Colosseum[] = _("COLOSSEUM");
#endif
#if GERMAN
const u8 gText_RecordCorner[] = _("Statistiktausch");
#else
const u8 gText_RecordCorner[] = _("RECORD CORNER");
#endif
#if GERMAN
const u8 gText_BerryCrush3[] = _("Beerenmühle");
#else
const u8 gText_BerryCrush3[] = _("BERRY CRUSH");
#endif
#if GERMAN
const u8 gText_BattleRules[] = _("Kampfregeln");
#else
const u8 gText_BattleRules[] = _("BATTLE RULES");
#endif
#if GERMAN
const u8 gText_JudgeMind[] = _("Jury: Verstand");
#else
const u8 gText_JudgeMind[] = _("JUDGE: MIND");
#endif
#if GERMAN
const u8 gText_JudgeSkill[] = _("Jury: Geschick");
#else
const u8 gText_JudgeSkill[] = _("JUDGE: SKILL");
#endif
#if GERMAN
const u8 gText_JudgeBody[] = _("Jury: Körper");
#else
const u8 gText_JudgeBody[] = _("JUDGE: BODY");
#endif
#if GERMAN
const u8 gText_BasicRules[] = _("Grundregeln");
#else
const u8 gText_BasicRules[] = _("BASIC RULES");
#endif
#if GERMAN
const u8 gText_SwapPartners[] = _("Tausch: Team");
#else
const u8 gText_SwapPartners[] = _("SWAP: PARTNER");
#endif
#if GERMAN
const u8 gText_SwapNumber[] = _("Tausch: Nr.");
#else
const u8 gText_SwapNumber[] = _("SWAP: NUMBER");
#endif
#if GERMAN
const u8 gText_SwapNotes[] = _("Tausch: Tipp");
#else
const u8 gText_SwapNotes[] = _("SWAP: NOTES");
#endif
#if GERMAN
const u8 gText_BattleBasics[] = _("Kampftipps");
#else
const u8 gText_BattleBasics[] = _("BATTLE BASICS");
#endif
#if GERMAN
const u8 gText_PokemonNature[] = _("Pokémon Wesen");
#else
const u8 gText_PokemonNature[] = _("POKéMON NATURE");
#endif
#if GERMAN
const u8 gText_PokemonMoves[] = _("Pkmn Attacken");
#else
const u8 gText_PokemonMoves[] = _("POKéMON MOVES");
#endif
#if GERMAN
const u8 gText_Underpowered[] = _("Wesen&Attacken");
#else
const u8 gText_Underpowered[] = _("UNDERPOWERED");
#endif
#if GERMAN
const u8 gText_WhenInDanger[] = _("Bei Gefahr");
#else
const u8 gText_WhenInDanger[] = _("WHEN IN DANGER");
#endif
#if GERMAN
const u8 gText_BattlePokemon[] = _("Kampfpokémon");
#else
const u8 gText_BattlePokemon[] = _("BATTLE POKéMON");
#endif
#if GERMAN
const u8 gText_BattleTrainers[] = _("Kampftrainer");
#else
const u8 gText_BattleTrainers[] = _("BATTLE TRAINERS");
#endif
#if GERMAN
const u8 gText_GoOn[] = _("Weiter");
#else
const u8 gText_GoOn[] = _("GO ON");
#endif
#if GERMAN
const u8 gText_Record2[] = _("Sichern");
#else
const u8 gText_Record2[] = _("RECORD");
#endif
#if GERMAN
const u8 gText_Rest[] = _("Ausruhen");
#else
const u8 gText_Rest[] = _("REST");
#endif
#if GERMAN
const u8 gText_Retire[] = _("Schluss");
#else
const u8 gText_Retire[] = _("RETIRE");
#endif
#if GERMAN
const u8 gText_1F[] = _("EG");
#else
const u8 gText_1F[] = _("1F");
#endif
#if GERMAN
const u8 gText_2F[] = _("1S");
#else
const u8 gText_2F[] = _("2F");
#endif
#if GERMAN
const u8 gText_3F[] = _("2S");
#else
const u8 gText_3F[] = _("3F");
#endif
#if GERMAN
const u8 gText_4F[] = _("3S");
#else
const u8 gText_4F[] = _("4F");
#endif
#if GERMAN
const u8 gText_5F[] = _("4S");
#else
const u8 gText_5F[] = _("5F");
#endif
#if GERMAN
const u8 gText_6F[] = _("5S");
#else
const u8 gText_6F[] = _("6F");
#endif
#if GERMAN
const u8 gText_7F[] = _("6S");
#else
const u8 gText_7F[] = _("7F");
#endif
#if GERMAN
const u8 gText_8F[] = _("7S");
#else
const u8 gText_8F[] = _("8F");
#endif
#if GERMAN
const u8 gText_9F[] = _("8S");
#else
const u8 gText_9F[] = _("9F");
#endif
#if GERMAN
const u8 gText_10F[] = _("9S");
#else
const u8 gText_10F[] = _("10F");
#endif
#if GERMAN
const u8 gText_11F[] = _("10S");
#else
const u8 gText_11F[] = _("11F");
#endif
#if GERMAN
const u8 gText_B1F[] = _("U1S");
#else
const u8 gText_B1F[] = _("B1F");
#endif
#if GERMAN
const u8 gText_B2F[] = _("U2S");
#else
const u8 gText_B2F[] = _("B2F");
#endif
#if GERMAN
const u8 gText_B3F[] = _("U3S");
#else
const u8 gText_B3F[] = _("B3F");
#endif
#if GERMAN
const u8 gText_B4F[] = _("U4S");
#else
const u8 gText_B4F[] = _("B4F");
#endif
#if GERMAN
const u8 gText_Rooftop[] = _("Dach");
#else
const u8 gText_Rooftop[] = _("ROOFTOP");
#endif
#if GERMAN
const u8 gText_ElevatorNowOn[] = _("Momentan im");
#else
const u8 gText_ElevatorNowOn[] = _("Now on:");
#endif
#if GERMAN
const u8 gText_BP[] = _("GP");
#else
const u8 gText_BP[] = _("BP");
#endif
#if GERMAN
const u8 gText_RankingHall[] = _("Ergebnishalle");
#else
const u8 gText_RankingHall[] = _("RANKING HALL");
#endif
#if GERMAN
const u8 gText_ExchangeService[] = _("Austauschservice");
#else
const u8 gText_ExchangeService[] = _("EXCHANGE SERVICE");
#endif
#if GERMAN
const u8 gText_LilycoveCity[] = _("Seegrasulb City");
#else
const u8 gText_LilycoveCity[] = _("LILYCOVE CITY");
#endif
#if GERMAN
const u8 gText_SlateportCity[] = _("Graphitport City");
#else
const u8 gText_SlateportCity[] = _("SLATEPORT CITY");
#endif
#if GERMAN
const u8 gText_Exit[] = _("Zurück");
#else
const u8 gText_Exit[] = _("EXIT");
#endif
#if GERMAN
const u8 gText_YourPartysFull[] = _("Dein Team ist voll!");
#else
const u8 gText_YourPartysFull[] = _("Your party's full!{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_InParty[] = _("Im Team");
#else
const u8 gText_InParty[] = _("IN PARTY");
#endif
#if GERMAN
const u8 gText_PokemonMaleLv[] = _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}");
#else
const u8 gText_PokemonMaleLv[] = _("{DYNAMIC 0}{BACKGROUND WHITE}{TEXT_COLORS LIGHT_RED GREEN WHITE}♂{BACKGROUND WHITE}{TEXT_COLORS DARK_GRAY LIGHT_GRAY WHITE}/{LV}{DYNAMIC 1}");
#endif // Unused
#if GERMAN
const u8 gText_PokemonFemaleLv[] = _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}");
#else
const u8 gText_PokemonFemaleLv[] = _("{DYNAMIC 0}{BACKGROUND WHITE}{TEXT_COLORS LIGHT_GREEN BLUE WHITE}♀{BACKGROUND WHITE}{TEXT_COLORS DARK_GRAY LIGHT_GRAY WHITE}/{LV}{DYNAMIC 1}");
#endif // Unused
const u8 gText_PokemonNoGenderLv[] = _("{DYNAMIC 0}/{LV}{DYNAMIC 1}"); // Unused
#if GERMAN
const u8 gText_PokemonMaleLv2[] = _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}{DYNAMIC 2}");
#else
const u8 gText_PokemonMaleLv2[] = _("{DYNAMIC 0}{BACKGROUND WHITE}{TEXT_COLORS LIGHT_RED GREEN WHITE}♂{BACKGROUND WHITE}{TEXT_COLORS DARK_GRAY LIGHT_GRAY WHITE}/{LV}{DYNAMIC 1}{DYNAMIC 2}");
#endif // Unused
#if GERMAN
const u8 gText_PokemonFemaleLv2[] = _("{DYNAMIC 0}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GRAY WHITE LIGHT_GRAY}/{LV}{DYNAMIC 1}{DYNAMIC 2}");
#else
const u8 gText_PokemonFemaleLv2[] = _("{DYNAMIC 0}{BACKGROUND WHITE}{TEXT_COLORS LIGHT_GREEN BLUE WHITE}♀{BACKGROUND WHITE}{TEXT_COLORS DARK_GRAY LIGHT_GRAY WHITE}/{LV}{DYNAMIC 1}{DYNAMIC 2}");
#endif // Unused
const u8 gText_PokemonNoGenderLv2[] = _("{DYNAMIC 0}/{LV}{DYNAMIC 1}{DYNAMIC 2}"); // Unused
#if GERMAN
const u8 gText_CombineFourWordsOrPhrases[] = _("Erstelle dein eigenes Profil!");
#else
const u8 gText_CombineFourWordsOrPhrases[] = _("Combine four words or phrases");
#endif
#if GERMAN
const u8 gText_AndMakeYourProfile[] = _("Kombiniere 4 Wörter/Ausdrücke.");
#else
const u8 gText_AndMakeYourProfile[] = _("and make your profile.");
#endif
#if GERMAN
const u8 gText_CombineSixWordsOrPhrases[] = _("Verwende 6 Ausdrücke,");
#else
const u8 gText_CombineSixWordsOrPhrases[] = _("Combine six words or phrases");
#endif
#if GERMAN
const u8 gText_AndMakeAMessage[] = _("um einen Satz zu bilden.");
#else
const u8 gText_AndMakeAMessage[] = _("and make a message.");
#endif
#if GERMAN
const u8 gText_FindWordsThatDescribeYour[] = _("Finde Worte, die deine momentanen");
#else
const u8 gText_FindWordsThatDescribeYour[] = _("Find words that describe your");
#endif
#if GERMAN
const u8 gText_FeelingsRightNow[] = _("Empfindungen beschreiben.");
#else
const u8 gText_FeelingsRightNow[] = _("feelings right now.");
#endif
const u8 gText_WithFourPhrases[] = _("With four phrases,"); // Unused
#if GERMAN
const u8 gText_CombineNineWordsOrPhrases[] = _("Kombiniere 9 Ausdrücke und");
#else
const u8 gText_CombineNineWordsOrPhrases[] = _("Combine nine words or phrases");
#endif
#if GERMAN
const u8 gText_AndMakeAMessage2[] = _("erstelle eine Nachricht.");
#else
const u8 gText_AndMakeAMessage2[] = _("and make a message.");
#endif
#if GERMAN
const u8 gText_ChangeJustOneWordOrPhrase[] = _("Ändere nur 1 Wort/Ausdruck");
#else
const u8 gText_ChangeJustOneWordOrPhrase[] = _("Change just one word or phrase");
#endif
#if GERMAN
const u8 gText_AndImproveTheBardsSong[] = _("und verbessere das Barden-Lied.");
#else
const u8 gText_AndImproveTheBardsSong[] = _("and improve the BARD's song.");
#endif
#if GERMAN
const u8 gText_YourProfile[] = _("Dein Profil");
#else
const u8 gText_YourProfile[] = _("Your profile");
#endif
#if GERMAN
const u8 gText_YourFeelingAtTheBattlesStart[] = _("Dein Gefühl zum Kampfbeginn");
#else
const u8 gText_YourFeelingAtTheBattlesStart[] = _("Your feeling at the battle's start");
#endif
#if GERMAN
const u8 gText_WhatYouSayIfYouWin[] = _("Dein Ausspruch im Fall des Sieges");
#else
const u8 gText_WhatYouSayIfYouWin[] = _("What you say if you win a battle");
#endif
#if GERMAN
const u8 gText_WhatYouSayIfYouLose[] = _("Dein Ausspruch bei einer Niederl.");
#else
const u8 gText_WhatYouSayIfYouLose[] = _("What you say if you lose a battle");
#endif
#if GERMAN
const u8 gText_TheAnswer[] = _("Die Antwort");
#else
const u8 gText_TheAnswer[] = _("The answer");
#endif
#if GERMAN
const u8 gText_TheMailMessage[] = _("Der Inhalt des Briefes");
#else
const u8 gText_TheMailMessage[] = _("The MAIL message");
#endif
#if GERMAN
const u8 gText_TheMailSalutation[] = _("Die Brief-Anrede");
#else
const u8 gText_TheMailSalutation[] = _("The MAIL salutation");
#endif // Unused
#if GERMAN
const u8 gText_TheBardsSong2[] = _("Das neue Lied");
#else
const u8 gText_TheBardsSong2[] = _("The new song");
#endif
#if GERMAN
const u8 gText_CombineTwoWordsOrPhrases[] = _("Kombiniere 2 Ausdrücke und");
#else
const u8 gText_CombineTwoWordsOrPhrases[] = _("Combine two words or phrases");
#endif
#if GERMAN
const u8 gText_AndMakeATrendySaying[] = _("schaffe einen hippen Spruch.");
#else
const u8 gText_AndMakeATrendySaying[] = _("and make a trendy saying.");
#endif
#if GERMAN
const u8 gText_TheTrendySaying[] = _("Der hippe Spruch");
#else
const u8 gText_TheTrendySaying[] = _("The trendy saying");
#endif
#if GERMAN
const u8 gText_IsAsShownOkay[] = _("lautet also so. O.K.?");
#else
const u8 gText_IsAsShownOkay[] = _("is as shown. Okay?");
#endif
#if GERMAN
const u8 gText_CombineTwoWordsOrPhrases2[] = _("Kombiniere 2 Ausdrücke und");
#else
const u8 gText_CombineTwoWordsOrPhrases2[] = _("Combine two words or phrases");
#endif
#if GERMAN
const u8 gText_ToTeachHerAGoodSaying[] = _("bringe ihr einen guten Spruch bei.");
#else
const u8 gText_ToTeachHerAGoodSaying[] = _("to teach her a good saying.");
#endif
#if GERMAN
const u8 gText_FindWordsWhichFit[] = _("Finde die passenden Worte");
#else
const u8 gText_FindWordsWhichFit[] = _("Find words which fit");
#endif
#if GERMAN
const u8 gText_TheTrainersImage[] = _("für diesen Trainer.");
#else
const u8 gText_TheTrainersImage[] = _("the TRAINER's image.");
#endif
#if GERMAN
const u8 gText_TheImage[] = _("Darstellung");
#else
const u8 gText_TheImage[] = _("The image:");
#endif
#if GERMAN
const u8 gText_OutOfTheListedChoices[] = _("Wähle eine der vorgegebenen");
#else
const u8 gText_OutOfTheListedChoices[] = _("Out of the listed choices,");
#endif
#if GERMAN
const u8 gText_SelectTheAnswerToTheQuiz[] = _("Antworten als Lösung aus");
#else
const u8 gText_SelectTheAnswerToTheQuiz[] = _("select the answer to the quiz!");
#endif
#if GERMAN
const u8 gText_AndCreateAQuiz[] = _("und erstelle ein Quiz!");
#else
const u8 gText_AndCreateAQuiz[] = _("and create a quiz!");
#endif
#if GERMAN
const u8 gText_PickAWordOrPhraseAnd[] = _("Wähle ein(en) Wort/Ausdruck aus");
#else
const u8 gText_PickAWordOrPhraseAnd[] = _("Pick a word or phrase and");
#endif
#if GERMAN
const u8 gText_SetTheQuizAnswer[] = _("und lege die Antwort fest.");
#else
const u8 gText_SetTheQuizAnswer[] = _("set the quiz answer.");
#endif
#if GERMAN
const u8 gText_TheAnswerColon[] = _("Die Antwort:");
#else
const u8 gText_TheAnswerColon[] = _("The answer:");
#endif
#if GERMAN
const u8 gText_TheQuizColon[] = _("Das Quiz:");
#else
const u8 gText_TheQuizColon[] = _("The quiz:");
#endif // Unused
#if GERMAN
const u8 gText_ApprenticePhrase[] = _("Aussage des Lehrlings:");
#else
const u8 gText_ApprenticePhrase[] = _("Apprentice's phrase:");
#endif
#if GERMAN
const u8 gText_QuitEditing[] = _("Das Textverfassen beenden?");
#else
const u8 gText_QuitEditing[] = _("Quit editing?");
#endif
#if GERMAN
const u8 gText_StopGivingPkmnMail[] = _("Pokémon keinen Brief geben?");
#else
const u8 gText_StopGivingPkmnMail[] = _("Stop giving the POKéMON MAIL?");
#endif
#if GERMAN
const u8 gText_AndFillOutTheQuestionnaire[] = _("Fülle den Fragebogen aus.");
#else
const u8 gText_AndFillOutTheQuestionnaire[] = _("and fill out the questionnaire.");
#endif
#if GERMAN
const u8 gText_LetsReplyToTheInterview[] = _("Lass uns das Interview beenden!");
#else
const u8 gText_LetsReplyToTheInterview[] = _("Let's reply to the interview!");
#endif
#if GERMAN
const u8 gText_AllTextBeingEditedWill[] = _("Der gesamte verfasste Text wird");
#else
const u8 gText_AllTextBeingEditedWill[] = _("All the text being edited will");
#endif
#if GERMAN
const u8 gText_BeDeletedThatOkay[] = _("gelöscht. Einverstanden?");
#else
const u8 gText_BeDeletedThatOkay[] = _("be deleted. Is that okay?");
#endif
const u8 gText_QuitEditing2[] = _("Quit editing?"); // Unused
#if GERMAN
const u8 gText_EditedTextWillNotBeSaved[] = _("Der geänderte Text wird nicht gesichert.");
#else
const u8 gText_EditedTextWillNotBeSaved[] = _("The edited text will not be saved.");
#endif // Unused
#if GERMAN
const u8 gText_IsThatOkay[] = _("Ist das in Ordnung?");
#else
const u8 gText_IsThatOkay[] = _("Is that okay?");
#endif // Unused
#if GERMAN
const u8 gText_PleaseEnterPhraseOrWord[] = _("Gib bitte ein Wort oder einen Satz ein.");
#else
const u8 gText_PleaseEnterPhraseOrWord[] = _("Please enter a phrase or word.");
#endif // Unused
#if GERMAN
const u8 gText_EntireTextCantBeDeleted[] = _("Der gesamte Text kann nicht\ngelöscht werden.");
#else
const u8 gText_EntireTextCantBeDeleted[] = _("The entire text can't be deleted.");
#endif
#if GERMAN
const u8 gText_OnlyOnePhrase[] = _("Nur ein Ausdruck ist änderbar.");
#else
const u8 gText_OnlyOnePhrase[] = _("Only one phrase may be changed.");
#endif
#if GERMAN
const u8 gText_OriginalSongWillBeUsed[] = _("Das Lied wird wiederhergestellt.");
#else
const u8 gText_OriginalSongWillBeUsed[] = _("The original song will be used.");
#endif
const u8 gText_ThatsTrendyAlready[] = _("That's trendy already!"); // Unused
#if GERMAN
const u8 gText_CombineTwoWordsOrPhrases3[] = _("Kombiniere 2 Wörter/Ausdrücke.");
#else
const u8 gText_CombineTwoWordsOrPhrases3[] = _("Combine two words or phrases.");
#endif
const u8 gText_QuitGivingInfo[] = _("Quit giving information?"); // Unused
#if GERMAN
const u8 gText_StopGivingPkmnMail2[] = _("Pokémon keinen Brief geben?");
#else
const u8 gText_StopGivingPkmnMail2[] = _("Stop giving the POKéMON MAIL?");
#endif // Unused
#if GERMAN
const u8 gText_CreateAQuiz2[] = _("Erstelle ein Quiz!");
#else
const u8 gText_CreateAQuiz2[] = _("Create a quiz!");
#endif // Unused
#if GERMAN
const u8 gText_SetTheAnswer[] = _("Lege die Antwort fest!");
#else
const u8 gText_SetTheAnswer[] = _("Set the answer!");
#endif // Unused
#if GERMAN
const u8 gText_CancelSelection[] = _("Auswahl abbrechen?");
#else
const u8 gText_CancelSelection[] = _("Cancel the selection?");
#endif // Unused
#if GERMAN
const u8 gText_Profile[] = _("Profil");
#else
const u8 gText_Profile[] = _("PROFILE");
#endif
#if GERMAN
const u8 gText_AtTheBattlesStart[] = _("Zum Kampfbeginn");
#else
const u8 gText_AtTheBattlesStart[] = _("At the battle's start:");
#endif
#if GERMAN
const u8 gText_UponWinningABattle[] = _("Über den Sieg");
#else
const u8 gText_UponWinningABattle[] = _("Upon winning a battle:");
#endif
#if GERMAN
const u8 gText_UponLosingABattle[] = _("Über die Niederlage");
#else
const u8 gText_UponLosingABattle[] = _("Upon losing a battle:");
#endif
#if GERMAN
const u8 gText_TheBardsSong[] = _("Das Barden-Lied");
#else
const u8 gText_TheBardsSong[] = _("The BARD's Song");
#endif
#if GERMAN
const u8 gText_WhatsHipAndHappening[] = _("Was ist hip? Was ist top?");
#else
const u8 gText_WhatsHipAndHappening[] = _("What's hip and happening?");
#endif
const u8 gText_Interview[] = _("Interview");
#if GERMAN
const u8 gText_GoodSaying[] = _("Guter Spruch");
#else
const u8 gText_GoodSaying[] = _("Good saying");
#endif
#if GERMAN
const u8 gText_FansQuestion[] = _("Frage eines Fans");
#else
const u8 gText_FansQuestion[] = _("Fan's question");
#endif
const u8 gJPText_WhatIsTheQuizAnswer[] = _("クイズの こたえは？"); // Unused
#if GERMAN
const u8 gText_ApprenticesPhrase[] = _("Worte des Lehrlings");
#else
const u8 gText_ApprenticesPhrase[] = _("Apprentice's phrase");
#endif
#if GERMAN
const u8 gText_Questionnaire[] = _("Fragebogen");
#else
const u8 gText_Questionnaire[] = _("QUESTIONNAIRE");
#endif
#if GERMAN
const u8 gText_YouCannotQuitHere[] = _("Beenden hier nicht möglich.");
#else
const u8 gText_YouCannotQuitHere[] = _("You cannot quit here.");
#endif
#if GERMAN
const u8 gText_SectionMustBeCompleted[] = _("Abschnitt noch abschließen.");
#else
const u8 gText_SectionMustBeCompleted[] = _("This section must be completed.");
#endif
#if GERMAN
const u8 gText_F700sQuiz[] = _("Quiz von {DYNAMIC 0}");
#else
const u8 gText_F700sQuiz[] = _("{DYNAMIC 0}'s quiz");
#endif
const u8 gText_Lady[] = _("Lady");
#if GERMAN
const u8 gText_AfterYouHaveReadTheQuiz[] = _("Drücke den A-Knopf, nachdem");
#else
const u8 gText_AfterYouHaveReadTheQuiz[] = _("After you have read the quiz");
#endif
#if GERMAN
const u8 gText_QuestionPressTheAButton[] = _("du die Quizfrage gelesen hast.");
#else
const u8 gText_QuestionPressTheAButton[] = _("question, press the A Button.");
#endif
#if GERMAN
const u8 gText_TheQuizAnswerIs[] = _("Wie lautet die Antwort?");
#else
const u8 gText_TheQuizAnswerIs[] = _("The quiz answer is?");
#endif
#if GERMAN
const u8 gText_LikeToQuitQuiz[] = _("Möchtest du dieses Quiz");
#else
const u8 gText_LikeToQuitQuiz[] = _("Would you like to quit this quiz");
#endif
#if GERMAN
const u8 gText_ChallengeQuestionMark[] = _("beenden?");
#else
const u8 gText_ChallengeQuestionMark[] = _("challenge?");
#endif
#if GERMAN
const u8 gText_IsThisQuizOK[] = _("Ist dieses Quiz o.k.?");
#else
const u8 gText_IsThisQuizOK[] = _("Is this quiz OK?");
#endif
#if GERMAN
const u8 gText_CreateAQuiz[] = _("Quiz erstellen!");
#else
const u8 gText_CreateAQuiz[] = _("Create a quiz!");
#endif
#if GERMAN
const u8 gText_SelectTheAnswer[] = _("Wähle die Antwort!");
#else
const u8 gText_SelectTheAnswer[] = _("Select the answer!");
#endif
#if GERMAN
const u8 gText_LyricsCantBeDeleted[] = _("Phrasenlöschen ist unmöglich!");
#else
const u8 gText_LyricsCantBeDeleted[] = _("The lyrics can't be deleted.");
#endif
#if GERMAN
const u8 gText_PokemonLeague[] = _("Pokémon Liga");
#else
const u8 gText_PokemonLeague[] = _("POKéMON LEAGUE");
#endif
#if GERMAN
const u8 gText_PokemonCenter[] = _("Pokémon-Center");
#else
const u8 gText_PokemonCenter[] = _("POKéMON CENTER");
#endif
const u8 gText_Coolness[] = _("Coolness ");
#if GERMAN
const u8 gText_Beauty3[] = _("Schönheit ");
#else
const u8 gText_Beauty3[] = _("Beauty ");
#endif
#if GERMAN
const u8 gText_Cuteness[] = _("Anmut ");
#else
const u8 gText_Cuteness[] = _("Cuteness ");
#endif
#if GERMAN
const u8 gText_Smartness[] = _("Klugheit ");
#else
const u8 gText_Smartness[] = _("Smartness ");
#endif
#if GERMAN
const u8 gText_Toughness[] = _("Stärke ");
#else
const u8 gText_Toughness[] = _("Toughness ");
#endif
#if GERMAN
const u8 gText_SaveFailedCheckingBackup[] = _("Speicherfehler! Backup Memory\nwird geprüft. Bitte warten…\n{COLOR RED}“Benötigte Zeit: 1 Minute”");
#else
const u8 gText_SaveFailedCheckingBackup[] = _("Save failed. Checking the backup\nmemory… Please wait.\n{COLOR RED}“Time required: about 1 minute”");
#endif
#if GERMAN
const u8 gText_BackupMemoryDamaged[] = _("Backup Memory defekt oder interne\nBatterie verbraucht! Weiterspielen\nmöglich, speichern nicht!");
#else
const u8 gText_BackupMemoryDamaged[] = _("The backup memory is damaged, or\nthe internal battery has run dry.\nYou can still play, but not save.");
#endif
#if GERMAN
const u8 gText_GamePlayCannotBeContinued[] = _("{COLOR RED}“Spiel fortsetzen nicht möglich.\nZurück zum Titelbildschirm…”");
#else
const u8 gText_GamePlayCannotBeContinued[] = _("{COLOR RED}“Game play cannot be continued.\nReturning to the title screen…”");
#endif
#if GERMAN
const u8 gText_CheckCompleted[] = _("Überprüfung beendet.\nNeuer Speicherversuch erfolgt.\nBitte warten…");
#else
const u8 gText_CheckCompleted[] = _("Check completed.\nAttempting to save again.\nPlease wait.");
#endif
#if GERMAN
const u8 gText_SaveCompleteGameCannotContinue[] = _("Speichern beendet.\n{COLOR RED}“Spiel fortsetzen nicht möglich.\nZurück zum Titelbildschirm.”");
#else
const u8 gText_SaveCompleteGameCannotContinue[] = _("Save completed.\n{COLOR RED}“Game play cannot be continued.\nReturning to the title screen.”");
#endif
#if GERMAN
const u8 gText_SaveCompletePressA[] = _("Speichern beendet.\n{COLOR RED}“Bitte A-Knopf drücken.”");
#else
const u8 gText_SaveCompletePressA[] = _("Save completed.\n{COLOR RED}“Please press the A Button.”");
#endif
#if GERMAN
const u8 gText_Ferry[] = _("Fähre");
#else
const u8 gText_Ferry[] = _("FERRY");
#endif
#if GERMAN
const u8 gText_SecretBase[] = _("Geheimbasis");
#else
const u8 gText_SecretBase[] = _("SECRET BASE");
#endif
#if GERMAN
const u8 gText_Hideout[] = _("Versteck");
#else
const u8 gText_Hideout[] = _("HIDEOUT");
#endif
#if GERMAN
const u8 gText_ResetRTCConfirmCancel[] = _("Echtzeituhr zurücksetzen?\nA: Bestätigen, B: Zurück");
#else
const u8 gText_ResetRTCConfirmCancel[] = _("Reset RTC?\nA: Confirm, B: Cancel");
#endif
#if GERMAN
const u8 gText_PresentTime[] = _("Aktuelle Uhrzeit im Spiel");
#else
const u8 gText_PresentTime[] = _("Present time in game");
#endif
#if GERMAN
const u8 gText_PreviousTime[] = _("Vorherige Uhrzeit im Spiel");
#else
const u8 gText_PreviousTime[] = _("Previous time in game");
#endif
#if GERMAN
const u8 gText_PleaseResetTime[] = _("Bitte die Zeit zurückstellen.");
#else
const u8 gText_PleaseResetTime[] = _("Please reset the time.");
#endif
#if GERMAN
const u8 gText_ClockHasBeenReset[] = _("Die Uhr wurde zurückgestellt. Daten\nwerden gesichert. Bitte warten…");
#else
const u8 gText_ClockHasBeenReset[] = _("The clock has been reset.\nData will be saved. Please wait.");
#endif
#if GERMAN
const u8 gText_SaveCompleted[] = _("Speichern beendet.");
#else
const u8 gText_SaveCompleted[] = _("Save completed.");
#endif
#if GERMAN
const u8 gText_SaveFailed[] = _("Speichern fehlgeschlagen.");
#else
const u8 gText_SaveFailed[] = _("Save failed…");
#endif
#if GERMAN
const u8 gText_NoSaveFileCantSetTime[] = _("Es existiert kein Speicherstand. Uhr-\nzeit kann nicht eingestellt werden.");
#else
const u8 gText_NoSaveFileCantSetTime[] = _("There is no save file, so the time\ncan't be set.");
#endif
#if GERMAN
const u8 gText_InGameClockUsable[] = _("Das spielinterne Zeiteingabe-\nSystem ist jetzt verfügbar.");
#else
const u8 gText_InGameClockUsable[] = _("The in-game clock adjustment system\nis now useable.");
#endif
#if GERMAN
const u8 gText_Spicy2[] = _("scharf");
#else
const u8 gText_Spicy2[] = _("spicy");
#endif
#if GERMAN
const u8 gText_Dry2[] = _("trocken");
#else
const u8 gText_Dry2[] = _("dry");
#endif
#if GERMAN
const u8 gText_Sweet2[] = _("süß");
#else
const u8 gText_Sweet2[] = _("sweet");
#endif
const u8 gText_Bitter2[] = _("bitter");
#if GERMAN
const u8 gText_Sour2[] = _("sauer");
#else
const u8 gText_Sour2[] = _("sour");
#endif
#if GERMAN
const u8 gText_Single[] = _("Einzel");
#else
const u8 gText_Single[] = _("SINGLE");
#endif
#if GERMAN
const u8 gText_Double[] = _("Doppel");
#else
const u8 gText_Double[] = _("DOUBLE");
#endif
#if GERMAN
const u8 gText_Knockout[] = _("Knockout");
#else
const u8 gText_Knockout[] = _("KNOCKOUT");
#endif
#if GERMAN
const u8 gText_Mixed[] = _("Gemischt");
#else
const u8 gText_Mixed[] = _("MIXED");
#endif
#if GERMAN
const u8 gText_First[] = _("ersten Preis");
#else
const u8 gText_First[] = _("first");
#endif
#if GERMAN
const u8 gText_Second[] = _("zweiten Preis");
#else
const u8 gText_Second[] = _("second");
#endif
#if GERMAN
const u8 gText_Third[] = _("dritten Preis");
#else
const u8 gText_Third[] = _("third");
#endif
#if OW_POISON_DAMAGE < GEN_4
#if GERMAN
const u8 gText_PkmnFainted_FldPsn[] = _("{STR_VAR_1} wurde besiegt…\p\n");
#else
const u8 gText_PkmnFainted_FldPsn[] = _("{STR_VAR_1} survived the poisoning.\nThe poison faded away!\p");
#endif
#else
#if GERMAN
const u8 gText_PkmnFainted_FldPsn[] = _("{STR_VAR_1} überlebt das Gift.\nDas Gift ist verschwunden!\p");
#else
const u8 gText_PkmnFainted_FldPsn[] = _("{STR_VAR_1} survived the poisoning.\nThe poison faded away!\p");
#endif
#endif
#if GERMAN
const u8 gText_PkmnSurvived_FldPsn[] = _("{STR_VAR_1} überlebt das Gift.\nDas Gift ist verschwunden!\p");
#else
const u8 gText_PkmnSurvived_FldPsn[] = _("{STR_VAR_1} survived the poisoning.\nThe poison faded away!\p");
#endif
#if GERMAN
const u8 gText_Marco[] = _("Marco");
#else
const u8 gText_Marco[] = _("MARCO");
#endif
#if GERMAN
const u8 gText_TrainerCardName[] = _("Name ");
#else
const u8 gText_TrainerCardName[] = _("NAME: ");
#endif
#if GERMAN
const u8 gText_TrainerCardIDNo[] = _("Idnr.");
#else
const u8 gText_TrainerCardIDNo[] = _("IDNo.");
#endif
#if GERMAN
const u8 gText_TrainerCardMoney[] = _("Geld");
#else
const u8 gText_TrainerCardMoney[] = _("MONEY");
#endif
const u8 gText_PokeDollar[] = _("¥"); // Unused
#if GERMAN
const u8 gText_TrainerCardPokedex[] = _("Pokédex");
#else
const u8 gText_TrainerCardPokedex[] = _("POKéDEX");
#endif
const u8 gText_EmptyString6[] = _("");
const u8 gText_Colon2[] = _(":");
const u8 gText_Points[] = _(" points"); // Unused
#if GERMAN
const u8 gText_TrainerCardTime[] = _("Spielzeit");
#else
const u8 gText_TrainerCardTime[] = _("TIME");
#endif
const u8 gJPText_BattlePoints[] = _("ゲ-ムポイント"); // Unused. Name presumed, translation is Game Points
#if GERMAN
const u8 gText_Var1sTrainerCard[] = _("Trainerpass von {STR_VAR_1}");
#else
const u8 gText_Var1sTrainerCard[] = _("{STR_VAR_1}'s TRAINER CARD");
#endif
#if GERMAN
const u8 gText_HallOfFameDebut[] = _("Erste Ruhmeshalle:");
#else
const u8 gText_HallOfFameDebut[] = _("HALL OF FAME DEBUT  ");
#endif
#if GERMAN
const u8 gText_LinkBattles[] = _("Kämpfe via Link");
#else
const u8 gText_LinkBattles[] = _("LINK BATTLES");
#endif
#if GERMAN
const u8 gText_LinkCableBattles[] = _("Kämpfe gg. Freund/E");
#else
const u8 gText_LinkCableBattles[] = _("LINK CABLE BATTLES");
#endif
#if GERMAN
const u8 gText_WinsLosses[] = _("S.: {COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}  N.: {COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}");
#else
const u8 gText_WinsLosses[] = _("W:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}  L:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}");
#endif
#if GERMAN
const u8 gText_PokemonTrades[] = _("Pokémon-Tausch:");
#else
const u8 gText_PokemonTrades[] = _("POKéMON TRADES");
#endif
#if GERMAN
const u8 gText_UnionTradesAndBattles[] = _("Konnex-Tausche & -Kämpfe:");
#else
const u8 gText_UnionTradesAndBattles[] = _("UNION TRADES & BATTLES");
#endif
#if GERMAN
const u8 gText_BerryCrush[] = _("Beerenmühle:");
#else
const u8 gText_BerryCrush[] = _("BERRY CRUSH");
#endif
#if GERMAN
const u8 gText_WaitingTrainerFinishReading[] = _("Der andere Trainer hat deinen\nTrainerpass noch nicht gelesen.");
#else
const u8 gText_WaitingTrainerFinishReading[] = _("Waiting for the other TRAINER to\nfinish reading your TRAINER CARD.");
#endif
#if GERMAN
const u8 gText_PokeblocksWithFriends[] = _("{POKEBLOCK} mit Freund/En:");
#else
const u8 gText_PokeblocksWithFriends[] = _("{POKEBLOCK}S W/FRIENDS");
#endif
const u8 gText_NumPokeblocks[] = _("{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}");
#if GERMAN
const u8 gText_WonContestsWFriends[] = _("Gew. Wettbewerbe mit Freunden:");
#else
const u8 gText_WonContestsWFriends[] = _("WON CONTESTS W/FRIENDS");
#endif
#if GERMAN
const u8 gText_BattlePtsWon[] = _("Erhaltene Gewinnpunkte:");
#else
const u8 gText_BattlePtsWon[] = _("BATTLE POINTS WON");
#endif
#if GERMAN
const u8 gText_NumBP[] = _("{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}GP");
#else
const u8 gText_NumBP[] = _("{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}BP");
#endif
#if GERMAN
const u8 gText_BattleTower[] = _("Duellturm");
#else
const u8 gText_BattleTower[] = _("BATTLE TOWER");
#endif
#if GERMAN
const u8 gText_WinsStraight[] = _("S.:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} in Folge:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}");
#else
const u8 gText_WinsStraight[] = _("W/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}  STRAIGHT/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}");
#endif
#if GERMAN
const u8 gText_BattleTower2[] = _("Duellturm");
#else
const u8 gText_BattleTower2[] = _("BATTLE TOWER");
#endif
#if GERMAN
const u8 gText_BattleDome[] = _("Kampfstadion");
#else
const u8 gText_BattleDome[] = _("BATTLE DOME");
#endif
#if GERMAN
const u8 gText_BattlePalace[] = _("Kampfpalast");
#else
const u8 gText_BattlePalace[] = _("BATTLE PALACE");
#endif
#if GERMAN
const u8 gText_BattleFactory[] = _("Kampffabrik");
#else
const u8 gText_BattleFactory[] = _("BATTLE FACTORY");
#endif
#if GERMAN
const u8 gText_BattleArena[] = _("Kampfring");
#else
const u8 gText_BattleArena[] = _("BATTLE ARENA");
#endif
#if GERMAN
const u8 gText_BattlePike[] = _("Kampfipitis");
#else
const u8 gText_BattlePike[] = _("BATTLE PIKE");
#endif
#if GERMAN
const u8 gText_BattlePyramid[] = _("Kampfpyramide");
#else
const u8 gText_BattlePyramid[] = _("BATTLE PYRAMID");
#endif

#if GERMAN
ALIGNED(4) const u8 gText_FacilitySingle[] = _("{STR_VAR_1} Einzel");
#else
ALIGNED(4) const u8 gText_FacilitySingle[] = _("{STR_VAR_1} SINGLE");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_FacilityDouble[] = _("{STR_VAR_1} Doppel");
#else
ALIGNED(4) const u8 gText_FacilityDouble[] = _("{STR_VAR_1} DOUBLE");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_FacilityMulti[] = _("{STR_VAR_1} Multi");
#else
ALIGNED(4) const u8 gText_FacilityMulti[] = _("{STR_VAR_1} MULTI");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_FacilityLink[] = _("{STR_VAR_1} Link");
#else
ALIGNED(4) const u8 gText_FacilityLink[] = _("{STR_VAR_1} LINK");
#endif
ALIGNED(4) const u8 gText_Facility[] = _("{STR_VAR_1}");

#if GERMAN
const u8 gText_Give[] = _("Geben");
#else
const u8 gText_Give[] = _("Give");
#endif
#if GERMAN
const u8 gText_NoNeed[] = _("Nein");
#else
const u8 gText_NoNeed[] = _("No need");
#endif
#if GERMAN
const u8 gText_AnnouncingResults[] = _("Bekanntgabe der Ergebnisse!");
#else
const u8 gText_AnnouncingResults[] = _("Announcing the results!");
#endif
#if GERMAN
const u8 gText_PreliminaryResults[] = _("Ergebnisse 1. Durchlauf!");
#else
const u8 gText_PreliminaryResults[] = _("The preliminary results!");
#endif
#if GERMAN
const u8 gText_Round2Results[] = _("Ergebnisse 2. Durchlauf!");
#else
const u8 gText_Round2Results[] = _("Round 2 results!");
#endif
#if GERMAN
const u8 gText_ContestantsMonWon[] = _("Sieger ist: {STR_VAR_2} von {STR_VAR_1}!");
#else
const u8 gText_ContestantsMonWon[] = _("{STR_VAR_1}'s {STR_VAR_2} won!");
#endif
#if GERMAN
const u8 gText_CommunicationStandby[] = _("Verbindung…");
#else
const u8 gText_CommunicationStandby[] = _("Communication standby…");
#endif
const u8 gText_ColorDarkGray[] = _("{COLOR DARK_GRAY}");
#if GERMAN
const u8 gText_ColorDynamic6WhiteDynamic5[] = _("{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR6 WHITE DYNAMIC_COLOR5}");
#else
const u8 gText_ColorDynamic6WhiteDynamic5[] = _("{BACKGROUND WHITE}{TEXT_COLORS DYNAMIC_COLOR6 DYNAMIC_COLOR5 WHITE}");
#endif // Unused
#if GERMAN
const u8 gText_HealthboxNickname[] = _("{HIGHLIGHT DARK_GRAY}");
#else
const u8 gText_HealthboxNickname[] = _("{BACKGROUND DARK_GRAY}{ACCENT DARK_GRAY}");
#endif
const u8 gText_EmptySpace2[] = _(" "); // Unused
const u8 gText_HealthboxGender_Male[] = _("{COLOR DYNAMIC_COLOR2}♂");
const u8 gText_HealthboxGender_Female[] = _("{COLOR DYNAMIC_COLOR1}♀");
const u8 gText_HealthboxGender_None[] = _("{COLOR DYNAMIC_COLOR2}");
#if GERMAN
const u8 gText_Upper[] = _("Groß");
#else
const u8 gText_Upper[] = _("UPPER");
#endif
#if GERMAN
const u8 gText_Lower[] = _("klein");
#else
const u8 gText_Lower[] = _("lower");
#endif
#if GERMAN
const u8 gText_Others[] = _("Others");
#else
const u8 gText_Others[] = _("OTHERS");
#endif
#if GERMAN
const u8 gText_Symbols[] = _("Symbole");
#else
const u8 gText_Symbols[] = _("SYMBOLS");
#endif
#if GERMAN
const u8 gText_Register2[] = _("Wählen");
#else
const u8 gText_Register2[] = _("REGISTER");
#endif
#if GERMAN
const u8 gText_Exit2[] = _("Beenden");
#else
const u8 gText_Exit2[] = _("EXIT");
#endif
#if GERMAN
const u8 gText_QuitChatting[] = _("Chat beenden?");
#else
const u8 gText_QuitChatting[] = _("Quit chatting?");
#endif
#if GERMAN
const u8 gText_RegisterTextWhere[] = _("Wo in Liste schreiben?");
#else
const u8 gText_RegisterTextWhere[] = _("Register text where?");
#endif
#if GERMAN
const u8 gText_RegisterTextHere[] = _("Hier in Liste schreiben?");
#else
const u8 gText_RegisterTextHere[] = _("Register text here?");
#endif
#if GERMAN
const u8 gText_InputText[] = _("Text schreiben.");
#else
const u8 gText_InputText[] = _("Input text.");
#endif
#if GERMAN
const u8 gText_F700JoinedChat[] = _("{DYNAMIC 0} ist im Chat!");
#else
const u8 gText_F700JoinedChat[] = _("{DYNAMIC 0} joined the chat!");
#endif
#if GERMAN
const u8 gText_F700LeftChat[] = _("{DYNAMIC 0} verließ den Chat.");
#else
const u8 gText_F700LeftChat[] = _("{DYNAMIC 0} left the chat.");
#endif
const u8 gJPText_PlayersXPokemon[] = _("{DYNAMIC 0}の{DYNAMIC 1}ひきめ:"); // Unused
const u8 gJPText_PlayersXPokmonDoesNotExist[] = _("{DYNAMIC 0}の{DYNAMIC 1}ひきめは いません"); // Unused
#if GERMAN
const u8 gText_ExitingChat[] = _("Chat wird verlassen…");
#else
const u8 gText_ExitingChat[] = _("Exiting the chat…");
#endif
#if GERMAN
const u8 gText_LeaderLeftEndingChat[] = _("Leiter {DYNAMIC 0} verlässt und\nbeendet somit den Chat.");
#else
const u8 gText_LeaderLeftEndingChat[] = _("The LEADER, {DYNAMIC 0}, has\nleft, ending the chat.");
#endif
#if GERMAN
const u8 gText_RegisteredTextChangedOKToSave[] = _("Der Text in der Liste wurde geändert.\nSoll gespeichert werden?");
#else
const u8 gText_RegisteredTextChangedOKToSave[] = _("The registered text has been changed.\nIs it okay to save the game?");
#endif
#if GERMAN
const u8 gText_AlreadySavedFile_Chat[] = _("Es gibt bereits einen Spielstand.\nSpielstand überschreiben?");
#else
const u8 gText_AlreadySavedFile_Chat[] = _("There is already a saved file.\nIs it okay to overwrite it?");
#endif
#if GERMAN
const u8 gText_SavingDontTurnOff_Chat[] = _("Speichervorgang…\nGerät Nicht Ausschalten!");
#else
const u8 gText_SavingDontTurnOff_Chat[] = _("SAVING…\nDON'T TURN OFF THE POWER.");
#endif
#if GERMAN
const u8 gText_PlayerSavedGame_Chat[] = _("{DYNAMIC 0} hat das Spiel gespeichert.");
#else
const u8 gText_PlayerSavedGame_Chat[] = _("{DYNAMIC 0} saved the game.");
#endif
#if GERMAN
const u8 gText_IfLeaderLeavesChatEnds[] = _("Falls der Leiter den Chat\nverlässt, ist er vorüber, O.K.?");
#else
const u8 gText_IfLeaderLeavesChatEnds[] = _("If the LEADER leaves, the chat\nwill end. Is that okay?");
#endif
#if GERMAN
const u8 gText_Hello[] = _("Hallo");
#else
const u8 gText_Hello[] = _("HELLO");
#endif
#if GERMAN
const u8 gText_Pokemon2[] = _("Pokémon");
#else
const u8 gText_Pokemon2[] = _("POKéMON");
#endif
#if GERMAN
const u8 gText_Trade[] = _("Tausch");
#else
const u8 gText_Trade[] = _("TRADE");
#endif
#if GERMAN
const u8 gText_Battle[] = _("Kampf");
#else
const u8 gText_Battle[] = _("BATTLE");
#endif
#if GERMAN
const u8 gText_Lets[] = _("Auf");
#else
const u8 gText_Lets[] = _("LET'S");
#endif
#if GERMAN
const u8 gText_Ok[] = _("O.K.!");
#else
const u8 gText_Ok[] = _("OK!");
#endif
#if GERMAN
const u8 gText_Sorry[] = _("Sorry");
#else
const u8 gText_Sorry[] = _("SORRY");
#endif
#if GERMAN
const u8 gText_YaySmileEmoji[] = _("Yo{EMOJI_BIGSMILE}");
#else
const u8 gText_YaySmileEmoji[] = _("YAY{EMOJI_BIGSMILE}");
#endif
#if GERMAN
const u8 gText_ThankYou[] = _("Danke");
#else
const u8 gText_ThankYou[] = _("THANK YOU");
#endif
#if GERMAN
const u8 gText_ByeBye[] = _("Tschüss!");
#else
const u8 gText_ByeBye[] = _("BYE-BYE!");
#endif
#if GERMAN
const u8 gText_HatchedFromEgg[] = _("{STR_VAR_1} schlüpfte aus dem Ei!");
#else
const u8 gText_HatchedFromEgg[] = _("{STR_VAR_1} hatched from the EGG!");
#endif
#if GERMAN
const u8 gText_NicknameHatchPrompt[] = _("Möchtest du dem geschlüpften\n{STR_VAR_1} einen Kosenamen geben?");
#else
const u8 gText_NicknameHatchPrompt[] = _("Would you like to nickname the newly\nhatched {STR_VAR_1}?");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_ReadyPickBerry[] = _("Die Beerenmühle starten?\nBitte wähle eine Beere aus!\p");
#else
ALIGNED(4) const u8 gText_ReadyPickBerry[] = _("Are you ready to BERRY-CRUSH?\nPlease pick a BERRY for use.\p");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WaitForAllChooseBerry[] = _("Bitte warte, bis alle Mitspieler\nBeeren ausgewählt haben.");
#else
ALIGNED(4) const u8 gText_WaitForAllChooseBerry[] = _("Please wait while each member\nchooses a BERRY.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_EndedWithXUnitsPowder[] = _("{PAUSE_MUSIC}{PLAY_BGM MUS_LEVEL_UP}Du hast {STR_VAR_1} Einheiten seiden-\nweichen Beerenpuder erhalten.{RESUME_MUSIC}\pDein Bestand an Beerenpuder ist\n{STR_VAR_2} Einheiten.\p");
#else
ALIGNED(4) const u8 gText_EndedWithXUnitsPowder[] = _("{PAUSE_MUSIC}{PLAY_BGM MUS_LEVEL_UP}You ended up with {STR_VAR_1} units of\nsilky-smooth BERRY POWDER.{RESUME_MUSIC}\pYour total amount of BERRY POWDER\nis {STR_VAR_2}.\p");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_RecordingGameResults[] = _("Das Resultat wird gespeichert.\nBitte warten!");
#else
ALIGNED(4) const u8 gText_RecordingGameResults[] = _("Recording your game results in the\nsave file.\lPlease wait.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_PlayBerryCrushAgain[] = _("Möchtest du erneut die\nBeerenmühle betreiben?");
#else
ALIGNED(4) const u8 gText_PlayBerryCrushAgain[] = _("Want to play BERRY CRUSH again?");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_YouHaveNoBerries[] = _("Du hast keine Beeren!\nDas Spiel wird abgebrochen.");
#else
ALIGNED(4) const u8 gText_YouHaveNoBerries[] = _("You have no BERRIES.\nThe game will be canceled.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_MemberDroppedOut[] = _("Ein Mitspieler hat abgebrochen.\nDas Spiel wird beendet.");
#else
ALIGNED(4) const u8 gText_MemberDroppedOut[] = _("A member dropped out.\nThe game will be canceled.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_TimesUpNoGoodPowder[] = _("Die Zeit ist abgelaufen!\pEs konnte kein guter Beerenpuder\nhergestellt werden…\p");
#else
ALIGNED(4) const u8 gText_TimesUpNoGoodPowder[] = _("Time's up.\pGood BERRY POWDER could not be\nmade…\p");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_CommunicationStandby2[] = _("Verbindung…");
#else
ALIGNED(4) const u8 gText_CommunicationStandby2[] = _("Communication standby…");
#endif
ALIGNED(4) const u8 gText_1DotBlueF700[] = _("1. {COLOR BLUE}{SHADOW LIGHT_BLUE}{DYNAMIC 0}");
ALIGNED(4) const u8 gText_1DotF700[] = _("1. {DYNAMIC 0}");
#if GERMAN
ALIGNED(4) const u8 gText_SpaceTimes2[] = _("-mal");
#else
ALIGNED(4) const u8 gText_SpaceTimes2[] = _(" time(s)");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_XDotY[] = _("{STR_VAR_1},{STR_VAR_2}");
#else
ALIGNED(4) const u8 gText_XDotY[] = _("{STR_VAR_1}.{STR_VAR_2}");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_Var1Berry[] = _("{STR_VAR_1}Beere");
#else
ALIGNED(4) const u8 gText_Var1Berry[] = _("{STR_VAR_1} BERRY");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_TimeColon[] = _("Zeit:");
#else
ALIGNED(4) const u8 gText_TimeColon[] = _("Time:");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_PressingSpeed[] = _("Mahltempo:");
#else
ALIGNED(4) const u8 gText_PressingSpeed[] = _("Pressing Speed:");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_Silkiness[] = _("Feinheit:");
#else
ALIGNED(4) const u8 gText_Silkiness[] = _("Silkiness:");
#endif
ALIGNED(4) const u8 gText_StrVar1[] = _("{STR_VAR_1}");
#if GERMAN
ALIGNED(4) const u8 gText_SpaceMin[] = _("Min. ");
#else
ALIGNED(4) const u8 gText_SpaceMin[] = _(" min. ");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_XDotY2[] = _("{STR_VAR_1},{STR_VAR_2}");
#else
ALIGNED(4) const u8 gText_XDotY2[] = _("{STR_VAR_1}.{STR_VAR_2}");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_SpaceSec[] = _("Sek.");
#else
ALIGNED(4) const u8 gText_SpaceSec[] = _(" sec.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_XDotY3[] = _("{STR_VAR_1},{STR_VAR_2}");
#else
ALIGNED(4) const u8 gText_XDotY3[] = _("{STR_VAR_1}.{STR_VAR_2}");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_TimesPerSec[] = _("-mal/Sek.");
#else
ALIGNED(4) const u8 gText_TimesPerSec[] = _(" Times/sec.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_Var1Percent[] = _("{STR_VAR_1} %");
#else
ALIGNED(4) const u8 gText_Var1Percent[] = _("{STR_VAR_1}%");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_PressesRankings[] = _("Platz nach Druckvorgängen");
#else
ALIGNED(4) const u8 gText_PressesRankings[] = _("No. of Presses Rankings");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_CrushingResults[] = _("Mahlresultat");
#else
ALIGNED(4) const u8 gText_CrushingResults[] = _("Crushing Results");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_NeatnessRankings[] = _("Beschaffenheits-Platzierung");
#else
ALIGNED(4) const u8 gText_NeatnessRankings[] = _("Neatness Rankings");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_CoopRankings[] = _("Kooperations-Platzierung");
#else
ALIGNED(4) const u8 gText_CoopRankings[] = _("Cooperative Rankings");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_PressingPowerRankings[] = _("Druckkraft-Platzierung");
#else
ALIGNED(4) const u8 gText_PressingPowerRankings[] = _("Pressing-Power Rankings");
#endif
#if GERMAN
const u8 gText_BerryCrush2[] = _("Beerenmühle");
#else
const u8 gText_BerryCrush2[] = _("BERRY CRUSH");
#endif
#if GERMAN
const u8 gText_PressingSpeedRankings[] = _("Drucktempo-Platzierung");
#else
const u8 gText_PressingSpeedRankings[] = _("Pressing-Speed Rankings");
#endif
#if GERMAN
const u8 gText_Var1Players[] = _("{STR_VAR_1} Spieler");
#else
const u8 gText_Var1Players[] = _("{STR_VAR_1} PLAYERS");
#endif
#if GERMAN
const u8 gText_SymbolsEarned[] = _("Gew. Symbole");
#else
const u8 gText_SymbolsEarned[] = _("Symbols Earned");
#endif
#if GERMAN
const u8 gText_BattleRecord[] = _("Video");
#else
const u8 gText_BattleRecord[] = _("Battle Record");
#endif
#if GERMAN
const u8 gText_BattlePoints[] = _("Gewinnpunkte");
#else
const u8 gText_BattlePoints[] = _("Battle Points");
#endif
#if GERMAN
const u8 gText_UnusedCancel[] = _("Cancel");
#else
const u8 gText_UnusedCancel[] = _("CANCEL");
#endif // Unused
const u8 gText_EmptyString7[] = _("");
#if GERMAN
const u8 gText_CheckFrontierMap[] = _("Kampfzonenkarte ansehen");
#else
const u8 gText_CheckFrontierMap[] = _("Check BATTLE FRONTIER MAP.");
#endif
#if GERMAN
const u8 gText_CheckTrainerCard[] = _("Trainerpass ansehen");
#else
const u8 gText_CheckTrainerCard[] = _("Check TRAINER CARD.");
#endif
#if GERMAN
const u8 gText_ViewRecordedBattle[] = _("Kampfaufzeichnung ansehen");
#else
const u8 gText_ViewRecordedBattle[] = _("View recorded battle.");
#endif
#if GERMAN
const u8 gText_PutAwayFrontierPass[] = _("Kampfzonenpass wegstecken");
#else
const u8 gText_PutAwayFrontierPass[] = _("Put away the FRONTIER PASS.");
#endif
#if GERMAN
const u8 gText_CurrentBattlePoints[] = _("Aktuelle Anzahl der Gewinnpunkte");
#else
const u8 gText_CurrentBattlePoints[] = _("Your current Battle Points.");
#endif
#if GERMAN
const u8 gText_CollectedSymbols[] = _("Die erhaltenen Symbole");
#else
const u8 gText_CollectedSymbols[] = _("Your collected Symbols.");
#endif
#if GERMAN
const u8 gText_BattleTowerAbilitySymbol[] = _("Duellturm - Anlagesymbol");
#else
const u8 gText_BattleTowerAbilitySymbol[] = _("Battle Tower - Ability Symbol");
#endif
#if GERMAN
const u8 gText_BattleDomeTacticsSymbol[] = _("Kampfstadion - Taktiksymbol");
#else
const u8 gText_BattleDomeTacticsSymbol[] = _("Battle Dome - Tactics Symbol");
#endif
#if GERMAN
const u8 gText_BattlePalaceSpiritsSymbol[] = _("Kampfpalast - Seelensymbol");
#else
const u8 gText_BattlePalaceSpiritsSymbol[] = _("Battle Palace - Spirits Symbol");
#endif
#if GERMAN
const u8 gText_BattleArenaGutsSymbol[] = _("Kampfring - Grobsymbol");
#else
const u8 gText_BattleArenaGutsSymbol[] = _("Battle Arena - Guts Symbol");
#endif
#if GERMAN
const u8 gText_BattleFactoryKnowledgeSymbol[] = _("Kampffabrik - Kenntnissymbol");
#else
const u8 gText_BattleFactoryKnowledgeSymbol[] = _("Battle Factory - Knowledge Symbol");
#endif
#if GERMAN
const u8 gText_BattlePikeLuckSymbol[] = _("Kampfipitis - Lossymbol");
#else
const u8 gText_BattlePikeLuckSymbol[] = _("Battle Pike - Luck Symbol");
#endif
#if GERMAN
const u8 gText_BattlePyramidBraveSymbol[] = _("Kampfpyramide - Bravursymbol");
#else
const u8 gText_BattlePyramidBraveSymbol[] = _("Battle Pyramid - Brave Symbol");
#endif
#if GERMAN
const u8 gText_ThereIsNoBattleRecord[] = _("Es gibt keine Kampfaufzeichnung.");
#else
const u8 gText_ThereIsNoBattleRecord[] = _("There is no Battle Record.");
#endif
#if GERMAN
const u8 gText_BattleTower3[] = _("Duellturm");
#else
const u8 gText_BattleTower3[] = _("BATTLE TOWER");
#endif
#if GERMAN
const u8 gText_BattleDome2[] = _("Kampfstadion");
#else
const u8 gText_BattleDome2[] = _("BATTLE DOME");
#endif
#if GERMAN
const u8 gText_BattlePalace2[] = _("Kampfpalast");
#else
const u8 gText_BattlePalace2[] = _("BATTLE PALACE");
#endif
#if GERMAN
const u8 gText_BattleArena2[] = _("Kampfring");
#else
const u8 gText_BattleArena2[] = _("BATTLE ARENA");
#endif
#if GERMAN
const u8 gText_BattleFactory2[] = _("Kampffabrik");
#else
const u8 gText_BattleFactory2[] = _("BATTLE FACTORY");
#endif
#if GERMAN
const u8 gText_BattlePike2[] = _("Kampfipitis");
#else
const u8 gText_BattlePike2[] = _("BATTLE PIKE");
#endif
#if GERMAN
const u8 gText_BattlePyramid2[] = _("Kampfpyramide");
#else
const u8 gText_BattlePyramid2[] = _("BATTLE PYRAMID");
#endif
#if GERMAN
const u8 gText_BattleTowerDesc[] = _("Kämpfe, bis du die Spitze erreichst!\nDeine Anlagen werden geprüft.");
#else
const u8 gText_BattleTowerDesc[] = _("KO opponents and aim for the top!\nYour ability will be tested.");
#endif
#if GERMAN
const u8 gText_BattleDomeDesc[] = _("Gewinne das Turnier!\nDeine Taktik wird geprüft.");
#else
const u8 gText_BattleDomeDesc[] = _("Keep winning at the tournament!\nYour tactics will be tested.");
#endif
#if GERMAN
const u8 gText_BattlePalaceDesc[] = _("Achte auf deine Pokémon!\nDeine Seele wird geprüft.");
#else
const u8 gText_BattlePalaceDesc[] = _("Watch your POKéMON battle!\nYour spirit will be tested.");
#endif
#if GERMAN
const u8 gText_BattleArenaDesc[] = _("Gewinne im Team!\nDeine Grobheit wird geprüft.");
#else
const u8 gText_BattleArenaDesc[] = _("Win battles with teamed-up POKéMON!\nYour guts will be tested.");
#endif
#if GERMAN
const u8 gText_BattleFactoryDesc[] = _("Gewinne mit Leih-Pokémon!\nDeine Kenntnisse werden geprüft.");
#else
const u8 gText_BattleFactoryDesc[] = _("Aim for victory using rental POKéMON!\nYour knowledge will be tested.");
#endif
#if GERMAN
const u8 gText_BattlePikeDesc[] = _("Wähle einen der drei Pfade aus!\nDein Los wird geprüft.");
#else
const u8 gText_BattlePikeDesc[] = _("Select one of three paths to battle!\nYour luck will be tested.");
#endif
#if GERMAN
const u8 gText_BattlePyramidDesc[] = _("Forsche dich ganz nach oben!\nDeine Bravur wird geprüft.");
#else
const u8 gText_BattlePyramidDesc[] = _("Aim for the top with exploration!\nYour bravery will be tested.");
#endif
#if GERMAN
const u8 gText_Powder[] = _("Puder");
#else
const u8 gText_Powder[] = _("POWDER");
#endif
#if GERMAN
const u8 gText_BerryPickingRecords[] = _("Rekorde für Beerenernte mit Dodri");
#else
const u8 gText_BerryPickingRecords[] = _("DODRIO BERRY-PICKING RECORDS");
#endif
#if GERMAN
const u8 gText_BerriesPicked[] = _("Geerntete Beeren:");
#else
const u8 gText_BerriesPicked[] = _("BERRIES picked:");
#endif
#if GERMAN
const u8 gText_BestScore[] = _("Höchstpunktzahl:");
#else
const u8 gText_BestScore[] = _("Best score:");
#endif
#if GERMAN
const u8 gText_BerriesInRowFivePlayers[] = _("Geerntete Beeren in Folge bei\nfünf Spielern:");
#else
const u8 gText_BerriesInRowFivePlayers[] = _("BERRIES picked in a row with\nfive players:");
#endif
#if GERMAN
const u8 gText_BerryPickingResults[] = _("Resultat der Beerenernte!");
#else
const u8 gText_BerryPickingResults[] = _("Announcing BERRY-PICKING results!");
#endif
#if GERMAN
const u8 gText_10P30P50P50P[] = _("{CLEAR_TO 0x03}10Pkt.{CLEAR_TO 0x2B}30Pkt.{CLEAR_TO 0x53}50Pkt.{CLEAR_TO 0x77}{EMOJI_MINUS}50Pkt.");
#else
const u8 gText_10P30P50P50P[] = _("{CLEAR_TO 0x03}10P{CLEAR_TO 0x2B}30P{CLEAR_TO 0x53}50P{CLEAR_TO 0x77}{EMOJI_MINUS}50P");
#endif
#if GERMAN
const u8 gText_AnnouncingRankings[] = _("Die Platzierungen!");
#else
const u8 gText_AnnouncingRankings[] = _("Announcing rankings!");
#endif
#if GERMAN
const u8 gText_AnnouncingPrizes[] = _("Die Preise!");
#else
const u8 gText_AnnouncingPrizes[] = _("Announcing prizes!");
#endif
const u8 gText_1Colon[] = _("1:");
const u8 gText_2Colon[] = _("2:");
const u8 gText_3Colon[] = _("3:");
const u8 gText_4Colon[] = _("4:");
const u8 gText_5Colon[] = _("5:");
#if GERMAN
const u8 gText_FirstPlacePrize[] = _("Der Erstplatzierte erhält:\n{DYNAMIC 0}!");
#else
const u8 gText_FirstPlacePrize[] = _("The first-place winner gets\nthis {DYNAMIC 0}!");
#endif
#if GERMAN
const u8 gText_CantHoldAnyMore[] = _("Mehr tragen unmöglich.");
#else
const u8 gText_CantHoldAnyMore[] = _("You can't hold any more!");
#endif
#if GERMAN
const u8 gText_FilledStorageSpace[] = _("Der Lagerplatz wurde aufgebraucht.");
#else
const u8 gText_FilledStorageSpace[] = _("It filled its storage space.");
#endif
#if GERMAN
const u8 gText_WantToPlayAgain[] = _("Erneut spielen?");
#else
const u8 gText_WantToPlayAgain[] = _("Want to play again?");
#endif
#if GERMAN
const u8 gText_SomeoneDroppedOut[] = _("Irgendjemand hat abgebrochen!\nVerbindung wird abgebrochen!");
#else
const u8 gText_SomeoneDroppedOut[] = _("Somebody dropped out.\nThe link will be canceled.");
#endif
#if GERMAN
const u8 gText_SpacePoints[] = _(" Punkte");
#else
const u8 gText_SpacePoints[] = _(" points");
#endif
#if GERMAN
const u8 gText_CommunicationStandby3[] = _("Verbindung…");
#else
const u8 gText_CommunicationStandby3[] = _("Communication standby…");
#endif
#if GERMAN
const u8 gText_SpacePoints2[] = _(" Punkte");
#else
const u8 gText_SpacePoints2[] = _(" points");
#endif
#if GERMAN
const u8 gText_SpaceTimes3[] = _("-mal");
#else
const u8 gText_SpaceTimes3[] = _(" time(s)");
#endif
#if GERMAN
const u8 gText_PkmnJumpRecords[] = _("Rekorde für Pokémon-Sprung");
#else
const u8 gText_PkmnJumpRecords[] = _("POKéMON JUMP RECORDS");
#endif
#if GERMAN
const u8 gText_JumpsInARow[] = _("Sprünge in Folge:");
#else
const u8 gText_JumpsInARow[] = _("Jumps in a row:");
#endif
#if GERMAN
const u8 gText_BestScore2[] = _("Höchstpunktzahl:");
#else
const u8 gText_BestScore2[] = _("Best score:");
#endif
#if GERMAN
const u8 gText_ExcellentsInARow[] = _("Famos in Folge:");
#else
const u8 gText_ExcellentsInARow[] = _("EXCELLENTS in a row:");
#endif
#if GERMAN
const u8 gText_AwesomeWonF701F700[] = _("Tolle Leistung! Du hast\n{DYNAMIC 1} {DYNAMIC 0} gewonnen!");
#else
const u8 gText_AwesomeWonF701F700[] = _("Awesome score! You've\nwon {DYNAMIC 1} {DYNAMIC 0}!");
#endif
#if GERMAN
const u8 gText_FilledStorageSpace2[] = _("Kein Platz mehr!");
#else
const u8 gText_FilledStorageSpace2[] = _("It filled its storage space.");
#endif
#if GERMAN
const u8 gText_CantHoldMore[] = _("Mehr tragen unmöglich.");
#else
const u8 gText_CantHoldMore[] = _("You can't hold any more!");
#endif
#if GERMAN
const u8 gText_WantToPlayAgain2[] = _("Erneut spielen?");
#else
const u8 gText_WantToPlayAgain2[] = _("Want to play again?");
#endif
#if GERMAN
const u8 gText_SomeoneDroppedOut2[] = _("Irgendjemand hat abgebrochen!\nVerbindung wird abgebrochen!");
#else
const u8 gText_SomeoneDroppedOut2[] = _("Somebody dropped out.\nThe link will be canceled.");
#endif
#if GERMAN
const u8 gText_CommunicationStandby4[] = _("Verbindung…");
#else
const u8 gText_CommunicationStandby4[] = _("Communication standby…");
#endif
#if GERMAN
const u8 gText_LinkContestResults[] = _("Linkwettbewerbsergebnis v. {PLAYER}");
#else
const u8 gText_LinkContestResults[] = _("{PLAYER}'s Link Contest Results");
#endif
#if GERMAN
const u8 gText_1st[] = _("1. ");
#else
const u8 gText_1st[] = _("1st");
#endif
#if GERMAN
const u8 gText_2nd[] = _("2. ");
#else
const u8 gText_2nd[] = _("2nd");
#endif
#if GERMAN
const u8 gText_3rd[] = _("3. ");
#else
const u8 gText_3rd[] = _("3rd");
#endif
#if GERMAN
const u8 gText_4th[] = _("4. ");
#else
const u8 gText_4th[] = _("4th");
#endif
const u8 gText_Friend[] = _("Friend");
#if GERMAN
const u8 gText_Pokemon3[] = _("Pokémon");
#else
const u8 gText_Pokemon3[] = _("POKeMON");
#endif // Unused
const u8 gJPText_MysteryGift[] = _("ふしぎなもらいもの");
const u8 gJPText_DecideStop[] = _("{A_BUTTON}けってい {B_BUTTON}やめる");
const u8 gJPText_ReceiveMysteryGiftWithEReader[] = _("カードeリーダー{PLUS}　で\nふしぎなもらいものを　よみこみます");
const u8 gJPText_SelectConnectFromEReaderMenu[] = _("カードeリーダー{PLUS}の　メニューから\n‘つうしん'を　えらび");
const u8 gJPText_SelectConnectWithGBA[] = _("‘ゲームボーイアドバンスとつうしん'\nを　せんたく　してください");
const u8 gJPText_SelectConnectAndPressA[] = _("カードeリーダー{PLUS}の　‘つうしん'を\nえらんで　Aボタンを　おしてください"); // Unused
const u8 gJPText_LinkIsIncorrect[] = _("せつぞくが　まちがっています");
const u8 gJPText_CardReadingHasBeenHalted[] = _("カードの　よみこみを\nちゅうし　しました");
const u8 gJPText_UnableConnectWithEReader[] = _("カードeリーダー{PLUS}と\nつうしん　できません"); // Unused
const u8 gJPText_Connecting[] = _("つうしん　ちゅう　です");
const u8 gJPText_ConnectionErrorCheckLink[] = _("つうしん　エラーです\nせつぞくを　たしかめて　ください");
const u8 gJPText_ConnectionErrorTryAgain[] = _("つうしん　エラーです\nはじめから　やりなおして　ください"); // Link error
const u8 gJPText_AllowEReaderToLoadCard[] = _("カードeリーダー{PLUS}　に\nカードを　よみこませて　ください");
const u8 gJPText_ConnectionComplete[] = _("つうしん　しゅうりょう！");
const u8 gJPText_NewTrainerHasComeToHoenn[] = _("あらたな　トレーナーが\nホウエンに　やってきた！");
const u8 gJPText_PleaseWaitAMoment[] = _("しばらく　おまちください");
const u8 gJPText_WriteErrorUnableToSaveData[] = _("かきこみ　エラー　です\nデータが　ほぞん　できませんでした");
#if GERMAN
const u8 gText_SingleBattleRoomResults[] = _("Einzelkampfraumergebnis von {PLAYER}");
#else
const u8 gText_SingleBattleRoomResults[] = _("{PLAYER}'s Single Battle Room Results");
#endif
#if GERMAN
const u8 gText_DoubleBattleRoomResults[] = _("Doppelkampfraumergebnis von {PLAYER}");
#else
const u8 gText_DoubleBattleRoomResults[] = _("{PLAYER}'s Double Battle Room Results");
#endif
#if GERMAN
const u8 gText_MultiBattleRoomResults[] = _("Multikampfraumergebnis von {PLAYER}");
#else
const u8 gText_MultiBattleRoomResults[] = _("{PLAYER}'s Multi Battle Room Results");
#endif
#if GERMAN
const u8 gText_LinkMultiBattleRoomResults[] = _("Linkmultikampfraumergebnis von {PLAYER}");
#else
const u8 gText_LinkMultiBattleRoomResults[] = _("{PLAYER}'s Link Multi Battle Room Results");
#endif
#if GERMAN
const u8 gText_SingleBattleTourneyResults[] = _("Einzelturnierkampfergebnis von {PLAYER}");
#else
const u8 gText_SingleBattleTourneyResults[] = _("{PLAYER}'s Single Battle Tourney Results");
#endif
#if GERMAN
const u8 gText_DoubleBattleTourneyResults[] = _("Doppelturnierkampfergebnis von {PLAYER}");
#else
const u8 gText_DoubleBattleTourneyResults[] = _("{PLAYER}'s Double Battle Tourney Results");
#endif
#if GERMAN
const u8 gText_SingleBattleHallResults[] = _("Einzelaufsichtshallenergebnis v. {PLAYER}");
#else
const u8 gText_SingleBattleHallResults[] = _("{PLAYER}'s Single Battle Hall Results");
#endif
#if GERMAN
const u8 gText_DoubleBattleHallResults[] = _("Doppelaufsichtshallenergebnis v. {PLAYER}");
#else
const u8 gText_DoubleBattleHallResults[] = _("{PLAYER}'s Double Battle Hall Results");
#endif
#if GERMAN
const u8 gText_BattleChoiceResults[] = _("Kampfbahnergebnis von {PLAYER}");
#else
const u8 gText_BattleChoiceResults[] = _("{PLAYER}'s Battle Choice Results");
#endif
#if GERMAN
const u8 gText_SetKOTourneyResults[] = _("K.O.-Teamturnierergebnis von {PLAYER}");
#else
const u8 gText_SetKOTourneyResults[] = _("{PLAYER}'s Set KO Tourney Results");
#endif
#if GERMAN
const u8 gText_BattleSwapSingleResults[] = _("Wechselkampfeinzelergebnis von {PLAYER}");
#else
const u8 gText_BattleSwapSingleResults[] = _("{PLAYER}'s Battle Swap Single Results");
#endif
#if GERMAN
const u8 gText_BattleSwapDoubleResults[] = _("Wechselkampfdoppelergebnis von {PLAYER}");
#else
const u8 gText_BattleSwapDoubleResults[] = _("{PLAYER}'s Battle Swap Double Results");
#endif
#if GERMAN
const u8 gText_BattleQuestResults[] = _("Kampfforschungsergebnis von {PLAYER}");
#else
const u8 gText_BattleQuestResults[] = _("{PLAYER}'s Battle Quest Results");
#endif
const u8 gText_Lv502[] = _("LV. 50");
#if GERMAN
const u8 gText_OpenLv[] = _("Freies Lv.");
#else
const u8 gText_OpenLv[] = _("OPEN LV.");
#endif
#if GERMAN
const u8 gText_WinStreak[] = _("Siegesserie: {STR_VAR_1}");
#else
const u8 gText_WinStreak[] = _("Win streak: {STR_VAR_1}");
#endif
#if GERMAN
const u8 gText_Current[] = _("Moment.");
#else
const u8 gText_Current[] = _("CURRENT");
#endif
#if GERMAN
const u8 gText_Record[] = _("Rekord");
#else
const u8 gText_Record[] = _("RECORD");
#endif
#if GERMAN
const u8 gText_Prev[] = _("Vorher");
#else
const u8 gText_Prev[] = _("PREV.");
#endif
#if GERMAN
const u8 gText_RentalSwap[] = _("Leih/Wechsel");
#else
const u8 gText_RentalSwap[] = _("Rental/Swap");
#endif
#if GERMAN
const u8 gText_Total[] = _("Gesamt");
#else
const u8 gText_Total[] = _("Total");
#endif
#if GERMAN
const u8 gText_ClearStreak[] = _("Erfolgsserie: {STR_VAR_1}");
#else
const u8 gText_ClearStreak[] = _("Clear streak: {STR_VAR_1}");
#endif
#if GERMAN
const u8 gText_Championships[] = _("Gesamtgewinne: {STR_VAR_1}");
#else
const u8 gText_Championships[] = _("Championships: {STR_VAR_1}");
#endif
#if GERMAN
const u8 gText_RoomsCleared[] = _("Absolv. Räume: {STR_VAR_1}");
#else
const u8 gText_RoomsCleared[] = _("Rooms cleared: {STR_VAR_1}");
#endif
#if GERMAN
const u8 gText_TimesCleared[] = _("Erf. Teilnahmen: {STR_VAR_1}");
#else
const u8 gText_TimesCleared[] = _("Times cleared:{CLEAR 0x05}{STR_VAR_1}");
#endif
#if GERMAN
const u8 gText_KOsInARow[] = _("K.O.-Serie: {STR_VAR_1}");
#else
const u8 gText_KOsInARow[] = _("KOs in a row: {STR_VAR_1}");
#endif
#if GERMAN
const u8 gText_TimesVar1[] = _("Anzahl: {STR_VAR_1}");
#else
const u8 gText_TimesVar1[] = _("Times: {STR_VAR_1}");
#endif
#if GERMAN
const u8 gText_FloorsCleared[] = _("Abs. Eb.: {STR_VAR_1}");
#else
const u8 gText_FloorsCleared[] = _("Floors cleared: {STR_VAR_1}");
#endif

ALIGNED(4) const u8 gText_RecordsLv50[] = _("LV. 50");
#if GERMAN
ALIGNED(4) const u8 gText_RecordsOpenLevel[] = _("Offene Kämpfe");
#else
ALIGNED(4) const u8 gText_RecordsOpenLevel[] = _("OPEN LEVEL");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_FrontierFacilityWinStreak[] = _("Siegesserie: {STR_VAR_2}");
#else
ALIGNED(4) const u8 gText_FrontierFacilityWinStreak[] = _("Win streak: {STR_VAR_2}");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_FrontierFacilityClearStreak[] = _("Erfolgsserie: {STR_VAR_2}");
#else
ALIGNED(4) const u8 gText_FrontierFacilityClearStreak[] = _("Clear streak: {STR_VAR_2}");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_FrontierFacilityRoomsCleared[] = _("Absolv. Räume: {STR_VAR_2}");
#else
ALIGNED(4) const u8 gText_FrontierFacilityRoomsCleared[] = _("Rooms cleared: {STR_VAR_2}");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_FrontierFacilityKOsStreak[] = _("K.O.-Serie: {STR_VAR_2}");
#else
ALIGNED(4) const u8 gText_FrontierFacilityKOsStreak[] = _("KOs in a row: {STR_VAR_2}");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_FrontierFacilityFloorsCleared[] = _("Abs. Eb.: {STR_VAR_2}");
#else
ALIGNED(4) const u8 gText_FrontierFacilityFloorsCleared[] = _("Floors cleared: {STR_VAR_2}");
#endif
ALIGNED(4) const u8 gText_123Dot[][3] = {_("1."), _("2."), _("3.")};
#if GERMAN
const u8 gText_FrontierFacilityTotalCaughtSpeciesBanned[] = _(" und {STR_VAR_2} der gefangenen\nPokémon-Arten sind nicht zugelassen");
#else
const u8 gText_FrontierFacilityTotalCaughtSpeciesBanned[] = _(" and {STR_VAR_2} of the POKéMON species\nyou caught are inelegible");
#endif
const u8 gText_FrontierFacilityIncluding[] = _(".\pThese include ");
#if GERMAN
const u8 gText_FrontierFacilityAreInelegible[] = _(" sind nicht zugelassen");
#else
const u8 gText_FrontierFacilityAreInelegible[] = _(" are inelegible");
#endif

#if GERMAN
const u8 gText_YesNo[] = _("Ja\nNein");
#else
const u8 gText_YesNo[] = _("YES\nNO");
#endif
const u8 gText_SelectorArrow3[] = _("▶");
#if GERMAN
const u8 gText_Peekaboo[] = _("Prüfblick");
#else
const u8 gText_Peekaboo[] = _("PEEKABOO!");
#endif
#if GERMAN
const u8 gText_CommErrorCheckConnections[] = _("Verbindungsfehler…\nÜberprüfe bitte alle Verbindungen\nund schalte das Gerät aus und wieder ein.");
#else
const u8 gText_CommErrorCheckConnections[] = _("Communication error…\nPlease check all connections,\nthen turn the power OFF and ON.");
#endif
#if GERMAN
const u8 gText_CommErrorEllipsis[] = _("Verbindungsfehler…");
#else
const u8 gText_CommErrorEllipsis[] = _("Communication error…");
#endif
#if GERMAN
const u8 gText_MoveCloserToLinkPartner[] = _("Verkürze die Distanz zum Mitspieler.\nVermeide Hindernisse zum Mitspieler.");
#else
const u8 gText_MoveCloserToLinkPartner[] = _("Move closer to your link partner(s).\nAvoid obstacles between partners.");
#endif
#if GERMAN
const u8 gText_ABtnRegistrationCounter[] = _("A-Knopf: Rezeption");
#else
const u8 gText_ABtnRegistrationCounter[] = _("A Button: Registration Counter");
#endif
#if GERMAN
const u8 gText_ABtnTitleScreen[] = _("A-Knopf: Titelbildschirm");
#else
const u8 gText_ABtnTitleScreen[] = _("A Button: Title Screen");
#endif
#if GERMAN
const u8 gText_NumPlayerLink[] = _("{STR_VAR_1}Sp-Link");
#else
const u8 gText_NumPlayerLink[] = _("{STR_VAR_1}P LINK");
#endif
#if GERMAN
const u8 gText_BronzeCard[] = _("Bronze");
#else
const u8 gText_BronzeCard[] = _("BRONZE");
#endif
#if GERMAN
const u8 gText_CopperCard[] = _("Kupferrot");
#else
const u8 gText_CopperCard[] = _("COPPER");
#endif
#if GERMAN
const u8 gText_SilverCard[] = _("Silber");
#else
const u8 gText_SilverCard[] = _("SILVER");
#endif
#if GERMAN
const u8 gText_GoldCard[] = _("Gold");
#else
const u8 gText_GoldCard[] = _("GOLD");
#endif
#if GERMAN
const u8 gText_Day[] = _("Tag");
#else
const u8 gText_Day[] = _("DAY");
#endif
const u8 gText_Colon3[] = _(":");
#if GERMAN
const u8 gText_Confirm2[] = _("O.K.");
#else
const u8 gText_Confirm2[] = _("CONFIRM");
#endif
#if GERMAN
const u8 gText_Days[] = _("Tage");
#else
const u8 gText_Days[] = _("Days");
#endif // Unused
#if GERMAN
const u8 gText_TimeColon2[] = _("Zeit");
#else
const u8 gText_TimeColon2[] = _("Time:");
#endif // Unused
#if GERMAN
const u8 gText_GameTime[] = _("Spielzeit");
#else
const u8 gText_GameTime[] = _("Game time");
#endif // Unused
#if GERMAN
const u8 gText_RTCTime[] = _("Echtzeituhr");
#else
const u8 gText_RTCTime[] = _("RTC time");
#endif // Unused
#if GERMAN
const u8 gText_UpdatedTime[] = _("Aktualisierte Zeit");
#else
const u8 gText_UpdatedTime[] = _("Updated time");
#endif // Unused
#if GERMAN
const u8 gText_MenuPokedex[] = _("Pokédex");
#else
const u8 gText_MenuPokedex[] = _("POKéDEX");
#endif
#if GERMAN
const u8 gText_MenuPokemon[] = _("Pokémon");
#else
const u8 gText_MenuPokemon[] = _("POKéMON");
#endif
#if GERMAN
const u8 gText_MenuBag[] = _("Beutel");
#else
const u8 gText_MenuBag[] = _("BAG");
#endif
#if IS_HNS
#if GERMAN
const u8 gText_MenuPokenav[] = _("PokéCom");
#else
const u8 gText_MenuPokenav[] = _("POKéNAV");
#endif
#else
#if GERMAN
const u8 gText_MenuPokenav[] = _("Pokénav");
#else
const u8 gText_MenuPokenav[] = _("POKéNAV");
#endif
#endif
const u8 gText_MenuPlayer[] = _("{PLAYER}");
#if GERMAN
const u8 gText_MenuSave[] = _("Sichern");
#else
const u8 gText_MenuSave[] = _("SAVE");
#endif
#if GERMAN
const u8 gText_MenuOption[] = _("Option.");
#else
const u8 gText_MenuOption[] = _("OPTION");
#endif
#if GERMAN
const u8 gText_MenuExit[] = _("Beenden");
#else
const u8 gText_MenuExit[] = _("EXIT");
#endif
#if GERMAN
const u8 gText_MenuRetire[] = _("Schluss");
#else
const u8 gText_MenuRetire[] = _("RETIRE");
#endif
#if GERMAN
const u8 gText_MenuRest[] = _("Ausruhen");
#else
const u8 gText_MenuRest[] = _("REST");
#endif
#if GERMAN
const u8 gText_MenuDexNav[] = _("Dexnav");
#else
const u8 gText_MenuDexNav[] = _("DEXNAV");
#endif
#if GERMAN
const u8 gText_SafariBallStock[] = _("Safaribälle\nVorrat: {STR_VAR_1}");
#else
const u8 gText_SafariBallStock[] = _("SAFARI BALLS\nStock: {STR_VAR_1}");
#endif
#if GERMAN
const u8 gText_MenuSafariStats[] = _("{STR_VAR_1}/{STR_VAR_2}\nBälle  {STR_VAR_3}");
#else
const u8 gText_MenuSafariStats[] = _("{STR_VAR_1}/{STR_VAR_2}\nBALLS  {STR_VAR_3}");
#endif
#if GERMAN
const u8 gText_BattlePyramidFloor[] = _("Kampfpyramide\n{STR_VAR_1}");
#else
const u8 gText_BattlePyramidFloor[] = _("Battle Pyramid\n{STR_VAR_1}");
#endif
#if GERMAN
const u8 gText_Floor1[] = _("Erdgeschoss");
#else
const u8 gText_Floor1[] = _("Floor 1");
#endif
#if GERMAN
const u8 gText_Floor2[] = _("Ebene 2");
#else
const u8 gText_Floor2[] = _("Floor 2");
#endif
#if GERMAN
const u8 gText_Floor3[] = _("Ebene 3");
#else
const u8 gText_Floor3[] = _("Floor 3");
#endif
#if GERMAN
const u8 gText_Floor4[] = _("Ebene 4");
#else
const u8 gText_Floor4[] = _("Floor 4");
#endif
#if GERMAN
const u8 gText_Floor5[] = _("Ebene 5");
#else
const u8 gText_Floor5[] = _("Floor 5");
#endif
#if GERMAN
const u8 gText_Floor6[] = _("Ebene 6");
#else
const u8 gText_Floor6[] = _("Floor 6");
#endif
#if GERMAN
const u8 gText_Floor7[] = _("Ebene 7");
#else
const u8 gText_Floor7[] = _("Floor 7");
#endif
#if GERMAN
const u8 gText_Peak[] = _("Spitze");
#else
const u8 gText_Peak[] = _("Peak");
#endif
#if GERMAN
const u8 gText_LinkStandby2[] = _("Verbindung…\n… … B-Knopf: Abbrechen");
#else
const u8 gText_LinkStandby2[] = _("Link standby…\n… … B Button: Cancel");
#endif
#if GERMAN
const u8 gText_PressAToLoadEvent[] = _("Lade Geschehen mit A-Knopf.\n… … B-Knopf: Abbrechen");
#else
const u8 gText_PressAToLoadEvent[] = _("Press the A Button to load event.\n… … B Button: Cancel");
#endif
#if GERMAN
const u8 gText_LoadingEvent[] = _("Geschehen wird geladen.");
#else
const u8 gText_LoadingEvent[] = _("Loading event…");
#endif
#if GERMAN
const u8 gText_DontRemoveCableTurnOff[] = _("Verbindungskabel nicht entfernen!\nDie Geräte nicht ausschalten!");
#else
const u8 gText_DontRemoveCableTurnOff[] = _("Don't remove the Game Link cable.\nDon't turn off the power.");
#endif
#if GERMAN
const u8 gText_EventSafelyLoaded[] = _("Geschehen ist erfolgreich geladen.");
#else
const u8 gText_EventSafelyLoaded[] = _("The event was safely loaded.");
#endif
#if GERMAN
const u8 gText_LoadErrorEndingSession[] = _("Fehler beim Laden!\nVorgang wird abgebrochen.");
#else
const u8 gText_LoadErrorEndingSession[] = _("Loading error.\nEnding session.");
#endif
const u8 gJPText_Player[] = _("プレイヤー"); // Unused
const u8 gJPText_Sama[] = _("さま"); // Unused
#if GERMAN
const u8 gText_DexHoenn[] = _("Hoenn");
#else
const u8 gText_DexHoenn[] = _("HOENN");
#endif
#if GERMAN
const u8 gText_DexNational[] = _("Nationaler");
#else
const u8 gText_DexNational[] = _("NATIONAL");
#endif
#if GERMAN
const u8 gText_PokedexDiploma[] = _("Spieler: {CLEAR 0x10}{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\n\n{STR_VAR_1} Pokédex\nDieses Dokument bescheinigt\ndie erfolgreiche Vervoll-\nständigung des Pokédex.\n\n{CLEAR_TO 0x42}{COLOR RED}{SHADOW LIGHT_RED}Game Freak");
#else
const u8 gText_PokedexDiploma[] = _("PLAYER: {CLEAR 0x10}{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\n\nThis document certifies\nthat you have successfully\ncompleted your\n{STR_VAR_1} POKéDEX.\n\n{CLEAR_TO 0x42}{COLOR RED}{SHADOW LIGHT_RED}GAME FREAK");
#endif
const u8 gJPText_GameFreak[] = _("{COLOR RED}{SHADOW LIGHT_RED}ゲ-ムフリ-ク"); // Unused
const u8 gText_DiplomaEmpty[] = _("{COLOR RED}{SHADOW LIGHT_RED}"); // Unused
#if GERMAN
const u8 gText_Hoenn[] = _("Hoenn");
#else
const u8 gText_Hoenn[] = _("HOENN");
#endif
#if GERMAN
const u8 gText_Kanto[] = _("Kanto");
#else
const u8 gText_Kanto[] = _("KANTO");
#endif
#if GERMAN
const u8 gText_Johto[] = _("Johto");
#else
const u8 gText_Johto[] = _("JOHTO");
#endif
#if GERMAN
const u8 gText_JohtoKanto[] = _("Johto & Kanto");
#else
const u8 gText_JohtoKanto[] = _("JOHTO & KANTO");
#endif
#if GERMAN
const u8 gText_XWillBeSentToY[] = _("{STR_VAR_2} wird\n{STR_VAR_1} zugesandt.");
#else
const u8 gText_XWillBeSentToY[] = _("{STR_VAR_2} will be\nsent to {STR_VAR_1}.");
#endif
#if GERMAN
const u8 gText_ByeByeVar1[] = _("Tschüss, {STR_VAR_2}!");
#else
const u8 gText_ByeByeVar1[] = _("Bye-bye, {STR_VAR_2}!");
#endif
#if GERMAN
const u8 gText_XSentOverY[] = _("{STR_VAR_1} versandte {STR_VAR_3}.");
#else
const u8 gText_XSentOverY[] = _("{STR_VAR_1} sent over {STR_VAR_3}.");
#endif
#if GERMAN
const u8 gText_TakeGoodCareOfX[] = _("Kümmere dich gut um {STR_VAR_3}!");
#else
const u8 gText_TakeGoodCareOfX[] = _("Take good care of {STR_VAR_3}!");
#endif

const u8 gText_ThreeQuestionMarks[] = _("???");
const u8 gText_FourQuestionMarks[] = _("????");
#if GERMAN
const u8 gText_MaxHP[] = _("Max. KP");
#else
const u8 gText_MaxHP[] = _("MAX. HP");
#endif
#if GERMAN
const u8 gText_Attack[] = _("Angriff");
#else
const u8 gText_Attack[] = _("ATTACK");
#endif
#if GERMAN
const u8 gText_Defense[] = _("Vert.");
#else
const u8 gText_Defense[] = _("DEFENSE");
#endif
#if GERMAN
const u8 gText_Speed[] = _("Init.");
#else
const u8 gText_Speed[] = _("SPEED");
#endif
#if GERMAN
const u8 gText_SpAtk[] = _("Sp. Ang.");
#else
const u8 gText_SpAtk[] = _("SP. ATK");
#endif
#if GERMAN
const u8 gText_SpDef[] = _("Sp. Ver.");
#else
const u8 gText_SpDef[] = _("SP. DEF");
#endif
const u8 gText_Plus[] = _("{PLUS}");
const u8 gText_Dash[] = _("-");
#if GERMAN
const u8 gText_MixingRecords[] = _("Rekorddaten-Austausch…");
#else
const u8 gText_MixingRecords[] = _("Mixing records…");
#endif
#if GERMAN
const u8 gText_RecordMixingComplete[] = _("Rekorddaten-Austausch beendet.\nVielen Dank für deine Geduld.");
#else
const u8 gText_RecordMixingComplete[] = _("Record mixing completed.\nThank you for waiting.");
#endif
#if GERMAN
const u8 gText_RentalPkmn2[] = _("Leih-Pokémon");
#else
const u8 gText_RentalPkmn2[] = _("RENTAL POKéMON");
#endif
#if GERMAN
const u8 gText_SelectFirstPkmn[] = _("Wähle das erste Pokémon!");
#else
const u8 gText_SelectFirstPkmn[] = _("Select the first POKéMON.");
#endif
#if GERMAN
const u8 gText_SelectSecondPkmn[] = _("Wähle das zweite Pokémon!");
#else
const u8 gText_SelectSecondPkmn[] = _("Select the second POKéMON.");
#endif
#if GERMAN
const u8 gText_SelectThirdPkmn[] = _("Wähle das dritte Pokémon!");
#else
const u8 gText_SelectThirdPkmn[] = _("Select the third POKéMON.");
#endif
#if GERMAN
const u8 gText_Rent[] = _("Verleih");
#else
const u8 gText_Rent[] = _("RENT");
#endif
#if GERMAN
const u8 gText_Summary[] = _("Bericht");
#else
const u8 gText_Summary[] = _("SUMMARY");
#endif
#if GERMAN
const u8 gText_Others2[] = _("Andere");
#else
const u8 gText_Others2[] = _("OTHERS");
#endif
#if GERMAN
const u8 gText_Deselect[] = _("Entfernen");
#else
const u8 gText_Deselect[] = _("DESELECT");
#endif
#if GERMAN
const u8 gText_TheseThreePkmnOkay[] = _("Diese drei Pkmn auswählen?");
#else
const u8 gText_TheseThreePkmnOkay[] = _("Are these three POKéMON OK?");
#endif
#if GERMAN
const u8 gText_Yes2[] = _("Ja");
#else
const u8 gText_Yes2[] = _("YES");
#endif
#if GERMAN
const u8 gText_No2[] = _("Nein");
#else
const u8 gText_No2[] = _("NO");
#endif
#if GERMAN
const u8 gText_CantSelectSamePkmn[] = _("Wahl desselben {PKMN} unmögl.");
#else
const u8 gText_CantSelectSamePkmn[] = _("Can't select same {PKMN}.");
#endif
#if GERMAN
const u8 gText_PkmnSwap[] = _("Pokémon-Wechsel");
#else
const u8 gText_PkmnSwap[] = _("POKéMON SWAP");
#endif
#if GERMAN
const u8 gText_SelectPkmnToSwap[] = _("Wähle das zu wechselnde {PKMN}.");
#else
const u8 gText_SelectPkmnToSwap[] = _("Select POKéMON to swap.");
#endif
#if GERMAN
const u8 gText_SelectPkmnToAccept[] = _("Bestätige das gewählte {PKMN}.");
#else
const u8 gText_SelectPkmnToAccept[] = _("Select POKéMON to accept.");
#endif
#if GERMAN
const u8 gText_Swap[] = _("Wechsel");
#else
const u8 gText_Swap[] = _("SWAP");
#endif
#if GERMAN
const u8 gText_Summary2[] = _("Bericht");
#else
const u8 gText_Summary2[] = _("SUMMARY");
#endif
#if GERMAN
const u8 gText_Rechoose[] = _("Neuwahl");
#else
const u8 gText_Rechoose[] = _("RECHOOSE");
#endif
#if GERMAN
const u8 gText_QuitSwapping[] = _("Wechseln beenden?");
#else
const u8 gText_QuitSwapping[] = _("Quit swapping?");
#endif
#if GERMAN
const u8 gText_Yes3[] = _("Ja");
#else
const u8 gText_Yes3[] = _("YES");
#endif
#if GERMAN
const u8 gText_No3[] = _("Nein");
#else
const u8 gText_No3[] = _("NO");
#endif
#if GERMAN
const u8 gText_PkmnForSwap[] = _("Wechselpkmn");
#else
const u8 gText_PkmnForSwap[] = _("{PKMN} FOR SWAP");
#endif
#if GERMAN
const u8 gText_Cancel3[] = _("Abbruch");
#else
const u8 gText_Cancel3[] = _("CANCEL");
#endif
#if GERMAN
const u8 gText_Swap2[] = _("Swap");
#else
const u8 gText_Swap2[] = _("SWAP");
#endif // Unused
#if GERMAN
const u8 gText_Accept[] = _("Accept");
#else
const u8 gText_Accept[] = _("ACCEPT");
#endif // Unused
#if GERMAN
const u8 gText_AcceptThisPkmn[] = _("Dieses {PKMN} annehmen?");
#else
const u8 gText_AcceptThisPkmn[] = _("Accept this POKéMON?");
#endif
const u8 gText_4Spaces[] = _("    "); // Unused
#if GERMAN
const u8 gText_SamePkmnInPartyAlready[] = _("Selbes {PKMN} bereits im Team.");
#else
const u8 gText_SamePkmnInPartyAlready[] = _("Same {PKMN} in party already.");
#endif
const u8 gText_DecimalPoint[] = _(".");
#if GERMAN
const u8 gText_SavingPlayer[] = _("Spieler");
#else
const u8 gText_SavingPlayer[] = _("PLAYER");
#endif
#if GERMAN
const u8 gText_SavingBadges[] = _("Orden");
#else
const u8 gText_SavingBadges[] = _("BADGES");
#endif
#if GERMAN
const u8 gText_SavingPokedex[] = _("Pokédex");
#else
const u8 gText_SavingPokedex[] = _("POKéDEX");
#endif
#if GERMAN
const u8 gText_SavingTime[] = _("Spielzeit");
#else
const u8 gText_SavingTime[] = _("TIME");
#endif
#if GERMAN
const u8 gText_WirelessCommStatus[] = _("Drahtlose Verbindungen:");
#else
const u8 gText_WirelessCommStatus[] = _("Wireless Communication Status");
#endif
#if GERMAN
const u8 gText_PeopleTrading[] = _("Tauscher:");
#else
const u8 gText_PeopleTrading[] = _("People trading:");
#endif
#if GERMAN
const u8 gText_PeopleBattling[] = _("Kämpfer:");
#else
const u8 gText_PeopleBattling[] = _("People battling:");
#endif
#if GERMAN
const u8 gText_PeopleInUnionRoom[] = _("Begegnungen im Konnex-Klub:");
#else
const u8 gText_PeopleInUnionRoom[] = _("People in the UNION ROOM:");
#endif
#if GERMAN
const u8 gText_PeopleCommunicating[] = _("Eingegangene Verbindungen:");
#else
const u8 gText_PeopleCommunicating[] = _("People communicating:");
#endif
#if GERMAN
const u8 gText_F700Players[] = _("{DYNAMIC 0} Spieler");
#else
const u8 gText_F700Players[] = _("{DYNAMIC 0} players");
#endif
#if GERMAN
const u8 gText_F701Players[] = _("{DYNAMIC 1} Spieler");
#else
const u8 gText_F701Players[] = _("{DYNAMIC 1} players");
#endif
#if GERMAN
const u8 gText_F702Players[] = _("{DYNAMIC 2} Spieler");
#else
const u8 gText_F702Players[] = _("{DYNAMIC 2} players");
#endif
#if GERMAN
const u8 gText_F703Players[] = _("{DYNAMIC 3} Spieler");
#else
const u8 gText_F703Players[] = _("{DYNAMIC 3} players");
#endif

const u8 *const gTextTable_Players[] = {
    gText_F700Players,
    gText_F701Players,
    gText_F702Players,
    gText_F703Players
};

#if GERMAN
ALIGNED(4) const u8 gText_WonderCards[] = _("Wunderkarten");
#else
ALIGNED(4) const u8 gText_WonderCards[] = _("WONDER CARDS");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WonderNews[] = _("Wundernews");
#else
ALIGNED(4) const u8 gText_WonderNews[] = _("WONDER NEWS");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WirelessCommunication[] = _("Drahtlose Verbindungen");
#else
ALIGNED(4) const u8 gText_WirelessCommunication[] = _("WIRELESS COMMUNICATION");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_Friend2[] = _("Freund");
#else
ALIGNED(4) const u8 gText_Friend2[] = _("FRIEND");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_Exit3[] = _("Zurück");
#else
ALIGNED(4) const u8 gText_Exit3[] = _("EXIT");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_Receive[] = _("Erhalten");
#else
ALIGNED(4) const u8 gText_Receive[] = _("RECEIVE");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_Send[] = _("Senden");
#else
ALIGNED(4) const u8 gText_Send[] = _("SEND");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_Toss[] = _("Müll");
#else
ALIGNED(4) const u8 gText_Toss[] = _("TOSS");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_VarietyOfEventsImportedWireless[] = _("Einige Geschehen werden über die\nDrahtlose Verbindung importiert.");
#else
ALIGNED(4) const u8 gText_VarietyOfEventsImportedWireless[] = _("A variety of events will be imported\nover Wireless Communication.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WonderCardsInPossession[] = _("Lies die Wunderkarten in\ndeinem Besitz.");
#else
ALIGNED(4) const u8 gText_WonderCardsInPossession[] = _("Read the WONDER CARDS in your\npossession.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_ReadNewsThatArrived[] = _("Lies die News!");
#else
ALIGNED(4) const u8 gText_ReadNewsThatArrived[] = _("Read the NEWS that arrived.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_ReturnToTitle[] = _("Zurück zum Titelbildschirm.");
#else
ALIGNED(4) const u8 gText_ReturnToTitle[] = _("Return to the title screen.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_DontHaveCardNewOneInput[] = _("Du hast keine Wunderkarte,\nalso wird eine neue Karte angelegt.");
#else
ALIGNED(4) const u8 gText_DontHaveCardNewOneInput[] = _("You don't have a WONDER CARD,\nso a new CARD will be input.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_DontHaveNewsNewOneInput[] = _("Du hast keine Wundernews,\nalso werden neue News angelegt.");
#else
ALIGNED(4) const u8 gText_DontHaveNewsNewOneInput[] = _("You don't have any WONDER NEWS,\nso new NEWS will be input.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WhereShouldCardBeAccessed[] = _("Wo soll auf die Wunderkarte\nzugegriffen werden?");
#else
ALIGNED(4) const u8 gText_WhereShouldCardBeAccessed[] = _("Where should the WONDER CARD\nbe accessed?");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WhereShouldNewsBeAccessed[] = _("Wo soll auf die Wundernews\nzugegriffen werden?");
#else
ALIGNED(4) const u8 gText_WhereShouldNewsBeAccessed[] = _("Where should the WONDER NEWS\nbe accessed?");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_CommunicationStandbyBButtonCancel[] = _("Verbindung…\n… … B-Knopf: Abbrechen");
#else
ALIGNED(4) const u8 gText_CommunicationStandbyBButtonCancel[] = _("Communication standby…\nB Button: Cancel");
#endif // Unused
#if GERMAN
ALIGNED(4) const u8 gText_Communicating[] = _("Übertragung… ");
#else
ALIGNED(4) const u8 gText_Communicating[] = _("Communicating…");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_CommunicationCompleted[] = _("Verbindung vollständig.");
#else
ALIGNED(4) const u8 gText_CommunicationCompleted[] = _("Communication completed.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_CommunicationError[] = _("Übertragungsfehler.");
#else
ALIGNED(4) const u8 gText_CommunicationError[] = _("Communication error.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_CommunicationCanceled[] = _("Die Verbindung wurde abgebrochen.");
#else
ALIGNED(4) const u8 gText_CommunicationCanceled[] = _("Communication has been canceled.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_ThrowAwayWonderCard[] = _("Soll die Wunderkarte weggeworfen\nund die neue Karte benutzt werden?");
#else
ALIGNED(4) const u8 gText_ThrowAwayWonderCard[] = _("Throw away the WONDER CARD\nand input a new CARD?");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_HaventReceivedCardsGift[] = _("Geschenk dieser Karte noch nicht\nerhalten! Neue Karte benutzen?");
#else
ALIGNED(4) const u8 gText_HaventReceivedCardsGift[] = _("You haven't received the CARD's gift\nyet. Input a new CARD anyway?");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WonderCardReceivedFrom[] = _("Eine Wunderkarte von {STR_VAR_1}\nerhalten.");
#else
ALIGNED(4) const u8 gText_WonderCardReceivedFrom[] = _("A WONDER CARD has been received\nfrom {STR_VAR_1}.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WonderNewsReceivedFrom[] = _("Ein Wundernews-Item von {STR_VAR_1}\nerhalten.");
#else
ALIGNED(4) const u8 gText_WonderNewsReceivedFrom[] = _("A WONDER NEWS item has been\nreceived from {STR_VAR_1}.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WonderCardReceived[] = _("Eine neue Wunderkarte erhalten.");
#else
ALIGNED(4) const u8 gText_WonderCardReceived[] = _("A new WONDER CARD has been\nreceived.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WonderNewsReceived[] = _("Ein neues Wundernews-Item erhalten.");
#else
ALIGNED(4) const u8 gText_WonderNewsReceived[] = _("A new WONDER NEWS item has been\nreceived.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_NewStampReceived[] = _("Einen neuen Stempel erhalten.");
#else
ALIGNED(4) const u8 gText_NewStampReceived[] = _("A new STAMP has been received.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_NewTrainerReceived[] = _("Ein neuer Trainer ist eingetroffen.");
#else
ALIGNED(4) const u8 gText_NewTrainerReceived[] = _("A new TRAINER has arrived.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_AlreadyHadCard[] = _("Diese Wunderkarte hattest\ndu bereits!");
#else
ALIGNED(4) const u8 gText_AlreadyHadCard[] = _("You already had that\nWONDER CARD.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_AlreadyHadNews[] = _("Dieses Wundernews-Item\nhattest du bereits.");
#else
ALIGNED(4) const u8 gText_AlreadyHadNews[] = _("You already had that\nWONDER NEWS item.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_AlreadyHadStamp[] = _("Diesen Stempel hattest\ndu bereits.");
#else
ALIGNED(4) const u8 gText_AlreadyHadStamp[] = _("You already had that\nSTAMP.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_NoMoreRoomForStamps[] = _("Es gibt keinen Platz mehr, um\nStempel hinzuzufügen.");
#else
ALIGNED(4) const u8 gText_NoMoreRoomForStamps[] = _("There's no more room for adding\nSTAMPS.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_RecordUploadedViaWireless[] = _("Dein Rekord wurde Drahtlos\nübertragen.");
#else
ALIGNED(4) const u8 gText_RecordUploadedViaWireless[] = _("Your record has been uploaded via\nWIRELESS COMMUNICATION.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_CantAcceptCardFromTrainer[] = _("Du kannst von diesem Trainer\nkeine Wunderkarte annehmen.");
#else
ALIGNED(4) const u8 gText_CantAcceptCardFromTrainer[] = _("You can't accept a WONDER CARD\nfrom this TRAINER.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_CantAcceptNewsFromTrainer[] = _("Du kannst von diesem Trainer\nkeine Wundernews annehmen.");
#else
ALIGNED(4) const u8 gText_CantAcceptNewsFromTrainer[] = _("You can't accept WONDER NEWS\nfrom this TRAINER.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_NothingSentOver[] = _("Es wurde nichts übertragen…");
#else
ALIGNED(4) const u8 gText_NothingSentOver[] = _("Nothing was sent over…");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WhatToDoWithCards[] = _("Was möchtest du mit den\nWunderkarten anstellen?");
#else
ALIGNED(4) const u8 gText_WhatToDoWithCards[] = _("What would you like to do\nwith the WONDER CARDS?");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WhatToDoWithNews[] = _("Was möchtest du mit den\nWundernews anstellen?");
#else
ALIGNED(4) const u8 gText_WhatToDoWithNews[] = _("What would you like to do\nwith the WONDER NEWS?");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_SendingWonderCard[] = _("Wunderkarte wird übertragen…");
#else
ALIGNED(4) const u8 gText_SendingWonderCard[] = _("Sending your WONDER CARD…");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_SendingWonderNews[] = _("Wundernews werden übertragen…");
#else
ALIGNED(4) const u8 gText_SendingWonderNews[] = _("Sending your WONDER NEWS item…");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WonderCardSentTo[] = _("Deine Wunderkarte wurde zu\n{STR_VAR_1} übertragen.");
#else
ALIGNED(4) const u8 gText_WonderCardSentTo[] = _("Your WONDER CARD has been sent\nto {STR_VAR_1}.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WonderNewsSentTo[] = _("Deine Wundernews wurden zu\n{STR_VAR_1} übertragen.");
#else
ALIGNED(4) const u8 gText_WonderNewsSentTo[] = _("Your WONDER NEWS item has been\nsent to {STR_VAR_1}.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_StampSentTo[] = _("{STR_VAR_1} erhält einen Stempel.");
#else
ALIGNED(4) const u8 gText_StampSentTo[] = _("A STAMP has been sent to {STR_VAR_1}.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_GiftSentTo[] = _("{STR_VAR_1} erhält Geschehen.");
#else
ALIGNED(4) const u8 gText_GiftSentTo[] = _("A GIFT has been sent to {STR_VAR_1}.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_OtherTrainerHasCard[] = _("Der andere Trainer hat diese\nWunderkarte bereits.");
#else
ALIGNED(4) const u8 gText_OtherTrainerHasCard[] = _("The other TRAINER has the same\nWONDER CARD already.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_OtherTrainerHasNews[] = _("Der andere Trainer hat diese\nWundernews bereits.");
#else
ALIGNED(4) const u8 gText_OtherTrainerHasNews[] = _("The other TRAINER has the same\nWONDER NEWS already.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_OtherTrainerHasStamp[] = _("Der andere Trainer hat diesen\nStempel bereits.");
#else
ALIGNED(4) const u8 gText_OtherTrainerHasStamp[] = _("The other TRAINER has the same\nSTAMP already.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_OtherTrainerCanceled[] = _("Der andere Trainer hat die\nVerbindung abgebrochen.");
#else
ALIGNED(4) const u8 gText_OtherTrainerCanceled[] = _("The other TRAINER canceled\ncommunication.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_CantSendGiftToTrainer[] = _("Du kannst diesem Trainer kein\nGeheimgeschehen übertragen.");
#else
ALIGNED(4) const u8 gText_CantSendGiftToTrainer[] = _("You can't send a MYSTERY GIFT to\nthis TRAINER.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_IfThrowAwayCardEventWontHappen[] = _("Wenn du die Karte weg-\nwirfst, passiert nichts! O.K.?");
#else
ALIGNED(4) const u8 gText_IfThrowAwayCardEventWontHappen[] = _("If you throw away the CARD,\nits event won't happen. Okay?");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_OkayToDiscardNews[] = _("Soll dieses News-Item weg-\ngeworfen werden?");
#else
ALIGNED(4) const u8 gText_OkayToDiscardNews[] = _("Is it okay to discard this\nNEWS item?");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_HaventReceivedGiftOkayToDiscard[] = _("Kein Geheimgeschehen!\nTrotzdem wegwerfen?");
#else
ALIGNED(4) const u8 gText_HaventReceivedGiftOkayToDiscard[] = _("You haven't received the\nGIFT. Is it okay to discard?");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_DataWillBeSaved[] = _("Daten werden gesichert.\nBitte warten…");
#else
ALIGNED(4) const u8 gText_DataWillBeSaved[] = _("Data will be saved.\nPlease wait.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_SaveCompletedPressA[] = _("Speichern beendet.\nBitte A-Knopf drücken.");
#else
ALIGNED(4) const u8 gText_SaveCompletedPressA[] = _("Save completed.\nPlease press the A Button.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WonderCardThrownAway[] = _("Wunderkarte weggeworfen!");
#else
ALIGNED(4) const u8 gText_WonderCardThrownAway[] = _("The WONDER CARD was thrown away.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_WonderNewsThrownAway[] = _("Wundernews weggeworfen!");
#else
ALIGNED(4) const u8 gText_WonderNewsThrownAway[] = _("The WONDER NEWS was thrown away.");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_MysteryGift[] = _("Geheimgeschehen");
#else
ALIGNED(4) const u8 gText_MysteryGift[] = _("MYSTERY GIFT");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_PickOKExit[] = _("{DPAD_UPDOWN}Wahl {A_BUTTON}O.K. {B_BUTTON}Beenden");
#else
ALIGNED(4) const u8 gText_PickOKExit[] = _("{DPAD_UPDOWN}PICK {A_BUTTON}OK {B_BUTTON}EXIT");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_PickOKCancel[] = _("{DPAD_UPDOWN}Wahl {A_BUTTON}O.K. {B_BUTTON}Zurück");
#else
ALIGNED(4) const u8 gText_PickOKCancel[] = _("{DPAD_UPDOWN}PICK {A_BUTTON}OK {B_BUTTON}CANCEL");
#endif
#if GERMAN
const u8 gText_PlayersBattleResults[] = _("Kampfergebnisse von {PLAYER}");
#else
const u8 gText_PlayersBattleResults[] = _("{PLAYER}'s BATTLE RESULTS");
#endif
#if GERMAN
const u8 gText_TotalRecordWLD[] = _("Gesamt-Rekord S.:{STR_VAR_1} N.:{STR_VAR_2} P.:{STR_VAR_3}");
#else
const u8 gText_TotalRecordWLD[] = _("TOTAL RECORD W:{STR_VAR_1} L:{STR_VAR_2} D:{STR_VAR_3}");
#endif
#if GERMAN
const u8 gText_WinLoseDraw[] = _("{CLEAR_TO 0x50}Sieg{CLEAR_TO 0x79}Nieder.{CLEAR_TO 0xB0}Patt");
#else
const u8 gText_WinLoseDraw[] = _("{CLEAR_TO 0x53}WIN{CLEAR_TO 0x80}LOSE{CLEAR_TO 0xB0}DRAW");
#endif
#if GERMAN
const u8 gText_CommunicationStandby5[] = _("Verbindung…");
#else
const u8 gText_CommunicationStandby5[] = _("Communication standby…");
#endif
#if GERMAN
const u8 gDaycareText_GetAlongVeryWell[] = _("Die beiden scheinen sich sehr zu\nmögen.");
#else
const u8 gDaycareText_GetAlongVeryWell[] = _("The two seem to get along\nvery well.");
#endif
#if GERMAN
const u8 gDaycareText_GetAlong[] = _("Die beiden scheinen sich zu\nvertragen.");
#else
const u8 gDaycareText_GetAlong[] = _("The two seem to get along.");
#endif
#if GERMAN
const u8 gDaycareText_DontLikeOther[] = _("Die beiden mögen sich nicht sehr.");
#else
const u8 gDaycareText_DontLikeOther[] = _("The two don't seem to like\neach other much.");
#endif
#if GERMAN
const u8 gDaycareText_PlayOther[] = _("Die beiden spielen lieber mit\nanderen Pokémon als miteinander.");
#else
const u8 gDaycareText_PlayOther[] = _("The two prefer to play with other\nPOKéMON than each other.");
#endif
const u8 gText_NewLine2[] = _("\n");
#if GERMAN
const u8 gText_Exit4[] = _("Keines");
#else
const u8 gText_Exit4[] = _("EXIT");
#endif
const u8 gText_Lv[] = _("{LV}");
#if GERMAN
const u8 gText_TimeBoard[] = _("Zeittafel");
#else
const u8 gText_TimeBoard[] = _("TIME BOARD");
#endif
#if GERMAN
const u8 gText_TimeCleared[] = _("Benötigte Zeit ");
#else
const u8 gText_TimeCleared[] = _("TIME CLEARED ");
#endif
#if GERMAN
const u8 gText_XMinYDotZSec[] = _("{STR_VAR_1} Min. {STR_VAR_2},{STR_VAR_3} Sek.");
#else
const u8 gText_XMinYDotZSec[] = _("{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.");
#endif
#if GERMAN
const u8 gText_TrainerHill1F[] = _("EG");
#else
const u8 gText_TrainerHill1F[] = _("1F");
#endif
#if GERMAN
const u8 gText_TrainerHill2F[] = _("1S");
#else
const u8 gText_TrainerHill2F[] = _("2F");
#endif
#if GERMAN
const u8 gText_TrainerHill3F[] = _("2S");
#else
const u8 gText_TrainerHill3F[] = _("3F");
#endif
#if GERMAN
const u8 gText_TrainerHill4F[] = _("3S");
#else
const u8 gText_TrainerHill4F[] = _("4F");
#endif
#if GERMAN
const u8 gText_TeachWhichMoveToPkmn[] = _("{STR_VAR_1} welche Att. beibr.?");
#else
const u8 gText_TeachWhichMoveToPkmn[] = _("Teach which {STR_VAR_3} to\n{STR_VAR_1}?");
#endif
#if GERMAN
const u8 gText_MoveRelearnerTeachMoveConfirm[] = _("{STR_VAR_2} beibringen?");
#else
const u8 gText_MoveRelearnerTeachMoveConfirm[] = _("Teach {STR_VAR_2}?");
#endif
#if GERMAN
const u8 gText_MoveRelearnerPkmnLearnedMove[] = _("{STR_VAR_1} lernte\n{STR_VAR_2}.");
#else
const u8 gText_MoveRelearnerPkmnLearnedMove[] = _("{STR_VAR_1} learned\n{STR_VAR_2}!");
#endif
#if GERMAN
const u8 gText_MoveRelearnerPkmnTryingToLearnMove[] = _("{STR_VAR_1} versucht,\n{STR_VAR_2} zu erlernen.\pAber {STR_VAR_1} kann nicht mehr\nals vier Attacken erlernen.\pSoll eine Attacke zu Gunsten von\n{STR_VAR_2} vergessen werden?");
#else
const u8 gText_MoveRelearnerPkmnTryingToLearnMove[] = _("{STR_VAR_1} is trying to learn\n{STR_VAR_2}.\pBut {STR_VAR_1} can't learn more\nthan four moves.\pDelete an older move to make\nroom for {STR_VAR_2}?");
#endif
#if GERMAN
const u8 gText_MoveRelearnerStopTryingToTeachMove[] = _("{STR_VAR_2} nicht erlernen?");
#else
const u8 gText_MoveRelearnerStopTryingToTeachMove[] = _("Stop trying to teach\n{STR_VAR_2}?");
#endif
#if GERMAN
const u8 gText_MoveRelearnerAndPoof[] = _("{PAUSE 32}1, {PAUSE 15}2 {PAUSE 15}…{PAUSE 15}…{PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Schwupp!\p");
#else
const u8 gText_MoveRelearnerAndPoof[] = _("{PAUSE 32}1, {PAUSE 15}2, and {PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Poof!\p");
#endif
#if GERMAN
const u8 gText_MoveRelearnerPkmnForgotMoveAndLearnedNew[] = _("{STR_VAR_1} vergaß\n{STR_VAR_3}.\pUnd…\p{STR_VAR_1} lernt {STR_VAR_2}.");
#else
const u8 gText_MoveRelearnerPkmnForgotMoveAndLearnedNew[] = _("{STR_VAR_1} forgot {STR_VAR_3}.\pAnd…\p{STR_VAR_1} learned {STR_VAR_2}.");
#endif
#if GERMAN
const u8 gText_MoveRelearnedPkmnDidNotLearnMove[] = _("{STR_VAR_1} hat die Attacke\n{STR_VAR_2} nicht erlernt.");
#else
const u8 gText_MoveRelearnedPkmnDidNotLearnMove[] = _("{STR_VAR_1} did not learn the\nmove {STR_VAR_2}.");
#endif // Unused
#if GERMAN
const u8 gText_MoveRelearnerGiveUp[] = _("Soll {STR_VAR_1} keine neue\nAttacke erlernen?");
#else
const u8 gText_MoveRelearnerGiveUp[] = _("Give up trying to teach a new\nmove to {STR_VAR_1}?");
#endif
#if GERMAN
const u8 gText_MoveRelearnerWhichMoveToForget[] = _("Welche Attacke soll vergessen\nwerden?\p");
#else
const u8 gText_MoveRelearnerWhichMoveToForget[] = _("Which move should be\nforgotten?\p");
#endif
#if GERMAN
const u8 gText_MoveRelearnerBattleMoves[] = _("Attacken");
#else
const u8 gText_MoveRelearnerBattleMoves[] = _("BATTLE MOVES");
#endif
#if GERMAN
const u8 gText_MoveRelearnerContestMovesTitle[] = _("Wett.-Attacken");
#else
const u8 gText_MoveRelearnerContestMovesTitle[] = _("CONTEST MOVES");
#endif
#if GERMAN
const u8 gText_MoveRelearnerType[] = _("Type/");
#else
const u8 gText_MoveRelearnerType[] = _("TYPE/");
#endif // Unused
#if GERMAN
const u8 gText_MoveRelearnerPP[] = _("AP/");
#else
const u8 gText_MoveRelearnerPP[] = _("PP/");
#endif
#if GERMAN
const u8 gText_MoveRelearnerPower[] = _("Stärke/");
#else
const u8 gText_MoveRelearnerPower[] = _("POWER/");
#endif
#if GERMAN
const u8 gText_MoveRelearnerAccuracy[] = _("Genau./");
#else
const u8 gText_MoveRelearnerAccuracy[] = _("ACCURACY/");
#endif
#if GERMAN
const u8 gText_MoveRelearnerAppeal[] = _("Ausdruck");
#else
const u8 gText_MoveRelearnerAppeal[] = _("APPEAL");
#endif
#if GERMAN
const u8 gText_MoveRelearnerJam[] = _("Eindruck");
#else
const u8 gText_MoveRelearnerJam[] = _("JAM");
#endif
#if GERMAN
const u8 gText_ClearAllSaveData[] = _("Alle gesich. Datenber. löschen?");
#else
const u8 gText_ClearAllSaveData[] = _("Clear all save data areas?");
#endif
#if GERMAN
const u8 gText_ClearingData[] = _("Daten werden gelöscht…\nBitte warten…");
#else
const u8 gText_ClearingData[] = _("Clearing data…\nPlease wait.");
#endif
#if GERMAN
const u8 gText_IsThisTheCorrectTime[] = _("Ist die Uhrzeit korrekt?");
#else
const u8 gText_IsThisTheCorrectTime[] = _("Is this the correct time?");
#endif
#if GERMAN
const u8 gText_Confirm3[] = _("O.K.");
#else
const u8 gText_Confirm3[] = _("CONFIRM");
#endif
#if GERMAN
const u8 gText_Cancel4[] = _("Zurück");
#else
const u8 gText_Cancel4[] = _("CANCEL");
#endif
#if GERMAN
const u8 gText_CommStandbyAwaitingOtherPlayer[] = _("Verbindungsaufbau…\nMitspieler wird erwartet.");
#else
const u8 gText_CommStandbyAwaitingOtherPlayer[] = _("Communication standby…\nAwaiting another player to choose.");
#endif
#if GERMAN
const u8 gText_BattleWasRefused[] = _("Der Kampf wurde abgesagt.{PAUSE 60}");
#else
const u8 gText_BattleWasRefused[] = _("The battle was refused.{PAUSE 60}");
#endif
#if GERMAN
const u8 gText_RefusedBattle[] = _("Kampfabsage.{PAUSE 60}");
#else
const u8 gText_RefusedBattle[] = _("Refused the battle.{PAUSE 60}");
#endif
#if GERMAN
const u8 gText_NoWeather[] = _("Wetterlos");
#else
const u8 gText_NoWeather[] = _("NO WEATHER");
#endif // Below are unused debug names for weather types
#if GERMAN
const u8 gText_Sunny[] = _("Sonnig");
#else
const u8 gText_Sunny[] = _("SUNNY");
#endif // Unused
#if GERMAN
const u8 gText_Sunny2[] = _("Sonnig 2");
#else
const u8 gText_Sunny2[] = _("SUNNY2");
#endif // Unused
#if GERMAN
const u8 gText_Rain[] = _("Regen");
#else
const u8 gText_Rain[] = _("RAIN");
#endif // Unused
#if GERMAN
const u8 gText_Snow[] = _("Schnee");
#else
const u8 gText_Snow[] = _("SNOW");
#endif // Unused
#if GERMAN
const u8 gText_Lightning[] = _("Gewitter");
#else
const u8 gText_Lightning[] = _("LIGHTNING");
#endif // Unused
#if GERMAN
const u8 gText_Fog[] = _("Nebel");
#else
const u8 gText_Fog[] = _("FOG");
#endif // Unused
#if GERMAN
const u8 gText_VolcanoAsh[] = _("Vulkanasche");
#else
const u8 gText_VolcanoAsh[] = _("VOLCANO ASH");
#endif // Unused
#if GERMAN
const u8 gText_Sandstorm[] = _("Sandsturm");
#else
const u8 gText_Sandstorm[] = _("SANDSTORM");
#endif // Unused
#if GERMAN
const u8 gText_Fog2[] = _("Nebel 2");
#else
const u8 gText_Fog2[] = _("FOG2");
#endif // Unused
#if GERMAN
const u8 gText_Seafloor[] = _("Tiefsee");
#else
const u8 gText_Seafloor[] = _("SEAFLOOR");
#endif // Unused
#if GERMAN
const u8 gText_Cloudy[] = _("Wolkig");
#else
const u8 gText_Cloudy[] = _("CLOUDY");
#endif // Unused
#if GERMAN
const u8 gText_Sunny3[] = _("Sonnig 3");
#else
const u8 gText_Sunny3[] = _("SUNNY3");
#endif // Unused
#if GERMAN
const u8 gText_HeavyRain[] = _("Wolkenbruch");
#else
const u8 gText_HeavyRain[] = _("HEAVY RAIN");
#endif // Unused
#if GERMAN
const u8 gText_Seafloor2[] = _("Tiefsee2");
#else
const u8 gText_Seafloor2[] = _("SEAFLOOR2");
#endif // Unused
#if GERMAN
const u8 gText_DelAll[] = _("Löschen");
#else
const u8 gText_DelAll[] = _("DEL. ALL");
#endif
#if GERMAN
const u8 gText_Cancel5[] = _("Abbruch");
#else
const u8 gText_Cancel5[] = _("CANCEL");
#endif
#if GERMAN
const u8 gText_Ok2[] = _("O.K.");
#else
const u8 gText_Ok2[] = _("OK");
#endif
#if GERMAN
const u8 gText_Quiz[] = _("Quiz");
#else
const u8 gText_Quiz[] = _("QUIZ");
#endif
#if GERMAN
const u8 gText_Answer[] = _("Antwort");
#else
const u8 gText_Answer[] = _("ANSWER");
#endif
#if GERMAN
const u8 gText_PokeBalls[] = _("Pokébälle");
#else
const u8 gText_PokeBalls[] = _("POKé BALLS");
#endif
#if GERMAN
const u8 gText_Berry[] = _("Beere");
#else
const u8 gText_Berry[] = _("BERRY");
#endif
#if GERMAN
const u8 gText_Berries[] = _("Beeren");
#else
const u8 gText_Berries[] = _("BERRIES");
#endif
#if GERMAN
const u8 gText_Obtained999RareCandies[] = _("Du hast 999 Sonderbonbons\nerhalten!{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_Obtained999RareCandies[] = _("You obtained 999 RARE\nCANDIES!{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_ExpShareOn[] = _("Der EP-Teiler wurde aktiviert.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_ExpShareOn[] = _("The Exp. Share has been turned on.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_ExpShareOff[] = _("Der EP-Teiler wurde deaktiviert.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_ExpShareOff[] = _("The Exp. Share has been turned off.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
ALIGNED(4) const u8 gText_Ghost[] = _("Geist");
#else
ALIGNED(4) const u8 gText_Ghost[] = _("GHOST");
#endif
#if GERMAN
const u8 gText_Boulderbadge[] = _("Felsorden");
#else
const u8 gText_Boulderbadge[] = _("BOULDERBADGE");
#endif
#if GERMAN
const u8 gText_Cascadebadge[] = _("Quellorden");
#else
const u8 gText_Cascadebadge[] = _("CASCADEBADGE");
#endif
#if GERMAN
const u8 gText_Thunderbadge[] = _("Donnerorden");
#else
const u8 gText_Thunderbadge[] = _("THUNDERBADGE");
#endif
#if GERMAN
const u8 gText_Rainbowbadge[] = _("Farborden");
#else
const u8 gText_Rainbowbadge[] = _("RAINBOWBADGE");
#endif
#if GERMAN
const u8 gText_Soulbadge[] = _("Seelenorden");
#else
const u8 gText_Soulbadge[] = _("SOULBADGE");
#endif
#if GERMAN
const u8 gText_Marshbadge[] = _("Sumpforden");
#else
const u8 gText_Marshbadge[] = _("MARSHBADGE");
#endif
#if GERMAN
const u8 gText_Volcanobadge[] = _("Vulkanorden");
#else
const u8 gText_Volcanobadge[] = _("VOLCANOBADGE");
#endif
#if GERMAN
const u8 gText_Earthbadge[] = _("Erdorden");
#else
const u8 gText_Earthbadge[] = _("EARTHBADGE");
#endif
#if GERMAN
const u8 gText_OakImportantToGetToKnowPokemonThroughly[] = _("Eich: Es ist wichtig deine\nPokémon gut kennenzulernen.\p");
#else
const u8 gText_OakImportantToGetToKnowPokemonThroughly[] = _("OAK: It's important to get to know\nyour POKéMON thoroughly.\p");
#endif
#if GERMAN
const u8 gText_OakThisIsListOfPokemon[] = _("Dies ist eine Liste deiner Pokémon,\n{PLAYER}.\pÖffne dies um die Attacken und\nFähigkeiten zu sehen.\pDu kannst sie hier auch auswählen\num ihnen ein Item zu geben.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_OakThisIsListOfPokemon[] = _("This is a list of your POKéMON,\n{PLAYER}.\pOpen this to check the skills\nand moves of your POKéMON.\pYou also choose POKéMON here if\nyou want to use an item on one.{PAUSE_UNTIL_PRESS}");
#endif

#if GERMAN
const u8 gText_GBPlayerOn[] = _("Der GB geht an.\nNostalgie füllt die Luft.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_GBPlayerOn[] = _("The GB Player was turned on.\nSounds from the past fill the air.{PAUSE_UNTIL_PRESS}");
#endif
#if GERMAN
const u8 gText_GBPlayerOff[] = _("GB ausgeschaltet.{PAUSE_UNTIL_PRESS}");
#else
const u8 gText_GBPlayerOff[] = _("The GB Player was turned off.\nSounds of nostalgia fade away.{PAUSE_UNTIL_PRESS}");
#endif

#if GERMAN
const u8 gText_Sunday[] = _("Sonntag");
#else
const u8 gText_Sunday[] = _("SUNDAY");
#endif
#if GERMAN
const u8 gText_Monday[] = _("Montag");
#else
const u8 gText_Monday[] = _("MONDAY");
#endif
#if GERMAN
const u8 gText_Tuesday[] = _("Dienstag");
#else
const u8 gText_Tuesday[] = _("TUESDAY");
#endif
#if GERMAN
const u8 gText_Wednesday[] = _("Mittwoch");
#else
const u8 gText_Wednesday[] = _("WEDNESDAY");
#endif
#if GERMAN
const u8 gText_Thursday[] = _("Donnerstag");
#else
const u8 gText_Thursday[] = _("THURSDAY");
#endif
#if GERMAN
const u8 gText_Friday[] = _("Freitag");
#else
const u8 gText_Friday[] = _("FRIDAY");
#endif
#if GERMAN
const u8 gText_Saturday[] = _("Samstag");
#else
const u8 gText_Saturday[] = _("SATURDAY");
#endif
#if GERMAN
const u8 gText_LoveBall[] =     _("Sympaball / Pirsifbeere / (FEE/PSY)");
#else
const u8 gText_LoveBall[] =     _("LOVE    / PECHA  / (FRY/PSY)");
#endif
#if GERMAN
const u8 gText_Lure[] =         _("Köderball / Fragiabeere / (WAS/DRA)");
#else
const u8 gText_Lure[] =         _("LURE    / RAWST  / (WTR/DRG)");
#endif
#if GERMAN
const u8 gText_FriendBall[] =   _("Freundesball / Amrenabeere / (KÄF/PFL)");
#else
const u8 gText_FriendBall[] =   _("FRIEND / CHERI  / (BUG/GRS)");
#endif
#if GERMAN
const u8 gText_Heavy[] =        _("Schwerball / Sinelbeere / (GES/BOD/STA)");
#else
const u8 gText_Heavy[] =        _("HEAVY   / ORAN   / (RCK/GND/STL)");
#endif
#if GERMAN
const u8 gText_Moon[] =         _("Mondball / Maronbeere / (UNL/GEI/GIF)");
#else
const u8 gText_Moon[] =         _("MOON    / CHESTO / (DRK/GST/PSN)");
#endif
#if GERMAN
const u8 gText_Fast[] =         _("Turboball / Wilbirbeere / (ELE/KAM/FEU)");
#else
const u8 gText_Fast[] =         _("FAST    / ASPEAR / (ELC/FIG/FIR)");
#endif
#if GERMAN
const u8 gText_LevelBall[] =    _("Levelball / Persimbeere / (NOR/FLU/EIS)");
#else
const u8 gText_LevelBall[] =    _("LEVEL  / PERSIM / (NRM/FLY/ICE)");
#endif
#if GERMAN
const u8 gText_Vermilion[] = _("Orania-City");
#else
const u8 gText_Vermilion[] = _("VERMILION");
#endif
#if GERMAN
const u8 gText_Olivine[] = _("Oliviana-City");
#else
const u8 gText_Olivine[] = _("OLIVINE");
#endif
#if GERMAN
const u8 gText_Floor0[] = _("Keller");
#else
const u8 gText_Floor0[] = _("Floor 0");
#endif
#if GERMAN
const u8 gText_Pal[] = _("Kumpel");
#else
const u8 gText_Pal[] = _("Pal");
#endif
#if GERMAN
const u8 gText_Underling[] = _("Untergebener");
#else
const u8 gText_Underling[] = _("Underling");
#endif
#if GERMAN
const u8 gText_Strategy[] = _("Strategie");
#else
const u8 gText_Strategy[] = _("Strategy");
#endif
const u8 gText_Training[] = _("Training");
#if GERMAN
const u8 gText_Cheating[] = _("Schummeln");
#else
const u8 gText_Cheating[] = _("Cheating");
#endif
#if GERMAN
const u8 gText_WeakPerson[] = _("Schwache Person");
#else
const u8 gText_WeakPerson[] = _("Weak person");
#endif
#if GERMAN
const u8 gText_ToughPerson[] = _("Starke Person");
#else
const u8 gText_ToughPerson[] = _("Tough person");
#endif
#if GERMAN
const u8 gText_Anybody[] = _("Irgendjemand");
#else
const u8 gText_Anybody[] = _("Anybody");
#endif
#if GERMAN
const u8 gText_Love2[] = _("Liebe");
#else
const u8 gText_Love2[] = _("Love");
#endif
#if GERMAN
const u8 gText_Violence[] = _("Gewalt");
#else
const u8 gText_Violence[] = _("Violence");
#endif
#if GERMAN
const u8 gText_Knowledge[] = _("Wissen");
#else
const u8 gText_Knowledge[] = _("Knowledge");
#endif
#if GERMAN
const u8 gText_Tough3[] = _("Zäh");
#else
const u8 gText_Tough3[] = _("Tough");
#endif
#if GERMAN
const u8 gText_Weak[] = _("Schwach");
#else
const u8 gText_Weak[] = _("Weak");
#endif
#if GERMAN
const u8 gText_Both[] = _("Beides");
#else
const u8 gText_Both[] = _("Both");
#endif
#if GERMAN
const u8 gText_GreenStone[] = _("Grüner Stein");
#else
const u8 gText_GreenStone[] = _("GREEN STONE");
#endif
#if GERMAN
const u8 gText_RedStone[] = _("Roter Stein");
#else
const u8 gText_RedStone[] = _("RED STONE");
#endif
#if GERMAN
const u8 gText_BlueStone[] = _("Blauer Stein");
#else
const u8 gText_BlueStone[] = _("BLUE STONE");
#endif
