OlivineCity_Cafe_hns_MapScripts::
	.byte 0

OlivineCity_Cafe_EventScript_Jasmine::
	lock
	faceplayer
	msgbox OlivineCity_Cafe_Text_Jasmine, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CAFE_JASMINE
	removeobject LOCALID_CAFE_JASMINE
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_JASMINE
	release
	end

OlivineCity_Cafe_Text_Jasmine:
#if GERMAN
	.string "Oh… Hallo, {PLAYER}.\p"
	.string "Diese Teller vor mir gehören nicht alle\n"
	.string "mir…\p"
	.string "Ähm…\p"
	.string "Eigentlich hat die Person, die\n"
	.string "vor mir saß, viel gegessen…\p"
	.string "Wenn du wieder kämpfen willst, besuche\n"
	.string "mich bitte im Kampf-Dojo in Saffronia\l"
	.string "City.$"
#else
	.string "Oh... Hello, {PLAYER}.\p"
	.string "These dishes in front of me are\n"
	.string "not all mine...\p"
	.string "Uh...\p"
	.string "Actually, the person who sat here\n"
	.string "before me ate a lot...\p"
	.string "If you'd like to battle again,\n"
	.string "please visit me at the FIGHTING\l"
	.string "DOJO in SAFFRON CITY.$"
#endif

OlivineCity_EventScript_SailorA::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_STRENGTH, OlivineCity_EventScript_SailorA2
	@ Origin Jade: Wer aus Kanto kommt, hat Staerke laengst.
	checkitem ITEM_HM_STRENGTH
	goto_if_eq VAR_RESULT, TRUE, OlivineCity_EventScript_SailorHasStrength
	msgbox OlivineCity_Text_CafeSailorStrength, MSGBOX_DEFAULT
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
OlivineCity_EventScript_SailorA2::
	msgbox OlivineCity_Text_CafeSailorGotStrength, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_SailorHasStrength::
	msgbox OlivineCity_Text_CafeSailorHasStrength, MSGBOX_DEFAULT
	giveitem ITEM_PROTEIN
	setflag FLAG_RECEIVED_HM_STRENGTH
	closemessage
	release
	end

OlivineCity_EventScript_Cook::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeFishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_SailorB::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSailorStrength:
#if GERMAN
	.string "Hah! Deine Pokémon sehen echt\n"
	.string "schwächlich aus!\p"
	.string "Sie haben nicht die Kraft, Felsen\n"
	.string "wegzustoßen.\p"
	.string "Hier, nimm das und lehre sie Stärke!$"
#else
	.string "Hah! Your POKéMON sure look like\n"
	.string "lightweights!\p"
	.string "They don't have the power to\n"
	.string "move boulders aside.\p"
	.string "Here, use this and teach them\n"
	.string "STRENGTH!$"
#endif

OlivineCity_Text_CafeSailorGotStrength:
#if GERMAN
	.string "Der Einzige, auf den du dich auf hoher\n"
	.string "See verlassen kannst, bist du selbst!\p"
	.string "Ich bin so stolz auf mich selbst!$"
#else
	.string "On the sea, the only thing you\n"
	.string "can count on is your own self!\p"
	.string "I'm so proud of my buff bod!\n"
	.string "You should train like me!$"
#endif

OlivineCity_Text_CafeFishingGuru:
#if GERMAN
	.string "Im Oliviana City Cafe gibt es nur\n"
	.string "delikate Seemannskost für Matrosen\l"
	.string "auf dem Speiseplan!$"
#else
	.string "OLIVINE CAFE's menu is packed\n"
	.string "with hearty fare for beefy\l"
	.string "SAILORS like me!$"
#endif

OlivineCity_Text_CafeSailor:
#if GERMAN
	.string "Immer wenn ich in diese Stadt komme,\n"
	.string "schaue ich hier zum Essen vorbei.\p"
	.string "Alles, was hier auf der Karte steht,\n"
	.string "verleiht mir unglaubliche Kräfte.\l"
	.string "Das Essen hier macht echt süchtig!$"
#else
	.string "Whenever I roll into this town,\n"
	.string "I always visit the OLIVINE CAFE.\p"
	.string "Everything on the menu makes me\n"
	.string "feel stronger. I can't stop eating!$"
#endif


OlivineCity_Text_CafeSailorHasStrength:
#if GERMAN
	.string "Stärke? Die hast du schon.\p"
	.string "Ich hab dreißig Jahre Kisten geschleppt\n"
	.string "und du kommst hier rein und hast es\l"
	.string "einfach.\p"
	.string "Nimm das. Trink es nicht, gib es einem\n"
	.string "deiner Pokémon.$"
#else
	.string "STRENGTH? You've got it already.\p"
	.string "Thirty years I hauled crates, and you\n"
	.string "walk in here having it all sorted.\p"
	.string "Take this. Don't drink it - give it to\n"
	.string "one of your POKéMON.$"
#endif
