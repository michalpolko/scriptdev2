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
