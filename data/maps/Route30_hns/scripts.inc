Route30_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route30_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route30_OnFrame
	.byte 0

Route30_OnTransition:
	callnative SetTimeBasedEncounters
	@ Origin Jade: Das Duell der beiden Jungen mit ihren Pokemon haengt an
	@ FLAG_MOM_VISITED - gesetzt wird das in HnS im Haus der Mutter, wenn sie
	@ den Spieler nach dem Diebstahl verabschiedet. Diese Szene gibt es bei
	@ uns nicht, das Haus gehoert jemand anderem. Ohne das Flag stehen die
	@ vier ewig auf der Route und Joey wird nie zum Trainer.
	@ Nach dem Diebstahl (Laborzustand 5) wird beides nachgetragen.
	@ Geprueft wird FLAG_HIDE_ROUTE_30_NPCS und nicht FLAG_MOM_VISITED: bei
	@ einem neuen Spiel setzt new_game.inc FLAG_MOM_VISITED bereits mit, waehrend
	@ FLAG_HIDE_ROUTE_30_NPCS gesetzt bleibt - Joey waere dann nie als Trainer
	@ aufgetaucht.
	call_if_set FLAG_HIDE_ROUTE_30_NPCS, Route30_EventScript_SyncAfterTheft
	end

Route30_EventScript_SyncAfterTheft::
	goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 5, Route30_EventScript_EndDuel
	return

Route30_EventScript_EndDuel::
	setflag FLAG_MOM_VISITED
	clearflag FLAG_HIDE_ROUTE_30_NPCS
	return

Route30_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 2, Route30_EventScript_ElmCall_Trigger
	.2byte 0

Route30_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route30_EventScript_Boy2
	msgbox Route30_Text_YoungsterDirectionsToMrPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Boy2::
	lock
	faceplayer
	msgbox Route30_Text_YoungsterEveryoneIsBattling, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Girl::
	lock
	faceplayer
	msgbox Route30_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Youngster_Joey_Fighting::
	lock
	msgbox Route30_Text_UseTackle, 	MSGBOX_AUTOCLOSE
	waitmessage
	playse SE_PIN
	applymovement LOCALID_ROUTE_30_JOEY, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ROUTE_30_JOEY
	faceplayer
	msgbox Route30_Text_ThisIsABigBattle, MSGBOX_AUTOCLOSE
	waitmessage
	turnobject LOCALID_ROUTE_30_JOEY DIR_NORTH
	release
	end


Route30_EventScript_Youngster_Joey::
	trainerbattle_single TRAINER_JOEY_HNS, Route30_Text_YoungsterJoey1Seen, Route30_Text_YoungsterJoey1Beaten, Route30_EventScript_RegisterJoey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route30_EventScript_RematchJoey
	msgbox Route30_Text_YoungsterJoey1After, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_RegisterJoey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route30_Text_JoeyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOEY_HNS
	release
	end

Route30_EventScript_RematchJoey::
	trainerbattle_rematch TRAINER_JOEY_HNS, Route30_Text_JoeyRematchIntro, Route30_Text_JoeyRematchDefeat
	msgbox Route30_Text_JoeyPostRematch, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Youngster_Mikey::
	trainerbattle_single TRAINER_MIKEY_HNS, Route30_Text_YoungsterMikeySeen, Route30_Text_YoungsterMikeyBeaten
	msgbox Route30_Text_YoungsterMikeyAfter, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Bugcatcher_Don::
	trainerbattle_single TRAINER_DON_HNS, Route30_Text_BugCatcherDonSeen, Route30_Text_BugCatcherDonBeaten
	msgbox Route30_Text_BugCatcherDonAfter, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_ElmCall_Trigger::
	lock
	setspeaker Route30_Text_ElmName
	pokenavcall Route30_Text_Elm_Disaster
	waitmessage
	delay 30
	setvar VAR_CHERRYGROVE_CITY_STATE, 3
	release
	end

Route30_EventScript_Sign::
	lock
	msgbox Route30_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route30_EventScript_TrainerTips::
	lock
	msgbox Route30_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route30_EventScript_Poliwag::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWAG, CRY_MODE_NORMAL
	msgbox Route30_Text_Poliwag, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route30_EventScript_Mailbox::
	msgbox Route30_Text_Mailbox, MSGBOX_SIGN
	end

Route30_Text_Mailbox:
#if GERMAN
	.string "Das Haus von Mr. Pokémon$"
#else
	.string "MR.POKéMON's House$"
#endif

Route30_Text_UseTackle:
#if GERMAN
	.string "Los, Rattfratz!\p"
	.string "Tackle!$"
#else
	.string "Go, RATTATA!\p"
	.string "TACKLE!$"
#endif

Route30_Text_ThisIsABigBattle:
#if GERMAN
	.string "Was willst du? Das hier ist ein sehr\n"
	.string "wichtiger Kampf für mich, ist das klar?\l"
	.string "Lass mich in Ruhe!$"
#else
	.string "What? This is a big battle!\n"
	.string "Leave me alone!$"
#endif

Route30_Text_YoungsterJoey1Seen:
#if GERMAN
	.string "Eigentlich bin ich hier, um mein Team\n"
	.string "nach einer Niederlage aufzustocken…\p"
	.string "Aber du wirkst wie ein Schwächling auf\n"
	.string "mich. Prima! Dich knöpfe ich mir vor!$"
#else
	.string "I just lost, so I'm trying to\n"
	.string "find more POKéMON.\p"
	.string "Wait! You look weak! Come on,\n"
	.string "let's battle!$"
#endif

Route30_Text_YoungsterJoey1Beaten:
#if GERMAN
	.string "Schon wieder vermöbelt!$"
#else
	.string "Ack! I lost again!\n"
	.string "Doggone it!$"
#endif

Route30_Text_YoungsterJoey1After:
#if GERMAN
	.string "Benötige ich noch mehr Pokémon,\n"
	.string "um noch besser zu kämpfen?\p"
	.string "Nein! Ich behalte dieses, egal was\n"
	.string "passiert!$"
#else
	.string "Do I have to have more POKéMON\n"
	.string "in order to battle better?\p"
	.string "No! I'm sticking with this one\n"
	.string "no matter what!$"
#endif

Route30_Text_YoungsterMikeySeen:
#if GERMAN
	.string "Du bist doch ein Pokémon-Trainer, oder?\n"
	.string "Liefern wir uns einen Kampf!$"
#else
	.string "You're a POKéMON trainer,\n"
	.string "right?\p"
	.string "Then you have to battle!$"
#endif

Route30_Text_YoungsterMikeyBeaten:
#if GERMAN
	.string "Das ist seltsam.\n"
	.string "Vorhin habe ich haushoch gewonnen…$"
#else
	.string "That's strange.\n"
	.string "I won before.$"
#endif

Route30_Text_YoungsterMikeyAfter:
#if GERMAN
	.string "Es ist ein langer, harter Weg, bis\n"
	.string "man ein guter Trainer wird.\p"
	.string "Aber gut! Ich werde mich im Kampf gegen\n"
	.string "alle möglichen Trainer stählen!$"
#else
	.string "Becoming a good trainer is\n"
	.string "really tough.\p"
	.string "I'm going to battle other\n"
	.string "people to get better.$"
#endif

Route30_Text_BugCatcherDonSeen:
#if GERMAN
	.string "Ich suchte Käfer-Pokémon, doch ich\n"
	.string "fand einen Trainer!$"
#else
	.string "Instead of a bug POKéMON,\n"
	.string "I found a trainer!$"
#endif

Route30_Text_BugCatcherDonBeaten:
#if GERMAN
	.string "Argh! Du bist zu stark!$"
#else
	.string "Argh! You're too strong!$"
#endif

Route30_Text_BugCatcherDonAfter:
#if GERMAN
	.string "Mir sind während des Fangens die\n"
	.string "Pokébälle ausgegangen.\p"
	.string "Ich hätte mehr kaufen sollen…$"
#else
	.string "I ran out of POKé BALLS while\n"
	.string "I was catching POKéMON.\p"
	.string "I should've bought some more…$"
#endif

Route30_Text_YoungsterDirectionsToMrPokemon:
#if GERMAN
	.string "Das Haus von Mr. Pokémon ist gleich da\n"
	.string "vorne!$"
#else
	.string "MR. POKéMON's house?\n"
	.string "It's a bit farther ahead.$"
#endif

Route30_Text_YoungsterEveryoneIsBattling:
#if GERMAN
	.string "Hier oben kämpft jeder gegen jeden.\p"
	.string "Wer durchwill, kommt nicht drumherum.$"
#else
	.string "Up here everyone battles everyone.\p"
	.string "There is no way through without it.$"
#endif

Route30_Text_CooltrainerF:
#if GERMAN
	.string "Ich selbst bin keine Trainerin.\p"
	.string "Aber ich sehe genug von ihnen, um zu\n"
	.string "erkennen, wer etwas kann.\p"
	.string "Du gehörst dazu.$"
#else
	.string "I am not a trainer myself.\p"
	.string "But I see enough of them to tell who\n"
	.string "knows what they are doing.\p"
	.string "You are one of them.$"
#endif

Route30_Text_Sign:
#if GERMAN
	.string "Route 30\p"
	.string "Viola City - Rosalia City$"
#else
	.string "ROUTE 30\p"
	.string "VIOLET CITY - CHERRYGROVE CITY$"
#endif

Route30_Text_MrPokemonsHouseDirectionsSign:
#if GERMAN
	.string "Das Haus von Mr. Pokémon?\n"
	.string "Immer geradeaus!$"
#else
	.string "MR. POKéMON'S HOUSE\n"
	.string "STRAIGHT AHEAD!$"
#endif

Route30_Text_MrPokemonsHouseSign:
#if GERMAN
	.string "Das Haus von Mr. Pokémon$"
#else
	.string "MR. POKéMON'S HOUSE$"
#endif

Route30_Text_TrainerTips:
#if GERMAN
	.string "Route 30\p"
	.string "Nach Norden: Route 31 und Viola City.\n"
	.string "Nach Süden: Neuborkia.$"
#else
	.string "ROUTE 30\p"
	.string "North: ROUTE 31 and VIOLET CITY.\n"
	.string "South: NEW BARK TOWN.$"
#endif

Route30_Text_JoeyRegister:
#if GERMAN
    .string "Du bist ziemlich gut!\p"
    .string "Mein Rattfratz will wie immer sofort\n"
    .string "loslegen.\p"
    .string "Es ist mein einziges Pokémon.\n"
    .string "Mit ihm werde ich ein großer Trainer\l"
    .string "werden!\p"
    .string "Lass uns irgendwann wieder kämpfen!$"
#else
	.string "You're pretty good!\p"
	.string "My RATTATA's raring to go,\n"
	.string "just like always.\p"
	.string "It's the only one I have.\n"
	.string "I'm going to become a great\l"
	.string "TRAINER with it!\p"
	.string "Let's battle again sometime!$"
#endif

Route30_Text_JoeyRematchIntro:
#if GERMAN
    .string "Ich habe versprochen, dass es\n"
    .string "diesmal anders wird! Los geht’s!$"
#else
	.string "I promised things would be\n"
	.string "different! Let's battle!$"
#endif

Route30_Text_JoeyRematchDefeat:
#if GERMAN
    .string "Ach! Schon wieder verloren!\n"
    .string "So ein Mist!$"
#else
	.string "Ack! I lost again!\n"
	.string "Doggone it!$"
#endif

Route30_Text_JoeyPostRematch:
#if GERMAN
    .string "Ich überprüfe die Attacken meines\n"
    .string "Rattfratz und tüftele an neuen\l"
    .string "Strategien.\p"
    .string "Wenn ich eine gute gefunden habe,\n"
    .string "kämpfen wir wieder!$"
#else
	.string "I'm checking out my\n"
	.string "RATTATA's moves and devising\l"
	.string "some strategies.\p"
	.string "When I come up with a good\n"
	.string "one, let's battle!$"
#endif

Route30_Text_YoungsterJoeyGiveHPUp:
#if GERMAN
	.string "Ich habe schon wieder verloren…\n"
	.string "Mann, du bist echt stark!\p"
	.string "Oh ja, fast hätte ich vergessen,\n"
	.string "dir das hier zu geben.\p"
	.string "Benutz es, um noch stärker zu\n"
	.string "werden, okay?\p"
	.string "Ich werde auch stärker werden.$"
#else
	.string "I lost again…\n"
	.string "Gee, you're tough!\p"
	.string "Oh yeah, I almost forgot that\n"
	.string "I had to give you this.\p"
	.string "Use it to get even tougher,\n"
	.string "OK?\p"
	.string "I'm going to get tougher too.$"
#endif

Route30_Text_ElmName:
#if GERMAN
	.string "Lind$"
#else
	.string "PROF.ELM$"
#endif

Route30_Text_Elm_Disaster:
#if GERMAN
	.string "H-hallo, {PLAYER}? Es ist\n"
	.string "schrecklich! Äh… uhm… wie soll ich\l"
	.string "das erklären?\p"
	.string "Ich weiß ja selbst nicht, wie…\n"
	.string "Jedenfalls ist es ganz\l"
	.string "schrecklich!\p"
	.string "Bitte, komm schnell zurück!$"
#else
	.string "PROF.ELM: H-hello? {PLAYER}? It's\n"
	.string "a disaster!\p"
	.string "Uh, um, it's just terrible!\p"
	.string "What should I do? It… Oh, no…\p"
	.string "Please get back here now!$"
#endif


Route30_Text_Poliwag:
#if GERMAN
	.string "Quapsel: Quap Quaap!$"
#else
	.string "POLIWAG: Wag waag!$"
#endif
