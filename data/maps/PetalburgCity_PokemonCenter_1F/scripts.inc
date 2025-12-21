.set LOCALID_NURSE, 1

PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_Mimicule::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WHISMUR, CRY_MODE_NORMAL
	msgbox PetalburgCity_PokemonCenter_1F_Text_Mimicule, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "C'est trop cool le fait qu'ils ont\n"
	.string "créer un système de stockage pour\l"
	.string "Pokémon dans un PC !\p"
	.string "Tu imagines toi de porter plus d'une\n"
	.string "centaine de Pokémon ?!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Tu veux bien me suivre sur Twitch ?\n"
	.string "Mon compte c'est GoldenChêvre-miel !$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "J'ai conçu un tableau regroupant tous\n"
	.string "les types existants.\p"
	.string "Chaque type possède des faiblesses,\n"
	.string "des résistances et parfois même des\l"
	.string "immunités.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Par exemple, ton Microrge est de\n"
	.string "type Plante.\p"
	.string "Le type Plante est efficace sur le type\n"
	.string "Eau, Roche et Sol.\p"
	.string "Cependant, il est faible face au type\n"
	.string "Feu, Insecte, Plante, Poison et Vol.\p"
	.string "Ouais, ça fait beaucoup de faiblesses\n"
	.string "quand-même…$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Par exemple, ton Serpuff est de\n"
	.string "type Feu.\p"
	.string "Le type Feu est efficace sur le type\n"
	.string "Acier, Glace, Insecte et Plante.\p"
	.string "Cependant, il est faible face au type\n"
	.string "Eau, Roche et Sol.\p"
	.string "C'est un type que beaucoup de dresseurs\n"
	.string "débutants prennent pour l'aventure.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Par exemple, ton Lubryon est de\n"
	.string "type Eau.\p"
	.string "Le type Eau est efficace sur le type\n"
	.string "Feu, Roche et Sol.\p"
	.string "Cependant, il est faible face au type\n"
	.string "Plante et Électrik.\p"
	.string "C'est le type qui recense le plus de\n"
	.string "Pokémon.$"

PetalburgCity_PokemonCenter_1F_Text_Mimicule:
	.string "Mimiscule: Boing !$"

