BattleFrontier_BattlePointExchangeServiceCorner_EventObjects: @ 853D018
	object_event 1, EVENT_OBJ_GFX_TEALA, 0, 0, 4, 4, 0, 9, 0, 0, 0, 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F173, 0, 0, 0
	object_event 2, EVENT_OBJ_GFX_BOY_4, 0, 0, 0, 5, 0, 10, 17, 0, 0, 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7E8, 0, 0, 0
	object_event 3, EVENT_OBJ_GFX_WOMAN_2, 0, 0, 0, 4, 0, 8, 17, 0, 0, 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7DD, 0, 0, 0
	object_event 4, EVENT_OBJ_GFX_SAILOR, 0, 0, 14, 6, 0, 2, 17, 0, 0, 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7D4, 0, 0, 0
	object_event 5, EVENT_OBJ_GFX_MAN_6, 0, 0, 1, 9, 0, 2, 17, 0, 0, 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7CB, 0, 0, 0
	object_event 6, EVENT_OBJ_GFX_TEALA, 0, 0, 5, 5, 0, 8, 0, 0, 0, 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F37C, 0, 0, 0
	object_event 7, EVENT_OBJ_GFX_TEALA, 0, 0, 9, 5, 0, 8, 0, 0, 0, 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F49F, 0, 0, 0
	object_event 8, EVENT_OBJ_GFX_TEALA, 0, 0, 10, 4, 0, 10, 0, 0, 0, 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F5F0, 0, 0, 0
	object_event 9, EVENT_OBJ_GFX_GIRL_1, 0, 0, 12, 10, 0, 2, 17, 0, 0, 0, BattleFrontier_BattlePointExchangeServiceCorner_EventScript_25F7F1, 0, 0, 0

BattleFrontier_BattlePointExchangeServiceCorner_MapWarps: @ 853D0F0
	warp_def 7, 10, 0, 6, MAP_BATTLE_FRONTIER_OUTSIDE_EAST
	warp_def 6, 10, 0, 6, MAP_BATTLE_FRONTIER_OUTSIDE_EAST
	warp_def 8, 10, 0, 6, MAP_BATTLE_FRONTIER_OUTSIDE_EAST

BattleFrontier_BattlePointExchangeServiceCorner_MapEvents:: @ 853D108
	map_events BattleFrontier_BattlePointExchangeServiceCorner_EventObjects, BattleFrontier_BattlePointExchangeServiceCorner_MapWarps, 0x0, 0x0
