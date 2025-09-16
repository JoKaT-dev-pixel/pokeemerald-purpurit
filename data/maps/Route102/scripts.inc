.set LOCALID_LASS, 3

Route102_MapScripts::
	.byte 0

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

RouteD2_EventScript_Quentin::
	trainerbattle_single TRAINER_RICK, RouteD2_Text_QuentinIntro, RouteD2_Text_QuentinDefeated
	msgbox RouteD2_Text_QuentinPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	delay 8
	playse SE_PIN
	applymovement LOCALID_LASS, Common_Movement_ExclamationMark
	waitmovement 0
	delay 5
	applymovement LOCALID_LASS, Common_Movement_Delay48
	waitmovement 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	applymovement LOCALID_LASS, Common_Movement_FaceAwayPlayer
	waitmovement 0
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon:
	.string "{ROCKET}Oréletta: {MAGMA}Maintenant que nous sommes\n"
	.string "là, il nous suffit d'attendre qu'un\l"
	.string "Pokémon sauvage fasse son apparition !\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Let's go bitch !$"

Route102_Text_WallyIDidIt:
	.string "{ROCKET}Oréletta: {MAGMA}Oh putain…!\p"
	.string "J'ai eu mon tout premier Pokémon !$"

Route102_Text_LetsGoBack:
	.string "{MAGMA}T'as vu comment j'ai slay ?!\n"
	.string "J'ai capturé un Pokémon sale couillon !\p"
	.string "Hum hum…\p"
	.string "Retournons voir Pascal !$"

Route102_Text_ImNotVeryTall:
	.string "Et non !\n"
	.string "Je t'ai eu !\p"
	.string "Tu as cru que j'allais éternuer à\n"
	.string "cause des herbes ?!\p"
	.string "Et bien, CHEH !$"

Route102_Text_RouteSignOldale:
	.string "“Route D-2”\p"
	.string "{LEFT_ARROW} Chantiville à l'Ouest.\n"
	.string "{RIGHT_ARROW} Fourqueue à l'Est.$"

Route102_Text_RouteSignPetalburg:
	.string "“Route D-2”\p"
	.string "{RIGHT_ARROW} Fourqueue à l'Est.\n"
	.string "{LEFT_ARROW} Chantiville à l'Ouest.$"
