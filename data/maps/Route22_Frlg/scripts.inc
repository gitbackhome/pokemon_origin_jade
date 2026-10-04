Route22_Frlg_MapScripts::
	.byte 0

Route22_EventScript_EarlyRivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route22_EventScript_EarlyRival
	end

Route22_EventScript_EarlyRivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 29, 9
	goto Route22_EventScript_EarlyRival
	end

Route22_EventScript_EarlyRivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 29, 9
	goto Route22_EventScript_EarlyRival
	end

Route22_EventScript_EarlyRival::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	addobject LOCALID_ROUTE22_RIVAL
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_EarlyRivalApproachTop
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_EarlyRivalApproach
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_EarlyRivalApproachBottom
	delay 6
	msgbox Route22_Text_EarlyRivalIntro
	call_if_eq VAR_STARTER_MON, 3, Route22_EventScript_EarlyRivalEevee
	call_if_eq VAR_STARTER_MON, 2, Route22_EventScript_EarlyRivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, Route22_EventScript_EarlyRivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, Route22_EventScript_EarlyRivalCharmander
	msgbox Route22_Text_EarlyRivalPostBattle
	closemessage
	delay 10
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_EarlyRivalExitTop
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_EarlyRivalExit
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_EarlyRivalExitBottom
	fadedefaultbgm
	removeobject LOCALID_ROUTE22_RIVAL
	setvar VAR_MAP_SCENE_ROUTE22, 2
	releaseall
	end

Route22_EventScript_EarlyRivalApproach::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproach
	waitmovement 0
	return

Route22_EventScript_EarlyRivalApproachBottom::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproachBottom
	applymovement LOCALID_PLAYER, Route22_Movement_PlayerFaceRival
	waitmovement 0
	return

Route22_EventScript_EarlyRivalSquirtle::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return

Route22_EventScript_EarlyRivalBulbasaur::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_BULBASAUR, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return

Route22_EventScript_EarlyRivalCharmander::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_CHARMANDER, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return

Route22_EventScript_EarlyRivalExit::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_EarlyRivalExit
	waitmovement 0
	return

Route22_EventScript_EarlyRivalExitBottom::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_EarlyRivalExitBottom
	waitmovement 0
	return

Route22_Movement_UnusedRivalExit:: @ 8
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

@ Origin Jade: nach Schritt 13 ist der Rivale aus dem Bild; die restlichen
@ 16 Schritte liefen unsichtbar weiter und haben den Spieler solange gesperrt.
Route22_Movement_EarlyRivalExit::
	walk_down
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ Origin Jade: nach Schritt 15 ist der Rivale aus dem Bild; die restlichen
@ 15 Schritte liefen unsichtbar weiter und haben den Spieler solange gesperrt.
Route22_Movement_EarlyRivalExitBottom::
	walk_up
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

Route22_Movement_RivalApproach::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route22_Movement_RivalApproachBottom::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route22_Movement_PlayerFaceRival::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	step_end

Route22_EventScript_LateRivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route22_EventScript_LateRival
	end

Route22_EventScript_LateRivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 29, 9
	goto Route22_EventScript_LateRival
	end

Route22_EventScript_LateRivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 29, 9
	goto Route22_EventScript_LateRival
	end

Route22_EventScript_LateRival::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	addobject LOCALID_ROUTE22_RIVAL
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_LateRivalApproachTop
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_LateRivalApproach
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_LateRivalApproachBottom
	msgbox Route22_Text_LateRivalIntro
	setvar VAR_LAST_TALKED, LOCALID_ROUTE22_RIVAL
	call_if_eq VAR_STARTER_MON, 3, Route22_EventScript_LateRivalEevee
	call_if_eq VAR_STARTER_MON, 2, Route22_EventScript_LateRivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, Route22_EventScript_LateRivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, Route22_EventScript_LateRivalCharmander
	msgbox Route22_Text_LateRivalPostBattle
	closemessage
	delay 10
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_EarlyRivalExitTop
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_EarlyRivalExit
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_EarlyRivalExitBottom
	fadedefaultbgm
	removeobject LOCALID_ROUTE22_RIVAL
	setvar VAR_MAP_SCENE_ROUTE22, 4
	releaseall
	end

Route22_EventScript_LateRivalApproach::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproach
	waitmovement 0
	return

Route22_EventScript_LateRivalApproachBottom::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproachBottom
	applymovement LOCALID_PLAYER, Route22_Movement_PlayerFaceRival
	waitmovement 0
	return

Route22_EventScript_LateRivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_SQUIRTLE, Route22_Text_LateRivalDefeat
	return

Route22_EventScript_LateRivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_BULBASAUR, Route22_Text_LateRivalDefeat
	return

Route22_EventScript_LateRivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_CHARMANDER, Route22_Text_LateRivalDefeat
	return

Route22_Movement_LateRivalExit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route22_EventScript_LeagueGateSign::
	msgbox Route22_Text_LeagueGateSign, MSGBOX_SIGN
	end

Route22_Text_EarlyRivalIntro::
#if GERMAN
	.string "{RIVAL}: Heh! {PLAYER}!\p"
	.string "Bist du auf dem Weg zur Pokémon\n"
	.string "Liga? Vergiss es!\p"
	.string "Wahrscheinlich besitzt du nicht\n"
	.string "einmal einen Orden!\p"
	.string "Die Wache wird dich gar nicht erst\n"
	.string "durchlassen!\p"
	.string "Ach, sind deine Pokémon eigentlich\n"
	.string "stärker geworden?$"
#else
	.string "{RIVAL}: Hey! {PLAYER}!\p"
	.string "You're off to the POKéMON LEAGUE?\n"
	.string "Forget about it!\p"
	.string "You probably don't have any\n"
	.string "BADGES, do you?\p"
	.string "The guard won't let you through\n"
	.string "without them.\p"
	.string "By the way, did your POKéMON get\n"
	.string "any stronger?$"
#endif

Route22_Text_EarlyRivalDefeat::
#if GERMAN
	.string "Oh nein! So viel Glück wie du kann\n"
	.string "man nicht haben!$"
#else
	.string "Awww!\n"
	.string "You just lucked out!$"
#endif

Route22_Text_EarlyRivalPostBattle::
#if GERMAN
	.string "In der Pokémon Liga gibt es viele\n"
	.string "starke Trainer!\p"
	.string "Ich muss einen Weg finden, an ihnen\n"
	.string "vorbeizukommen.\p"
	.string "Du solltest aufhören zu bummeln\n"
	.string "und dich in Bewegung setzen!$"
#else
	.string "I heard the POKéMON LEAGUE is\n"
	.string "crawling with tough TRAINERS.\p"
	.string "I have to figure out how to get\n"
	.string "past them.\p"
	.string "You should quit dawdling and get a\n"
	.string "move on!$"
#endif

@ Translated in RB as "{RIVAL}: What? Why do I have 2 POKéMON? You should catch some more too!"
Route22_Text_RivalShouldCatchSomeMons::
	.string "{RIVAL}“なんだ？\n"
	.string "ポケモン　2ひきも\l"
	.string "もってるの　なぜか　だって？\p"
	.string "おまえも\n"
	.string "つかまえれば　いい　じゃん！$"

Route22_Text_LateRivalIntro::
#if GERMAN
	.string "{RIVAL}: Was?! {PLAYER}!\n"
	.string "Was für eine Überraschung!\p"
	.string "Du bist also auch auf dem Weg zur\n"
	.string "Pokémon Liga, oder?\p"
	.string "Du besitzt auch alle Orden?\n"
	.string "Das ist cool!\p"
	.string "{PLAYER}, ich werde mich für die\n"
	.string "Pokémon Liga aufwärmen, indem ich dich\l"
	.string "besiege!\p"
	.string "Also, los geht es!$"
#else
	.string "{RIVAL}: What? {PLAYER}!\n"
	.string "What a surprise to see you here!\p"
	.string "So you're going to the POKéMON\n"
	.string "LEAGUE?\p"
	.string "You collected all the BADGES, too?\n"
	.string "That's cool!\p"
	.string "Then I'll whip you, {PLAYER}, as a\n"
	.string "warm-up for the POKéMON LEAGUE!\p"
	.string "Come on!$"
#endif

Route22_Text_LateRivalDefeat::
#if GERMAN
	.string "Was!?\p"
	.string "Ich war zu unvorsichtig!$"
#else
	.string "What!?\p"
	.string "I was just careless, you!$"
#endif

Route22_Text_LateRivalPostBattle::
#if GERMAN
	.string "Das war ein gutes Aufwärmtraining!\n"
	.string "Ich bin gut auf die Pokémon Liga\l"
	.string "vorbereitet!\p"
	.string "{PLAYER}, auch wenn du gewonnen\n"
	.string "hast, musst du mehr trainieren!\p"
	.string "Ich glaube, du bist dir dessen\n"
	.string "bewusst! Bis dann!$"
#else
	.string "That loosened me up.\n"
	.string "I'm ready for the POKéMON LEAGUE!\p"
	.string "{PLAYER}, you need more practice.\p"
	.string "But hey, you know that!\n"
	.string "I'm out of here. Smell ya!$"
#endif

@ Translated in RB as "{RIVAL}: Hahaha! {PLAYER}! That's your best? You're nowhere near as good as me, pal! Go train some more! You loser!"
Route22_Text_LateRivalVictory::
	.string "{RIVAL}“ひゃははッ　{PLAYER}ー！\n"
	.string "それで　がんばってるのかよ！\l"
	.string "おれの　さいのうに　くらべりゃ\l"
	.string "{PLAYER}は　まだまだ　だな！\p"
	.string "もっと　れんしゅう　こいよ！\n"
	.string "あははーッ！$"

Route22_Text_LeagueGateSign::
#if GERMAN
	.string "Pokémon Liga\n"
	.string "Haupteingang$"
#else
	.string "POKéMON LEAGUE\n"
	.string "Front Gate$"
#endif

Route22_EventScript_EarlyRivalApproachTop::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproachTop
	waitmovement 0
	return

Route22_EventScript_LateRivalApproachTop::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproachTop
	waitmovement 0
	return

Route22_EventScript_EarlyRivalExitTop::
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalExitTop
	waitmovement 0
	return

Route22_Movement_RivalApproachTop::
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

@ Origin Jade: nach Schritt 13 ist der Rivale aus dem Bild; die restlichen
@ 17 Schritte liefen unsichtbar weiter und haben den Spieler solange gesperrt.
Route22_Movement_RivalExitTop::
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route22_EventScript_EarlyRivalEevee::
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_EEVEE, RIVAL_BATTLE_TUTORIAL, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
	return

Route22_EventScript_LateRivalEevee::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_EEVEE, Route22_Text_LateRivalDefeat
	return
