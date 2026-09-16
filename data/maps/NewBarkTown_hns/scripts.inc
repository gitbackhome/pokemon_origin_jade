NewBarkTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

NewBarkTown_OnFrame::
	map_script_2 VAR_NEWBARK_TOWN_STATE, 6, NewBarkTown_EventScript_ElmCallAfterLeague
	.2byte 0

NewBarkTown_EventScript_ElmCallAfterLeague::
	lock
	setspeaker NewBarkTown_Text_ElmName
	pokenavcall BlackthornCity_Text_ElmCall
	waitmessage
	delay 30
	setvar VAR_NEWBARK_TOWN_STATE, 7
	setvar VAR_NEWBARKTOWN_LABSTATE, 10
	release
	end

NewBarkTown_Text_ElmName:
#if GERMAN
	.string "Lind$"
#else
	.string "PROF.ELM$"
#endif

NewBarkTown_OnTransition::
	call_if_unset FLAG_JOHTO_ARRIVAL_DONE, NewBarkTown_EventScript_JohtoArrivalSetup
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_Set_TalkToElm
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 4, NewBarkTown_Set_TalkToMom
	end

@ Origin Jade: HnS setzt seine Johto-Startwerte im Haus der Mutter, waehrend
@ der Spieler dort seine Ausruestung bekommt. Wer als Champion aus Kanto
@ kommt, laeuft durch diese Szene nie - und betrat Johto deshalb ohne diese
@ Flags. Sichtbar wurde das am Polizisten, der von Anfang an im Labor stand,
@ obwohl er erst zur Diebstahlszene gehoert.
NewBarkTown_EventScript_JohtoArrivalSetup::
	setflag FLAG_JOHTO_ARRIVAL_DONE
	@ Ortszustand: HnS setzt ihn im Haus der Mutter auf 2. Ohne ihn stimmen
	@ die Zustaende der Neuborkia-NPCs nicht und niemand haelt den Spieler
	@ auf, bevor er bei Lind war. Nur setzen, wenn er noch unberuehrt ist.
	call_if_eq VAR_NEWBARK_TOWN_STATE, 0, NewBarkTown_EventScript_SetArrivalState
	setflag FLAG_HIDE_LAB_POLICEMAN
	setflag FLAG_VISITED_NEWBARK_TOWN
	@ Pokegear und Anrufliste: in Kanto laengst vorhanden, die Johto-Seite
	@ haengt aber an diesen Flags.
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_REGISTER_RIVAL_POKENAV
	return

NewBarkTown_EventScript_SetArrivalState::
	setvar VAR_NEWBARK_TOWN_STATE, 2
	return

NewBarkTown_Set_TalkToElm::
	clearflag FLAG_HIDE_SILVER_NEWBARKTOWN
	setobjectxyperm LOCALID_LASS, 0, 11
	callnative SetTimeBasedEncounters
	end

NewBarkTown_Set_TalkToMom::
	setobjectxyperm LOCALID_LASS, 0, 11
	callnative SetTimeBasedEncounters
	end

NewBarkTown_EventScript_LabSign::
	msgbox NewBarkTown_Text_LabSign, MSGBOX_SIGN
	end

NewBarkTown_EventScript_TownSign::
	msgbox NewBarkTown_Text_Sign, MSGBOX_SIGN
	closemessage
	end


NewBarkTown_EventScript_Lass::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_EventScript_LassState2
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 3, NewBarkTown_EventScript_LassState3
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 4, NewBarkTown_EventScript_LassState4
	msgbox NewBarkTown_Text_LassState5, MSGBOX_DEFAULT
	closemessage
	release
	end
	
NewBarkTown_EventScript_LassState2::
	playse SE_PIN
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_LASS
	faceplayer
	waitmovement 0
	msgbox NewBarkTown_Text_LassState2, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_LassState3::
	msgbox NewBarkTown_Text_LassState3, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_LassState4::
	playse SE_PIN
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_LASS
	faceplayer
	waitmovement 0
	msgbox NewBarkTown_Text_LassState4, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Wooper::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WOOPER, CRY_MODE_NORMAL
	msgbox NewBarkTown_Text_Wooper, MSGBOX_DEFAULT
	waitmoncry
	release
	end

NewBarkTown_EventScript_LeaveTrigger::
	lock
	call_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_EventScript_LeaveTriggersState2
	call_if_eq VAR_NEWBARK_TOWN_STATE, 4, NewBarkTown_EventScript_LeaveTriggersState4
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerStepBack
	waitmovement 0
	release
	end

NewBarkTown_EventScript_LeaveTriggersState2::
	playse SE_PIN
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_LASS
	applymovement LOCALID_LASS, NewBarkTown_Movement_FaceDown
	waitmovement 0
	msgbox NewBarkTown_Text_LassState2, MSGBOX_DEFAULT
	closemessage
	return

NewBarkTown_EventScript_LeaveTriggersState4::
	playse SE_PIN
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_LASS
	applymovement LOCALID_LASS, NewBarkTown_Movement_FaceDown
	waitmovement 0
	msgbox NewBarkTown_Text_LassState4, MSGBOX_DEFAULT
	closemessage
	return 



NewBarkTown_EventScript_FatMan::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 2, NewBarkTown_EventScript_FatManState2
	msgbox NewBarkTown_Text_FatManState3, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_FatManState2::
	msgbox NewBarkTown_Text_FatManState2, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Silver::
	lock
	msgbox NewBarkTown_Text_Silver1, MSGBOX_DEFAULT
	delay 60
	playse SE_PIN
	applymovement LOCALID_SILVER, Common_Movement_ExclamationMark
	faceplayer
	waitmovement 0
	msgbox NewBarkTown_Text_Silver2, MSGBOX_DEFAULT
	playse SE_BANG
	applymovement LOCALID_SILVER, NewBarkTown_Movement_SilverPushesPlayer
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Movement_PlayerPushedBySilver
	waitmovement 0
	applymovement LOCALID_SILVER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	waitmovement 0
	release
	end


NewBarkTown_EventScript_Door::
	msgbox NewBarkTown_Text_Door, MSGBOX_SIGN
	end

NewBarkTown_EventScript_TestMan1::
	givebp 4
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	end

NewBarkTown_EventScript_TestMan2::
	setvar VAR_NEWBARK_TOWN_STATE, 4
	setflag FLAG_HIDE_SILVER_NEWBARKTOWN
	end

NewBarkTown_EventScript_TestMan3::
	setvar VAR_NEWBARK_TOWN_STATE, 5
	
	clearflag FLAG_COMPLETED_AERODACTYL_PUZZLE
	clearflag FLAG_COMPLETED_HOOH_PUZZLE
	clearflag FLAG_COMPLETED_KABUTO_PUZZLE
	clearflag FLAG_COMPLETED_OMANYTE_PUZZLE
	end

NewBarkTown_Movement_SilverPushesPlayer:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	face_down
	lock_facing_direction
	unlock_facing_direction
	walk_fast_up
	walk_fast_right
	walk_fast_right
	step_end


NewBarkTown_Movement_PlayerPushedBySilver:
	walk_fast_left
	face_up
	walk_fast_down
	face_up
	lock_facing_direction
	jump_2_down
	unlock_facing_direction
	face_down
	step_end

	


NewBarkTown_Movement_FaceDown:
	face_down
	step_end

NewBarkTown_Text_LabSign:
#if GERMAN
	.string "Prof. Linds\n"
	.string "Pokémon Labor$"
#else
	.string "PROF.ELM'S LAB$"
#endif

NewBarkTown_Text_Door:
#if GERMAN
	.string "Die Tür ist verschlossen.$"
#else
	.string "The door is locked.$"
#endif

NewBarkTown_Text_Wooper:
#if GERMAN
	.string "Felino: Fwhaaaa.$"
#else
	.string "WOOPER: Woooooop.$"
#endif

NewBarkTown_Text_FatManState2:
#if GERMAN
	.string "Ein PokéCom! So eins hätte ich auch\n"
	.string "gern.$"
#else
	.string "A POKéGEAR! I would like one of\n"
	.string "those myself.$"
#endif

NewBarkTown_Text_FatManState3:
#if GERMAN
	.string "Tag!\p"
	.string "Es heißt, Professor Lind habe neue\n"
	.string "Pokémon gefunden!$"
#else
	.string "Hello there!\p"
	.string "They say PROF. ELM has found new\n"
	.string "POKéMON!$"
#endif

NewBarkTown_Text_LassState2:
#if GERMAN
	.string "Du bist nicht von hier, oder?\p"
	.string "Hier kennt jeder jeden. Fremde fallen\n"
	.string "auf.\p"
	.string "Wenn du weiterwillst, geh vorher zu\n"
	.string "Professor Lind. Ohne ihn kommst du in\l"
	.string "Johto nicht weit - egal, wie stark du\l"
	.string "bist.$"
#else
	.string "You are not from here, are you?\p"
	.string "Everyone knows everyone here.\n"
	.string "Strangers stand out.\p"
	.string "If you mean to go on, see PROF. ELM\n"
	.string "first. Without him you won't get far\l"
	.string "in JOHTO, however strong you are.$"
#endif

NewBarkTown_Text_LassState3:
#if GERMAN
	.string "Oh! Dein Pokémon ist bezaubernd!\n"
	.string "Ich wünschte, ich hätte auch so eins.$"
#else
	.string "Oh! Your POKéMON is adorable!\n"
	.string "I wish I had one!$"
#endif

NewBarkTown_Text_LassState4:
#if GERMAN
	.string "Oh, du ziehst schon weiter?\p"
	.string "Dabei war es gerade erst spannend\n"
	.string "hier.$"
#else
	.string "Oh, moving on already?\p"
	.string "And things were just getting\n"
	.string "interesting around here.$"
#endif

NewBarkTown_Text_LassState5:
#if GERMAN
	.string "Mit einem PokéCom kann man von\n"
	.string "überall aus telefonieren.\p"
	.string "Sogar bis nach Kanto, heißt es.$"
#else
	.string "With a POKéGEAR you can call from\n"
	.string "anywhere.\p"
	.string "Even as far as KANTO, they say.$"
#endif

NewBarkTown_Text_Silver1:
#if GERMAN
	.string "… … …\p"
	.string "Das ist also das berühmte\n"
	.string "Lind-Pokémon-Labor…$"
#else
	.string ". . .\p"
	.string "So this is the famous ELM\n"
	.string "POKéMON LAB…$"
#endif

NewBarkTown_Text_Silver2:
#if GERMAN
	.string "…Hey! Starre mich nicht so an!$"
#else
	.string "…What are you staring at?$"
#endif

NewBarkTown_Text_Sign:
#if GERMAN
	.string "Neuborkia\n"
	.string "Die Stadt der ersten Schritte$"
#else
	.string "NEW BARK TOWN\n"
	.string "The town where the winds of a new\l"
	.string "beginning blow$"
#endif

NewBarkTown_EventScript_PlayersHouseMailbox::
	msgbox NewBarkTown_Text_PlayersHouse, MSGBOX_SIGN
	end

NewBarkTown_EventScript_ElmsHouseMailbox::
	msgbox NewBarkTown_Text_ElmsHouse, MSGBOX_SIGN
	end

NewBarkTown_Text_PlayersHouse:
#if GERMAN
	.string "Ein Wohnhaus$"
#else
	.string "A house$"
#endif

NewBarkTown_Text_ElmsHouse:
#if GERMAN
	.string "Prof. Linds Haus$"
#else
	.string "PROF.ELM'S HOUSE$"
#endif
