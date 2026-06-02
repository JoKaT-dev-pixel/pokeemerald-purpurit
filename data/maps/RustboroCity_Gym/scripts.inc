.set LOCALID_GYM_GUY, 4

RustboroCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_Gym_OnFrame
	.byte 0

RustboroCity_Gym_OnFrame:
	map_script_2 VAR_RUSTBORO_CITY_GYM_STATE, 0, RustboroCity_Gym_EventScript_GymGuyTrigger
	.2byte 0

Larochelle_Arene_EventScript_Jamy::
	setvar VAR_MUGSHOT_ID, MUGSHOT_ROXANNE
	trainerbattle_single TRAINER_ROXANNE_1, Larochelle_Arene_Text_JamyIntro, Larochelle_Arene_Text_JamyDefeat, Larochelle_Arene_EventScript_JamyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Larochelle_Arene_EventScript_JamyRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox Larochelle_Arene_Text_JamyPostBattle, MSGBOX_DEFAULT
	release
	end

Larochelle_Arene_EventScript_JamyDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

Larochelle_Arene_EventScript_JamyRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, Larochelle_Arene_Text_JamyPreRematch, Larochelle_Arene_Text_JamyRematchDefeat, Larochelle_Arene_Text_JamyRematchNeedTwoMons
	msgbox Larochelle_Arene_Text_JamyPostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuyTrigger::
	lockall
	applymovement LOCALID_GYM_GUY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_GYM_GUY, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_GYM_GUY, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_GYM_GUY, RustboroCity_Gym_Movement_GymGuyApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastUp
	waitmovement 0
	goto RustboroCity_Gym_EventScript_GymGuide
	end

RustboroCity_Gym_EventScript_GymGuide::
	goto_if_set FLAG_FRESH_WATER_GYM_1, RustboroCity_Gym_EventScript_ReceivedFreshWater
	msgbox RustboroCity_Gym_Text_GymGuideFreshWater, MSGBOX_DEFAULT
	giveitem ITEM_FRESH_WATER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GYM_GUY, RustboroCity_Gym_Movement_GymGuyMoveAwayPlayer
	waitmovement 0
	setflag FLAG_FRESH_WATER_GYM_1
	setvar VAR_RUSTBORO_CITY_GYM_STATE, 1
	releaseall
	end

RustboroCity_Gym_Movement_GymGuyApproachPlayer:
	walk_right
	walk_right
	walk_in_place_down
	step_end

RustboroCity_Gym_Movement_GymGuyMoveAwayPlayer:
	walk_left
	walk_left
	walk_in_place_down
	step_end

RustboroCity_Gym_EventScript_ReceivedFreshWater::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall Larochelle_Arene_Text_JamyRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideFreshWater:
	.string "{AQUA}Yo !\p"
	.string "Ta tâche consiste à collecter des\n"
	.string "Badges, ai-je tort ?\p"
	.string "Si tu souhaites être à la hauteur, alors\n"
	.string "laisse-moi te donner un p'tit tips !\p"
	.string "Ne t'inquiète pas, il n'y a pas d'arnaque.\n"
	.string "C'est gratos !\p"
	.string "Mais d'abord, tiens !\n"
	.string "C'est en cas de pépin !$"

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "{AQUA}Le champion de cette arène manie des\n"
	.string "Pokémon de type Roche.\p"
	.string "La caractéristique principale du type\n"
	.string "Roche est sa robustesse, cependant il\l"
	.string "tolère mal les capacités des types Eau\l"
	.string "et Plante.\p"
	.string "Pour un premier affrontement avec les\n"
	.string "Pokémon que tu possèdes, ça risquerait\l"
	.string "d'être ardu.\p"
	.string "Si tu n'agis pas intelligemment, ça sera\n"
	.string "Game Over pour toi.$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Wow !\n"
	.string "T'es plus un novice maintenant !\p"
	.string "À présent, tu me dois 1 000 000 ¥ pour\n"
	.string "mes conseils !\p"
	.string "Quoi ?!\p"
	.string "Tu n'as pas assez ?!\p"
	.string "Très bien, je vais te suivre où que tu\n"
	.string "ailles, te soutenir, je vais te préparer\l"
	.string "des succulents petits plats, et un\l"
	.string "jour, je t'empoisonnerai quand tu t'y\l"
	.string "attendras le moins.\p"
	.string "Et je me délecterai de ta souffrance.\p"
	.string "À la prochaine UwU !$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Ici, on ne loupe pas les cours !\n"
	.string "Alors, va prendre une chaise.$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Je suis désolé, je croyais que tu étais\n"
	.string "ici pour poursuivre tes études…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Je te conseille de suivre des cours sur\n"
	.string "le type Roche qui sont très captivants.$"

RustboroCity_Gym_Text_TommyIntro:
	.string "J'ai suivi des cours sur les\n"
	.string "caractéristiques du type Roche !\p"
	.string "C'est le moment de le mettre en\n"
	.string "application !$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Wow, il me reste encore beaucoup à\n"
	.string "apprendre ! $"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "Savais-tu que le type Roche englobe\n"
	.string "les Pokémon composés de la matière du\l"
	.string "même nom, ainsi que les Pokémon de l'ère\l"
	.string "préhistorique ?$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Faisons-le vite, car le cours de Jamy\n"
	.string "ne va pas tarder à débuter !$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "J'étais convaincue d'avoir bien révisé\n"
	.string "pourtant…$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "On aurait tous aimé avoir Jamy comme\n"
	.string "professeur de sciences !$"

Larochelle_Arene_Text_JamyIntro:
	.string "Bienvenue dans l'Arène de Larochelle.\n"
	.string "Je suis Jamy Gourmaud !\p"
	.string "Vois-tu, je suis reconnu comme un\n"
	.string "passeur de savoir.\p"
	.string "La rigueur et la pédagogie sont mes\n"
	.string "plus grands atouts.\p"
	.string "Permets-moi de te démontrer que les\n"
	.string "connaissances scientifiques peuvent\l"
	.string "être mises à profit dans un combat\l"
	.string "Pokémon !$"

Larochelle_Arene_Text_JamyDefeat:
	.string "ÉNORME !\p"
	.string "Tu m'as impressionné…!\p"
	.string "Cette quête de savoir ne cesse de\n"
	.string "croître au fil des confrontations\l"
	.string "avec divers Dresseurs !\p"
	.string "Selon les règlements de la Ligue\n"
	.string "Pokémon, le Champion est tenu de\l"
	.string "remettre cela au Dresseur qui l'a\l"
	.string "vaincu.\p"
	.string "Donc, prends ce Badge officiel de la\n"
	.string "Ligue Pokémon.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} reçoit le Badge Science\n"
	.string "de Jamy !$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "Ce Badge augmentera la force d'Attaque\n"
	.string "de tes Pokémon.\p"
	.string "Cela leur donne la possibilité\n"
	.string "d'exploiter la CS Coupe en dehors des\l"
	.string "combats.\p"
	.string "Je te remets ceci également, ça va\n"
	.string "t'être bénéfique !$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "La capacité Tomberoche est inclus dans\n"
	.string "cette CT.\p"
	.string "La chute de rochers cause des dégâts\n"
	.string "et la Vitesse se réduit.\p"
	.string "En te confrontant à de nombreux\n"
	.string "Dresseurs, tu devras acquérir beaucoup\l"
	.string "de connaissances.\p"
	.string "Alors en ROUTE !$"

Larochelle_Arene_Text_JamyPostBattle:
	.string "Je me considère comme un passeur, un\n"
	.string "trait d’union entre ceux qui savent et\l"
	.string "ceux qui ont envie de savoir.\p"
	.string "J’aime expliquer, mais surtout partager\n"
	.string "le plaisir que j’ai eu à comprendre.$"

RustboroCity_Gym_Text_GymStatue:
	.string "Arène de Larochelle$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "Arène de Larochelle\p"
	.string "Nouveau Dresseur reconnu par Jamy\n"
	.string "Gourmaud:\p"
	.string "{PLAYER}$"

Larochelle_Arene_Text_JamyRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "ROXANNE: Oh, hello, {PLAYER}?\n"
	.string "This is ROXANNE of RUSTBORO CITY.\p"
	.string "I heard from BRAWLY that you're\n"
	.string "moving up through the ranks of\l"
	.string "TRAINERS at an incredible clip.\p"
	.string "Well, I'd rather not think that\n"
	.string "I can't beat you.\p"
	.string "I promise, I will shape up my GYM\n"
	.string "so that you may challenge us again.\p"
	.string "I hope you'll be looking forward to\n"
	.string "that occasion as much as me!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "Registered GYM LEADER ROXANNE\n"
	.string "in the POKéNAV.$"

Larochelle_Arene_Text_JamyPreRematch:
	.string "ROXANNE: I'm so glad to see you again.\n"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become. Let us battle!$"

Larochelle_Arene_Text_JamyRematchDefeat:
	.string "Grr…\n"
	.string "Again, I have lost…$"

Larochelle_Arene_Text_JamyPostRematch:
	.string "ROXANNE: I still have much to learn\n"
	.string "when it comes to battling POKéMON.\p"
	.string "That awareness makes me love battling\n"
	.string "all that much more!$"

Larochelle_Arene_Text_JamyRematchNeedTwoMons:
	.string "ROXANNE: I'm so glad to see you again.\n"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become…\p"
	.string "Oh, no…\n"
	.string "You only have one POKéMON with you?\p"
	.string "Please return with at least one more\n"
	.string "POKéMON.$"
