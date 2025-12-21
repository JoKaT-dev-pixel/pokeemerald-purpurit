.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Man::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersHealsPokemon, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Woman::
	msgbox OldaleTown_PokemonCenter_1F_Text_Woman, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersHealsPokemon:
	.string "Le Centre Pokémon est un endroit\n"
	.string "idéal pour soigner ses Pokémon.\p"
	.string "Non seulement c'est génial, mais en\n"
	.string "plus, c'est gratuit !$"

OldaleTown_PokemonCenter_1F_Text_Woman:
	.string "Parfois, je me demande vraiment si ça\n"
	.string "existe des personnes qui utilisent des\l"
	.string "Pokémon pour des fins politiques ?!\p"
	.string "Ça serait horrible !$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "Finalement, tu as pu voir ce qu'il y a\n"
	.string "au 2e étage !\p"
	.string "C'est cool !$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "Apparemment, y'a une dinguerie au\n"
	.string "premier étage mais flemme d'y aller.$"

