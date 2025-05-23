.set LOCALID_MART_EMPLOYEE, 2

OldaleTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	.byte 0

OldaleTown_OnTransition:
	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
	end

@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
OldaleTown_EventScript_SetOldaleState::
	setvar VAR_OLDALE_TOWN_STATE, 1
	return

OldaleTown_EventScript_MoveMartEmployee::
	setobjectxyperm LOCALID_MART_EMPLOYEE, 21, 13
	setobjectmovementtype LOCALID_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
	return

OldaleTown_EventScript_TownSign::
	msgbox OldaleTown_Text_TownSign, MSGBOX_SIGN
	end

OldaleTown_EventScript_Girl::
	msgbox OldaleTown_Text_Girl, MSGBOX_NPC
	end

OldaleTown_EventScript_Scout::
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
	end

OldaleTown_EventScript_OldWoman::
	msgbox OldaleTown_Text_OldMan, MSGBOX_NPC
	end

OldaleTown_EventScript_Geek::
	msgbox OldaleTown_Text_Geek, MSGBOX_NPC
	end

OldaleTown_EventScript_MartEmployee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
	setflag FLAG_TEMP_1
	playbgm MUS_FOLLOW_ME, FALSE
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, OldaleTown_EventScript_GoToMartSouth
	case DIR_NORTH, OldaleTown_EventScript_GoToMartNorth
	case DIR_EAST, OldaleTown_EventScript_GoToMartEast
	end

OldaleTown_EventScript_GoToMartSouth::
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeSouth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerSouth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartNorth::
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeNorth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerNorth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartEast::
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerEast
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeEast
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_ExplainPokemonMart::
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_POTION_OLDALE
	fadedefaultbgm
	release
	end

OldaleTown_EventScript_ExplainPotion::
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	release
	end

OldaleTown_Movement_EmployeeEast:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_right
	step_end

OldaleTown_Movement_EmployeeSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_right
	step_end

OldaleTown_Movement_EmployeeNorth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_right
	step_end

OldaleTown_Movement_Unknown1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_right
	step_end

OldaleTown_Movement_PlayerEast:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OldaleTown_Movement_PlayerSouth:
	walk_in_place_faster_left
	delay_16
	delay_8
	delay_4
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OldaleTown_Movement_PlayerNorth:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OldaleTown_Movement_Unknown2:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OldaleTown_Text_Girl:
	.string "Fisé dé poute !\p"
	.string "Así es como dices hola en francés,\n"
	.string "¿no?$"

OldaleTown_Text_SavingMyProgress:
	.string "À ta place, je commencerais plutôt à\n"
	.string "sauvegarder ma partie !$"

OldaleTown_Text_OldMan:
	.string "J'ai vécu tant d'années ici et c'était\n"
	.string "très animé.\p"
	.string "Maintenant, avec le temps, il n'y a\n"
	.string "plus rien d'intéressant…$"

OldaleTown_Text_Geek:
	.string "La règle dit qu'il y a une exception\n"
	.string "à chaque règle.\p"
	.string "Cette règle n'a pas d'exception.\p"
	.string "Ce qui fait d'elle l'exception à la\n"
	.string "règle.$"

OldaleTown_Text_IWorkAtPokemonMart:
	.string "Pssst, hé toi !\p"
	.string "Tu m'as l'air d'être un vrai Dresseur,\n"
	.string "pas vrai ?!\p"
	.string "Je travaille à la Boutique Pokémon\n"
	.string "au coin de la rue.\p"
	.string "Viens, suis-moi !$"

OldaleTown_Text_ThisIsAPokemonMart:
	.string "Tu vois ce bâtiment ?\n"
	.string "C'est une Boutique Pokémon !\p"
	.string "C'est ici que tu peux t'acheter des\n"
	.string "objets très divers.\p"
	.string "Tiens ceci, c'est cadeau de la maison !\n"
	.string "Reviens me voir quand tu veux !$"

OldaleTown_Text_PotionExplanation:
	.string "Ce que je viens de te donner est un\n"
	.string "Multi Exp !\p"
	.string "Bien évidemment, tu peux choisir de\n"
	.string "l'activer ou non pour qu'il fonctionne.$"

OldaleTown_Text_TownSign:
	.string "Fourqueue\p"
	.string "… … … … … … … … …\p"
	.string "Ce village a un drôle de nom…$"

