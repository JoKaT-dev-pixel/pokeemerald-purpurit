.set LOCALID_BIRCH, 1
.set LOCALID_ZIGZAGOON, 3
.set LOCALID_RIVAL, 6
.set LOCALID_FOOTPRINTS_MAN, 7

Route101_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition2
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnTransition:
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

Route101_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE101_STATE, 1
	end

Route101_EventScript_StartBirchRescue::
	lockall
	playbgm MUS_HELP, TRUE
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
	closemessage
	setobjectxy LOCALID_BIRCH, 28, 15
	setobjectxy LOCALID_ZIGZAGOON, 28, 16
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_EnterScene
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunAway1
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
	playmoncry SPECIES_TAILLOW, CRY_MODE_NORMAL
	waitmovement 0
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunInCircles
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
	applymovement LOCALID_BIRCH, Route101_Movement_BirchFaceZigzagoon
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE101_STATE, 2
	releaseall
	end

Route101_EventScript_PreventExitSouth::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitWest::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitNorth::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitNorth
	waitmovement 0
	releaseall
	end

Route101_Movement_PreventExitSouth:
	walk_up
	step_end

Route101_Movement_PreventExitWest:
	walk_right
	step_end

Route101_Movement_PreventExitNorth:
	walk_down
	step_end

Route101_Movement_ZigzagoonChaseInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_ZigzagoonChase1:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_ZigzagoonFaceBirch:
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route101_Movement_EnterScene:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_faster_left
	step_end

Route101_Movement_BirchRunInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_BirchRunAway1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_BirchFaceZigzagoon:
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Route101_Movement_Unused1:
	walk_up
	walk_up
	step_end

Route101_Movement_Unused2:
	walk_up
	walk_left
	walk_up
	step_end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_BirchsBag::
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ZIGZAGOON
	setobjectxy OBJ_EVENT_ID_PLAYER, 34, 13
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	special ChooseStarter
	waitstate
	applymovement LOCALID_BIRCH, Route101_Movement_BirchApproachPlayer
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
	special HealPlayerParty
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
	waitstate
	release
	end

Route101_EventScript_HideMayInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Movement_BirchApproachPlayer:
	walk_right
	step_end

Route101_Text_HelpMe:
	.string "Mais…!!\n"
	.string "Mais lâche-moi Pokémon de merde !!$"

Route101_Text_PleaseHelp:
	.string "Reste pas planté là !\n"
	.string "Sauve-moi !\p"
	.string "Dans mon Sac !\n"
	.string "Il y a 3 Poké Balls !\p"
	.string "Grouille-toi !$"

Route101_Text_DontLeaveMe:
	.string "Je te jure que si tu me laisses\n"
	.string "tomber, je vais niquer ta daronne !$"

Route101_Text_YouSavedMe:
	.string "{ROCKET}Prof. Fildrong: {AQUA}Quelle terrible\n"
	.string "désillusion !\p"
	.string "Je me promenais tranquillement et\n"
	.string "ce Cornaigri sorti de nulle part m'a\l"
	.string "attaquer !\p"
	.string "C'est un Pokémon qui a toujours été\n"
	.string "agressif.\p"
	.string "Merci beaucoup de m'avoir secouru !\p"
	.string "Tu es un Dresseur n'est-ce pas ?\p"
	.string "J'aimerai discuter sérieusement\n"
	.string "avec toi.\p"
	.string "Ceci dit, restons pas là ! Rentrons\n"
	.string "au labo !\p"
	.string "Zé parti !$"

Route101_OnTransition2:
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_VISITED_OLDALE_TOWN
	addobject LOCALID_FOOTPRINTS_MAN
	call_if_unset FLAG_ADVENTURE_STARTED, RouteD1_EventScript_BlockWestEntrance

RouteD1_EventScript_BlockWestEntrance::
	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 26, 9
	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
	return

RouteD1_EventScript_FootprintsMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, RouteD1_EventScript_NotBlockingPath
	msgbox RouteD1_Text_DiscoveredFootprints, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOOTPRINTS_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RouteD1_EventScript_BlockedPath::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, RouteD1_Movement_PlayerStepBack
	applymovement LOCALID_FOOTPRINTS_MAN, RouteD1_Movement_BackUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox RouteD1_Text_WaitDontComeInHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOOTPRINTS_MAN, RouteD1_Movement_ReturnToOriginalPosition
	waitmovement 0
	releaseall
	end

RouteD1_EventScript_NotBlockingPath::
	msgbox RouteD1_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
	release
	end

RouteD1_EventScript_Rival::
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_0x8009, 0
	goto RouteD1_EventScript_ShowRivalMessage
	end

RouteD1_EventScript_RivalTrigger1::
	lockall
	applymovement LOCALID_RIVAL, RouteD1_Movement_RivalApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto RouteD1_EventScript_ShowRivalMessage
	end

RouteD1_EventScript_RivalTrigger2::
	lockall
	applymovement LOCALID_RIVAL, RouteD1_Movement_RivalApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto RouteD1_EventScript_ShowRivalMessage
	end

RouteD1_EventScript_RivalTrigger3::
	lockall
	applymovement LOCALID_RIVAL, RouteD1_Movement_RivalApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto RouteD1_EventScript_ShowRivalMessage
	end

RouteD1_EventScript_ShowRivalMessage::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RouteD1_EventScript_ShowMayMessage
	goto_if_eq VAR_RESULT, FEMALE, RouteD1_EventScript_ShowBrendanMessage
	end

RouteD1_EventScript_ShowMayMessage::
	setvar VAR_0x8000, MUGSHOT_FEMALE_ANGRY
	callnative DrawMugshot
	msgbox RouteD1_Text_MayLetsGoBack, MSGBOX_DEFAULT
	callnative ClearMugshot
	goto RouteD1_EventScript_RivalFinish
	end

RouteD1_EventScript_ShowBrendanMessage::
	msgbox RouteD1_Text_BrendanLetsGoBack, MSGBOX_DEFAULT
	goto RouteD1_EventScript_RivalFinish
	end

RouteD1_EventScript_RivalFinish::
	closemessage
	call_if_eq VAR_0x8009, 0, RouteD1_EventScript_DoExitMovement1
	call_if_eq VAR_0x8009, 1, RouteD1_EventScript_DoExitMovement2
	applymovement LOCALID_RIVAL, RouteD1_Movement_RivalExit
	waitmovement 0
	removeobject LOCALID_RIVAL
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	releaseall
	end

RouteD1_EventScript_DoExitMovement1::
	goto_if_ne VAR_FACING, DIR_SOUTH, RouteD1_EventScript_DoExitMovement2
	applymovement LOCALID_RIVAL, RouteD1_Movement_RivalExit
	waitmovement 0
	return

RouteD1_EventScript_DoExitMovement2::
	applymovement OBJ_EVENT_ID_PLAYER, RouteD1_Movement_WatchRivalExit
	applymovement LOCALID_RIVAL, RouteD1_Movement_RivalExit
	waitmovement 0
	return

RouteD1_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	step_end

RouteD1_Movement_RivalApproachPlayer2:
	walk_left
	step_end

RouteD1_Movement_RivalApproachPlayer3:
	face_left
	step_end

RouteD1_Movement_RivalExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RouteD1_Movement_WatchRivalExit:
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

RouteD1_Movement_PlayerStepBack:
	delay_8
	walk_right
	step_end

RouteD1_Movement_BackUp:
	walk_fast_up
	walk_in_place_faster_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

RouteD1_Movement_ReturnToOriginalPosition:
	walk_down
	walk_left
	unlock_facing_direction
	step_end


RouteD1_Text_WaitDontComeInHere:
	.string "Hé oh, attends !\n"
	.string "Interdiction de passer !\p"
	.string "J'ai pas encore fini de couper\n"
	.string "les arbres !\p"
	.string "Tu passeras quand j'aurai fini !$"

RouteD1_Text_DiscoveredFootprints:
	.string "Interdiction de passer !\p"
	.string "J'ai pas encore fini de couper\n"
	.string "les arbres !\p"
	.string "Tu passeras quand j'aurai fini !$"

RouteD1_Text_FinishedSketchingFootprints:
	.string "J'ai fini de couper les arbres !\p"
	.string "Avec ça, je pourrais faire un bon\n"
	.string "feu de cheminée !\p"
	.string "Vas-y, passe !$"

RouteD1_Text_MayLetsGoBack:
	.string "{ROCKET}{RIVAL}: {MAGMA}Allez ! Dépêche-toi !\n"
	.string "J'ai pas que ça à faire !$"

RouteD1_Text_BrendanLetsGoBack:
	.string "BRENDAN: I'm heading back to my dad's\n"
	.string "LAB now.\l"
	.string "{PLAYER}, you should hustle back, too.$"

Route101_Text_RouteSign:
	.string "“Route D-1”\p"
	.string "{DOWN_ARROW} Bourg Paumé au Sud.\n"
	.string "{UP_ARROW} Chenal 9 au Nord.\l"
	.string "{LEFT_ARROW} Fourqueue à l'Ouest.$"

