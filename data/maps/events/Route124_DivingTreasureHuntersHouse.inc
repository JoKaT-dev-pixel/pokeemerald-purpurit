Route124_DivingTreasureHuntersHouse_EventObjects: @ 853ED9C
	object_event 1, EVENT_OBJ_GFX_MAN_6, 0, 0, 5, 4, 0, 9, 0, 0, 0, 0, Route124_DivingTreasureHuntersHouse_EventScript_270A32, 0, 0, 0

Route124_DivingTreasureHuntersHouse_MapWarps: @ 853EDB4
	warp_def 3, 8, 0, 0, MAP_ROUTE124
	warp_def 4, 8, 0, 0, MAP_ROUTE124

Route124_DivingTreasureHuntersHouse_MapBGEvents: @ 853EDC4
	bg_event 7, 1, 0, 0, 0, Route124_DivingTreasureHuntersHouse_EventScript_270F63

Route124_DivingTreasureHuntersHouse_MapEvents:: @ 853EDD0
	map_events Route124_DivingTreasureHuntersHouse_EventObjects, Route124_DivingTreasureHuntersHouse_MapWarps, 0x0, Route124_DivingTreasureHuntersHouse_MapBGEvents