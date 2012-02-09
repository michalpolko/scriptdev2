/* Copyright (C) 2006 - 2012 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: instance_icecrown_citadel
SD%Complete:
SDComment:
SDCategory: Icecrown Citadel
EndScriptData */

#include "precompiled.h"
#include "icecrown_citadel.h"

instance_icecrown_citadel::instance_icecrown_citadel(Map *pMap) : ScriptedInstance(pMap)
{
    Initialize();
}

void instance_icecrown_citadel::Initialize()
{
    memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
}

void instance_icecrown_citadel::Load(const char *strIn)
{
    if (!strIn)
    {
        OUT_LOAD_INST_DATA_FAIL;
        return;
    }

    OUT_LOAD_INST_DATA(strIn);

    std::istringstream loadStream(strIn);
    loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3]
        >> m_auiEncounter[4] >> m_auiEncounter[5] >> m_auiEncounter[6] >> m_auiEncounter[7] >> m_auiEncounter[8]
        >> m_auiEncounter[9] >> m_auiEncounter[10] >> m_auiEncounter[11] >> m_auiEncounter[12] >> m_auiEncounter[13];

    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
    {
        if (m_auiEncounter[i] == IN_PROGRESS)
            m_auiEncounter[i] = NOT_STARTED;
    }

    OUT_LOAD_INST_DATA_COMPLETE;
}

bool instance_icecrown_citadel::IsEncounterInProgress() const
{
    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
    {
        if (m_auiEncounter[i] == IN_PROGRESS)
            return true;
    }

    return false;
}

void instance_icecrown_citadel::OnPlayerEnter(Player *pPlayer)
{
    m_uiRaidTeam = pPlayer->GetTeam();
}

/**
 * Store Guids and set correct gameobjects' states.
 */
void instance_icecrown_citadel::OnObjectCreate(GameObject *pGo)
{
    switch(pGo->GetEntry())
    {
        case GO_ICEWALL_1:
            if (m_auiEncounter[TYPE_MARROWGAR] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_ICEWALL_2:
            if (m_auiEncounter[TYPE_MARROWGAR] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_DEATHWHISPER_ELEVATOR:
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_SAURFANG_DOOR:
            if (m_auiEncounter[TYPE_DEATHBRINGER_SAURFANG] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_ORANGE_PLAGUE:
            if (m_auiEncounter[TYPE_FESTERGUT] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_GREEN_PLAGUE:
            if (m_auiEncounter[TYPE_ROTFACE] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_SCIENTIST_DOOR_GREEN:
            if (m_auiEncounter[TYPE_ROTFACE] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_SCIENTIST_DOOR_ORANGE:
            if (m_auiEncounter[TYPE_FESTERGUT] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_SCIENTIST_DOOR_COLLISION:
            if (m_auiEncounter[TYPE_FESTERGUT] == DONE && m_auiEncounter[TYPE_ROTFACE] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_SCIENTIST_DOOR:
            if (m_auiEncounter[TYPE_FESTERGUT] == DONE && m_auiEncounter[TYPE_ROTFACE] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_CRIMSON_HALL_DOOR:
            if (m_auiEncounter[TYPE_BLOOD_PRINCE_COUNCIL] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_COUNCIL_DOOR_1:
            if (m_auiEncounter[TYPE_BLOOD_PRINCE_COUNCIL] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_COUNCIL_DOOR_2:
            if (m_auiEncounter[TYPE_BLOOD_PRINCE_COUNCIL] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_GREEN_DRAGON_DOOR_2:
            if (m_auiEncounter[TYPE_VALITHRIA] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_SINDRAGOSA_DOOR_1:
            if (m_auiEncounter[TYPE_VALITHRIA] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_SINDRAGOSA_DOOR_2:
            if (m_auiEncounter[TYPE_VALITHRIA] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
        case GO_SAURFANG_CACHE:
        case GO_SAURFANG_CACHE_25:
        case GO_SAURFANG_CACHE_10_H:
        case GO_SAURFANG_CACHE_25_H:
            m_mGoEntryGuidStore[GO_SAURFANG_CACHE] = pGo->GetObjectGuid();
            break;
        case GO_GUNSHIP_ARMORY_A:
        case GO_GUNSHIP_ARMORY_A_25:
        case GO_GUNSHIP_ARMORY_A_10H:
        case GO_GUNSHIP_ARMORY_A_25H:
            m_mGoEntryGuidStore[GO_GUNSHIP_ARMORY_A] = pGo->GetObjectGuid();
            break;
        case GO_GUNSHIP_ARMORY_H:
        case GO_GUNSHIP_ARMORY_H_25:
        case GO_GUNSHIP_ARMORY_H_10H:
        case GO_GUNSHIP_ARMORY_H_25H:
            m_mGoEntryGuidStore[GO_GUNSHIP_ARMORY_H] = pGo->GetObjectGuid();
            break;
        case GO_DREAMWALKER_CACHE:
        case GO_DREAMWALKER_CACHE_25:
        case GO_DREAMWALKER_CACHE_10_H:
        case GO_DREAMWALKER_CACHE_25_H:
            m_mGoEntryGuidStore[GO_DREAMWALKER_CACHE] = pGo->GetObjectGuid();
            break;
        case GO_ICESHARD_1:
        case GO_ICESHARD_2:
        case GO_ICESHARD_3:
        case GO_ICESHARD_4:
        case GO_FROSTY_WIND:
        case GO_FROSTY_EDGE:
        case GO_SNOW_EDGE:
        case GO_ARTHAS_PLATFORM:
        case GO_ARTHAS_PRECIPICE:
        case GO_GAS_RELEASE_VALVE:
        case GO_MARROWGAR_DOOR:
        case GO_BLOODPRINCE_DOOR:
        case GO_ICECROWN_GRATE:
        case GO_SINDRAGOSA_ENTRANCE:
        case GO_VALITHRIA_DOOR_1:
        case GO_VALITHRIA_DOOR_2:
        case GO_VALITHRIA_DOOR_3:
        case GO_VALITHRIA_DOOR_4:
        case GO_FROSTWING_DOOR:
        case GO_GREEN_DRAGON_DOOR_1:
        case GO_BLOODWING_DOOR:
        case GO_ORATORY_DOOR:
            m_mGoEntryGuidStore[pGo->GetEntry()] = pGo->GetObjectGuid();
            break;
    }
}

void instance_icecrown_citadel::OnCreatureCreate(Creature *pCreature)
{
    switch(pCreature->GetEntry())
    {
        case NPC_LORD_MARROWGAR:
        case NPC_LADY_DEATHWHISPER:
        case NPC_DEATHBRINGER_SAURFANG:
        case NPC_FESTERGUT:
        case NPC_ROTFACE:
        case NPC_PROFESSOR_PUTRICIDE:
        case NPC_TALDARAM:
        case NPC_VALANAR:
        case NPC_KELESETH:
        case NPC_QUEEN_LANATHEL:
        case NPC_LANATHEL_INTRO:
        case NPC_VALITHRIA:
        case NPC_SINDRAGOSA:
        case NPC_LICH_KING:
        case NPC_TIRION:
        case NPC_RIMEFANG:
        case NPC_SPINESTALKER:
        case NPC_STINKY:
        case NPC_PRECIOUS:
        case NPC_VALITHRIA_COMBAT_TRIGGER:
        case NPC_BLOOD_ORB_CONTROL:
             m_mNpcEntryGuidStore[pCreature->GetEntry()] = pCreature->GetObjectGuid();
             break;
    }
}

uint32 instance_icecrown_citadel::GetData(uint32 uiType)
{
    if (uiType >= MAX_DATA_TYPE)
        return 0;
    else
        return m_auiEncounter[uiType];
}

void instance_icecrown_citadel::SetData(uint32 uiType, uint32 uiData)
{
    switch(uiType)
    {
        case TYPE_MARROWGAR:
            m_auiEncounter[TYPE_MARROWGAR] = uiData;
            DoUseDoorOrButton(GO_MARROWGAR_DOOR);
            if (uiData == DONE)
            {
                DoUseDoorOrButton(GO_ICEWALL_1);
                DoUseDoorOrButton(GO_ICEWALL_2);
                DoUseDoorOrButton(GO_ORATORY_DOOR);
            }
            break;
         case TYPE_LADY_DEATHWHISPER:
            m_auiEncounter[TYPE_LADY_DEATHWHISPER] = uiData;
            DoUseDoorOrButton(GO_ORATORY_DOOR);
            // run the elevator
            // currently elevator moving after spawning, don't know how to make it stop :/
            /*if (uiData == DONE)
            {
                if (GameObject* pGO = GetSingleGameObjectFromStorage(GO_DEATHWHISPER_ELEVATOR))
                {
                    pGO->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
                    pGO->SetGoState(GO_STATE_READY);
                }
            }*/
            break;
         case TYPE_GUNSHIP_BATTLE:
            m_auiEncounter[TYPE_GUNSHIP_BATTLE] = uiData;

            if (uiData == DONE)
            {
                if (GetRaidTeam() == ALLIANCE)
                    DoRespawnGameObject(GO_GUNSHIP_ARMORY_A, 60*MINUTE);
                else
                    DoRespawnGameObject(GO_GUNSHIP_ARMORY_H, 60*MINUTE);
            }
            break;
         case TYPE_DEATHBRINGER_SAURFANG:
            m_auiEncounter[TYPE_DEATHBRINGER_SAURFANG] = uiData;

            if (uiData == DONE)
            {
                DoUseDoorOrButton(GO_SAURFANG_DOOR);
                DoRespawnGameObject(GO_SAURFANG_CACHE, 60*MINUTE);
            }
            break;
         case TYPE_FESTERGUT:
            m_auiEncounter[TYPE_FESTERGUT] = uiData;
            DoUseDoorOrButton(GO_ORANGE_PLAGUE);

            if (uiData == DONE)
            {
                DoUseDoorOrButton(GO_SCIENTIST_DOOR_ORANGE);

                if (m_auiEncounter[TYPE_ROTFACE] == DONE)
                    DoUseDoorOrButton(GO_SCIENTIST_DOOR_COLLISION);
            }
            break;
         case TYPE_ROTFACE:
            m_auiEncounter[TYPE_ROTFACE] = uiData;
            DoUseDoorOrButton(GO_GREEN_PLAGUE);

            if (uiData == DONE)
            {
                DoUseDoorOrButton(GO_SCIENTIST_DOOR_GREEN);

                if (m_auiEncounter[TYPE_FESTERGUT] == DONE)
                    DoUseDoorOrButton(GO_SCIENTIST_DOOR_COLLISION);
            }
            break;
         case TYPE_PROFESSOR_PUTRICIDE:
            m_auiEncounter[TYPE_PROFESSOR_PUTRICIDE] = uiData;
            DoUseDoorOrButton(GO_SCIENTIST_DOOR);
            break;
         case TYPE_BLOOD_PRINCE_COUNCIL:
            m_auiEncounter[TYPE_BLOOD_PRINCE_COUNCIL] = uiData;
            DoUseDoorOrButton(GO_CRIMSON_HALL_DOOR);

            if (uiData == DONE)
            {
                DoUseDoorOrButton(GO_COUNCIL_DOOR_1);
                DoUseDoorOrButton(GO_COUNCIL_DOOR_2);
            }
            break;
         case TYPE_QUEEN_LANATHEL:
            m_auiEncounter[TYPE_QUEEN_LANATHEL] = uiData;
            DoUseDoorOrButton(GO_BLOODPRINCE_DOOR);
            if (uiData == DONE)
                DoUseDoorOrButton(GO_ICECROWN_GRATE);
            break;
         case TYPE_VALITHRIA:
            m_auiEncounter[TYPE_VALITHRIA] = uiData;
            DoUseDoorOrButton(GO_GREEN_DRAGON_DOOR_1);
            DoUseDoorOrButton(GO_VALITHRIA_DOOR_1);
            DoUseDoorOrButton(GO_VALITHRIA_DOOR_2);

            if (instance->GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL ||
                instance->GetDifficulty() == RAID_DIFFICULTY_25MAN_HEROIC)
            {
                DoUseDoorOrButton(GO_VALITHRIA_DOOR_3);
                DoUseDoorOrButton(GO_VALITHRIA_DOOR_4);
            }

            if (uiData == DONE)
            {
                DoUseDoorOrButton(GO_GREEN_DRAGON_DOOR_2);
                DoUseDoorOrButton(GO_SINDRAGOSA_DOOR_1);
                DoUseDoorOrButton(GO_SINDRAGOSA_DOOR_2);
                DoRespawnGameObject(GO_DREAMWALKER_CACHE, 60*MINUTE);
            }

            break;
         case TYPE_SINDRAGOSA:
            m_auiEncounter[TYPE_SINDRAGOSA] = uiData;
            DoUseDoorOrButton(GO_SINDRAGOSA_ENTRANCE);
            break;
         case TYPE_LICH_KING:
            m_auiEncounter[TYPE_LICH_KING] = uiData;
            break;
         case TYPE_FROSTMOURNE_ROOM:
             m_auiEncounter[TYPE_FROSTMOURNE_ROOM] = uiData;
             break;
    }

    if (uiData == DONE)
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;

        for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            saveStream << m_auiEncounter[i] << " ";

        m_strInstData = saveStream.str();

        SaveToDB();
        OUT_SAVE_INST_DATA_COMPLETE;
    }
}

bool instance_icecrown_citadel::CheckAchievementCriteriaMeet(uint32 uiCriteriaId, Player const* pSource, Unit const* pTarget, uint32 uiMiscvalue1)
{
    return false;
}

bool instance_icecrown_citadel::CheckConditionCriteriaMeet(Player const* pSource, uint32 uiMapId, uint32 uiInstanceConditionId)
{
    return false;
}

Team instance_icecrown_citadel::GetRaidTeam()
{
    return m_uiRaidTeam;
}

InstanceData* GetInstanceData_instance_icecrown_citadel(Map* pMap)
{
    return new instance_icecrown_citadel(pMap);
}

void AddSC_instance_icecrown_citadel()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "instance_icecrown_citadel";
    pNewScript->GetInstanceData = &GetInstanceData_instance_icecrown_citadel;
    pNewScript->RegisterSelf();
}
