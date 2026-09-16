CherrygroveCity_Mart_hns_MapScripts::
	.byte 0

Cherrygrove_Pokemart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	@ Origin Jade: Frueher war das Sortiment bis zur Pokeball-Lieferung auf
	@ Trank und Gegengift beschraenkt, danach zeigte Clerk2 "pokemart 0" -
	@ ein Nullzeiger, also gar kein Laden. Beides raus: ein Sortiment, von
	@ Anfang an auf dem Stand eines Spielers, der Kanto hinter sich hat.
	pokemart Cherrygrove_Pokemart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Cherrygrove_Pokemart_EventScript_Youngster::
	lock
	faceplayer
	msgbox Cherrygrove_Pokemart_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Cherrygrove_Pokemart_EventScript_Bugcatcher::
	lock
	faceplayer
	msgbox Cherrygrove_Pokemart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

	.align 3
Cherrygrove_Pokemart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POKE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_NONE
	release
	end

Cherrygrove_Pokemart_Text_CooltrainerM:
#if GERMAN
	.string "Kleiner Laden, aber gut sortiert.\p"
	.string "Die Lieferung kommt zweimal die Woche\n"
	.string "aus Dukatia herauf.$"
#else
	.string "Small shop, but well stocked.\p"
	.string "The delivery comes up from GOLDENROD\n"
	.string "twice a week.$"
#endif

Cherrygrove_Pokemart_Text_CooltrainerM_PokeBallsInStock:
#if GERMAN
	.string "Die neue Lieferung Pokébälle ist da!\n"
	.string "Jetzt kann ich wieder nach Herzenslust\l"
	.string "auf Pokémon-Jagd gehen!$"
#else
	.string "POKé BALLS are in stock!\n"
	.string "Now I can catch POKéMON!$"
#endif

Cherrygrove_Pokemart_Text_Youngster:
#if GERMAN
	.string "Von hier führt jeder Weg irgendwann\n"
	.string "nach Norden.\p"
	.string "Manche kommen zurück, manche nicht.\n"
	.string "Die meisten bleiben einfach hängen.$"
#else
	.string "Every road from here leads north\n"
	.string "sooner or later.\p"
	.string "Some come back, some don't. Most just\n"
	.string "end up staying somewhere.$"
#endif
