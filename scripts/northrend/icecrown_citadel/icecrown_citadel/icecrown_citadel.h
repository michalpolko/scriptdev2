/* Copyright (C) 2006 - 2012 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_ICECROWN_CITADEL_H
#define DEF_ICECROWN_CITADEL_H

enum
{
    // encounter types
    TYPE_MARROWGAR                  = 0,
    TYPE_LADY_DEATHWHISPER          = 1,
    TYPE_GUNSHIP_BATTLE             = 2,
    TYPE_DEATHBRINGER_SAURFANG      = 3,
    TYPE_FESTERGUT                  = 4,
    TYPE_ROTFACE                    = 5,
    TYPE_PROFESSOR_PUTRICIDE        = 6,
    TYPE_BLOOD_PRINCE_COUNCIL       = 7,
    TYPE_QUEEN_LANATHEL             = 8,
    TYPE_VALITHRIA                  = 9,
    TYPE_SINDRAGOSA                 = 10,
    TYPE_LICH_KING                  = 11,
    MAX_ENCOUNTER                   = 12,

    // other types, encounter helpers
    TYPE_FROSTMOURNE_ROOM           = 13,
    MAX_DATA_TYPE                   = 14, // limiter for GetData()

    // NPC entries
    // bosses
    NPC_LORD_MARROWGAR          = 36612,
    NPC_LADY_DEATHWHISPER       = 36855,
    NPC_DEATHBRINGER_SAURFANG   = 37813,
    NPC_FESTERGUT               = 36626,
    NPC_ROTFACE                 = 36627,
    NPC_PROFESSOR_PUTRICIDE     = 36678,
    NPC_TALDARAM                = 37973,
    NPC_VALANAR                 = 37970,
    NPC_KELESETH                = 37972,
    NPC_QUEEN_LANATHEL          = 37955,
    NPC_VALITHRIA               = 36789,
    NPC_SINDRAGOSA              = 36853,
    NPC_LICH_KING               = 36597,

    // boss-related and other NPCs
    NPC_OVERLORD_SAURFANG       = 37187,
    NPC_KORKRON_REAVER          = 37920,
    NPC_MURADIN_BRONZEBEARD     = 37200, // Saurfang's encounter and at the instance entrance
    NPC_SKYBREAKER_MARINE       = 37380,
    NPC_ALLIANCE_MASON          = 37902,
    NPC_BLOOD_ORB_CONTROL       = 38008,
    NPC_LANATHEL_INTRO          = 38004,
    NPC_VALITHRIA_QUEST         = 38589,
    NPC_VALITHRIA_COMBAT_TRIGGER= 38752,
    NPC_MURADIN                 = 36948, // Gunship Battle's encounter(?)
    NPC_TIRION                  = 38995,
    NPC_MENETHIL                = 38579,
    NPC_FROSTMOURNE_TRIGGER     = 38584,
    NPC_FROSTMOURNE_HOLDER      = 27880,
    NPC_STINKY                  = 37025,
    NPC_PRECIOUS                = 37217,
    NPC_RIMEFANG                = 37533,
    NPC_SPINESTALKER            = 37534,

    // GameObjects entries
    GO_ICEWALL_1                = 201911,
    GO_ICEWALL_2                = 201910,
    GO_MARROWGAR_DOOR           = 201857,

    GO_ORATORY_DOOR             = 201563,
    GO_DEATHWHISPER_ELEVATOR    = 202220,

    GO_SAURFANG_DOOR            = 201825,

    GO_GAS_RELEASE_VALVE        = 201616,
    GO_ORANGE_PLAGUE            = 201371,
    GO_GREEN_PLAGUE             = 201370,
    GO_SCIENTIST_DOOR_GREEN     = 201614,
    GO_SCIENTIST_DOOR_ORANGE    = 201613,
    GO_SCIENTIST_DOOR_COLLISION = 201612,
    GO_SCIENTIST_DOOR           = 201372,

    GO_BLOODWING_DOOR           = 201920,
    GO_CRIMSON_HALL_DOOR        = 201376,
    GO_COUNCIL_DOOR_1           = 201377,
    GO_COUNCIL_DOOR_2           = 201378,
    GO_BLOODPRINCE_DOOR         = 201746,

    GO_ICECROWN_GRATE           = 201755,
    GO_FROSTWING_DOOR           = 201919,
    GO_GREEN_DRAGON_DOOR_1      = 201375,
    GO_GREEN_DRAGON_DOOR_2      = 201374,
    GO_VALITHRIA_DOOR_1         = 201381,
    GO_VALITHRIA_DOOR_2         = 201382,
    GO_VALITHRIA_DOOR_3         = 201383,
    GO_VALITHRIA_DOOR_4         = 201380,
    GO_SINDRAGOSA_DOOR_1        = 201369,
    GO_SINDRAGOSA_DOOR_2        = 201379,
    GO_SINDRAGOSA_ENTRANCE      = 201373,

    GO_FROZENTRONE_TR           = 202223,
    GO_ICESHARD_1               = 202142,
    GO_ICESHARD_2               = 202141,
    GO_ICESHARD_3               = 202143,
    GO_ICESHARD_4               = 202144,
    GO_FROSTY_WIND              = 202188,
    GO_FROSTY_EDGE              = 202189,
    GO_SNOW_EDGE                = 202190,
    GO_ARTHAS_PLATFORM          = 202161,
    GO_ARTHAS_PRECIPICE         = 202078,

    GO_PLAGUE_SIGIL             = 202182,
    GO_FROSTWING_SIGIL          = 202181,
    GO_BLOODWING_SIGIL          = 202183,

    // loot chests
    GO_SAURFANG_CACHE           = 202239,
    GO_SAURFANG_CACHE_25        = 202240,
    GO_SAURFANG_CACHE_10_H      = 202238,
    GO_SAURFANG_CACHE_25_H      = 202241,

    GO_GUNSHIP_ARMORY_A         = 201872,
    GO_GUNSHIP_ARMORY_A_25      = 201873,
    GO_GUNSHIP_ARMORY_A_10H     = 201874,
    GO_GUNSHIP_ARMORY_A_25H     = 201875,

    GO_GUNSHIP_ARMORY_H         = 202177,
    GO_GUNSHIP_ARMORY_H_25      = 202178,
    GO_GUNSHIP_ARMORY_H_10H     = 202179,
    GO_GUNSHIP_ARMORY_H_25H     = 202180,

    GO_DREAMWALKER_CACHE         = 201959,
    GO_DREAMWALKER_CACHE_25      = 202339,
    GO_DREAMWALKER_CACHE_10_H    = 202338,
    GO_DREAMWALKER_CACHE_25_H    = 202340
};

enum AchievementCriteriaIds
{
    // Lord Marrowgar
    CRITERIA_BONED_10N                  = 12775,
    CRITERIA_BONED_25N                  = 12962,
    CRITERIA_BONED_10H                  = 13393,
    CRITERIA_BONED_25H                  = 13394,

    // Rotface
    CRITERIA_DANCES_WITH_OOZES_10N      = 12984,
    CRITERIA_DANCES_WITH_OOZES_25N      = 12966,
    CRITERIA_DANCES_WITH_OOZES_10H      = 12985,
    CRITERIA_DANCES_WITH_OOZES_25H      = 12983,

    // Professor Putricide
    CRITERIA_NAUSEA_10N                 = 12987,
    CRITERIA_NAUSEA_25N                 = 12968,
    CRITERIA_NAUSEA_10H                 = 12988,
    CRITERIA_NAUSEA_25H                 = 12981,

    // Blood Prince Council
    CRITERIA_ORB_WHISPERER_10N          = 13033,
    CRITERIA_ORB_WHISPERER_25N          = 12969,
    CRITERIA_ORB_WHISPERER_10H          = 13034,
    CRITERIA_ORB_WHISPERER_25H          = 13032,

    // Blood-Queen Lana'thel
    CRITERIA_KILL_LANA_THEL_10M         = 13340,
    CRITERIA_KILL_LANA_THEL_25M         = 13360,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_10N  = 12780,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_25N  = 13012,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_10V  = 13011,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_25V  = 13013,
};

class MANGOS_DLL_DECL instance_icecrown_citadel : public ScriptedInstance
{
    public:
        instance_icecrown_citadel(Map *pMap);

        void Initialize();
        void Load(const char* strIn);

        const char* Save()
        {
            return m_strInstData.c_str();
        }

        bool IsEncounterInProgress() const;

        void OnPlayerEnter(Player *pPlayer);

        void OnObjectCreate(GameObject *pGo);
        void OnCreatureCreate(Creature * pCreature);

        uint32 GetData(uint32 uiType);
        void SetData(uint32 uiType, uint32 uiData);

        bool CheckAchievementCriteriaMeet(uint32 uiCriteriaId, Player const* pSource, Unit const* pTarget = NULL, uint32 uiMiscvalue1 = 0);
        bool CheckConditionCriteriaMeet(Player const* pSource, uint32 uiMapId, uint32 uiInstanceConditionId);

        Team GetRaidTeam();

    private:
        std::string m_strInstData;
        uint32 m_auiEncounter[MAX_ENCOUNTER];

        // raid is from Alliance or Horde?
        Team m_uiRaidTeam;
};

class MANGOS_DLL_DECL base_icc_creatureAI : public ScriptedAI
{
    public:
        base_icc_creatureAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
            m_uiMapDifficulty = pCreature->GetMap()->GetDifficulty();
            m_bIsHeroic = m_uiMapDifficulty > RAID_DIFFICULTY_25MAN_NORMAL;
            m_bIs25Man = (m_uiMapDifficulty == RAID_DIFFICULTY_25MAN_NORMAL || m_uiMapDifficulty == RAID_DIFFICULTY_25MAN_HEROIC);
        }

        virtual void Reset() = 0;
        virtual void UpdateAI(const uint32 uiDiff) = 0;

    protected:
        ScriptedInstance* m_pInstance;
        Difficulty m_uiMapDifficulty;
        bool m_bIsHeroic;
        bool m_bIs25Man;
};

#endif
