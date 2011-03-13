/* Copyright (C) 2006 - 2011 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Borean_Tundra
SD%Complete: 100
SDComment: Quest support: 11708, 11692, 11961, 11865, 12019. Taxi vendors. 11570
SDCategory: Borean Tundra
EndScriptData */

/* ContentData
npc_fizzcrank_fullthrottle
npc_iruk
npc_kara_thricestar
npc_nesingwary_trapper
go_caribou_trap
npc_surristrasz
npc_tiare
npc_lurgglbr
mob_elder
mob_arcane_prisoner
go_tadpole_cage
mob_tadpole
go_mammoth_trap
npc_beryl_sorcerer
go_scourge_cage
npc_nexus_drake
npc_valanar
npc_thassarian
EndContentData */

#include "precompiled.h"
#include "ObjectMgr.h"
#include "escort_ai.h"
#include "follower_ai.h"

/*######
## npc_fizzcrank_fullthrottle
######*/

#define GOSSIP_ITEM_GO_ON   "Go on."
#define GOSSIP_ITEM_TELL_ME "Tell me what's going on out here, Fizzcrank."

enum
{
    GOSSIP_TEXTID_FIZZCRANK1    = 12456,
    GOSSIP_TEXTID_FIZZCRANK2    = 12457,
    GOSSIP_TEXTID_FIZZCRANK3    = 12458,
    GOSSIP_TEXTID_FIZZCRANK4    = 12459,
    GOSSIP_TEXTID_FIZZCRANK5    = 12460,
    GOSSIP_TEXTID_FIZZCRANK6    = 12461,
    GOSSIP_TEXTID_FIZZCRANK7    = 12462,
    GOSSIP_TEXTID_FIZZCRANK8    = 12463,
    GOSSIP_TEXTID_FIZZCRANK9    = 12464,

    QUEST_THE_MECHAGNOMES       = 11708
};

bool GossipHello_npc_fizzcrank_fullthrottle(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_THE_MECHAGNOMES) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TELL_ME, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_fizzcrank_fullthrottle(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK1, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK2, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK3, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK4, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK5, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK6, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+7:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK7, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+8:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_GO_ON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK8, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+9:
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FIZZCRANK9, pCreature->GetGUID());
            pPlayer->AreaExploredOrEventHappens(QUEST_THE_MECHAGNOMES);
            break;
    }
    return true;
}

/*######
## npc_iruk
######*/

#define GOSSIP_ITEM_IRUK        "<Search corpse for Issliruk's Totem.>"

enum
{
    QUEST_SPIRITS_WATCH_OVER_US     = 11961,
    SPELL_CREATE_TOTEM              = 46816
};

bool GossipHello_npc_iruk(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_SPIRITS_WATCH_OVER_US) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_IRUK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_iruk(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->CastSpell(pPlayer,SPELL_CREATE_TOTEM,true);
    }

    return true;
}

/*######
## npc_kara_thricestar
######*/

#define GOSSIP_ITEM_THRICESTAR1      "Do you think I could take a ride on one of those flying machines?"
#define GOSSIP_ITEM_THRICESTAR2      "Kara, I need to be flown out the Dens of Dying to find Bixie."

enum
{
    QUEST_CHECK_IN_WITH_BIXIE       = 11692,
    SPELL_FIZZCRANK_AIRSTRIP        = 51446
};

bool GossipHello_npc_kara_thricestar(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isTaxi())
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, GOSSIP_ITEM_THRICESTAR1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

    if (pPlayer->GetQuestStatus(QUEST_CHECK_IN_WITH_BIXIE) == QUEST_STATUS_COMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_THRICESTAR2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_kara_thricestar(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
            pPlayer->GetSession()->SendTaxiMenu(pCreature);
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CastSpell(pPlayer, SPELL_FIZZCRANK_AIRSTRIP, false);
            break;
    }

    return true;
}

/*######
## npc_nesingwary_trapper
######*/

enum
{
    NPC_NESINGWARY_TRAPPER  = 25835,
    GO_QUALITY_FUR          = 187983,

    SAY_PHRASE_1            = -1000599,
    SAY_PHRASE_2            = -1000600,
    SAY_PHRASE_3            = -1000601,
    SAY_PHRASE_4            = -1000602
};

struct MANGOS_DLL_DECL npc_nesingwary_trapperAI : public ScriptedAI
{
    npc_nesingwary_trapperAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    uint8 m_uiPhase;
    uint32 m_uiPhaseTimer;
    uint64 m_uiPlayerGUID;
    uint64 m_uiGobjectTrapGUID;

    void Reset()
    {
        m_uiPhase = 0;
        m_uiPhaseTimer = 0;
        m_uiPlayerGUID = 0;
        m_uiGobjectTrapGUID = 0;
    }

    void StartAction(uint64 uiPlayerGUID, uint64 uiGoTrapGUID)
    {
        m_uiPhase = 1;
        m_uiPhaseTimer = 3000;
        m_uiPlayerGUID = uiPlayerGUID;
        m_uiGobjectTrapGUID = uiGoTrapGUID;

        switch (urand(0, 3))
        {
            case 0: DoScriptText(SAY_PHRASE_1, m_creature); break;
            case 1: DoScriptText(SAY_PHRASE_2, m_creature); break;
            case 2: DoScriptText(SAY_PHRASE_3, m_creature); break;
            case 3: DoScriptText(SAY_PHRASE_4, m_creature); break;
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!m_creature->getVictim() && m_uiPhase)
        {
            if (m_uiPhaseTimer <= uiDiff)
            {
                switch(m_uiPhase)
                {
                    case 1:
                        if (GameObject* pTrap = m_creature->GetMap()->GetGameObject(m_uiGobjectTrapGUID))
                        {
                            if (pTrap->isSpawned())
                                m_creature->GetMotionMaster()->MovePoint(0, pTrap->GetPositionX(), pTrap->GetPositionY(), pTrap->GetPositionZ());
                        }
                        break;
                    case 2:
                        if (GameObject* pTrap = m_creature->GetMap()->GetGameObject(m_uiGobjectTrapGUID))
                        {
                            if (pTrap->isSpawned())
                            {
                                pTrap->Use(m_creature);

                                if (Player* pPlayer = m_creature->GetMap()->GetPlayer(m_uiPlayerGUID))
                                {
                                    if (pPlayer->isAlive())
                                        pPlayer->KilledMonsterCredit(m_creature->GetEntry());
                                }
                            }
                        }
                        break;
                }

                m_uiPhase = 0;
            }
            else
                m_uiPhaseTimer -= uiDiff;
        }
    }

    void MovementInform(uint32 uiType, uint32 uiPointId)
    {
        m_creature->HandleEmote(EMOTE_ONESHOT_LOOT);
        m_uiPhaseTimer = 2000;
        m_uiPhase = 2;
    }
};

CreatureAI* GetAI_npc_nesingwary_trapper(Creature* pCreature)
{
    return new npc_nesingwary_trapperAI(pCreature);
}

/*######
## go_caribou_trap
######*/

bool GOUse_go_caribou_trap(Player* pPlayer, GameObject* pGo)
{
    float fX, fY, fZ;
    pGo->GetClosePoint(fX, fY, fZ, pGo->GetObjectBoundingRadius(), 2*INTERACTION_DISTANCE, frand(0, M_PI_F*2));

    if (Creature* pCreature = pGo->SummonCreature(NPC_NESINGWARY_TRAPPER, fX, fY, fZ, pGo->GetOrientation(), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10000))
    {
        if (npc_nesingwary_trapperAI* pTrapperAI = dynamic_cast<npc_nesingwary_trapperAI*>(pCreature->AI()))
            pTrapperAI->StartAction(pPlayer->GetGUID(), pGo->GetGUID());

        pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);

        if (GameObject* pGoFur = GetClosestGameObjectWithEntry(pGo, GO_QUALITY_FUR, INTERACTION_DISTANCE))
        {
            if (!pGoFur->isSpawned())
            {
                pGoFur->SetRespawnTime(10);
                pGoFur->Refresh();
            }
        }
    }

    return true;
}

/*######
## npc_surristrasz
######*/

#define GOSSIP_ITEM_FREE_FLIGHT "I'd like passage to the Transitus Shield."
#define GOSSIP_ITEM_FLIGHT      "May I use a drake to fly elsewhere?"

enum
{
    SPELL_ABMER_TO_COLDARRA     = 46064
};

bool GossipHello_npc_surristrasz(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pCreature->isTaxi())
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FREE_FLIGHT, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_GOSSIP);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, GOSSIP_ITEM_FLIGHT, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_TAXIVENDOR);
    }

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_surristrasz(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_OPTION_GOSSIP)
    {
        pPlayer->CLOSE_GOSSIP_MENU();

        //TaxiPath 795 (amber to coldarra)
        pPlayer->CastSpell(pPlayer, SPELL_ABMER_TO_COLDARRA, true);
    }

    if (uiAction == GOSSIP_OPTION_TAXIVENDOR)
        pPlayer->GetSession()->SendTaxiMenu(pCreature);

    return true;
}

/*######
## npc_tiare
######*/

#define GOSSIP_ITEM_TELEPORT    "Teleport me to Amber Ledge, please."

enum
{
    SPELL_TELEPORT_COLDARRA     = 50135
};

bool GossipHello_npc_tiare(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TELEPORT, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_GOSSIP);
    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_tiare(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_OPTION_GOSSIP)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->CastSpell(pPlayer, SPELL_TELEPORT_COLDARRA, true);
    }
    return true;
}

/*######
## npc_lurgglbr
######*/

enum
{
    QUEST_ESCAPE_FROM_WINTERFIN_CAVERNS = 11570,
    GO_CAGE                             = 187369,

    SAY_START_1                         = -1000575,
    SAY_START_2                         = -1000576,
    SAY_END_1                           = -1000577,
    SAY_END_2                           = -1000578
};

struct MANGOS_DLL_DECL npc_lurgglbrAI : public npc_escortAI
{
    npc_lurgglbrAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        m_uiSayTimer = 0;
        m_uiSpeech = 0;
        Reset();
    }

    uint32 m_uiSayTimer;
    uint8 m_uiSpeech;

    void Reset()
    {
        if (!HasEscortState(STATE_ESCORT_ESCORTING))
        {
            m_uiSayTimer = 0;
            m_uiSpeech = 0;
        }
    }

    void JustStartedEscort()
    {
        if (GameObject* pCage = GetClosestGameObjectWithEntry(m_creature, GO_CAGE, INTERACTION_DISTANCE))
        {
            if (pCage->GetGoState() == GO_STATE_READY)
                pCage->Use(m_creature);
        }
    }

    void WaypointStart(uint32 uiPointId)
    {
        switch(uiPointId)
        {
            case 1:
                if (Player* pPlayer = GetPlayerForEscort())
                    DoScriptText(SAY_START_2, m_creature, pPlayer);

                // Cage actually closes here, however it's normally determined by GO template and auto close time

                break;
        }
    }

    void WaypointReached(uint32 uiPointId)
    {
        switch(uiPointId)
        {
            case 0:
                if (Player* pPlayer = GetPlayerForEscort())
                {
                    m_creature->SetFacingToObject(pPlayer);
                    DoScriptText(SAY_START_1, m_creature, pPlayer);
                }
                break;
            case 25:
                if (Player* pPlayer = GetPlayerForEscort())
                {
                    DoScriptText(SAY_END_1, m_creature, pPlayer);
                    m_uiSayTimer = 3000;
                }
                break;
        }
    }

    void UpdateEscortAI(const uint32 uiDiff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
        {
            if (m_uiSayTimer)
            {
                if (m_uiSayTimer <= uiDiff)
                {
                    Player* pPlayer = GetPlayerForEscort();

                    if (!pPlayer)
                    {
                        m_uiSayTimer = 0;
                        return;
                    }

                    m_creature->SetFacingToObject(pPlayer);

                    switch(m_uiSpeech)
                    {
                        case 0:
                            DoScriptText(SAY_END_2, m_creature, pPlayer);
                            m_uiSayTimer = 3000;
                            break;
                        case 1:
                            pPlayer->GroupEventHappens(QUEST_ESCAPE_FROM_WINTERFIN_CAVERNS, m_creature);
                            m_uiSayTimer = 0;
                            break;
                    }

                    ++m_uiSpeech;
                }
                else
                    m_uiSayTimer -= uiDiff;
            }

            return;
        }

        DoMeleeAttackIfReady();
    }
};

bool QuestAccept_npc_lurgglbr(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_ESCAPE_FROM_WINTERFIN_CAVERNS)
    {
        if (npc_lurgglbrAI* pEscortAI = dynamic_cast<npc_lurgglbrAI*>(pCreature->AI()))
        {
            pCreature->setFaction(FACTION_ESCORT_N_NEUTRAL_PASSIVE);
            pEscortAI->Start(false, pPlayer->GetGUID(), pQuest);
        }
    }
    return true;
}

CreatureAI* GetAI_npc_lurgglbr(Creature* pCreature)
{
    return new npc_lurgglbrAI(pCreature);
}
/*######
## mob_elder
######*/
enum
{
    SPELL_ANCESTOR_RITUAL               = 45536,
    SPELL_GREEN_BEAM                    = 39165,

    NPC_ELDER_KESUK                     = 25397,
    NPC_ELDER_SAGANI                    = 25398,
    NPC_ELDER_TAKRET                    = 25399,
    
    GO_ELDER_KESUK                      = 191088,
    GO_ELDER_SAGANI                     = 191089,
    GO_ELDER_TAKRET                     = 191090,

    POINT_ID                            = 1
};

struct MANGOS_DLL_DECL mob_elderAI : public ScriptedAI
{
    mob_elderAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    bool bEventInProgress;
    uint64 uiPlayerGUID;
    uint32 m_uiResetTimer;

    void Reset()
    {
        uiPlayerGUID = 0;
        m_uiResetTimer = 10000;

        m_creature->InterruptSpell(CURRENT_CHANNELED_SPELL,false);
        m_creature->RemoveAllAuras();
        m_creature->SetDisplayId(m_creature->GetNativeDisplayId());
        m_creature->GetMotionMaster()->MoveTargetedHome();

        bEventInProgress = false;
    }

    void SpellHit(Unit* pCaster, SpellEntry const* pSpell)
    {
        if (!pCaster || bEventInProgress)
            return;

        if (pCaster->GetTypeId() == TYPEID_PLAYER && pSpell->Id == SPELL_ANCESTOR_RITUAL)
        {
            bEventInProgress = true;
            uiPlayerGUID = pCaster->GetGUID();
            m_creature->GetMotionMaster()->MoveIdle();
            m_creature->StopMoving();

            uint32 go_entry;
            switch (m_creature->GetEntry())
            {
                case NPC_ELDER_SAGANI:  go_entry = GO_ELDER_SAGANI; break;
                case NPC_ELDER_KESUK:   go_entry = GO_ELDER_KESUK; break;
                case NPC_ELDER_TAKRET:  go_entry = GO_ELDER_TAKRET; break;
                default: break;
            }
            
            float x,y,z;
            if (GameObject* pGo = GetClosestGameObjectWithEntry(pCaster, go_entry, DEFAULT_VISIBILITY_DISTANCE))
                pGo->GetNearPoint(pGo,x,y,z,2.0f,2.0f,pGo->GetOrientation());
            else 
            {
                error_log("SD2: mob_elder (%s entry %u) couldn't find gameobject entry %u. Please check your database",m_creature->GetName(),m_creature->GetEntry(),go_entry);
                Reset();
            }

            m_creature->GetMotionMaster()->MovePoint(POINT_ID,x,y,z);
        }
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE)
            return;

        Player* pPlayer = m_creature->GetMap()->GetPlayer(uiPlayerGUID);

        if (!pPlayer)
            return;

        if (id == POINT_ID)
        {
            DoCast(m_creature,SPELL_GREEN_BEAM,false);
            // Because spell focus is m_creature not static gameobject or something we have to check if player actualy is near m_creature
            if (pPlayer->GetDistance(m_creature) < 5.0f)
                pPlayer->KilledMonsterCredit(m_creature->GetEntry(),m_creature->GetGUID()); 
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (m_creature->HasAura(SPELL_GREEN_BEAM))
        {
            if (m_uiResetTimer <= uiDiff)
                Reset();
            else m_uiResetTimer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_mob_elder(Creature* pCreature)
{
    return new mob_elderAI(pCreature);
}

// Oh Noes, the Tadpoles! 
// HACKED!
enum Tadpole_Cage
{
    MOB_WINTERFIN_TADPOLE       = 25201,
    GO_TADPOLE_CAGE             = 187373,
    QUEST_OH_NOES_THE_TADPOLES  = 11560
};

int32 Speaches[7] =
{ 
    -1999806,-1999805,-1999804,           // negative
    -1999810,-1999809,-1999808,-1999807   // positive
};

struct MANGOS_DLL_DECL mob_tadpoleAI : public ScriptedAI
{
    mob_tadpoleAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    bool bIsFollowing;
    bool bIsResetingCage;
    uint32 Timer;

    void Reset() 
    {
        if (GameObject* pGo = GetClosestGameObjectWithEntry(m_creature,GO_TADPOLE_CAGE,2.0f))
        {
            pGo->SetGoState(GO_STATE_READY);
            pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
        }

        bIsFollowing = false;
        bIsResetingCage = false;
        Timer = urand(15000, 30000);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (bIsFollowing || bIsResetingCage)
            if (Timer <= uiDiff)
            {
                if (bIsFollowing)
                {
                    DoScriptText(Speaches[urand(5, 6)],m_creature);
                    Timer = urand(28000,59000);
                }
                // if player is not eligeble for tadpole to follow lets reset him and his cage
                else if (bIsResetingCage)    
                    Reset();
            }else Timer -= uiDiff;
   }
};

CreatureAI* GetAI_mob_tadpole(Creature* pCreature)
{
    return new mob_tadpoleAI(pCreature);
}

bool GOUse_go_tadpole_cage(Player* pPlayer, GameObject* pGo)
{
    if (!pPlayer)
        return false;


    std::list<Creature*> lCreatureList;
    GetCreatureListWithEntryInGrid(lCreatureList, pGo, MOB_WINTERFIN_TADPOLE, 2.0f);

    if (!lCreatureList.empty())
    {
        for (std::list<Creature*>::iterator itr = lCreatureList.begin(); itr != lCreatureList.end(); ++itr)
        {
            if ((*itr) && (*itr)->isAlive())
            {
                if (pPlayer->GetQuestStatus(QUEST_OH_NOES_THE_TADPOLES) != QUEST_STATUS_INCOMPLETE)
                {
                    //choose one of negative speaches
                    DoScriptText(Speaches[urand(0, 2)],(*itr),pPlayer);
                    ((mob_tadpoleAI*)(*itr)->AI())->bIsResetingCage = true;
                    continue;
                }

                else if (Creature* pNewTadpole = (*itr)->SummonCreature(MOB_WINTERFIN_TADPOLE,(*itr)->GetPositionX(),(*itr)->GetPositionY(),(*itr)->GetPositionZ(),(*itr)->GetOrientation(),TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN,urand(60000,120000)))
                {
                    pNewTadpole->GetMotionMaster()->MoveFollow(pPlayer, float(urand(1, 4)), 2*M_PI/float(urand(1, 20)));
                    pPlayer->KilledMonsterCredit((*itr)->GetEntry(),(*itr)->GetGUID());
                    (*itr)->ForcedDespawn();
                    if (pPlayer->getGender() == GENDER_MALE)
                        DoScriptText(Speaches[3],pNewTadpole,pPlayer);
                    else DoScriptText(Speaches[4],pNewTadpole,pPlayer);
                    ((mob_tadpoleAI*)pNewTadpole->AI())->bIsFollowing = true;
                }
            }
        }
    }

    lCreatureList.clear();
    // just open the door without despawn
    pGo->SetGoState(GO_STATE_ACTIVE);
    // and make cage not targetable
    pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
    return true;
}

enum PrisonBreak
{
    QUEST_PRISON_BREAK          = 11587,
    SPELL_HEARTSTONE_VISUAL     = 45451,
    SPELL_PRISON_BREAK_CREDIT   = 45456,

    SAY_SUCCEDED                = -1999803,
    SAY_FAILED                  = -1999802
};

struct MANGOS_DLL_DECL mob_arcane_prisonerAI : public ScriptedAI
{
    mob_arcane_prisonerAI(Creature* pCreature) : ScriptedAI(pCreature){Reset();}
    
    bool bEventDone;
    uint32 m_uiEventTimer;

    void Reset() 
    {
        // small amount of time is needed to let npc fall on the ground
        m_uiEventTimer = 1000;
        bEventDone = false;
    }

    void UpdateAI (const uint32 uiDiff)
    {
        if (!bEventDone && m_uiEventTimer <= uiDiff)
        {
            bEventDone = true;
            // update server with position of NPC after it fall on the ground
            // this will prevent to spawn eventual corpse in the air (cosmetic effect)
            float x,y,z;
            m_creature->GetPosition(x, y, z);
            z = m_creature->GetMap()->GetTerrain()->GetHeight(x, y, MAX_HEIGHT, false);
            m_creature->Relocate(x, y, z+2);

            if (urand(0, 2) < 2)
            {
                DoScriptText(SAY_FAILED, m_creature, NULL);
                m_creature->DealDamage(m_creature, m_creature->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, NULL, false);
            }
            else
            {
                if (Player* pPlayer = m_creature->GetMap()->GetPlayer(m_creature->GetCreatorGuid()))
                {
                    DoScriptText(SAY_SUCCEDED, m_creature, pPlayer);
                    if (pPlayer->GetQuestStatus(QUEST_PRISON_BREAK) == QUEST_STATUS_INCOMPLETE)
                        DoCastSpellIfCan(pPlayer, SPELL_PRISON_BREAK_CREDIT, CAST_TRIGGERED);
                }
                DoCastSpellIfCan(m_creature, SPELL_HEARTSTONE_VISUAL);
            }
        }
        else
            m_uiEventTimer -= uiDiff;
    }
};

CreatureAI* GetAI_mob_arcane_prisoner(Creature* pCreature)
{
    return new mob_arcane_prisonerAI(pCreature);
}

/*#####
## go_mammoth_trap
#####*/

enum
{
    QUEST_HELP_THOSE_THAT    =  11876,
    NPC_TRAPPED_MAMMOTH      =  25850,
    SPELL_DESPAWN_SELF       =  43014
};

bool GOUse_go_mammoth_trap(Player* pPlayer, GameObject* pGo)
{
    if (pPlayer->GetQuestStatus(QUEST_HELP_THOSE_THAT) == QUEST_STATUS_INCOMPLETE)
    {
        Creature *pCreature = GetClosestCreatureWithEntry(pGo, NPC_TRAPPED_MAMMOTH, INTERACTION_DISTANCE);
        if(pCreature)
        {
            pPlayer->KilledMonsterCredit(NPC_TRAPPED_MAMMOTH, pCreature->GetGUID());
            pCreature->CastSpell(pCreature, SPELL_DESPAWN_SELF, false);
        }
    }
    return false;
};

/*######
## npc_beryl_sorcerer
######*/

enum eBerylSorcerer
{
    NPC_CAPTURED_BERLY_SORCERER         = 25474,
    NPC_LIBRARIAN_DONATHAN              = 25262,

    SPELL_ARCANE_CHAINS                 = 45611,
    SPELL_COSMETIC_CHAINS               = 54324,
    SPELL_COSMETIC_ENSLAVE_CHAINS_SELF  = 45631
};

struct MANGOS_DLL_DECL npc_beryl_sorcererAI : public FollowerAI
{
    npc_beryl_sorcererAI(Creature* pCreature) : FollowerAI(pCreature) { 
        Reset(); 
    }

    bool bEnslaved;
    uint64 uiChainerGUID;

    void Reset()
    {
         m_creature->setFaction(14);
         bEnslaved = false;
    }
    void EnterCombat(Unit* pWho)
    {
            AttackStart(pWho);
    }
    
    void SpellHit(Unit* pCaster, SpellEntry const* pSpell)
    {
        if (pSpell->Id == SPELL_ARCANE_CHAINS && pCaster->GetTypeId() == TYPEID_PLAYER && !bEnslaved)
            {
                EnterEvadeMode(); //We make sure that the npc is not attacking the player!
                m_creature->setFaction(35);
                uiChainerGUID = pCaster->GetGUID();
                if(Player *pChainer = m_creature->GetMap()->GetPlayer(uiChainerGUID))
                {
                StartFollow(pChainer, 35, NULL);
                m_creature->UpdateEntry(NPC_CAPTURED_BERLY_SORCERER);
                DoCast(m_creature, SPELL_COSMETIC_ENSLAVE_CHAINS_SELF, true);
               
                bEnslaved = true;
                }
            }
    }

    void MoveInLineOfSight(Unit* pWho)
    {
            FollowerAI::MoveInLineOfSight(pWho);

            if (pWho->GetEntry() == NPC_LIBRARIAN_DONATHAN && m_creature->IsWithinDistInMap(pWho, INTERACTION_DISTANCE))
            {
                if(Player *pChainer = m_creature->GetMap()->GetPlayer(uiChainerGUID))
                {
                    pChainer->KilledMonsterCredit(NPC_CAPTURED_BERLY_SORCERER,m_creature->GetGUID());
                    SetFollowComplete();
                    m_creature->ForcedDespawn(1000);
                }
            }
     }
    void UpdateAI(const uint32 uiDiff)
    {
        if (!m_creature->getVictim())
                return;

            DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_npc_beryl_sorcerer(Creature* pCreature)
{
    return new npc_beryl_sorcererAI(pCreature);
}

/*#####
## go_scourge_cage
#####*/

enum
{
    QUEST_MERCIFUL_FREEDOM      =  11676,
    NPC_SCOURGE_PRISONER        =  25610,
};

bool GOUse_go_scourge_cage(Player* pPlayer, GameObject* pGo)
{
    if (pPlayer->GetQuestStatus(QUEST_MERCIFUL_FREEDOM) == QUEST_STATUS_INCOMPLETE)
    {
        Creature *pCreature = GetClosestCreatureWithEntry(pGo, NPC_SCOURGE_PRISONER, INTERACTION_DISTANCE);
        if(pCreature)
        {
            pPlayer->KilledMonsterCredit(NPC_SCOURGE_PRISONER, pCreature->GetGUID());
            pCreature->CastSpell(pCreature, SPELL_DESPAWN_SELF, false);
        }
    }
    return false;
};

/*######
## npc_nexus_drake
######*/

enum
{
    SPELL_DRAKE_HARPOON             = 46607,
    SPELL_RED_DRAGONBLOOD           = 46620,
    SPELL_DRAKE_HATCHLING_SUBDUED   = 46691,
    SPELL_SUBDUED                   = 46675,

    NPC_RAELORASZ                   = 26117,
    DRAKE_HUNT_KILL_CREDIT          = 26175,

    QUEST_DRAKE_HUNT                = 11919,
    QUEST_DRAKE_HUNT_D              = 11940

};

struct MANGOS_DLL_DECL npc_nexus_drakeAI : public FollowerAI
{
    npc_nexus_drakeAI(Creature* pCreature) : FollowerAI(pCreature) { Reset(); }
    
     uint64 uiHarpoonerGUID;
     bool bWithRedDragonBlood;
     bool bIsFollowing;

     void Reset()
     {
         bWithRedDragonBlood = false;
         bIsFollowing = false;
     }

     void EnterCombat(Unit* pWho)
     {
         AttackStart(pWho);
     }
     
     void SpellHit(Unit* pCaster, SpellEntry const* pSpell)
     {
            if (pSpell->Id == SPELL_DRAKE_HARPOON && pCaster->GetTypeId() == TYPEID_PLAYER)
            {
                uiHarpoonerGUID = pCaster->GetGUID();
                DoCast(m_creature, SPELL_RED_DRAGONBLOOD, true);
            }
            m_creature->Attack(pCaster,true);
            bWithRedDragonBlood = true;
     }

     void MoveInLineOfSight(Unit *pWho)
     {
         FollowerAI::MoveInLineOfSight(pWho);


         if (pWho->GetEntry() == NPC_RAELORASZ && m_creature->IsWithinDistInMap(pWho, INTERACTION_DISTANCE))
         {
           if (Player *pHarpooner = m_creature->GetMap()->GetPlayer(uiHarpoonerGUID))
                 {
                    
                     pHarpooner->KilledMonsterCredit(DRAKE_HUNT_KILL_CREDIT,m_creature->GetGUID());
                     pHarpooner->RemoveAurasByCasterSpell(SPELL_DRAKE_HATCHLING_SUBDUED,uiHarpoonerGUID);
                     SetFollowComplete();
                     uiHarpoonerGUID = 0;
                     m_creature->ForcedDespawn(1000);
                 }
              
          }
      }
     
     void UpdateAI(const uint32 uidiff)
        {
            if (bWithRedDragonBlood && uiHarpoonerGUID && !m_creature->HasAura(SPELL_RED_DRAGONBLOOD))
            {
                if (Player *pHarpooner = m_creature->GetMap()->GetPlayer(uiHarpoonerGUID))
                {
                    EnterEvadeMode();
                    StartFollow(pHarpooner, 35, NULL);

                    DoCast(m_creature, SPELL_SUBDUED, true);
                    pHarpooner->CastSpell(pHarpooner, SPELL_DRAKE_HATCHLING_SUBDUED, true);

                    m_creature->AttackStop();
                    bIsFollowing = true;
                    bWithRedDragonBlood = false;
                }
            }
            if(bIsFollowing && !m_creature->HasAura(SPELL_SUBDUED))
            {
                m_creature->ForcedDespawn(1000);
            }

            if (!m_creature->getVictim())
                return;

            DoMeleeAttackIfReady();
        }
};

CreatureAI* GetAI_npc_nexus_drake(Creature* pCreature)
{
    return new npc_nexus_drakeAI(pCreature);
}

/**** Quest: Last Rites ****/
enum
{
    /************* Speech and Sounds ***********************/
    SAY_DIA01 = -1534071,
    SAY_DIA02 = -1534072,
    SAY_DIA03 = -1534073,
    SAY_DIA04 = -1534074,
    SAY_DIA05 = -1534075,
    SAY_DIA06 = -1534076,
    SAY_DIA07 = -1534077,
    SAY_DIA08 = -1534078,
    SAY_DIA09 = -1534079,
    SAY_DIA10 = -1534080,
    SAY_DIA11 = -1534081,
    SAY_DIA12 = -1534082,
    SAY_DIA13 = -1534083,
    SAY_DIA14 = -1534084,
    SAY_DIA15 = -1534085,
    SAY_DIA16 = -1534086,
    SAY_DIA17 = -1534087,
    SAY_DIA18 = -1534088,
    SAY_DIA19 = -1534089,
    SAY_DIA20 = -1534090,

    /************* Npc's ***********************/
    NPC_THASSARIAN = 26170,
    NPC_LICH_KING = 26203,
    NPC_LERYSSA = 25251,
    NPC_ARLOS = 25250,
    NPC_VALANAR = 28189,
    NPC_VISUAL_FORM = 25301,

    /************* Other's ***********************/
    QUEST_LAST_RITES = 12019,
    STAFF_ID = 485,
    AREA_ID = 4128,
};

#define GOSSIP_ITEM_T "Let's do this, Thassarian. It's now or never."

struct MANGOS_DLL_DECL npc_thassarianAI : public ScriptedAI
{
    npc_thassarianAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiStepTimer;
    uint32 m_uiStep;

    uint64 m_uiValanarGUID;
    uint64 m_uiLichKingGUID;
    uint64 m_uiLeryssaGUID;
    uint64 m_uiArlosGUID;

    void Reset()
    {
        m_uiValanarGUID = 0;
        m_uiLichKingGUID = 0;
        m_uiLeryssaGUID = 0;
        m_uiArlosGUID = 0;
        m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        if (m_creature->GetAreaId() == AREA_ID)
            m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        m_uiStep = 0;
        m_uiStepTimer = 100;
    }

    void JustDied(Unit* pKiller)
    {
        if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
Kill(Leryssa);
        if (Unit* Arlos = m_creature->GetMap()->GetCreature(m_uiArlosGUID))
            Kill(Arlos);
        if (Unit* Valanar = m_creature->GetMap()->GetCreature(m_uiValanarGUID))
            Valanar->RemoveFromWorld();
    }

    void EnterEvadeMode()
    {
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        m_creature->CombatStop(true);

        m_creature->SetLootRecipient(NULL);

        if (m_creature->isAlive() && m_uiStep > 20)
        {
            m_creature->GetMotionMaster()->MoveTargetedHome();
            Reset();
        }
    }

    void StartEvent(uint8 EventId)
    {
        m_uiStep = EventId;
        m_uiStepTimer = 100;
    }

    void JumpNextStep(uint32 Time)
    {
        m_uiStepTimer = Time;
        m_uiStep++;
    }

    void Kill(Unit* Oo)
    {
        Oo->DealDamage(Oo, Oo->GetMaxHealth() ,NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
    }

    void Event()
    {
        switch(m_uiStep)
        {
            case 1:
               m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
               m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
               m_creature->AddSplineFlag(SPLINEFLAG_WALKMODE);
               m_creature->GetMotionMaster()->MovePoint(0, 3712.466f, 3570.2911f, 477.443f);
               JumpNextStep(4000);
               break;
            case 2:
               m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
               if (Creature* LichKing = m_creature->SummonCreature(NPC_LICH_KING,3730.15f,3519.43f,473.32f,1.37f,TEMPSUMMON_CORPSE_TIMED_DESPAWN,30))
               {
                   m_uiLichKingGUID = LichKing->GetGUID();
                   LichKing->GetMotionMaster()->MovePoint(0, 3738.691f, 3564.734f, 477.442f);
               }
               JumpNextStep(3000);
               break;
            case 3:
               if (Creature* Valanar = m_creature->SummonCreature(NPC_VALANAR,3748.80f,3615.27f,473.3232f,4.50f,TEMPSUMMON_CORPSE_TIMED_DESPAWN,60000))
               {
                   m_uiValanarGUID = Valanar->GetGUID();
                   Valanar->SetRespawnDelay(DAY);
                   Valanar->GetMotionMaster()->MovePoint(0, 3739.823f, 3570.564f, 477.442f);
                   ((Creature*)Valanar)->UpdateEntry(NPC_VISUAL_FORM, HORDE); //huck! Replace spell (spell "Valanar Transformation" don't work!) He must update Valanar Entry and Change Name!
                   Valanar->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                   Valanar->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                   Valanar->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(0));
               }
               JumpNextStep(20000);
               break;
            case 4:
               if (Unit* Valanar = m_creature->GetMap()->GetCreature(m_uiValanarGUID))
               {
                   ((Creature*)Valanar)->UpdateEntry(NPC_VALANAR);
                   Valanar->SetStandState(UNIT_STAND_STATE_KNEEL);
                   ((Creature*)Valanar)->LoadEquipment(STAFF_ID);
                   DoScriptText(SAY_DIA01, Valanar);
               }
               if (Creature* Leryssa = m_creature->SummonCreature(NPC_LERYSSA,3753.105f,3614.296f,473.32f,1.37f,TEMPSUMMON_CORPSE_TIMED_DESPAWN,10))
               {
                   m_uiLeryssaGUID = Leryssa->GetGUID();
                   Leryssa->GetMotionMaster()->MovePoint(0, 3745.636f, 3572.464f, 477.442f);
                   Leryssa->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                   Leryssa->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
               }
               if (Creature* Arlos = m_creature->SummonCreature(NPC_ARLOS,3744.82f,3616.11f,473.32f,1.37f,TEMPSUMMON_CORPSE_TIMED_DESPAWN,10))
               {
                   m_uiArlosGUID = Arlos->GetGUID();
                   Arlos->GetMotionMaster()->MovePoint(0, 3734.854f, 3573.028f, 477.442f);
                   Arlos->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                   Arlos->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
               }
               JumpNextStep(8000);
               break;
            case 5:
               if (Unit* Valanar = m_creature->GetMap()->GetCreature(m_uiValanarGUID))
DoScriptText(SAY_DIA02, Valanar);
               JumpNextStep(11000);
               break;
            case 6:
               if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
                   Leryssa->CastSpell(Leryssa,45066,false);
               if (Unit* Arlos = m_creature->GetMap()->GetCreature(m_uiArlosGUID))
                   Arlos->CastSpell(Arlos,45066,false);
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
                   DoScriptText(SAY_DIA03, LichKing);
               JumpNextStep(9000);
               break;
            case 7:
               m_creature->RemoveSplineFlag(SPLINEFLAG_WALKMODE);
               m_creature->GetMotionMaster()->MovePoint(0, 3722.271f, 3566.878f, 477.442f);
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
                   m_creature->SetFacingToObject(LichKing);
               DoScriptText(SAY_DIA04, m_creature);
               JumpNextStep(2000);
               break;
            case 8:
               if (Unit* Valanar = m_creature->GetMap()->GetCreature(m_uiValanarGUID))
                   Valanar->SetStandState(UNIT_STAND_STATE_STAND);
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
                   LichKing->SetFacingToObject(m_creature);
               DoScriptText(SAY_DIA05, m_creature);
               JumpNextStep(6000);
               break;
            case 9:
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
                   DoScriptText(SAY_DIA06, LichKing);
               JumpNextStep(17000);
               break;
            case 10:
               DoScriptText(SAY_DIA07, m_creature);
               JumpNextStep(9000);
               break;
            case 11:
               if (Unit* Valanar = m_creature->GetMap()->GetCreature(m_uiValanarGUID))
                   DoScriptText(SAY_DIA08, Valanar);
               JumpNextStep(6000);
               break;
            case 12:
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
               {
                   if(Unit* Valanar = m_creature->GetMap()->GetCreature(m_uiValanarGUID))
                   {
                       LichKing->SetFacingToObject(Valanar);
DoScriptText(SAY_DIA09, LichKing);
                   }
               }
               JumpNextStep(4000);
               break;
            case 13:
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
                   LichKing->SetFacingToObject(m_creature);
               JumpNextStep(500);
               break;
            case 14:
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
                   LichKing->HandleEmoteCommand(25);
               JumpNextStep(5500);
               break;
            case 15:
               if (Unit* Valanar = m_creature->GetMap()->GetCreature(m_uiValanarGUID))
               {
                   DoScriptText(SAY_DIA10, Valanar);
                   Valanar->SetFacingToObject(m_creature);
                   Valanar->setFaction(14);
                   m_creature->AI()->AttackStart(Valanar);
               }
               if (Unit* LichKing = m_creature->GetMap()->GetCreature(m_uiLichKingGUID))
Kill(LichKing);
               JumpNextStep(500);
               break;
case 17:
               EnterEvadeMode();
               m_creature->GetMotionMaster()->MovePoint(0, 3721.361f, 3566.910f, 477.442f);
               m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, UNIT_STAND_STATE_STAND);
               if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
               {
                   DoScriptText(SAY_DIA14, Leryssa);
                   Leryssa->RemoveAurasDueToSpell(45066);
               }
               if (Unit* Arlos = m_creature->GetMap()->GetCreature(m_uiArlosGUID))
                   DoScriptText(SAY_DIA11, Arlos);
               JumpNextStep(3000);
               break;
            case 18:
               if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
               {
                   ((Creature*)Leryssa)->RemoveSplineFlag(SPLINEFLAG_WALKMODE);
                   Leryssa->GetMotionMaster()->MovePoint(0, 3726.749f, 3568.097f, 477.442f);
                   Leryssa->SetFacingToObject(m_creature);
                   Leryssa->SetStandState(UNIT_STAND_STATE_SIT);
                   m_creature->SetFacingToObject(Leryssa);
                   m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);
               }
               if (Unit* Arlos = m_creature->GetMap()->GetCreature(m_uiArlosGUID))
               {
                   DoScriptText(SAY_DIA12, Arlos);
                   Arlos->RemoveAurasDueToSpell(45066);
                   Arlos->SetStandState(UNIT_STAND_STATE_DEAD);
               }
               JumpNextStep(5000);
               break;
            case 19:
               if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
                   DoScriptText(SAY_DIA15, Leryssa);
               JumpNextStep(5000);
               break;
            case 20:
               DoScriptText(SAY_DIA13, m_creature);
               JumpNextStep(3000);
               break;
            case 21:
               DoScriptText(SAY_DIA16, m_creature);
               JumpNextStep(6000);
               break;
            case 22:
               if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
                   DoScriptText(SAY_DIA17, Leryssa);
               JumpNextStep(9000);
               break;
            case 23:
               DoScriptText(SAY_DIA18, m_creature);
               JumpNextStep(9000);
               break;
            case 24:
               if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
                   DoScriptText(SAY_DIA19, Leryssa);
               JumpNextStep(8000);
               break;
            case 25:
               DoScriptText(SAY_DIA20, m_creature);
               JumpNextStep(6000);
               break;
            case 26:
               m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
               JumpNextStep(60000);
               break;
            case 27:
               if (Unit* Leryssa = m_creature->GetMap()->GetCreature(m_uiLeryssaGUID))
Kill(Leryssa);
               if (Unit* Arlos = m_creature->GetMap()->GetCreature(m_uiArlosGUID))
                   Kill(Arlos);
               JumpNextStep(6000);
               EnterEvadeMode();
               m_creature->SetStandState(UNIT_STAND_STATE_STAND);
               break;
         }
    }

    void UpdateAI(const uint32 uiDiff)
    {
         if (m_uiStepTimer <= uiDiff)
             Event();
         else
             m_uiStepTimer -= uiDiff;

         if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

         DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_thassarian(Creature* pCreature)
{
    return new npc_thassarianAI(pCreature);
}

/*Prince Valanar AI*/

enum
{
   SPELL_SHADOW_BOLT = 15537,
   SPELL_SOUL_BLAST = 50992,
   SPELL_SOUL_MIRROR = 51009
};

struct MANGOS_DLL_DECL npc_valanarAI : public ScriptedAI
{
    npc_valanarAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        Reset();
        SetCombatMovement(false);
    }

    uint32 m_uiShadowBoltTimer;
    uint32 m_uiShadowBlastTimer;
    uint32 m_uiSoulTimer;

    void Reset()
    {
        m_uiShadowBoltTimer = 1300;
        m_uiShadowBlastTimer = 7300;
        m_uiSoulTimer = 17300;
    }
 
    void JustDied(Unit* pKiller)
    {
        if (Creature* pTas = GetClosestCreatureWithEntry(m_creature, NPC_THASSARIAN, 80.0f))
           ((npc_thassarianAI*)pTas->AI())->StartEvent(17);
    }

    void SpellHitTarget(Unit *target, const SpellEntry *spell)
    {
        if (spell->Id == SPELL_SOUL_BLAST)
           m_creature->DealDamage(target, target->GetMaxHealth() / 5,NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if (done_by->HasAura(SPELL_SOUL_MIRROR))
           m_creature->DealDamage(done_by, damage ,NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        if (m_uiShadowBoltTimer < diff)
        {
            if(Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 0))
               DoCast(pTarget, SPELL_SHADOW_BOLT);
m_uiShadowBoltTimer = 3300;
        }
        else
            m_uiShadowBoltTimer -= diff;

        if (m_uiShadowBlastTimer < diff)
        {
           m_creature->InterruptNonMeleeSpells(false);
           if(Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 0))
              DoCast(pTarget,SPELL_SOUL_BLAST);
m_uiShadowBlastTimer = urand(6000, 12000);
        }
        else
            m_uiShadowBlastTimer -= diff;

        if (m_uiSoulTimer < diff)
        {
            m_creature->InterruptNonMeleeSpells(false);
            DoCast(m_creature->getVictim(),SPELL_SOUL_MIRROR);
            m_uiSoulTimer = urand(15000, 20000);
        }
        else
            m_uiSoulTimer -= diff;
    }
};

bool GossipHello_npc_thassarian(Player *player, Creature *pCreature)
{
    if (pCreature->isQuestGiver())
        player->PrepareQuestMenu(pCreature->GetGUID());

    if (player->GetQuestStatus(QUEST_LAST_RITES) == QUEST_STATUS_INCOMPLETE)
        if(((npc_thassarianAI*)pCreature->AI())->m_uiStep == 0 && pCreature->GetAreaId() == AREA_ID)
            player->ADD_GOSSIP_ITEM(0, GOSSIP_ITEM_T, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->PlayerTalkClass->SendGossipMenu(player->GetGossipTextId(pCreature),pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_thassarian(Player *player, Creature *pCreature, uint32 sender, uint32 action )
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
          ((npc_thassarianAI*)pCreature->AI())->StartEvent(1);
          player->CLOSE_GOSSIP_MENU();
    }
    return true;
}

CreatureAI* GetAI_npc_valanar(Creature* pCreature)
{
    return new npc_valanarAI(pCreature);
}

/*######
## npc_mootoo_the_younger
######*/
enum Mootoo_the_Younger_Texts
{
    SAY_1                    = -1750040,
    SAY_2                    = -1750041,
    SAY_3                    = -1750042,
    SAY_4                    = -1750043,
    SAY_5                    = -1750044
};
enum Mootoo_the_Younger
{
    NPC_MOOTOO_THE_YOUNGER          =25504,
    QUEST_ESCAPING_THE_MIST         =11664
};


struct MANGOS_DLL_DECL npc_mootoo_the_youngerAI : public npc_escortAI
{
        npc_mootoo_the_youngerAI(Creature *pCreature) : npc_escortAI(pCreature) {}

        void Reset(){}

        void JustDied(Unit* /*killer*/)
        {
            if (Player* pPlayer=GetPlayerForEscort())
                pPlayer->FailQuest(QUEST_ESCAPING_THE_MIST);
        }

        void WaypointReached(uint32 uiPointId)
        {
            Player* pPlayer = GetPlayerForEscort();

            if (!pPlayer)
                return;

            switch(uiPointId)
            {
            case 10:
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                DoScriptText(SAY_2, m_creature);
                break;
            case 12:
                DoScriptText(SAY_3, m_creature);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LOOT);
                break;
            case 16:
                DoScriptText(SAY_4, m_creature);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                break;
            case 20:
                m_creature->SetPhaseMask(1,true);
                DoScriptText(SAY_5, m_creature);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                if (pPlayer)
                    pPlayer->GroupEventHappens(QUEST_ESCAPING_THE_MIST, m_creature);
                SetRun(true);
                break;
            }
        }
};

bool QuestAccept_npc_mootoo_the_younger(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_ESCAPING_THE_MIST)
    {
        pCreature->SetStandState(UNIT_STAND_STATE_STAND);
        pCreature->setFaction((pPlayer->GetTeam() == ALLIANCE) ? FACTION_ESCORT_A_PASSIVE : FACTION_ESCORT_H_PASSIVE);
        DoScriptText(SAY_1, pCreature);

		if (npc_mootoo_the_youngerAI* pEscortAI = dynamic_cast<npc_mootoo_the_youngerAI*>(pCreature->AI()))
            	pEscortAI->Start(false, pPlayer->GetGUID(), pQuest, true);

    }
    return true;
}

CreatureAI* GetAI_npc_mootoo_the_younger(Creature* pCreature)
{
    return new npc_mootoo_the_youngerAI(pCreature);
}

/*######
## npc_bonker_togglevolt
######*/

enum Bonker_Togglevolt
{
    NPC_BONKER_TOGGLEVOLT           = 25589,
    QUEST_GET_ME_OUTA_HERE          = 11673
};
enum Bonker_Togglevolt_Texts
{
	SAY_bonker_1					= -1700001,
    SAY_bonker_2                   	= -1700002,
    SAY_bonker_3                    = -1700003
	
};

struct MANGOS_DLL_DECL npc_bonker_togglevoltAI : public npc_escortAI
    {
        npc_bonker_togglevoltAI(Creature *pCreature) : npc_escortAI(pCreature) {}
        
        void Reset(){}

        void JustDied(Unit* /*killer*/)
        {
            if (Player* pPlayer = GetPlayerForEscort())
                pPlayer->FailQuest(QUEST_ESCAPING_THE_MIST);
        }

        void WaypointReached(uint32 uiPointId)
        {
            Player* pPlayer = GetPlayerForEscort();

            if (!pPlayer)
                return;

            switch(uiPointId)
            {
			case 1:
				DoScriptText(SAY_bonker_1,m_creature);
				break;
			case 3:
				DoScriptText(SAY_bonker_2,m_creature);
				break;
            case 29:
				DoScriptText(SAY_bonker_3,m_creature);
                if (pPlayer)
                    pPlayer->GroupEventHappens(QUEST_GET_ME_OUTA_HERE, m_creature);
                break;
            }
        }
    };

    

bool QuestAccept_npc_bonker_togglevolt(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_GET_ME_OUTA_HERE)
        {
            pCreature->SetStandState(UNIT_STAND_STATE_STAND);
	        pCreature->setFaction((pPlayer->GetTeam() == ALLIANCE) ? FACTION_ESCORT_A_PASSIVE : FACTION_ESCORT_H_PASSIVE);            
	        DoScriptText(SAY_bonker_2, pCreature, pPlayer);
            
			if (npc_bonker_togglevoltAI* pEscortAI = dynamic_cast<npc_bonker_togglevoltAI*>(pCreature->AI()))
            		pEscortAI->Start(false, pPlayer->GetGUID(), pQuest, true);
        }
        return true;
    }

CreatureAI* GetAI_npc_bonker_togglevolt(Creature* pCreature)
{
    return new npc_bonker_togglevoltAI(pCreature);
}

void AddSC_borean_tundra()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_fizzcrank_fullthrottle";
    newscript->pGossipHello = &GossipHello_npc_fizzcrank_fullthrottle;
    newscript->pGossipSelect = &GossipSelect_npc_fizzcrank_fullthrottle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_iruk";
    newscript->pGossipHello = &GossipHello_npc_iruk;
    newscript->pGossipSelect = &GossipSelect_npc_iruk;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_kara_thricestar";
    newscript->pGossipHello = &GossipHello_npc_kara_thricestar;
    newscript->pGossipSelect = &GossipSelect_npc_kara_thricestar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_nesingwary_trapper";
    newscript->GetAI = &GetAI_npc_nesingwary_trapper;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_caribou_trap";
    newscript->pGOUse = &GOUse_go_caribou_trap;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_surristrasz";
    newscript->pGossipHello = &GossipHello_npc_surristrasz;
    newscript->pGossipSelect = &GossipSelect_npc_surristrasz;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_tiare";
    newscript->pGossipHello = &GossipHello_npc_tiare;
    newscript->pGossipSelect = &GossipSelect_npc_tiare;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_lurgglbr";
    newscript->GetAI = &GetAI_npc_lurgglbr;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_lurgglbr;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_elder";
    newscript->GetAI = &GetAI_mob_elder;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_arcane_prisoner";
    newscript->GetAI = &GetAI_mob_arcane_prisoner;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_tadpole_cage";
    newscript->pGOUse = &GOUse_go_tadpole_cage;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_tadpole";
    newscript->GetAI = &GetAI_mob_tadpole;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_mammoth_trap";
    newscript->pGOUse = &GOUse_go_mammoth_trap;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_beryl_sorcerer";
    newscript->GetAI = &GetAI_npc_beryl_sorcerer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_scourge_cage";
    newscript->pGOUse = &GOUse_go_scourge_cage;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_nexus_drake";
    newscript->GetAI = &GetAI_npc_nexus_drake;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name = "npc_valanar";
    newscript->GetAI = &GetAI_npc_valanar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_thassarian";
    newscript->GetAI = &GetAI_npc_thassarian;
    newscript->pGossipHello = &GossipHello_npc_thassarian;
    newscript->pGossipSelect = &GossipSelect_npc_thassarian;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_mootoo_the_younger";
    newscript->GetAI = &GetAI_npc_mootoo_the_younger;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_mootoo_the_younger;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_bonker_togglevolt";
    newscript->GetAI = &GetAI_npc_bonker_togglevolt;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_bonker_togglevolt;
    newscript->RegisterSelf();

}
