/* Copyright (C) 2006 - 2012 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_ICECROWN_CITADEL_H
#define DEF_ICECROWN_CITADEL_H

class MANGOS_DLL_DECL instance_icecrown_citadel : ScriptedInstance
{
    public:
        instance_icecrown_citadel(Map *pMap);

        void Initialize() {}
        void Load(const char* data);
        const char* Save();

        void Update(uint32 uiDiff);
        bool IsEncounterInProgress() const;

        void OnPlayerEnter(Player *pPlayer);
        void OnPlayerDeath(Player *pPlayer);
        void OnPlayerLeave(Player *pPlayer);
        void OnObjectCreate(GameObject *pGo);
        void OnCreatureCreate(Creature * pCreature);
        void OnCreatureEnterCombat(Creature * pCreature);
        void OnCreatureEvade(Creature *pCreature);
        void OnCreatureDeath(Creature *pCreature);

        uint32 GetData(uint32 uiType);
        void SetData(uint32 uiType, uint32 uiData);

        bool CheckAchievementCriteriaMeet(uint32 uiCriteriaId, Player const* pSource, Unit const* pTarget = NULL, uint32 uiMiscvalue1 = 0);
        bool CheckConditionCriteriaMeet(Player const* pSource, uint32 uiMapId, uint32 uiInstanceConditionId);
};
