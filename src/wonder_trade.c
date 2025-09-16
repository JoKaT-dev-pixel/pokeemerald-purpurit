#include "global.h"
#include "pokemon.h"
#include "strings.h"
#include "random.h"
#include "text.h"
#include "event_data.h"
#include "region_map.h"
#include "constants/species.h"
#include "constants/items.h"
#include "constants/abilities.h"
#include "data/text/wonder_trade_OT_names.h"
#include "constants/region_map_sections.h"
#include "item.h"
#include "constants/item.h"
#include "constants/hold_effects.h"
#include "mail.h"
#include "constants/pokemon.h"
#include "party_menu.h"
#include "field_weather.h"
#include "constants/weather.h"
#include "battle.h" // A workaround to include the expansion's constants/form_change_types.h without breaking Pret/Pokeemerald compatibility.
#include "string_util.h"
#include "daycare.h"
#include "wonder_trade.h"

// This file's functions.
static u16 PickRandomSpecies(void);
static u8 GetWonderTradeOT(u8 *name);
static u16 GetWonderTradeEvolutionTargetSpecies(struct Pokemon *mon);
static u32 GetEvolutionSpecies(u16 speciesId);
static bool32 IsSpeciesFamilyMegaEvolutionCompatible(u16 species, u16 heldStone);
static u16 GetValidHeldItemForSpecies(u16 speciesId);

struct WonderTrade {
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 species;
    u8 ivs[NUM_STATS];
    u8 abilityNum;
    u32 otId;
    u8 conditions[CONTEST_CATEGORIES_COUNT];
    u32 personality;
    u16 heldItem;
    u8 mailNum;
    u8 otName[TRAINER_NAME_LENGTH + 1];
    u8 otGender;
    u8 sheen;
    u16 requestedSpecies;
};

#ifndef RHH_EXPANSION
// This is a list of items that are not used in vanilla.
// Feel free to delete it and remove the check that uses it,
// if you use the pokeemerald-expansion.
static const u16 sIsInvalidItem[] = {
    [ITEM_034]            = TRUE,
    [ITEM_035]            = TRUE,
    [ITEM_036]            = TRUE,
    [ITEM_037]            = TRUE,
    [ITEM_038]            = TRUE,
    [ITEM_039]            = TRUE,
    [ITEM_03A]            = TRUE,
    [ITEM_03B]            = TRUE,
    [ITEM_03C]            = TRUE,
    [ITEM_03D]            = TRUE,
    [ITEM_03E]            = TRUE,
    [ITEM_048]            = TRUE,
    [ITEM_052]            = TRUE,
    [ITEM_057]            = TRUE,
    [ITEM_058]            = TRUE,
    [ITEM_059]            = TRUE,
    [ITEM_05A]            = TRUE,
    [ITEM_05B]            = TRUE,
    [ITEM_05C]            = TRUE,
    [ITEM_063]            = TRUE,
    [ITEM_064]            = TRUE,
    [ITEM_065]            = TRUE,
    [ITEM_066]            = TRUE,
    [ITEM_069]            = TRUE,
    [ITEM_070]            = TRUE,
    [ITEM_071]            = TRUE,
    [ITEM_072]            = TRUE,
    [ITEM_073]            = TRUE,
    [ITEM_074]            = TRUE,
    [ITEM_075]            = TRUE,
    [ITEM_076]            = TRUE,
    [ITEM_077]            = TRUE,
    [ITEM_078]            = TRUE,
    [ITEM_UNUSED_BERRY_1] = TRUE,
    [ITEM_UNUSED_BERRY_2] = TRUE,
    [ITEM_UNUSED_BERRY_3] = TRUE,
    [ITEM_0E2]            = TRUE,
    [ITEM_0E3]            = TRUE,
    [ITEM_0E4]            = TRUE,
    [ITEM_0E5]            = TRUE,
    [ITEM_0E6]            = TRUE,
    [ITEM_0E7]            = TRUE,
    [ITEM_0E8]            = TRUE,
    [ITEM_0E9]            = TRUE,
    [ITEM_0EA]            = TRUE,
    [ITEM_0EB]            = TRUE,
    [ITEM_0EC]            = TRUE,
    [ITEM_0ED]            = TRUE,
    [ITEM_0EE]            = TRUE,
    [ITEM_0EF]            = TRUE,
    [ITEM_0F0]            = TRUE,
    [ITEM_0F1]            = TRUE,
    [ITEM_0F2]            = TRUE,
    [ITEM_0F3]            = TRUE,
    [ITEM_0F4]            = TRUE,
    [ITEM_0F5]            = TRUE,
    [ITEM_0F6]            = TRUE,
    [ITEM_0F7]            = TRUE,
    [ITEM_0F8]            = TRUE,
    [ITEM_0F9]            = TRUE,
    [ITEM_0FA]            = TRUE,
    [ITEM_0FB]            = TRUE,
    [ITEM_0FC]            = TRUE,
    [ITEM_0FD]            = TRUE,
    [ITEM_10B]            = TRUE,
    [ITEM_15B]            = TRUE,
    [ITEM_15C]            = TRUE,
};
#endif

static const u16 sIsValidSpecies[] = {
    SPECIES_POOCHYENA,
    SPECIES_ZIGZAGOON,
    SPECIES_MACHOP,
    SPECIES_LOTAD,
    SPECIES_WURMPLE,
    SPECIES_TAILLOW,
    SPECIES_ABRA,
    SPECIES_NINCADA,
    SPECIES_PIKACHU,
    SPECIES_WHISMUR,
    SPECIES_MIMIKYU,
    SPECIES_KRICKETOT,
    SPECIES_PETILIL,
    SPECIES_PIDGEY,
    SPECIES_SHROOMISH,
    SPECIES_CACNEA,
    SPECIES_MEOWTH,
    SPECIES_NUMEL,
    SPECIES_HORSEA,
    SPECIES_TYNAMO,
};

static const u8 sSpeciesNicknames[][POKEMON_NAME_LENGTH + 1] = {
    [SPECIES_POOCHYENA]  = _("Quoicoubeh"),
    [SPECIES_ZIGZAGOON]  = _("Rocky"),
    [SPECIES_MACHOP]     = _("Achille"),
    [SPECIES_LOTAD]      = _("Naruto"),
    [SPECIES_WURMPLE]    = _("Zika"),
    [SPECIES_TAILLOW]    = _("Crow"),
    [SPECIES_ABRA]       = _("JeDorsWesh"),
    [SPECIES_NINCADA]    = _("NIKTAMÈRE"),
    [SPECIES_PIKACHU]    = _("Chip"),
    [SPECIES_WHISMUR]    = _("Mickey"),
    [SPECIES_MIMIKYU]    = _("Bebou UwU"),
    [SPECIES_KRICKETOT]  = _("Baguette"),
    [SPECIES_PETILIL]    = _("Bob Marley"),
    [SPECIES_PIDGEY]     = _("Omelette"),
    [SPECIES_SHROOMISH]  = _("Schtroumpf"),
    [SPECIES_CACNEA]     = _("Ooga Booga"),
    [SPECIES_MEOWTH]     = _("Mes Impôts"),
    [SPECIES_NUMEL]      = _("Hamdoulah"),
    [SPECIES_HORSEA]     = _("Terayaki"),
    [SPECIES_TYNAMO]     = _("Missclick")
};

static void SetWonderTradeMonNickname(struct Pokemon *mon, u16 wonderTradeSpecies)
{
    u8 monName[POKEMON_NAME_LENGTH + 1] = {0};
    u32 i;

    // 50% chance to copy nickname for species provided in sSpeciesNicknames.
    for (i = 0; i < NELEMS(sSpeciesNicknames); i++)
    {
        if (i == wonderTradeSpecies && (Random() % 99) <= 49)
        {
            StringCopy(monName, sSpeciesNicknames[wonderTradeSpecies]);
            break;
        }
    }

    // If monName is empty a nickname hasn't been stored in it, so copy the species' name.
    if (monName[0] == '\0')
    {
    #ifdef RHH_EXPANSION
        StringCopy(monName, GetSpeciesName(wonderTradeSpecies));
    #else
        GetSpeciesName(monName, wonderTradeSpecies);
    #endif
    }

    SetMonData(mon, MON_DATA_NICKNAME, monName);
}

static u16 PickRandomSpecies(void) // picks only base forms
{
    u16 species = sIsValidSpecies[Random() % NELEMS(sIsValidSpecies)];
    return species;
}

static u8 GetWonderTradeOT(u8 *name)
{
    u8 randGender = (Random() % 2); // 0 for male, 1 for female
    u8 numOTNames = 60;
    u8 selectedName = Random() %numOTNames;
    u8 i;
    if (randGender == MALE) // male OT selected
    {
        randGender = 0;
        for (i = 0; i < 8; ++i)
        {
            name[i] = maleWTNames[selectedName][i];
        }
        name[8] = EOS;
    }
    else                    // female OT selected
    {
        randGender = 0xFF;
        for (i = 0; i < 8; ++i)
        {
            name[i] = femaleWTNames[selectedName][i];
        }
        name[8] = EOS;
    }
    return randGender;
}

void CreateWonderTradePokemon(void)
{
    u16 wonderTradeSpecies = PickRandomSpecies();
    u8 playerMonLevel = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_LEVEL);
    u8 chanceToEvolve = Random() % 99;
    u16 newHeldItem = ITEM_NONE;
    u16 playerMonHeldItem = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HELD_ITEM);
    u32 i;
#ifdef RHH_EXPANSION
    u8 abilityNum;
#endif
    u8 otName[PLAYER_NAME_LENGTH + 1];
    u8 genderOT = GetWonderTradeOT(otName);
    u8 metLocation = METLOC_IN_GAME_TRADE;
    const struct Evolution *evolutions = GetSpeciesEvolutions(playerMonHeldItem);
    struct WonderTrade sWonderTrades[] =
    {
        [0] = {
            .nickname = _(""),
            .species = wonderTradeSpecies,
            .ivs = {(Random() % 32), (Random() % 32), (Random() % 32), (Random() % 32), (Random() % 32), (Random() % 32)},
            .abilityNum = (Random() % 2), // Can't use NUM_NORMAL_ABILITY_SLOTS because it's not present in Pret/Pokeemerald.
            .otId = 0, // Handled by CreateMon->CreateBoxMon.
            .conditions = {0, 0, 0, 0, 0},
            .personality = 0, // Handled by CreateMon->CreateBoxMon.
            .heldItem = newHeldItem,
            .mailNum = -1,
            .otName = _("ERROR"),
            .otGender = (Random() % 2), // Decided by the personality generated in CreateMon->CreateBoxMon.
            .sheen = 0,
            .requestedSpecies = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES)
        },
    };
    struct WonderTrade *wonderTrade = &sWonderTrades[0];

    // Creates the base of a Pokémon in the first slot of a nonexistent enemy's party.
    CreateMon(&gEnemyParty[0], wonderTradeSpecies, playerMonLevel, USE_RANDOM_IVS, FALSE, 0, OT_ID_PRESET, ((Random() << 16) | Random()));

    // 10% chance of having the generated Wonder Traded 'mon carry an item.
    if ((Random() % 99) < 10)
        newHeldItem = GetValidHeldItemForSpecies(wonderTradeSpecies);

    if (playerMonHeldItem == ITEM_NONE)
    {
        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            if (evolutions[i].method == EVO_TRADE_ITEM && Random() % 100 < 50)
            {
                // 30% chance for the in coming Pokémon to hold the item they need to evolve if they need one
                if (Random() % 100 <= 29)
                {
                    newHeldItem = evolutions[i].param;
                    SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &newHeldItem);
                }
            }
        }
    }

    if (chanceToEvolve > 69) // 30% to evolve into the highest stage.
    {
        // 1st pass.
        wonderTradeSpecies = GetWonderTradeEvolutionTargetSpecies(&gEnemyParty[0]);
        SetMonData(&gEnemyParty[0], MON_DATA_SPECIES, &wonderTradeSpecies);
        // 2nd pass.
        wonderTradeSpecies = GetWonderTradeEvolutionTargetSpecies(&gEnemyParty[0]);
        SetMonData(&gEnemyParty[0], MON_DATA_SPECIES, &wonderTradeSpecies);
    }
    else if (chanceToEvolve >= 19 && chanceToEvolve <= 69) // 50% to evolve once.
    {
        wonderTradeSpecies = GetWonderTradeEvolutionTargetSpecies(&gEnemyParty[0]);
        SetMonData(&gEnemyParty[0], MON_DATA_SPECIES, &wonderTradeSpecies);
    }

#ifdef RHH_EXPANSION
    // 10% chance of giving the incoming Pokémon their HA, if they have one
    if (gSpeciesInfo[wonderTradeSpecies].abilities[2] != ABILITY_NONE && (Random() % 99) < 50)
    {
        if ((Random() % 99) < 10)
        {
            abilityNum = 2;
            SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &abilityNum);
        }
    }
#endif

    SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &newHeldItem);
    SetMonData(&gEnemyParty[0], MON_DATA_HP_IV, &wonderTrade->ivs[0]);
    SetMonData(&gEnemyParty[0], MON_DATA_ATK_IV, &wonderTrade->ivs[1]);
    SetMonData(&gEnemyParty[0], MON_DATA_DEF_IV, &wonderTrade->ivs[2]);
    SetMonData(&gEnemyParty[0], MON_DATA_SPEED_IV, &wonderTrade->ivs[3]);
    SetMonData(&gEnemyParty[0], MON_DATA_SPATK_IV, &wonderTrade->ivs[4]);
    SetMonData(&gEnemyParty[0], MON_DATA_SPDEF_IV, &wonderTrade->ivs[5]);
    SetWonderTradeMonNickname(&gEnemyParty[0], wonderTradeSpecies);
    SetMonData(&gEnemyParty[0], MON_DATA_OT_NAME, otName);
    SetMonData(&gEnemyParty[0], MON_DATA_BEAUTY, &wonderTrade->conditions[1]);
    SetMonData(&gEnemyParty[0], MON_DATA_CUTE, &wonderTrade->conditions[2]);
    SetMonData(&gEnemyParty[0], MON_DATA_COOL, &wonderTrade->conditions[0]);
    SetMonData(&gEnemyParty[0], MON_DATA_SMART, &wonderTrade->conditions[3]);
    SetMonData(&gEnemyParty[0], MON_DATA_TOUGH, &wonderTrade->conditions[4]);
    SetMonData(&gEnemyParty[0], MON_DATA_SHEEN, &wonderTrade->sheen);
    SetMonData(&gEnemyParty[0], MON_DATA_OT_GENDER, &genderOT);
    SetMonData(&gEnemyParty[0], MON_DATA_MET_LOCATION, &metLocation);
    CalculateMonStats(&gEnemyParty[0]);
}

#ifdef RHH_EXPANSION
static u16 GetWonderTradeEvolutionTargetSpecies(struct Pokemon *mon)
{
    int i, j;
    u16 targetSpecies = 0;
    u16 partnerSpecies = GetMonData(mon, MON_DATA_SPECIES);
    u32 partnerPersonality = GetMonData(mon, MON_DATA_PERSONALITY);
    u16 upperPersonality = partnerPersonality >> 16;
    u8 partnerLevel = GetMonData(mon, MON_DATA_LEVEL);
    u16 rndEeveevolutionChance = Random() % 8;
    u16 rndAlcrememeEvoChance = Random() % 9;
    u16 currentMap = ((gSaveBlock1Ptr->location.mapGroup) << 8 | gSaveBlock1Ptr->location.mapNum);
    u16 partnerHeldItem = GetMonData(mon, MON_DATA_HELD_ITEM);
    u16 playerSpecies = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES);
    u16 partnerHoldEffect = ItemId_GetHoldEffect(partnerHeldItem);

    const struct Evolution *evolutions = GetSpeciesEvolutions(partnerSpecies);

    // partnerSpecies-specific exceptions.
    if (partnerSpecies == SPECIES_NINCADA && partnerLevel >= 20)
    {
        if ((Random() % 2) == 0)
            targetSpecies = SPECIES_NINJASK;
        else
            targetSpecies = SPECIES_SHEDINJA;
        return targetSpecies;
    }
    else if (partnerSpecies == SPECIES_EEVEE && partnerLevel >= 25)
    {
        if (rndEeveevolutionChance == 0)
            targetSpecies = SPECIES_VAPOREON;
        else if (rndEeveevolutionChance == 1)
            targetSpecies = SPECIES_JOLTEON;
        else if (rndEeveevolutionChance == 2)
            targetSpecies = SPECIES_FLAREON;
        else if (rndEeveevolutionChance == 3)
            targetSpecies = SPECIES_ESPEON;
        else if (rndEeveevolutionChance == 4)
            targetSpecies = SPECIES_UMBREON;
        else if (rndEeveevolutionChance == 5)
            targetSpecies = SPECIES_LEAFEON;
        else if (rndEeveevolutionChance == 6)
            targetSpecies = SPECIES_GLACEON;
        else if (rndEeveevolutionChance == 7)
            targetSpecies = SPECIES_SYLVEON;
        return targetSpecies;
    }
    else if (partnerSpecies == SPECIES_MILCERY && partnerLevel >= 25)
    {
        if (rndAlcrememeEvoChance == 0)
            targetSpecies = SPECIES_ALCREMIE;
        else if (rndAlcrememeEvoChance == 1)
            targetSpecies = SPECIES_ALCREMIE_RUBY_CREAM;
        else if (rndAlcrememeEvoChance == 2)
            targetSpecies = SPECIES_ALCREMIE_MATCHA_CREAM;
        else if (rndAlcrememeEvoChance == 3)
            targetSpecies = SPECIES_ALCREMIE_MINT_CREAM;
        else if (rndAlcrememeEvoChance == 4)
            targetSpecies = SPECIES_ALCREMIE_LEMON_CREAM;
        else if (rndAlcrememeEvoChance == 5)
            targetSpecies = SPECIES_ALCREMIE_SALTED_CREAM;
        else if (rndAlcrememeEvoChance == 6)
            targetSpecies = SPECIES_ALCREMIE_RUBY_SWIRL;
        else if (rndAlcrememeEvoChance == 7)
            targetSpecies = SPECIES_ALCREMIE_CARAMEL_SWIRL;
        else if (rndAlcrememeEvoChance == 8)
            targetSpecies = SPECIES_ALCREMIE_RAINBOW_SWIRL;
        return targetSpecies;
    }

    for (i = 0; i < 5; i++)
    {
        switch (evolutions[i].method)
        {
        case EVO_FRIENDSHIP:
            if ((partnerSpecies == SPECIES_PICHU || partnerSpecies == SPECIES_CLEFFA || partnerSpecies == SPECIES_IGGLYBUFF
              || partnerSpecies == SPECIES_TOGEPI || partnerSpecies == SPECIES_AZURILL || partnerSpecies == SPECIES_BUDEW
              || partnerSpecies == SPECIES_BUNEARY || partnerSpecies == SPECIES_SWOOBAT || partnerSpecies == SPECIES_SWADLOON)
              && partnerLevel >= 16)
                targetSpecies = evolutions[i].targetSpecies;
            else if (partnerSpecies == SPECIES_MEOWTH_ALOLAN && partnerLevel >= 28)
                targetSpecies = evolutions[i].targetSpecies;
            else if ((partnerSpecies == SPECIES_GOLBAT || partnerSpecies == SPECIES_CHANSEY
                   || partnerSpecies == SPECIES_MUNCHLAX) && partnerLevel >= 35)
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_LEVEL:
            if (partnerSpecies == SPECIES_SLOWPOKE && partnerLevel >= 37)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_SLOWBRO;
                else
                    targetSpecies = SPECIES_SLOWKING;
            }
            else if (partnerSpecies == SPECIES_TOXEL && partnerLevel >= 30)
            {
                if (GetNature(mon) == NATURE_HARDY || GetNature(mon) == NATURE_BRAVE
                 || GetNature(mon) == NATURE_ADAMANT || GetNature(mon) == NATURE_NAUGHTY
                 || GetNature(mon) == NATURE_DOCILE || GetNature(mon) == NATURE_IMPISH
                 || GetNature(mon) == NATURE_LAX || GetNature(mon) == NATURE_HASTY
                 || GetNature(mon) == NATURE_JOLLY || GetNature(mon) == NATURE_NAIVE
                 || GetNature(mon) == NATURE_RASH || GetNature(mon) == NATURE_SASSY
                 || GetNature(mon) == NATURE_QUIRKY)
                    targetSpecies = SPECIES_TOXTRICITY;
                else
                    targetSpecies = SPECIES_TOXTRICITY_LOW_KEY;
            }
            else if (evolutions[i].param <= partnerLevel)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            break;
        case EVO_LEVEL_ATK_GT_DEF:
            if (evolutions[i].param <= partnerLevel)
            {
                if (GetMonData(mon, MON_DATA_ATK, 0) > GetMonData(mon, MON_DATA_DEF, 0))
                    targetSpecies = evolutions[i].targetSpecies;
            }
            break;
        case EVO_LEVEL_ATK_EQ_DEF:
            if (evolutions[i].param <= partnerLevel)
            {
                if (GetMonData(mon, MON_DATA_ATK, 0) == GetMonData(mon, MON_DATA_DEF, 0))
                    targetSpecies = evolutions[i].targetSpecies;
            }
            break;
        case EVO_LEVEL_ATK_LT_DEF:
            if (evolutions[i].param <= partnerLevel)
            {
                if (GetMonData(mon, MON_DATA_ATK, 0) < GetMonData(mon, MON_DATA_DEF, 0))
                    targetSpecies = evolutions[i].targetSpecies;
            }
            break;
        case EVO_LEVEL_SILCOON:
            if (evolutions[i].param <= partnerLevel && (upperPersonality % 10) <= 4)
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_LEVEL_CASCOON:
            if (evolutions[i].param <= partnerLevel && (upperPersonality % 10) > 4)
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_BEAUTY:
            if (partnerLevel >= 30)
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_ITEM:
            if (partnerSpecies == SPECIES_GLOOM && partnerLevel >= 36)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_VILEPLUME;
                else
                    targetSpecies = SPECIES_BELLOSSOM;
            }
            else if (partnerSpecies == SPECIES_WEEPINBELL && partnerLevel >= 36)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if ((partnerSpecies == SPECIES_VULPIX || partnerSpecies == SPECIES_GROWLITHE) && partnerLevel >= 32)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if ((partnerSpecies == SPECIES_SHELLDER || partnerSpecies == SPECIES_STARYU) && partnerLevel >= 43)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if ((partnerSpecies == SPECIES_NIDORINA || partnerSpecies == SPECIES_NIDORINO || partnerSpecies == SPECIES_EXEGGCUTE) && partnerLevel >= 26)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if ((partnerSpecies == SPECIES_JIGGLYPUFF || partnerSpecies == SPECIES_CLEFAIRY || partnerSpecies == SPECIES_SKITTY) && partnerLevel >= 38)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if ((partnerSpecies == SPECIES_LOMBRE || partnerSpecies == SPECIES_NUZLEAF) && partnerLevel >= 38)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if (partnerSpecies == SPECIES_POLIWHIRL && partnerLevel >= 44)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_POLIWRATH;
                else
                    targetSpecies = SPECIES_POLITOED;
            }
            else if (partnerSpecies == SPECIES_PIKACHU && partnerLevel >= 27)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if (partnerSpecies == SPECIES_SUNKERN && partnerLevel >= 15)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if ((partnerSpecies == SPECIES_MURKROW || partnerSpecies == SPECIES_MISDREAVUS
                   || partnerSpecies == SPECIES_MUNNA || partnerSpecies == SPECIES_DOUBLADE
                   || partnerSpecies == SPECIES_SINISTEA || partnerSpecies == SPECIES_SANDSHREW_ALOLAN
                   || partnerSpecies == SPECIES_VULPIX_ALOLAN || partnerSpecies == SPECIES_SINISTEA_ANTIQUE)
                   && partnerLevel >= 25)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if ((partnerSpecies == SPECIES_PANSAGE || partnerSpecies == SPECIES_PANSEAR
                   || partnerSpecies == SPECIES_PANPOUR || partnerSpecies == SPECIES_COTTONEE
                   || partnerSpecies == SPECIES_PETILIL || partnerSpecies == SPECIES_MINCCINO
                   || partnerSpecies == SPECIES_FLOETTE || partnerSpecies == SPECIES_FLOETTE_YELLOW_FLOWER
                   || partnerSpecies == SPECIES_FLOETTE_ORANGE_FLOWER || partnerSpecies == SPECIES_FLOETTE_BLUE_FLOWER
                   || partnerSpecies == SPECIES_FLOETTE_WHITE_FLOWER) && partnerLevel >= 15)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if ((partnerSpecies == SPECIES_EELEKTRIK || partnerSpecies == SPECIES_LAMPENT
                   || partnerSpecies == SPECIES_HELIOPTILE || partnerSpecies == SPECIES_CHARJABUG
                   || partnerSpecies == SPECIES_DARUMAKA_GALARIAN) && partnerLevel >= 35)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if (partnerSpecies == SPECIES_APPLIN && partnerLevel >= 30)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_FLAPPLE;
                else
                    targetSpecies = SPECIES_APPLETUN;
            }
            else if (partnerSpecies == SPECIES_SLOWPOKE_GALARIAN && partnerLevel >= 37)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_SLOWBRO_GALARIAN;
                else
                    targetSpecies = SPECIES_SLOWKING_GALARIAN;
            }
            break;
        case EVO_ITEM_FEMALE:
            if (GetMonGender(mon) == MON_FEMALE && partnerSpecies == SPECIES_SNORUNT && partnerLevel >= 35)
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_ITEM_MALE:
            if (GetMonGender(mon) == MON_MALE && partnerSpecies == SPECIES_KIRLIA && partnerLevel >= 35)
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_MOVE:
            if (MonKnowsMove(mon, evolutions[i].param))
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_FRIENDSHIP_MOVE_TYPE:
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (gMovesInfo[GetMonData(mon, MON_DATA_MOVE1 + j, NULL)].type == evolutions[i].param)
                {
                    targetSpecies = evolutions[i].targetSpecies;
                    break;
                }
            }
            break;
        case EVO_LEVEL_DARK_TYPE_MON_IN_PARTY:
            if (evolutions[i].param <= partnerLevel)
            {
                for (j = 0; j < PARTY_SIZE; j++)
                {
                    u16 currSpecies = GetMonData(&gPlayerParty[j], MON_DATA_SPECIES, NULL);
                    if (gSpeciesInfo[currSpecies].types[0] == TYPE_DARK
                     || gSpeciesInfo[currSpecies].types[1] == TYPE_DARK)
                    {
                        targetSpecies = evolutions[i].targetSpecies;
                        break;
                    }
                }
            }
            break;
        case EVO_LEVEL_RAIN:
            j = GetCurrentWeather();
            if (j == WEATHER_RAIN || j == WEATHER_RAIN_THUNDERSTORM || j == WEATHER_DOWNPOUR)
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_MAPSEC:
            if (gMapHeader.regionMapSectionId == evolutions[i].param)
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_SPECIFIC_MAP:
            if (currentMap == evolutions[i].param)
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_SPECIFIC_MON_IN_PARTY:
            for (j = 0; j < PARTY_SIZE; j++)
            {
                if (GetMonData(&gPlayerParty[j], MON_DATA_SPECIES) == evolutions[i].param)
                    targetSpecies = evolutions[i].targetSpecies;
            }
            break;
        case EVO_TRADE:
            targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_TRADE_ITEM:
            if (evolutions[i].param == partnerHeldItem)
            {
                partnerHeldItem = ITEM_NONE;
                SetMonData(mon, MON_DATA_HELD_ITEM, &partnerHeldItem);
                targetSpecies = evolutions[i].targetSpecies;
            }
            break;
        case EVO_TRADE_SPECIFIC_MON:
            if (evolutions[i].param == playerSpecies && partnerHoldEffect != HOLD_EFFECT_PREVENT_EVOLVE)
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_LEVEL_FOG:
            j = GetCurrentWeather();
            if (evolutions[i].param <= partnerLevel && (j == WEATHER_FOG_HORIZONTAL || j == WEATHER_FOG_DIAGONAL))
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_LEVEL_NATURE_AMPED:
            if (evolutions[i].param <= partnerLevel)
            {
                u8 nature = GetNature(mon);
                switch (nature)
                {
                case NATURE_HARDY:
                case NATURE_BRAVE:
                case NATURE_ADAMANT:
                case NATURE_NAUGHTY:
                case NATURE_DOCILE:
                case NATURE_IMPISH:
                case NATURE_LAX:
                case NATURE_HASTY:
                case NATURE_JOLLY:
                case NATURE_NAIVE:
                case NATURE_RASH:
                case NATURE_SASSY:
                case NATURE_QUIRKY:
                    targetSpecies = evolutions[i].targetSpecies;
                    break;
                }
            }
            break;
        case EVO_LEVEL_NATURE_LOW_KEY:
            if (evolutions[i].param <= partnerLevel)
            {
                u8 nature = GetNature(mon);
                switch (nature)
                {
                case NATURE_LONELY:
                case NATURE_BOLD:
                case NATURE_RELAXED:
                case NATURE_TIMID:
                case NATURE_SERIOUS:
                case NATURE_MODEST:
                case NATURE_MILD:
                case NATURE_QUIET:
                case NATURE_BASHFUL:
                case NATURE_CALM:
                case NATURE_GENTLE:
                case NATURE_CAREFUL:
                    targetSpecies = evolutions[i].targetSpecies;
                    break;
                }
            }
            break;
        case EVO_ITEM_HOLD:
            if (partnerHeldItem == evolutions[i].param)
            {
                partnerHeldItem = 0;
                SetMonData(mon, MON_DATA_HELD_ITEM, &partnerHeldItem);
                targetSpecies = evolutions[i].targetSpecies;
            }
            break;
        }
    }

    return (targetSpecies == 0) ? partnerSpecies : targetSpecies;
}
#else
static u16 GetWonderTradeEvolutionTargetSpecies(struct Pokemon *mon)
{
    int i;
    u16 targetSpecies = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
    u16 upperPersonality = personality >> 16;
    u8 level = GetMonData(mon, MON_DATA_LEVEL);
    u16 rndEeveevolutionChance = Random() % 5;

    if (species == SPECIES_EEVEE || species == SPECIES_NINCADA)
    {
        if (species == SPECIES_NINCADA && level >= 20)
        {
            if ((Random() % 2) == 0)
                targetSpecies = SPECIES_NINJASK;
            else
                targetSpecies = SPECIES_SHEDINJA;
            return targetSpecies;
        }
        else if (species == SPECIES_EEVEE && level >= 25)
        {
            if (rndEeveevolutionChance == 0)
                targetSpecies = SPECIES_VAPOREON;
            else if (rndEeveevolutionChance == 1)
                targetSpecies = SPECIES_JOLTEON;
            else if (rndEeveevolutionChance == 2)
                targetSpecies = SPECIES_FLAREON;
            else if (rndEeveevolutionChance == 3)
                targetSpecies = SPECIES_ESPEON;
            else if (rndEeveevolutionChance == 4)
                targetSpecies = SPECIES_UMBREON;
            return targetSpecies;
        }
    }

    for (i = 0; i < 5; i++)
    {
        switch (evolutions[i].method)
        {
        case EVO_FRIENDSHIP:
            if ((species == SPECIES_PICHU || species == SPECIES_CLEFFA || species == SPECIES_IGGLYBUFF
              || species == SPECIES_TOGEPI || species == SPECIES_AZURILL) && level >= 16)
                targetSpecies = evolutions[i].targetSpecies;
            else if ((species == SPECIES_GOLBAT || species == SPECIES_CHANSEY) && level >= 35)
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_LEVEL:
            if (species == SPECIES_SLOWPOKE && level >= 37)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_SLOWBRO;
                else
                    targetSpecies = SPECIES_SLOWKING;
            }
            else if (evolutions[i].param <= level)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            break;
        case EVO_LEVEL_ATK_GT_DEF:
            if (evolutions[i].param <= level)
            {
                if (GetMonData(mon, MON_DATA_ATK, 0) > GetMonData(mon, MON_DATA_DEF, 0))
                    targetSpecies = evolutions[i].targetSpecies;
            }
            break;
        case EVO_LEVEL_ATK_EQ_DEF:
            if (evolutions[i].param <= level)
            {
                if (GetMonData(mon, MON_DATA_ATK, 0) == GetMonData(mon, MON_DATA_DEF, 0))
                    targetSpecies = evolutions[i].targetSpecies;
            }
            break;
        case EVO_LEVEL_ATK_LT_DEF:
            if (evolutions[i].param <= level)
            {
                if (GetMonData(mon, MON_DATA_ATK, 0) < GetMonData(mon, MON_DATA_DEF, 0))
                    targetSpecies = evolutions[i].targetSpecies;
            }
            break;
        case EVO_LEVEL_SILCOON:
            if (evolutions[i].param <= level && (upperPersonality % 10) <= 4)
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_LEVEL_CASCOON:
            if (evolutions[i].param <= level && (upperPersonality % 10) > 4)
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_BEAUTY:
            if (level >= 30)
                targetSpecies = evolutions[i].targetSpecies;
            break;
        case EVO_ITEM:
            if (species == SPECIES_GLOOM && level >= 36)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_VILEPLUME;
                else
                    targetSpecies = SPECIES_BELLOSSOM;
            }
            else if (species == SPECIES_WEEPINBELL && level >= 36)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if ((species == SPECIES_VULPIX || species == SPECIES_GROWLITHE) && level >= 32)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if ((species == SPECIES_SHELLDER || species == SPECIES_STARYU) && level >= 43)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if ((species == SPECIES_NIDORINA || species == SPECIES_NIDORINO || species == SPECIES_EXEGGCUTE) && level >= 26)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if ((species == SPECIES_JIGGLYPUFF || species == SPECIES_CLEFAIRY || species == SPECIES_SKITTY) && level >= 38)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if ((species == SPECIES_LOMBRE || species == SPECIES_NUZLEAF) && level >= 38)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if (species == SPECIES_POLIWHIRL && level >= 44)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_POLIWRATH;
                else
                    targetSpecies = SPECIES_POLITOED;
            }
            else if (species == SPECIES_PIKACHU && level >= 27)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if (species == SPECIES_SUNKERN && level >= 15)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            break;
        case EVO_TRADE_ITEM:
            if ((species == SPECIES_ONIX || species == SPECIES_SEADRA) && level >= 40)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if (species == SPECIES_SCYTHER && level >= 26)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if (species == SPECIES_PORYGON && level >= 21)
            {
                targetSpecies = evolutions[i].targetSpecies;
            }
            else if (species == SPECIES_CLAMPERL && level >= 22)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_HUNTAIL;
                else
                    targetSpecies = SPECIES_GOREBYSS;
            }
            break;
        }
    }

    if (targetSpecies == 0)
        return species;
    else
        return targetSpecies;
}
#endif

#if defined RHH_EXPANSION
static u32 GetEvolutionSpecies(u16 speciesId)
{
    u32 i;
    const struct Evolution *evolutions = GetSpeciesEvolutions(speciesId);

    if (evolutions != NULL)
    {
        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            if (evolutions[i].targetSpecies)
                return evolutions[i].targetSpecies;
        }
    }
    return SPECIES_NONE;
}

static bool32 IsSpeciesFamilyMegaEvolutionCompatible(u16 species, u16 heldStone)
{
    u32 i;
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);
    u16 nextEvo = GetEvolutionSpecies(species);

    for (i = 0; formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        if (formChanges[i].method == FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM && formChanges[i].param1 == heldStone)
            return TRUE;
    }

    if (nextEvo != SPECIES_NONE)
        return IsSpeciesFamilyMegaEvolutionCompatible(nextEvo, heldStone);

    return FALSE;
}
#endif

// Generates an item randomly for a Pokémon received via Wonder Trade to hold, with a few exceptions.
static u16 GetValidHeldItemForSpecies(u16 species)
{
    u16 item;
    u16 holdEffect;
    u16 itemPocket;
    u8 itemImportance;

    ROLL:
        item = Random() % ITEMS_COUNT;

    holdEffect = ItemId_GetHoldEffect(item);
    itemPocket = ItemId_GetPocket(item);
    itemImportance = ItemId_GetImportance(item);

    if (item == ITEM_NONE || item == ITEM_ENIGMA_BERRY)
        goto ROLL;
    else if (holdEffect == HOLD_EFFECT_NONE)
        goto ROLL;
    else if (IS_ITEM_MAIL(item))
        goto ROLL;
    else if (itemPocket == POCKET_KEY_ITEMS || itemPocket == POCKET_TM_HM)
        goto ROLL;
#ifdef RHH_EXPANSION
    else if (item == ITEM_GRACIDEA
          || item == ITEM_RED_ORB
          || item == ITEM_BLUE_ORB
          || item == ITEM_ADAMANT_ORB
          || item == ITEM_LUSTROUS_ORB
          || item == ITEM_GRISEOUS_ORB
          || item == ITEM_ADAMANT_CRYSTAL
          || item == ITEM_LUSTROUS_GLOBE
          || item == ITEM_GRISEOUS_CORE)
        goto ROLL;
    else if ((holdEffect == HOLD_EFFECT_MEMORY || holdEffect == HOLD_EFFECT_DRIVE
           || holdEffect == HOLD_EFFECT_PLATE || holdEffect == HOLD_EFFECT_GEMS)
           && (gSpeciesInfo[species].types[0] != ItemId_GetHoldEffectParam(item)
            || gSpeciesInfo[species].types[1] != ItemId_GetHoldEffectParam(item)))
        goto ROLL;
    // Re-roll the item generated if it's a Mega Stone not compatible with the Pokémon that's being received.
    else if (holdEffect == HOLD_EFFECT_MEGA_STONE && !IsSpeciesFamilyMegaEvolutionCompatible(species, item))
        goto ROLL;
    else if (holdEffect == HOLD_EFFECT_Z_CRYSTAL)
        goto ROLL;
#else
    else if (sIsInvalidItem[item])
        goto ROLL;
#endif
    else if (itemImportance > 0)
        goto ROLL;

    return item;
}
