.set LOCALID_GUARD, 2

BattleStudioLobby_MapScripts::
	.byte 0

BattleStudioLobby_EventScript_StorageGuard::
	lock
	faceplayer
	goto_if_ge VAR_ORBS_QUEST_STATE, 4, BattleStudioLobby_EventScript_GuardPostOrb
	goto_if_eq VAR_ORBS_QUEST_STATE, 3, BattleStudioLobby_EventScript_GuardMoveAside
	msgbox BattleStudioLobby_Text_CantLetYouIn, MSGBOX_AUTOCLOSE
	release
	end

BattleStudioLobby_EventScript_GuardMoveAside::
	msgbox BattleStudioLobby_Text_TheOrb, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GUARD, BattleStudioLobby_Movement_GuardMoveAside
	waitmovement 0
	removeobject LOCALID_GUARD
	setflag FLAG_TEMP_13
	release
	end

BattleStudioLobby_Movement_GuardMoveAside:
	walk_up
	step_end

BattleStudioLobby_EventScript_GuardPostOrb::
	msgbox BattleStudioLobby_Text_KeepTheSecret, MSGBOX_AUTOCLOSE
	release
	end

BattleStudioLobby_Text_CantLetYouIn:
	.string "Hey, bub. Can't let any people,\n"
	.string "fighter or not, into here.\l"
	.string "Sorry, regulations.$"

BattleStudioLobby_Text_TheOrb:
	.string "Hey, bub. Can't let any people,\n"
	.string "fighter or not, into here.\l"
	.string "...You said what now?\p"
	.string "You got some kinda map? And its\n"
	.string "pointin' you to treasure?\l"
	.string "...Hmph.\p"
	.string "I 'spose I can look the other\n"
	.string "way for 15 minutes.\l"
	.string "Get in and get out.\l"
	.string "And remember me if you get rich.$"

BattleStudioLobby_Text_KeepTheSecret:
	.string "So ya ended up seein' stuff\n"
	.string "you maybe shouldn't have, bub.\p"
	.string "What happens in the Battle Studio\n"
	.string "stays in the Battle Studio.$"
