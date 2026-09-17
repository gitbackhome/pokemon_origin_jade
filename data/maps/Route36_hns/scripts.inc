Route36_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route36_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route36_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route36_EventScript_RockSmashGuy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_RockSmashGuy2
	msgbox Route36_Text_RockSmashGuy1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_RockSmashGuy2::
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, Route36_EventScript_RockSmashGuy3
	@ Origin Jade: Wer aus Kanto kommt, hat die VM laengst.
	checkitem ITEM_HM_ROCK_SMASH
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_RockSmashGuyHasHM
	msgbox Route36_Text_RockSmashGuy2, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
Route36_EventScript_RockSmashGuy3::
	msgbox Route36_Text_RockSmashGuy3
	closemessage
	release
	end

Route36_EventScript_RockSmashGuyHasHM::
	msgbox Route36_Text_RockSmashGuyHasHM, MSGBOX_DEFAULT
	giveitem ITEM_HARD_STONE
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	closemessage
	release
	end

Route36_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_Lass2
	msgbox Route36_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_Lass2::
	msgbox Route36_Text_Lass2_ClearedSudowoodo, MSGBOX_DEFAULT
	closemessage
	release
	end

Route36_EventScript_Arthur::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HARD_STONE, Route36_EventScript_ArthurCompleted
	msgbox Route36_Text_MeetArthur, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route36_EventScript_ArthurNope
	case 1, Route36_EventScript_ArthurNope
	case 2, Route36_EventScript_ArthurNope
	case 3, Route36_EventScript_ArthurNope
	case 4, Route36_EventScript_ArthurYes
	case 5, Route36_EventScript_ArthurNope
	case 6, Route36_EventScript_ArthurNope
	case 7, Route36_EventScript_ArthurCancel
	case MULTI_B_PRESSED, Route36_EventScript_ArthurCancel
	closemessage
	release
	end
Route36_EventScript_ArthurYes::
	msgbox Route36_Text_ArthurGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_HARD_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_HARD_STONE
	msgbox Route36_Text_ArthurGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurNope::
	msgbox Route36_Text_ArthurNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurCancel::
	closemessage
	release
	end
Route36_EventScript_ArthurCompleted::
	msgbox Route36_Text_ArthurThursday, MSGBOX_DEFAULT
	closemessage
	release
	end


Route36_EventScript_SudoWoodo::
	lock
	msgbox Route36_Text_OddTree, MSGBOX_DEFAULT
	checkitem ITEM_SQUIRT_BOTTLE
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoChoice
	closemessage
	release
	end
Route36_EventScript_SudoWoodoChoice::
	msgbox Route36_Text_UseSquirtbottle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoWater
	closemessage
	release
	end
Route36_EventScript_SudoWoodoWater::
	msgbox Route36_Text_UsedSquirtbottle, MSGBOX_DEFAULT
	playse SE_DOWNPOUR
	waitse
	closemessage
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_ROUTE36_SUDOWOODO, Route36_Movement_SudoWoodo
	waitmovement 0
	faceplayer
	msgbox Route36_Text_SudowoodoAttacked
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_ROUTE36_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 20
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route36_EventScript_Defeated_Sudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route36_EventScript_RanSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route36_EventScript_RanSudowoodo
Route36_EventScript_Defeated_Sudowoodo::
	setflag FLAG_HIDE_SUDOWOODO
	removeobject LOCALID_ROUTE36_SUDOWOODO
	checkitem ITEM_HM_ROCK_SMASH
	call_if_eq VAR_RESULT, FALSE, Route36_EventScript_RockSmashGuySudoWoodo
	release
	end

Route36_EventScript_RanSudowoodo::
	turnobject LOCALID_ROUTE36_SUDOWOODO, DIR_NORTH
	release
	end

Route36_EventScript_RockSmashGuySudoWoodo:
	playse SE_PIN
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Common_Movement_ExclamationMark
	turnobject LOCALID_ROUTE36_ROCKSMASHGUY, DIR_WEST
	waitmovement 0
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Route36_Movement_RockSmashGuy
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	return

Route36_Movement_RockSmashGuy:
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	step_end

Route36_EventScript_Mark::
	trainerbattle_single TRAINER_MARK_HNS, Route36_Text_PsychicMarkSeen, Route36_Text_PsychicMarkBeaten
	msgbox Route36_Text_PsychicMarkAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Schoolboy::
	trainerbattle_single TRAINER_ALAN_HNS, Route36_Text_SchoolboyAlan1Seen, Route36_Text_SchoolboyAlan1Beaten, Route36_EventScript_RegisterAlan
	goto_if_set FLAG_ALAN_HAS_ITEM_HNS, Route36_EventScript_AlanGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_RematchAlan
	msgbox Route36_Text_SchoolboyAlanAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_RegisterAlan::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route36_Text_AlanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ALAN_HNS
	release
	end

Route36_EventScript_RematchAlan::
	trainerbattle_rematch TRAINER_ALAN_HNS, Route36_Text_AlanRematchIntro, Route36_Text_AlanRematchDefeat
	msgbox Route36_Text_AlanPostRematch, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_AlanGiveItem::
	msgbox Route36_Text_AlanHasItem, MSGBOX_DEFAULT
	giveitem VAR_ALAN_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route36_EventScript_AlanNoRoom
	clearflag FLAG_ALAN_HAS_ITEM_HNS
	msgbox Route36_Text_AlanGaveItem, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_AlanNoRoom::
	msgbox Route36_Text_AlanNoRoom, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Sign::
	lock
	msgbox Route36_Text_Sign_RuinsNorth, MSGBOX_SIGN
	closemessage
	release
	end

Route36_EventScript_Sign2::
	lock
	msgbox Route36_Text_Tips1, MSGBOX_SIGN
	closemessage
	release
	end

Route36_Movement_SudoWoodo:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

Route36_Text_UseSquirtbottle:
#if GERMAN
	.string "Das ist ein merkwürdiger Baum.\n"
	.string "Möchtest du die Schiggykanne benutzen?$"
#else
	.string "Use SQUIRTBOTTLE?$"
#endif

Route36_Text_UsedSquirtbottle:
#if GERMAN
	.string "{PLAYER} setzt die Schiggykanne ein!$"
#else
	.string "{PLAYER} used the SQUIRTBOTTLE.$"
#endif

Route36_Text_SudowoodoAttacked:
#if GERMAN
	.string "Der merkwürdige Baum krümmt sich unter\n"
	.string "dem Wasser aus der Schiggykanne!\p"
	.string "Er greift dich an!$"
#else
	.string "The weird tree doesn't like the\n"
	.string "SQUIRTBOTTLE!\p"
	.string "The weird tree attacked!$"
#endif

Route36_Text_RockSmashGuy1:
#if GERMAN
	.string "Wat is los!\p"
	.string "Ich wollte diesen Baum mit einem\n"
	.string "geraden Schlag fällen.\p"
	.string "Aber es ging nicht!\n"
	.string "Ich bin ein Versager!$"
#else
	.string "Wa-hey!\p"
	.string "I was going to snap that tree\n"
	.string "with my straight-arm punch.\p"
	.string "But I couldn't! I'm a failure!$"
#endif

Route36_Text_RockSmashGuy2:
#if GERMAN
	.string "Hast du diesen lästigen Baum\n"
	.string "beseitigt?\p"
	.string "Ich bin beeindruckt!\n"
	.string "Das hier sollst du haben.$"
#else
	.string "Did you clear that wretched tree?\p"
	.string "I'm impressed!\n"
	.string "I want you to have this.$"
#endif

Route36_Text_RockSmashGuy3:
#if GERMAN
	.string "Das ist übrigens Zertrümmerer.\p"
	.string "Damit kannst du Felsen mit einem\n"
	.string "gezielten Hieb zertrümmern.\p"
	.string "Sind dir Steine im Weg, schlag sie\n"
	.string "einfach kaputt!$"
#else
	.string "That happens to be ROCK SMASH.\p"
	.string "You can shatter rocks with just a\n"
	.string "single well-aimed smack.\p"
	.string "If any rocks are in your way,\n"
	.string "just smash 'em up!$"
#endif

Route36_Text_OddTree:
#if GERMAN
	.string "Ein seltsamer Baum versperrt\n"
	.string "den Weg.$"
#else
	.string "A weird tree is blocking the way.$"
#endif

Route36_Text_Lass1:
#if GERMAN
	.string "Ein merkwürdiger Baum blockiert die\n"
	.string "Straße nach Dukatia City.\p"
	.string "Wegen dieses Baumes kann ich\n"
	.string "nicht einkaufen gehen.\p"
	.string "Man sollte etwas dagegen tun.$"
#else
	.string "Be careful at night on this route!\p"
	.string "I saw a POKéMON that looked like\n"
	.string "GROWLITHE, but it had a scary aura\l"
	.string "to it.$"
#endif

Route36_Text_Lass2_ClearedSudowoodo:
#if GERMAN
	.string "Dieser merkwürdige Baum ist spurlos\n"
	.string "verschwunden.\p"
	.string "Ach! Der Baum war in Wirklichkeit ein\n"
	.string "Pokémon?$"
#else
	.string "That odd tree disappeared without\n"
	.string "a trace.\p"
	.string "Oh! That tree was really a\n"
	.string "POKéMON?$"
#endif

Route36_Text_PsychicMarkSeen:
#if GERMAN
	.string "Ich werde jetzt deine Gedanken lesen!$"
#else
	.string "I'm going to read your thoughts!$"
#endif

Route36_Text_PsychicMarkBeaten:
#if GERMAN
	.string "Ich habe mich wohl bei dir verlesen!$"
#else
	.string "I misread you!$"
#endif

Route36_Text_PsychicMarkAfter:
#if GERMAN
	.string "Wenn ich doch bloß die Gedanken\n"
	.string "meiner Gegner lesen könnte.$"
#else
	.string "I'd be strong if only I could tell\n"
	.string "what my opponent was thinking.$"
#endif

Route36_Text_SchoolboyAlan1Seen:
#if GERMAN
	.string "Dank meiner Studien bin ich für jedes\n"
	.string "Pokémon bereit!$"
#else
	.string "Thanks to my studies, I'm ready\n"
	.string "for any POKéMON!$"
#endif

Route36_Text_SchoolboyAlan1Beaten:
#if GERMAN
	.string "Ups! Ein Fehler in der Berechnung?$"
#else
	.string "Oops! Computation error?$"
#endif

Route36_Text_SchoolboyAlanAfter:
#if GERMAN
	.string "Mist. Ich lerne fünf Stunden am Tag.\p"
	.string "Zum Lernen gehört mehr als nur Bücher\n"
	.string "zu lesen.$"
#else
	.string "Darn. I study five hours a day too.\p"
	.string "There's more to learning than just\n"
	.string "reading books.$"
#endif

Route36_Text_MeetArthur:
#if GERMAN
	.string "Donatus: Wer bist du?\n"
	.string "Ich bin Donatus von der\l"
	.string "Wochentagsfamilie.\p"
	.string "Wenn du meinen Lieblingstag errätst,\n"
	.string "gebe ich dir eine Belohnung.$"
#else
	.string "ARTHUR: Who are you?\n"
	.string "I'm ARTHUR of the WEEKDAY FAMILY.\p"
	.string "If you can guess my favorite day,\n"
	.string "I'll give you a reward.$"
#endif

Route36_Text_ArthurNope:
#if GERMAN
	.string "Nicht ganz!$"
#else
	.string "Not quite!$"
#endif

Route36_Text_ArthurGivesGift:
#if GERMAN
	.string "Hier bitte. Das kannst du haben.$"
#else
	.string "Here. You can have this.$"
#endif

Route36_Text_ArthurGaveGift:
#if GERMAN
	.string "Donatus: Ich mag Stein, Stein ist schön\n"
	.string "und stark.\p"
	.string "Huhuhuheheheh.$"
#else
	.string "ARTHUR: A POKéMON that uses ROCK-\n"
	.string "type moves should hold on to that.\p"
	.string "It pumps up ROCK-type attacks.$"
#endif

Route36_Text_ArthurThursday:
#if GERMAN
	.string "Donatus: Ich bin Donatus vom\n"
	.string "Donnerstag.\p"
	.string "Ich in der fünfte Sohn von sieben.$"
#else
	.string "ARTHUR: I'm ARTHUR of Thursday.\n"
	.string "I'm the fifth son out of seven.$"
#endif

Route36_Text_Sign:
#if GERMAN
	.string "Route 36$"
#else
	.string "ROUTE 36$"
#endif

Route36_Text_Sign_RuinsNorth:
#if GERMAN
	.string "Alph-Ruinen\n"
	.string "Nordeingang$"
#else
	.string "RUINS OF ALPH\n"
	.string "NORTH ENTRANCE$"
#endif

Route36_Text_Tips1:
#if GERMAN
	.string "Route 36\p"
	.string "Westlich liegt Teak City,\n"
	.string "östlich die Ruinen von Alph.$"
#else
	.string "ROUTE 36\p"
	.string "ECRUTEAK CITY lies to the west,\n"
	.string "the RUINS OF ALPH to the east.$"
#endif

Route36_Text_Tips2:
#if GERMAN
	.string "Route 36\p"
	.string "Achtung, Wurzeln und loses Geröll.\n"
	.string "Wanderer bitte vorsichtig gehen.$"
#else
	.string "ROUTE 36\p"
	.string "Watch for roots and loose stones.\n"
	.string "Travellers, tread carefully.$"
#endif

Route36_Text_AlanRegister:
#if GERMAN
    .string "Verdammt. Ich lerne auch fünf\n"
    .string "Stunden am Tag.\p"
    .string "Zum Lernen gehört mehr, als nur\n"
    .string "Bücher zu lesen.$"
#else
	.string "Darn. I study five hours a day too.\p"
	.string "There's more to learning than just\n"
	.string "reading books.$"
#endif

Route36_Text_AlanRematchIntro:
#if GERMAN
    .string "Dank meines Studiums bin ich auf\n"
    .string "jedes Pokémon vorbereitet!$"
#else
	.string "Thanks to my studies, I'm ready\n"
	.string "for any POKéMON!$"
#endif

Route36_Text_AlanRematchDefeat:
#if GERMAN
    .string "Ups! Rechenfehler?$"
#else
	.string "Oops! Computation error?$"
#endif

Route36_Text_AlanPostRematch:
#if GERMAN
    .string "Verdammt. Ich lerne auch fünf\n"
    .string "Stunden am Tag.\p"
    .string "Zum Lernen gehört mehr, als nur\n"
    .string "Bücher zu lesen.$"
#else
	.string "Darn. I study five hours a day too.\p"
	.string "There's more to learning than just\n"
	.string "reading books.$"
#endif

Route36_Text_AlanHasItem:
#if GERMAN
    .string "Hey! Ich habe beim Lernen etwas\n"
    .string "gefunden!\p"
    .string "Hier, du kannst es haben!$"
#else
	.string "Hey! I found something\n"
	.string "while studying!\p"
	.string "Here, you can have it!$"
#endif

Route36_Text_AlanGaveItem:
#if GERMAN
    .string "Ich sage dir Bescheid, wenn ich\n"
    .string "noch etwas finde!$"
#else
	.string "I'll let you know if I find\n"
	.string "anything else!$"
#endif

Route36_Text_AlanNoRoom:
#if GERMAN
    .string "Hm, dein Beutel ist voll.\p"
    .string "Komm wieder, wenn du Platz hast.$"
#else
	.string "Hmm, your BAG is full.\p"
	.string "Come back when you have room.$"
#endif

Route36_Text_RockSmashGuyHasHM:
#if GERMAN
	.string "Der Brocken lag hier, seit ich denken\n"
	.string "kann. Und du räumst ihn weg, als wäre\l"
	.string "er Kies.\p"
	.string "Den Zertrümmerer wollte ich dir geben.\n"
	.string "Brauchst du offenbar nicht.\p"
	.string "Nimm den hier. Der hält, was er\n"
	.string "verspricht.$"
#else
	.string "That rock sat here as long as I can\n"
	.string "remember. You clear it like gravel.\p"
	.string "I meant to give you ROCK SMASH. You\n"
	.string "clearly don't need it.\p"
	.string "Take this instead. It holds up.$"
#endif

