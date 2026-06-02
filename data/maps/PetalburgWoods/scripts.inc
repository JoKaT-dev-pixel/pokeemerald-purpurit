.set LOCALID_GRUNT, 3
.set LOCALID_DEVON_EMPLOYEE, 4

PetalburgWoods_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PetalburgWoods_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgWoods_OnTransition
	.byte 0

PetalburgWoods_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, PetalburgWoods_EventScript_TryRemoveShroomish
	end

PetalburgWoods_EventScript_TryRemoveShroomish::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

PetalburgWoods_OnTransition:
	call_if_unset FLAG_DEFEATED_SHROOMISH_1_PETALBURG_WOODS, PetalburgWoods_EventScript_ShowShroomish1
	call_if_unset FLAG_DEFEATED_SHROOMISH_2_PETALBURG_WOODS, PetalburgWoods_EventScript_ShowShroomish2
	call_if_unset FLAG_DEFEATED_SHROOMISH_3_PETALBURG_WOODS, PetalburgWoods_EventScript_ShowShroomish3
	end

PetalburgWoods_EventScript_ShowShroomish1::
	clearflag FLAG_HIDE_PETALBURG_WOODS_SHROOMISH_1
	return

PetalburgWoods_EventScript_ShowShroomish2::
	clearflag FLAG_HIDE_PETALBURG_WOODS_SHROOMISH_2
	return

PetalburgWoods_EventScript_ShowShroomish3::
	clearflag FLAG_HIDE_PETALBURG_WOODS_SHROOMISH_3
	return

PetalburgWoods_EventScript_Shroomish1::
	lock
	faceplayer
	setwildbattle SPECIES_SHROOMISH, 5
	waitse
	playmoncry SPECIES_SHROOMISH, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PetalburgWoods_EventScript_DefeatedShroomish1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PetalburgWoods_EventScript_DefeatedShroomish1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PetalburgWoods_EventScript_DefeatedShroomish1
	setflag FLAG_DEFEATED_SHROOMISH_1_PETALBURG_WOODS
	release
	end

PetalburgWoods_EventScript_DefeatedShroomish1::
	setflag FLAG_DEFEATED_SHROOMISH_1_PETALBURG_WOODS
	goto Common_EventScript_RemoveStaticPokemon
	end

PetalburgWoods_EventScript_Shroomish2::
	lock
	faceplayer
	setwildbattle SPECIES_SHROOMISH, 5
	waitse
	playmoncry SPECIES_SHROOMISH, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PetalburgWoods_EventScript_DefeatedShroomish2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PetalburgWoods_EventScript_DefeatedShroomish2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PetalburgWoods_EventScript_DefeatedShroomish2
	setflag FLAG_DEFEATED_SHROOMISH_2_PETALBURG_WOODS
	release
	end

PetalburgWoods_EventScript_DefeatedShroomish2::
	setflag FLAG_DEFEATED_SHROOMISH_2_PETALBURG_WOODS
	goto Common_EventScript_RemoveStaticPokemon
	end

PetalburgWoods_EventScript_Shroomish3::
	lock
	faceplayer
	setwildbattle SPECIES_SHROOMISH, 5
	waitse
	playmoncry SPECIES_SHROOMISH, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PetalburgWoods_EventScript_DefeatedShroomish3
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PetalburgWoods_EventScript_DefeatedShroomish3
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PetalburgWoods_EventScript_DefeatedShroomish3
	setflag FLAG_DEFEATED_SHROOMISH_2_PETALBURG_WOODS
	release
	end

PetalburgWoods_EventScript_DefeatedShroomish3::
	setflag FLAG_DEFEATED_SHROOMISH_3_PETALBURG_WOODS
	goto Common_EventScript_RemoveStaticPokemon
	end

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_REVO_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Man::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

BoisChantilly_EventScript_Matthieu::
	trainerbattle_single TRAINER_ALLEN, BoisChantilly_Text_MatthieuIntro, BoisChantilly_Text_MatthieuDefeated
	msgbox BoisChantilly_Text_MatthieuPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "{ROCKET}???: {AQUA}Ah, si j'ai pop ici c'est ce qu'il va\n"
	.string "se produire quelque chose !$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "{ROCKET}???: {AQUA}Oh mais, c'est la chose que j'ai vu\n"
	.string "tout à l'heure à Chantiville !\p"
	.string "Alors, ça fart ?!$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "{AQUA}Hé, toi là-bas !!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "{AQUA}J'suis sûr que t'es un Dresseur\n"
	.string "Pokémon, pas vrai ?!\p"
	.string "Que dirais-tu de rejoindre les rangs de\n"
	.string "la Team Némésis ?$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "{ROCKET}???: {AQUA}Mais il veut quoi, lui ?!\p"
	.string "Allez machin-truc, donne-lui une bonne\n"
	.string "leçon à ce clown !$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "{AQUA}Nous sommes un groupe qui souhaite\n"
	.string "retrouver les vraies valeur de la région\l"
	.string "de Gaullia.\p"
	.string "Alors, ça t'intéresse ?$"

PetalburgWoods_Text_Nointerested:
	.string "{AQUA}Non ?\p"
	.string "T'es de la résistance, c'est ça\n"
	.string "sale merde ?!\p"
	.string "Je vois…\p"
	.string "Je vais devoir me débarrasser de toi !\p"
	.string "Allez, viens par là, que je t’attrape !$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Putain, j'ai affaire à un coriace !$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "{AQUA}C'est impossible…!\p"
	.string "Comment un déchet comme toi peut être\n"
	.string "aussi fort ?!\p"
	.string "Mais… Ça n'a plus d'importance !\p"
	.string "Tu verras, les autres membres de la\n"
	.string "Team Némésis vont lutter pour vous\l"
	.string "exclure et ça sera fini de vous !\p"
	.string "Finis l'immigration, finies les\n"
	.string "LGBT et la résistance !\p"
	.string "On va vous écraser !\n"
	.string "Vive la Team Némésis !$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "{ROCKET}???: {AQUA}Qu'est-ce qui peut être con…!\p"
	.string "Il vient d'envoyer un Pokémon au\n"
	.string "combat alors qu'il lutte contre la\l"
	.string "maltraitance des Pokémon !\p"
	.string "c'est la chose la plus débile que j'ai\n"
	.string "jamais vu !\p"
	.string "En tout cas, merci d'avoir battu à\n"
	.string "ma place !\p"
	.string "J'en ai profité pour lui voler ceci\n"
	.string "dans son sac !$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "{ROCKET}???: {AQUA}Je sais que tu dois surement te\n"
	.string "dire comment je m'appelle.\p"
	.string "Bah si tu veux le savoir, demande ça\n"
	.string "au développeur du jeu !\p"
	.string "Attends une minute…\p"
	.string "Le mongole de tout à l'heure, il est\n"
	.string "bien parti vers Larochelle, non ?!$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "{AQUA}Faut l'arrêter avant qu'il ne soit\n"
	.string "trop tard !$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT BALL.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "Chez les scouts, il est interdit de\n"
	.string "jouer avec des armes à feu !$"

PetalburgWoods_Text_ICouldntWin:
	.string "C'est pas juste…!$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "OK, j'utilise des armes mais c'est\n"
	.string "normal, je suis un éclaireur !$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Ho-ho-ho !\n"
	.string "Tu veux voir ma grosse hache ?!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Je crois que je vais fermer ma\n"
	.string "braguette !$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Je t'assure que je n'avais pas vu que\n"
	.string "ma braguette était rester ouverte !$"

PetalburgWoods_Text_IWantRematch1:
	.string "I want a rematch when my BUG\n"
	.string "POKéMON grow up!\p"
	.string "I'm registering you in my POKéNAV!$"

PetalburgWoods_Text_IWantRematch2:
	.string "I want a rematch when my BUG \n"
	.string "POKéMON grow up!\p"
	.string "I'm registering you in my POKéNAV!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "My BUG POKéMON have grown.\n"
	.string "I'll be popular again.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "I can't be popular if I lose.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "You get to be popular if you have\n"
	.string "strong POKéMON, right?\l"
	.string "So, I've been training hard.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "J'ai entendu des faits divers\n"
	.string "à propos de cette forêt!\p"
	.string "Un mec aurait buté sa copine en\n"
	.string "étranglant par erreur parce\l"
	.string "qu'elle a refusé le mariage.\p"
	.string "Voilà, elle a refusé de se marier\n"
	.string "avec lui parce que c'était un\l"
	.string "bouffon et du coup lui il l'a tué\l"
	.string "dans la forêt.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Parfois, je regarde le sol et je finis\n"
	.string "par trouver des objets rares.\p"
	.string "J'ai beaucoup de chance d'en avoir\n"
	.string "ramasser autant d'objets !$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Oh, neat!\n"
	.string "That's the BADGE from RUSTBORO GYM!\p"
	.string "You must be a TRAINER.\n"
	.string "You should try using this item.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "It's a MIRACLE SEED.\n"
	.string "If a POKéMON holds that item, its\l"
	.string "GRASS-type moves become stronger.\p"
	.string "Besides MIRACLE SEED, I think there are\n"
	.string "other convenient items for POKéMON\l"
	.string "to hold.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "“Conseils aux Dresseurs”\p"
	.string "Attention aux champignons !\p"
	.string "Certains de ces champignons sont\n"
	.string "piégés.\p"
	.string "N'oubliez pas que vous n'êtes pas\n"
	.string "un plombier moustachu !$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "“Conseils aux Dresseurs”\p"
	.string "Si quelqu'un vous donne un bon conseil,\n"
	.string "faites le contraire.$"
