.set LOCALID_TEACHER, 1

RustGymClassroom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustGymClassroom_OnFrame
	.byte 0

RustGymClassroom_OnFrame:
	map_script_2 VAR_RUST_GYM_STATE, 2, RustGymClassroom_EventScript_Class1
	map_script_2 VAR_RUST_GYM_STATE, 5, RustGymClassroom_EventScript_Class2
	map_script_2 VAR_RUST_GYM_STATE, 7, RustGymClassroom_EventScript_TakeTest
	.2byte 0

RustGymClassroom_EventScript_Class1::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustGymClassroom_Movement_WalkToSeat
	waitmovement 0
	delay 16
	applymovement LOCALID_TEACHER, RustGymClassroom_Movement_TeacherAddressClass
	waitmovement 0
	msgbox RustGymClassroom_Text_Lesson1, MSGBOX_DEFAULT
	closemessage
	playse SE_BIKE_BELL
	waitse
	msgbox RustGymClassroom_Text_ClassOver1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RUST_GYM_STATE, 3
	applymovement LOCALID_TEACHER, RustGymClassroom_Movement_TeacherBackToDesk
	waitmovement 0
	release
	end

RustGymClassroom_EventScript_Class2::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustGymClassroom_Movement_WalkToSeat
	waitmovement 0
	delay 16
	applymovement LOCALID_TEACHER, RustGymClassroom_Movement_TeacherAddressClass
	waitmovement 0
	msgbox RustGymClassroom_Text_Lesson2, MSGBOX_DEFAULT
	closemessage
	playse SE_BIKE_BELL
	waitse
	msgbox RustGymClassroom_Text_ClassOver2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RUST_GYM_STATE, 6
	applymovement LOCALID_TEACHER, RustGymClassroom_Movement_TeacherBackToDesk
	waitmovement 0
	release
	end

RustGymClassroom_EventScript_TakeTest::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RustGymClassroom_Movement_WalkToSeat
	waitmovement 0
	delay 16
	applymovement LOCALID_TEACHER, RustGymClassroom_Movement_TeacherAddressClass
	waitmovement 0
	msgbox RustGymClassroom_Text_AboutToTakeTest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TEACHER, RustGymClassroom_Movement_TeacherBackToDesk
	waitmovement 0
	release
	end

RustGymClassroom_EventScript_TestQuestion1::
	msgbox RustGymClassroom_Text_TestQuestion1, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_1, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 4, RustGymClassroom_EventScript_TestQuestion2
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion2
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion2::
	msgbox RustGymClassroom_Text_TestQuestion2, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_2, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 4, RustGymClassroom_EventScript_TestQuestion3
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion3
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion3::
	msgbox RustGymClassroom_Text_TestQuestion3, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_3, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 4, RustGymClassroom_EventScript_TestQuestion4
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion4
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion4::
	msgbox RustGymClassroom_Text_TestQuestion4, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_4, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 4, RustGymClassroom_EventScript_TestQuestion5
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion5
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion5::
	msgbox RustGymClassroom_Text_TestQuestion5, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_5, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 4, RustGymClassroom_EventScript_TestQuestion6
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion6
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion6::
	msgbox RustGymClassroom_Text_TestQuestion6, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_6, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 4, RustGymClassroom_EventScript_TestQuestion7
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion7
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion7::
	msgbox RustGymClassroom_Text_TestQuestion7, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_7, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 4, RustGymClassroom_EventScript_TestQuestion8
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion8
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion8::
	msgbox RustGymClassroom_Text_TestQuestion8, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_8, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 4, RustGymClassroom_EventScript_TestQuestion9
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion9
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion9::
	msgbox RustGymClassroom_Text_TestQuestion9, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_9, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 4, RustGymClassroom_EventScript_TestQuestion10
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion10
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion10::
	msgbox RustGymClassroom_Text_TestQuestion10, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_10, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 4, RustGymClassroom_EventScript_TestFinished
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestFinished
	closemessage
	release
	end

RustGymClassroom_EventScript_TestFinished::
	playse SE_DING_DONG
	waitse
	applymovement LOCALID_TEACHER, RustGymClassroom_Movement_TeacherAddressClass
	waitmovement 0
	msgbox RustGymClassroom_Text_IWillNowGradeYourPapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TEACHER, RustGymClassroom_Movement_TeacherGradeTest1
	waitmovement 0
	playse SE_NOTE_C
	waitse
	applymovement LOCALID_TEACHER, RustGymClassroom_Movement_TeacherGradeTest2
	waitmovement 0
	playse SE_NOTE_D
	waitse
	applymovement LOCALID_TEACHER, RustGymClassroom_Movement_TeacherGradeTest3
	waitmovement 0
	playse SE_NOTE_E
	waitse
	applymovement LOCALID_TEACHER, RustGymClassroom_Movement_TeacherGradeTest4
	waitmovement 0
	playse SE_NOTE_F
	waitse
	applymovement LOCALID_TEACHER, RustGymClassroom_Movement_TeacherGradeTest5
	waitmovement 0
	playse SE_NOTE_G
	waitse
	applymovement LOCALID_TEACHER, RustGymClassroom_Movement_TeacherGradeTest6
	waitmovement 0
	playse SE_NOTE_A
	waitse
	applymovement LOCALID_TEACHER, RustGymClassroom_Movement_TeacherGradeTest7
	waitmovement 0
	playse SE_NOTE_B
	waitse
	applymovement LOCALID_TEACHER, RustGymClassroom_Movement_TeacherFinishedGrading
	waitmovement 0
	playse SE_NOTE_C_HIGH
	waitse
	msgbox RustGymClassroom_Text_FailuresMustReportToPrincipal, MSGBOX_DEFAULT
	closemessage
	delay 32
	msgbox RustGymClassroom_Text_YouCheckYourScore, MSGBOX_DEFAULT
	goto_if_gt VAR_TEMP_5, 1, RustGymClassroom_EventScript_Failure
	goto RustGymClassroom_EventScript_Pass
	release
	end

RustGymClassroom_EventScript_Pass::
	setvar VAR_RUST_GYM_STATE, 8
	playfanfare MUS_SLOTS_WIN
	waitfanfare
	msgbox RustGymClassroom_Text_YouPassedTheTest, MSGBOX_DEFAULT
	release
	end

RustGymClassroom_EventScript_Failure::
	setvar VAR_RUST_GYM_STATE, 10
	playfanfare MUS_TOO_BAD
	waitfanfare
	msgbox RustGymClassroom_Text_YouFailedTheTest, MSGBOX_DEFAULT
	closemessage
	warp MAP_RUST_GYM_PRINCIPALS_OFFICE, 2, 39
	waitstate
	release
	end

RustGymClassroom_Movement_WalkToSeat:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

RustGymClassroom_Movement_TeacherAddressClass:
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

RustGymClassroom_Movement_TeacherBackToDesk:
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

RustGymClassroom_Movement_TeacherGradeTest1:
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	face_left
	step_end

RustGymClassroom_Movement_TeacherGradeTest2:
	walk_faster_up
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_down
	step_end

RustGymClassroom_Movement_TeacherGradeTest3:
	walk_faster_up
	walk_faster_up
	walk_faster_left
	face_down
	step_end

RustGymClassroom_Movement_TeacherGradeTest4:
	walk_faster_up
	walk_faster_up
	walk_faster_left
	face_down
	step_end

RustGymClassroom_Movement_TeacherGradeTest5:
	walk_faster_left
	walk_faster_left
	face_down
	step_end

RustGymClassroom_Movement_TeacherGradeTest6:
	walk_faster_left
	walk_faster_down
	walk_faster_down
	step_end

RustGymClassroom_Movement_TeacherGradeTest7:
	walk_faster_right
	walk_faster_down
	walk_faster_down
	step_end

RustGymClassroom_Movement_TeacherFinishedGrading:
	walk_faster_up
	walk_faster_up
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	face_down
	step_end

RustGymClassroom_Text_Lesson1:
	.string "$"

RustGymClassroom_Text_ClassOver1:
	.string "$"

RustGymClassroom_Text_Lesson2:
	.string "$"

RustGymClassroom_Text_ClassOver2:
	.string "$"

RustGymClassroom_Text_AboutToTakeTest:
	.string "$"

RustGymClassroom_Text_TestQuestion1:
	.string "$"

RustGymClassroom_Text_TestQuestion2:
	.string "$"

RustGymClassroom_Text_TestQuestion3:
	.string "$"

RustGymClassroom_Text_TestQuestion4:
	.string "$"

RustGymClassroom_Text_TestQuestion5:
	.string "$"

RustGymClassroom_Text_TestQuestion6:
	.string "$"

RustGymClassroom_Text_TestQuestion7:
	.string "$"

RustGymClassroom_Text_TestQuestion8:
	.string "$"

RustGymClassroom_Text_TestQuestion9:
	.string "$"

RustGymClassroom_Text_TestQuestion10:
	.string "$"

RustGymClassroom_Text_IWillNowGradeYourPapers:
	.string "$"

RustGymClassroom_Text_FailuresMustReportToPrincipal:
	.string "$"

RustGymClassroom_Text_YouCheckYourScore:
	.string "$"

RustGymClassroom_Text_YouPassedTheTest:
	.string "$"

RustGymClassroom_Text_YouFailedTheTest:
	.string "$"
