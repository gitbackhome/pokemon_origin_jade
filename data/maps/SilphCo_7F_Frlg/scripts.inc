SilphCo_7F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_7F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_7F_OnTransition
	.byte 0

SilphCo_7F_OnLoad::
	call_if_unset FLAG_SILPH_7F_DOOR_1, EventScript_Close7FDoor1
	call_if_unset FLAG_SILPH_7F_DOOR_2, EventScript_Close7FDoor2
	call_if_unset FLAG_SILPH_7F_DOOR_3, EventScript_Close7FDoor3
	end

SilphCo_7F_OnTransition::
	call_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_SetObjRocketsGone
	end

SilphCo_7F_EventScript_SetObjRocketsGone::
	setobjectmovementtype LOCALID_SILPH_CO_7F_WORKER_M2, MOVEMENT_TYPE_FACE_UP
	return

SilphCo_7F_EventScript_RivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalScene::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox SilphCo_7F_Text_RivalWhatKeptYou
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalApproachTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalApproachBottom
	msgbox SilphCo_7F_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_SILPH_CO_RIVAL
	call_if_eq VAR_STARTER_MON, 3, SilphCo_7F_EventScript_RivalEevee
	call_if_eq VAR_STARTER_MON, 2, SilphCo_7F_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, SilphCo_7F_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, SilphCo_7F_EventScript_RivalCharmander
	msgbox SilphCo_7F_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalExitTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalExitBottom
	playse SE_WARP_IN
	fadedefaultbgm
	removeobject LOCALID_SILPH_CO_RIVAL
	waitse
	setvar VAR_MAP_SCENE_SILPH_CO_7F, 1
	releaseall
	end

SilphCo_7F_EventScript_RivalApproachTop::
	closemessage
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalApproachTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalApproachBottom::
	return

SilphCo_7F_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_SQUIRTLE, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_BULBASAUR, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CHARMANDER, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalExitTop::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalExitBottom::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitBottom
	waitmovement 0
	return

SilphCo_7F_Movement_RivalApproachTop::
	walk_up
	step_end

SilphCo_7F_Movement_RivalExitTop::
	walk_right
	walk_right
	walk_right
	walk_up
	delay_16
	step_end

SilphCo_7F_Movement_RivalExitBottom::
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	delay_16
	step_end

SilphCo_7F_EventScript_LaprasGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_LAPRAS_FROM_SILPH, SilphCo_7F_EventScript_AlreadyGotLapras
	msgbox SilphCo_7F_Text_HaveMonForSavingUs
	setvar VAR_TEMP_1, SPECIES_LAPRAS
	givemon SPECIES_LAPRAS, 25
	goto_if_eq VAR_RESULT, 0, SilphCo_7F_EventScript_ReceiveLaprasParty
	goto_if_eq VAR_RESULT, 1, SilphCo_7F_EventScript_ReceiveLaprasPC
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

SilphCo_7F_EventScript_ReceiveLaprasParty::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_EndReceiveLapras
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_ReceiveLaprasPC::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_LaprasTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SilphCo_7F_EventScript_LaprasTransferredToPC
	end

SilphCo_7F_EventScript_LaprasTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_EndReceiveLapras::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SilphCo_7F_Text_ExplainLapras
	setflag FLAG_GOT_LAPRAS_FROM_SILPH
	release
	end

SilphCo_7F_EventScript_AlreadyGotLapras::
	msgbox SilphCo_7F_Text_RocketBossWentToBoardroom
	release
	end

SilphCo_7F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_7F_Text_RocketsAfterMasterBall
	release
	end

SilphCo_7F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_7F_Text_CanceledMasterBallProject
	release
	end

SilphCo_7F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_7F_Text_BadIfTeamRocketTookOver
	release
	end

SilphCo_7F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_7F_Text_WowYouChasedOffTeamRocket
	release
	end

SilphCo_7F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_7F_Text_ReallyDangerousHere
	release
	end

SilphCo_7F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_7F_Text_ThankYouSoMuch
	release
	end

SilphCo_7F_EventScript_FloorSign::
	msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_7F_EventScript_Joshua::
	trainerbattle_single TRAINER_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaIntro, SilphCo_7F_Text_JoshuaDefeat
	msgbox SilphCo_7F_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_33, SilphCo_7F_Text_Grunt1Intro, SilphCo_7F_Text_Grunt1Defeat
	msgbox SilphCo_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_34, SilphCo_7F_Text_Grunt2Intro, SilphCo_7F_Text_Grunt2Defeat
	msgbox SilphCo_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_35, SilphCo_7F_Text_Grunt3Intro, SilphCo_7F_Text_Grunt3Defeat
	msgbox SilphCo_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_Text_HaveMonForSavingUs::
#if GERMAN
	.string "Oh! Du bist kein Rocket! Kommst du, um\n"
	.string "uns zu retten? Klasse!\l"
	.string "Vielen Dank!\p"
	.string "Nimm dieses Pokémon als Dankeschön.$"
#else
	.string "Oh! Hi! You're not a ROCKET!\n"
	.string "You came to save us?\l"
	.string "Why, thank you!\p"
	.string "I want you to have this POKéMON\n"
	.string "for saving us.$"
#endif

SilphCo_7F_Text_ObtainedLaprasFromEmployee::
#if GERMAN
	.string "{PLAYER} erhält ein Lapras von\n"
	.string "einem Silph-Angestellten!$"
#else
	.string "{PLAYER} obtained a LAPRAS from\n"
	.string "the SILPH employee!$"
#endif

SilphCo_7F_Text_ExplainLapras::
#if GERMAN
	.string "Es heißt Lapras und ist sehr\n"
	.string "intelligent.\p"
	.string "Es hat bisher bei uns im Labor gelebt.\n"
	.string "Aber bei dir ist es besser aufgehoben!\p"
	.string "Du wirst Lapras sicher ein guter\n"
	.string "Trainer sein!\p"
	.string "Es ist ein guter Schwimmer und\n"
	.string "kann dich übers Wasser tragen!$"
#else
	.string "It's a LAPRAS.\n"
	.string "It's a very intelligent POKéMON.\p"
	.string "We kept it in our lab, but it will\n"
	.string "be much better off with you.\p"
	.string "I think you will be a good TRAINER\n"
	.string "for LAPRAS!\p"
	.string "It's a good swimmer.\n"
	.string "It'll give you a lift across water!$"
#endif

SilphCo_7F_Text_RocketBossWentToBoardroom::
#if GERMAN
	.string "Team Rockets Boss ging in den\n"
	.string "Sitzungssaal!\p"
	.string "Ob unser Präsident wohlauf ist?$"
#else
	.string "TEAM ROCKET's BOSS went to the\n"
	.string "boardroom!\p"
	.string "Is our PRESIDENT okay?\n"
	.string "I'm worried.$"
#endif

SilphCo_7F_Text_RocketsAfterMasterBall::
#if GERMAN
	.string "Das Team Rocket ist hinter dem\n"
	.string "Meisterball her, mit dem man jedes\l"
	.string "Pokémon fangen kann!$"
#else
	.string "TEAM ROCKET was after the MASTER\n"
	.string "BALL, which catches any POKéMON.$"
#endif

SilphCo_7F_Text_CanceledMasterBallProject::
#if GERMAN
	.string "Wir haben das Projekt gestoppt.\n"
	.string "Der Meisterball in Team Rockets\l"
	.string "Händen? Niemals!$"
#else
	.string "We canceled the MASTER BALL\n"
	.string "project because of TEAM ROCKET.$"
#endif

SilphCo_7F_Text_BadIfTeamRocketTookOver::
#if GERMAN
	.string "Es wäre fatal, wenn das Team Rocket die\n"
	.string "Silph Co. oder unsere Pokémon\l"
	.string "übernehmen würde!$"
#else
	.string "It would be bad if TEAM ROCKET\n"
	.string "took over SILPH or our POKéMON.$"
#endif

SilphCo_7F_Text_WowYouChasedOffTeamRocket::
#if GERMAN
	.string "Wow!\p"
	.string "Du bist ganz allein mit dem Team\n"
	.string "Rocket fertig geworden?$"
#else
	.string "Wow!\p"
	.string "You chased off TEAM ROCKET all by\n"
	.string "yourself?$"
#endif

SilphCo_7F_Text_ReallyDangerousHere::
#if GERMAN
	.string "Hier ist es sehr gefährlich!\n"
	.string "Du wirst mich nicht retten können!$"
#else
	.string "You!\n"
	.string "It's really dangerous here!\p"
	.string "You came to save me?\n"
	.string "You can't!$"
#endif

SilphCo_7F_Text_ThankYouSoMuch::
#if GERMAN
	.string "Ich danke vielmals!$"
#else
	.string "Thank you so much!$"
#endif

SilphCo_7F_Text_Grunt3Intro::
#if GERMAN
	.string "Du bist ganz schön mutig!$"
#else
	.string "Uh-oh!\n"
	.string "I smell a little mouse!$"
#endif

SilphCo_7F_Text_Grunt3Defeat::
#if GERMAN
	.string "Licht aus!$"
#else
	.string "Lights out!$"
#endif

SilphCo_7F_Text_Grunt3PostBattle::
#if GERMAN
	.string "Wenn du nur so durch die Gegend\n"
	.string "läufst, findest du den Boss nie!$"
#else
	.string "You won't find my BOSS by just\n"
	.string "scurrying around!$"
#endif

SilphCo_7F_Text_JoshuaIntro::
#if GERMAN
	.string "Haha!\p"
	.string "Du dachtest wohl, ich arbeite für\n"
	.string "die Silph Co.?$"
#else
	.string "Heheh!\p"
	.string "You mistook me for a SILPH worker?$"
#endif

SilphCo_7F_Text_JoshuaDefeat::
#if GERMAN
	.string "Feierabend! Ich geh nach Hause!$"
#else
	.string "I'm done!$"
#endif

SilphCo_7F_Text_JoshuaPostBattle::
#if GERMAN
	.string "Kaum trocken hinter den Ohren, aber\n"
	.string "schon ein begabter Trainer!$"
#else
	.string "Despite your age, you are a\n"
	.string "skilled TRAINER!$"
#endif

SilphCo_7F_Text_Grunt1Intro::
#if GERMAN
	.string "Ich bin einer der vier berüchtigten\n"
	.string "Rocket-brüder!$"
#else
	.string "I am one of the four ROCKET\n"
	.string "BROTHERS!$"
#endif

SilphCo_7F_Text_Grunt1Defeat::
#if GERMAN
	.string "Tut mir Leid, Brüder...$"
#else
	.string "Aack!\n"
	.string "Brothers, I lost!$"
#endif

SilphCo_7F_Text_Grunt1PostBattle::
#if GERMAN
	.string "Warte nur, meine Brüder werden\n"
	.string "mich rächen!!!$"
#else
	.string "Doesn't matter.\n"
	.string "My brothers will repay the favor!$"
#endif

SilphCo_7F_Text_Grunt2Intro::
#if GERMAN
	.string "Ein Kind im Gebäude?\n"
	.string "Das musst du sein!$"
#else
	.string "A child intruder?\n"
	.string "That must be you!$"
#endif

SilphCo_7F_Text_Grunt2Defeat::
#if GERMAN
	.string "Na toll!\n"
	.string "Ich hab verloren!$"
#else
	.string "Fine!\n"
	.string "I lost!$"
#endif

SilphCo_7F_Text_Grunt2PostBattle::
#if GERMAN
	.string "Geh nach Hause, bevor mein Boss\n"
	.string "dich in den Boden stampft!$"
#else
	.string "Go on home before my BOSS gets\n"
	.string "ticked off!$"
#endif

SilphCo_7F_Text_RivalWhatKeptYou::
#if GERMAN
	.string "{RIVAL}: Was hat dich aufgehalten,\n"
	.string "{PLAYER}?$"
#else
	.string "{RIVAL}: What kept you, {PLAYER}?$"
#endif

SilphCo_7F_Text_RivalIntro::
#if GERMAN
	.string "{RIVAL}: Hahaha! Ich wusste, du\n"
	.string "würdest hier vorbeikommen!\p"
	.string "Ich schätze, das Team Rocket hat\n"
	.string "dir ganz schön zugesetzt!\p"
	.string "Ich hab dich in Saffronia City gesehen\n"
	.string "und mich gefragt, ob du seitdem besser\l"
	.string "geworden bist!$"
#else
	.string "{RIVAL}: Hahaha! I thought you'd\n"
	.string "turn up if I waited here!\p"
	.string "I guess TEAM ROCKET slowed you\n"
	.string "down! Not that I care!\p"
	.string "I saw you in SAFFRON, so I decided\n"
	.string "to see if you got better!$"
#endif

SilphCo_7F_Text_RivalDefeat::
#if GERMAN
	.string "Mann!\n"
	.string "Du bist so gut, dass du gegen den\l"
	.string "Rocket Boss antreten kannst!$"
#else
	.string "Oh, man!\n"
	.string "So, you are ready for BOSS\l"
	.string "ROCKET!$"
#endif

SilphCo_7F_Text_RivalPostBattle::
#if GERMAN
	.string "Also, {PLAYER}!\n"
	.string "Ich ziehe dann weiter!\p"
	.string "Wenn ich in den Pokédex sehe, erkenne\n"
	.string "ich, wie stark die Pokémon sind und wie\l"
	.string "sie sich entwickeln!\p"
	.string "Ich werde zur Pokémon Liga gehen.\n"
	.string "Dann werde ich die Top Vier ausstechen!\p"
	.string "Bald bin ich der mächtigste Trainer der\n"
	.string "Welt!\p"
	.string "Viel Glück, {PLAYER}!\n"
	.string "Und trainiere schön weiter!\l"
	.string "Ciao!$"
#else
	.string "Well, {PLAYER}!\n"
	.string "I'm moving on up and ahead!\p"
	.string "By checking my POKéDEX, I'm\n"
	.string "starting to see what's strong and\l"
	.string "how they evolve!\p"
	.string "Am I a genius or what?\p"
	.string "I'm going to the POKéMON LEAGUE to\n"
	.string "boot out the ELITE FOUR.\p"
	.string "I'll become the world's most\n"
	.string "powerful TRAINER!\p"
	.string "{PLAYER}, well, good luck to you!\n"
	.string "Don't sweat it!\l"
	.string "Smell ya!$"
#endif

SilphCo_7F_Text_FloorSign::
#if GERMAN
	.string "Silph Co. Büro des Präsidenten\n"
	.string "6 Og$"
#else
	.string "SILPH CO. HEAD OFFICE\n"
	.string "7F$"
#endif


SilphCo_7F_EventScript_RivalEevee::
	trainerbattle_earlyrival TRAINER_RIVAL_SILPH_EEVEE, RIVAL_BATTLE_TUTORIAL, SilphCo_7F_Text_RivalDefeat, Text_RivalVictory
	return
