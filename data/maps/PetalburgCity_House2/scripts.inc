PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "Grâce à Pascal, mon fils est devenu\n"
	.string "obéissant et va à l'école.\p"
	.string "Hors de question qu'il devienne un\n"
	.string "délinquant !$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "À cause de Pascal, ma mère m'oblige\n"
	.string "à faire mes devoirs !\p"
	.string "J'en ai tellement que je ne peux même\n"
	.string "pas jouer à Call of Duty !$"

