.set LOCALID_STEVEN, 1
.set LOCALID_TOTEM, 2

GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	special SpawnCameraObject
    applymovement OBJ_EVENT_ID_CAMERA, GraniteCave_StevensRoom_Movement_CameraPanUp
    fadeoutbgm 0
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_FakePlayerWalkInPlaceDown
	waitmovement 0
	msgbox GraniteCave_StevensRoom_Text_FakePlayerTalking, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_M_COMET_PUNCH
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_BrokenArtifact
	waitmovement 0
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 25
	msgbox GraniteCave_StevensRoom_Text_BrokenArtifactTotem, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_FakePlayerWalkInPlaceDown
	waitmovement 0
	msgbox GraniteCave_StevensRoom_Text_FakePlayerExit, MSGBOX_DEFAULT
	closemessage
	delay 18
	playse SE_WARP_IN
	removeobject LOCALID_STEVEN
	waitse
	delay 20
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	fadescreenswapbuffers FADE_TO_WHITE
	addobject LOCALID_TOTEM
	delay 90
	delay 50
	fadescreenswapbuffers FADE_FROM_WHITE
	waitse
	playbgm MUS_NONE, TRUE
	playmoncry SPECIES_ABSOL, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
    applymovement OBJ_EVENT_ID_CAMERA, GraniteCave_StevensRoom_Movement_CameraPanDown
    waitmovement OBJ_EVENT_ID_CAMERA
    special RemoveCameraObject
	waitmovement 0
	applymovement LOCALID_TOTEM, GraniteCave_StevensRoom_Movement_TotemApproach
	waitmovement 0
	delay 15
	settotemboost 1, 0, 0, 1, 0, 1, 0, 0
    setwildbattle SPECIES_ABSOL, 25
    special BattleSetup_StartTotemBattle
	waitstate
	playbgm MUS_RG_SEVII_CAVE, TRUE
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_TOTEM
	fadescreen FADE_FROM_BLACK
	delay 30
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, ITEM_LETTER
	playse SE_WIN_OPEN
	waitse
	setflag FLAG_DELIVERED_STEVEN_LETTER
	delay 25
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	closemessage
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis2, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox GraniteCave_StevensRoom_Text_FindOddIncenseInTheGround, MSGBOX_DEFAULT
	giveitem ITEM_ODD_INCENSE
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	setvar VAR_GRANITE_CAVE_STEVEN_ROOM_STATE, 1
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_BrokenArtifact:
	walk_in_place_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_FakePlayerWalkInPlaceDown:
	walk_in_place_down
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_CameraPanUp:
    walk_up
    walk_up
	step_end

GraniteCave_StevensRoom_Movement_CameraPanDown:
    walk_down
    walk_down
    step_end

GraniteCave_StevensRoom_Movement_TotemApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

GraniteCave_StevensRoom_Text_FakePlayerTalking:
	.string "{ROCKET}???: {AQUA}Hey Wassup, N-Word !\n"
	.string "J'ai besoin de ton avis.\p"
	.string "Tu penses qu'il va se passer quoi si je\n"
	.string "brise ce gros caillou ?$"

GraniteCave_StevensRoom_Text_BrokenArtifactTotem:
	.string "{AQUA}… … … … … … … … …\n"
	.string "… … … … … … … … …\p"
	.string "Oups…!\p"
	.string "Je crois que j'ai fais une boulette…$"

GraniteCave_StevensRoom_Text_FakePlayerExit:
	.string "{AQUA}Bon bah, démerde-toi !\p"
	.string "À plus dans le bus !$"

GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string "{ROCKET}???: {AQUA}Psst !\p"
	.string "C'est moi, je peux communiquer par\n"
	.string "télépathie maintenant, la classe non ?\p"
	.string "Désolé de t'avoir laisser tomber mais tu\n"
	.string "n'as rien donc tout va bien !\p"
	.string "Je te conseille de lire ton e-mail, celui\n"
	.string "dont le PDG de Apple t'a envoyé.$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "{ROCKET}J'ai une annonce à faire !\p"
	.string "Monsieur Popeye est une vraie salope !\n"
	.string "Il a pissé sur ma femme !\p"
	.string "Oui, vous avez bien lu, il a sorti sa\n"
	.string "putain de BITE de marin et il a pissé\l"
	.string "sur MA FEMME !\p"
	.string "Il a dit que sa bite était “ÉNORME !”,\n"
	.string "et j'ai dit “C'est dégueulasse !”\p"
	.string "Alors je publie un post de dénonciation\n"
	.string "sur mon compte X.\p"
	.string "Monsieur Popeye, tu as une petite\n"
	.string "bite !\p"
	.string "Elle est de la taille d'une noix, mais\n"
	.string "BEAUCOUP plus petite !\p"
	.string "Et devine quoi ? Voilà à quoi ressemble\n"
	.string "la mienne !\p"
	.string "8=======================D$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis2:
	.string "{ROCKET}C'est ça, mon pote !\p"
	.string "Que des veines, pas de poils, pénis de\n"
	.string "chair, regarde ça, on dirait deux boules\l"
	.string "et un bang !\p"
	.string "Tu as baisé ma femme, alors devine quoi,\n"
	.string "je vais baiser la tienne !\p"
	.string "Eh oui, voilà ce qu'elle va obtenir,\n"
	.string "mon SUPER PISSE LASER !\p"
	.string "Sauf que je ne vais pas seulement\n"
	.string "pisser sur ta meuf, je vise bien plus\l"
	.string "haut.\p"
	.string "JE VAIS PISSER SUR TA MÈRE !\p"
	.string "ALORS, POPEYE, ÇA TE PLAÎT ? J'AI PISSÉ\n"
	.string "SUR TA MÈRE, ESPÈCE D'IDIOT !\p"
	.string "Il te reste 23 heures avant que mes\n"
	.string "GOOOOOOUUUUUUUTTELETTES de pisse\l"
	.string "n'atteignent ta putain de FILLE !$"

GraniteCave_StevensRoom_Text_FindOddIncenseInTheGround:
	.string "Le Pokémon dominant a laissé quelque\n"
	.string "chose au sol.$"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "{EMERALD}??? vous a enregistré à distance\n"
	.string "dans le PokéPad.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "Now, I've got to hurry along.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "Oh, your BAG is full…\n"
	.string "That's too bad, then.$"

