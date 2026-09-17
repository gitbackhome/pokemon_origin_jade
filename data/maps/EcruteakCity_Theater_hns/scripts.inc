EcruteakCity_Theater_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_Theater_OnTransition
	.byte 0

EcruteakCity_Theater_OnTransition::
	call_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_MapScript_SetRocketSceneActive
	call_if_eq VAR_ECRUTEAK_CITY_THEATER, 8, EcruteakCity_Theater_MapScript_SetKimonoMovement
	end

EcruteakCity_Theater_MapScript_SetRocketSceneActive::
	setobjectxyperm LOCALID_ECRUTEAK_ZUKI, 10, 2
	setobjectmovementtype LOCALID_ECRUTEAK_ROCKET, MOVEMENT_TYPE_TOWER_BEAM
	return

EcruteakCity_Theater_MapScript_SetKimonoMovement::
	setobjectmovementtype LOCALID_ECRUTEAK_ZUKI, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_NAOKO, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_MIKI, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_SAYO, MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_KUNI, MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_SISTER, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	return

EcruteakCity_Theater_EventScript_RocketEventTrigger::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 60
	turnobject LOCALID_ECRUTEAK_ROCKET, DIR_NORTH
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, EcruteakCity_Theater_Movement_CameraPanUp
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	msgbox EcruteakCity_Theater_Text_KimonoRocket1, MSGBOX_DEFAULT
	closemessage
	msgbox EcruteakCity_Theater_Text_Rocket2, MSGBOX_DEFAULT
	applymovement LOCALID_ECRUTEAK_ZUKI, EcruteakCity_Theater_Movement_KimonoGirlMoveBack
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_Rocket3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ECRUTEAK_ROCKET, EcruteakCity_Theater_Movement_RocketDance
	delay 50
	applymovement OBJ_EVENT_ID_CAMERA, EcruteakCity_Theater_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setobjectmovementtype LOCALID_ECRUTEAK_ROCKET, MOVEMENT_TYPE_TOWER_BEAM
	setobjectxyperm LOCALID_ECRUTEAK_ZUKI, 10, 2
	setvar VAR_ECRUTEAK_CITY_THEATER, 1
	releaseall
	end

EcruteakCity_Theater_Movement_RocketDance:
	walk_in_place_down
	delay_2
	walk_in_place_right
	delay_2
	face_up
	delay_2
	face_left
	delay_8
	walk_in_place_down
	delay_2
	walk_in_place_left
	delay_2
	face_up
	delay_8
	face_right
	step_end

EcruteakCity_Theater_Movement_CameraPanUp:
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

EcruteakCity_Theater_Movement_CameraPanDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

EcruteakCity_Theater_Movement_KimonoGirlMoveBack:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

EcruteakCity_Theater_Text_Rocket1:
#if GERMAN
	.string "Lass endlich dieses langweilige\n"
	.string "Gezappele und leg mal einen\l"
	.string "anständigen Hula aufs Parkett!$"
#else
	.string "ROCKET: Stop dancing such a serious\n"
	.string "dance! Show me something like\l"
	.string "a hula dance!$"
#endif

EcruteakCity_Theater_Text_KimonoRocket1:
#if GERMAN
	.string "Dürfte ich Euch gnädigst darum bitten,\n"
	.string "Eure Zwischenrufe einzustellen?$"
#else
	.string "KIMONO GIRL: ...You mustn't push\n"
	.string "such a request on me.$"
#endif

EcruteakCity_Theater_Text_Rocket2:
#if GERMAN
	.string "Was soll das heißen?\p"
	.string "Hat das Publikum etwa nicht das Recht,\n"
	.string "selbst zu bestimmen, was es sehen will?$"
#else
	.string "ROCKET: Huh?\p"
	.string "Are you telling me you don't\n"
	.string "respect what the customer\l"
	.string "wants?$"
#endif

EcruteakCity_Theater_Text_Rocket3:
#if GERMAN
	.string "Soll ich Euch mal zeigen, wie man das\n"
	.string "richtig macht?\p"
	.string "Mwahahaha!$"
#else
	.string "Well, then I'll show you how\n"
	.string "to dance. I'll show you a\l"
	.string "great one.\p"
	.string "Wahahaha!$"
#endif

EcruteakCity_Theater_EventScript_Rocket::
	lock
	faceplayer
	msgbox EcruteakCity_Theater_Text_RocketSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_33_HNS, EcruteakCity_Theater_Text_RocketBeaten
	msgbox EcruteakCity_Theater_Text_RocketAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ECRUTEAK_ROCKET, EcruteakCity_Theater_Movement_RocketLeave
	waitmovement 0
	setflag FLAG_HIDE_ECRUTEAK_ROCKET
	removeobject LOCALID_ECRUTEAK_ROCKET
	call_if_eq VAR_FACING, DIR_EAST, EcruteakCity_Theater_EventScript_PostRocketLeft
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_Theater_EventScript_PostRocketRight
	call_if_eq VAR_FACING, DIR_SOUTH, EcruteakCity_Theater_EventScript_PostRocketTop
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox EcruteakCity_Theater_Text_KimonoRocket3, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ECRUTEAK_CITY_THEATER, 2
	release
	end

EcruteakCity_Theater_EventScript_PostRocketLeft::
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkDown1
	waitmovement 0
	return

EcruteakCity_Theater_EventScript_PostRocketRight::
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkRight1
	waitmovement 0
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkDown1
	waitmovement 0
	return

EcruteakCity_Theater_EventScript_PostRocketTop::
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

EcruteakCity_Theater_Movement_RocketLeave:
	jump_2_down
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

EcruteakCity_Theater_Text_RocketSeen:
#if GERMAN
	.string "Hä? Was soll das werden?\p"
	.string "Stellst du dich mir etwa in den Weg?$"
#else
	.string "Huh? Who are you?\n"
	.string "You dare to get in my way?$"
#endif

EcruteakCity_Theater_Text_RocketBeaten:
#if GERMAN
	.string "Hm, ich bin wohl doch nur ein\n"
	.string "Schmalspurganove…$"
#else
	.string "Oh, no!\n"
	.string "You make me look like a\l"
	.string "villain!$"
#endif

EcruteakCity_Theater_Text_RocketAfter:
#if GERMAN
	.string "…Oh nein! Ich habe ganz vergessen, dass\n"
	.string "wir gleich mit der Durchführung unseres\l"
	.string "teuflischen Plans beginnen!\p"
	.string "Wenn herauskommt, dass ich hier\n"
	.string "faulenze und alles aufhalte, lassen die\l"
	.string "mich glatt wieder ganz unten als\l"
	.string "Schuhputzer anfangen!\p"
	.string "Ich muss hier auf der Stelle weg!$"
#else
	.string "Oops! I have an important mission!\n"
	.string "If they find out I was wasting\l"
	.string "time here, they'll make me start\l"
	.string "over as the lowest ROCKET GRUNT!\p"
	.string "I better leave now!$"
#endif

EcruteakCity_Theater_Text_KimonoRocket3:
#if GERMAN
	.string "Ihr seid {PLAYER}, nicht wahr?\n"
	.string "Das war wirklich beeindruckend.\p"
	.string "Ihr seid gutmütig und stark und Ihr\n"
	.string "versteht Euch ausgezeichnet im\l"
	.string "Training von Pokémon.\p"
	.string "Ich wusste einfach, dass ich mich in\n"
	.string "Euch nicht getäuscht hatte. Hohoho!\p"
	.string "Aber ich führe wieder Selbstgespräche!\n"
	.string "Hört mir am besten einfach nicht zu!$"
#else
	.string "You must be {PLAYER},\n"
	.string "correct? That was indeed\l"
	.string "excellent.\p"
	.string "Kind and strong... Good at\n"
	.string "raising POKéMON as well...\p"
	.string "That person does know what\n"
	.string "to look for in people...\p"
	.string "Ohoho! That was just me\n"
	.string "talking to myself.\l"
	.string "Never mind.$"
#endif


EcruteakCity_Theater_EventScript_KimonoGirl::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 6, EcruteakCity_Theater_EventScript_KimonoGirlDuringEvent
	msgbox EcruteakCity_Theater_Text_KimonoDone, MSGBOX_DEFAULT
	closemessage
	release
	end
EcruteakCity_Theater_EventScript_KimonoGirlDuringEvent::
	msgbox EcruteakCity_Theater_Text_KimonoGirlsBeforeBattle, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_Theater_EventScript_Zuki::
	lock
	faceplayer
	goto_if_ge VAR_ECRUTEAK_CITY_THEATER, 8, EcruteakCity_Theater_EventScript_ZukiAfterLegendary
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 6, EcruteakCity_Theater_EventScript_ZukiBattle
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_ZukiDuringRocket
	msgbox EcruteakCity_Theater_Text_Kimono, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_ZukiAfterLegendary::
	msgbox EcruteakCity_Theater_Text_ZukiAfterAll, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_ZukiDuringRocket::
	msgbox EcruteakCity_Theater_Text_KimonoGirlBeaten, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_Text_Kimono:
#if GERMAN
	.string "Wir Kimono-Girls leben für den Tanz.\n"
	.string "Wir haben noch keine Probe verpasst.\l"
	.string "Dasselbe gilt auch für unsere Pokémon!\p"
	.string "Wir nehmen uns täglich viel Zeit für sie\n"
	.string "und achten darauf, dass sie langsam,\l"
	.string "aber sicher an ihrem Training wachsen.$"
#else
	.string "For KIMONO GIRLS like me,\n"
	.string "dancing is everything.\p"
	.string "I have never gone a day\n"
	.string "without a dance practice.\p"
	.string "POKéMON are the same.\n"
	.string "They grow with you little\l"
	.string "by little each day.$"
#endif

EcruteakCity_Theater_EventScript_SurfGuy::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_SurfGuyDuringRocket
	goto_if_unset FLAG_RECEIVED_HM_SURF, EcruteakCity_Theater_EventScript_SurfGuy_GiveSurf
	msgbox EcruteakCity_Theater_Text_SurfGuyAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_SurfGuy_GiveSurf::
	@ Origin Jade: Wer aus Kanto kommt, hat den Surfer laengst.
	checkitem ITEM_HM_SURF
	call_if_eq VAR_RESULT, TRUE, EcruteakCity_Theater_EventScript_SurfGuyHasSurf
	call_if_eq VAR_RESULT, FALSE, EcruteakCity_Theater_EventScript_SurfGuyGivesSurf
	setflag FLAG_RECEIVED_HM_SURF
	closemessage
	setflag FLAG_RECEIVED_HM_SURF
	setvar VAR_ECRUTEAK_CITY_THEATER, 3
	release
	end

EcruteakCity_Theater_EventScript_SurfGuyGivesSurf::
	msgbox EcruteakCity_Theater_Text_SurfGuyGiveSurf, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	msgbox EcruteakCity_Theater_Text_SurfGuyGaveSurf
	return

EcruteakCity_Theater_EventScript_SurfGuyHasSurf::
	msgbox EcruteakCity_Theater_Text_SurfGuyHasSurf, MSGBOX_DEFAULT
	giveitem ITEM_MYSTIC_WATER
	return

EcruteakCity_Theater_EventScript_SurfGuyDuringRocket::
	msgbox EcruteakCity_Theater_Text_SurfGuyRocket, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_TriggerSurfGuy::
	lock
	applymovement LOCALID_SURF_GUY, EcruteakCity_Theater_Movement_SurfGuy1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	@ Origin Jade: Wer aus Kanto kommt, hat den Surfer laengst.
	checkitem ITEM_HM_SURF
	call_if_eq VAR_RESULT, TRUE, EcruteakCity_Theater_EventScript_SurfGuyHasSurf
	call_if_eq VAR_RESULT, FALSE, EcruteakCity_Theater_EventScript_SurfGuyGivesSurf
	setflag FLAG_RECEIVED_HM_SURF
	closemessage
	setflag FLAG_RECEIVED_HM_SURF
	setvar VAR_ECRUTEAK_CITY_THEATER, 3
	applymovement LOCALID_SURF_GUY, EcruteakCity_Theater_Movement_SurfGuy2
	waitmovement 0
	release
	end

EcruteakCity_Theater_EventScript_Psyduck::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	msgbox EcruteakCity_Theater_Text_Psyduck, MSGBOX_DEFAULT
	waitmoncry
	release
	end


EcruteakCity_Theater_EventScript_Boy::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_BoyDuringRocket
	msgbox EcruteakCity_Theater_Text_Boy, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_BoyDuringRocket::
	msgbox EcruteakCity_Theater_Text_BoyBefore, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_Theater_EventScript_Granny::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_GrannyDuringRocket
	msgbox EcruteakCity_Theater_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_GrannyDuringRocket::
	msgbox EcruteakCity_Theater_Text_GrannyBefore, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_Theater_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_GrampsDuringRocket
	msgbox EcruteakCity_Theater_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_GrampsDuringRocket::
	msgbox EcruteakCity_Theater_Text_GrampsBefore, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_Girl::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_GirlDuringRocket
	msgbox EcruteakCity_Theater_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_GirlDuringRocket::
	msgbox EcruteakCity_Theater_Text_GirlBefore, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_FancyPanel::
	lock
	msgbox EcruteakCity_Theater_Text_FancyPanel, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_Movement_SurfGuy1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

EcruteakCity_Theater_Movement_SurfGuy2:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EcruteakCity_Theater_Text_SurfGuyRocket:
#if GERMAN
	.string "Was bildet sich dieser Kerl von\n"
	.string "Team Rocket eigentlich ein?!?\p"
	.string "Meinem Kimono-Girl solchen Ärger zu\n"
	.string "bereiten!\p"
	.string "Du bist doch ein Trainer, oder?\n"
	.string "Dann rette sie gefälligst!$"
#else
	.string "What's the deal with that\n"
	.string "Team Rocket Grunt, messing\l"
	.string "with that KIMONO GIRL?\p"
	.string "You are a Trainer, right?\n"
	.string "Please help her!$"
#endif

EcruteakCity_Theater_Text_SurfGuyGiveSurf:
#if GERMAN
	.string "Das war wirklich meisterhaft!\p"
	.string "Beherzte junge Leute wie dich\n"
	.string "sieht man nicht alle Tage!\p"
	.string "Hier, das ist ein kleines Dankeschön.\n"
	.string "Nur mal keine falsche Bescheidenheit!\l"
	.string "Nimm es ruhig an!$"
#else
	.string "Wonderful! You were so\n"
	.string "courageous for your age!\p"
	.string "It was a rare sight to see!\n"
	.string "I want you to have this.\p"
	.string "Don't be shy--take it!$"
#endif

EcruteakCity_Theater_Text_SurfGuyGaveSurf:
#if GERMAN
	.string "Die Attacke darin nennt sich Surfer.\n"
	.string "Damit bretterst du mit deinen Pokémon\l"
	.string "in Windeseile über die Wellen!$"
#else
	.string "That's SURF.\n"
	.string "It's a move that lets POKéMON\l"
	.string "swim across water with ease.$"
#endif

EcruteakCity_Theater_Text_SurfGuyAfter:
#if GERMAN
	.string "Die Kimono-Girls sind nicht nur sehr\n"
	.string "talentierte Tänzerinnen, sondern auch\l"
	.string "herausragende Pokémon-Trainer!\p"
	.string "Sie stellen ihre Kampffähigkeiten bloß\n"
	.string "nicht so oft zur Schau…\p"
	.string "Aber wenn die Kimono-Girls richtig Ernst\n"
	.string "machen, bleibt kein Auge trocken!\p"
	.string "Du wirst auch deine Probleme damit\n"
	.string "haben, sie zu besiegen…$"
#else
	.string "Not only are the KIMONO GIRLS\n"
	.string "great dancers, they're also\l"
	.string "skilled at POKéMON.\p"
	.string "But they battle only for good\n"
	.string "reasons.\p"
	.string "I don't know if you could beat\n"
	.string "them if they showed their skill...$"
#endif

EcruteakCity_Theater_Text_Psyduck:
#if GERMAN
	.string "Enton: E-enton!$"
#else
	.string "PSYDUCK: Dau dau!$"
#endif

EcruteakCity_Theater_Text_BoyBefore:
#if GERMAN
	.string "Ahhhh!$"
#else
	.string "Eeeeek!$"
#endif

EcruteakCity_Theater_Text_Boy:
#if GERMAN
	.string "A-aus und vorbei!\p"
	.string "Das war meine Chance, ein Kimono-Girl\n"
	.string "näher kennenzulernen…$"
#else
	.string "I was supposed to be the hero...!\n"
	.string "So much for getting close to\l"
	.string "a KIMONO GIRL!$"
#endif

EcruteakCity_Theater_Text_Granny:
#if GERMAN
	.string "Dieser Mann hat immer sein Enton dabei!\p"
	.string "Er meinte mal, er wolle einem Pokémon,\n"
	.string "das die Attacke Surfer beherrscht,\l"
	.string "gerne das Tanzen beibringen.\p"
	.string "Wart’s ab, als Nächstes bringt er ihm\n"
	.string "dann bestimmt Synchronschwimmen bei!$"
#else
	.string "That man's always with his\n"
	.string "PSYDUCK.\p"
	.string "Says he wants a POKéMON that\n"
	.string "can SURF and dance.\p"
	.string "Is he trying to make a POKéMON\n"
	.string "that stars in synchronized\l"
	.string "swimming?$"
#endif

EcruteakCity_Theater_Text_GrannyBefore:
#if GERMAN
	.string "Hnnngh…\p"
	.string "Wenn ich nur nicht solches Bauchweh\n"
	.string "hätte, würde ich diesem Typen schon\l"
	.string "Manieren beibringen!$"
#else
	.string "Oh... Ouch...!\n"
	.string "This stomachache!\p"
	.string "I wouldn't let this guy act like\n"
	.string "that if not for this pain...!$"
#endif

EcruteakCity_Theater_Text_Gramps:
#if GERMAN
	.string "Die Kimono-Girls sind echt hübsch…\p"
	.string "Aber wenn man vor Publikum auftreten\n"
	.string "möchte, muss man erst mal ein sehr\l"
	.string "hartes Training absolvieren!\p"
	.string "Na ja, aber was tut man nicht alles\n"
	.string "für seinen Traumberuf?$"
#else
	.string "The KIMONO GIRLS are so\n"
	.string "beautiful...\p"
	.string "But they have to go through\n"
	.string "rigorous training.\p"
	.string "And they have to learn to follow\n"
	.string "customs before appearing in\l"
	.string "public.\p"
	.string "But if you love something,\n"
	.string "anything is possible.$"
#endif

EcruteakCity_Theater_Text_GrampsBefore:
#if GERMAN
	.string "Hnnngh…\p"
	.string "Würde mir meine Hüfte nur nicht so übel\n"
	.string "mitspielen, würde ich diesem Typen\l"
	.string "schon Manieren beibringen!$"
#else
	.string "Oh... Ouch...!\n"
	.string "This back pain!\p"
	.string "I wouldn't let this guy act like\n"
	.string "that if not for this pain...!$"
#endif

EcruteakCity_Theater_Text_Girl:
#if GERMAN
	.string "Die Kimono-Girls sind meine großen\n"
	.string "Schwestern! Ich werde eines Tages wie\l"
	.string "sie sein!$"
#else
	.string "The KIMONO GIRLS are my big\n"
	.string "sisters! I'll be like them one\l"
	.string "day!$"
#endif

EcruteakCity_Theater_Text_GirlBefore:
#if GERMAN
	.string "Ich mag diesen lustigen Tanz!$"
#else
	.string "I like that funny dance!$"
#endif

EcruteakCity_Theater_Text_FancyPanel:
#if GERMAN
	.string "Das ist ein schickes Panel, das mit\n"
	.string "Blumen verziert ist.$"
#else
	.string "It's a fancy panel that's\n"
	.string "decorated with flowers.$"
#endif

EcruteakCity_Theater_Trigger_PreBattleCutsceneLeft::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, EcruteakCity_Theater_Movement_PlayerWalkToZukiLeft
	applymovement2 OBJ_EVENT_ID_FOLLOWER, EcruteakCity_Theater_Movement_MonWalkToZukiLeft
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto EcruteakCity_Theater_EventScript_LegendaryCutscene

EcruteakCity_Theater_Trigger_PreBattleCutsceneTop::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, EcruteakCity_Theater_Movement_PlayerWalkToZukiTop
	applymovement2 OBJ_EVENT_ID_FOLLOWER, EcruteakCity_Theater_Movement_MonWalkToZukiTop
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto EcruteakCity_Theater_EventScript_LegendaryCutscene

EcruteakCity_Theater_Trigger_PreBattleCutsceneRight::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, EcruteakCity_Theater_Movement_PlayerWalkToZukiRight
	applymovement2 OBJ_EVENT_ID_FOLLOWER, EcruteakCity_Theater_Movement_MonWalkToZukiRight
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto EcruteakCity_Theater_EventScript_LegendaryCutscene


EcruteakCity_Theater_Movement_PlayerWalkToZukiLeft:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end
EcruteakCity_Theater_Movement_MonWalkToZukiLeft:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

EcruteakCity_Theater_Movement_PlayerWalkToZukiTop:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end
EcruteakCity_Theater_Movement_MonWalkToZukiTop:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

EcruteakCity_Theater_Movement_PlayerWalkToZukiRight:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end
EcruteakCity_Theater_Movement_MonWalkToZukiRight::
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end


EcruteakCity_Theater_Movement_KimonoSpin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	step_end

EcruteakCity_Theater_EventScript_LugiaBuffer::
	bufferspeciesname STR_VAR_1, SPECIES_LUGIA
	return
EcruteakCity_Theater_EventScript_HoohBuffer::
	bufferspeciesname STR_VAR_1, SPECIES_HO_OH
	return
EcruteakCity_Theater_EventScript_LegendaryCutscene::
	call_if_eq VAR_LUGIA_OR_HOOH, 1, EcruteakCity_Theater_EventScript_LugiaBuffer
	call_if_eq VAR_LUGIA_OR_HOOH, 2, EcruteakCity_Theater_EventScript_HoohBuffer
	msgbox EcruteakCity_Theater_Text_ZukiSeen, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ECRUTEAK_ZUKI, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 6
EcruteakCity_Theater_EventScript_ZukiBattle::
	msgbox EcruteakCity_Theater_Text_ZukiSeenAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, EcruteakCity_Theater_EventScript_LegendaryDenied
	call_if_eq VAR_FACING, DIR_SOUTH, EcruteakCity_Theater_Movement_SouthCorrection
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_Theater_Movement_WestCorrection
	call_if_eq VAR_FACING, DIR_EAST, EcruteakCity_Theater_Movement_EastCorrection
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 1, 2, 0, 0
	trainerbattle_no_intro TRAINER_ZUKI_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement2 LOCALID_ECRUTEAK_ZUKI, EcruteakCity_Theater_Movement_ZukiWalkUp
	waitmovement 0
EcruteakCity_Theater_EventScript_NaokoBattle::
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ECRUTEAK_NAOKO, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement2 LOCALID_ECRUTEAK_NAOKO, EcruteakCity_Theater_Movement_NaokoWalkToPlayer
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_NaokoSeen, MSGBOX_DEFAULT
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 1, 0, 1, 1, 0
	trainerbattle_no_intro TRAINER_NAOKO_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement2 LOCALID_ECRUTEAK_NAOKO, EcruteakCity_Theater_Movement_NaokoWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_MikiBattle::
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ECRUTEAK_MIKI, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement2 LOCALID_ECRUTEAK_MIKI, EcruteakCity_Theater_Movement_MikiWalkToPlayer
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_MikiSeen, MSGBOX_DEFAULT
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 1, 2, 0
	trainerbattle_no_intro TRAINER_MIKI_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement2 LOCALID_ECRUTEAK_MIKI, EcruteakCity_Theater_Movement_MikiWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_SayoBattle::
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ECRUTEAK_SAYO, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement2 LOCALID_ECRUTEAK_SAYO, EcruteakCity_Theater_Movement_SayoWalkToPlayer
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_SayoSeen, MSGBOX_DEFAULT
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 2, 1, 0, 0
	trainerbattle_no_intro TRAINER_SAYO_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement2 LOCALID_ECRUTEAK_SAYO, EcruteakCity_Theater_Movement_SayoWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_KuniBattle::
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ECRUTEAK_KUNI, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement2 LOCALID_ECRUTEAK_KUNI, EcruteakCity_Theater_Movement_KuniWalkToPlayer
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_KuniSeen, MSGBOX_DEFAULT
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 0, 0, 1, 0
	trainerbattle_no_intro TRAINER_KUNI_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement2 LOCALID_ECRUTEAK_KUNI, EcruteakCity_Theater_Movement_KuniWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_BeatGauntlet::
	applymovement2 LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkDown1
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_ZukiDone, MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, EcruteakCity_Theater_EventScript_Lugia
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, EcruteakCity_Theater_EventScript_Hooh

	EcruteakCity_Theater_Movement_SouthCorrection::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

	EcruteakCity_Theater_Movement_WestCorrection::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

	EcruteakCity_Theater_Movement_EastCorrection::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

EcruteakCity_Theater_EventScript_Lugia::
	giveitem ITEM_TIDAL_BELL
	closemessage
	playse SE_M_RAZOR_WIND
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	addobject LOCALID_ECRUTEAK_SISTER
	applymovement2 LOCALID_ECRUTEAK_SISTER, EcruteakCity_Theater_Movement_Sister
	waitmovement 0
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_WEST
	msgbox EcruteakCity_Theater_Text_GirlLugia, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ECRUTEAK_ZUKI
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	msgbox EcruteakCity_Theater_Text_ZukiLugia, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK

	removeobject LOCALID_ECRUTEAK_ZUKI
	removeobject LOCALID_ECRUTEAK_MIKI
	removeobject LOCALID_ECRUTEAK_NAOKO
	removeobject LOCALID_ECRUTEAK_KUNI
	removeobject LOCALID_ECRUTEAK_SAYO
	removeobject LOCALID_ECRUTEAK_MIKI

	removeobject LOCALID_ECRUTEAK_SISTER
	playse SE_EXIT
	delay 120
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setvar VAR_COMPLETED_LUGIA, 2
	setvar VAR_COMPLETED_HO_OH, 3
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setvar VAR_NEWBARKTOWN_LABSTATE, 9
	setvar VAR_ECRUTEAK_CITY_THEATER, 7
	release
	end
EcruteakCity_Theater_EventScript_Hooh::
	giveitem ITEM_CLEAR_BELL
	closemessage
	playse SE_M_RAZOR_WIND
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	addobject LOCALID_ECRUTEAK_SISTER
	applymovement2 LOCALID_ECRUTEAK_SISTER, EcruteakCity_Theater_Movement_Sister
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_GirlHooh, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ECRUTEAK_ZUKI
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	msgbox EcruteakCity_Theater_Text_ZukiHooh, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK

	removeobject LOCALID_ECRUTEAK_ZUKI
	removeobject LOCALID_ECRUTEAK_MIKI
	removeobject LOCALID_ECRUTEAK_NAOKO
	removeobject LOCALID_ECRUTEAK_KUNI
	removeobject LOCALID_ECRUTEAK_SAYO
	removeobject LOCALID_ECRUTEAK_MIKI

	removeobject LOCALID_ECRUTEAK_SISTER
	playse SE_EXIT
	delay 120
	fadescreenswapbuffers FADE_FROM_BLACK

	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setvar VAR_COMPLETED_HO_OH, 2
	setvar VAR_COMPLETED_LUGIA, 3
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setvar VAR_NEWBARKTOWN_LABSTATE, 9
	setvar VAR_ECRUTEAK_CITY_THEATER, 7
	release
	end

EcruteakCity_Theater_Movement_Sister:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_right
	step_end

EcruteakCity_Theater_EventScript_LegendaryDenied::
	msgbox EcruteakCity_Theater_Text_ZukiNo, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_Movement_ZukiWalkUp:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end
EcruteakCity_Theater_Movement_NaokoWalkToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end
EcruteakCity_Theater_Movement_NaokoWalkBack:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end
EcruteakCity_Theater_Movement_MikiWalkToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end
EcruteakCity_Theater_Movement_MikiWalkBack:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

EcruteakCity_Theater_Movement_SayoWalkToPlayer:
	walk_down
	walk_right
	walk_right
	walk_right
	face_down
	step_end
EcruteakCity_Theater_Movement_SayoWalkBack:
	walk_left
	walk_left
	walk_left
	walk_up
	face_down
	step_end

EcruteakCity_Theater_Movement_KuniWalkToPlayer:
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end
EcruteakCity_Theater_Movement_KuniWalkBack:
	walk_right
	walk_right
	walk_right
	walk_up
	face_down
	step_end

EcruteakCity_Theater_Text_KimonoGirlBeaten:
#if GERMAN
	.string "…$"
#else
	.string "...$"
#endif

EcruteakCity_Theater_Text_ZukiSeen:
#if GERMAN
	.string "Guten Tag! Ich darf mich vorstellen…\n"
	.string "Ich bin Tamao, eines der Kimono-Girls.\p"
	.string "Wir hatten bereits in Viola City das\n"
	.string "Vergnügen, nicht wahr?\p"
	.string "Nur jemand, der über ein aufrichtiges\n"
	.string "Herz und ein Händchen im Umgang mit\l"
	.string "Pokémon verfügt, kann Ho-Oh rufen.\p"
	.string "Die richtige Person lässt sich daran\n"
	.string "erkennen, dass sie das Rätsel-Ei bei\l"
	.string "sich trägt, wenn sie hier auftaucht.\p"
	.string "Ich habe Mr. Pokémon bereits im Vorfeld\n"
	.string "aufgetragen, es dem Richtigen zu geben.\p"
	.string "Und genau dieses Ei ist Euch über\n"
	.string "Professor Lind in die Hände gefallen!\p"
	.string "Ein reines Herz alleine führt Euch in\n"
	.string "einem Pokémon-Kampf aber noch längst\l"
	.string "nicht zum Sieg!\p"
	.string "Ihr müsst auch genau wissen, wie Ihr\n"
	.string "Euer Pokémon-Team anzupacken habt!\p"
	.string "Und nun lasst mich bitte überprüfen, ob\n"
	.string "Ihr diese Fähigkeit tatsächlich besitzt!\p"
	.string "Seid Ihr bereit?$"
#else
	.string "Welcome. My name is ZUKI.\n"
	.string "I met you previously in VIOLET\l"
	.string "CITY.\p"
	.string "To bring back {STR_VAR_1}, we\n"
	.string "needed someone with the right bond\l"
	.string "with POKéMON.\p"
	.string "We asked MR. POKéMON to give this\n"
	.string "MYSTERY EGG to\l"
	.string "whoever showed potential.\p"
	.string "The EGG went from MR. POKéMON\n"
	.string "to PROF.ELM, then to you.\p"
	.string "But being pure alone is not enough\n"
	.string "to face the power of this POKéMON.$"
#endif

EcruteakCity_Theater_Text_ZukiSeenAgain:
#if GERMAN
	.string "Ihr müsst genau wissen, wie Ihr Euer\n"
	.string "Pokémon-Team anzupacken habt!\p"
	.string "Und nun lasst mich bitte überprüfen, ob\n"
	.string "Ihr diese Fähigkeit tatsächlich besitzt!\p"
	.string "Seid Ihr bereit?$"
#else
	.string "I will test you to see if you are\n"
	.string "a good Trainer.\p"
	.string "Are you ready, {PLAYER}?$"
#endif

EcruteakCity_Theater_Text_ZukiNo:
#if GERMAN
	.string "Sehr wohl. Dann werde ich hier auf Euch\n"
	.string "warten, bis Ihr bereit seid.$"
#else
	.string "That is fine...\n"
	.string "I will wait for you to get\l"
	.string "ready.$"
#endif

EcruteakCity_Theater_Text_NaokoSeen:
#if GERMAN
	.string "Du bist sehr stark. Du hast mir im\n"
	.string "Steineichenwald geholfen.\p"
	.string "Ich heiße Edith. Ich habe keine\n"
	.string "so gute Orientierung.\p"
	.string "Ich sah, wie du Team Rocket besiegt\n"
	.string "hast, als Kurt am Flegmon-Brunnen in\l"
	.string "Not war.\p"
	.string "Lass mich dich und deine Pokémon\n"
	.string "herausfordern!$"
#else
	.string "You are quite strong. You helped\n"
	.string "me in the ILEX FOREST.\p"
	.string "I'm NAOKO--not so good with\n"
	.string "directions.\p"
	.string "I saw you defeat Team Rocket\n"
	.string "when KURT was in trouble at\l"
	.string "the SLOWPOKE WELL.\p"
	.string "Let me challenge you and your\n"
	.string "POKéMON!$"
#endif

EcruteakCity_Theater_Text_MikiSeen:
#if GERMAN
	.string "Ihr habt Team Rocket vertrieben.\n"
	.string "Das war sehr gute Arbeit.\p"
	.string "Aber Ihr seid Euch hoffentlich bewusst,\n"
	.string "welch ein vortrefflicher Gegner ich bin!\p"
	.string "Ihr solltet niemals die Waffen einer\n"
	.string "Frau unterschätzen!\p"
	.string "Ich bin Satsuki von den Kimono-Girls.\p"
	.string "Und nun lasst uns kämpfen!$"
#else
	.string "You're quite the Trainer. I\n"
	.string "remember you chased off that\l"
	.string "Rocket Grunt from right here.\p"
	.string "Thank you for that.\p"
	.string "Though, I'm a Trainer too.\n"
	.string "She who knows the most speaks\l"
	.string "the least!\p"
	.string "I am MIKI--the KIMONO GIRL!\p"
	.string "Let me challenge you and your\n"
	.string "POKéMON!$"
#endif

EcruteakCity_Theater_Text_SayoSeen:
#if GERMAN
	.string "Guter Kampfgeist! Du hast mich\n"
	.string "vom Eis gestoßen.\p"
	.string "Ich laufe in Sandalen.\n"
	.string "Ich bin Keiko, das Kimono-Girl!\p"
	.string "Ich hörte zu in der Drachenhöhle, als du\n"
	.string "den Test des Ältesten bestanden hast.\p"
	.string "Lass mich dich und deine Pokémon\n"
	.string "herausfordern!$"
#else
	.string "Excellent spirit! You got me\n"
	.string "off the ice by pushing me.\p"
	.string "I skate in sandals.\n"
	.string "I am SAYO--the KIMONO GIRL!\p"
	.string "I listened in the DRAGON'S DEN\n"
	.string "when you passed the Elder's test.\p"
	.string "Let me challenge you and your\n"
	.string "POKéMON!$"
#endif

EcruteakCity_Theater_Text_KuniSeen:
#if GERMAN
	.string "Ich bin die Letzte.\p"
	.string "Du warst zuverlässig im Dukatia-Tunnel.\p"
	.string "Ich tanze auch unterirdisch…\n"
	.string "Hussa!\p"
	.string "Ich sah, wie du Rocket am\n"
	.string "Radioturm-Auftrag gehindert hast.\p"
	.string "Zeig mir jetzt deine Stärke!\n"
	.string "Lass mich dich und deine Pokémon\l"
	.string "herausfordern!$"
#else
	.string "I'm the last one.\p"
	.string "You were dependable at the\n"
	.string "GOLDENROD TUNNEL.\p"
	.string "I'm the one who twirls even\n"
	.string "underground--KUNI!\p"
	.string "I saw you thwart Rocket's\n"
	.string "plan to take the Radio Tower.\p"
	.string "Now show me your strength!\n"
	.string "Let me challenge you and your\l"
	.string "POKéMON!$"
#endif

EcruteakCity_Theater_Text_ZukiDone:
#if GERMAN
	.string "Wir haben uns in Euch nicht getäuscht.\n"
	.string "Ihr seid wahrlich würdig, dies zu\l"
	.string "besitzen…\p"
	.string "Bitte empfangt unsere Gabe!$"
#else
	.string "We were not wrong about you.\n"
	.string "You are indeed worthy of this...\p"
	.string "Please take it.$"
#endif

EcruteakCity_Theater_Text_GirlHooh:
#if GERMAN
	.string "Hört mir alle zu!\p"
	.string "Der Schatten eines riesigen Pokémon ist\n"
	.string "über dem Glockenturm erschienen!\p"
	.string "Könnte das etwa…$"
#else
	.string "Big sisters! I just saw the\n"
	.string "big shadow of a POKéMON over\l"
	.string "the TIN TOWER!\p"
	.string "It could be...$"
#endif

EcruteakCity_Theater_Text_GirlLugia:
#if GERMAN
	.string "Hört mir alle zu!\p"
	.string "Der Umriss eines riesigen Pokémon wurde\n"
	.string "bei den Strudelinseln gesichtet!\p"
	.string "Das wird doch nicht etwa…$"
#else
	.string "Big sisters! I just saw the\n"
	.string "big shadow of a POKéMON in the\l"
	.string "WHIRL ISLANDS' waters!\p"
	.string "It could be...$"
#endif

EcruteakCity_Theater_Text_ZukiHooh:
#if GERMAN
	.string "Tamao: Nun denn, {PLAYER}!\n"
	.string "Wir eilen schon einmal vor Euch zum\l"
	.string "Glockenturm!$"
#else
	.string "ZUKI: {PLAYER}!\n"
	.string "We'll be at the TIN TOWER.\n"
	.string "See you there!$"
#endif

EcruteakCity_Theater_Text_ZukiLugia:
#if GERMAN
	.string "Tamao: Nun denn, {PLAYER}!\n"
	.string "Wir eilen schon einmal vor Euch zu den\l"
	.string "Strudelinseln!$"
#else
	.string "ZUKI: {PLAYER}!\n"
	.string "We'll be at the WHIRL ISLANDS.\l"
	.string "See you there!$"
#endif

EcruteakCity_Theater_Text_KimonoDone:
#if GERMAN
	.string "Wir stecken mitten in den Tanzproben!$"
#else
	.string "We are rehearsing a dance.$"
#endif

EcruteakCity_Theater_Text_ZukiAfterAll:
#if GERMAN
	.string "Danke für deine Hilfe neulich.\p"
	.string "Du hast gezeigt, dass Menschen\n"
	.string "mit Pokémon eine Bindung aufbauen…\p"
	.string "Wir schätzen es, dass du unsere\n"
	.string "Hoffnungen erfüllt hast, {PLAYER}!\p"
	.string "Wenn du daraus etwas gelernt hast,\n"
	.string "dank Mr. Pokémon und Prof. Lind..$"
#else
	.string "Thank you for your help the\n"
	.string "other day.\p"
	.string "You've shown the bond between\n"
	.string "people can grow with POKéMON...\p"
	.string "We appreciate how you lived up\n"
	.string "to our hopes, {PLAYER}!\p"
	.string "If you learned anything from\n"
	.string "this, thank MR. POKéMON and\l"
	.string "PROF.ELM...$"
#endif

EcruteakCity_Theater_Text_KimonoGirlsBeforeBattle:
#if GERMAN
	.string "Wenn Ihr bereit seid, dann sprecht\n"
	.string "bitte mit Tamao in der Mitte.$"
#else
	.string "Talk to ZUKI in the middle\n"
	.string "when you are ready.$"
#endif


EcruteakCity_Theater_Text_SurfGuyHasSurf:
#if GERMAN
	.string "Den Surfer wolltest du sicher haben.\p"
	.string "Du hast ihn. Schon lange, dem Blick\n"
	.string "nach zu urteilen.\p"
	.string "Dann etwas anderes: Das hier stammt\n"
	.string "aus dem Brunnen unter dem Theater.\p"
	.string "Es macht Wasser nicht nass. Es macht\n"
	.string "es ernst.$"
#else
	.string "I suppose you came for SURF.\p"
	.string "You have it. For a long while, by the\n"
	.string "look of you.\p"
	.string "Something else, then. This comes from\n"
	.string "the well beneath the theater.\p"
	.string "It doesn't make water wet. It makes it\n"
	.string "mean business.$"
#endif
