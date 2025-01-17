.set LOCALID_LANETTE, 1

RustGymLibrary_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustGymLibrary_OnFrame
	.byte 0

RustGymLibrary_OnFrame:
	map_script_2 VAR_RUST_GYM_STATE, 6, RustGymLibrary_EventScript_ShouldStudy
	.2byte 0

RustGymLibrary_EventScript_ShouldStudy::
	lock
	setvar VAR_RUST_GYM_STATE, 7
	msgbox RustGymLibrary_Text_ShouldStudy, MSGBOX_AUTOCLOSE
	release
	end

RustGymLibrary_EventScript_NyarlyBook::
	msgbox RustGymLibrary_Text_NyarlyBook, MSGBOX_SIGN
	end

RustGymLibrary_EventScript_FableBook::
	msgbox RustGymLibrary_Text_FableBook, MSGBOX_SIGN
	end

RustGymLibrary_EventScript_MathBook::
	msgbox RustGymLibrary_Text_MathBook, MSGBOX_SIGN
	end

RustGymLibrary_EventScript_HistoryBook::
	msgbox RustGymLibrary_Text_HistoryBook, MSGBOX_SIGN
	end

RustGymLibrary_EventScript_BadBook::
	msgbox RustGymLibrary_Text_BadBook, MSGBOX_SIGN
	end

RustGymLibrary_EventScript_GoodNoodleBoard::
	msgbox RustGymLibrary_Text_GoodNoodleBoard, MSGBOX_SIGN
	end

RustGymLibrary_Text_ShouldStudy:
	.string "(You should really study\n"
	.string "some before returning to\l"
	.string "the classroom to take the test.)$"

RustGymLibrary_Text_NyarlyBook:
	.string "(It's a book on Nyarly.)\p"
	.string "Nyarly is a perfectly normal\n"
	.string "cat in every way. Nyarly likes\l"
	.string "to eat fish and cat food.\l"
	.string "You must brush Nyarly's fur\l"
	.string "every day. On Sundays, you\l"
	.string "must not disturb Nyarly if\l"
	.string "not necessary, for Sundays\l"
	.string "are Nyarly's rest day.\p"
	.string "(...)$"

RustGymLibrary_Text_FableBook:
	.string "(This book is titled, Tales\n"
	.string "from the Backwoods: Fables,\l"
	.string "Legends and Myths.)\p"
	.string "There was once a poor fisherman\n"
	.string "who lived in a cabin by the sea.\l"
	.string "He had a poor wife at home who\l"
	.string "was satisfied with their\l"
	.string "simple seaside life.\p"
	.string "To feed himself and his beloved,\n"
	.string "the fisherman would cast his line\l"
	.string "by the rocky shore atop a smooth\l"
	.string "boulder, staying till sundown.\p"
	.string "The man fished every day, until\n"
	.string "one fateful morning he thought\l"
	.string "to himself, 'There could maybe\l"
	.string "be more to life than fishing\l"
	.string "day in and day out.'\p"
	.string "His line tensed, and he reeled\n"
	.string "in a golden fish, that gleamed\l"
	.string "brighter than even the rising sun.\p"
	.string "'I am the Stunfisk of Covetous\n"
	.string "Yearning. Hark, I have heard your\l"
	.string "longing, and shall bequeath onto\l"
	.string "you one wish. Be forewarned; the\l"
	.string "heavier you yearn, there will\l"
	.string "be a price to pay.'\p"
	.string "The fisherman wished for a life\n"
	.string "beyond this routine of fishing,\l"
	.string "a house more grand than his\l"
	.string "humble cottage; to take it all away.\p"
	.string "'And so it shall be.'\p"
	.string "He set the Stunfisk free, and\n"
	.string "watched it swim into the distance.\p"
	.string "As he walked home, he could see a\n"
	.string "brand new, luxurious mansion in the\l"
	.string "distance. Excited, he flung open\l"
	.string "the door, and called out\l"
	.string "for his wife...\p"
	.string "(The book's pages are torn out\n"
	.string "after this sentence, but there\l"
	.string "is one annotation...)\p"
	.string "'Hokeymon Hogert 2'\p"
	.string "(Probably some vandal.)\n$"

RustGymLibrary_Text_MathBook:
	.string "(This book is labelled\n"
	.string "Advanced Pokemathics.)\p"
	.string "The distance between two towns,\n"
	.string "A and B, is 570 KMs.\p"
	.string "A Torstevic starts from A at\n"
	.string "50 KMpH at 6am. Another starts\l"
	.string "from B at 80 KMpH at 7am.\l"
	.string "The two Torstevic are heading\l"
	.string "towards each other.\l"
	.string "At what time will they meet?\p"
	.string "(There is a proof included.)\p"
	.string "Let the two Torstevic meet at\n"
	.string "a distance X KM from town A.\p"
	.string "Time required by Torstevic A\n"
	.string "to cover X is X/50 Hours.\p"
	.string "Time required by Torstevic B\n"
	.string "to cover (570 - x)KM =\l"
	.string "(570 - x)/80\p"
	.string "Torstevic A started 1 hour\n"
	.string "early; it has travelled\l"
	.string "50 KM in this 1 hour.\p"
	.string "Therefore, x/50 - 1 =\n"
	.string "(570 - x)/80. On solving,\l"
	.string "x = 250.\p"
	.string "They will meet at a distance of\n"
	.string "250 KM from town A.\p"
	.string "So, the time at which they meet\n"
	.string "will be 250/50 = 5 hours, after\l"
	.string "6am. Hence, they will meet\l"
	.string "at 11 am.$"

RustGymLibrary_Text_HistoryBook:
	.string "(This book is called\n"
	.string "The Feudal Era: History\l"
	.string "of the Greats.)\p"
	.string "In the Winter of 1538, during the\n"
	.string "Ho-Engoku Period, Onda Mushinaga\l"
	.string "had been in the midst of a brutal\l"
	.string "nighttime siege led by his own\l"
	.string "uncle, Onda Mushitomo.\p"
	.string "Mushinaga was a political darling\n"
	.string "at the time, as well as an\l"
	.string "experienced general that had\l"
	.string "personally led a charge to claim\l"
	.string "half of Kanto. This instilled\l"
	.string "fear in his uncle, and\l"
	.string "Mushitomo plotted against him\l"
	.string "in secret for years.\p"
	.string "This culminated in an attack\n"
	.string "planned to catch Mushinaga off\l"
	.string "guard, as most of his forces\l"
	.string "were currently in the\l"
	.string "Orange Islands. However, Mushinaga\l"
	.string "had predicted his uncle's\l"
	.string "treachery, and set traps in the\l"
	.string "form of many burrowed Terminyte\l"
	.string "bred to resist the cold.\p"
	.string "As Mushitomo's 1000 man army\n"
	.string "approached through the forest,\l"
	.string "the Terminyte were commanded to\l"
	.string "explode all at once, setting fire\l"
	.string "to the woods and crippling the\l"
	.string "battalion enough for Mushinaga's\l"
	.string "200 man squad to finish off the\l"
	.string "enemy, without a single casualty\l"
	.string "nor damage to his precious castle.\p"
	.string "As soon as he was able, Mushinaga\n"
	.string "commanded assassin-trained Ninjask\l"
	.string "to seek out and dispatch his\l"
	.string "uncle's entire family line.\p"
	.string "This siege established Mushinaga's\n"
	.string "reputation as the Demon Bug King\l"
	.string "of 6 Enflamed Oceans.$"

RustGymLibrary_Text_BadBook:
	.string "(Nothing in this shelf you can\n"
	.string "use. Should check another.)$"

RustGymLibrary_Text_GoodNoodleBoard:
	.string "(It's the Good Noodle Board.)\p"
	.string "(Someone named 'Bob' has a lot\n"
	.string "of stars on here...)$"
