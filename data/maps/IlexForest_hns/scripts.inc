IlexForest_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IlexForest_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

IlexForest_OnTransition:
	call_if_eq VAR_ILEX_FOREST_FARFETCHD, 1, IlexForest_EventScript_ReenterWhenFarfetchdLeaving
	call_if_eq VAR_ILEX_FOREST_FARFETCHD, 2, IlexForest_EventScript_ReenterDuringCutScene
	callnative SetTimeBasedEncounters
	end

IlexForest_EventScript_ReenterWhenFarfetchdLeaving::
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 33, 51
	return

IlexForest_EventScript_ReenterDuringCutScene::
	clearflag FLAG_HIDE_ILEX_FOREST_MASTER
	clearflag FLAG_HIDE_ILEX_FOREST_APPRENTICE
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 28, 42
	return

IlexForest_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 2, IlexForest_EventScript_Apprentice2
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 3, IlexForest_EventScript_Apprentice2
	msgbox IlexForest_Text_ApprenticeIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

IlexForest_EventScript_Apprentice2::
	msgbox IlexForest_Text_ApprenticeAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

IlexForest_EventScript_Boss::
	lock
	faceplayer
	msgbox IlexForest_Text_CharcoalMasterTalkAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

IlexForest_EventScript_Farfetchd_1A::
	lock
	faceplayer
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 3, IlexForest_EventScript_Farfetchd_Done
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 2, IlexForest_EventScript_Farfetchd_Done
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 1, IlexForest_EventScript_Farfetchd_Leave
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_1B
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_1A
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_1
	@add clockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
	addobject LOCALID_ILEX_FOREST_FARFETCHD_2
	release
	end
IlexForest_EventScript_Farfetchd_1B::
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_1B
	waitmovement 0
	setvar VAR_ILEX_FOREST_FARFETCHD, 1
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 33, 51
	release
	end

IlexForest_EventScript_Farfetchd_2A::
	lock
	faceplayer
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_2B
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_2, IlexForest_Movement_Farfetchd_2A
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_2
	@add clockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
	addobject LOCALID_ILEX_FOREST_FARFETCHD_3
	release
	end
IlexForest_EventScript_Farfetchd_2B::
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_2, IlexForest_Movement_Farfetchd_2B
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_2
	@add counterclockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	addobject LOCALID_ILEX_FOREST_FARFETCHD_1
	release
	end

IlexForest_EventScript_Farfetchd_3A::
	lock
	faceplayer
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_3B
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_3, IlexForest_Movement_Farfetchd_3A
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_3
	@add clockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
	addobject LOCALID_ILEX_FOREST_FARFETCHD_2
	release
	end
IlexForest_EventScript_Farfetchd_3B::
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_3, IlexForest_Movement_Farfetchd_3B
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_3
	@add counterclockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
	addobject LOCALID_ILEX_FOREST_FARFETCHD_4
	release
	end

IlexForest_EventScript_Farfetchd_4A::
	lock
	faceplayer
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_4B
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_4, IlexForest_Movement_Farfetchd_4A
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_4
	@add clockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
	addobject LOCALID_ILEX_FOREST_FARFETCHD_3
	release
	end
IlexForest_EventScript_Farfetchd_4B::
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_4, IlexForest_Movement_Farfetchd_4B
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_4
	@add counterclockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	addobject LOCALID_ILEX_FOREST_FARFETCHD_1
	release
	end


IlexForest_EventScript_Farfetchd_Leave::
	goto_if_eq VAR_FACING, DIR_EAST, IlexForest_EventScript_Farfetchd_Return
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_Return
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_Leave
	waitmovement 0
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 28, 42
	setvar VAR_ILEX_FOREST_FARFETCHD, 2
	clearflag FLAG_HIDE_ILEX_FOREST_KIMONO
	clearflag FLAG_HIDE_ILEX_FOREST_MASTER
	setflag FLAG_HIDE_AZALEA_TOWN_CUT_MASTER
	addobject 1
	release
	end
IlexForest_EventScript_Farfetchd_Return::
	setvar VAR_ILEX_FOREST_FARFETCHD, 0
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_Return
	waitmovement 0
	setobjectxyperm LOCALID_ILEX_FOREST_FARFETCHD_1, 42, 47
	release
	end
IlexForest_EventScript_Farfetchd_Done::
	release
	end

IlexForest_EventScript_TriggerBot::
	lock
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_WalkUp
	waitmovement 0
IlexForest_EventScript_Trigger::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox IlexForest_Text_CharcoalMasterIntro, MSGBOX_DEFAULT
	closemessage
	@ Origin Jade: Wer aus Kanto kommt, hat den Zerschneider laengst.
	checkitem ITEM_HM_CUT
	goto_if_eq VAR_RESULT, TRUE, IlexForest_EventScript_HasCut
	giveitem ITEM_HM_CUT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	goto IlexForest_EventScript_CutDone

IlexForest_EventScript_HasCut::
	msgbox IlexForest_Text_CharcoalMasterHasCut, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED

IlexForest_EventScript_CutDone::
	msgbox IlexForest_Text_CharcoalMasterOutro, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_HM_CUT
	setflag FLAG_HIDE_ILEX_FOREST_MASTER
	setflag FLAG_HIDE_ILEX_FOREST_APPRENTICE
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	setvar VAR_ILEX_FOREST_FARFETCHD, 3
	setvar VAR_AZALEA_TOWN_STATE, 7
	clearflag FLAG_HIDE_AZALEA_TOWN_FARFETCHD
	clearflag FLAG_HIDE_AZALEA_TOWN_CUT_MASTER
	closemessage
	release
	end

IlexForest_EventScript_Picnicker::
	lock
	faceplayer
	msgbox IlexForest_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

IlexForest_EventScript_BugcatcherWayne::
	trainerbattle_single TRAINER_WAYNE_HNS, IlexForest_Text_BugCatcherWayneSeen, IlexForest_Text_BugCatcherWayneBeaten
	msgbox IlexForest_Text_BugCatcherWayneAfter, MSGBOX_AUTOCLOSE
	end

IlexForest_EventScript_Shrine::
	lock
	goto_if_eq VAR_AZALEA_TOWN_STATE, 9, IlexForest_EventScript_Celebi_Event
	msgbox IlexForest_Text_Shrine, MSGBOX_DEFAULT
	closemessage
	release
	end

IlexForest_EventScript_Celebi_Event::
	msgbox IlexForest_Text_ShrineCelebiEvent, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, IlexForest_EventScript_Shrine_Cancel
	msgbox IlexForest_Text_InsertGSBall, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_CELEBI
	addobject LOCALID_ILEX_FOREST_CELEBI
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_ILEX_FOREST_CELEBI, IlexForest_Movement_Celebi1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_ILEX_FOREST_CELEBI, IlexForest_Movement_Celebi2
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_ILEX_FOREST_CELEBI, IlexForest_Movement_Celebi3
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_CELEBI, 40
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	call_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, IlexForest_EventScript_Shrine_Caught
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ILEX_FOREST_CELEBI
	setflag FLAG_HIDE_CELEBI
	special GivePartyMonNationalRibbon
	fadescreenswapbuffers FADE_FROM_BLACK
IlexForest_EventScript_Kurt::
	clearflag FLAG_HIDE_ILEX_FOREST_KURT
	addobject LOCALID_ILEX_FOREST_KURT
	applymovement LOCALID_ILEX_FOREST_KURT, IlexForest_Movement_Kurt1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox IlexForest_Text_KurtCaughtCelebi, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ILEX_FOREST_KURT, IlexForest_Movement_Kurt2
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_KURT
	removeobject LOCALID_ILEX_FOREST_KURT
	setvar VAR_AZALEA_TOWN_STATE, 10
	release
	end

IlexForest_EventScript_Shrine_Caught::
	setflag FLAG_CAUGHT_CELEBI
	return

IlexForest_EventScript_Shrine_Cancel::
	closemessage
	release
	end


IlexForest_EventScript_SecondCelebi::
	lock
	faceplayer
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_CELEBI, 40
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IlexForest_EventScript_SecondCelebiRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ILEX_FOREST_SECOND_CELEBI
	setflag FLAG_HIDE_ILEX_FOREST_SECOND_CELEBI
	fadescreenswapbuffers FADE_FROM_BLACK
	special GivePartyMonNationalRibbon
	release
	end

IlexForest_EventScript_SecondCelebiRan::
	release
	end


IlexForest_EventScript_Sign::
	lock
	msgbox IlexForest_Text_Signpost, MSGBOX_SIGN
	closemessage
	release
	end

IlexForest_EventScript_Kimono::
	lock
	playbgm MUS_HG_KIMONO_GIRL, FALSE
	playse SE_PIN
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_NORTH
	applymovement2 LOCALID_ILEX_FOREST_KIMONO, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ILEX_FOREST_KIMONO
	applymovement2 LOCALID_ILEX_FOREST_KIMONO, IlexForest_Movement_Kimono_Girl1
	waitmovement 0
	msgbox IlexForest_Text_Kimono_Girl1, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ILEX_FOREST_KIMONO, IlexForest_Movement_Kimono_Girl_Spin
	waitmovement 0
	turnobject LOCALID_ILEX_FOREST_KIMONO, DIR_SOUTH
	msgbox IlexForest_Text_Kimono_Girl2, MSGBOX_YESNO
	closemessage
	msgbox IlexForest_Text_Kimono_Girl3, MSGBOX_DEFAULT
	closemessage
	playfirstmoncry
	applymovement2 OBJ_EVENT_ID_FOLLOWER, IlexForest_Movement_Follower1
	waitmovement 0
	playfirstmoncry
	turnobject LOCALID_ILEX_FOREST_KIMONO, DIR_WEST
	msgbox IlexForest_Text_Kimono_Girl4, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ILEX_FOREST_KIMONO, DIR_SOUTH
	delay 16
	msgbox IlexForest_Text_Kimono_Girl5, MSGBOX_DEFAULT
	closemessage
	delay 16
	playfirstmoncry
	applymovement2 OBJ_EVENT_ID_FOLLOWER, IlexForest_Movement_Follower2
	applymovement2 LOCALID_ILEX_FOREST_KIMONO, IlexForest_Movement_Kimono_Girl2
	waitmovement 0
	waitmovement 0
	fadedefaultbgm
	setvar VAR_ILEX_FOREST_FARFETCHD, 4
	setflag FLAG_HIDE_ILEX_FOREST_KIMONO
	removeobject LOCALID_ILEX_FOREST_KIMONO
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER, IlexForest_Movement_Follower3
	waitmovement 0
	playfirstmoncry
	release
	end

IlexForest_EventScript_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

IlexForest_EventScript_Ether::
	finditem ITEM_ETHER
	end

IlexForest_EventScript_FullHeal::
	finditem ITEM_FULL_HEAL
	end

IlexForest_EventScript_Item_FalseSwipe::
	finditem ITEM_TM_FALSE_SWIPE
	end

IlexForest_Movement_Kimono_Girl1:
	walk_right
	face_down
	step_end

IlexForest_Movement_Kimono_Girl_Spin:
	face_left
	delay_8
	face_up
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_up
	delay_8
	face_right
	delay_8
	face_down
	step_end

IlexForest_Movement_Follower1:
	walk_left
	jump_2_up
	walk_up
	face_right
	jump_in_place_right
	delay 16
	face_left
	jump_in_place_left
	delay 16
	face_right
	step_end

IlexForest_Movement_Follower2:
	face_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

IlexForest_Movement_Kimono_Girl2:
	face_left
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

IlexForest_Movement_Follower3:
	delay 16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	jump_2_down
	walk_right
	face_up
	step_end


IlexForest_Movement_Farfetchd_1A:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
IlexForest_Movement_Farfetchd_1B:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
IlexForest_Movement_Farfetchd_2A:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end
IlexForest_Movement_Farfetchd_2B:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
IlexForest_Movement_Farfetchd_3A:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
IlexForest_Movement_Farfetchd_3B:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
IlexForest_Movement_Farfetchd_4A:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
IlexForest_Movement_Farfetchd_4B:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

IlexForest_Movement_Farfetchd_Leave:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_down
	step_end
IlexForest_Movement_Farfetchd_Return:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

IlexForest_Movement_Celebi1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

IlexForest_Movement_Celebi2:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

IlexForest_Movement_Celebi3:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

IlexForest_Movement_Kurt1:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

IlexForest_Movement_Kurt2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

IlexForest_Text_ApprenticeIntro:
#if GERMAN
	.string "Oh, Mist… Mein Boss wird sauer sein…\p"
	.string "Das Porenta, das mit dem Zerschneider\n"
	.string "Bäume\p"
	.string "fällt, um nach Holzkohle zu\p"
	.string "suchen, ist abgehauen.\p"
	.string "Ich traue mich nicht in den\n"
	.string "Steineichenwald, um nach ihm zu suchen.\p"
	.string "Er ist so groß, dunkel und unheimlich…$"
#else
	.string "Oh, man… My boss is going to be\n"
	.string "steaming…\p"
	.string "The FARFETCH'D that CUTS trees\n"
	.string "for charcoal took off on me.\p"
	.string "I can't go looking for it here\n"
	.string "in the ILEX FOREST.\p"
	.string "It's too big, dark and scary\n"
	.string "for me…$"
#endif

IlexForest_Text_ApprenticeAfter:
#if GERMAN
	.string "Wow! Vielen Dank auch!\p"
	.string "Die Pokémon von meinem Boss gehorchen\n"
	.string "mir nicht, da ich keinen Orden besitze.$"
#else
	.string "Wow! Thanks a whole bunch!\p"
	.string "My boss' POKéMON won't obey me\n"
	.string "because I don't have a BADGE.$"
#endif

IlexForest_Text_ItsTheMissingPokemon:
#if GERMAN
	.string "Das vermisste Pokémon!$"
#else
	.string "It's the missing POKéMON!$"
#endif

IlexForest_Text_Kwaaaa:
#if GERMAN
	.string "Porenta: Pooorenta!$"
#else
	.string "FARFETCH'D: Kwaa!$"
#endif

IlexForest_Text_CharcoalMasterIntro:
#if GERMAN
	.string "Oh! Das sind ja meine Kleinen,\n"
	.string "Po und Renta!\p"
	.string "Sag bloß…\p"
	.string "Hast du diese beiden etwa für mich\n"
	.string "eingefangen?!?\p"
	.string "Wenn diese zwei keine Bäume für mich\n"
	.string "fällen, kann ich keine Kohle herstellen!\p"
	.string "Vielen Dank! Wie kann ich mich nur\n"
	.string "dafür erkenntlich zeigen?\p"
	.string "Ich hab’s!\n"
	.string "Nimm das hier!$"
#else
	.string "Ah! My FARFETCH'D!\p"
	.string "You found it for us, kid?\p"
	.string "Without it, we wouldn't be able\n"
	.string "to CUT trees for charcoal.\p"
	.string "Thanks, kid!\p"
	.string "Now, how can I thank you…\p"
	.string "I know! Here, take this.$"
#endif

IlexForest_Text_CharcoalMasterOutro:
#if GERMAN
	.string "Das ist die VM Zerschneider!\n"
	.string "Besitzt du den Orden aus der Arena von\l"
	.string "Azalea City, kann ein Pokémon deiner\l"
	.string "Wahl damit kleinere Bäume fällen!\p"
	.string "Aaaber!\p"
	.string "Hat ein Pokémon diese VM einmal gelernt,\n"
	.string "kann es sie so schnell auch nicht wieder\l"
	.string "vergessen!\p"
	.string "Überlege dir also sehr gut, welchem\n"
	.string "deiner Pokémon du sie beibringst!$"
#else
	.string "That's the CUT HM.\n"
	.string "Teach that to a POKéMON to clear\l"
	.string "small trees.\p"
	.string "Of course, you have to have the\n"
	.string "GYM BADGE from AZALEA to use it.$"
#endif

IlexForest_Text_CharcoalMasterTalkAfter:
#if GERMAN
	.string "Willst du mein Schüler werden?\n"
	.string "In zehn Jahren bist du topfit!$"
#else
	.string "Do you want to apprentice as a\n"
	.string "charcoal maker with me?\p"
	.string "You'll be first-rate in ten years!$"
#endif

IlexForest_Text_Lass:
#if GERMAN
	.string "Ist dem Waldpatron etwas zugestoßen?$"
#else
	.string "Did something happen to the\n"
	.string "forest's guardian?$"
#endif

IlexForest_Text_Signpost:
#if GERMAN
	.string "Steineichenwald\p"
	.string "So dicht bewachsen, dass sich der\n"
	.string "Himmel hinter dem Dickicht nur noch\l"
	.string "dunkel erahnen lässt.\p"
	.string "Pass auf, wo du hintrittst. Hier ist\n"
	.string "schon manchem etwas aus der Tasche\l"
	.string "gefallen.$"
#else
	.string "ILEX FOREST\p"
	.string "So overgrown with trees that the sky\n"
	.string "is barely a glimmer through the\l"
	.string "canopy.\p"
	.string "Watch where you tread. More than one\n"
	.string "traveller has dropped something\l"
	.string "here.$"
#endif

IlexForest_Text_Shrine:
#if GERMAN
	.string "Der Steineichenwald-Schrein… er wurde\n"
	.string "zu Ehren des Waldpatrons errichtet.$"
#else
	.string "ILEX FOREST SHRINE…\p"
	.string "It's in honor of the forest's\n"
	.string "protector…$"
#endif

IlexForest_Text_ShrineCelebiEvent:
#if GERMAN
	.string "Steineichenwald Schrein…\p"
	.string "Zu Ehren des Patrons…\p"
	.string "Oh? Was ist das?\p"
	.string "Ein Loch.\n"
	.string "Es scheint, der GS-Ball passt hinein.\l"
	.string "\p"
	.string "Willst du den GS-Ball einsetzen?$"
#else
	.string "ILEX FOREST SHRINE…\p"
	.string "It's in honor of the forest's\n"
	.string "protector…\p"
	.string "Oh? What is this?\p"
	.string "It's a hole.\n"
	.string "It looks like the GS BALL would fit\l"
	.string "inside it.\p"
	.string "Want to put the GS BALL here?$"
#endif

IlexForest_Text_InsertGSBall:
#if GERMAN
	.string "{PLAYER} setzte den GS-Ball ein.$"
#else
	.string "{PLAYER} put in the GS BALL.$"
#endif

IlexForest_Text_KurtCaughtCelebi:
#if GERMAN
	.string "Puh, war das spannend!\p"
	.string "{PLAYER}, das war fantastisch. Danke!\n"
	.string "\p"
	.string "Die Legenden über den Shrine\n"
	.string "waren also wahr.\p"
	.string "Ich bin inspiriert, bessere Bälle zu\n"
	.string "machen!\p"
	.string "Ich gehe jetzt!$"
#else
	.string "Whew, wasn't that something!\p"
	.string "{PLAYER}, that was fantastic. Thanks!\p"
	.string "The legends about that SHRINE were\n"
	.string "real after all.\p"
	.string "I feel inspired by what I just saw.\p"
	.string "It motivates me to make better BALLS!\p"
	.string "I'm going!$"
#endif

IlexForest_Text_BugCatcherWayneSeen:
#if GERMAN
	.string "Schleich dich nicht so an!\p"
	.string "Du hast ein Pokémon verschreckt!$"
#else
	.string "Don't sneak up on me like that!\p"
	.string "You frightened a POKéMON away!$"
#endif

IlexForest_Text_BugCatcherWayneBeaten:
#if GERMAN
	.string "Dieses Pokémon habe ich noch nie zuvor\n"
	.string "gesehen…$"
#else
	.string "I hadn't seen that POKéMON before…$"
#endif

IlexForest_Text_BugCatcherWayneAfter:
#if GERMAN
	.string "Ein Pokémon, das ich nie zuvor gesehen\n"
	.string "habe, fiel vom Baum, als ich Kopfnuss\l"
	.string "einsetzte.\p"
	.string "Ich sollte Kopfnuss öfter nutzen.$"
#else
	.string "A POKéMON I've never seen before\n"
	.string "fell out of the tree when I used\l"
	.string "HEADBUTT.\p"
	.string "I ought to use HEADBUTT in other\n"
	.string "places too.$"
#endif

IlexForest_Text_Kimono_Girl1:
#if GERMAN
	.string "Kimono, Kimono, mein Gewand!\n"
	.string "Sage mir, wie finde ich zum Waldesrand?$"
#else
	.string "KIMONO GIRL, KIMONO GIRL, lost and\n"
	.string "all alone. Poor girl lost in the\l"
	.string "dark ILEX FOREST.$"
#endif

IlexForest_Text_Kimono_Girl2:
#if GERMAN
	.string "Was sagt Ihr da? Ihr wollt mich schon\n"
	.string "einmal gesehen haben?\l"
	.string "In Viola City?\l"
	.string "Gewiss täuscht Ihr Euch!\p"
	.string "Aber wärt Ihr unter Umständen so\n"
	.string "freundlich, meiner Wenigkeit den Weg\l"
	.string "aus diesem Wald zu weisen?$"
#else
	.string "You remember me from VIOLET CITY?\n"
	.string "You must be imagining.\p"
	.string "Anyway, will you show me how to\n"
	.string "get out of this forest?$"
#endif

IlexForest_Text_Kimono_Girl3:
#if GERMAN
	.string "Dann nehme ich an, Ihr kennt den Weg\n"
	.string "nach draußen selbst nicht?$"
#else
	.string "Me oh my... You are lost yourself,\n"
	.string "aren't you?$"
#endif

IlexForest_Text_Kimono_Girl4:
#if GERMAN
	.string "Sieh an! Möchtest du mir vielleicht den\n"
	.string "Weg nach draußen zeigen?\l"
	.string "Was für ein kluges Pokémon!$"
#else
	.string "Wow! Are you going to show me how\n"
	.string "to get out?\p"
	.string "You are such a smart POKéMON!$"
#endif

IlexForest_Text_Kimono_Girl5:
#if GERMAN
	.string "Ich gehe schon mal vor!$"
#else
	.string "See you.$"
#endif

IlexForest_Text_CharcoalMasterHasCut:
#if GERMAN
	.string "Den Zerschneider trägst du schon bei\n"
	.string "dir. Natürlich.\p"
	.string "Mein Lehrling hat ein halbes Jahr\n"
	.string "gebraucht, bis der Baum fiel.\p"
	.string "Dann nimm das hier. Der Wald gibt\n"
	.string "gern, wenn man ihn nicht abholzt.$"
#else
	.string "You already carry CUT. Of course you\n"
	.string "do.\p"
	.string "My apprentice needed half a year\n"
	.string "before that tree came down.\p"
	.string "Then take this. The forest gives\n"
	.string "freely, if you don't clear it.$"
#endif
