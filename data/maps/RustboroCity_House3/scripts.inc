RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Il est toujours sage de bien s'occuper\n"
	.string "de tes Pokémon et de leur attribuer des\l"
	.string "noms plutôt… uniques.\p"
	.string "Je pense que ma femme en abuse un peu\n"
	.string "trop.$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "J'ai donné le nom de Biscotte à mon\n"
	.string "Fusabiri.\p"
	.string "Penses-tu aussi qu'il est adorable à\n"
	.string "croquer ?$"

RustboroCity_House3_Text_Pekachu:
	.string "Biscotte: Biriri !$"

