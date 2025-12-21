.set LOCALID_WALLYS_DAD, 1
.set LOCALID_MANIAC, 7

PetalburgCity_Pokecoffee_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_Pokecoffee_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Pokecoffee_OnWarp
	.byte 0

PetalburgCity_Pokecoffee_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_Pokecoffee_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Pokecoffee_EventScript_Hiker::
	msgbox PetalburgCity_Pokecoffee_Text_Hiker, MSGBOX_NPC
	end

PetalburgCity_Pokecoffee_EventScript_Man::
	msgbox PetalburgCity_Pokecoffee_Text_Man, MSGBOX_NPC
	end

PetalburgCity_Pokecoffee_EventScript_Maniac::
	lock
	faceplayer
	msgbox PetalburgCity_Pokecoffee_Text_Dating, MSGBOX_NPC
	closemessage
	applymovement LOCALID_MANIAC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PetalburgCity_Pokecoffee_EventScript_Girl::
	msgbox PetalburgCity_Pokecoffee_Text_Girl, MSGBOX_NPC
	end

PetalburgCity_Pokecoffee_EventScript_Woman::
	msgbox PetalburgCity_Pokecoffee_Text_Woman, MSGBOX_NPC
	end

PetalburgCity_Pokecoffee_EventScript_CookHotCoffee::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox PetalburgCity_Pokecoffee_Text_CookHotCoffee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Pokecoffee_EventScript_BuyHotCoffee
	msgbox PetalburgCity_Pokecoffee_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

PetalburgCity_Pokecoffee_EventScript_BuyHotCoffee::
	lock
	faceplayer
	checkmoney 250
	goto_if_eq VAR_RESULT, FALSE, PetalburgCity_Pokecoffee_EventScript_NotEnoughMoney
	checkitemspace ITEM_HOT_COFFEE
	goto_if_eq VAR_RESULT, FALSE, PetalburgCity_Pokecoffee_EventScript_NotEnoughSpace
	msgbox PetalburgCity_Pokecoffee_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 250
	updatemoneybox
	giveitem ITEM_HOT_COFFEE
	hidemoneybox
	release
	end

PetalburgCity_Pokecoffee_EventScript_NotEnoughMoney::
	lock
	faceplayer
	msgbox PetalburgCity_Pokecoffee_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

PetalburgCity_Pokecoffee_EventScript_NotEnoughSpace::
	lock
	faceplayer
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

PetalburgCity_Pokecoffee_EventScript_Waitress::
	msgbox PetalburgCity_Pokecoffee_Text_Waitress, MSGBOX_NPC
	end

PetalburgCity_Pokecoffee_Text_Hiker:
	.string "J'ai appris sur internet que le café\n"
	.string "favorise la pousse de barbe !\p"
	.string "Tu crois que ça fonctionne sur les\n"
	.string "poils du torse ?$"

PetalburgCity_Pokecoffee_Text_Man:
	.string "Chaque matin, je viens ici prendre mon\n"
	.string "café.\p"
	.string "SLURP !!\p"
	.string "Attends deux secondes…!\p"
	.string "SLURP !!\n"
	.string "Trop bon…!\p"
	.string "Du coup, je disais donc…\p"
	.string "SLURP !!\n"
	.string "Putain c'est trop bon !\p"
	.string "Désolé, mais je ne peux plus m'arrêter\n"
	.string "d'en boire.$"

PetalburgCity_Pokecoffee_Text_Dating:
	.string "Je suis en date avec deux nanas, la\n"
	.string "classe non ?\p"
	.string "Je les ai rencontrées sur des sites\n"
	.string "de rencontre.\p"
	.string "Tu devrais essayer pour pécho des 10\n"
	.string "sur 10 !$"

PetalburgCity_Pokecoffee_Text_Girl:
	.string "Ce connard nous a menti sur ses\n"
	.string "photos !\p"
	.string "En plus d'être moche, c'est un gros\n"
	.string "pervers !$"

PetalburgCity_Pokecoffee_Text_Woman:
	.string "J'ai accepté ce date car il me faisait\n"
	.string "trop de la peine.\p"
	.string "Sincèrement, je regrette d'avoir dit\n"
	.string "oui…\p"
	.string "Au moins, j'espère qu'il va nous payer\n"
	.string "notre café.$"

PetalburgCity_Pokecoffee_Text_CookHotCoffee:
	.string "Bonjour !\n"
	.string "Je vous sers quelque chose à boire ?\p"
	.string "On ne fait que du Café Chaud pour\n"
	.string "250 ¥.$"

PetalburgCity_Pokecoffee_Text_HereYouGo:
	.string "Voilà votre Café Chaud !$"

PetalburgCity_Pokecoffee_Text_NotEnoughMoney:
	.string "Vous avez pas assez d'argent.$"

PetalburgCity_Pokecoffee_Text_ThatsTooBad:
	.string "Vous ne voulez rien ?\n"
	.string "C'est dommage…$"

PetalburgCity_Pokecoffee_Text_Waitress:
	.string "Bienvenue au Pokécafé !\p"
	.string "Nous servons ici du café de haute\n"
	.string "qualité avec un prix raisonnable.\p"
	.string "Profitez-en pour faire une pause\n"
	.string "dans ce bar et de vous détendre.$"
