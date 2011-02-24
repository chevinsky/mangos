-- Instance Ulduar

-- teleporter
UPDATE gameobject_template SET ScriptName = "go_ulduar_teleporter" WHERE entry = 194569;

-- fragments of Val'Anyr
DELETE FROM creature_loot_template WHERE item = 45038;
INSERT INTO creature_loot_template VALUES
(33190, 45038, 6, 2, 1, 1, 0, 0, 0), -- Ignis 6%
(33724, 45038, 4, 2, 1, 1, 0, 0, 0), -- Razorscale %
(33885, 45038, 7, 3, 1, 1, 0, 0, 0), -- XT-002 normal %
(33692, 45038, 4, 3, 1, 1, 0, 0, 0), -- Runemaster %
(33694, 45038, 4, 2, 1, 1, 0, 0, 0), -- Stormcaller %
(33693, 45038, 7, 4, 1, 1, 0, 0, 0), --  Steelbreaker %
(34175, 45038, 6, 2, 1, 1, 0, 0, 0); -- Auriaya %

DELETE FROM gameobject_loot_template WHERE item = 45038;
INSERT INTO gameobject_loot_template VALUES
(26929, 45038, 10, 2, 1, 1, 0, 0, 0); -- Kologarn %

DELETE FROM reference_loot_template WHERE item = 45038;
INSERT INTO reference_loot_template VALUES
(33886, 45038, 14, 3, 1, 1, 18, 603, 38); -- XT-002 hard %

-- ****** Ignis the Furnace Master ******
UPDATE `creature_template` SET `ScriptName` = "boss_ignis" WHERE `entry` = 33118;
UPDATE `creature_template` SET lootid = entry, `mechanic_immune_mask` = 617299839 WHERE entry IN (33118, 33190);
UPDATE `creature_template` SET `ScriptName` = "mob_iron_construct" WHERE `entry` = 33121;
UPDATE `creature_template` SET `AIName` = "EventAI" WHERE `entry` = 33221;
DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 33221;
INSERT INTO `creature_ai_scripts` VALUES
(3322101, 33221, 0, 0, 100, 2, 3000, 3000, 0, 0, 11, 62548, 0, 0, 20, 0, 0, 0, 21, 0, 0, 0, "Scorch Trigger - Cast Scorch normal"),
(3322102, 33221, 0, 0, 100, 4, 3000, 3000, 0, 0, 11, 63476, 0, 0, 20, 0, 0, 0, 21, 0, 0, 0, "Scorch Trigger - Cast Scorch heroic"),
(3322103, 33221, 4, 0, 100, 6, 0, 0, 0, 0, 20, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, "Scorch Trigger - Disable Combat Movement on Aggro");
-- Ignis loot
DELETE FROM `creature_loot_template` WHERE `entry` IN (33118, 33190);
INSERT INTO `creature_loot_template` VALUES
-- 10 man
(33118, 40753, 100, 0, 1, 1, 0, 0, 0),
(33118, 1, 100, 1, -33119, 2, 0, 0, 0),
-- 25 man
(33190, 45624, 100, 0, 1, 1, 0, 0, 0),
(33190, 1, 100, 1, -33191, 4, 0, 0, 0);

DELETE FROM `reference_loot_template` WHERE `entry` IN (33119, 33191);
INSERT INTO `reference_loot_template` VALUES
-- Ignis10
(33119, 45316, 0, 1, 1, 1, 0, 0, 0),
(33119, 45318, 0, 1, 1, 1, 0, 0, 0),
(33119, 45313, 0, 1, 1, 1, 0, 0, 0),
(33119, 45310, 0, 1, 1, 1, 0, 0, 0),
(33119, 45312, 0, 1, 1, 1, 0, 0, 0),
(33119, 45314, 0, 1, 1, 1, 0, 0, 0),
(33119, 45321, 0, 1, 1, 1, 0, 0, 0),
(33119, 45311, 0, 1, 1, 1, 0, 0, 0),
(33119, 45309, 0, 1, 1, 1, 0, 0, 0),
(33119, 45317, 0, 1, 1, 1, 0, 0, 0),
-- Ignis25
(33191, 45166, 0, 1, 1, 1, 0, 0, 0),
(33191, 45157, 0, 1, 1, 1, 0, 0, 0),
(33191, 45162, 0, 1, 1, 1, 0, 0, 0),
(33191, 45185, 0, 1, 1, 1, 0, 0, 0),
(33191, 45161, 0, 1, 1, 1, 0, 0, 0),
(33191, 45158, 0, 1, 1, 1, 0, 0, 0),
(33191, 45164, 0, 1, 1, 1, 0, 0, 0),
(33191, 45171, 0, 1, 1, 1, 0, 0, 0),
(33191, 45167, 0, 1, 1, 1, 0, 0, 0),
(33191, 45168, 0, 1, 1, 1, 0, 0, 0),
(33191, 45170, 0, 1, 1, 1, 0, 0, 0),
(33191, 45186, 0, 1, 1, 1, 0, 0, 0),
(33191, 45169, 0, 1, 1, 1, 0, 0, 0),
(33191, 45165, 0, 1, 1, 1, 0, 0, 0),
(33191, 45187, 0, 1, 1, 1, 0, 0, 0);

-- ****** Razorscale ******
UPDATE creature_template SET `ScriptName`="boss_razorscale" WHERE entry=33186;
UPDATE creature_template SET mechanic_immune_mask=617299803, `lootid` = `entry`, `InhabitType` = 7 WHERE entry IN (33186, 33724);
-- original x=587.547, y= -174.927, z = 391.517; make the boss fly before encounter starts
update creature set position_x = 590.346741, position_y = -226.947647, position_z = 460.897583 where id = 33186;
UPDATE gameobject_template SET flags= 6553648, ScriptName="go_broken_harpoon" WHERE entry = 194565;
-- only 2 harpoons for 10 man
update gameobject set spawnMask = 2 where guid in (73595, 73592);
-- mole machines & adds
UPDATE creature_template SET ScriptName = "mob_mole_machine" WHERE entry = 33245;
UPDATE creature_template SET ScriptName = "mob_dark_rune_watcher" WHERE entry = 33453;
UPDATE creature_template SET ScriptName = "mob_dark_rune_sentinel" WHERE entry = 33846;
UPDATE creature_template SET ScriptName = "mob_dark_rune_guardian" WHERE entry = 33388;
UPDATE creature_template SET ScriptName = "npc_expedition_commander" WHERE entry = 33210;
UPDATE creature_template SET ScriptName = "mob_devouring_flame_target" WHERE entry in (34189, 34188);
UPDATE creature_template SET unit_flags = 0 WHERE `entry` = 33233;
UPDATE `creature_template`SET `unit_flags` = `unit_flags`&~33554432 WHERE entry = 33282;
-- expedition NPCs - don't enter the fight
UPDATE `creature_template` SET `unit_flags` = `unit_flags`|2|33554432, `flags_extra` = `flags_extra`|2 WHERE `entry` IN (33259, 33816, 33287);
-- harpoon script target
DELETE FROM `spell_script_target` WHERE `entry` = 62505;
INSERT INTO `spell_script_target` VALUES
(62505, 1, 33186);
-- loot
DELETE FROM `creature_loot_template` WHERE `entry` IN (33186, 33724);
INSERT INTO `creature_loot_template` VALUES
-- 10 man
(33186, 40753, 100, 0, 1, 1, 0, 0, 0),
(33186, 1, 100, 1, -33187, 2, 0, 0, 0),
-- 25 man
(33724, 45624, 100, 0, 1, 1, 0, 0, 0),
(33724, 1, 100, 1, -33725, 4, 0, 0, 0);

DELETE FROM `reference_loot_template` WHERE `entry` IN (33187, 33725);
INSERT INTO `reference_loot_template` VALUES
-- Razorscale10
(33187, 45303, 0, 1, 1, 1, 0, 0, 0),
(33187, 45306, 0, 1, 1, 1, 0, 0, 0),
(33187, 45301, 0, 1, 1, 1, 0, 0, 0),
(33187, 45305, 0, 1, 1, 1, 0, 0, 0),
(33187, 45299, 0, 1, 1, 1, 0, 0, 0),
(33187, 45308, 0, 1, 1, 1, 0, 0, 0),
(33187, 45307, 0, 1, 1, 1, 0, 0, 0),
(33187, 45298, 0, 1, 1, 1, 0, 0, 0),
(33187, 45304, 0, 1, 1, 1, 0, 0, 0),
(33187, 45302, 0, 1, 1, 1, 0, 0, 0),
-- Razorscale25
(33725, 45151, 0, 1, 1, 1, 0, 0, 0),
(33725, 45149, 0, 1, 1, 1, 0, 0, 0),
(33725, 45150, 0, 1, 1, 1, 0, 0, 0),
(33725, 45139, 0, 1, 1, 1, 0, 0, 0),
(33725, 45138, 0, 1, 1, 1, 0, 0, 0),
(33725, 45147, 0, 1, 1, 1, 0, 0, 0),
(33725, 45510, 0, 1, 1, 1, 0, 0, 0),
(33725, 45148, 0, 1, 1, 1, 0, 0, 0),
(33725, 45141, 0, 1, 1, 1, 0, 0, 0),
(33725, 45140, 0, 1, 1, 1, 0, 0, 0),
(33725, 45142, 0, 1, 1, 1, 0, 0, 0),
(33725, 45143, 0, 1, 1, 1, 0, 0, 0),
(33725, 45146, 0, 1, 1, 1, 0, 0, 0),
(33725, 45144, 0, 1, 1, 1, 0, 0, 0),
(33725, 45137, 0, 1, 1, 1, 0, 0, 0);

-- ****** XT-002 Deconstructor ******
UPDATE `creature_template` SET `ScriptName` = "boss_xt_002" WHERE `entry` = 33293;
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299839, `lootid` = `entry` WHERE entry IN (33293, 33885);
UPDATE `creature_template` SET `ScriptName` = "mob_xtheart" WHERE `entry` = 33329;
UPDATE `creature_template` SET `ScriptName` = "mob_pummeler" WHERE `entry` = 33344;
UPDATE `creature_template` SET `ScriptName` = "mob_boombot" WHERE `entry` = 33346;
UPDATE `creature_template` SET `ScriptName` = "mob_voidzone" WHERE `entry` = 34001;
UPDATE `creature_template` SET `ScriptName` = "mob_lifespark" WHERE `entry` = 34004;
UPDATE `creature_template` SET `ScriptName` = "mob_scrap_bot" WHERE `entry` = 33343;

-- adjust the damage of Life Sparks
UPDATE `creature_template` SET mindmg = 478, maxdmg = 530, dmg_multiplier = 22 WHERE entry = 34004;
UPDATE `creature_template` SET mindmg = 478, maxdmg = 530, dmg_multiplier = 30 WHERE entry = 34005;

-- loot
DELETE FROM `creature_loot_template` WHERE `entry` IN (33293, 33885);
INSERT INTO `creature_loot_template` VALUES
-- 10 man normal
(33293, 40753, 100, 0, 1, 1, 0, 0, 0),
(33293, 1, 100, 1, -33294, 2, 0, 0, 0),
-- 10 man hard mode
(33293, 45868, 0, 2, 1, 1, 18, 603, 38),
(33293, 45867, 0, 2, 1, 1, 18, 603, 38),
(33293, 45869, 0, 2, 1, 1, 18, 603, 38),
(33293, 45870, 0, 2, 1, 1, 18, 603, 38),
(33293, 45871, 0, 2, 1, 1, 18, 603, 38),
-- 25 man normal
(33885, 45624, 100, 0, 1, 1, 0, 0, 0),
(33885, 1, 100, 1, -33886, 4, 0, 0, 0),
-- 25 man hard mode
(33885, 45445, 0, 2, 1, 1, 18, 603, 38),
(33885, 45443, 0, 2, 1, 1, 18, 603, 38),
(33885, 45444, 0, 2, 1, 1, 18, 603, 38),
(33885, 45446, 0, 2, 1, 1, 18, 603, 38),
(33885, 45442, 0, 2, 1, 1, 18, 603, 38);

DELETE FROM `reference_loot_template` WHERE `entry` IN (33294, 33886);
INSERT INTO `reference_loot_template` VALUES
-- XT10normal
(33294, 45680, 0, 1, 1, 1, 0, 0, 0),
(33294, 45694, 0, 1, 1, 1, 0, 0, 0),
(33294, 45676, 0, 1, 1, 1, 0, 0, 0),
(33294, 45679, 0, 1, 1, 1, 0, 0, 0),
(33294, 45687, 0, 1, 1, 1, 0, 0, 0),
(33294, 45685, 0, 1, 1, 1, 0, 0, 0),
(33294, 45686, 0, 1, 1, 1, 0, 0, 0),
(33294, 45677, 0, 1, 1, 1, 0, 0, 0),
(33294, 45682, 0, 1, 1, 1, 0, 0, 0),
(33294, 45675, 0, 1, 1, 1, 0, 0, 0),
-- XT25normal
(33886, 45260, 0, 1, 1, 1, 0, 0, 0),
(33886, 45249, 0, 1, 1, 1, 0, 0, 0),
(33886, 45250, 0, 1, 1, 1, 0, 0, 0),
(33886, 45248, 0, 1, 1, 1, 0, 0, 0),
(33886, 45246, 0, 1, 1, 1, 0, 0, 0),
(33886, 45252, 0, 1, 1, 1, 0, 0, 0),
(33886, 45253, 0, 1, 1, 1, 0, 0, 0),
(33886, 45257, 0, 1, 1, 1, 0, 0, 0),
(33886, 45259, 0, 1, 1, 1, 0, 0, 0),
(33886, 45258, 0, 1, 1, 1, 0, 0, 0),
(33886, 45251, 0, 1, 1, 1, 0, 0, 0),
(33886, 45254, 0, 1, 1, 1, 0, 0, 0),
(33886, 45247, 0, 1, 1, 1, 0, 0, 0),
(33886, 45255, 0, 1, 1, 1, 0, 0, 0),
(33886, 45256, 0, 1, 1, 1, 0, 0, 0);

-- Iron Council (Assembly of Iron)
-- Iron council
UPDATE creature_template SET ScriptName='boss_brundir' WHERE entry = 32857;
UPDATE creature_template SET ScriptName='boss_molgeim' WHERE entry = 32927;
UPDATE creature_template SET ScriptName='boss_steelbreaker' WHERE entry = 32867;
UPDATE creature_template SET ScriptName = 'mob_rune_of_power' WHERE entry = 33705;
UPDATE creature_template SET ScriptName = 'mob_rune_of_summoning' WHERE entry = 33051;
UPDATE creature_template SET ScriptName = 'mob_ulduar_lightning_elemental' WHERE entry = 32958;
UPDATE creature_template SET mechanic_immune_mask = 619397115 WHERE entry IN (32857, 33694, 32927, 33692, 32867, 33693);
UPDATE creature_template SET mechanic_immune_mask = 619395067 WHERE entry IN (32857, 33694); -- Brundir stunnable
-- LOOT
UPDATE creature_template SET lootid = entry WHERE entry IN (32857, 32927, 32867, 33694, 33692, 33693);
DELETE FROM creature_loot_template WHERE entry IN (32857, 32927, 32867, 33694, 33692, 33693);
INSERT INTO creature_loot_template VALUES
-- 10man
-- Brundir
(32857, 40753, 100, 0, 1, 1, 0, 0, 0), -- Emblem of Valor
(32857, 1, 100, 1, -32857, 2, 0, 0, 0),
-- Molgeim
(32927, 40753, 100, 0, 1, 1, 0, 0, 0), -- Emblem of Valor
(32927, 1, 100, 1, -32857, 2, 0, 0, 0),
(32927, 45506, 50, 2, 1, 1, 0, 0, 0), -- Data Disk qitem
-- Steelbreaker
(32867, 40753, 100, 0, 1, 1, 0, 0, 0), -- Emblem of Valor
(32867, 1, 100, 1, -32857, 2, 0, 0, 0),
(32867, 45506, 50, 2, 1, 1, 0, 0, 0), -- Data Disk qitem
(32867, 2, 100, 3, -32867, 1, 0, 0, 0), -- hard mode loot
-- 25man
-- Brundir
(33694, 45624, 100, 0, 1, 1, 0, 0, 0), -- Emblem of Conquest
(33694, 1, 100, 1, -33694, 4, 0, 0, 0),
-- Molgeim
(33692, 45624, 100, 0, 1, 1, 0, 0, 0), -- Emblem of Conquest
(33692, 1, 100, 1, -33694, 4, 0, 0, 0),
(33692, 45857, 50, 2, 1, 1, 0, 0, 0), -- Data Disk qitem
-- Steelbreaker
(33693, 45624, 100, 0, 1, 1, 0, 0, 0), -- Emblem of Conquest
(33693, 1, 100, 1, -33694, 4, 0, 0, 0),
(33693, 45857, 50, 2, 1, 1, 0, 0, 0), -- Data Disk qitem
(33693, 2, 100, 3, -33693, 1, 0, 0, 0); -- hard mode loot


DELETE FROM `reference_loot_template` WHERE `entry` IN (32857, 33694, 32867, 33693);
INSERT INTO `reference_loot_template` VALUES
-- 10man
-- normal mode
(32857, 45333, 0, 1, 1, 1, 0, 0, 0),
(32857, 45378, 0, 1, 1, 1, 0, 0, 0),
(32857, 45329, 0, 1, 1, 1, 0, 0, 0),
(32857, 45322, 0, 1, 1, 1, 0, 0, 0),
(32857, 45330, 0, 1, 1, 1, 0, 0, 0),
(32857, 45418, 0, 1, 1, 1, 0, 0, 0),
(32857, 45324, 0, 1, 1, 1, 0, 0, 0),
(32857, 45331, 0, 1, 1, 1, 0, 0, 0),
(32857, 45423, 0, 1, 1, 1, 0, 0, 0),
(32857, 45332, 0, 1, 1, 1, 0, 0, 0),
-- hard mode
(32867, 45455, 0, 3, 1, 1, 0, 0, 0),
(32867, 45456, 0, 3, 1, 1, 0, 0, 0),
(32867, 45448, 0, 3, 1, 1, 0, 0, 0),
(32867, 45449, 0, 3, 1, 1, 0, 0, 0),
(32867, 45447, 0, 3, 1, 1, 0, 0, 0),
-- 25man
(33694, 45226, 0, 1, 1, 1, 0, 0, 0),
(33694, 45224, 0, 1, 1, 1, 0, 0, 0),
(33694, 45228, 0, 1, 1, 1, 0, 0, 0),
(33694, 45193, 0, 1, 1, 1, 0, 0, 0),
(33694, 45227, 0, 1, 1, 1, 0, 0, 0),
(33694, 45238, 0, 1, 1, 1, 0, 0, 0),
(33694, 45237, 0, 1, 1, 1, 0, 0, 0),
(33694, 45235, 0, 1, 1, 1, 0, 0, 0),
(33694, 45240, 0, 1, 1, 1, 0, 0, 0),
(33694, 45234, 0, 1, 1, 1, 0, 0, 0),
(33694, 45232, 0, 1, 1, 1, 0, 0, 0),
(33694, 45239, 0, 1, 1, 1, 0, 0, 0),
(33694, 45225, 0, 1, 1, 1, 0, 0, 0),
(33694, 45233, 0, 1, 1, 1, 0, 0, 0),
(33694, 45236, 0, 1, 1, 1, 0, 0, 0),
-- hard mode
(33693, 45241, 0, 3, 1, 1, 0, 0, 0),
(33693, 45245, 0, 3, 1, 1, 0, 0, 0),
(33693, 45607, 0, 3, 1, 1, 0, 0, 0),
(33693, 45243, 0, 3, 1, 1, 0, 0, 0),
(33693, 45242, 0, 3, 1, 1, 0, 0, 0),
(33693, 45244, 0, 3, 1, 1, 0, 0, 0);

-- Kologarn
-- fix arms position because of the missing vehicles
-- use when can't reach the boss?
DELETE FROM creature WHERE id IN (32933, 32934);
INSERT INTO creature (id, map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, DeathState, MovementType) VALUES
(32933, 603, 3, 65535, 0, 0, 1799.68, -24.3599, 452.227, 3.14747, 604800, 0, 0, 543855, 0, 0, 0);
-- INSERT INTO creature (id, map, spawnMask, phaseMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, DeathState, MovementType) VALUES
-- (32934, 603, 3, 65535, 0, 0, 1799.68, -24.3599, 452.227, 3.14747, 604800, 0, 0, 543855, 0, 0, 0);
UPDATE creature_model_info SET bounding_radius=15, combat_reach=15 WHERE modelid IN (28638, 28822, 28821);
UPDATE creature_template SET mechanic_immune_mask=617299803, scriptname='boss_kologarn' WHERE entry IN (32930, 33909);
UPDATE creature_template SET mechanic_immune_mask=652951551, scriptname='boss_right_arm' WHERE entry=32934;
UPDATE creature_template SET mechanic_immune_mask=652951551, scriptname='boss_left_arm' WHERE entry=32933;
UPDATE creature_template SET ScriptName = 'mob_ulduar_rubble' WHERE entry IN (33768, 33809, 33908, 33942);
UPDATE creature_template SET RegenHealth = 1 WHERE entry = 33910;
UPDATE creature_template SET RegenHealth = 1 WHERE entry = 33911;
UPDATE creature_template SET ScriptName = "mob_eyebeam_trigger" WHERE entry IN (33802, 33632);

DELETE FROM creature_template_addon WHERE entry = 32934;
INSERT INTO creature_template_addon VALUES
(32934, 0, 0, 0, 0, 0, 0, 380, "", "");

DELETE FROM vehicle_data WHERE entry = 380;
INSERT INTO vehicle_data VALUES (380, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM vehicle_seat_data WHERE seat IN (3690, 3691, 3692);
INSERT INTO vehicle_seat_data VALUES
(3690, 0),
(3691, 0),
(3692, 0);

-- missing loot 25man
DELETE FROM gameobject_loot_template WHERE entry = 26929;
INSERT INTO gameobject_loot_template VALUES
(26929, 45624, 100, 0, 1, 1, 0, 0, 0), -- Emblem of Conquest
(26929, 45261, 100, 1, -26929, 4, 0, 0, 0); -- 4 items
DELETE FROM reference_loot_template WHERE entry = 26929;
INSERT INTO reference_loot_template VALUES
(26929, 45261, 0, 1, 1, 1, 0, 0, 0),
(26929, 45266, 0, 1, 1, 1, 0, 0, 0),
(26929, 45269, 0, 1, 1, 1, 0, 0, 0),
(26929, 45273, 0, 1, 1, 1, 0, 0, 0),
(26929, 45271, 0, 1, 1, 1, 0, 0, 0),
(26929, 45262, 0, 1, 1, 1, 0, 0, 0),
(26929, 45263, 0, 1, 1, 1, 0, 0, 0),
(26929, 45270, 0, 1, 1, 1, 0, 0, 0),
(26929, 45274, 0, 1, 1, 1, 0, 0, 0),
(26929, 45267, 0, 1, 1, 1, 0, 0, 0),
(26929, 45272, 0, 1, 1, 1, 0, 0, 0),
(26929, 45265, 0, 1, 1, 1, 0, 0, 0),
(26929, 45275, 0, 1, 1, 1, 0, 0, 0),
(26929, 45264, 0, 1, 1, 1, 0, 0, 0),
(26929, 45268, 0, 1, 1, 1, 0, 0, 0);

-- Auriaya
UPDATE creature_template SET mechanic_immune_mask=583745371, equipment_id = 103000, scriptname='boss_auriaya' WHERE entry=33515;
UPDATE creature_template SET mechanic_immune_mask=619395071, scriptname='mob_feral_defender' WHERE entry=34035;
UPDATE creature_template SET minlevel=80, maxlevel=80, faction_h=14, faction_a=14, scriptname='mob_seeping_feral_essence' WHERE entry=34098;
UPDATE creature_template SET ScriptName = 'mob_sanctum_sentry' WHERE entry = 34014;
UPDATE `creature_template` SET `mechanic_immune_mask` = 619397115 WHERE `entry` IN (33515, 34175);
DELETE FROM creature_equip_template WHERE entry = 103000;
INSERT INTO creature_equip_template values (103000, 45315, 0, 0);
DELETE FROM spell_script_target WHERE entry = 64449;
INSERT INTO spell_script_target VALUES
(64449, 1, 34096);

-- LOOT
UPDATE creature_template SET lootid = entry WHERE entry IN (33515, 34175);
DELETE FROM creature_loot_template WHERE entry IN (33515, 34175);
INSERT INTO creature_loot_template VALUES
-- 10man
(33515, 40753, 100, 0, 1, 1, 0, 0, 0), -- Emblem of Valor
(33515, 1, 100, 1, -33515, 2, 0, 0, 0),
-- 25man
(34175, 45624, 100, 0, 1, 1, 0, 0, 0), -- Emblem of Conquest
(34175, 1, 100, 1, -34175, 4, 0, 0, 0);

DELETE FROM `reference_loot_template` WHERE `entry` IN (33515, 34175);
INSERT INTO `reference_loot_template` VALUES
-- 10man
-- normal mode
(33515, 45864, 0, 1, 1, 1, 0, 0, 0),
(33515, 45866, 0, 1, 1, 1, 0, 0, 0),
(33515, 45709, 0, 1, 1, 1, 0, 0, 0),
(33515, 45708, 0, 1, 1, 1, 0, 0, 0),
(33515, 45711, 0, 1, 1, 1, 0, 0, 0),
(33515, 45713, 0, 1, 1, 1, 0, 0, 0),
(33515, 45707, 0, 1, 1, 1, 0, 0, 0),
(33515, 45865, 0, 1, 1, 1, 0, 0, 0),
(33515, 45712, 0, 1, 1, 1, 0, 0, 0),
(33515, 45832, 0, 1, 1, 1, 0, 0, 0),
-- 25man
(34175, 45327, 0, 1, 1, 1, 0, 0, 0),
(34175, 45319, 0, 1, 1, 1, 0, 0, 0),
(34175, 45434, 0, 1, 1, 1, 0, 0, 0),
(34175, 45438, 0, 1, 1, 1, 0, 0, 0),
(34175, 45334, 0, 1, 1, 1, 0, 0, 0),
(34175, 45439, 0, 1, 1, 1, 0, 0, 0),
(34175, 45440, 0, 1, 1, 1, 0, 0, 0),
(34175, 45325, 0, 1, 1, 1, 0, 0, 0),
(34175, 45436, 0, 1, 1, 1, 0, 0, 0),
(34175, 45435, 0, 1, 1, 1, 0, 0, 0),
(34175, 45326, 0, 1, 1, 1, 0, 0, 0),
(34175, 45441, 0, 1, 1, 1, 0, 0, 0),
(34175, 45320, 0, 1, 1, 1, 0, 0, 0),
(34175, 45315, 0, 1, 1, 1, 0, 0, 0),
(34175, 45437, 0, 1, 1, 1, 0, 0, 0);

-- Freya
UPDATE creature_template SET ScriptName = 'boss_freya' WHERE entry = 32906;
UPDATE creature_template SET ScriptName = 'boss_elder_brightleaf' WHERE entry = 32915;
UPDATE creature_template SET ScriptName = 'boss_elder_ironbranch' WHERE entry = 32913;
UPDATE creature_template SET ScriptName = 'boss_elder_stonebark' WHERE entry = 32914;
UPDATE creature_template SET ScriptName = 'mob_iron_roots' WHERE entry IN (33088, 33168);
UPDATE creature_template SET ScriptName = 'mob_freya_ground' WHERE entry IN (33215, 33228, 33170, 33050, 34129);
UPDATE creature_template SET ScriptName = 'mob_freya_spawned' WHERE entry IN (32916, 32919, 33202, 33203, 32918);

-- some aura fixes, this may be wrong
REPLACE INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES ('62525', '1', '32906');
REPLACE INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES ('62524', '1', '32906');
REPLACE INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES ('62521', '1', '32906');
REPLACE INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES ('62385', '1', '32906');
REPLACE INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES ('62387', '1', '32906');
REPLACE INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES ('62386', '1', '32906');

-- Added hack for Freya's gift
-- DELETE FROM `gameobject` WHERE `id` IN (194324, 194325,194326,194327,194328,194329,194330,194331);
-- INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
-- (733324, 194324, 603, 1, 65535, 2374.876221, -78.512665, 425.073608, 3.260976, 0, 0, 0.706026, 0.708186, -604800, 100, 1),
-- (733325, 194325, 603, 1, 65535, 2374.876221, -78.512665, 425.073608, 3.260976, 0, 0, 0.706026, 0.708186, -604800, 100, 1),
-- (733326, 194326, 603, 1, 65535, 2374.876221, -78.512665, 425.073608, 3.260976, 0, 0, 0.706026, 0.708186, -604800, 100, 1),
-- (733327, 194327, 603, 1, 65535, 2374.876221, -78.512665, 425.073608, 3.260976, 0, 0, 0.706026, 0.708186, -604800, 100, 1),
-- (733328, 194328, 603, 2, 65535, 2374.876221, -78.512665, 425.073608, 3.260976, 0, 0, 0.706026, 0.708186, -604800, 100, 1),
-- (733329, 194329, 603, 2, 65535, 2374.876221, -78.512665, 425.073608, 3.260976, 0, 0, 0.706026, 0.708186, -604800, 100, 1),
-- (733330, 194330, 603, 2, 65535, 2374.876221, -78.512665, 425.073608, 3.260976, 0, 0, 0.706026, 0.708186, -604800, 100, 1),
-- (733331, 194331, 603, 2, 65535, 2374.876221, -78.512665, 425.073608, 3.260976, 0, 0, 0.706026, 0.708186, -604800, 100, 1);
-- Delete bugged spell from mobs
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (33430,33732) AND `action1_param1` = 63007;
