const struct Ability gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("No special ability."),
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
        .name = _("Puanteur"),
        .description = COMPOUND_STRING("Émet une odeur si nauséabonde\nqu'il peut effrayer sa cible."),
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("Crachin"),
        .description = COMPOUND_STRING("Le Pokémon invoque la pluie\nquand il entre au combat."),
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("Turbo"),
        .description = COMPOUND_STRING("La Vitesse du Pokémon augmente\nà chaque tour."),
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("Armurbaston"),
        .description = COMPOUND_STRING("Le Pokémon est protégé des\ncoups critiques."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("Fermeté"),
        .description = COMPOUND_STRING("Protège des capacités mettant\nK.O. en un coup."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("Moiteur"),
        .description = COMPOUND_STRING("Empêche les combattants de\ns'autodétruire."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("Échauffement"),
        .description = COMPOUND_STRING("Protège le Pokémon de la\nparalysie."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("Sand Veil"),
        .description = COMPOUND_STRING("Ups evasion in a sandstorm."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("Statik"),
        .description = COMPOUND_STRING("Un contact avec le Pokémon peut\nparalyser."),
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("Absorbe-Volt"),
        .description = COMPOUND_STRING("Récupère des PV si touché par\nune capacité Électrik."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("Absorbe-Eau"),
        .description = COMPOUND_STRING("Récupère des PV si touché par\nune capacité Eau."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("Benêt"),
        .description = COMPOUND_STRING("Immunise le Pokémon contre\nl'attraction ou la provocation."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("Ciel Gris"),
        .description = COMPOUND_STRING("Annule tous les effets liés à la\nmétéo."),
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Œil Composé"),
    #else
        .name = _("CompoundEyes"),
    #endif
        .description = COMPOUND_STRING("Les yeux à facettes du Pokémon\naugmentent sa Précision."),
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("Insomnia"),
        .description = COMPOUND_STRING("Le Pokémon est incapable de\ndormir."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("Homochromie"),
        .description = COMPOUND_STRING("Le Pokémon adopte le type de la\ncapacité ennemie."),
        .aiRating = 2,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("Vaccin"),
        .description = COMPOUND_STRING("Le {PKMN} est naturellement immunisé\ncontre toute forme de poison."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("Torche"),
        .description = COMPOUND_STRING("Booste capacités Feu si touché\npar attaques Feu."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("Écran Poudre"),
        .description = COMPOUND_STRING("Annule les effets cumulés d'une\nattaque ennemie."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("Tempo Perso"),
        .description = COMPOUND_STRING("Vit sa vie à son propre rythme,\nce qui empêche la confusion."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("Ventouse"),
        .description = COMPOUND_STRING("Annule les capacités ou objets\nqui font changer de Pokémon."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("Intimidation"),
        .description = COMPOUND_STRING("Baisse l'Attaque ennemie."),
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("Marque Ombre"),
        .description = COMPOUND_STRING("Empêche le Pokémon ennemi de\nquitter le combat."),
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("Peau Dure"),
        .description = COMPOUND_STRING("Le Pokémon blesse l'ennemi\nqui le touche."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("Garde Mystik"),
        .description = COMPOUND_STRING("Seules les capacités “super efficaces”\nl'atteignent."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("Lévitation"),
        .description = COMPOUND_STRING("Immunise contre toutes les\ncapacités de type Sol."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("Pose Spore"),
        .description = COMPOUND_STRING("Peut paralyser, empoisonner,\nendormir au contact."),
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("Synchro"),
        .description = COMPOUND_STRING("Transmet brûlure, poison ou\nparalysie à l'ennemi."),
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("Corps Sain"),
        .description = COMPOUND_STRING("Empêche les stats du Pokémon\nde baisser"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("Médic Nature"),
        .description = COMPOUND_STRING("Quitter le combat soigne les\nproblèmes de statut."),
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Paratonnerre"),
    #else
        .name = _("LightningRod"),
    #endif
        .description = COMPOUND_STRING("Attire et neutralise l'électricité\net monte l'Atq. Spé."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("Sérénité"),
        .description = COMPOUND_STRING("Augmente les chances d'infliger\ndes effets additionnels."),
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("Glissade"),
        .description = COMPOUND_STRING("Augmente la Vitesse du Pokémon\ns'il pleut."),
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("Chlorophylle"),
        .description = COMPOUND_STRING("Augmente la Vitesse du Pokémon\ns'il y a du soleil."),
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("Luminescence"),
        .description = COMPOUND_STRING("Iillumine les alentours, ce qui\nempêche sa Précision de baisser."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("Calque"),
        .description = COMPOUND_STRING("Imite le talent de l'ennemi."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("Coloforce"),
        .description = COMPOUND_STRING("Double la puissance des attaques\nphysiques."),
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("Point Poison"),
        .description = COMPOUND_STRING("Peut empoisonner l'ennemi s'il\ny a contact."),
        .aiRating = 4,
    },

    [ABILITY_INNER_FOCUS] =
    {
        .name = _("Attention"),
        .description = COMPOUND_STRING("Empêche le Pokémon d'avoir peur."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("Magma Armor"),
        .description = COMPOUND_STRING("Prevents freezing."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("Ignifu-Voile"),
        .description = COMPOUND_STRING("Le voile qui recouvre le Pokémon\nle protège des brûlures."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_MAGNET_PULL] =
    {
        .name = _("Magnépiège"),
        .description = COMPOUND_STRING("Empêche les Pokémon Acier de\nfuir."),
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("Anti-Bruit"),
        .description = COMPOUND_STRING("Protège le Pokémon de toutes\nles capacités sonores."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("Cuvette"),
        .description = COMPOUND_STRING("Récupère progressivement des PV\npar temps de pluie."),
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("Sable Volant"),
        .description = COMPOUND_STRING("Le Pokémon invoque une\ntempête de sable."),
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("Pression"),
        .description = COMPOUND_STRING("Force l'ennemi à dépenser\nplus de PP."),
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("Isograisse"),
        .description = COMPOUND_STRING("Augmente la résistance aux\ncapacités Feu et Glace."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("Matinal"),
        .description = COMPOUND_STRING("Se réveille deux fois plus\nrapidement que les autres."),
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("Corps Ardent"),
        .description = COMPOUND_STRING("Peut brûler l'attaquant s'il\ny a contact."),
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("Fuite"),
        .description = COMPOUND_STRING("Permet de fuir n'importe quel\nPokémon sauvage."),
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("Regard Vif"),
        .description = COMPOUND_STRING("Empêche le Pokémon de perdre\nen précision."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("Hyper Cutter"),
        .description = COMPOUND_STRING("Empêche la réduction de l'Attaque."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("Ramassage"),
        .description = COMPOUND_STRING("Permet parfois au Pokémon de\nramasser des objets."),
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("Absentéisme"),
        .description = COMPOUND_STRING("Le Pokémon ne frappe qu'un tour\nsur deux."),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("Agitation"),
        .description = COMPOUND_STRING("Améliore l'Attaque du Pokémon,\nmais diminue la Précision."),
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("Joli Sourire"),
        .description = COMPOUND_STRING("Séduit parfois l'ennemi au contact."),
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
        .name = _("Plus"),
        .description = COMPOUND_STRING("Augmente l'Atq. Spé. si un Pokémon\na Moins ou Plus."),
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
        .name = _("Moins"),
        .description = COMPOUND_STRING("Augmente l'Atq. Spé. si un Pokémon\na Moins ou Plus."),
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("Forecast"),
        .description = COMPOUND_STRING("Changes with the weather."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("Glu"),
        .description = COMPOUND_STRING("Fait s'agripper à l'objet pour\nen empêcher le vol."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("Mue"),
        .description = COMPOUND_STRING("Soigne parfois ses altérations\nde statut en muant."),
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
        .name = _("Cran"),
        .description = COMPOUND_STRING("Augmente l'Attaque s'il y a un\nproblème de statut."),
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Écaille Spéciale"),
    #else
        .name = _("Marvel Scale"),
    #endif
        .description = COMPOUND_STRING("Augmente la Défense s'il y a un\nproblème de statut."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("Suintement"),
        .description = COMPOUND_STRING("Blesse l'attaquant qui draine\nl'énergie du Pokémon."),
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("Engrais"),
        .description = COMPOUND_STRING("Booste les capacités de type\nPlante en cas de besoin."),
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("Brasier"),
        .description = COMPOUND_STRING("Booste les capacités de type\nFeu en cas de besoin."),
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("Torrent"),
        .description = COMPOUND_STRING("Booste les capacités de type\nEau en cas de besoin."),
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
        .name = _("Essaim"),
        .description = COMPOUND_STRING("Booste les capacités de type\nInsecte en cas de besoin."),
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("Tête de Roc"),
        .description = COMPOUND_STRING("Protège le Pokémon des dégâts\nde contrecoups."),
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("Sécheresse"),
        .description = COMPOUND_STRING("Le Pokémon invoque le soleil\nquand il entre au combat."),
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("Arena Trap"),
        .description = COMPOUND_STRING("Prevents fleeing."),
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("Esprit Vital"),
        .description = COMPOUND_STRING("Empêche le Pokémon de s'endormir."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("Écran Fumée"),
        .description = COMPOUND_STRING("Empêche les stats du Pokémon\nde baisser."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("Pure Power"),
        .description = COMPOUND_STRING("Raises Attack."),
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("Coque Armure"),
        .description = COMPOUND_STRING("Le Pokémon est protégé des\ncoups critiques par sa carapace."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("Air Lock"),
        .description = COMPOUND_STRING("Negates weather effects."),
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("Pieds Confus"),
        .description = COMPOUND_STRING("Augmente l'Esquive du Pokémon\ns'il est confus."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("Motorisé"),
        .description = COMPOUND_STRING("Augmente la Vitesse si touché\npar une capacité Électrik."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("Rivalité"),
        .description = COMPOUND_STRING("Devient plus fort si l'ennemi\nest du même sexe."),
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("Impassible"),
        .description = COMPOUND_STRING("Augmente la Vitesse du Pokémon\nquand il a peur."),
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("Rideau Neige"),
        .description = COMPOUND_STRING("Augmente l'Esquive durant les\ntempêtes de grêle ou neige."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("Gloutonnerie"),
        .description = COMPOUND_STRING("Permet d'utiliser plus\nrapidement une Baie tenue."),
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("Colérique"),
        .description = COMPOUND_STRING("Monte l'Attaque au max après\nun coup critique."),
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("Délestage"),
        .description = COMPOUND_STRING("Augmente la Vitesse si l'objet\ntenu est utilisé ou perdu."),
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("Ignifugé"),
        .description = COMPOUND_STRING("Réduit la puissance des\ncapacités de type Feu."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("Simple"),
        .description = COMPOUND_STRING("Prone to wild stat changes."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("Peau Sèche"),
        .description = COMPOUND_STRING("Perd des PV à la chaleur, mais\nl'eau les restaure."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("Télécharge"),
        .description = COMPOUND_STRING("Ajuste la puissance selon l'ennemi."),
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("Poing de Fer"),
        .description = COMPOUND_STRING("Augmente la puissance des\ncapacités coups de poing."),
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("Poison Heal"),
        .description = COMPOUND_STRING("Restores HP if poisoned."),
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("Adaptabilité"),
        .description = COMPOUND_STRING("Augmente la puissance des\ncapacités de même type."),
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("Multi-Coups"),
        .description = COMPOUND_STRING("Augmente la fréquence des\nattaques multiples."),
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("Hydratation"),
        .description = COMPOUND_STRING("Soigne les problèmes de\nstatut s'il pleut."),
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("Force Soleil"),
        .description = COMPOUND_STRING("Augmente l'Attaque Spéciale\nmais baisse les PV au soleil."),
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("Pied Véloce"),
        .description = COMPOUND_STRING("Augmente la Vitesse en cas\nde problème de statut."),
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("Normalise"),
        .description = COMPOUND_STRING("Toutes les capacités sont\nde type Normal."),
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("Sniper"),
        .description = COMPOUND_STRING("Booste les capacités qui sont des\ncoups critiques."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("Garde Magik"),
        .description = COMPOUND_STRING("Seule une attaque directe peut\nblesser le Pokémon."),
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("Annule Garde"),
        .description = COMPOUND_STRING("Les capacités du {PKMN} et de\nl'ennemi touchent à coup sûr."),
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
        .name = _("Stall"),
        .description = COMPOUND_STRING("Always moves last."),
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("Technicien"),
        .description = COMPOUND_STRING("Augmente la puissance des capacités\nles plus faibles."),
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
        #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Feuille Garde"),
    #else
        .name = _("Leaf Guard"),
    #endif
        .description = COMPOUND_STRING("Empêche les problèmes de statut\nau soleil."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_KLUTZ] =
    {
        .name = _("Maladresse"),
        .description = COMPOUND_STRING("Le Pokémon ne peut utiliser aucun\nobjet tenu."),
        .aiRating = -1,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("Brise Moule"),
        .description = COMPOUND_STRING("Les talents adverses ne bloquent\npas ses capacités."),
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("Chanceux"),
        .description = COMPOUND_STRING("Augmente la fréquence des coups\ncritiques."),
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("Boom Final"),
        .description = COMPOUND_STRING("Blesse l'attaquant qui porte\nle coup de grâce."),
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("Anticipation"),
        .description = COMPOUND_STRING("Senses dangerous moves."),
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("Prédiction"),
        .description = COMPOUND_STRING("Découvre la capacité ennemie\nla plus puissante."),
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("Unaware"),
        .description = COMPOUND_STRING("Ignores stat changes."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("Tinted Lens"),
        .description = COMPOUND_STRING("Ups “not very effective”."),
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
        .name = _("Filtre"),
        .description = COMPOUND_STRING("Affaiblit les capacités\n“super efficaces”."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SLOW_START] =
    {
        .name = _("Début Calme"),
        .description = COMPOUND_STRING("Divise temporairement la Vitesse\net l'Attaque par deux."),
        .aiRating = -2,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("Querelleur"),
        .description = COMPOUND_STRING("Les capacités Normal et Combat\ntouchent les Pokémon Spectre."),
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("Lavabo"),
        .description = COMPOUND_STRING("Attire et neutralise les attaques\nEau, et monte l'Att. Spé."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("Corps Gel"),
        .description = COMPOUND_STRING("Régénère ses PV lors des\ntempêtes de grêle ou neige."),
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("Solide Roc"),
        .description = COMPOUND_STRING("Affaiblit les capacités\n“super efficaces”."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("Alerte Neige"),
    #if B_SNOW_WARNING >= GEN_9
        .description = COMPOUND_STRING("Le Pokémon invoque la neige\nquand il entre au combat."),
    #else
        .description = COMPOUND_STRING("Summons hail in battle."),
    #endif
        .aiRating = 8,
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("Honey Gather"),
        .description = COMPOUND_STRING("May gather Honey."),
        .aiRating = 0,
    },

    [ABILITY_FRISK] =
    {
        .name = _("Frisk"),
        .description = COMPOUND_STRING("Checks a foe's item."),
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("Téméraire"),
        .description = COMPOUND_STRING("Booste les capacités ayant\ndes dégâts de contrecoups."),
        .aiRating = 6,
    },

    [ABILITY_MULTITYPE] =
    {
        .name = _("Multitype"),
        .description = COMPOUND_STRING("Changes type to its Plate."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_FLOWER_GIFT] =
    {
        .name = _("Flower Gift"),
        .description = COMPOUND_STRING("Allies power up in sunshine."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("Mauvais Rêve"),
        .description = COMPOUND_STRING("Réduit les PV d'un ennemi endormi."),
        .aiRating = 4,
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("Pickpocket"),
        .description = COMPOUND_STRING("Vole l'objet de l'ennemi si son\nattaque touche."),
        .aiRating = 3,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("Sans Limite"),
        .description = COMPOUND_STRING("Frappe plus fort mais annule les\neffets cumulés."),
        .aiRating = 8,
    },

    [ABILITY_CONTRARY] =
    {
        .name = _("Contestation"),
        .description = COMPOUND_STRING("Inverse les variations de stats."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("Tension"),
        .description = COMPOUND_STRING("Fait stresser l'ennemi, ce qui\nl'empêche de manger des Baies."),
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("Acharné"),
        .description = COMPOUND_STRING("Augmente beaucoup l'Attaque du\nPokémon quand ses stats baissent."),
        .aiRating = 5,
    },

    [ABILITY_DEFEATIST] =
    {
        .name = _("Defeatist"),
        .description = COMPOUND_STRING("Gives up at half HP."),
        .aiRating = -1,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("Corps Maudit"),
        .description = COMPOUND_STRING("Peut empêcher l'ennemi de\nréutiliser une attaque."),
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
        .name = _("Cœur Soin"),
        .description = COMPOUND_STRING("Guérit parfois le statut des\nalliés alentour."),
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("Garde-Ami"),
        .description = COMPOUND_STRING("Diminue les dégâts subis\npar les alliés."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("Armurouillée"),
        .description = COMPOUND_STRING("Un coup physique baisse la\nDéfense, monte la Vitesse."),
        .aiRating = 2,
    },

    [ABILITY_HEAVY_METAL] =
    {
        .name = _("Heavy Metal"),
        .description = COMPOUND_STRING("Double le poids du Pokémon."),
        .aiRating = -1,
        .breakable = TRUE,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("Light Metal"),
        .description = COMPOUND_STRING("Divise par deux le poids du\nPokémon."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("Multiécaille"),
        .description = COMPOUND_STRING("Reçoit moins de dégâts si les\nPV sont au maximum."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("Toxic Boost"),
        .description = COMPOUND_STRING("Ups Attack if poisoned."),
        .aiRating = 6,
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("Rage Brûlure"),
        .description = COMPOUND_STRING("Booste les attaques spéciales\nsi le statut est brûlure."),
        .aiRating = 5,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("Récolte"),
        .description = COMPOUND_STRING("Permet de réutiliser une même\nBaie plusieurs fois."),
        .aiRating = 5,
    },

    [ABILITY_TELEPATHY] =
    {
        .name = _("Télépathe"),
        .description = COMPOUND_STRING("Anticipe et évite les attaques\nde ses alliés."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_MOODY] =
    {
        .name = _("Lunatique"),
        .description = COMPOUND_STRING("Monte une stat tout en en\nbaissant une autre."),
        .aiRating = 10,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("Envelocape"),
        .description = COMPOUND_STRING("Protège du sable, de la grêle\nou de la poudre."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("Toxitouche"),
        .description = COMPOUND_STRING("Peut empoisonner l'ennemi par\nsimple contact."),
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("Régé-Force"),
        .description = COMPOUND_STRING("Restaure un peu de PV si le\nPokémon est retiré du combat."),
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("Cœur de Coq"),
        .description = COMPOUND_STRING("Empêche les capacités adverses\nde baisser la Défense."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("Sand Rush"),
        .description = COMPOUND_STRING("Ups Speed in a sandstorm."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("Peau Miracle"),
        .description = COMPOUND_STRING("Le Pokémon résiste mieux\naux capacités de statut."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("Analyste"),
        .description = COMPOUND_STRING("Booste les capacités s'il\nattaque en dernier."),
        .aiRating = 5,
    },

    [ABILITY_ILLUSION] =
    {
        .name = _("Illusion"),
        .description = COMPOUND_STRING("Appears as a partner."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("Imposter"),
        .description = COMPOUND_STRING("Transforms into the foe."),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
        #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Infiltration"),
    #else
        .name = _("Infiltrator"),
    #endif
        .description = COMPOUND_STRING("Traverse les barrières et les\nclones adverses pour attaquer."),
        .aiRating = 6,
    },

    [ABILITY_MUMMY] =
    {
        .name = _("Mummy"),
        .description = COMPOUND_STRING("Spreads with contact."),
        .aiRating = 5,
    },

    [ABILITY_MOXIE] =
    {
        .name = _("Impudence"),
        .description = COMPOUND_STRING("Monte l'Attaque quand il met un\nennemi K.O."),
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("Cœur Noble"),
        .description = COMPOUND_STRING("Monte l'Attaque si une attaque\nTénèbres le touche."),
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
        .name = _("Phobique"),
        .description = COMPOUND_STRING("Sa peur de certains types\naugmente sa Vitesse."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("Miroir Magik"),
        .description = COMPOUND_STRING("Renvoie les attaques de statut."),
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("Herbivore"),
        .description = COMPOUND_STRING("Neutralise les attaques Plante\net augmente l'Attaque."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PRANKSTER] =
    {
        .name = _("Farceur"),
        .description = COMPOUND_STRING("Rend les capacités de statut\nprioritaires."),
        .aiRating = 8,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("Force Sable"),
        .description = COMPOUND_STRING("Renforce des capacités en cas\nde tempête de sable."),
        .aiRating = 4,
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("Iron Barbs"),
        .description = COMPOUND_STRING("Hurts to touch."),
        .aiRating = 6,
    },

    [ABILITY_ZEN_MODE] =
    {
        .name = _("Zen Mode"),
        .description = COMPOUND_STRING("Transforms at half HP."),
        .aiRating = -1,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
    },

    [ABILITY_VICTORY_STAR] =
    {
        .name = _("Victory Star"),
        .description = COMPOUND_STRING("Raises party accuracy."),
        .aiRating = 6,
    },

    [ABILITY_TURBOBLAZE] =
    {
        .name = _("Turboblaze"),
        .description = COMPOUND_STRING("Moves hit through abilities."),
        .aiRating = 7,
    },

    [ABILITY_TERAVOLT] =
    {
        .name = _("Teravolt"),
        .description = COMPOUND_STRING("Moves hit through abilities."),
        .aiRating = 7,
    },

    [ABILITY_AROMA_VEIL] =
    {
        .name = _("Aroma-Voile"),
        .description = COMPOUND_STRING("Protège l'équipe des effets\nlimitant le libre arbitre."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
        .name = _("Flower Veil"),
        .description = COMPOUND_STRING("Protects Grass-types."),
        .aiRating = 0,
    },

    [ABILITY_CHEEK_POUCH] =
    {
        .name = _("Cheek Pouch"),
        .description = COMPOUND_STRING("Eating Berries restores HP."),
        .aiRating = 4,
    },

    [ABILITY_PROTEAN] =
    {
        .name = _("Protéen"),
        .description = COMPOUND_STRING("Le Pokémon prend le type de la\ncapacité qu'il utilise."),
        .aiRating = 8,
    },

    [ABILITY_FUR_COAT] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Toison Épaisse"),
    #else
        .name = _("Fur Coat"),
    #endif
        .description = COMPOUND_STRING("Divise les dégâts des attaques\nphysiques par deux."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MAGICIAN] =
    {
        .name = _("Magicien"),
        .description = COMPOUND_STRING("Les capacités volent aussi\nl'objet tenu par la cible."),
        .aiRating = 3,
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("Pare-Balles"),
        .description = COMPOUND_STRING("Protège de certaines capacités\nprojetant des bombes, balles…"),
        .aiRating = 7,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("Competitive"),
        .description = COMPOUND_STRING("Lowered stats up Sp. Atk."),
        .aiRating = 5,
    },

    [ABILITY_STRONG_JAW] =
    {
        .name = _("Prognathe"),
        .description = COMPOUND_STRING("Grâce à une puissante mâchoire,\nles morsures sont plus fortes."),
        .aiRating = 6,
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("Peau Gelée"),
        .description = COMPOUND_STRING("Les capacités de type Normal\ndeviennent de type Glace."),
        .aiRating = 8,
    },

    [ABILITY_SWEET_VEIL] =
    {
        .name = _("Gluco-Voile"),
        .description = COMPOUND_STRING("Les Pokémon de l'équipe ne\npeuvent pas s'endormir."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Stance Change"),
    #else
        .name = _("StanceChange"),
    #endif
        .description = COMPOUND_STRING("Transforms as it battles."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_GALE_WINGS] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Ailes Bourrasque"),
    #else
        .name = _("Gale Wings"),
    #endif
        .description = COMPOUND_STRING("Les attaques Vol sont prioritaires\nsi les PV sont au maximum."),
        .aiRating = 6,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Mega Launcher"),
    #else
        .name = _("MegaLauncher"),
    #endif
        .description = COMPOUND_STRING("Boosts pulse moves."),
        .aiRating = 7,
    },

    [ABILITY_GRASS_PELT] =
    {
        .name = _("Toison Herbue"),
        .description = COMPOUND_STRING("Augmente la Défense du Pokémon\nsi Champ Herbu est actif."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SYMBIOSIS] =
    {
        .name = _("Symbiosis"),
        .description = COMPOUND_STRING("Passes its item to an ally."),
        .aiRating = 0,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
        .name = _("Griffe Dure"),
        .description = COMPOUND_STRING("Augmente la puissance des attaques\ndirectes du Pokémon."),
        .aiRating = 7,
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("Pixilate"),
        .description = COMPOUND_STRING("Normal moves become Fairy."),
        .aiRating = 8,
    },

    [ABILITY_GOOEY] =
    {
        .name = _("Poisseux"),
        .description = COMPOUND_STRING("Diminue la Vitesse de l'attaquant\nqui le touche."),
        .aiRating = 5,
    },

    [ABILITY_AERILATE] =
    {
        .name = _("Aerilate"),
        .description = COMPOUND_STRING("Normal moves become Flying."),
        .aiRating = 8,
    },

    [ABILITY_PARENTAL_BOND] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Parental Bond"),
    #else
        .name = _("ParentalBond"),
    #endif
        .description = COMPOUND_STRING("Moves hit twice."),
        .aiRating = 10,
    },

    [ABILITY_DARK_AURA] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Aura Ténébreuse"),
    #else
        .name = _("Dark Aura"),
    #endif
        .description = COMPOUND_STRING("Renforce les attaques de type\nTénèbres de tous les Pokémon."),
        .aiRating = 6,
    },

    [ABILITY_FAIRY_AURA] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Aura Féerique"),
    #else
        .name = _("Fairy Aura"),
    #endif
        .description = COMPOUND_STRING("Renforce les attaques de type\nFée de tous les Pokémon."),
        .aiRating = 6,
    },

    [ABILITY_AURA_BREAK] =
    {
        .name = _("Aura Break"),
        .description = COMPOUND_STRING("Reverse aura abilities."),
        .aiRating = 3,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Primordial Sea"),
    #else
        .name = _("PrimrdialSea"),
    #endif
        .description = COMPOUND_STRING("Summons heavy rain."),
        .aiRating = 10,
    },

    [ABILITY_DESOLATE_LAND] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Desolate Land"),
    #else
        .name = _("DesolateLand"),
    #endif
        .description = COMPOUND_STRING("Summons intense sunlight."),
        .aiRating = 10,
    },

    [ABILITY_DELTA_STREAM] =
    {
        .name = _("Delta Stream"),
        .description = COMPOUND_STRING("Summons strong winds."),
        .aiRating = 10,
    },

    [ABILITY_STAMINA] =
    {
        .name = _("Endurance"),
        .description = COMPOUND_STRING("Augmente la Défense du Pokémon\nlorsqu'il subit une attaque."),
        .aiRating = 6,
    },

    [ABILITY_WIMP_OUT] =
    {
        .name = _("Wimp Out"),
        .description = COMPOUND_STRING("Flees at half HP."),
        .aiRating = 3,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Emergency Exit"),
    #else
        .name = _("EmergncyExit"),
    #endif
        .description = COMPOUND_STRING("Flees at half HP."),
        .aiRating = 3,
    },

    [ABILITY_WATER_COMPACTION] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Water Compaction"),
    #else
        .name = _("WtrCmpaction"),
    #endif
        .description = COMPOUND_STRING("Water boosts Defense."),
        .aiRating = 4,
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("Cruauté"),
        .description = COMPOUND_STRING("Le coup sera forcément critique\nsi l'adversaire est empoisonné."),
        .aiRating = 4,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
        .name = _("Shields Down"),
        .description = COMPOUND_STRING("Shell breaks at half HP."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_STAKEOUT] =
    {
        .name = _("Filature"),
        .description = COMPOUND_STRING("Double les dégâts si la cible\nvient d'entrer sur le terrain."),
        .aiRating = 6,
    },

    [ABILITY_WATER_BUBBLE] =
    {
        .name = _("Aquabulle"),
        .description = COMPOUND_STRING("Réduit les dégâts des capacités\nFeu. Immunisé contre les brûlures."),
        .aiRating = 8,
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("Expert Acier"),
        .description = COMPOUND_STRING("Augmente la puissance des\nattaques de type Acier."),
        .aiRating = 6,
    },

    [ABILITY_BERSERK] =
    {
        .name = _("Folle Furie"),
        .description = COMPOUND_STRING("Augmente l'Att. Spé. du Pokémon\nlorsqu'il tombe à la moitié de ses PV "),
        .aiRating = 5,
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("Chasse-Neige"),
        .description = COMPOUND_STRING("Augmente la Vitesse durant les\ntempêtes de grêle ou neige."),
        .aiRating = 5,
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("Long Reach"),
        .description = COMPOUND_STRING("Never makes contact."),
        .aiRating = 3,
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("Hydrata-Son"),
        .description = COMPOUND_STRING("Toutes les attaques sonores\ndu Pokémon prennent le type Eau."),
        .aiRating = 5,
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("Prioguérison"),
        .description = COMPOUND_STRING("Les capacités qui soignent\ndeviennent prioritaires."),
        .aiRating = 7,
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("Galvanize"),
        .description = COMPOUND_STRING("Normal moves turn Electric."),
        .aiRating = 8,
    },

    [ABILITY_SURGE_SURFER] =
    {
        .name = _("Surf Caudal"),
        .description = COMPOUND_STRING("La Vitesse du Pokémon est\ndoublée sur un Champ Électrifié."),
        .aiRating = 4,
    },

    [ABILITY_SCHOOLING] =
    {
        .name = _("Schooling"),
        .description = COMPOUND_STRING("Forms a school when strong."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_DISGUISE] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Cache-Boîte"),
    #else
        .name = _("Disguise"),
    #endif
        .description = COMPOUND_STRING("La boîte qui recouvre le\nPokémon protège d'une attaque."),
        .aiRating = 8,
        .breakable = TRUE,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_BATTLE_BOND] =
    {
        .name = _("Battle Bond"),
        .description = COMPOUND_STRING("Changes form after a KO."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_POWER_CONSTRUCT] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Power Construct"),
    #else
        .name = _("PwrConstruct"),
    #endif
        .description = COMPOUND_STRING("Cells aid it when weakened."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_CORROSION] =
    {
        .name = _("Corrosion"),
        .description = COMPOUND_STRING("Permet d'empoisonner les Pokémon\nde type Acier ou Poison."),
        .aiRating = 5,
    },

    [ABILITY_COMATOSE] =
    {
        .name = _("Hypersommeil"),
        .description = COMPOUND_STRING("Rêve en permanence et ne se\nréveille jamais."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Prestance Royale"),
    #else
        .name = _("QueenlyMjsty"),
    #endif
        .description = COMPOUND_STRING("L'adversaire ne peut pas viser\navec une attaque prioritaire."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_INNARDS_OUT] =
    {
        #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Expuls'Organes"),
    #else
        .name = _("Innards Out"),
    #endif
        .description = COMPOUND_STRING("Le Pokémon blesse l'adversaire\nl'ayant mis K.O."),
        .aiRating = 5,
    },

    [ABILITY_DANCER] =
    {
        .name = _("Danseuse"),
        .description = COMPOUND_STRING("Se mets à danser si un Pokémon\nutilise une capacité dansante."),
        .aiRating = 5,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("Battery"),
        .description = COMPOUND_STRING("Boosts ally's Sp. Atk."),
        .aiRating = 0,
    },

    [ABILITY_FLUFFY] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Boule de Poils"),
    #else
        .name = _("Fluffy"),
    #endif
        .description = COMPOUND_STRING("Diminue les dégâts des attaques\ndirectes mais vulnérable au Feu."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("Corps Coloré"),
        .description = COMPOUND_STRING("L'adversaire ne peut pas viser\navec une attaque prioritaire."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("Soul-Heart"),
        .description = COMPOUND_STRING("KOs raise Sp. Atk."),
        .aiRating = 7,
    },

    [ABILITY_TANGLING_HAIR] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Tangling Hair"),
    #else
        .name = _("TanglingHair"),
    #endif
        .description = COMPOUND_STRING("Lowers Speed on contact."),
        .aiRating = 5,
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("Receiver"),
        .description = COMPOUND_STRING("Copies ally's ability."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Power Of Alchemy"),
    #else
        .name = _("PwrOfAlchemy"),
    #endif
        .description = COMPOUND_STRING("Copies ally's ability."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("Beast Boost"),
        .description = COMPOUND_STRING("KOs boost best stat."),
        .aiRating = 7,
    },

    [ABILITY_RKS_SYSTEM] =
    {
        .name = _("RKS System"),
        .description = COMPOUND_STRING("Memories change its type."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_ELECTRIC_SURGE] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Créa-Élec"),
    #else
        .name = _("ElectrcSurge"),
    #endif
        .description = COMPOUND_STRING("Crée un Champ Électrifié au\nmoment où il entre au combat."),
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Psychic Surge"),
    #else
        .name = _("PsychicSurge"),
    #endif
        .description = COMPOUND_STRING("Field becomes weird."),
        .aiRating = 8,
    },

    [ABILITY_MISTY_SURGE] =
    {
        .name = _("Misty Surge"),
        .description = COMPOUND_STRING("Field becomes misty."),
        .aiRating = 8,
    },

    [ABILITY_GRASSY_SURGE] =
    {
        .name = _("Grassy Surge"),
        .description = COMPOUND_STRING("Field becomes grassy."),
        .aiRating = 8,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Full Metal Body"),
    #else
        .name = _("FullMetalBdy"),
    #endif
        .description = COMPOUND_STRING("Prevents stat reduction."),
        .aiRating = 4,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Shadow Shield"),
    #else
        .name = _("ShadowShield"),
    #endif
        .description = COMPOUND_STRING("Halves damage at full HP."),
        .aiRating = 8,
    },

    [ABILITY_PRISM_ARMOR] =
    {
        .name = _("Prism Armor"),
        .description = COMPOUND_STRING("Weakens “supereffective”."),
        .aiRating = 6,
    },

    [ABILITY_NEUROFORCE] =
    {
        .name = _("Neuroforce"),
        .description = COMPOUND_STRING("Ups “supereffective”."),
        .aiRating = 6,
    },

    [ABILITY_INTREPID_SWORD] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Intrepid Sword"),
    #else
        .name = _("IntrepidSwrd"),
    #endif
        .description = COMPOUND_STRING("Ups Attack on entry."),
        .aiRating = 3,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Dauntless Shield"),
    #else
        .name = _("DauntlssShld"),
    #endif
        .description = COMPOUND_STRING("Ups Defense on entry."),
        .aiRating = 3,
    },

    [ABILITY_LIBERO] =
    {
        .name = _("Libero"),
        .description = COMPOUND_STRING("Changes type to move's."),
    },

    [ABILITY_BALL_FETCH] =
    {
        .name = _("Ramasse Ball"),
        .description = COMPOUND_STRING("Ramasse la Poké Ball lors du\npremier lancer raté."),
        .aiRating = 0,
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("Cotton Down"),
        .description = COMPOUND_STRING("Lower Speed of all when hit."),
        .aiRating = 3,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Propulseur"),
    #else
        .name = _("PropellrTail"),
    #endif
        .description = COMPOUND_STRING("Ignore l'effet des capacités ou\ndes talents qui attirent les capacités."),
        .aiRating = 2,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Armure Miroir"),
    #else
        .name = _("Mirror Armor"),
    #endif
        .description = COMPOUND_STRING("Renvoie les effets réducteurs\nde stats qu'il reçoit."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_GULP_MISSILE] =
    {
        .name = _("Gulp Missile"),
        .description = COMPOUND_STRING("If hit, spits prey from sea."),
        .aiRating = 3,
        .cantBeCopied = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STALWART] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Nerfs d'Acier"),
    #else
        .name = _("Stalwart"),
    #endif
        .description = COMPOUND_STRING("Ignore l'effet des capacités ou\ndes talents qui attirent les capacités."),
        .aiRating = 2,
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("Turbine"),
        .description = COMPOUND_STRING("Augmente énormément la Vitesse si\ntouché par une capacité Feu ou Eau."),
        .aiRating = 3,
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("Punk Rock"),
        .description = COMPOUND_STRING("Booste les capacités et réduit\nles dégâts sonores."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SAND_SPIT] =
    {
        .name = _("Sand Spit"),
        .description = COMPOUND_STRING("Creates a sandstorm if hit."),
        .aiRating = 5,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("Ice Scales"),
        .description = COMPOUND_STRING("Halves special damage."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_RIPEN] =
    {
        .name = _("Mûrissement"),
        .description = COMPOUND_STRING("Fait mûrir la Baie qu'il tient\net double ainsi son effet."),
        .aiRating = 4,
    },

    [ABILITY_ICE_FACE] =
    {
        .name = _("Ice Face"),
        .description = COMPOUND_STRING("Hail or Snow renew free hit."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .breakable = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_SPOT] =
    {
        .name = _("Power Spot"),
        .description = COMPOUND_STRING("Powers up ally moves."),
        .aiRating = 2,
    },

    [ABILITY_MIMICRY] =
    {
        .name = _("Mimétisme"),
        .description = COMPOUND_STRING("Adopte le même type que le terrain\nlorsqu'un champ est actif."),
        .aiRating = 2,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Brise-Barrière"),
    #else
        .name = _("ScreenCleanr"),
    #endif
        .description = COMPOUND_STRING("Les effets des écrans des alliés\net des adversaires disparaissent."),
        .aiRating = 3,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Boost Acier"),
    #else
        .name = _("SteelySpirit"),
    #endif
        .description = COMPOUND_STRING("Booste la puissance des capacités\nde type Acier des Pokémon alliés."),
        .aiRating = 2,
    },

    [ABILITY_PERISH_BODY] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Corps Condamné"),
    #else
        .name = _("Perish Body"),
    #endif
        .description = COMPOUND_STRING("Le {PKMN} et l'ennemi tombent K.O. dans\n3 tours si touché par une attaque directe."),
        .aiRating = -1,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Wandering Spirit"),
    #else
        .name = _("WandrngSprit"),
    #endif
        .description = COMPOUND_STRING("Trade abilities on contact."),
        .aiRating = 2,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Entêtement"),
    #else
        .name = _("GorillaTacti"),
    #endif
        .description = COMPOUND_STRING("Monte l'Attaque, mais ne permet\nd'utiliser qu'une seule capacité."),
        .aiRating = 4,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Gaz Inhibiteur"),
    #else
        .name = _("NeutrlzngGas"),
    #endif
        .description = COMPOUND_STRING("Les effets des talents de tous\nles autres Pokémon sont annulés."),
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
        .name = _("Voile Pastel"),
        .description = COMPOUND_STRING("Protège contre toutes les\naltérations de statut liées au poison."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Hunger Switch"),
    #else
        .name = _("HungerSwitch"),
    #endif
        .description = COMPOUND_STRING("Changes form each turn."),
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUICK_DRAW] =
    {
        .name = _("Tir Vif"),
        .description = COMPOUND_STRING("Permet parfois au Pokémon\nd'agir en premier."),
        .aiRating = 4,
    },

    [ABILITY_UNSEEN_FIST] =
    {
        .name = _("Unseen Fist"),
        .description = COMPOUND_STRING("Contact evades protection."),
        .aiRating = 6,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Curious Medicine"),
    #else
        .name = _("CuriusMedicn"),
    #endif
        .description = COMPOUND_STRING("Remove ally's stat changes."),
        .aiRating = 3,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("Transistor"),
        .description = COMPOUND_STRING("Augmente la puissance des capacités\nde type Électrik."),
        .aiRating = 6,
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("Dragon's Maw"),
        .description = COMPOUND_STRING("Ups Dragon-type moves."),
        .aiRating = 6,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Chilling Neigh"),
    #else
        .name = _("ChillngNeigh"),
    #endif
        .description = COMPOUND_STRING("KOs boost Attack stat."),
        .aiRating = 7,
    },

    [ABILITY_GRIM_NEIGH] =
    {
        .name = _("Grim Neigh"),
        .description = COMPOUND_STRING("KOs boost Sp. Atk stat."),
        .aiRating = 7,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
        .name = _("As One"),
        .description = COMPOUND_STRING("Unnerve and Chilling Neigh."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_AS_ONE_SHADOW_RIDER] =
    {
        .name = _("As One"),
        .description = COMPOUND_STRING("Unnerve and Grim Neigh."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_LINGERING_AROMA] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Odeur Tenace"),
    #else
        .name = _("LngerngAroma"),
    #endif
        .description = COMPOUND_STRING("Remplace le talent de\nl'attaquant par Odeur Tenace."),
        .aiRating = 5,
    },

    [ABILITY_SEED_SOWER] =
    {
        .name = _("Seed Sower"),
        .description = COMPOUND_STRING("Affects terrain when hit."),
        .aiRating = 5,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Thermal Exchange"),
    #else
        .name = _("ThrmlExchnge"),
    #endif
        .description = COMPOUND_STRING("Fire hits up Attack."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANGER_SHELL] =
    {
        .name = _("Anger Shell"),
        .description = COMPOUND_STRING("Gets angry at half HP."),
        .aiRating = 3,
    },

    [ABILITY_PURIFYING_SALT] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Purifying Salt"),
    #else
        .name = _("PurfyingSalt"),
    #endif
        .description = COMPOUND_STRING("Protected by pure salts."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Bien Cuit"),
    #else
        .name = _("WellBakedBdy"),
    #endif
        .description = COMPOUND_STRING("Augmente beaucoup la Défense si\ntouché par une capacité Feu."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("Wind Rider"),
        .description = COMPOUND_STRING("Ups Attack if hit by wind."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Chien de Garde"),
    #else
        .name = _("Guard Dog"),
    #endif
        .description = COMPOUND_STRING("L'Attaque du Pokémon augmente\ns'il subit de l'intimidation."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Rocky Payload"),
    #else
        .name = _("RockyPayload"),
    #endif
        .description = COMPOUND_STRING("Powers up Rock moves."),
        .aiRating = 6,
    },

    [ABILITY_WIND_POWER] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Turbine Éolienne"),
    #else
        .name = _("Wind Power"),
    #endif
        .description = COMPOUND_STRING("Se charge en électricité s'il\nsubit une capacité liée au vent."),
        .aiRating = 4,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
        .name = _("Zero to Hero"),
        .description = COMPOUND_STRING("Changes form on switch out."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_COMMANDER] =
    {
        .name = _("Commander"),
        .description = COMPOUND_STRING("Commands from Dondozo."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Grecharge"),
    #else
        .name = _("Elecmrphosis"),
    #endif
        .description = COMPOUND_STRING("Si le Pokémon subit des dégâts,\nil se charge en électricité."),
        .aiRating = 5,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Protosynthesis"),
    #else
        .name = _("Protosnthsis"),
    #endif
        .description = COMPOUND_STRING("Sun boosts best stat."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUARK_DRIVE] =
    {
        .name = _("Quark Drive"),
        .description = COMPOUND_STRING("Elec. field ups best stat."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
        .name = _("Corps en Or"),
        .description = COMPOUND_STRING("Immunise contre les capacités\nde statut des autres Pokémon."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Vessel of Ruin"),
    #else
        .name = _("VesselOfRuin"),
    #endif
        .description = COMPOUND_STRING("Lowers foes' sp. damage."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Sword of Ruin"),
    #else
        .name = _("SwordOfRuin"),
    #endif
        .description = COMPOUND_STRING("Lowers foes' Defense."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Tablets of Ruin"),
    #else
        .name = _("TabltsOfRuin"),
    #endif
        .description = COMPOUND_STRING("Lowers foes' damage."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Beads of Ruin"),
    #else
        .name = _("BeadsOfRuin"),
    #endif
        .description = COMPOUND_STRING("Lowers foes' Sp. Defense."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Orichalcum Pulse"),
    #else
        .name = _("OrchlcumPlse"),
    #endif
        .description = COMPOUND_STRING("Summons sunlight in battle."),
        .aiRating = 8,
    },

    [ABILITY_HADRON_ENGINE] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Hadron Engine"),
    #else
        .name = _("HadronEngine"),
    #endif
        .description = COMPOUND_STRING("Field becomes Electric."),
        .aiRating = 8,
    },

    [ABILITY_OPPORTUNIST] =
    {
        .name = _("Opportuniste"),
        .description = COMPOUND_STRING("Copie l'augmentation des stats si\nles stats de l'ennemi augmentent."),
        .aiRating = 5,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("Cud Chew"),
        .description = COMPOUND_STRING("Eats a used berry again."),
        .aiRating = 4,
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("Incisif"),
        .description = COMPOUND_STRING("Augmente la puissance des\ncapacités tranchantes."),
        .aiRating = 7,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Général Suprême"),
    #else
        .name = _("SuprmeOvrlrd"),
    #endif
        .description = COMPOUND_STRING("L'Att. et l'Att. Spé. augmentent\nlégèrement pour chaque allié mis K.O."),
        .aiRating = 6,
    },

    [ABILITY_COSTAR] =
    {
        .name = _("Collab"),
        .description = COMPOUND_STRING("Copie les changements de stats\nde son allié."),
        .aiRating = 5,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Dépôt Toxique"),
    #else
        .name = _("Toxic Debris"),
    #endif
        .description = COMPOUND_STRING("Répand des pics toxiques si\ntouché par une capacité physique."),
        .aiRating = 4,
    },

    [ABILITY_ARMOR_TAIL] =
    {
        .name = _("Armor Tail"),
        .description = COMPOUND_STRING("Protects from priority."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_EARTH_EATER] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Absorbe-Terre"),
    #else
        .name = _("Earth Eater"),
    #endif
        .description = COMPOUND_STRING("Récupère des PV si touché par\nune capacité Sol."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Mycelium Might"),
    #else
        .name = _("MceliumMight"),
    #endif
        .description = COMPOUND_STRING("Status moves never fail."),
        .aiRating = 2,
    },

    [ABILITY_HOSPITALITY] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Aux Petits Soins"),
    #else
        .name = _("Hospitality"),
    #endif
        .description = COMPOUND_STRING("Restaure quelques PV de l'allié\nen rejoignant le combat."),
        .aiRating = 5,
    },

    [ABILITY_MINDS_EYE] =
    {
        .name = _("Mind's Eye"),
        .description = COMPOUND_STRING("Keen Eye and Scrappy."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Embody Aspect"),
    #else
        .name = _("EmbodyAspect"),
    #endif
        .description = COMPOUND_STRING("Raises Speed."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Embody Aspect"),
    #else
        .name = _("EmbodyAspect"),
    #endif
        .description = COMPOUND_STRING("Raises Attack."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Embody Aspect"),
    #else
        .name = _("EmbodyAspect"),
    #endif
        .description = COMPOUND_STRING("Raises Sp. Def."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Embody Aspect"),
    #else
        .name = _("EmbodyAspect"),
    #endif
        .description = COMPOUND_STRING("Raises Defense."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
        .name = _("Toxic Chain"),
        .description = COMPOUND_STRING("Moves can poison."),
        .aiRating = 8,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Supersweet Syrup"),
    #else
        .name = _("SuprswtSyrup"),
    #endif
        .description = COMPOUND_STRING("Lowers the foe's Evasion."),
        .aiRating = 5,
    },

    [ABILITY_TERA_SHIFT] =
    {
        .name = _("Tera Shift"),
        .description = COMPOUND_STRING("Terasteralizes upon entry."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TERA_SHELL] =
    {
        .name = _("Tera Shell"),
        .description = COMPOUND_STRING("Resistant to types at full HP."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Teraform Zero"),
    #else
        .name = _("TeraformZero"),
    #endif
        .description = COMPOUND_STRING("Removes weather and terrain."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Emprise Toxique"),
    #else
        .name = _("PoisnPuppter"),
    #endif
        .description = COMPOUND_STRING("Rend confus un Pokémon si\nce dernier est empoisonné."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_DOMINANCE] =
    {
        .name = _("Domination"),
        .description = COMPOUND_STRING("Soumets les {PKMN} adverses et baisse\nleur Attaque et Attaque Spéciale."),
        .aiRating = 7,
    },

    [ABILITY_ZERO_VOLT] =
    {
        .name = _("Zéro Volt"),
        .description = COMPOUND_STRING("Permet aux capacités de type\nÉlectrik de toucher le type Sol."),
        .aiRating = 7,
    },

    [ABILITY_MIRAGE] =
    {
        .name = _("Mirage"),
        .description = COMPOUND_STRING("Augmente l'Esquive du Pokémon\ns'il y a du soleil."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_CRYOGENIC] =
    {
        .name = _("Cryogénie"),
        .description = COMPOUND_STRING("Peut geler l'attaquant s'il\ny a contact."),
        .aiRating = 4,
    },

    [ABILITY_MESMERIZE] =
    {
        .name = _("Hypnotique"),
        .description = COMPOUND_STRING("Peut endormir l'attaquant s'il\ny a contact."),
        .aiRating = 4,
    },

    [ABILITY_SOUL_SAP] =
    {
        .name = _("Absorbe-Âme"),
        .description = COMPOUND_STRING("Récupère des PV si touché par\nune capacité Spectre."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATERPROOF] =
    {
        .name = _("Imperméable"),
        .description = COMPOUND_STRING("Diminue de moitié la puissance\ndes capacités de type Eau."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_REGAL] =
    {
        .name = _("Régalien"),
        .description = COMPOUND_STRING("Toutes les capacités offensives\ndu Pokémon sont prioritaires."),
        .aiRating = 6,
    },

    [ABILITY_SOLAR_PANELS] =
    {
        .name = _("Photovoltaïk"),
        .description = COMPOUND_STRING("Récupère progressivement des\nPV lorsqu'il y a du soleil."),
        .aiRating = 3,
    },

    [ABILITY_BAD_LUCK] =
    {
        .name = _("Malchance"),
        .description = COMPOUND_STRING("Réduit les chances des effets\nadditionnels adverses."),
        .aiRating = 8,
    },

    [ABILITY_ANXIETY] =
    {
        .name = _("Angoisse"),
        .description = COMPOUND_STRING("Monte la Vitesse au max après\nun coup critique."),
        .aiRating = 4,
    },

    [ABILITY_INFLATION] =
    {
        .name = _("Inflation"),
        .description = COMPOUND_STRING("Augmente l'Atq et l'Atq Spé.\naprès un coup super efficace."),
        .aiRating = 7,
    },

    [ABILITY_ADRENALINE] =
    {
        .name = _("Adrénaline"),
        .description = COMPOUND_STRING("Augmente la Vitesse du Pokémon\nlorsqu'il tombe à la moitié de ses PV."),
        .aiRating = 7,
    },

    [ABILITY_STUN_GUN] =
    {
        .name = _("Paralyseur"),
        .description = COMPOUND_STRING("Peut paralyser l'ennemi par simple\ncontact."),
        .aiRating = 7,
    },

    [ABILITY_RECORDING] =
    {
        #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Enregistrement"),
    #else
        .name = _("Recording"),
    #endif
        .description = COMPOUND_STRING("Neutralise les capacités sonores et\nmonte l'Attaque Spéciale."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_DETERMINATION] =
    {
        #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Volonté de Fer"),
    #else
        .name = _("Determintn"),
    #endif
        .description = COMPOUND_STRING("Restore quelques PV et augmente\nl'Att. et la Déf. si les PV sont bas."),
        .aiRating = 7,
    },

    [ABILITY_EXOSKELETON] =
    {
        .name = _("Exosquelette"),
        .description = COMPOUND_STRING("Double la Défense du Pokémon."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MASTERMIND] =
    {
        .name = _("Mentaliste"),
        .description = COMPOUND_STRING("Double la puissance des attaques\nspéciales."),
        .aiRating = 10,
    },

    [ABILITY_PERFECTIONNIST] =
    {
        #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Perfectionniste"),
    #else
        .name = _("Perfection"),
    #endif
        .description = COMPOUND_STRING("Augmente beaucoup la Précision mais\nréduit la puissance des capacités."),
        .aiRating = 7,
    },

    [ABILITY_SOUND_WAVE] =
    {
        .name = _("Onde Sonore"),
        .description = COMPOUND_STRING("Immunise et rend prioritaire\nles capacités sonores."),
        .aiRating = 7,
    },

    [ABILITY_MINERALATE] =
    {
        .name = _("Peau Minérale"),
        .description = COMPOUND_STRING("Les capacités de type Normal\ndeviennent de type Roche."),
        .aiRating = 8,
    },

    [ABILITY_NOTHING] =
    {
        .name = _("Rien"),
        .description = COMPOUND_STRING("Ce talent ne fait rien de\nparticulier."),
        .aiRating = 5,
    },

    [ABILITY_MINDLESS] =
    {
        .name = _("Stupide"),
        .description = COMPOUND_STRING("Immunise contre toutes les\ncapacités de type Psy."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_CANNABINOID] =
    {
        .name = _("Cannabinoïde"),
        .description = COMPOUND_STRING("Augmente l'Attaque Spéciale si\ntouché par une capacité Feu."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_MATERIALIST] =
    {
        .name = _("Matérialiste"),
        .description = COMPOUND_STRING("Augmente la puissance des attaques\ns'il tient un objet."),
        .aiRating = 7,
    },

    [ABILITY_YANDERE] =
    {
        .name = _("Yandere"),
        .description = COMPOUND_STRING("Augmente l'Attaque si le Pokémon\nest amoureux."),
        .aiRating = 6,
    },

    [ABILITY_BIG_TAIL] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Queue Épaisse"),
    #else
        .name = _("Big Tail"),
    #endif
        .description = COMPOUND_STRING("Grâce à sa queue robuste,\nles attaques à queue sont plus fortes."),
        .aiRating = 6,
    },

    [ABILITY_SIMPING] =
    {
        .name = _("Simp"),
        .description = COMPOUND_STRING("Attaque toujours après si\nl'ennemi est du sexe opposé."),
        .aiRating = -1,
    },

    [ABILITY_AVIAN_FORCE] =
    {
    #if B_EXPANDED_ABILITY_NAMES == TRUE
        .name = _("Force Aviaire"),
    #else
        .name = _("Avian Force"),
    #endif
        .description = COMPOUND_STRING("Augmente la puissance des\ncapacités physiques de type Vol."),
        .aiRating = 6,
    },

    [ABILITY_PARASITISM] =
    {
        .name = _("Parasitisme"),
        .description = COMPOUND_STRING("Infecte l'ennemi si touché par\nune capacité physique."),
        .aiRating = 6,
    },
};
