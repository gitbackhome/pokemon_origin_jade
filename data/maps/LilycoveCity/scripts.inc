LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
#if IS_HNS
	@ HnS: FLAG_BADGE07_GET gehoert zu den Johto/Kanto-Orden und ist
	@ hier laengst gesetzt - stattdessen den Hoenn-Orden pruefen.
	setvar VAR_0x8004, 6
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_GirlAquaGone
#else
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
#endif
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
#if IS_HNS
	@ HnS: FLAG_BADGE07_GET gehoert zu den Johto/Kanto-Orden und ist
	@ hier laengst gesetzt - stattdessen den Hoenn-Orden pruefen.
	setvar VAR_0x8004, 6
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_ExpertM2AquaGone
#else
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
#endif
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_IS_HOENN_CHAMPION, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
#if IS_HNS
	@ HnS-Kanon: Die Rivalin ist immer Maike, unabhaengig vom Geschlecht
	@ der Spielfigur. Brix bleibt als eigenstaendige Figur frei.
	goto LilycoveCity_EventScript_May
#else
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
#endif
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
#if IS_HNS
	@ HnS: VAR_STARTER_MON traegt hier den Johto-Starter. Maikes Starterlinie
	@ steht seit Route 103 fest (Flemmli), deshalb immer das Treecko-Set.
	goto LilycoveCity_EventScript_BattleMayTreecko
#else
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
#endif
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
#if IS_HNS
	@ HnS: FLAG_BADGE06_GET gehoert zu den Johto/Kanto-Orden und ist
	@ hier laengst gesetzt - stattdessen den Hoenn-Orden pruefen.
	setvar VAR_0x8004, 5
	special CheckHoennBadge
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_CheckFinalBadge
#else
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
#endif
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
#if IS_HNS
	@ HnS: FLAG_BADGE08_GET gehoert zu den Johto/Kanto-Orden und ist
	@ hier laengst gesetzt - stattdessen den Hoenn-Orden pruefen.
	setvar VAR_0x8004, 7
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_HasFinalBadge
#else
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
#endif
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_IS_HOENN_CHAMPION, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
#if IS_HNS
	@ HnS: FLAG_BADGE06_GET gehoert zu den Johto/Kanto-Orden und ist
	@ hier laengst gesetzt - stattdessen den Hoenn-Orden pruefen.
	setvar VAR_0x8004, 5
	special CheckHoennBadge
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_CheckFinalBadge
#else
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
#endif
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_IS_HOENN_CHAMPION, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
#if GERMAN
	.string "Maike: {PLAYER}!\p"
	.string "Ich habe hier alles zusammen, was mein\n"
	.string "Team noch gebraucht hat.\p"
	.string "Sechs Pokémon, jedes einzelne von mir\n"
	.string "großgezogen.\p"
	.string "Irgendwann schlage ich einen Champion.\n"
	.string "Und du bist der, den ich meine.$"
#else
	.string "MAY: Oh, hey?\n"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
	.string "I bought a whole bunch of DOLLS and\n"
	.string "POSTERS.\p"
	.string "Of course, I've also caught a lot of\n"
	.string "POKéMON, and I'm raising them\l"
	.string "properly, too.\p"
	.string "Actually, I'm more worried if you're\n"
	.string "raising POKéMON properly, {PLAYER}{KUN}.\p"
	.string "I'll battle with you, so you can show\n"
	.string "me your POKéMON, {PLAYER}{KUN}.$"
#endif

LilycoveCity_Text_MayNotRaisingPokemon:
#if GERMAN
	.string "Maike: Jetzt nicht?\p"
	.string "Dann eben später. Ich laufe dir nicht\n"
	.string "weg, {PLAYER}.$"
#else
	.string "MAY: Oh, why? {PLAYER}{KUN}, haven't you\n"
	.string "been raising your POKéMON?\p"
	.string "That's not a very good showing as a\n"
	.string "TRAINER…$"
#endif

LilycoveCity_Text_MayBattleMe:
#if GERMAN
	.string "Maike: Komm schon. Einmal noch.$"
#else
	.string "MAY: Come on, battle with me, so I can\n"
	.string "check out your POKéMON!$"
#endif

LilycoveCity_Text_MayWontBeBeaten:
#if GERMAN
	.string "Maike: Diesmal gebe ich nichts her.\n"
	.string "Nicht eines.$"
#else
	.string "MAY: The POKéMON I raised won't be\n"
	.string "beaten by your POKéMON, {PLAYER}{KUN}!$"
#endif

LilycoveCity_Text_MayDefeat:
#if GERMAN
	.string "… … … … … … … …\p"
	.string "Auf Route 103 warst du eine Wand.\p"
	.string "Heute warst du eine Tür, die sich\n"
	.string "einen Spalt geöffnet hat.\p"
	.string "Beim nächsten Mal reiße ich sie auf.$"
#else
	.string "… … … … … … … …\p"
	.string "I remember the battle I had with you,\n"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
	.string "That battle helped you become this\n"
	.string "strong, {PLAYER}{KUN}, didn't it?$"
#endif

LilycoveCity_Text_MayGoingBackToLittleroot:
#if GERMAN
	.string "Maike: Ich fahre kurz nach Wurzelheim\n"
	.string "und zeige meinem Vater den Pokédex.\p"
	.string "Danach trainiere ich weiter.\p"
	.string "Ich habe schließlich noch etwas vor.$"
#else
	.string "MAY: I'm thinking of going back to\n"
	.string "LITTLEROOT soon.\p"
	.string "I've caught a decent group of POKéMON,\n"
	.string "and my POKéDEX is coming along, so\l"
	.string "I'm going home to show my dad.$"
#endif

LilycoveCity_Text_MayYouGoingToCollectBadges:
#if GERMAN
	.string "{PLAYER}{KUN}, was wirst du machen?\p"
	.string "Alle Orden der Arenen sammeln und die\n"
	.string "Pokémon Liga herausfordern?\p"
	.string "Nun, während du deine Orden sammelst,\n"
	.string "werde ich weiter an meinem Pokédex\l"
	.string "arbeiten. Ich werde ihn eher\l"
	.string "vollständig haben als du, wetten?\p"
	.string "Bis dann!$"
#else
	.string "{PLAYER}{KUN}, what are you going to do?\p"
	.string "Collect all the GYM BADGES and take\n"
	.string "the POKéMON LEAGUE challenge?\p"
	.string "Well, while you're collecting BADGES,\n"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
	.string "POKéDEX. I'll complete it before you!\p"
	.string "See you!$"
#endif

LilycoveCity_Text_MayYouGoingToPokemonLeague:
#if GERMAN
	.string "Und, {PLAYER}{KUN}, was wirst du\n"
	.string "machen? \p"
	.string "Wirst du die Pokémon Liga heraus-\n"
	.string "fordern?\p"
	.string "Oder wirst du deinen Pokédex vervoll-\n"
	.string "ständigen?\p"
	.string "Ich habe gegen dich verloren, aber den\n"
	.string "Pokédex werde ich eher vollständig\l"
	.string "haben als du!\p"
	.string "Man sieht sich!$"
#else
	.string "{PLAYER}{KUN}, what are you going to do?\p"
	.string "Are you taking the POKéMON LEAGUE\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "POKéDEX?\p"
	.string "I might've lost to you in battling,\n"
	.string "but I'll finish my POKéDEX before you!\p"
	.string "See you!$"
#endif

LilycoveCity_Text_MayYouGoingToBattleFrontier:
#if GERMAN
	.string "Und, {PLAYER}{KUN}, was wirst du\n"
	.string "machen? \p"
	.string "Wirst du zur Kampfzone gehen?\p"
	.string "Oder wirst du deinen Pokédex vervoll-\n"
	.string "ständigen?\p"
	.string "Ich habe gegen dich verloren, aber den\n"
	.string "Pokédex werde ich eher vollständig\l"
	.string "haben als du!\p"
	.string "Man sieht sich!$"
#else
	.string "{PLAYER}{KUN}, what are you going to do?\p"
	.string "Are you taking the BATTLE FRONTIER\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "POKéDEX?\p"
	.string "I might've lost to you in battling,\n"
	.string "but I'll finish my POKéDEX before you!\p"
	.string "See you!$"
#endif

LilycoveCity_Text_BrendanShoppingLetsBattle:
#if GERMAN
	.string "Maike: Oh, du bist es, {PLAYER}.\p"
	.string "Ich mache Besorgungen für meinen\n"
	.string "Vater. Nein, ich kaufe keine Puppen!\p"
	.string "Wir haben uns lange nicht mehr\n"
	.string "gesehen. \p"
	.string "Sollen wir kämpfen, um zu sehen, wer\n"
	.string "seine Pokémon besser trainiert?$"
#else
	.string "BRENDAN: Oh, hey, it's {PLAYER}.\p"
	.string "I'm running an errand for my dad.\n"
	.string "No, I'm not buying any DOLLS.\p"
	.string "Anyways, it's been a while.\p"
	.string "Want to have a battle to see who's been\n"
	.string "raising POKéMON better?$"
#endif

LilycoveCity_Text_BrendanNoConfidence:
#if GERMAN
	.string "Maike: Oh, hast du ein Problem? Nicht\n"
	.string "genügend Selbstbewusstsein, was?$"
#else
	.string "BRENDAN: Oh, what's the matter?\n"
	.string "Don't have the confidence?$"
#endif

LilycoveCity_Text_BrendanBattleMe:
#if GERMAN
	.string "Maike: Sollen wir kämpfen, um zu sehen,\n"
	.string "wer seine Pokémon besser trainiert?$"
#else
	.string "BRENDAN: Want to battle to see who's\n"
	.string "been raising POKéMON better?$"
#endif

LilycoveCity_Text_BrendanWontBeBeaten:
#if GERMAN
	.string "Maike: Aah, ich werde doch nicht\n"
	.string "gegen {PLAYER} verlieren! Niemals!$"
#else
	.string "BRENDAN: Aww, but you know I'm not\n"
	.string "going to lose to no {PLAYER}.$"
#endif

LilycoveCity_Text_BrendanDefeat:
#if GERMAN
	.string "Ach… Du hast dich stark verbessert.\p"
	.string "Das schmerzt - und dabei hatte ich als\n"
	.string "Trainer sogar einen Vorsprung…$"
#else
	.string "Humph…\n"
	.string "You've done a lot of raising.\p"
	.string "That stings a bit--I had a head start\n"
	.string "on you as a TRAINER…$"
#endif

LilycoveCity_Text_BrendanGoingBackToLittleroot:
#if GERMAN
	.string "Maike: Ich…\n"
	.string "Ich gehe nach Hause, nach Wurzelheim.\l"
	.string "\p"
	.string "Weißt du, ich helfe meinem Vater bei dem\n"
	.string "Pokédex. Es geht ganz anständig voran\l"
	.string "und ich sollte ihm das mal zeigen.$"
#else
	.string "BRENDAN: I…\n"
	.string "I plan on going home to LITTLEROOT.\p"
	.string "You know I'm helping out my dad on his\n"
	.string "POKéDEX. It's coming together pretty\l"
	.string "decently, so I should go show him.$"
#endif

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
#if GERMAN
	.string "Und, {PLAYER}, was wirst du tun?\p"
	.string "Wirst du alle Orden der Arenen sammeln\n"
	.string "und die Pokémon Liga herausfordern?\p"
	.string "Vielleicht werde ich das auch machen…\n"
	.string "\p"
	.string "Gut, bleib am Ball!$"
#else
	.string "{PLAYER}, what are you going to do?\p"
	.string "Collect all the GYM BADGES and take\n"
	.string "the POKéMON LEAGUE challenge?\p"
	.string "Maybe I'll do that, too…\p"
	.string "Well, anyway, hang in there!$"
#endif

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
#if GERMAN
	.string "Und, {PLAYER}, was wirst du tun?\p"
	.string "Da du so stark geworden bist, wirst du\n"
	.string "die Pokémon Liga herausfordern?\p"
	.string "Hey, ich habe meine Pokémon bestimmt\n"
	.string "viel besser trainiert und sollte\l"
	.string "eigentlich stärker sein als du…\p"
	.string "Nun ja, bleib am Ball!$"
#else
	.string "{PLAYER}, what are you going to do?\p"
	.string "Since you're that strong, are you\n"
	.string "taking the POKéMON LEAGUE challenge?\p"
	.string "Heh, even me--if I trained my POKéMON\n"
	.string "a bit more, I should be stronger than\l"
	.string "you, {PLAYER}.\p"
	.string "Well, anyway, hang in there!$"
#endif

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
#if GERMAN
	.string "Und, {PLAYER}, was machst du nun?\p"
	.string "Wirst du zur Kampfzone gehen?\p"
	.string "Oder wirst du deinen Pokédex\n"
	.string "vervollständigen?\p"
	.string "Da du so stark geworden bist, solltest\n"
	.string "du zur Kampfzone gehen.\p"
	.string "Häh, wenn ich meine Pokémon besser\n"
	.string "trainiere, sollte ich eigentlich stärker\l"
	.string "werden als du…\p"
	.string "Vielleicht sollte ich zur Kampfzone\n"
	.string "gehen.\p"
	.string "Wie dem auch sei… Bleib am Ball!$"
#else
	.string "{PLAYER}, what are you going to do?\p"
	.string "Are you taking the BATTLE FRONTIER\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "POKéDEX?\p"
	.string "Since you're that strong, you should\n"
	.string "consider the BATTLE FRONTIER.\p"
	.string "Heh, if I train my POKéMON a bit more,\n"
	.string "I'll get stronger than you, {PLAYER}.\p"
	.string "Maybe I should go to the BATTLE\n"
	.string "FRONTIER.\p"
	.string "Well, anyway, hang in there!$"
#endif

LilycoveCity_Text_MovedLootIntoHideoutToday:
#if GERMAN
	.string "Hähähä…\p"
	.string "Heute haben wir noch mehr Beute in\n"
	.string "unser Versteck gebracht…\p"
	.string "We…wer bist du denn??? Ich… äh, habe\n"
	.string "mit mir selbst gesprochen!$"
#else
	.string "Fufufu…\p"
	.string "We moved more loot into our secret\n"
	.string "HIDEOUT today…\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"
#endif

LilycoveCity_Text_ChanceToDoBigThings:
#if GERMAN
	.string "Ich bin nur ein Rüpel, ich weiß nicht,\n"
	.string "was unser Boss so vorhat…\p"
	.string "Aber als Mitglied von Team Aqua habe ich\n"
	.string "die Möglichkeit, große Dinge zu tun!\p"
	.string "Ww…wer bist du denn??? I-Ich… hähähä,\n"
	.string "habe nur mit mir selber gesprochen!$"
#else
	.string "I'm just a GRUNT, so I don't know what\n"
	.string "the BOSS is thinking…\p"
	.string "But being on TEAM AQUA, I know I'll get\n"
	.string "the chance to do big things!\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"
#endif

LilycoveCity_Text_DontGoNearCaveInCove:
#if GERMAN
	.string "Hey, du da!\p"
	.string "Komm bloß nicht in die Nähe der Höhle\n"
	.string "in der Bucht!\p"
	.string "Warum nicht? Das geht dich nichts an!\n"
	.string "Ich bin ein Erwachsener, also gehorche!$"
#else
	.string "Hey, you!\p"
	.string "Don't go near the cave in the cove!\p"
	.string "Why? You don't need a reason why!\n"
	.string "I'm an adult, so you just listen to me!$"
#endif

LilycoveCity_Text_IfWorldBecomesOurs:
#if GERMAN
	.string "Wenn die ganze Welt erst einmal uns\n"
	.string "gehört, Team Aqua, dann wird sie ein\l"
	.string "besserer Ort für Pokémon sein.$"
#else
	.string "If this whole wide world becomes ours,\n"
	.string "TEAM AQUA's, it will be a happier\l"
	.string "place for POKéMON, too.$"
#endif

LilycoveCity_Text_WailmerLeapOutOfWater:
#if GERMAN
	.string "Hier, Wailmer!!!\n"
	.string "Springt aus dem Wasser!$"
#else
	.string "There! WAILMER!\n"
	.string "Leap out of the water now!$"
#endif

LilycoveCity_Text_GetLostMessingUpTraining:
#if GERMAN
	.string "Häh? Was willst du?\p"
	.string "Du störst uns beim Training, also würde\n"
	.string "ich vorschlagen, du verschwindest!$"
#else
	.string "Hunh? What do you want?\p"
	.string "You're messing up our training,\n"
	.string "so can you, like, get lost?$"
#endif

LilycoveCity_Text_ContestHallInTown:
#if GERMAN
	.string "Hier gibt es eine Pokémon Wettbewerbs-\n"
	.string "halle.\p"
	.string "Und das bedeutet, dass gut\n"
	.string "aufgezogene Pokémon aus dem ganzen\l"
	.string "Land zu sehen sind.\p"
	.string "Mein Herz strömt über vor Begeisterung!$"
#else
	.string "There's a POKéMON CONTEST HALL\n"
	.string "right in this here town. \p"
	.string "That means well-raised POKéMON will\n"
	.string "come from all over the country.\p"
	.string "My heart swells with excitement!$"
#endif

LilycoveCity_Text_StrangeCaveInCove:
#if GERMAN
	.string "Hast du die seltsame Höhle in der\n"
	.string "Bucht am Ende des Ortes gesehen?$"
#else
	.string "Have you seen that strange cave in\n"
	.string "the cove at the edge of town?$"
#endif

LilycoveCity_Text_GoingToMoveDeleterForHMs:
#if GERMAN
	.string "Ich werde meinem Pokémon einige neue\n"
	.string "Attacken für den Wettbewerb\l"
	.string "beibringen.\p"
	.string "Daher werde ich den Attackenverlerner\n"
	.string "besuchen, damit einige VMs verlernt\l"
	.string "werden.$"
#else
	.string "I'm going to teach my POKéMON some new\n"
	.string "moves for entering a CONTEST.\p"
	.string "So, I'm going to see the MOVE DELETER\n"
	.string "and make it forget HM moves.$"
#endif

LilycoveCity_Text_ImFromKanto:
#if GERMAN
	.string "Ich komme aus Kanto.\p"
	.string "Die Hoenn-Region ist wunderschön mit\n"
	.string "all dem Wasser und dem Grün.\p"
	.string "Hey, warte mal!\p"
	.string "Ob es seltene Pokémon gibt, die nur in\n"
	.string "dieser Region leben???$"
#else
	.string "I came from KANTO.\p"
	.string "The HOENN region is beautiful with\n"
	.string "all its water and verdant nature.\p"
	.string "Hunh? Wait a second…\p"
	.string "Could there be rare POKéMON that live\n"
	.string "only in this area?$"
#endif

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
#if GERMAN
	.string "Team Aqua trainiert seine Wailmer\n"
	.string "drüben in der Bucht.\p"
	.string "Wir Matrosen können nicht auslaufen,\n"
	.string "da sie uns im Weg sind.$"
#else
	.string "TEAM AQUA's been training their\n"
	.string "WAILMER in the cove.\p"
	.string "We SAILORS can't get our boats out\n"
	.string "to sea with them in the way!$"
#endif

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
#if GERMAN
	.string "Ahoi, hast du das mitbekommen?\p"
	.string "Jemand hat für uns Team Aqua aus\n"
	.string "unserer Fahrrinne verjagt!\p"
	.string "Die Wailmer befinden sich nicht mehr in\n"
	.string "der Bucht und wir haben freie Fahrt.$"
#else
	.string "Ahoy, did you know?\p"
	.string "Someone punted TEAM AQUA out of\n"
	.string "the way for us!\p"
	.string "That got the WAILMER out of the cove,\n"
	.string "so we can get our boats out again.$"
#endif

LilycoveCity_Text_SomeoneStoleMyPokemon:
#if GERMAN
	.string "Ich habe ein entspannendes Nickerchen\n"
	.string "im Gasthof am Meer gehalten. Das\l"
	.string "Rauschen der Wellen war so angenehm.\p"
	.string "Und da hat mir jemand mein Pokémon\n"
	.string "gestohlen!\p"
	.string "Wer ist der schändliche Dieb?\n"
	.string "Team Aqua? Es war Team Aqua?!?$"
#else
	.string "I was taking a relaxing snooze at the\n"
	.string "seaside inn to the sound of waves…\p"
	.string "When someone stole my POKéMON!\p"
	.string "Who's the abductor?\n"
	.string "TEAM AQUA? Is it TEAM AQUA?$"
#endif

LilycoveCity_Text_MissingPokemonCameBack:
#if GERMAN
	.string "Mein gestohlenes Pokémon…\n"
	.string "Es kam zurück, ohne dass ich es merkte.$"
#else
	.string "My missing POKéMON…\n"
	.string "It came back without me noticing!$"
#endif

LilycoveCity_Text_ImArtDealer:
#if GERMAN
	.string "Ich bin ein Kunsthändler.\p"
	.string "Ich kaufe und verkaufe Kunstgegen-\n"
	.string "stände. Vorzugsweise Gemälde.\p"
	.string "Ich habe gehört, dass das hiesige\n"
	.string "Museum ständig erstklassige Werke\l"
	.string "ausstellt.$"
#else
	.string "I'm an ART DEALER.\p"
	.string "I am a buyer and seller of fine art,\n"
	.string "especially paintings.\p"
	.string "I've heard that the MUSEUM here has\n"
	.string "magnificent works on exhibit…$"
#endif

LilycoveCity_Text_SeaRemainsForeverYoung:
#if GERMAN
	.string "Auch wenn ich alt und grau werde, das\n"
	.string "Meer wird immer jung und voll von Leben\l"
	.string "sein…\p"
	.string "Hahahahaha… Haaahahahaha…$"
#else
	.string "Even as we grow old and wrinkled,\n"
	.string "the sea remains forever young with\l"
	.string "the vivid brilliance of life…\p"
	.string "Fwohoho fwohohohoho…$"
#endif

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
#if GERMAN
	.string "Vor 60 Jahren hat mein Mann hier um\n"
	.string "meine Hand angehalten. Und das Meer ist\l"
	.string "immer noch genauso schön.\p"
	.string "Hahahahaha… Haaahahahaha…$"
#else
	.string "It was sixty years ago that my husband\n"
	.string "proposed to me here.\l"
	.string "The sea remains as beautiful as ever.\p"
	.string "Mufufufu mufufufufufu…$"
#endif

LilycoveCity_Text_TeamAquaRenovatedCavern:
#if GERMAN
	.string "Hm, kennst du diese besondere Höhle in\n"
	.string "der Bucht?\p"
	.string "Das ist eine natürliche Formation, aber\n"
	.string "Team Aqua kam und hat das Aussehen\l"
	.string "verändert.\p"
	.string "Sie nennen sich selber “Naturliebendes\n"
	.string "Team Aqua”!\p"
	.string "Aber was sie sagen und was sie tun,\n"
	.string "passt überhaupt nicht zusammen!$"
#else
	.string "Hm, you know of the peculiar cavern\n"
	.string "in this cove?\p"
	.string "That had been a natural formation,\n"
	.string "but then that TEAM AQUA lot came\l"
	.string "along and made their renovations.\p"
	.string "They call themselves\n"
	.string "the “nature-loving TEAM AQUA”!\p"
	.string "But what they do and what they say\n"
	.string "don't match at all!$"
#endif

LilycoveCity_Text_TeamAquaLotGoneForGood:
#if GERMAN
	.string "Die Höhle in der Bucht…\p"
	.string "Es ist mir erst gar nicht aufgefallen,\n"
	.string "aber sie ist völlig leer.\p"
	.string "Team Aqua muss verschwunden sein.$"
#else
	.string "That cave in the cove…\p"
	.string "I didn't notice it right away,\n"
	.string "but it's completely empty now.\p"
	.string "That TEAM AQUA lot, they must\n"
	.string "have gone away for good.$"
#endif

LilycoveCity_Text_CitySign:
#if GERMAN
	.string "Seegrasulb City\p"
	.string "“Wo das Land endet und das\n"
	.string "Meer beginnt.”$"
#else
	.string "LILYCOVE CITY\p"
	.string "“Where the land ends and the\n"
	.string "sea begins.”$"
#endif

LilycoveCity_Text_ContestHallSign:
#if GERMAN
	.string "Pokémon Wettbewerbshalle\n"
	.string "“Der Treffpunkt für Trainer.”$"
#else
	.string "POKéMON CONTEST HALL\n"
	.string "“The gathering place for TRAINERS!”$"
#endif

LilycoveCity_Text_MotelSign:
#if GERMAN
	.string "Grassee Motel\p"
	.string "“Behalte uns als Rose von\n"
	.string "Seegrasulb City in Erinnerung.”$"
#else
	.string "COVE LILY MOTEL\p"
	.string "“Remember us as COVE LILY of\n"
	.string "LILYCOVE.”$"
#endif

LilycoveCity_Text_MuseumSign:
#if GERMAN
	.string "Seegrasulb City Museum\p"
	.string "“Ausstellung von\n"
	.string "Pokémon-Meisterwerken!”$"
#else
	.string "LILYCOVE MUSEUM\p"
	.string "“POKéMON Masterpiece Collection\n"
	.string "on exhibit!”$"
#endif

LilycoveCity_Text_MuseumSignPlayersExhibit:
#if GERMAN
	.string "Seegrasulb City Museum\p"
	.string "“Aktuelle Ausstellung:\n"
	.string "Die Pokémon-Sammlung von {PLAYER}!”$"
#else
	.string "LILYCOVE MUSEUM\p"
	.string "“{PLAYER}'s POKéMON Collection\n"
	.string "on exhibit!”$"
#endif

LilycoveCity_Text_HarborSignUnderConstruction:
#if GERMAN
	.string "Hafen Seegrasulb City\p"
	.string "“Die Fähre MS Tide wird momentan\n"
	.string "in der Werft gebaut.\p"
	.string "Die Fähre wird so bald wie möglich\n"
	.string "ihren Dienst aufnehmen.”$"
#else
	.string "LILYCOVE CITY HARBOR\p"
	.string "“The ferry S.S. TIDAL is under\n"
	.string "construction in SLATEPORT CITY.\p"
	.string "“Service is scheduled to begin\n"
	.string "shortly.”$"
#endif

LilycoveCity_Text_HarborSign:
#if GERMAN
	.string "Hafen Seegrasulb City\p"
	.string "“Genießen Sie die entspannende Fahrt\n"
	.string "mit der Fähre MS Tide.”$"
#else
	.string "LILYCOVE CITY HARBOR\p"
	.string "“Enjoy a delightful cruise on\n"
	.string "the ferry S.S. TIDAL.”$"
#endif

LilycoveCity_Text_TrainerFanClubSign:
#if GERMAN
	.string "Pokémon Trainer-Fanclub\p"
	.string "Die Namen von Trainern sind auf dem\n"
	.string "Schild eingeritzt…$"
#else
	.string "POKéMON TRAINER FAN CLUB\p"
	.string "The names of TRAINERS are scribbled\n"
	.string "all over the sign…$"
#endif

LilycoveCity_Text_DepartmentStoreSign:
#if GERMAN
	.string "Seegrasulb City Einkaufszentrum\p"
	.string "“Ein Überfluss an Waren und\n"
	.string "Überraschungen!\p"
	.string "Ein Ort, an dem man alles findet, was\n"
	.string "das Herz begehrt!”$"
#else
	.string "LILYCOVE DEPARTMENT STORE\p"
	.string "“Overflowing with great merchandise\n"
	.string "and excitement!\p"
	.string "“A great place to find that something\n"
	.string "you need!”$"
#endif

LilycoveCity_Text_MoveDeletersHouseSign:
#if GERMAN
	.string "Haus des Attacken-Verlerners\p"
	.string "“Hier werden Pokémon-Attacken\n"
	.string "verlernt.”$"
#else
	.string "MOVE DELETER'S HOUSE\p"
	.string "“Unwanted POKéMON moves deleted.”$"
#endif

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
#if GERMAN
	.string "Hast du schon mal etwas über den\n"
	.string "Beerenmixer gehört?$"
#else
	.string "Do you know about the machine\n"
	.string "BERRY BLENDER?$"
#endif

LilycoveCity_Text_FasterSpinBetterPokeblocks:
#if GERMAN
	.string "Man muss mit anderen zusammenarbeiten,\n"
	.string "um ihn schneller drehen zu können.\p"
	.string "Ich habe gehört, je schneller man ihn\n"
	.string "dreht, desto besser werden die\l"
	.string "{POKEBLOCK}.$"
#else
	.string "People have to work together to get it\n"
	.string "to spin faster.\p"
	.string "The faster you can make it spin, the\n"
	.string "better {POKEBLOCK}S you can get, I've heard.$"
#endif

LilycoveCity_Text_ExplainBerryBlender:
#if GERMAN
	.string "Damit stellt man eine Leckerei her,\n"
	.string "die {POKEBLOCK} genannt wird.\p"
	.string "Wenn du einem Pokémon einen guten\n"
	.string "{POKEBLOCK} gibst, verbessern sich seine\l"
	.string "Eigenschaften.$"
#else
	.string "It's used for making a kind of candy\n"
	.string "called a {POKEBLOCK}.\p"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
	.string "its condition will improve by a lot.$"
#endif

LilycoveCity_Text_HeardTowerCalledSkyPillar:
#if GERMAN
	.string "Ich habe gehört, dass draußen auf dem\n"
	.string "Seeweg ein Turm sein soll.\p"
	.string "Er soll Himmelturm heißen.$"
#else
	.string "I heard there's a tower somewhere out\n"
	.string "on the sea routes.\p"
	.string "It's called the SKY PILLAR, I hear.$"
#endif

LilycoveCity_Text_SawTallTowerOnRoute131:
#if GERMAN
	.string "Ich habe einen großen Turm in der Nähe\n"
	.string "der Route 131 gesehen.\p"
	.string "Ist das der…$"
#else
	.string "I saw this tall tower somewhere\n"
	.string "around ROUTE 131.\p"
	.string "Could that possibly be…?$"
#endif

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
#if GERMAN
	.string "Wir sind in den Flitterwochen und\n"
	.string "gerade hier angekommen.\p"
	.string "Wir haben ein Drachen-Pokémon\n"
	.string "gesehen, das am Himmel flog.\p"
	.string "Leben in der Hoenn-Region viele\n"
	.string "solcher coolen Pokémon?$"
#else
	.string "We just arrived here on our\n"
	.string "honeymoon vacation.\p"
	.string "We happened to see a DRAGON-type\n"
	.string "POKéMON flying way up in the sky.\p"
	.string "Do cool POKéMON like that live in\n"
	.string "the HOENN region?$"
#endif

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
#if GERMAN
	.string "Wir haben uns vorgenommen, in unseren\n"
	.string "Flitterwochen so viele seltene Pokémon\l"
	.string "zu sehen, wie es eben geht.\p"
	.string "Daher waren wir auch total glücklich,\n"
	.string "als wir gleich nach unserer Ankunft\l"
	.string "dieses Pokémon zu Gesicht bekamen.\p"
	.string "Ich meine, wir waren wirklich glücklich!$"
#else
	.string "On our honeymoon, we vowed to see as\n"
	.string "many rare POKéMON as we can.\p"
	.string "So we were delighted to see a rare\n"
	.string "POKéMON as soon as we arrived.\p"
	.string "I mean, we are totally happy!$"
#endif


LilycoveCity_EventScript_WarpNPC::
    lock
    faceplayer
    gettime
    compare VAR_0x8000, 6
    goto_if_lt LilycoveCity_EventScript_WrongTime
    compare VAR_0x8000, 12
    goto_if_ge LilycoveCity_EventScript_WrongTime
    
    msgbox LilycoveCity_Text_WantToWarp, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq LilycoveCity_EventScript_DoWarp
    msgbox LilycoveCity_Text_DeclinedWarp, MSGBOX_DEFAULT
    release
    end

LilycoveCity_EventScript_WrongTime::
    msgbox LilycoveCity_Text_WrongTime, MSGBOX_DEFAULT
    release
    end

LilycoveCity_EventScript_DoWarp::
    msgbox LilycoveCity_Text_AcceptWarp, MSGBOX_DEFAULT
    closemessage
    warp MAP_CERULEAN_CITY, 34, 8
    waitstate
    release
    end
LilycoveCity_Text_WrongTime:
    .string "Ahoi, ich reise immer vormittags nach Kanto ab.\nWenn du willst, nehme ich dich mit.$"

LilycoveCity_Text_WantToWarp:
    .string "Ahoi, du kommst gerade rechtzeitig. Ich\nfahre jetzt nach Kanto ab. Willst du mit?$"

LilycoveCity_Text_AcceptWarp:
    .string "Dann fahren wir ab!$"

LilycoveCity_Text_DeclinedWarp:
    .string "Vielleicht nächstes Mal.$$"
