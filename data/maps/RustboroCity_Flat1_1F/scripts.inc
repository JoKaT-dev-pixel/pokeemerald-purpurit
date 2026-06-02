RustboroCity_Flat1_1F_MapScripts::
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man::
	lock
	faceplayer
	msgbox RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility
	waitmessage
	multichoicedefault 21, 6, MULTI_RUSTBOROCITYFLAT1F, 0, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_Flat1_1F_EventScript_ChooseGreen
	case 1, RustboroCity_Flat1_1F_EventScript_ChooseYellow
	case 2, RustboroCity_Flat1_1F_EventScript_ChooseBlueGreen
	case MULTI_B_PRESSED, Larochelle_EventScript_ChooseIDontKnow
	end

RustboroCity_Flat1_1F_EventScript_ChooseGreen::
	msgbox RustboroCity_Flat1_1F_Text_RedFish, MSGBOX_DEFAULT
	closemessage
	release
	end

RustboroCity_Flat1_1F_EventScript_ChooseYellow::
	msgbox RustboroCity_Flat1_1F_Text_RedFish, MSGBOX_DEFAULT
	closemessage
	release
	end

RustboroCity_Flat1_1F_EventScript_ChooseBlueGreen::
	msgbox RustboroCity_Flat1_1F_Text_RedFish, MSGBOX_DEFAULT
	closemessage
	release
	end

RustboroCity_Flat1_1F_EventScript_Woman::
	msgbox RustboroCity_Flat1_1F_Text_PokemonStrange, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility:
	.string "De quelle couleur sont les p'tits pois ?$"

RustboroCity_Flat1_1F_Text_RedFish:
	.string "Non rouge parce que les p'tits\n"
	.string "poissons rouges, hahahaha !$"

RustboroCity_Flat1_1F_Text_PokemonStrange:
	.string "On sait que tu viens de Larochelle si tu\n"
	.string "emploie souvent l'expression\l"
	.string "“c'tantôt” au lieu de “après-midi”.$"

