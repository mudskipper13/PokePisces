SkyPillarInteriors_MapScripts::
	.byte 0

SkyPillarInteriors_EventScript_FieldNurse::
	lock
	faceplayer
	msgbox SkyPillarInteriors_Text_Healing, MSGBOX_DEFAULT
	delay 4
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	delay 8
	msgbox SkyPillarInteriors_Text_WontBeThereInFuture, MSGBOX_DEFAULT
	release
	end

SkyPillarInteriors_EventScript_RockTombGuy::
    lock
	faceplayer
	checkitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, TRUE, SkyPillarInteriors_EventScript_GaveRockTomb
	msgbox SkyPillarInteriors_Text_DeltaStones, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

SkyPillarInteriors_EventScript_GaveRockTomb::
    msgbox SkyPillarInteriors_Text_BuriedPast, MSGBOX_AUTOCLOSE
    release
    end

SkyPillarInteriors_EventScript_CoolLady::
	msgbox SkyPillarInteriors_Text_CoolLady, MSGBOX_NPC
	end

SkyPillarInteriors_EventScript_Researcher::
	msgbox SkyPillarInteriors_Text_Researcher, MSGBOX_NPC
	end

SkyPillarInteriors_EventScript_PrecociousKid::
	msgbox SkyPillarInteriors_Text_PrecociousKid, MSGBOX_NPC
	end

SkyPillarInteriors_Text_CoolLady:
	.string "Bicycle Parkour used to go ham\n"
	.string "in this tower back in the day.\l"
	.string "It was dangerous... just\l"
	.string "how I like it!\p"
	.string "Shame that the townsfolk came\n"
	.string "together and restored the building.\l"
	.string "Well, maybe not a shame in the\l"
	.string "grand scheme of things.\l"
	.string "But think about the parkour!$"

SkyPillarInteriors_Text_Researcher:
	.string "This structure can teach us\n"
	.string "so very many things about\l"
	.string "Hoenn's mysterious past.\p"
	.string "There seemed to have existed an\n"
	.string "ancient tribe of Dragon-loving\l"
	.string "people that worshipped\l"
	.string "the Pokemon Rayquaza, with\l"
	.string "this structure being their\l"
	.string "magnum opus.\p"
	.string "That tribe has since all\n"
	.string "but disappeared.$"

SkyPillarInteriors_Text_PrecociousKid:
	.string "See those huge holes?\n"
	.string "It sounds crazy, but hey,\l"
	.string "I would KILL to do a\l"
	.string "big jump across one.\p"
	.string "I know, I know.\n"
	.string "Treacherous.$"

SkyPillarInteriors_Text_DeltaStones:
	.string "The Sky Pillar is constructed out\n"
	.string "of the same material as those\l"
	.string "triangular Delta Stones.\p"
	.string "I suppose in a manner of speaking,\n"
	.string "the pillar is one huge Delta Stone!\p"
	.string "Because of this connection, some\n"
	.string "scholars have speculated that\l"
	.string "the Sky Pillar may have been\l"
	.string "built as a way of trapping some\l"
	.string "large being beneath it, its\l"
	.string "titanic weight locking it forever.\p"
	.string "But that's just some old wives tale!\p"
	.string "In the spirit of trapping Pokémon\n"
	.string "with rocks, take this TM.$"

SkyPillarInteriors_Text_BuriedPast:
	.string "In my many years, I have\n"
	.string "often wondered about what may lie\l"
	.string "buried right under our well-\l"
	.string "travelled daily paths.\p"
	.string "Maybe its down there for a reason!$"

SkyPillarInteriors_Text_Healing:
	.string "Kid, what brings you\n"
	.string "up this far?\l"
	.string "Going to meet somebody at\l"
	.string "the top or something?\p"
	.string "Your Pokemon must be weary.\n"
	.string "I will do you a favor\l"
	.string "and heal your party.$"

SkyPillarInteriors_Text_WontBeThereInFuture:
	.string "Now, in the future, kid, someone\n"
	.string "like me may not be around always\l"
	.string "to save you with a full heal.\l"
	.string "Stock up on items before\l"
	.string "you go on long treks, 'kay?$"
