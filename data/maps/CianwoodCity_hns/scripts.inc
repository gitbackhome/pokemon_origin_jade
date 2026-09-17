CianwoodCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CianwoodCity_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, CianwoodCity_EventScript_InitializeSuicune
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

CianwoodCity_RemoveEusine::
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	end

CianwoodCity_OnFrame::
	map_script_2 VAR_GETFLY, 1, CianwoodCity_EventScript_Flytrigger
	.2byte 0

CianwoodCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CIANWOOD_CITY
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

CianwoodCity_EventScript_InitializeSuicune::
	goto_if_ge VAR_SUICUNE_ENCOUNTERS, 2, CianwoodCity_EventScript_InitializeNothing
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setvar VAR_TEMP_0, 1
	end

CianwoodCity_EventScript_InitializeNothing::
	setvar VAR_TEMP_0, 1
	end

CianwoodCity_EventScript_Flytrigger::
	lock
	playse SE_PIN
	applymovement LOCALID_CIANWOOD_CHUCKSWIFE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_CIANWOOD_CHUCKSWIFE
	applymovement LOCALID_CIANWOOD_CHUCKSWIFE, CianwoodCity_Movement_ChucksWife
	waitmovement 0
	@ Origin Jade: Wer aus Kanto kommt, hat Fliegen laengst.
	checkitem ITEM_HM_FLY
	goto_if_eq VAR_RESULT, TRUE, CianwoodCity_EventScript_FlytriggerHasFly
	msgbox CianwoodCity_Text_ChucksWifeGiveHM, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLY
	msgbox CianwoodCity_Text_ChucksWifeFlySpeech, MSGBOX_DEFAULT
CianwoodCity_EventScript_FlytriggerDone::
	closemessage
	setvar VAR_GETFLY, 2
	goto_if_eq VAR_TRIGGER_ELM_ROCKET_CALL, 1, Mahoganytown_EventScript_RocketTrigger
	release
	end

CianwoodCity_EventScript_FlytriggerHasFly::
	msgbox CianwoodCity_Text_ChucksWifeHasFly, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK
	goto CianwoodCity_EventScript_FlytriggerDone

CianwoodCity_Movement_ChucksWife:
	walk_left
	walk_left
	walk_up
	walk_left
	face_up
	step_end

CianwoodCity_EventScript_Test::
	lock
	random 2
	call_if_eq VAR_RESULT, 1, EventScript_RockSmashHeartscale
	release
	end

CianwoodCity_EventScript_ChucksWife::
	lock
	faceplayer
	checkitem ITEM_HM_FLY
	goto_if_eq VAR_RESULT, TRUE, CianwoodCity_EventScript_ChucksWifeAlreadyHasFly
	msgbox CianwoodCity_Text_ChucksWifeEasierToFly, MSGBOX_DEFAULT
	goto_if_set FLAG_BADGE05_GET, CianwoodCity_EventScript_ChucksWifeGiveFly
	msgbox CianwoodCity_Text_ChucksWifeBeatChuck, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_ChucksWifeGiveFly::
	msgbox CianwoodCity_Text_ChucksWifeGiveHM, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLY
	msgbox CianwoodCity_Text_ChucksWifeFlySpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_ChucksWifeAlreadyHasFly::
	msgbox CianwoodCity_Text_ChucksWifeChubby, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_ChucksWifeEasierToFly:
#if GERMAN
	.string "Du hast auf dem Weg hierher doch\n"
	.string "bestimmt das Meer überquert, oder?\p"
	.string "Würde eines deiner Pokémon die Attacke\n"
	.string "Fliegen beherrschen, hättest du dir den\l"
	.string "ganzen Ärger sparen können!$"
#else
	.string "You crossed the sea to get here?\p"
	.string "That must have been hard.\p"
	.string "It would be much easier if your\n"
	.string "POKéMON knew how to FLY...$"
#endif

CianwoodCity_Text_ChucksWifeBeatChuck:
#if GERMAN
	.string "Aber dafür hättest du natürlich auch\n"
	.string "den passenden Orden gebraucht!\l"
	.string "Komm wieder, wenn du den Arenaleiter\l"
	.string "dieser Stadt besiegt hast!\l"
	.string "Dann bekommst du etwas von mir!$"
#else
	.string "But you can't use FLY without this\n"
	.string "city's GYM BADGE.\p"
	.string "If you beat the GYM LEADER here,\n"
	.string "come see me.\p"
	.string "I'll have a nice gift for you.$"
#endif

CianwoodCity_Text_ChucksWifeGiveHM:
#if GERMAN
	.string "Du hast den Orden von Anemonia City!\p"
	.string "Gut, dann will ich dir diese VM schenken!$"
#else
	.string "That's CIANWOOD's GYM BADGE!\p"
	.string "Then you should take this HM.$"
#endif

CianwoodCity_Text_ChucksWifeFlySpeech:
#if GERMAN
	.string "Wenn du einem deiner Pokémon die\n"
	.string "Attacke Fliegen beibringst, kannst du\l"
	.string "sofort in jede beliebige Stadt düsen,\l"
	.string "die du bisher besucht hast.$"
#else
	.string "Teach FLY to your POKéMON.\p"
	.string "You will be able to FLY instantly\n"
	.string "to anywhere you have visited.$"
#endif

CianwoodCity_Text_ChucksWifeChubby:
#if GERMAN
	.string "Hihihi! Mein Mann versucht, härter zu\n"
	.string "trainieren, weil du ihn besiegt hast.\p"
	.string "Das trifft sich gut, denn er hat in\n"
	.string "letzter Zeit etwas Speck angesetzt!$"
#else
	.string "My husband lost to you, so he needs\n"
	.string "to train harder.\p"
	.string "That's good, since he was getting\n"
	.string "a little chubby.$"
#endif

CianwoodCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox CianwoodCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_Youngster:
#if GERMAN
	.string "Wenn eins deiner Pokémon die Attacke\n"
	.string "Fliegen gelernt hat, gelangst du auch im\l"
	.string "Handumdrehen bis nach Oliviana City!$"
#else
	.string "If you use FLY, you can get back\n"
	.string "to OLIVINE instantly.$"
#endif

CianwoodCity_EventScript_PokefanM::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokefanM:
#if GERMAN
	.string "Hinter den Felsen nördlich der Stadt\n"
	.string "findest du viele interessante Items!\p"
	.string "Um sie zu finden, musst du lediglich\n"
	.string "einem deiner Pokémon den Befehl geben,\l"
	.string "die Attacke Zertrümmerer einzusetzen!$"
#else
	.string "Boulders to the north of town can\n"
	.string "be crushed.\p"
	.string "They may be hiding something.\p"
	.string "Your POKéMON could use ROCK SMASH\n"
	.string "to break them.$"
#endif

CianwoodCity_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_Lass:
#if GERMAN
	.string "Hartwig, der Arenaleiter, steigt gerne\n"
	.string "selbst gegen seine Kampf-Pokémon in\l"
	.string "den Ring, um sie abzuhärten.$"
#else
	.string "CHUCK, the GYM LEADER, spars with\n"
	.string "his fighting POKéMON.$"
#endif

CianwoodCity_EventScript_SuicuneTrigger::
	lock
	hidefollower 1
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_CIANWOOD_SUICUNE, CianwoodCity_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement LOCALID_CIANWOOD_SUICUNE, CianwoodCity_Movement_Suicune2
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_CIANWOOD_SUICUNE, CianwoodCity_Movement_Suicune3
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	delay 30
	playbgm MUS_HG_EUSINE, FALSE
	clearflag FLAG_HIDE_CIANWOOD_EUSINE
	addobject LOCALID_CIANWOOD_EUSINE
	applymovement LOCALID_CIANWOOD_EUSINE, CianwoodCity_Movement_Eusine1
	waitmovement 0
	delay 55
	applymovement LOCALID_CIANWOOD_EUSINE, CianwoodCity_Movement_Eusine2
	waitmovement 0
	msgbox CianwoodCity_Text_EusineSuicune, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_EUSINE_HNS, CianwoodCity_Text_EusineBeaten
	playbgm MUS_HG_EUSINE, FALSE
	msgbox CianwoodCity_Text_EusineAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CIANWOOD_EUSINE, CianwoodCity_Movement_Eusine3
	waitmovement 0
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setflag FLAG_HIDE_CIANWOOD_SUICUNE
	removeobject LOCALID_CIANWOOD_SUICUNE
	removeobject LOCALID_CIANWOOD_EUSINE
	setvar VAR_SUICUNE_ENCOUNTERS, 2
	setvar VAR_CIANWOOD_CITY_STATE, 2
	fadedefaultbgm
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, CianwoodCity_EventScript_DoneJohtoSuicune
	release
	end

CianwoodCity_EventScript_DoneJohtoSuicune::
	setvar VAR_SUICUNE_ENCOUNTERS, 3
	return

CianwoodCity_Movement_Suicune1:
	jump_in_place_right_left
	jump_in_place_right_left
	face_down
	step_end

CianwoodCity_Movement_Suicune2:
	jump_down
	jump_2_down
	jump_right
	face_up
	step_end

CianwoodCity_Movement_Suicune3:
	jump_2_down
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	step_end

CianwoodCity_Movement_Eusine1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_right
	step_end

CianwoodCity_Movement_Eusine2:
	face_up
	walk_up
	walk_up
	step_end

CianwoodCity_Movement_Eusine3:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

CianwoodCity_Text_EusineSuicune:
#if GERMAN
	.string "Eusin: Hallo, {PLAYER}!\p"
	.string "Sag mal… war das eben nicht Suicune?\p"
	.string "Ich konnte es nicht richtig erkennen,\n"
	.string "aber für den Hauch einer Sekunde meinte\l"
	.string "ich wirklich, gesehen zu haben, wie da\l"
	.string "Suicune über das Meer gebrettert ist.\p"
	.string "Suicune ist so schön und so stolz…\p"
	.string "Außerdem läuft es mit atemberaubender\n"
	.string "Geschwindigkeit Städte und Straßen ab!\p"
	.string "Es ist einfach ein wundervolles Pokémon.\p"
	.string "Ich würde es nur zu gerne mal aus\n"
	.string "nächster Nähe sehen…\p"
	.string "Los, lass uns kämpfen! Wenn ich dich\n"
	.string "besiege, erkennt mich Suicune\l"
	.string "vielleicht als würdigen Trainer an!\p"
	.string "Komm schon, {PLAYER}!$"
#else
	.string "EUSINE: Yo, {PLAYER}.\p"
	.string "Wasn't that SUICUNE just now?\p"
	.string "I only caught a quick glimpse, but\n"
	.string "I thought I saw SUICUNE running on\l"
	.string "the waves.\p"
	.string "SUICUNE is beautiful and grand.\p"
	.string "And it races through towns and\n"
	.string "roads at simply awesome speeds.\p"
	.string "It's wonderful…\p"
	.string "I want to see SUICUNE up close…\p"
	.string "I've decided.\p"
	.string "I'll battle you as a trainer to\n"
	.string "earn SUICUNE's respect!\p"
	.string "Come on, {PLAYER}. Let's battle now!$"
#endif

CianwoodCity_Text_EusineBeaten:
#if GERMAN
	.string "Ich sage es ungern, aber du gewinnst!$"
#else
	.string "I hate to admit it, but you win.$"
#endif

CianwoodCity_Text_EusineAfter:
#if GERMAN
	.string "Du bist unglaublich, {PLAYER}!\p"
	.string "Kein Wunder, dass Pokémon sich zu dir\n"
	.string "hingezogen fühlen.\p"
	.string "Jetzt verstehe ich es.\p"
	.string "Ich werde weiter nach Suicune suchen.\p"
	.string "Wir werden uns sicher wiedersehen.\p"
	.string "Bis dann!$"
#else
	.string "You're amazing, {PLAYER}!\p"
	.string "No wonder POKéMON gravitate to you.\p"
	.string "I get it now.\p"
	.string "I'm going to keep searching for\n"
	.string "SUICUNE.\p"
	.string "I'm sure we'll see each other again.\p"
	.string "See you around!$"
#endif

CianwoodCity_EventScript_CitySign::
	lock
	msgbox CianwoodCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_Text_Sign:
#if GERMAN
	.string "Anemonia City\p"
	.string "Ein Hafen in der rauen See$"
#else
	.string "CIANWOOD CITY\p"
	.string "A Port Surrounded by Rough Seas$"
#endif

CianwoodCity_EventScript_GymSign::
	lock
	msgbox CianwoodCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_Text_GymSign:
#if GERMAN
	.string "Pokémon-Arena von Anemonia City\n"
	.string "Leiter: Hartwig Er lässt lieber seine\l"
	.string "Fäuste für sich sprechen!$"
#else
	.string "CIANWOOD CITY POKéMON GYM\p"
	.string "LEADER: CHUCK\p"
	.string "His Roaring Fists Do the Talking$"
#endif

CianwoodCity_EventScript_Pharmacy::
	lock
	msgbox CianwoodCity_Text_PharmacySign, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_Text_PharmacySign:
#if GERMAN
	.string "Apotheke von Anemonia City\p"
	.string "Seit 500 Jahren im Geschäft.\n"
	.string "Wir haben immer ein offenes Ohr für\l"
	.string "medizinische Fragen aller Art!$"
#else
	.string "500 Years of Tradition\p"
	.string "CIANWOOD CITY PHARMACY\p"
	.string "We Await Your Medicinal Queries$"
#endif

CianwoodCity_EventScript_CaveSign::
	lock
	msgbox CianwoodCity_Text_Safari, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_EventScript_Engineer::
	lock
	faceplayer
	msgbox CianwoodCity_Text_Engineer, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_Safari:
#if GERMAN
	.string "Felsschlundhöhle Weg zur Safari-Zone.$"
#else
	.string "CLIFF EDGE CAVE\n"
	.string "Road to the SAFARI ZONE.$"
#endif

CianwoodCity_Text_Engineer:
#if GERMAN
	.string "Hier sind aktuell Bauarbeiten.\n"
	.string "Wir gestalten die neue Safari-Zone, du\l"
	.string "musst noch warten.$"
#else
	.string "This path is under construction.\n"
	.string "We're getting the new SAFARI ZONE\l"
	.string "up and running!$"
#endif

CianwoodCity_Text_ChucksWifeHasFly:
#if GERMAN
	.string "Warte doch! Ich wollte dir Fliegen\n"
	.string "mitgeben, für den Rückweg übers Meer.\p"
	.string "Du hast es. Natürlich hast du es.\p"
	.string "Dann nimm wenigstens das hier. Es lag\n"
	.string "in Chucks Trainingsschuppen und er\l"
	.string "merkt es nicht.$"
#else
	.string "Wait! I meant to give you FLY, for the\n"
	.string "way back across the sea.\p"
	.string "You have it. Of course you have it.\p"
	.string "Then take this at least. It was in\n"
	.string "CHUCK's training shed and he won't\l"
	.string "notice.$"
#endif
