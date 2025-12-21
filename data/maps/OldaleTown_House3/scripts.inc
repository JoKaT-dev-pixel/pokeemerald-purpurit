OldaleTown_House3_MapScripts::
	.byte 0

Fourqueue_House3_EventScript_Man::
	msgbox Fourqueue_House3_Text_Man, MSGBOX_NPC
	end

Fourqueue_House3_EventScript_Twin::
	msgbox Fourqueue_House3_Text_Twin, MSGBOX_NPC
	end

Fourqueue_House3_EventScript_Castoutou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox Fourqueue_House3_Text_Castoutou, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Fourqueue_House3_Text_Man:
	.string "Je suis au bord du gouffre…\p"
	.string "Notre vie était vraiment difficile\n"
	.string "avant que j'obtienne mon certificat.\p"
	.string "Nous étions extrêmement pauvres…\p"
	.string "Ma femme a fini par en avoir assez…\n"
	.string "Et elle nous a quittés…$"

Fourqueue_House3_Text_Twin:
	.string "Moi, je m'appelle Nina !\p"
	.string "Et mon Castoutou, lui, c'est Alexander !\p"
	.string "Je m'inquiète beaucoup pour mon papa…\p"
	.string "Il ne joue jamais avec nous et il est\n"
	.string "très inquiet pour son examen…$"

Fourqueue_House3_Text_Castoutou:
	.string "Castoutou: Wouaf !$"
