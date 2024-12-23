OldaleTown_House1_MapScripts::
	.byte 0

Fourqueue_House1_EventScript_Woman::
	msgbox Fourqueue_House1_Text_Woman, MSGBOX_NPC
	warp MAP_OLDALE_TOWN, 9, 15
	waitstate
	end

Fourqueue_House1_Text_Woman:
	.string "Qu'est-ce que c'est que ces manières ?\p"
	.string "On ne rentre pas chez les gens comme\n"
	.string "ça !\p"
	.string "Sors de chez moi tout de suite sale\n"
	.string "petit garnement !$"

