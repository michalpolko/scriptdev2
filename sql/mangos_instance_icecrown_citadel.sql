##########################
###  Icecrown Citadel  ###
### for world database ###
### developed for UDB  ###
##########################

-- instance template
UPDATE `instance_template` SET `ScriptName` = 'instance_icecrown_citadel' WHERE `map` = 631;


-- ---------
-- Marrowgar
-- ---------

UPDATE `creature_template` SET `ScriptName` = 'boss_lord_marrowgar', `AIName` = '' WHERE `entry` = 36612;
UPDATE `creature_template` SET `ScriptName` = 'mob_coldflame', `AIName` = '' WHERE `entry` = 36672;
UPDATE `creature_template` SET `ScriptName` = 'mob_bone_spike', `AIName` = '' WHERE `entry` = 38711;

-- -----------------
-- Lady Deathwhisper
-- -----------------

UPDATE `creature_template` SET `ScriptName` = 'boss_lady_deathwhisper', `AIName` = '' WHERE `entry` = 36855;
UPDATE `creature_template` SET `ScriptName` = 'mob_cult_adherent', `AIName` = '' WHERE `entry` = 37949;
UPDATE `creature_template` SET `ScriptName` = 'mob_cult_fanatic', `AIName` = '' WHERE `entry` = 37890;
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 256 WHERE `entry` IN (38296, 38297); -- can't taunt Lady on heroic mode

-- Vengeful Blast aura for shades
DELETE FROM `creature_template_addon` WHERE `entry` = 38222;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES (38222, "71494");

-- ---------------------
-- Deathbringer Saurfang
-- ---------------------

UPDATE `creature_template` SET `ScriptName`='boss_deathbringer_saurfang', `AIName` = '' WHERE `entry` = 37813;
UPDATE `creature_template` SET `ScriptName`='npc_highlord_saurfang_deathbringer_event_icc', `AIName` = '' WHERE `entry` = 37187;
UPDATE `creature_template` SET `ScriptName`='npc_muradin_deathbringer_event_icc', `AIName` = '' WHERE `entry` = 37200;
UPDATE `creature_template` SET `ScriptName`='npc_deathbringer_event_guards_iccAI', `AIName` = '' WHERE `entry` IN (37920, 37902);
UPDATE `creature_template` SET `ScriptName` = 'mob_blood_beast', `AIName`='' WHERE `entry`= 38508;

-- set power type for Saurfang when implemented
-- UPDATE `creature_template` SET `PowerType` = 3 WHERE `entry` IN (37813, 38402, 38582, 38583);

-- update faction for Deathbringer Saurfang
UPDATE `creature_template` SET `faction_A` = 974, `faction_H` = 974 WHERE `entry` IN (37813, 38402, 38582, 38583);

-- Mark of the Fallen Champion triggered heal
DELETE FROM `spell_script_target` WHERE `entry` IN (72260, 72202, 72278,72279,72280);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(72260, 1, 37813),
(72278, 1, 37813),
(72279, 1, 37813),
(72280, 1, 37813),
(72202, 1, 37813);

-- Mark of the Fallen Champion proc event
DELETE FROM `spell_proc_event` WHERE entry IN (72178, 72256);
INSERT INTO `spell_proc_event` VALUES
(72256, 0x7F,  0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0),
(72178, 0x7F,  0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000, 0);

-- Rune of Blood (Saurfang)
DELETE FROM `spell_proc_event` WHERE `entry` = 72408;
INSERT INTO `spell_proc_event` () VALUES
(72408, 0x00, 0x00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000, 0x00000000, 0x00000000, 0x00000014, 0x00000003, 0, 0, 0);

-- Blood Link (Saurfang, Blood Beast)
DELETE FROM `spell_proc_event` WHERE `entry` = 72176;
INSERT INTO `spell_proc_event` () VALUES
(72176, 0x00, 0x00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000, 0x00000000, 0x00000000, 0x00000014, 0x00000003, 0, 0, 0);

-- Scent of Blood
DELETE FROM `spell_script_target` WHERE `entry` = 72771;
INSERT INTO `spell_script_target` VALUES (72771, 1, 38508);

-- remove spawn of Muradin Bronzebeard
DELETE FROM `creature` WHERE `guid` = 118491;
-- and his Marines
DELETE FROM `creature` WHERE `guid` IN (120814, 120806, 120791, 120821);

------------------
-- Queen Lana'thel
------------------

UPDATE `creature_template` SET `ScriptName`='boss_blood_queen_lanathel', `AIName`='' WHERE `entry`= 37955;
UPDATE `creature_template` SET `AIName` ='', `ScriptName`='mob_swarming_shadows' WHERE `entry`= 38163;
