VioletCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_Pokecenter_OnTransition
	.byte 0

VioletCity_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	end

VioletCity_PokemonCenter_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TOGEPI_EGG, VioletCity_PokemonCenter_EventScript_Aide_Received
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_Offer @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_AideNoRoom
VioletCity_PokemonCenter_EventScript_Aide_Offer::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end


VioletCity_PokemonCenter_EventScript_Aide_FullParty::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFullParty, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_AideNoRoom::
	msgbox VioletCity_PokeCenter_Text_ElmsAideNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Refuse::
	msgbox VioletCity_PokeCenter_Text_ElmsAideRefuse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Accepted::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_GiveEgg @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_Aide_FullParty
VioletCity_PokemonCenter_EventScript_Aide_GiveEgg::
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	giveegg SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Common_EventScript_NoMoreRoomForPokemon @ party limit of 1 and every BOX full
	call_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC
	setflag FLAG_RECEIVED_TOGEPI_EGG
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveItem, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE_SMALL
	setflag FLAG_HIDE_VIOLET_CITY_AIDE
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 1
	clearflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	clearflag FLAG_HIDE_NEWBARKTOWN_LAB_AIDE
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC::
	msgbox VioletCity_PokeCenter_Text_ElmsAideEggToPC, MSGBOX_DEFAULT
	closemessage
	return

VioletCity_PokemonCenter_EventScript_Aide_Received::
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EVentScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_GameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Man::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_Text_BookshelfWoman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_BooksAreGreat, MSGBOX_DEFAULT
	closemessage
	release
	end


VioletCity_PokeCenter_Text_ElmsAideFavor:
#if GERMAN
	.string "{PLAYER}, lange nicht gesehen.\p"
	.string "Prof. Lind hat mich losgeschickt, um\n"
	.string "dich zu finden.\p"
	.string "Er hätte da noch eine Bitte.\p"
	.string "Würdest du dieses Ei nehmen?$"
#else
	.string "{PLAYER}, long time, no see.\p"
	.string "PROF.ELM asked me to find you.\p"
	.string "He has another favor to ask.\p"
	.string "Would you take the POKéMON EGG?$"
#endif

VioletCity_PokeCenter_Text_ElmsAideNoRoom:
#if GERMAN
	.string "{PLAYER}, lange nicht gesehen.\p"
	.string "Prof. Lind hat mich losgeschickt, um\n"
	.string "dich zu finden.\p"
	.string "Er hätte da noch eine Bitte.\p"
	.string "Würdest du dieses Ei nehmen?\p"
	.string "Oh, warte… Du musst erst Platz in\n"
	.string "deinem Team schaffen.$"
#else
	.string "{PLAYER}, long time, no see.\p"
	.string "PROF.ELM asked me to find you.\p"
	.string "He has another favor to ask.\p"
	.string "Would you take the POKéMON EGG?\p"
	.string "Oh, wait... You need to make room\n"
	.string "in your party first.$"
#endif

VioletCity_PokeCenter_Text_ElmsAideGiveEgg:
#if GERMAN
	.string "Wir haben herausgefunden, dass ein\n"
	.string "Pokémon erst im Ei heranwachsen muss,\l"
	.string "bevor es schlüpft.\p"
	.string "Und es muss dabei unter aktiven\n"
	.string "Pokémon sein.\p"
	.string "{PLAYER}, auf dich können wir uns\n"
	.string "verlassen.$"
#else
	.string "We discovered that a POKéMON won't\n"
	.string "hatch until it grows in the EGG.\p"
	.string "It also has to be with other\n"
	.string "active POKéMON to hatch.\p"
	.string "{PLAYER}, you're the only person\n"
	.string "we can rely on.$"
#endif

VioletCity_PokeCenter_Text_ElmsAideGiveItem:
#if GERMAN
	.string "Ach, und das hier hilft vielleicht,\n"
	.string "wenn es soweit ist.$"
#else
	.string "Oh, and this might help when it hatches.$"
#endif

VioletCity_PokeCenter_Text_ElmsAideFullParty:
#if GERMAN
	.string "Oh nein. Du kannst kein weiteres\n"
	.string "Pokémon mitnehmen.\p"
	.string "Ich warte hier, bis du Platz für das\n"
	.string "Ei gemacht hast.$"
#else
	.string "Oh, no. You can't carry any more\n"
	.string "POKéMON with you.\p"
	.string "I'll wait here while you make\n"
	.string "room for the EGG.$"
#endif

VioletCity_PokeCenter_Text_ElmsAideEggToPC:
#if GERMAN
	.string "Oh, du kannst gar kein weiteres\n"
	.string "Pokémon mitnehmen.\p"
	.string "Keine Sorge - ich habe das Ei an\n"
	.string "Bills PC geschickt.$"
#else
	.string "Oh, but you can't carry any more\n"
	.string "POKéMON with you.\p"
	.string "Don't worry--I sent the EGG to\n"
	.string "BILL'S PC for you.$"
#endif

VioletCity_PokeCenter_Text_ElmsAideRefuse:
#if GERMAN
	.string "A-aber… Prof. Lind hat ausdrücklich\n"
	.string "nach dir gefragt…$"
#else
	.string "B-but… PROF.ELM asked for you…$"
#endif

VioletCity_PokeCenter_Text_BooksAreGreat:
#if GERMAN
	.string "Während meine Pokémon aufgepäppelt\n"
	.string "werden, lese ich ein gutes Buch.$"
#else
	.string "While my POKéMON are recovering\n"
	.string "I love to read a good book.$"
#endif

VioletCity_PokeCenter_Text_MobileAdapter:
#if GERMAN
	.string "Ich habe eben gegen einen Freund in\n"
	.string "Anemonia City gekämpft, über Fernkampf.\p"
	.string "Mit der richtigen Verbindung erreichst\n"
	.string "du jemanden noch so weit weg.$"
#else
	.string "I just battled a friend in\n"
	.string "CIANWOOD over a link.\p"
	.string "If you connect a MOBILE ADAPTER,\n"
	.string "you can link with a friend far\l"
	.string "away.$"
#endif

VioletCity_PokeCenter_Text_GameboyKid:
#if GERMAN
	.string "Das Lagerungssystem für Pokémon hat\n"
	.string "ein Mann namens Bill gebaut.$"
#else
	.string "A guy named BILL made the\n"
	.string "POKéMON PC storage system.$"
#endif

VioletCity_PokeCenter_Text_Gentleman:
#if GERMAN
	.string "Drüben in Kanto, vor gar nicht langer\n"
	.string "Zeit: Team Rocket hat dort mit Pokémon\l"
	.string "übel Schindluder getrieben.\p"
	.string "Aber es ging gut aus - ein junger\n"
	.string "Trainer hat den Laden auffliegen\l"
	.string "lassen.\p"
	.string "Keiner weiß so recht, wer das war.$"
#else
	.string "It was around three years ago.\p"
	.string "TEAM ROCKET was up to no good\n"
	.string "with POKéMON.\p"
	.string "But justice prevailed--a young\n"
	.string "kid broke 'em up.$"
#endif

VioletCity_PokeCenter_Text_Youngster:
#if GERMAN
	.string "Pokémon sind klug. Sie gehorchen\n"
	.string "keinem Trainer, den sie nicht achten.\p"
	.string "Und die Liga hier in Johto hat ihre\n"
	.string "eigenen Regeln. Orden aus anderen\l"
	.string "Regionen zählen nur bedingt.$"
#else
	.string "POKéMON are smart. They won't\n"
	.string "obey a trainer they don't respect.\p"
	.string "Without the right GYM BADGES,\n"
	.string "they will just do as they please.$"
#endif
