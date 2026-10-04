CherrygroveCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CherryGroveCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

CherryGroveCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

CherryGroveCity_EventScript_TriggerGent_Top::
	lock
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	setflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	playse SE_PIN
	applymovement LOCALID_GUIDE_GENT, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GUIDE_GENT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox CherrygroveCity_Text_GuideGentIntro, MSGBOX_YESNO
	waitmessage
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_TriggerGent_Cancel
	msgbox CherrygroveCity_Text_GuideGentTourStart, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Top
	waitmovement 0
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Trigger_Gent
	waitmovement 0
	goto CherryGroveCity_EventScript_GentTour
	release
	end

CherryGroveCity_EventScript_TriggerGent_Mid::
	lock
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	setflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	playse SE_PIN
	applymovement LOCALID_GUIDE_GENT, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GUIDE_GENT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox CherrygroveCity_Text_GuideGentIntro, MSGBOX_YESNO
	waitmessage
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_TriggerGent_Cancel
	msgbox CherrygroveCity_Text_GuideGentTourStart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Trigger_Gent
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto CherryGroveCity_EventScript_GentTour
	release
	end

CherryGroveCity_EventScript_TriggerGent_Bottom::
	lock
	setflag FLAG_VISITED_CHERRYGROVE_CITY
	setflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	playse SE_PIN
	applymovement LOCALID_GUIDE_GENT, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GUIDE_GENT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox CherrygroveCity_Text_GuideGentIntro, MSGBOX_YESNO
	waitmessage
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_TriggerGent_Cancel
	msgbox CherrygroveCity_Text_GuideGentTourStart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Trigger_Gent
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Bottom
	waitmovement 0
	goto CherryGroveCity_EventScript_GentTour
	release
	end

CherryGroveCity_EventScript_TriggerGent_Cancel::
	msgbox CherrygroveCity_Text_GuideGentDecline, MSGBOX_DEFAULT
	closemessage
	setvar VAR_CHERRYGROVE_CITY_STATE, 1 @ CHANGE THIS TO 1 LATER
	release
	end

CherryGroveCity_EventScript_GentTour::
	playbgm MUS_HG_FOLLOW_ME_2, FALSE
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Pokecenter
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Pokecenter
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentPokecenter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Pokemart
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Pokemart
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentMart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Route30
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Route30
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentRoute30, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Sea
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Sea
	waitmovement 0
	waitmovement 0
	msgbox CherrygroveCity_Text_GuideGentSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_House_Gent
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_House_Player
	waitmovement 0
	waitmovement 0
	delay 20
	msgbox CherrygroveCity_Text_GuideGentMap, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_GUIDE_GENT, CherryGroveCity_Movement_Gent_Leave
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 20
	opendoor 42, 14
	waitdooranim
	waitmovement 0
	removeobject LOCALID_GUIDE_GENT
	closedoor 42, 14
	waitdooranim

	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
	setvar VAR_CHERRYGROVE_CITY_STATE, 1
	fadedefaultbgm
	release
	end

CherryGroveCity_EventScript_Fisherman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MYSTICWATER, CherryGroveCity_EventScript_Fisherman2
	msgbox CherrygroveCity_Text_MysticWaterGuyBefore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CherryGroveCity_EventScript_Fisherman2
	giveitem ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_MYSTICWATER
	release
	end

CherryGroveCity_EventScript_Fisherman2::
	msgbox CherrygroveCity_Text_MysticWaterGuyAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Lass::
	lock
	faceplayer
	msgbox CherrygroveCity_Text_TeacherHaveMapCard, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, CherryGroveCity_EventScript_Boy2
	msgbox CherrygroveCity_Text_YoungsterNoPokedex, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Boy2::
	msgbox CherrygroveCity_Text_YoungsterHavePokedex, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGroveCity_EventScript_Staryu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARYU, CRY_MODE_NORMAL
	msgbox CherryGroveCity_Text_Staryu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CherryGroveCity_EventScript_Corsola::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CORSOLA, CRY_MODE_NORMAL
	msgbox CherryGroveCity_Text_Corsola, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CherryGroveCity_EventScript_Krabby::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KRABBY, CRY_MODE_NORMAL
	msgbox CherryGroveCity_Text_Krabby, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CherryGroveCity_EventScript_Sign::
	lock
	msgbox CherrygroveCity_Text_CitySign, MSGBOX_SIGN
	closemessage
	release
	end

CherryGroveCity_EventScript_TriggerSilver_Top::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Silver_Top
	waitmovement 0
	goto CherryGroveCity_EventScript_TriggerSilver
	end

CherryGroveCity_EventScript_TriggerSilver_Bottom::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Trigger_Silver_Bottom
	waitmovement 0
	goto CherryGroveCity_EventScript_TriggerSilver
	end

CherryGroveCity_EventScript_TriggerSilver::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Enter
	waitmovement 0
	msgbox CherrygroveCity_Text_RivalSeen, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_STARTER_MON, 0, CherryGroveCity_Silver_Battle_Cyndaquil
	goto_if_eq VAR_STARTER_MON, 1, CherryGroveCity_Silver_Battle_Totodile
	goto_if_eq VAR_STARTER_MON, 2, CherryGroveCity_Silver_Battle_Chikorita
	release
	end

CherryGroveCity_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_1_HNS, CherrygroveCity_Text_SilverWin
	goto CherryGroveCity_Silver_AfterBattle

CherryGroveCity_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_1_HNS, CherrygroveCity_Text_SilverWin
	goto CherryGroveCity_Silver_AfterBattle

CherryGroveCity_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_1_HNS, CherrygroveCity_Text_SilverWin
	goto CherryGroveCity_Silver_AfterBattle

CherryGroveCity_Silver_AfterBattle::
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox CherrygroveCity_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CherryGroveCity_Movement_Silver_Leave1Player
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Leave1
	waitmovement 0
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_CHERRYGROVE_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_CHERRYGROVE_SILVER
	turnobject LOCALID_CHERRYGROVE_SILVER, DIR_EAST
	delay 60
	turnobject LOCALID_CHERRYGROVE_SILVER, DIR_SOUTH
	delay 30
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Return
	waitmovement 0
	msgbox CherrygroveCity_Text_RivalID, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CHERRYGROVE_SILVER, CherryGroveCity_Movement_Silver_Leave2
	waitmovement 0
	removeobject LOCALID_CHERRYGROVE_SILVER
	setflag FLAG_HIDE_SILVER_CHERRYGROVE
	setvar VAR_CHERRYGROVE_CITY_STATE, 4
	fadedefaultbgm
	release
	end

CherrygroveCity_Text_GuideGentIntro:
#if GERMAN
	.string "Hallo! Dich habe ich hier noch nie\n"
	.string "gesehen.\p"
	.string "Ich zeige Neuankömmlingen gern die\n"
	.string "Stadt. Rosalia ist klein, aber sie\l"
	.string "hat ihre Geschichten.\p"
	.string "Hast du einen Moment?$"
#else
	.string "Hello! I have never seen you here\n"
	.string "before.\p"
	.string "I like showing newcomers around.\n"
	.string "CHERRYGROVE is small, but it has\l"
	.string "its stories.\p"
	.string "Do you have a moment?$"
#endif

CherrygroveCity_Text_GuideGentTourStart:
#if GERMAN
	.string "Wunderbar! Dann komm mit.$"
#else
	.string "Wonderful! Come along then.$"
#endif

CherrygroveCity_Text_GuideGentPokecenter:
#if GERMAN
	.string "Unser Pokémon-Center.\p"
	.string "Die Schwester hier kennt jeden\n"
	.string "Trainer, der je nach Johto gekommen\l"
	.string "ist. Und sie vergisst keinen.\p"
	.string "Frag sie mal nach früher.$"
#else
	.string "Our POKéMON CENTER.\p"
	.string "The nurse here has met every trainer\n"
	.string "who ever came to JOHTO. And she\l"
	.string "forgets none of them.\p"
	.string "Ask her about the old days sometime.$"
#endif

CherrygroveCity_Text_GuideGentMart:
#if GERMAN
	.string "Der Markt.\p"
	.string "Die Lieferungen kommen über See,\n"
	.string "deshalb ist das Sortiment hier oft\l"
	.string "anders als im Landesinneren.\p"
	.string "Ein Blick lohnt sich.$"
#else
	.string "The MART.\p"
	.string "Deliveries come in by sea, so the\n"
	.string "stock here often differs from what\l"
	.string "you find inland.\p"
	.string "Worth a look.$"
#endif

CherrygroveCity_Text_GuideGentRoute30:
#if GERMAN
	.string "Dort geht es auf Route 30 und weiter\n"
	.string "nach Viola City.\p"
	.string "Wer nach Johto kommt, nimmt fast\n"
	.string "immer diesen Weg.$"
#else
	.string "That way lies ROUTE 30 and on to\n"
	.string "VIOLET CITY.\p"
	.string "Almost everyone who comes to JOHTO\n"
	.string "takes that road.$"
#endif

CherrygroveCity_Text_GuideGentSea:
#if GERMAN
	.string "Und das Meer.\p"
	.string "Bei klarem Wetter sieht man von hier\n"
	.string "bis zur Küste von Kanto hinüber.\p"
	.string "Manche sagen, das sei nur Einbildung.$"
#else
	.string "And the sea.\p"
	.string "On a clear day you can see all the\n"
	.string "way across to the KANTO coast.\p"
	.string "Some say that is only imagination.$"
#endif

CherrygroveCity_Text_GuideGentMap:
#if GERMAN
	.string "Und hier wohne ich.\p"
	.string "Danke für deine Gesellschaft. Ich rede\n"
	.string "gern, wenn mir jemand zuhört.\p"
	.string "Viel Glück, wo auch immer du hinwillst.$"
#else
	.string "And this is where I live.\p"
	.string "Thank you for your company. I do like\n"
	.string "to talk when someone listens.\p"
	.string "Good luck, wherever you are headed.$"
#endif

CherrygroveCity_Text_GuideGentDecline:
#if GERMAN
	.string "Oh… Dabei mache ich das so gern.\p"
	.string "Gut. Komm zu mir, wann immer du\n"
	.string "willst.$"
#else
	.string "Oh… And I do so enjoy it.\p"
	.string "Very well. Come and see me whenever\n"
	.string "you like.$"
#endif

CherrygroveCity_Text_RivalSeen:
#if GERMAN
	.string "… … …\n"
	.string "Du hast ein Pokémon aus dem Labor.\p"
	.string "Was für eine Verschwendung für einen\n"
	.string "Schwächling wie dich!\p"
	.string "… … …\p"
	.string "Was ich damit sagen will, fragst du?\n"
	.string "Wie deutlich muss ich denn noch werden?\p"
	.string "Dann erkläre ich’s dir eben ganz genau!\n"
	.string "Mein Pokémon hier ist auch nicht übel!\l"
	.string "Wenn es erst mal mit dir fertig ist,\l"
	.string "bleiben keine Fragen mehr offen!$"
#else
	.string "… … … … … … … …\p"
	.string "You got a POKéMON at the LAB.\p"
	.string "What a waste.\n"
	.string "A wimp like you.\p"
	.string "… … … … … … … …\p"
	.string "Don't you get what I'm saying?\n"
	.string "Well, I too, have a good POKéMON.\p"
	.string "I'll show you what I mean!$"
#endif

CherrygroveCity_Text_SilverWin:
#if GERMAN
	.string "Hmpf! Du hast gewonnen!\n"
	.string "Bist du jetzt zufrieden?$"
#else
	.string "Humph. Are you happy you won?$"
#endif

CherrygroveCity_Text_RivalAfter:
#if GERMAN
	.string "… … …\p"
	.string "Willst du wissen, wer ich bin?\n"
	.string "Ich werde es dir sagen!\p"
	.string "Ich bin derjenige, den die Leute schon\n"
	.string "bald den größten Pokémon-Trainer aller\l"
	.string "Zeiten nennen werden!$"
#else
	.string "… … … … … … … …\p"
	.string "Do you want to know who I am?\p"
	.string "I'm going to be the world's\n"
	.string "greatest POKéMON trainer.$"
#endif

CherrygroveCity_Text_RivalID:
#if GERMAN
	.string "Gib mir das! Das ist der Trainerpass,\n"
	.string "den ich verloren habe! Er gehört mir!\p"
	.string "Hmpf… jetzt hast du meinen Namen\n"
	.string "gesehen, oder?$"
#else
	.string "Give it back!\n"
	.string "That's my TRAINER CARD!\p"
	.string "Oh no!\n"
	.string "You saw my name...$"
#endif

CherrygroveCity_Text_TeacherHaveMapCard:
#if GERMAN
	.string "Egal, wohin die Reise auch geht, mit\n"
	.string "Pokémon als Weggefährten wird es dir\l"
	.string "ganz bestimmt nie langweilig!$"
#else
	.string "When you're with POKéMON,\n"
	.string "going anywhere is fun.$"
#endif

CherrygroveCity_Text_YoungsterNoPokedex:
#if GERMAN
	.string "Mr. Pokémons Haus liegt noch weiter\n"
	.string "vorne.$"
#else
	.string "MR. POKéMON's house is still\n"
	.string "farther up ahead.$"
#endif

CherrygroveCity_Text_YoungsterHavePokedex:
#if GERMAN
	.string "Ich habe tapfer gegen die Trainer auf\n"
	.string "der Straße gekämpft, aber mein Team hat\l"
	.string "verloren und nun sind meine Pokémon\l"
	.string "völlig außer Kraft.\p"
	.string "Ich muss sie in ein Pokémon-Center\n"
	.string "bringen, und zwar schnell…$"
#else
	.string "I battled the trainers on the\n"
	.string "road.\p"
	.string "My POKéMON lost. They're a\n"
	.string "mess! I must take them to a\l"
	.string "POKéMON CENTER.$"
#endif

CherrygroveCity_Text_MysticWaterGuyBefore:
#if GERMAN
	.string "Das Pokémon, das ich mir neulich\n"
	.string "geangelt habe, hatte ein Item dabei!\p"
	.string "Es hieß Zauberwasser oder so…\n"
	.string "Aber da ich nur am Angeln von Pokémon\l"
	.string "interessiert bin, kannst du es haben.$"
#else
	.string "A POKéMON I caught had an\n"
	.string "item.\p"
	.string "I think it's MYSTIC WATER.\p"
	.string "I don't need it, so do you\n"
	.string "want it?$"
#endif

CherrygroveCity_Text_MysticWaterGuyAfter:
#if GERMAN
	.string "Ich gehe dann mal wieder ans Angeln.$"
#else
	.string "Back to fishing for me, then.$"
#endif

CherrygroveCity_Text_CitySign:
#if GERMAN
	.string "Rosalia City\n"
	.string "Die Stadt des Blumendufts$"
#else
	.string "CHERRYGROVE CITY\p"
	.string "The City of Cute, Fragrant\n"
	.string "Flowers$"
#endif

CherrygroveCity_Text_GuideGentsHouseSign:
#if GERMAN
	.string "Haus des Reiseführers$"
#else
	.string "GUIDE GENT'S HOUSE$"
#endif

CherryGroveCity_Text_Staryu:
#if GERMAN
	.string "Sterndu: Duuuuuuuu.$"
#else
	.string "STARYU: Yuuuuuuuu.$"
#endif

CherryGroveCity_Text_Corsola:
#if GERMAN
	.string "Corasonn: Corasonn! La!$"
#else
	.string "CORSOLA: Corsola! La!$"
#endif

CherryGroveCity_Text_Krabby:
#if GERMAN
	.string "Krabby: Kraaaaah!$"
#else
	.string "KRABBY: KOOOOKEEE!$"
#endif

CherryGroveCity_Movement_Trigger_Gent:
	walk_down
	walk_left
	walk_down
	face_left
	step_end

CherryGroveCity_Movement_Trigger_Top:
	walk_down
	face_up
	step_end

CherryGroveCity_Movement_Trigger_Bottom:
	walk_up
	face_up
	step_end

CherryGroveCity_Movement_Pokecenter:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

CherryGroveCity_Movement_Pokemart:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

CherryGroveCity_Movement_Route30:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

CherryGroveCity_Movement_Sea:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

CherryGroveCity_Movement_House_Gent:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

CherryGroveCity_Movement_House_Player:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

CherryGroveCity_Movement_Gent_Leave:
	walk_up
	walk_up
	step_end

CherryGroveCity_Movement_Trigger_Silver_Top:
	walk_down
	face_right
	step_end

CherryGroveCity_Movement_Trigger_Silver_Bottom:
	walk_up
	face_right
	step_end

CherryGroveCity_Movement_Silver_Enter:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CherryGroveCity_Movement_Silver_Leave1:
	delay_16
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CherryGroveCity_Movement_Silver_Leave1Player:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

CherryGroveCity_Movement_Silver_Return:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end


CherryGroveCity_Movement_Silver_Leave2:
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

CherryGroveCity_EventScript_WarpNPC::
    lock
    faceplayer
    gettime
    compare VAR_0x8000, 6
    goto_if_lt CherryGroveCity_EventScript_WrongTime
    compare VAR_0x8000, 12
    goto_if_ge CherryGroveCity_EventScript_WrongTime
    
    msgbox CherryGroveCity_Text_WantToWarp, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq CherryGroveCity_EventScript_DoWarp
    msgbox CherryGroveCity_Text_DeclinedWarp, MSGBOX_DEFAULT
    release
    end

CherryGroveCity_EventScript_WrongTime::
    msgbox CherryGroveCity_Text_WrongTime, MSGBOX_DEFAULT
    release
    end

CherryGroveCity_EventScript_DoWarp::
    msgbox CherryGroveCity_Text_AcceptWarp, MSGBOX_DEFAULT
    closemessage
    warp MAP_CERULEAN_CITY, 34, 8
    waitstate
    release
    end
CherryGroveCity_Text_WrongTime:
    .string "Ahoi, ich reise immer vormittags nach Kanto ab.\nWenn du willst, nehme ich dich mit.$"

CherryGroveCity_Text_WantToWarp:
    .string "Ahoi, du kommst gerade rechtzeitig. Ich\nfahre jetzt nach Kanto ab. Willst du mit?$"

CherryGroveCity_Text_AcceptWarp:
    .string "Dann fahren wir ab!$"

CherryGroveCity_Text_DeclinedWarp:
    .string "Vielleicht nächstes Mal.$$"
