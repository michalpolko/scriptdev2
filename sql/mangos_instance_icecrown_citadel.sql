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

UPDATE `creature_template` SET `ScriptName` = 'boss_lady_deathwhisper', `AIName` = '' WHERE `entry` = 36855;
UPDATE `creature_template` SET `ScriptName` = 'mob_cult_adherent', `AIName` = '' WHERE `entry` = 37949;
UPDATE `creature_template` SET `ScriptName` = 'mob_cult_fanatic', `AIName` = '' WHERE `entry` = 37890;
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 256 WHERE `entry` IN (38296, 38297); -- can't taunt Lady on heroic mode

-- Vengeful Blast aura for shades
DELETE FROM `creature_template_addon` WHERE `entry` = 38222;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES (38222, "71494");
