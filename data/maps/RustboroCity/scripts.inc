.set LOCALID_LITTLE_BOY, 7
.set LOCALID_LITTLE_GIRL, 8
.set LOCALID_DEVON_EMPLOYEE, 9
.set LOCALID_GRUNT, 10
.set LOCALID_RIVAL, 14
.set LOCALID_SCIENTIST, 15

RustboroCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
	.byte 0

RustboroCity_OnTransition:
	setflag FLAG_VISITED_RUSTBORO_CITY
	call Common_EventScript_SetupRivalGfxId
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
	end

RustboroCity_EventScript_PositionScientistForExit::
	goto_if_eq VAR_TEMP_0, 11, RustboroCity_EventScript_PositionScientistLeftExit
	setobjectxyperm LOCALID_SCIENTIST, 13, 15
	end

RustboroCity_EventScript_PositionScientistLeftExit::
	setobjectxyperm LOCALID_SCIENTIST, 13, 15
	end

RustboroCity_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

RustboroCity_OnFrame:
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
	.2byte 0

RustboroCity_EventScript_ScientistAddMatchCall::
	lockall
	setvar VAR_ROUTE104_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerWalkDown
	waitmovement 0
	playse SE_EXIT
	delay 10
	addobject LOCALID_SCIENTIST
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
	waitmovement 0
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HAS_MATCH_CALL
	applymovement LOCALID_SCIENTIST, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	applymovement LOCALID_SCIENTIST, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
	closemessage
	delay 20
	goto RustboroCity_EventScript_MatchCallTutorial

RustboroCity_EventScript_PleaseSelectPokenav::
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
	closemessage
	delay 10
	goto RustboroCity_EventScript_MatchCallTutorial

RustboroCity_EventScript_MatchCallTutorial::
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	special ScriptMenu_CreateStartMenuForPokenavTutorial
	waitstate
	switch VAR_RESULT
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
	special OpenPokenavForTutorial
	waitstate
	delay 20
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_SCIENTIST
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
	setvar VAR_RUSTBORO_CITY_STATE, 7
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

RustboroCity_Movement_ScientistWalkInPlaceDown:
	walk_in_place_down
	step_end

RustboroCity_Movement_PlayerWalkDown:
	walk_down
	step_end

RustboroCity_Movement_ScientistApproachPlayer:
	walk_down
	delay_16
	step_end

@ Unused
RustboroCity_Movement_ScientistWalkAroundPlayer:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_up
	delay_16
	step_end

RustboroCity_Movement_ScientistLeave:
	walk_up
	step_end

RustboroCity_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_FatManSawGrunt::
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_DevonEmployee2::
	lock
	faceplayer
	msgbox RustboroCity_Text_YoureNewAroundHere
	waitmessage
	multichoicedefault 21, 6, MULTI_SALARYMAN, 0, FALSE
	switch VAR_RESULT
	case 0, Larochelle_EventScript_Choose10Hours
	case 1, Larochelle_EventScript_ChooseInfiniteHours
	case 2, Larochelle_EventScript_ChooseIDontKnow
	case MULTI_B_PRESSED, Larochelle_EventScript_ChooseIDontKnow
	end

Larochelle_EventScript_Choose10Hours::
	msgbox Larochelle_Text_10Hours, MSGBOX_DEFAULT
	closemessage
	release
	end

Larochelle_EventScript_ChooseInfiniteHours::
	msgbox Larochelle_Text_InfiniteHours, MSGBOX_DEFAULT
	closemessage
	release
	end

Larochelle_EventScript_ChooseIDontKnow::
	msgbox Larochelle_Text_IDontKnow, MSGBOX_DEFAULT
	closemessage
	release
	end

RustboroCity_EventScript_Woman::
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
	end

RustboroCity_EventScript_Boy1::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Boy1HaveBadge
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy1HaveBadge::
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy2::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Boy2BrineyLeftTunnel::
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Maniac::
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
	end

RustboroCity_EventScript_SDFRustBall::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_SDF_EventScript_BuyRustBall
	msgbox RustboroCity_SDF_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

RustboroCity_SDF_EventScript_BuyRustBall::
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_SDF_EventScript_NotEnoughMoney
	checkitemspace ITEM_RUST_BALL
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_SDF_EventScript_NotEnoughSpace
	msgbox RustboroCity_SDF_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 200
	updatemoneybox
	giveitem ITEM_RUST_BALL, 5
	hidemoneybox
	release
	end

RustboroCity_SDF_EventScript_NotEnoughMoney::
	msgbox RustboroCity_SDF_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

RustboroCity_SDF_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

RustboroCity_EventScript_TunnelSign::
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
	end

RustboroCity_EventScript_DevonCorpSign::
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_GymSign::
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
	end

@ Unused
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CitySign::
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
	end

RustboroCity_EventScript_TrainersSchoolSign::
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CuttersHouseSign::
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
	end

RustboroCity_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
	applymovement LOCALID_LITTLE_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_Castoutou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox RustboroCity_Text_Castoutou, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_EventScript_SchoolKid::
	lock
	faceplayer
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_StolenGoodsTrigger0::
	lockall
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 13, 20
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 0
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger1::
	lockall
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 13, 20
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 1
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger2::
	lockall
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 13, 20
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 2
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger3::
	lockall
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 13, 20
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 3
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger4::
	lockall
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 13, 20
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 4
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsScene::
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	addobject LOCALID_GRUNT
	addobject LOCALID_DEVON_EMPLOYEE
	applymovement LOCALID_GRUNT, RustboroCity_Movement_GruntEscape
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
	waitmovement 0
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_DEVON_EMPLOYEE
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 28, 9
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setflag FLAG_DEVON_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 2
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
	setvar VAR_ROUTE116_STATE, 1
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	releaseall
	end

@ Unused
RustboroCity_EventScript_ShadyCharacterTookOff::
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
	return

@ Unused
RustboroCity_EventScript_YouGotItThankYou::
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
	return

@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
RustboroCity_EventScript_EmployeeApproachUp::
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
	waitmovement 0
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachLeft::
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
	waitmovement 0
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachRight::
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
	waitmovement 0
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachDown::
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
	waitmovement 0
	return

@ Unused, similar movement to the above scripts
RustboroCity_EventScript_EmployeeApproachPlayerFar::
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

@ Unused
RustboroCity_Movement_GruntEscapeExtended:
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_GruntEscape:
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_EmployeeChaseGrunt1:
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_in_place_faster_up
	step_end

RustboroCity_Movement_EmployeeChaseGrunt2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachUp:
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachLeft:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachRight:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachDown:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachPlayerFar:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

RustboroCity_EventScript_DevonEmployee1::
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
	waitse
	setvar VAR_TEMP_1, 4
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger0::
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger1::
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger2::
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger3::
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_EmployeeAskToGetGoods::
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 3
	copyobjectxytoperm LOCALID_DEVON_EMPLOYEE
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
	releaseall
	end

@ The below movement scripts are either partially or fully duplicated by the movement scripts when the player returns the goods
RustboroCity_EventScript_EmployeeFacePlayerUp1::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerLeft1::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerDown1::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeApproachPlayerDown1::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_Movement_EmployeeApproachPlayerDown:
	walk_down
	step_end

RustboroCity_EventScript_ReturnGoodsTrigger0::
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger1::
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger2::
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger3::
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoods::
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp2
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft2
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown2
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown2
	call_if_eq VAR_TEMP_1, 4, RustboroCity_EventScript_EmployeeFacePlayerRight
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
	giveitem ITEM_VS_SEEKER
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setvar VAR_RUSTBORO_CITY_STATE, 5
	delay 30
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
	waitstate
	releaseall
	end

RustboroCity_EventScript_BagFull::
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	return

RustboroCity_EventScript_EmployeeFacePlayerUp2::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerLeft2::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerDown2::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeApproachPlayerDown2::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerRight::
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	return

RustboroCity_EventScript_Rival::
	lockall
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_PlayRivalMusic::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
	return

RustboroCity_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

RustboroCity_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

RustboroCity_EventScript_RivalTrigger0::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger1::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger2::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger3::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger4::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger5::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger6::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger7::
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalEncounter::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
	end

RustboroCity_EventScript_MayEncounter::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	setvar VAR_0x8000, MUGSHOT_FEMALE_BORED
	callnative DrawMugshot
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
	callnative ClearMugshot
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_ROUTE104_STATE, 2
	setvar VAR_0x8008, 0
	setvar VAR_0x8000, MUGSHOT_FEMALE_ANGRY
	callnative DrawMugshot
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_DEFAULT
	callnative ClearMugshot
	closemessage
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMayTreecko
	case 1, RustboroCity_EventScript_BattleMayTorchic
	case 2, RustboroCity_EventScript_BattleMayMudkip
	releaseall
	end

RustboroCity_EventScript_MayAskToBattle::
	setvar VAR_0x8008, 1
	setvar VAR_0x8000, MUGSHOT_FEMALE_BORED
	callnative DrawMugshot
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
	callnative ClearMugshot
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMayTreecko
	case 1, RustboroCity_EventScript_BattleMayTorchic
	case 2, RustboroCity_EventScript_BattleMayMudkip
	releaseall
	end

RustboroCity_EventScript_BattleMay::
	setvar VAR_0x8000, MUGSHOT_FEMALE_BORED
	callnative DrawMugshot
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
	callnative ClearMugshot
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMayTreecko
	case 1, RustboroCity_EventScript_BattleMayTorchic
	case 2, RustboroCity_EventScript_BattleMayMudkip
	end

RustboroCity_EventScript_MayBrineyHint::
	setvar VAR_0x8000, MUGSHOT_FEMALE_ANGRY
	callnative DrawMugshot
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
	callnative ClearMugshot
	setvar VAR_RUSTBORO_CITY_STATE, 8
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_RestoreBgm::
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

RustboroCity_EventScript_BattleMayTreecko::
	setvar VAR_MUGSHOT_ID, MUGSHOT_MAY
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMayTorchic::
	setvar VAR_MUGSHOT_ID, MUGSHOT_MAY
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMayMudkip::
	setvar VAR_MUGSHOT_ID, MUGSHOT_MAY
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BrendanEncounter::
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_BrendanAskToBattle::
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleBrendan::
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
	end

RustboroCity_EventScript_BrendanBrineyHint::
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_Movement_RivalApproachPlayer0:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer2:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer3:
	walk_down
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer4:
	walk_down
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer5:
	walk_down
	walk_right
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer6:
	walk_down
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer7:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_EventScript_Lass::
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
	end

RustboroCity_Text_WeShortenItToDevon:
	.string "Pourquoi cette maison a-t-elle une\n"
	.string "pomme géante ?\p"
	.string "Y a-t-il des pommes à l'intérieur ?$"

RustboroCity_Text_SneakyLookingManWentAroundCorner:
	.string "Pourquoi il court le monsieur ?\p"
	.string "Est-ce parce qu'il a volé des pommes\n"
 	.string "dans la maison des pommes ?$"

RustboroCity_Text_HaveYouChallengedGym:
	.string "Wallah, j'ai trop le seum…!\p"
	.string "La vie de ma mère, le Champion est\n"
	.string "trop fort, wesh !\p"
	.string "Si t'as un Pokémon de type Feu dans\n"
	.string "l'équipe, force à toi !$"

RustboroCity_Text_HeyThatsRustborosGymBadge:
	.string "Wesh, c’est le Badge de l'arène !\p"
	.string "Putain, ça me casse les couilles\n"
	.string "d'avoir perdu face au Champion…!$"

RustboroCity_Text_YoureNewAroundHere:
	.string "J'ai besoin de ton aide, ma montre a\n"
	.string "disparu !\p"
	.string "Pourrais-tu me dire l'heure, s'il te\n"
	.string "plaît ?$"

Larochelle_Text_10Hours:
	.string "C'est bon, je l'ai retrouvé ! T'as servi à\n"
	.string "rien, en fait.$"

Larochelle_Text_InfiniteHours:
	.string "Mince ! Je suis en retard au travail !\p"
	.string "Oh et puis zut, de toute manière, je ne\n"
	.string "suis pas bien rémunéré…!\p"
	.string "J'ai pris ma décision, je fais le mur !$"

Larochelle_Text_IDontKnow:
	.string "Ah bon…?!\n"
	.string "Tu es vraiment dans le flou ?\p"
	.string "T'es vraiment une merde, tu sais ?!$"

RustboroCity_Text_GymLeaderIsntEasyWithFire:
	.string "J'adore ressentir le souffle du vent\n"
	.string "dans mes cheveux près de l'océan.\p"
	.string "Cette ville reste agréable à explorer,\n"
	.string "en plus d'abriter le siège officiel de\l"
	.string "la célèbre marque Apple.$"

RustboroCity_Text_MrBrineyWalksInTheTunnel:
	.string "Ne te laisse pas avoir par le sans-abri\n"
	.string "qui tente de te vendre des Poké Balls\l"
	.string "spéciales.\p"
	.string "Il a réussi à me duper en croyant que\n"
	.string "cela pourrait être une bonne affaire.$"

RustboroCity_Text_MrBrineyLovesPeeko:
	.string "Il est trop cool ton PokéPad !\p"
	.string "Je ne comprends pas comment tu t'y es\n"
	.string "pris pour obtenir ce modèle, mais une\l"
	.string "chose est sûre, il a de la classe !$"

RustboroCity_Text_WowYouHavePokemon:
	.string "Tu sais qu'Inoxtag a décidé de relever\n"
	.string "le défi d'accéder au rang Platine sur\l"
	.string "LoL en seulement une semaine ?\p"
	.string "Ce noob a échoué en atteignant\n"
	.string "seulement le rang Silver 4.\p"
	.string "Pff…! Quel loser !$"

RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
	.string "Je te propose des Balls de haute\n"
	.string "qualité pour 200 ¥, marché conclu ?!$"

RustboroCity_SDF_Text_HereYouGo:
	.string "Ah, ah, quel pigeon celui-là !\p"
	.string "Heu… Je veux dire…!\p"
	.string "Voici tes Balls comme convenu !\n"
	.string "Maintenant, dégage de là !$"

RustboroCity_SDF_Text_NotEnoughMoney:
	.string "Dégage, sale pauvre !$"

RustboroCity_SDF_Text_ThatsTooBad:
	.string "Va au diable, imbécile !$"

RustboroCity_Text_PokemonCanChangeLookFromExp:
	.string "J'essaie de faire évoluer mon Castoutou\n"
	.string "en lui donnant des Protéines, mais il\l"
	.string "n'évolue toujours pas…$"

RustboroCity_Text_Castoutou:
	.string "Castoutou: Grrroar !!$"

RustboroCity_Text_TradePokemonGrowFast:
	.string "J'ai fais une grosse découverte !\p"
	.string "Es-tu au courant que si tu as un\n"
	.string "Pokémon obtenu par échange, son gain\l"
	.string "d'expérience est multiplié ?\p"
	.string "Attention !\p"
	.string "Il se pourrait qu'il puisse te désobéir\n"
	.string "si tu n'en obtiens pas assez de Badges.$"

RustboroCity_Text_OutOfTheWay:
	.string "{AQUA}Hahahaha !\n"
	.string "VIVE LA TEAM NÉMÉSIS !!$"

RustboroCity_Text_WaitDontTakeMyGoods:
	.string "{AQUA}REVIENS ICI SALE ENCULÉ !!$"

RustboroCity_Text_HelpMeIWasRobbed:
	.string "{AQUA}Oh, Dieu soit loué !\n"
	.string "J'ai besoin d'aide !\p"
	.string "Ce bouffon de la Team Némésis a dérobé\n"
	.string "les plans du nouvel appareil, le\l"
	.string "PokéPad…!\p"
	.string "Si je ne récupère pas, je vais\n"
	.string "rencontrer de sérieux problèmes…!$"

RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
	.string "Je pense que cet enculé s'est dirigé\n"
	.string "vers les catacombes là-bas.$"

RustboroCity_Text_YouGotItThankYou:
	.string "Alors, as-tu réussi à récupérer les\n"
	.string "plans ?\p"
	.string "Enfin ! Je te suis extrêmement\n"
	.string "reconnaissant !\p"
	.string "Si tu savais à quel point ce truc est\n"
	.string "précieux, je ne sais pas ce que la Team\l"
	.string "Némésis envisage de faire avec ses\l"
	.string "plans.\p"
	.string "Mais je crois qu'ils sont en train de\n"
	.string "concocter quelque chose.\p"
	.string "En tout cas, étant donné que tu m'as\n"
	.string "rendu service, je t'offre cet outil\l"
	.string "fraîchement sorti d'Apple INC. !$"

RustboroCity_Text_YoureLoadedWithItems:
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT BALL.$"

RustboroCity_Text_PleaseComeWithMe:
	.string "J'ai une autre demande, viens avec moi\n"
	.string "chez Apple INC.\p"
	.string "Le chef désire te rencontrer en face à\n"
	.string "face.$"

RustboroCity_Text_MayHiLetsRegister:
	.string "{ROCKET}{RIVAL}: {MAGMA}Oh, t'es là toi !\p"
	.string "J'ai croisé Fildrong tout à l'heure et il\n"
	.string "m'a suggéré de te rajouter dans mes\l"
	.string "contacts…\p"
	.string "Eh bien, étant donné que je n'ai pas\n"
	.string "d'autre choix, échangeons nos numéros…\p"
	.string "{ROCKET}… … … … … …$"

RustboroCity_Text_RegisteredMay:
	.string "{EMERALD}Vous avez enregistré {RIVAL}\n"
	.string "dans le PokéPad.$"

RustboroCity_Text_MayPassedBrineyWantToBattle:
	.string "{ROCKET}{RIVAL}: {MAGMA}Abordons maintenant un sujet\n"
	.string "sérieux !\p"
	.string "Nous possédons tous les deux un Badge,\n"
	.string "ce qui signifie qu'on rentre dans la\l"
	.string "cour des grands.\p"
	.string "Je propose qu'on se batte en duel de\n"
	.string "Pokémon !\p"
	.string "C'est une chance pour moi de constater\n"
	.string "les progrès que j'ai réalisés jusqu'à\l"
	.string "présent.\p"
	.string "Vas-y, prépare-toi pour une raclée, le\n"
	.string "rat !$"

RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
	.string "MAY: Oh, what's the matter?\p"
	.string "Haven't you caught or raised your\n"
	.string "POKéMON very much?\p"
	.string "That's not very good for a TRAINER!$"

RustboroCity_Text_MayWantToBattle:
	.string "So, what do you think?\n"
	.string "How about a little battle here?$"

RustboroCity_Text_MayImNotGoingToLose:
	.string "{ROCKET}{RIVAL}: {MAGMA}C'est pas moi qui suis forte,\n"
	.string "c'est toi qui es nul !\p"
	.string "Mais bon, si tu persistes, alors\n"
	.string "engageons-nous dans un combat !$"

RustboroCity_Text_MayDefeat:
	.string "Fait chier ! T'es bien plus fort que je\n"
	.string "ne l'imaginais !$"

RustboroCity_Text_MayMrBrineyHint:
	.string "{ROCKET}{RIVAL}: {MAGMA}Ok, ok !\p"
	.string "Tu as peut-être remporté ce combat,\n"
	.string "mais je te garantis que je vais\l"
	.string "continuer à perfectionner mon équipe !\p"
	.string "Ma prochaine destination sera à\n"
	.string "Kohlanta.\p"
	.string "Il y a une arène là-bas, mais je dois\n"
	.string "trouver un moyen d'y accéder.$"

RustboroCity_Text_BrendanHiLetsRegister:
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
	.string "You had a MATCH CALL feature put\n"
	.string "on your POKéNAV! Cool!\p"
	.string "Let's register each other so we can\n"
	.string "get in touch anytime!\p"
	.string "… … … … … …$"

RustboroCity_Text_RegisteredBrendan:
	.string "Registered BRENDAN\n"
	.string "in the POKéNAV.$"

RustboroCity_Text_BrendanPassedBrineyWantToBattle:
	.string "BRENDAN: By the way, {PLAYER}, I walked\n"
	.string "by MR. BRINEY in PETALBURG WOODS.\p"
	.string "I bet he was on his way home to his\n"
	.string "cottage by the sea.\p"
	.string "{PLAYER}, how's your POKéDEX?\n"
	.string "Have you filled in any pages yet?\p"
	.string "Mine rules.\p"
	.string "Want to have a battle to test how\n"
	.string "far you've progressed?$"

RustboroCity_Text_BrendanNoConfidenceInPokemon:
	.string "BRENDAN: What's the matter? Don't have\n"
	.string "any confidence in your POKéMON?$"

RustboroCity_Text_BrendanWantToBattle:
	.string "BRENDAN: What's up?\n"
	.string "Want to have a battle with me?$"

RustboroCity_Text_BrendanIWontGoEasy:
	.string "BRENDAN: I know you just became\n"
	.string "a TRAINER, but I won't go easy!$"

RustboroCity_Text_BrendanDefeat:
	.string "Hmm…\n"
	.string "You're pretty good.$"

RustboroCity_Text_BrendanMrBrineyHint:
	.string "BRENDAN: By the way, you know\n"
	.string "MR. BRINEY? The guy I just passed?\p"
	.string "I bet you didn't know this, since you\n"
	.string "just moved here, {PLAYER}, but\l"
	.string "MR. BRINEY was once a great sailor.$"

RustboroCity_Text_TunnelNearingCompletion:
	.string "Il est écrit:\n"
	.string "“Seul Link peut vaincre Ganon.”$"

RustboroCity_Text_DevonCorpSign:
	.string "APPLE INC.\n"
	.string "“Think Different.”$"

RustboroCity_Text_GymSign:
	.string "Arène de Larochelle\p"
	.string "Champion: Jamy\n"
	.string "“C’est pas sorcier !”$"

RustboroCity_Text_DevonCorpBranchOfficeSign:
	.string "DEVON CORP. BRANCH OFFICE\p"
	.string "“Access limited to DEVON employees\n"
	.string "and authorized personnel.”$"

RustboroCity_Text_CitySign:
	.string "Larochelle\n"
	.string "“Ville où le passé et l’avenir\l"
	.string "s'entremêlent.”$"

RustboroCity_Text_TrainersSchoolSign:
	.string "Cathédrale$"

RustboroCity_Text_CuttersHouse:
	.string "BarberShop and Ladies\n"
	.string "“Salon de coiffure pour homme et\l"
	.string "femme.”$"

RustboroCity_Text_DevelopedNewPokenavFeature:
	.string "{AQUA}Monsieur Tim Cook m'a envoyé. Il m'a\n"
	.string "donné pour mission d'améliorer votre\l"
	.string "PokéPad.\p"
	.string "Et c'est parfait car j'ai conçu et mis en\n"
	.string "place une toute nouvelle application.\p"
	.string "Vous allez adorer ça !$"

RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
	.string "{AQUA}Formidable !\p"
	.string "L'installation de l'application iCall\n"
	.string "s'est parfaitement déroulée et aucun\l"
	.string "bug n'a été constaté !\p"
	.string "À présent, vous avez la possibilité de\n"
	.string "discuter avec les individus qui sont\l"
	.string "inscrits dans votre PokéPad.\p"
	.string "Allez-y, tentez d'appeler quelqu'un.$"

RustboroCity_Text_PleaseSelectPokenav:
	.string "{AQUA}Il faut que vous vous rendiez sur votre\n"
	.string "PokéPad.$"

RustboroCity_Text_IdBetterGetBackToWork:
	.string "{AQUA}Génial ! Eh bien, il serait bon que je\n"
	.string "reprenne le travail.\p"
	.string "Sur ce, je vous souhaite une bonne\n"
	.string "continuation !$"

RustboroCity_Text_YouCanHave2On2Battle:
	.string "Je te suggère d'aller au BarberShop\n"
	.string "and Ladies.\p"
	.string "J'y ai fait réaliser une belle coiffure.\p"
	.string "Et par-dessus tout, leurs soins sont de\n"
	.string "la meilleure qualité.$"
