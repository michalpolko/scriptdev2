/* Copyright (C) 2006 - 2012 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_ICECROWN_CITADEL_H
#define DEF_ICECROWN_CITADEL_H

enum
{
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
    MAX_ENCOUNTER                   = 12
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

        void OnObjectCreate(GameObject *pGo);
        void OnCreatureCreate(Creature * pCreature);

        uint32 GetData(uint32 uiType);
        void SetData(uint32 uiType, uint32 uiData);

        bool CheckAchievementCriteriaMeet(uint32 uiCriteriaId, Player const* pSource, Unit const* pTarget = NULL, uint32 uiMiscvalue1 = 0);
        bool CheckConditionCriteriaMeet(Player const* pSource, uint32 uiMapId, uint32 uiInstanceConditionId);

    private:
        std::string m_strInstData;
        uint32 m_auiEncounter[MAX_ENCOUNTER];
};

#endif
