.equ SIGN_LADY_READY, VAR_TEMP_2

PalletTown_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_OnFrame
	.byte 0

PalletTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
	call_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_TryReadySignLady
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 0, PalletTown_EventScript_SetSignLadyPos
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, PalletTown_EventScript_SetSignLadyDone
	end

PalletTown_EventScript_TryReadySignLady::
	goto_if_unset FLAG_OPENED_START_MENU, Common_EventScript_NopReturn
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, Common_EventScript_NopReturn
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	return

PalletTown_EventScript_SetSignLadyDone::
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2
	return

PalletTown_EventScript_SetSignLadyPos::
	goto_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_MoveSignLadyToRouteEntrance
	setobjectxyperm LOCALID_PALLET_SIGN_LADY, 5, 15
	setobjectmovementtype LOCALID_PALLET_SIGN_LADY, MOVEMENT_TYPE_FACE_UP
	return

PalletTown_EventScript_MoveSignLadyToRouteEntrance::
	setobjectxyperm LOCALID_PALLET_SIGN_LADY, 12, 2
	setobjectmovementtype LOCALID_PALLET_SIGN_LADY, MOVEMENT_TYPE_FACE_DOWN
	setvar SIGN_LADY_READY, TRUE
	return

PalletTown_OnFrame::
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_OAK, 2, PalletTown_EventScript_OakRatingScene
	.2byte 0

@ Oak approaches player after exiting their house post Elite Four to check if they should receieve the National Dex
PalletTown_EventScript_OakRatingScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	setobjectxyperm LOCALID_PALLET_PROF_OAK, 14, 14
	setobjectmovementtype LOCALID_PALLET_PROF_OAK, MOVEMENT_TYPE_FACE_LEFT
	addobject LOCALID_PALLET_PROF_OAK
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToPlayersDoor
	waitmovement 0
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, PalletTown_EventScript_NotBeenToOneIslandYet
	msgbox PalletTown_Text_OakLetMeSeePokedex
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring STR_VAR_1, VAR_0x8008
	buffernumberstring STR_VAR_2, VAR_0x8009
	goto_if_lt VAR_0x8009, 60, PalletTown_EventScript_NotEnoughMonsForNationalDex
	msgbox PalletTown_Text_CaughtXImpressiveFollowMe
	closemessage
	playbgm MUS_FOLLOW_ME, 0
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerWalkToLabFromHouse
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToLabFromHouse
	waitmovement 0
	opendoor 16, 13
	waitdooranim
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLab
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerEnterLab
	waitmovement 0
	closedoor 16, 13
	waitdooranim
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
	waitstate
	releaseall
	end

PalletTown_EventScript_EndOakRatingScene::
	closemessage
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakExit
	waitmovement 0
	removeobject LOCALID_PALLET_PROF_OAK
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
	releaseall
	end

PalletTown_EventScript_NotEnoughMonsForNationalDex::
	msgbox PalletTown_Text_CaughtXPuttingInHonestEffort
	goto PalletTown_EventScript_EndOakRatingScene
	end

PalletTown_EventScript_NotBeenToOneIslandYet::
	msgbox PalletTown_Text_OakYouEnjoyingTraveling
	goto PalletTown_EventScript_EndOakRatingScene
	end

PalletTown_Movement_OakWalkToPlayersDoor::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

PalletTown_Movement_OakExit::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

PalletTown_Movement_OakWalkToLabFromHouse::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

PalletTown_Movement_PlayerWalkToLabFromHouse::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PalletTown_EventScript_OakTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto PalletTown_EventScript_OakTrigger
	end

PalletTown_EventScript_OakTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto PalletTown_EventScript_OakTrigger
	end



PalletTown_EventScript_OakTrigger::
	goto PalletTown_EventScript_PikachuStart

	@ Normaler Start
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	famechecker FAMECHECKER_OAK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	famechecker FAMECHECKER_OAK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	textcolor NPC_TEXT_COLOR_MALE
	delay 30
	playbgm MUS_RG_OAK, 0
	message PalletTown_Text_OakDontGoOut
	waitmessage
	delay 85
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	addobject LOCALID_PALLET_PROF_OAK
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakEnterLeft
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakEnterRight
	delay 30
	msgbox PalletTown_Text_OakGrassUnsafeNeedMon
	closemessage
	delay 30
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakLeadPlayerToLabLeft
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakLeadPlayerToLabRight
	opendoor 16, 13
	waitdooranim
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLab
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerEnterLab
	waitmovement 0
	closedoor 16, 13
	waitdooranim
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
	setflag FLAG_DONT_TRANSITION_MUSIC
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
	waitstate
	releaseall
	end


PalletTown_EventScript_PikachuStart::
    famechecker FAMECHECKER_OAK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
    textcolor NPC_TEXT_COLOR_MALE
    delay 30
    playbgm MUS_RG_OAK, 0
    message PalletTown_Text_OakDontGoOut
    waitmessage
    delay 85
    closemessage
    applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    playse SE_PIN
    applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement 8, PalletTown_Movement_PikachuRunIn
    delay 30
    
    addobject LOCALID_PALLET_PROF_OAK
    call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakEnterLeft
    call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakEnterRight
    delay 30
    
    playmoncry SPECIES_PIKACHU, 0
    applymovement 8, Common_Movement_ExclamationMark
    waitmovement 0
    waitmoncry
    delay 20
    
    applymovement LOCALID_PALLET_PROF_OAK, Common_Movement_WalkInPlaceFasterUp
    waitmovement 0
    
    playse SE_BALL_TRAY_ENTER
    delay 15

    @setwildbattle SPECIES_PIKACHU, 5, ITEM_LIGHT_BALL
    @dowildbattle
    @waitstate

    removeobject 8
    playse SE_RG_BALL_CLICK
    waitse
    delay 30
    
    msgbox PalletTown_Text_OakCaughtPikachu, MSGBOX_DEFAULT
    closemessage
    
    delay 30
    call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakLeadPlayerToLabLeft
    call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakLeadPlayerToLabRight
    opendoor 16, 13
    waitdooranim
    applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLab
    applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerEnterLab
    waitmovement 0
    closedoor 16, 13
    waitdooranim
    
    setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
    clearflag FLAG_HIDE_OAK_IN_HIS_LAB
    setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
    setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
    setflag FLAG_DONT_TRANSITION_MUSIC
    warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
    waitstate
    releaseall
    end

PalletTown_Movement_PikachuRunIn:
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    walk_fast_down
    step_end

PalletTown_Text_OakCaughtPikachu::
	.string "Eich: Puh, das war knapp!\n"
	.string "Ein wildes PIKACHU hat dich attackiert.\p"
	.string "Ich habe es schnell gefangen.\n"
	.string "Es ist gefährlich ohne \neigenes Pokemon!\p"
	.string "Komm mit mir ins Labor!$"


PalletTown_EventScript_OakEnterLeft::
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLeft
	waitmovement 0
	return

PalletTown_EventScript_OakEnterRight::
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterRight
	waitmovement 0
	return

PalletTown_EventScript_OakLeadPlayerToLabLeft::
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToLabLeft
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerWalkToLabLeft
	waitmovement 0
	return

PalletTown_EventScript_OakLeadPlayerToLabRight::
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToLabRight
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerWalkToLabRight
	waitmovement 0
	return

PalletTown_Movement_OakEnterLeft::
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

PalletTown_Movement_OakEnterRight::
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

	.macro walk_to_lab
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	.endm

PalletTown_Movement_OakWalkToLabLeft::
	walk_down
	walk_to_lab
	walk_right
	walk_in_place_faster_up
	step_end

PalletTown_Movement_OakWalkToLabRight::
	walk_down
	walk_left
	walk_to_lab
	walk_right
	walk_in_place_faster_up
	step_end

PalletTown_Movement_OakEnterLab::
	walk_up
	set_invisible
	step_end

PalletTown_Movement_PlayerWalkToLabLeft::
	walk_down
	walk_down
	walk_to_lab
	step_end

PalletTown_Movement_PlayerWalkToLabRight::
	walk_down
	walk_down
	walk_left
	walk_to_lab
	step_end

PalletTown_Movement_PlayerEnterLab::
	walk_right
	walk_up
	set_invisible
	step_end

PalletTown_EventScript_SignLady::
	lock
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2, PalletTown_EventScript_SignLadyDone
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, PalletTown_EventScript_SignLadyJustShowedSign
	goto_if_eq SIGN_LADY_READY, TRUE, PalletTown_EventScript_SignLadyStartShowSign
	goto_if_set FLAG_TEMP_2, PalletTown_EventScript_SignLadyGoReadSign
	msgbox PalletTown_Text_HmmIsThatRight
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_Delay48
	waitmovement 0
	msgbox PalletTown_Text_OhLookLook
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayRight
	call_if_ne VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayLeft
	copyobjectxytoperm LOCALID_PALLET_SIGN_LADY
	setflag FLAG_TEMP_2
	release
	end

PalletTown_EventScript_SignLadyMoveOutOfWayRight::
	applymovement LOCALID_PALLET_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayRight
	waitmovement 0
	return

PalletTown_EventScript_SignLadyMoveOutOfWayLeft::
	applymovement LOCALID_PALLET_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayLeft
	waitmovement 0
	return

PalletTown_EventScript_SignLadyDone::
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox PalletTown_Text_RaisingMonsToo
	release
	end

PalletTown_EventScript_SignLadyGoReadSign::
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox PalletTown_Text_ReadItReadIt
	release
	end

PalletTown_EventScript_SignLadyJustShowedSign::
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox PalletTown_Text_SignsAreUsefulArentThey
	release
	end

PalletTown_Movement_SignLadyMoveOutOfWayRight::
	walk_right
	walk_in_place_faster_left
	step_end

PalletTown_Movement_SignLadyMoveOutOfWayLeft::
	walk_left
	walk_in_place_faster_right
	step_end

PalletTown_EventScript_FatMan::
	msgbox PalletTown_Text_CanStoreItemsAndMonsInPC, MSGBOX_NPC
	end

PalletTown_EventScript_OaksLabSign::
	lockall
	famechecker FAMECHECKER_OAK, 0
	msgbox PalletTown_Text_OakPokemonResearchLab
	releaseall
	end

PalletTown_EventScript_PlayersHouseSign::
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
	end

PalletTown_EventScript_RivalsHouseSign::
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
	end

PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
	end

PalletTown_EventScript_TrainerTips::
	lockall
	msgbox PalletTown_Text_PressStartToOpenMenu
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	releaseall
	end

PalletTown_EventScript_SignLadyTrigger::
	lockall
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	call PalletTown_EventScript_SignLadyShowSign
	releaseall
	end

PalletTown_EventScript_SignLadyShowSign::
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox PalletTown_Text_LookCopiedTrainerTipsSign
	closemessage
	delay 20
	textcolor NPC_TEXT_COLOR_NEUTRAL
	setflag FLAG_OPENED_START_MENU
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	setvar SIGN_LADY_READY, FALSE
	special SetWalkingIntoSignVars
	special DisableMsgBoxWalkaway
	signmsg
	msgbox PalletTown_Text_PressStartToOpenMenuCopy
	normalmsg
	return

PalletTown_EventScript_SignLadyStartShowSign::
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
	waitmovement 0
	call PalletTown_EventScript_SignLadyShowSign
	release
	end

PalletTown_Text_OakDontGoOut::
#if GERMAN
	.string "Eich: Warte!\n"
	.string "Geh nicht raus!$"
#else
	.string "OAK: Hey! Wait!\n"
	.string "Don't go out!$"
#endif

PalletTown_Text_OakGrassUnsafeNeedMon::
#if GERMAN
	.string "Prof. Eich: Draußen ist es gefährlich!\n"
	.string "Wilde Pokémon leben im hohen Gras!\p"
	.string "Du brauchst eigene Pokémon, um\n"
	.string "dich zu schützen.\p"
	.string "Komm, folge mir!$"
#else
	.string "OAK: It's unsafe!\n"
	.string "Wild POKéMON live in tall grass!\p"
	.string "You need your own POKéMON for\n"
	.string "your protection.\p"
	.string "I know!\n"
	.string "Here, come with me!$"
#endif

PalletTown_Text_RaisingMonsToo::
#if GERMAN
	.string "Auch ich ziehe Pokémon auf!\p"
	.string "Wenn sie stark sind, können sie mich\n"
	.string "beschützen!$"
#else
	.string "I'm raising POKéMON, too.\p"
	.string "When they get strong, they can\n"
	.string "protect me.$"
#endif

PalletTown_Text_CanStoreItemsAndMonsInPC::
#if GERMAN
	.string "Die Technik heutzutage ist unglaublich!\p"
	.string "Man kann sogar Items und Pokémon\n"
	.string "via PC lagern und wieder abrufen!$"
#else
	.string "Technology is incredible!\p"
	.string "You can now store and recall items\n"
	.string "and POKéMON as data via PC.$"
#endif

PalletTown_Text_OakPokemonResearchLab::
#if GERMAN
	.string "Professor Eich Pokémon-Labor$"
#else
	.string "OAK POKéMON RESEARCH LAB$"
#endif

PalletTown_Text_PlayersHouse::
#if GERMAN
	.string "Haus von {PLAYER}$"
#else
	.string "{PLAYER}'s house$"
#endif

PalletTown_Text_RivalsHouse::
#if GERMAN
	.string "Haus von {RIVAL}$"
#else
	.string "{RIVAL}'s house$"
#endif

PalletTown_Text_TownSign::
#if GERMAN
	.string "Alabastia Dich erwarten aufregende\n"
	.string "Abenteuer!$"
#else
	.string "PALLET TOWN\n"
	.string "Shades of your journey await!$"
#endif

PalletTown_Text_OakLetMeSeePokedex::
#if GERMAN
	.string "Eich: Ah, {PLAYER}!\n"
	.string "Du bist also zurück?\p"
	.string "Wie ist es denn um deinen Pokédex\n"
	.string "bestellt?\p"
	.string "Darf ich ihn sehen?\p"
	.string "Aha…$"
#else
	.string "OAK: Ah, {PLAYER}!\n"
	.string "You're back, are you?\p"
	.string "How much have you filled in your\n"
	.string "POKéDEX?\p"
	.string "May I see it?\p"
	.string "Let's see…$"
#endif

PalletTown_Text_CaughtXPuttingInHonestEffort::
#if GERMAN
	.string "Du hast {STR_VAR_2} gefangen…\p"
	.string "Hmm, es scheint, du würdest dich\n"
	.string "wirklich anstrengen.\p"
	.string "Wenn du mehr Einträge hast, musst du\n"
	.string "ihn mir erneut zeigen.$"
#else
	.string "You've caught {STR_VAR_2}…\p"
	.string "Hm, it looks as if you're putting\n"
	.string "in an honest effort.\p"
	.string "When you manage to fill it some\n"
	.string "more, come show me, please.$"
#endif

PalletTown_Text_CaughtXImpressiveFollowMe::
#if GERMAN
	.string "Du hast {STR_VAR_2} gefangen…\n"
	.string "Das ist wirklich beeindruckend!\p"
	.string "Es gibt etwas, das ich dich fragen\n"
	.string "wollte, {PLAYER}.\p"
	.string "Komm!\n"
	.string "Folge mir!$"
#else
	.string "You've caught… {STR_VAR_2}!?\n"
	.string "Now, this is impressive!\p"
	.string "There's something I wanted to ask\n"
	.string "of you, {PLAYER}.\p"
	.string "Come.\n"
	.string "Follow me.$"
#endif

PalletTown_Text_OakYouEnjoyingTraveling::
#if GERMAN
	.string "Eich: Ah, {PLAYER}!\n"
	.string "Dir scheint das Reisen Spaß zu machen!\l"
	.string "Da ich dich kenne, {PLAYER}, kann ich\l"
	.string "mir vorstellen, dass du auch abgelegene\l"
	.string "Orte bereist.\p"
	.string "Das ist gut!\n"
	.string "Hoho!$"
#else
	.string "OAK: Ah, {PLAYER}!\n"
	.string "You seem to be enjoying traveling.\p"
	.string "Knowing you, {PLAYER}, I can easily\n"
	.string "imagine you going out to even more\l"
	.string "exotic locales.\p"
	.string "Good for you, good for you.\n"
	.string "Hohoho.$"
#endif

@ For the NPC in Pallet Town that talks about the Trainer Tips sign
PalletTown_Text_HmmIsThatRight::
#if GERMAN
	.string "Hmm…\n"
	.string "Ist das richtig…$"
#else
	.string "Hmm…\n"
	.string "Is that right…$"
#endif

PalletTown_Text_OhLookLook::
#if GERMAN
	.string "Oh!\n"
	.string "Sieh mal, sieh!$"
#else
	.string "Oh!\n"
	.string "Look, look!$"
#endif

PalletTown_Text_ReadItReadIt::
#if GERMAN
	.string "Lies es! Lies es!$"
#else
	.string "Read it, read it!$"
#endif

@ Used by sign
PalletTown_Text_PressStartToOpenMenu::
#if GERMAN
	.string "Drücke Start, um das Menü aufzurufen!$"
#else
	.string "TRAINER TIPS\p"
	.string "Press START to open the MENU!$"
#endif

PalletTown_Text_SignsAreUsefulArentThey::
#if GERMAN
	.string "Schilder sind hilfreich, nicht?$"
#else
	.string "Signs are useful, aren't they?$"
#endif

PalletTown_Text_LookCopiedTrainerTipsSign::
#if GERMAN
	.string "Sieh nur!\p"
	.string "Ich habe das, was auf einem dieser\n"
	.string "Tipps für Trainer-Schilder steht,\l"
	.string "abgeschrieben!$"
#else
	.string "Look, look!\p"
	.string "I copied what it said on one of\n"
	.string "those TRAINER TIPS signs!$"
#endif

@ Used by NPC
PalletTown_Text_PressStartToOpenMenuCopy::
#if GERMAN
	.string "Drücke Start, um das Menü aufzurufen!$"
#else
	.string "TRAINER TIPS!\p"
	.string "Press START to open the MENU!$"
#endif
