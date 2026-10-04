CeruleanCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
	.byte 0

CeruleanCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CERULEAN_CITY
	call_if_unset FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_BlockExits
	end

CeruleanCity_EventScript_BlockExits::
	setobjectxyperm LOCALID_CERULEAN_POLICEMAN, 44, 20
	setobjectxyperm LOCALID_CERULEAN_SLOWBRO, 32, 45
	setobjectxyperm LOCALID_CERULEAN_LASS, 32, 44
	return

CeruleanCity_EventScript_RivalTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerMidL::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_CERULEAN_RIVAL, 42, 1
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerMidR::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_CERULEAN_RIVAL, 43, 1
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_CERULEAN_RIVAL, 44, 1
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_Rival::
	textcolor NPC_TEXT_COLOR_MALE
	setvar VAR_MAP_SCENE_ROUTE22, 2
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	addobject LOCALID_CERULEAN_RIVAL
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalEnter
	waitmovement 0
	msgbox CeruleanCity_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_CERULEAN_RIVAL
	call_if_eq VAR_STARTER_MON, 2, CeruleanCity_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, CeruleanCity_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, CeruleanCity_EventScript_RivalCharmander
	famechecker FAMECHECKER_BILL, 0
	msgbox CeruleanCity_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 1, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 2, CeruleanCity_EventScript_RivalStartExitRight
	@ Kanto-Merge: Die Ruhmesdatei entfaellt - das PokeCom fuehrt die
	@ Kontakte. Damit faellt auch das Umdrehen weg: der Rivale geht in einem
	@ Zug, statt stehenzubleiben und noch einmal das Wort zu ergreifen.
	setvar VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1
	setflag FLAG_GOT_FAME_CHECKER
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalExit
	waitmovement 0
	fadedefaultbgm
	@ Kanto-Merge: removeobject wirkt nur bis zum naechsten Betreten der
	@ Karte. Ohne den Flag stand der Rivale beim Wiederkommen erneut da.
	setflag FLAG_HIDE_CERULEAN_RIVAL
	removeobject LOCALID_CERULEAN_RIVAL
	releaseall
	end

CeruleanCity_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_SQUIRTLE, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_BULBASAUR, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_CHARMANDER, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalStartExit::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExit
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalStartExit
	waitmovement 0
	return

CeruleanCity_EventScript_RivalStartExitRight::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExitRight
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalStartExitRight
	waitmovement 0
	return

CeruleanCity_Movement_PlayerWatchRivalExit::
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_PlayerWatchRivalExitRight::
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_RivalEnter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ Kanto-Merge: Der Rivale lief weg, blieb stehen und kam wieder hoch -
@ das war der Anlauf zur Ruhmesdatei. Die entfaellt, also geht er durch.
CeruleanCity_Movement_RivalStartExit::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ Kanto-Merge: Der Rivale lief weg, blieb stehen und kam wieder hoch -
@ das war der Anlauf zur Ruhmesdatei. Die entfaellt, also geht er durch.
CeruleanCity_Movement_RivalStartExitRight::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Movement_RivalExit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_EventScript_Grunt::
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_EventScript_GruntDefeated
	message CeruleanCity_Text_GruntIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_EventScript_GruntDefeated::
	msgbox CeruleanCity_Text_OkayIllReturnStolenTM
	checkitemspace ITEM_TM28
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_EventScript_NoRoomForTM28
	giveitem_msg CeruleanCity_Text_RecoveredTM28FromGrunt, ITEM_TM28
	msgbox CeruleanCity_Text_BetterGetMovingBye
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_CERULEAN_GRUNT
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_GOT_TM28_FROM_ROCKET
	release
	end

CeruleanCity_EventScript_NoRoomForTM28::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeruleanCity_Text_MakeRoomForThisCantRun
	release
	end

CeruleanCity_EventScript_GruntTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_CERULEAN_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	goto CeruleanCity_EventScript_GruntTrigger
	end

CeruleanCity_EventScript_GruntTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_CERULEAN_GRUNT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto CeruleanCity_EventScript_GruntTrigger
	end

CeruleanCity_EventScript_GruntTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeruleanCity_Text_GruntIntro
	setvar VAR_LAST_TALKED, LOCALID_CERULEAN_GRUNT
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_EventScript_Policeman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_PeopleHereWereRobbed
	closemessage
	applymovement LOCALID_CERULEAN_POLICEMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

@ Sperr-Trigger auf den vier Kacheln links des Polizisten (40-43, 20).
@ Aktiv, solange der Wachdienst laeuft (bis Bill das Ticket gibt, wie
@ BlockExits). Der Spieler wird einen Schritt nach oben zurueckgesetzt.
@ Nach dem Ticket entschaerft der erste Kontakt alle vier Trigger fuer
@ den Kartenbesuch (VAR_TEMP_0 wird beim Betreten der Karte genullt).
CeruleanCity_EventScript_PolicemanBlock::
	lockall
	goto_if_set FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_PolicemanBlockOver
	applymovement LOCALID_CERULEAN_POLICEMAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CeruleanCity_Text_PeopleHereWereRobbed
	closemessage
	applymovement LOCALID_CERULEAN_POLICEMAN, Common_Movement_FaceOriginalDirection
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Movement_PushPlayerUp
	waitmovement 0
	releaseall
	end

CeruleanCity_EventScript_PolicemanBlockOver::
	setvar VAR_TEMP_0, 1
	releaseall
	end

CeruleanCity_Movement_PushPlayerUp:
	walk_up
	step_end

CeruleanCity_EventScript_LittleBoy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_LittleBoySlowbroMoved
	msgbox CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree
	release
	end

CeruleanCity_EventScript_LittleBoySlowbroMoved::
	msgbox CeruleanCity_Text_YouCanCutDownSmallTrees
	release
	end

CeruleanCity_EventScript_BaldingMan::
	msgbox CeruleanCity_Text_PokemonEncyclopediaAmusing, MSGBOX_NPC
	end

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_TrainerLifeIsToughIsntIt, MSGBOX_NPC
	end

CeruleanCity_EventScript_CeruleanCaveGuard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_EventScript_Woman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_WantBrightRedBicycle
	closemessage
	applymovement LOCALID_CERULEAN_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeruleanCity_EventScript_Lass::
	lock
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroCommand1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroCommand2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroCommand3
	waitmessage
	delay 40
	playse SE_PIN
	applymovement LOCALID_CERULEAN_SLOWBRO, Common_Movement_QuestionMark
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroFailed1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroFailed2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroFailed3
	release
	end

CeruleanCity_EventScript_SlowbroCommand1::
	message CeruleanCity_Text_SlowbroUseSonicboom
	return

CeruleanCity_EventScript_SlowbroCommand2::
	message CeruleanCity_Text_SlowbroPunch
	return

CeruleanCity_EventScript_SlowbroCommand3::
	message CeruleanCity_Text_SlowbroWithdraw
	return

CeruleanCity_EventScript_SlowbroFailed1::
	msgbox CeruleanCity_Text_SlowbroPayAttention
	return

CeruleanCity_EventScript_SlowbroFailed2::
	msgbox CeruleanCity_Text_NoYouBlewItAgain
	return

CeruleanCity_EventScript_SlowbroFailed3::
	msgbox CeruleanCity_Text_HardToControlMonsObedience
	return

CeruleanCity_EventScript_Slowbro::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroText1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroText2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroText3
	call_if_eq VAR_0x8008, 3, CeruleanCity_EventScript_SlowbroText4
	release
	end

CeruleanCity_EventScript_SlowbroText1::
	msgbox CeruleanCity_Text_SlowbroTookSnooze
	return

CeruleanCity_EventScript_SlowbroText2::
	msgbox CeruleanCity_Text_SlowbroLoafingAround
	return

CeruleanCity_EventScript_SlowbroText3::
	msgbox CeruleanCity_Text_SlowbroTurnedAway
	return

CeruleanCity_EventScript_SlowbroText4::
	msgbox CeruleanCity_Text_SlowbroIgnoredOrders
	return

CeruleanCity_EventScript_CitySign::
	msgbox CeruleanCity_Text_CitySign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_TrainerTips::
	msgbox CeruleanCity_Text_TrainerTipsHeldItems, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_MISTY, 0
	msgbox CeruleanCity_Text_GymSign
	releaseall
	end

CeruleanCity_Text_RivalIntro::
#if GERMAN
	.string "{RIVAL}: Hi, {PLAYER}!\p"
	.string "Du bist also immer noch unterwegs!\p"
	.string "Mir geht es bestens! Ich habe jede\n"
	.string "Menge neue, starke Pokémon gefangen!\p"
	.string "Zeig, was du gefangen hast, {PLAYER}!$"
#else
	.string "{RIVAL}: Yo! {PLAYER}!\p"
	.string "You're still struggling along back\n"
	.string "here?\p"
	.string "I'm doing great! I caught a bunch\n"
	.string "of strong and smart POKéMON!\p"
	.string "Here, let me see what you caught,\n"
	.string "{PLAYER}!$"
#endif

CeruleanCity_Text_RivalDefeat::
#if GERMAN
	.string "Heh, schon gut! Du hast gewonnen!$"
#else
	.string "Hey!\n"
	.string "Take it easy!\l"
	.string "You won already!$"
#endif

CeruleanCity_Text_RivalPostBattle::
#if GERMAN
	.string "{RIVAL}: Soll ich dir was verraten?\p"
	.string "Ich war bei Bill und habe mir seine\n"
	.string "seltenen Pokémon zeigen lassen!\p"
	.string "Das hat mir einige Einträge in\n"
	.string "meinem Pokédex gebracht!\p"
	.string "Bill ist weltweit als Pokémaniac\n"
	.string "bekannt!\p"
	.string "Er hat das Pokémon-Lagerungs-\n"
	.string "System für den PC entwickelt!\p"
	.string "Du kannst dich bei ihm dafür bedanken!\p"
	.string "Na ja, ich hau ab!\n"
	.string "Mach es gut!$"
#else
	.string "{RIVAL}: Hey, guess what?\p"
	.string "I went to BILL's and got him to\n"
	.string "show me his rare POKéMON.\p"
	.string "That added a lot of pages to my\n"
	.string "POKéDEX!\p"
	.string "After all, BILL's world famous as a\n"
	.string "POKéMANIAC.\p"
	.string "He invented the POKéMON Storage\n"
	.string "System on PC, too.\p"
	.string "Since you're using his system,\n"
	.string "you should go thank him.\p"
	.string "Well, I better get rolling!\n"
	.string "Smell ya later!$"
#endif

CeruleanCity_Text_OhRightLittlePresentAsFavor::
#if GERMAN
	.string "Oh, ja, genau!\p"
	.string "Du tust mir Leid. Nein, wirklich!\n"
	.string "Du mühst dich immer so ab.\p"
	.string "Darum will ich dir einen Gefallen\n"
	.string "tun und schenke dir das!$"
#else
	.string "Oh, yeah, right.\p"
	.string "I feel sorry for you. No, really.\n"
	.string "You're always plodding behind me.\p"
	.string "So here, I'll give you a little\n"
	.string "present as a favor.$"
#endif

CeruleanCity_Text_ExplainFameCheckerSmellYa::
#if GERMAN
	.string "Ein redseliges Plappermaul wie du!\n"
	.string "Das ist wie für dich geschaffen!\p"
	.string "Ich brauche es nicht, da ich mich\n"
	.string "nicht um die anderen schere.\p"
	.string "In Ordnung! Jetzt muss ich aber\n"
	.string "wirklich gehen. Tschüss!$"
#else
	.string "A chatty gossip like you…\n"
	.string "That thing's perfect.\p"
	.string "I don't need it because I don't\n"
	.string "give a hoot about others.\p"
	.string "All right, this time I really am\n"
	.string "gone. Smell ya!$"
#endif

CeruleanCity_Text_GruntIntro::
#if GERMAN
	.string "He! Bleib draußen! Du hast hier\n"
	.string "nichts zu suchen! Was ich hier tue?\p"
	.string "Ich bin nur ein unschuldiger Passant!\n"
	.string "Was?\p"
	.string "Glaubst du mir etwa nicht?$"
#else
	.string "Hey! Stay out!\n"
	.string "It's not your yard!\p"
	.string "…Huh?\n"
	.string "Me?\p"
	.string "I'm an innocent bystander!\n"
	.string "Don't you believe me?{PLAY_BGM}{MUS_RG_ENCOUNTER_ROCKET}$"
#endif

CeruleanCity_Text_GruntDefeat::
#if GERMAN
	.string "Rüpel: Ist gut!\n"
	.string "Ich gebe auf! Ich verschwinde!$"
#else
	.string "GRUNT: Stop! I give up!\n"
	.string "I'll leave quietly!$"
#endif

CeruleanCity_Text_OkayIllReturnStolenTM::
#if GERMAN
	.string "O.K.! Ich gebe die gestohlene TM\n"
	.string "zurück!$"
#else
	.string "…Okay.\n"
	.string "I'll return the TM I stole.$"
#endif

CeruleanCity_Text_RecoveredTM28FromGrunt::
#if GERMAN
	.string "{PLAYER} nimmt dem Rüpel von\n"
	.string "Team Rocket TM28 wieder ab!$"
#else
	.string "{PLAYER} recovered TM28 from\n"
	.string "the TEAM ROCKET GRUNT.$"
#endif

CeruleanCity_Text_BetterGetMovingBye::
#if GERMAN
	.string "Ich gehe wohl besser!\n"
	.string "Tschüss!$"
#else
	.string "I better get moving!\n"
	.string "Bye!$"
#endif

CeruleanCity_Text_MakeRoomForThisCantRun::
#if GERMAN
	.string "Mach Platz in deinem Beutel!\p"
	.string "Ich kann erst gehen, wenn du es\n"
	.string "genommen hast!$"
#else
	.string "Make room for this!\n"
	.string "I can't run until I give it to you!$"
#endif

CeruleanCity_Text_TrainerLifeIsToughIsntIt::
#if GERMAN
	.string "Du bist auch ein Trainer?\p"
	.string "Zu sammeln und zu kämpfen ist nicht\n"
	.string "immer so leicht!$"
#else
	.string "You're a TRAINER, too?\p"
	.string "Collecting, battling…\n"
	.string "It's a tough life, isn't it?$"
#endif

CeruleanCity_Text_YouCanCutDownSmallTrees::
#if GERMAN
	.string "Pokémon können Büsche mit dem\n"
	.string "Zerschneider klein hacken.\p"
	.string "Auch der kleine Baum vor dem Geschäft\n"
	.string "kann entfernt werden.\p"
	.string "Aber es gibt auch einen anderen\n"
	.string "Weg!$"
#else
	.string "Did you know that you can CUT down\n"
	.string "small trees?\p"
	.string "Even that small tree in front of\n"
	.string "the shop can be CUT down.\p"
	.string "I think there's a way around it,\n"
	.string "though.$"
#endif

CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree::
#if GERMAN
	.string "Wenn das Lahmus nicht im Weg wäre,\n"
	.string "könntest du den kleinen Baum fällen.\p"
	.string "Dann könntest du auf die andere\n"
	.string "Seite.\p"
	.string "Aber es gibt auch einen anderen\n"
	.string "Weg!$"
#else
	.string "If that SLOWBRO wasn't there, you\n"
	.string "could CUT down the small tree.\p"
	.string "That way, you could get to the\n"
	.string "other side.\p"
	.string "I think there's a way around it,\n"
	.string "though.$"
#endif

CeruleanCity_Text_PokemonEncyclopediaAmusing::
#if GERMAN
	.string "Du erstellst eine Enzyklopädie der\n"
	.string "Pokémon? Das klingt lustig!$"
#else
	.string "You're making an encyclopedia on\n"
	.string "POKéMON? That sounds amusing.$"
#endif

CeruleanCity_Text_PeopleHereWereRobbed::
#if GERMAN
	.string "Die Leute hier wurden beraubt.\p"
	.string "Das Team Rocket steckt hinter dem\n"
	.string "abscheulichen Verbrechen!\p"
	.string "Sogar die Polizei ist gegen das\n"
	.string "Team Rocket machtlos!$"
#else
	.string "The people here were robbed.\p"
	.string "It's obvious that TEAM ROCKET is\n"
	.string "behind this most heinous crime!\p"
	.string "Even our POLICE FORCE has\n"
	.string "trouble with the ROCKETS!$"
#endif

CeruleanCity_Text_SlowbroUseSonicboom::
#if GERMAN
	.string "O.K.! Lahmus!\n"
	.string "Setze Ultraschall ein!$"
#else
	.string "Okay! SLOWBRO!\n"
	.string "Use SONICBOOM!$"
#endif

CeruleanCity_Text_SlowbroPayAttention::
#if GERMAN
	.string "Los, mach schon, Lahmus!$"
#else
	.string "Come on, SLOWBRO, pay attention!$"
#endif

CeruleanCity_Text_SlowbroPunch::
#if GERMAN
	.string "Lahmus, schlage zu!$"
#else
	.string "SLOWBRO, punch!$"
#endif

CeruleanCity_Text_NoYouBlewItAgain::
#if GERMAN
	.string "Oh nein!\n"
	.string "Wieder nicht...$"
#else
	.string "No!\n"
	.string "You blew it again!$"
#endif

CeruleanCity_Text_SlowbroWithdraw::
#if GERMAN
	.string "Lahmus, Zurück!$"
#else
	.string "SLOWBRO, WITHDRAW!$"
#endif

CeruleanCity_Text_HardToControlMonsObedience::
#if GERMAN
	.string "Nein, nicht!!! Es ist schwer, ein\n"
	.string "Pokémon zu kontrollieren!\p"
	.string "Ob dein Pokémon gehorcht, hängt von\n"
	.string "deinen Fähigkeiten als Trainer ab!$"
#else
	.string "No! That's wrong!\n"
	.string "It's so hard to control POKéMON!\p"
	.string "Your POKéMON's obedience depends\n"
	.string "on your abilities as a TRAINER.$"
#endif

CeruleanCity_Text_SlowbroTookSnooze::
#if GERMAN
	.string "Lahmus macht ein Nickerchen...$"
#else
	.string "SLOWBRO took a snooze…$"
#endif

CeruleanCity_Text_SlowbroLoafingAround::
#if GERMAN
	.string "Lahmus bummelt herum...$"
#else
	.string "SLOWBRO is loafing around…$"
#endif

CeruleanCity_Text_SlowbroTurnedAway::
#if GERMAN
	.string "Lahmus wendet sich ab...$"
#else
	.string "SLOWBRO turned away…$"
#endif

CeruleanCity_Text_SlowbroIgnoredOrders::
#if GERMAN
	.string "Lahmus ignoriert die Befehle...$"
#else
	.string "SLOWBRO ignored orders…$"
#endif

CeruleanCity_Text_WantBrightRedBicycle::
#if GERMAN
	.string "Ich hätte gern ein rotes Fahrrad!\p"
	.string "Aber ich würde nicht damit fahren,\n"
	.string "damit es nicht schmutzig wird!$"
#else
	.string "I want a bright red bicycle.\p"
	.string "I'll keep it at home, so it won't\n"
	.string "get dirty.$"
#endif

CeruleanCity_Text_ThisIsCeruleanCave::
#if GERMAN
	.string "Die Azuria Höhle!\n"
	.string "Dort leben extrem starke Pokémon!\p"
	.string "Nur außergewöhnlichen Trainern\n"
	.string "wird der Zutritt gewährt.\p"
	.string "Du musst stark genug sein, um der\n"
	.string "Pokémon Liga-Champion zu werden!\p"
	.string "Und du solltest bereits Großes\n"
	.string "geleistet haben.$"
#else
	.string "This is CERULEAN CAVE.\p"
	.string "Horribly strong POKéMON live inside\n"
	.string "there.\p"
	.string "It takes a very special TRAINER to\n"
	.string "be allowed inside there.\p"
	.string "You'd have to be strong enough to\n"
	.string "become the POKéMON LEAGUE\l"
	.string "CHAMPION for starters.\p"
	.string "And, you would have to have\n"
	.string "made a great achievement.$"
#endif

CeruleanCity_Text_CitySign::
#if GERMAN
	.string "Azuria City Eine mysteriöse blaue Aura\n"
	.string "umgibt die Stadt!$"
#else
	.string "CERULEAN CITY\n"
	.string "A Mysterious, Blue Aura Surrounds\l"
	.string "It$"
#endif

CeruleanCity_Text_TrainerTipsHeldItems::
#if GERMAN
	.string "Tipps für Trainer\p"
	.string "Einem Pokémon kann ein\n"
	.string "Item zum Halten gegeben werden.\p"
	.string "Manche Items können sogar vom Pokémon\n"
	.string "im Kampf eingesetzt werden.$"
#else
	.string "TRAINER TIPS\p"
	.string "A POKéMON can be made to hold\n"
	.string "an item.\p"
	.string "Some items can even be used by\n"
	.string "the holding POKéMON in battle.$"
#endif

CeruleanCity_Text_BikeShopSign::
#if GERMAN
	.string "Fahrradladen Fahre leicht und schnell\n"
	.string "mit dem Rad durch Höhlen und Gras!$"
#else
	.string "Grass and caves handled easily!\n"
	.string "BIKE SHOP$"
#endif

CeruleanCity_Text_GymSign::
#if GERMAN
	.string "Azuria City Pokémon-Arena\n"
	.string "Arenaleiterin: Misty Die Burschikose\l"
	.string "Meerjungfrau!$"
#else
	.string "CERULEAN CITY POKéMON GYM\n"
	.string "LEADER: MISTY\l"
	.string "The Tomboyish Mermaid!$"
#endif

EventScript_MusicGuy::
    lock
    faceplayer
    giveitem ITEM_MUSIK
    release
    end


CeruleanCity_EventScript_WarpNPC::
    lock
    faceplayer
    gettime
    compare VAR_0x8000, 6
    goto_if_lt CeruleanCity_EventScript_WrongTime
    compare VAR_0x8000, 12
    goto_if_ge CeruleanCity_EventScript_WrongTime
    
    msgbox CeruleanCity_Text_WantToWarp, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq CeruleanCity_EventScript_DoWarp
    msgbox CeruleanCity_Text_DeclinedWarp, MSGBOX_DEFAULT
    release
    end

CeruleanCity_EventScript_WrongTime::
    msgbox CeruleanCity_Text_WrongTime, MSGBOX_DEFAULT
    release
    end

CeruleanCity_EventScript_DoWarp::
    msgbox CeruleanCity_Text_AcceptWarp, MSGBOX_DEFAULT
    closemessage
    warp MAP_LILYCOVE_CITY_HARBOR, 9, 11
    waitstate
    release
    end
CeruleanCity_Text_WrongTime:
    .string "Ahoi, ich fahre am vormittag nach Hoenn.\nWenn du willst, nehme ich dich mit.$"

CeruleanCity_Text_WantToWarp:
    .string "Ahoi, du kommst genau zur Abfahrtszeit.\nWir fahren nach Hoenn. Willst du mit?$"

CeruleanCity_Text_AcceptWarp:
    .string "Dann fahren wir ab!$"

CeruleanCity_Text_DeclinedWarp:
    .string "Vielleicht nächstes Mal.$$"





CeruleanCity_EventScript_WarpJohtoNPC::
    lock
    faceplayer
    gettime
    compare VAR_0x8000, 12
    goto_if_lt CeruleanCity_EventScript_WrongTime_Johto
    compare VAR_0x8000, 14
    goto_if_ge CeruleanCity_EventScript_WrongTime_Johto
    
    msgbox CeruleanCity_Text_WantToWarpJohto, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq CeruleanCity_EventScript_DoWarpJohto
    msgbox CeruleanCity_Text_DeclinedWarpJohto, MSGBOX_DEFAULT
    release
    end

CeruleanCity_EventScript_WrongTime_Johto::
    msgbox CeruleanCity_Text_WrongTime_Johto, MSGBOX_DEFAULT
    release
    end

CeruleanCity_EventScript_DoWarpJohto::
    msgbox CeruleanCity_Text_AcceptWarpJohto, MSGBOX_DEFAULT
    closemessage
    warp MAP_CHERRYGROVE_CITY_HNS, 24, 17
    waitstate
    release
    end
CeruleanCity_Text_WrongTime_Johto:
    .string "Ahoi, wir liefern den Fisch und nehmen\nmittags Passagiere mit nach Johto.$"

CeruleanCity_Text_WantToWarpJohto:
    .string "Ahoi, du kommst genau rechtzeitig. Wir\nfahren nach Johto. Willst du mit?$"

CeruleanCity_Text_AcceptWarpJohto:
    .string "Dann, fahren wir ab!$"

CeruleanCity_Text_DeclinedWarpJohto:
    .string "Vielleicht nächstes Mal..$$"
