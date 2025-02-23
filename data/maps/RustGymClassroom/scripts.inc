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
	goto RustGymClassroom_EventScript_TestQuestion1
	release
	end

RustGymClassroom_EventScript_TestQuestion1::
	msgbox RustGymClassroom_Text_TestQuestion1, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_1, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 2, RustGymClassroom_EventScript_TestQuestion2
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion2
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion2::
	msgbox RustGymClassroom_Text_TestQuestion2, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_2, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 1, RustGymClassroom_EventScript_TestQuestion3
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion3
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion3::
	msgbox RustGymClassroom_Text_TestQuestion3, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_3, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 0, RustGymClassroom_EventScript_TestQuestion4
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion4
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion4::
	msgbox RustGymClassroom_Text_TestQuestion4, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_4, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 3, RustGymClassroom_EventScript_TestQuestion5
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion5
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion5::
	msgbox RustGymClassroom_Text_TestQuestion5, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_5, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 4, RustGymClassroom_EventScript_TestQuestion6
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion6
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion6::
	msgbox RustGymClassroom_Text_TestQuestion6, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_6, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 1, RustGymClassroom_EventScript_TestQuestion7
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion7
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion7::
	msgbox RustGymClassroom_Text_TestQuestion7, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_7, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 2, RustGymClassroom_EventScript_TestQuestion8
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion8
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion8::
	msgbox RustGymClassroom_Text_TestQuestion8, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_8, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 4, RustGymClassroom_EventScript_TestQuestion9
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion9
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion9::
	msgbox RustGymClassroom_Text_TestQuestion9, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_9, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 0, RustGymClassroom_EventScript_TestQuestion10
	addvar VAR_TEMP_5, 1
	goto RustGymClassroom_EventScript_TestQuestion10
	closemessage
	release
	end

RustGymClassroom_EventScript_TestQuestion10::
	msgbox RustGymClassroom_Text_TestQuestion10, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_RUSTGYM_QUESTION_10, TRUE
	copyvar VAR_TEMP_1, VAR_RESULT
	goto_if_eq VAR_TEMP_1, 0, RustGymClassroom_EventScript_TestFinished
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
	closemessage
	warp MAP_RUST_GYM_GYM, 5, 15
	waitstate
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
	.string "Alright, class! Quiet down now.\n"
	.string "Any unruly students will get the\l"
	.string "wrath of the Quick Claw!\p"
	.string "(The teacher brandishes a\n"
	.string "sharp talon between his fingers.)\p"
	.string "As in, you will Quickly be\n"
	.string "Clawing your way out of\l"
	.string "2-hour detention!\p"
	.string "Ahem. Let us begin first period.\p"
	.string "Please open your textbooks to\n"
	.string "page 348. We're going to be\l"
	.string "reviewing some Hoennian History.\p"
	.string "Now, this is all fairly-recent\n"
	.string "events, but it is still history,\l"
	.string "so it needs to be extensively\l"
	.string "taught to the youth.\p"
	.string "It concerns the tale of the great\n"
	.string "giants, Groudon and Kyogre.\l"
	.string "The former, a master of the earth.\l"
	.string "The latter, of the sea.\l"
	.string "The pair had a palpable hatred\l"
	.string "toward one another, and would\l"
	.string "often quarrel, resulting in\l"
	.string "cataclysms in ancient times.\p"
	.string "The third ancient giant,\n"
	.string "Rayquaza, master of the\l"
	.string "atmosphere above, was their\l"
	.string "mediator. The mere appearance\l"
	.string "of Rayquaza would end battles\l"
	.string "in an instant. After a particularly\l"
	.string "brutal bout one year, Rayquaza\l"
	.string "forced Groudon and Kyogre to\l"
	.string "go dormant, keeping the region safe\l"
	.string "for centuries.\p"
	.string "That was until a recent event,\n"
	.string "in which the nefarious\l"
	.string "organizations of Team Magma\l"
	.string "and Team Aqua procured the means\l"
	.string "to reawaken these beasts, and the\l"
	.string "two engaged in fierce battle\l"
	.string "once again.\p"
	.string "The fierce storms and numbing\n"
	.string "droughts summoned during that\l"
	.string "tumultuous time threatened to\l"
	.string "end all of Hoenn; that is, until\l"
	.string "one brave soul called on Rayquaza,\l"
	.string "resting atop Sky Pillar, to end\l"
	.string "the conflict. And so, peace had\l"
	.string "been restored.\p"
	.string "In the years since, the two warring\n"
	.string "giants have been dormant, seemingly\l"
	.string "for good. Rayquaza, perhaps having\l"
	.string "sensed its service was no longer\l"
	.string "needed in this region, vanished\l"
	.string "one day.\p"
	.string "Within the Cave of Origin in\n"
	.string "Sootopolis, the site at which\l"
	.string "the giants had their tussle,\l"
	.string "swims two fish Pokemon of\l"
	.string "considerable power and mystery.\p"
	.string "Some say that the duo had always\n"
	.string "been there; others say that they\l"
	.string "had only shown up recently.\l"
	.string "Whatever the answer, they seem\l"
	.string "to represent our region's recent\l"
	.string "firm unity, in contrast to the\l"
	.string "dueling Pokemon of old that\l"
	.string "once resided there.$"

RustGymClassroom_Text_ClassOver1:
	.string "That bell marks the end of\n"
	.string "this period, class. You are to\l"
	.string "report to Ms. Lanette in the\l"
	.string "computer lab for your next period.\p"
	.string "Don't be late!$"

RustGymClassroom_Text_Lesson2:
	.string "(The teacher stood and scratched\n"
	.string "on the chalkboard with his\l"
	.string "Quick Claw, making an ear-splitting\l"
	.string "noise that grabbed everyone's\l"
	.string "full attention.)\p"
	.string "Miss me, class? Well, the answer\n"
	.string "doesn't matter to me. The only\l"
	.string "'answers' you lot should be\l"
	.string "worried about are your answers\l"
	.string "to the exam questions at the\l"
	.string "end of the day! Ha!\p"
	.string "With that said, open your textbooks\n"
	.string "again, to page 277. Another\l"
	.string "history lesson for you all!\p"
	.string "After the era of time known as\n"
	.string "the Great Pokemon Suppression\l"
	.string "- GPS for short - an intense\l"
	.string "plague swept the region of Hoenn.\p"
	.string "It was a disease called White Eye,\n"
	.string "which caused intense heart\l"
	.string "palpitations, heartburn, whitening\l"
	.string "of skin, panic attacks, and distinct\l"
	.string "circular patterns to appear on the\l"
	.string "afflicted's body. There was no\l"
	.string "known cure, nor an identifiable\l"
	.string "root cause.\p"
	.string "Hoenn was beset by this plague for\n"
	.string "3 long years, until it was\l"
	.string "discovered by local baker\l"
	.string "Michael Pillsbury that during the\l"
	.string "GPS, around half of the region's\l"
	.string "local forests were destroyed.\l"
	.string "The lack of trees resulted in the\l"
	.string "Kodough population, which\l"
	.string "typically possess trees, to instead\l"
	.string "inspirit the humans of Hoenn.\p"
	.string "The government established the\n"
	.string "Department of Obscure and\l"
	.string "Unorthodox Ghostly Hexes\l"
	.string "- DOUGH for short - to combat\l"
	.string "this and potential future mass-\l"
	.string "possessions from affecting Hoenn.\p"
	.string "The Pillsbury Act of 76 was drafted\n"
	.string "into law, which states that the\l"
	.string "protection of Hoenn's forests must\l"
	.string "be maintained for the continued\l"
	.string "safety of its citizens and fauna.\p"
	.string "The act was named after Michael\n"
	.string "Pillsbury, who became the last man\l"
	.string "to die from the White Eye plague.$"

RustGymClassroom_Text_ClassOver2:
	.string "Over so soon!\n"
	.string "Next time you'll be seeing me,\l"
	.string "it will be for today's exam.\p"
	.string "You have some free time for this\n"
	.string "next period; I highly suggest\l"
	.string "going to the library to do\l"
	.string "some thorough studying!$"

RustGymClassroom_Text_AboutToTakeTest:
	.string "Alrighty, class. Your test papers\n"
	.string "have been placed onto your desks.\p"
	.string "Take great care to sign your name\n"
	.string "at the top, and good luck.\p"
	.string "Remember; in this university, a\n"
	.string "score below 90% is considered\l"
	.string "failure! We want only perfection!$"

RustGymClassroom_Text_TestQuestion1:
	.string "Question 1\p"
	.string "The Pillsbury Act mandates the\n"
	.string "protection of Hoenn's what?$"

RustGymClassroom_Text_TestQuestion2:
	.string "Question 2\p"
	.string "What do the two fish Pokemon in\n"
	.string "Sootopolis represent to Hoenn?$"

RustGymClassroom_Text_TestQuestion3:
	.string "Question 3\p"
	.string "What stat does the move Laser\n"
	.string "Focus raise if the user was\l"
	.string "not damaged that turn?$"

RustGymClassroom_Text_TestQuestion4:
	.string "Question 4\p"
	.string "What did the fisherman wish from\n"
	.string "the Stunfish of Covetous Yearning?$"

RustGymClassroom_Text_TestQuestion5:
	.string "Question 5\p"
	.string "Where did Rayquaza rest before\n"
	.string "ending Groudon and Kyogre's fight?$"

RustGymClassroom_Text_TestQuestion6:
	.string "Question 6\p"
	.string "What Pokemon caused the\n"
	.string "White Eye plague of 1873?$"

RustGymClassroom_Text_TestQuestion7:
	.string "Question 7\p"
	.string "What type of Pokemon did Onda\n"
	.string "Mushinaga specialize in?$"

RustGymClassroom_Text_TestQuestion8:
	.string "Question 8\p"
	.string "What Pokemon did Mushinaga use\n"
	.string "to dispatch his uncle's line?$"

RustGymClassroom_Text_TestQuestion9:
	.string "Question 9\p"
	.string "The distance between two towns,\n"
	.string "A and B, is 570 KMs. A Torstevic\l"
	.string "starts from town A at 50KMpH\l"
	.string "at 6am, and another starts from\l"
	.string "town B at 80KMpH at 7am.\p"
	.string "They're heading towards each other.\n"
	.string "At what time will they meet?$"

RustGymClassroom_Text_TestQuestion10:
	.string "Question 10\p"
	.string "On what day of the week should\n"
	.string "Nyarly not be perturbed?$"

RustGymClassroom_Text_IWillNowGradeYourPapers:
	.string "That's all the time you are\n"
	.string "allotted, class! Pens down!\p"
	.string "I will briskly come to each\n"
	.string "of your desks and grade the\l"
	.string "exams in a moment...!$"

RustGymClassroom_Text_FailuresMustReportToPrincipal:
	.string "All done!\p"
	.string "Pass the exam, and you are\n"
	.string "free to queue up for a gym\l"
	.string "battle against Principal Roxanne!\p"
	.string "Failure? Well...\p"
	.string "Failing students will report\n"
	.string "directly to her office for\l"
	.string "disciplinary action.$"

RustGymClassroom_Text_YouCheckYourScore:
	.string "(You steel yourself to check\n"
	.string "your test score...)$"

RustGymClassroom_Text_YouPassedTheTest:
	.string "(You Passed!)$"

RustGymClassroom_Text_YouFailedTheTest:
	.string "(...)\p"
	.string "(...Failure...)\p"
	.string "(...Off to the principal's office.)$"
