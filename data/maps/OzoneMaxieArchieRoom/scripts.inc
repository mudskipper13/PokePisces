.set LOCALID_MAXIE, 2
.set LOCALID_ARCHIE, 1

OzoneMaxieArchieRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OzoneMaxieArchieRoom_OnFrame
	.byte 0

OzoneMaxieArchieRoom_OnFrame:
	map_script_2 VAR_TEMP_4, 0, OzoneMaxieArchieRoom_EventScript_FightMaxieArchie
	.2byte 0

OzoneMaxieArchieRoom_EventScript_FightMaxieArchie::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, OzoneMaxieArchieRoom_Movement_WalkToBattle
	waitmovement 0
	delay 8
	setvar VAR_TEMP_4, 1
	speakername OzoneMaxieArchieRoom_Text_NameMaxie
	msgbox OzoneMaxieArchieRoom_Text_HowImpressive, MSGBOX_DEFAULT
	speakername OzoneMaxieArchieRoom_Text_NameArchie
	msgbox OzoneMaxieArchieRoom_Text_ThisIsYourLastFight, MSGBOX_DEFAULT
	speakername OzoneMaxieArchieRoom_Text_NameMaxie
	msgbox OzoneMaxieArchieRoom_Text_MyAnalysis, MSGBOX_DEFAULT
	speakername OzoneMaxieArchieRoom_Text_NameArchie
	msgbox OzoneMaxieArchieRoom_Text_LetsGetToIt, MSGBOX_DEFAULT
	speakername NULL
	trainerbattle_two_trainers TRAINER_P_MAXIE, OzoneMaxieArchieRoom_Text_MaxieDefeat, TRAINER_P_ARCHIE, OzoneMaxieArchieRoom_Text_ArchieDefeat, OzoneMaxieArchieRoom_EventScript_LeadersDefeated, NO_MUSIC
	goto OzoneMaxieArchieRoom_EventScript_LeadersDefeated
	release
	end

OzoneMaxieArchieRoom_Movement_WalkToBattle:
	walk_up
	jump_2_up
	step_end

OzoneMaxieArchieRoom_EventScript_LeadersDefeated::
	lock
	speakername OzoneMaxieArchieRoom_Text_NameArchie
	msgbox OzoneMaxieArchieRoom_Text_ThatWasGreat, MSGBOX_DEFAULT
	speakername OzoneMaxieArchieRoom_Text_NameMaxie
	msgbox OzoneMaxieArchieRoom_Text_ToCommemorateTheOccasion, MSGBOX_DEFAULT
	closemessage
	delay 16
	playbgm MUS_ABNORMAL_WEATHER, FALSE
	setweather WEATHER_ABNORMAL
	doweather
	applymovement LOCALID_ARCHIE, OzoneMaxieArchieRoom_Movement_Confused
	applymovement LOCALID_MAXIE, OzoneMaxieArchieRoom_Movement_Confused
	delay 8
	setvar VAR_PISCES_STORY_PROGRESS, 11
	turnobject LOCALID_ARCHIE, DIR_EAST
	speakername OzoneMaxieArchieRoom_Text_NameArchie
	msgbox OzoneMaxieArchieRoom_Text_ItsLikeBefore, MSGBOX_DEFAULT
	speakername OzoneMaxieArchieRoom_Text_NameMaxie
	msgbox OzoneMaxieArchieRoom_Text_SomethingIsVeryWrong, MSGBOX_DEFAULT
	closemessage
	delay 4
	warp MAP_OZONE_SITUATION_ROOM, 3, 4
	waitstate
	release
	end

OzoneMaxieArchieRoom_Movement_Confused:
	emote_question_mark
	step_end

OzoneMaxieArchieRoom_Text_NameMaxie:
	.string "Maxie$"

OzoneMaxieArchieRoom_Text_NameArchie:
	.string "Archie$"

OzoneMaxieArchieRoom_Text_HowImpressive:
	.string "$"

OzoneMaxieArchieRoom_Text_ThisIsYourLastFight:
	.string "$"

OzoneMaxieArchieRoom_Text_MyAnalysis:
	.string "$"

OzoneMaxieArchieRoom_Text_LetsGetToIt:
	.string "$"

OzoneMaxieArchieRoom_Text_MaxieDefeat:
	.string "defeat$"

OzoneMaxieArchieRoom_Text_ArchieDefeat:
	.string "defeat$"

OzoneMaxieArchieRoom_Text_ThatWasGreat:
	.string "post$"

OzoneMaxieArchieRoom_Text_ToCommemorateTheOccasion:
	.string "$"

OzoneMaxieArchieRoom_Text_ItsLikeBefore:
	.string "$"

OzoneMaxieArchieRoom_Text_SomethingIsVeryWrong:
	.string "$"
