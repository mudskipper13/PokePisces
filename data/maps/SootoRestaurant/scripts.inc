SootoRestaurant_MapScripts::
	.byte 0

SootoRestaurant_EventScript_Chef::
	lock
	goto_if_eq VAR_PISCES_STORY_PROGRESS, 0, SootoRestaurant_EventScript_NotServing
	goto_if_unset FLAG_RECEIVED_SALT, SootoRestaurant_EventScript_HaveSomeSalt
	msgbox SootoRestaurant_Text_ChefPostSalt, MSGBOX_AUTOCLOSE
	release
	end

SootoRestaurant_EventScript_NotServing::
	msgbox SootoRestaurant_Text_ChefPreGym, MSGBOX_AUTOCLOSE
	release
	end

SootoRestaurant_EventScript_HaveSomeSalt::
	msgbox SootoRestaurant_Text_ChefPostGym, MSGBOX_AUTOCLOSE
	giveitem ITEM_SHOAL_SALT
	setflag FLAG_RECEIVED_SALT
	closemessage
	release
	end

SootoRestaurant_EventScript_SaltShaker::
	lock
	goto_if_unset FLAG_RECEIVED_SEASHELL_1, SootoRestaurant_EventScript_DontTakeSalt
	goto_if_unset FLAG_RECEIVED_SEASHELL_2, SootoRestaurant_EventScript_DontTakeSalt
	goto_if_unset FLAG_RECEIVED_SEASHELL_3, SootoRestaurant_EventScript_DontTakeSalt
	goto_if_unset FLAG_RECEIVED_SEASHELL_4, SootoRestaurant_EventScript_DontTakeSalt
	goto_if_set FLAG_RECEIVED_SALT, SootoRestaurant_EventScript_DontTakeSalt
	msgbox SootoRestaurant_Text_TakeSalt, MSGBOX_DEFAULT
	giveitem ITEM_SHOAL_SALT
	setflag FLAG_RECEIVED_SALT
	closemessage
	release
	end

SootoRestaurant_EventScript_DontTakeSalt::
	msgbox SootoRestaurant_Text_DontTakeSalt, MSGBOX_AUTOCLOSE
	release
	end

SootoRestaurant_EventScript_FriendLateToLunch::
	msgbox SootoRestaurant_Text_FriendLateToLunch, MSGBOX_NPC
	end

SootoRestaurant_EventScript_GotPlacesToBe::
	msgbox SootoRestaurant_Text_GotPlacesToBe, MSGBOX_NPC
	end

SootoRestaurant_EventScript_NothingLikeIt::
	msgbox SootoRestaurant_Text_NothingLikeIt, MSGBOX_NPC
	end

SootoRestaurant_EventScript_FoodSnob::
	msgbox SootoRestaurant_Text_FoodSnob, MSGBOX_NPC
	end

SootoRestaurant_EventScript_CoffeeMan::
	msgbox SootoRestaurant_Text_CoffeeMan, MSGBOX_NPC
	end

SootoRestaurant_EventScript_ButteredBivague::
	msgbox SootoRestaurant_Text_ButteredBivague, MSGBOX_SIGN
	end

SootoRestaurant_EventScript_SpryteStew::
	msgbox SootoRestaurant_Text_SpryteStew, MSGBOX_SIGN
	end

SootoRestaurant_EventScript_SpitroastedSanctisow::
	msgbox SootoRestaurant_Text_SpitroastedSanctisow, MSGBOX_SIGN
	end

SootoRestaurant_Text_ChefPreGym:
	.string "Terribly sorry, my dear customer.\n"
	.string "I'm afraid we are not selling our\l"
	.string "dishes at the moment.\p"
	.string "The owner is having a dinner party\n"
	.string "right now that we must cater.\p"
	.string "Deepest apologies, but we must request\n"
	.string "you to come back after said party.$"

SootoRestaurant_Text_ChefPostGym:
	.string "Ah, hello there!\n"
	.string "What may I serve you today?\p"
	.string "…\p"
	.string "You just want a plate with salt\n"
	.string "sprinkled on it?\p"
	.string "I can give you that for free.\n"
	.string "Odd, but who am I to judge?$"

SootoRestaurant_Text_ChefPostSalt:
	.string "Oh? Not feeling hungry?\p"
	.string "Well, we are always here if you change\n"
	.string "your mind!$"

SootoRestaurant_Text_TakeSalt:
	.string "…\p"
	.string "(No one's looking right now.)\p"
	.string "(You unscrew the top of the shaker and\n"
	.string "pour a bunch into your hands.)$"

SootoRestaurant_Text_DontTakeSalt:
	.string "(It's a salt shaker.)$"

SootoRestaurant_Text_FriendLateToLunch:
	.string "...Our friend hasn't shown.\n"
	.string "We were supposed to have\l"
	.string "lunch together.\l"
	.string "They're so bothersome...$"

SootoRestaurant_Text_GotPlacesToBe:
	.string "C'mon, man, I got places\n"
	.string "to be! I'm just gonna start\l"
	.string "chowin' down if they don't\l"
	.string "get here soon!$"

SootoRestaurant_Text_NothingLikeIt:
	.string "Nothing out there really\n"
	.string "compares to the food at\l"
	.string "Juan-core Cuisine!\l"
	.string "I'd eat here all the time\l"
	.string "if I could afford it.$"

SootoRestaurant_Text_FoodSnob:
	.string "Meh... I've had better\n"
	.string "meals elsewhere.\l"
	.string "This place is a bit too\l"
	.string "fancy-shmancy for my tastes.$"

SootoRestaurant_Text_CoffeeMan:
	.string "Every day I come here and\n"
	.string "get just a coffee. Black.\l"
	.string "It's all an old fart like\l"
	.string "me really needs.$"

SootoRestaurant_Text_ButteredBivague:
	.string "(It's the seafood menu.\n"
	.string "They're selling dishes\l"
	.string "like buttered Bivague...)$"

SootoRestaurant_Text_SpryteStew:
	.string "(It's the 'healthy' menu.\n"
	.string "They're selling dishes\l"
	.string "like Spryte stew...)$"

SootoRestaurant_Text_SpitroastedSanctisow:
	.string "(It's the high cholestorol menu.\n"
	.string "They're selling dishes\l"
	.string "like spit-roasted Sanctisow...)$"
