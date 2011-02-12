-- Adding missing NPCs n Location Gjalerbron (Howling Fjord)


-- Add missing NPCs - Necrolord (24014)

DELETE FROM creature WHERE id=24014;
INSERT INTO `creature` ( `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`) VALUES
( 24014, 571, 1, 1, 0, 0, 2722.93, -3404.28, 179.657, 4.64259, 300, 5, 0, 7185, 7196, 0, 1),
( 24014, 571, 1, 1, 0, 0, 2441.07, -3637.95, 181.387, 3.49687, 300, 5, 0, 7185, 7196, 0, 1),
( 24014, 571, 1, 1, 0, 0, 2801.48, -3611.38, 141.334, 5.07651, 300, 5, 0, 7185, 7196, 0, 1),
( 24014, 571, 1, 1, 0, 0, 2439.56, -3643.6, 201.397, 2.24711, 300, 5, 0, 7185, 7196, 0, 1),
( 24014, 571, 1, 1, 0, 0, 2794.07, -3601.53, 201.401, 3.99145, 300, 5, 0, 7185, 7196, 0, 1),
( 24014, 571, 1, 1, 0, 0, 2716.1, -3447.36, 161.28, 2.85331, 300, 0, 0, 7185, 7196, 0, 0),
( 24014, 571, 1, 1, 0, 0, 2757.94, -3524.41, 166.137, 3.7458, 300, 5, 0, 7185, 7196, 0, 1),
( 24014, 571, 1, 1, 0, 0, 2782.33, -3544.88, 166.491, 2.15024, 300, 0, 0, 7185, 7196, 0, 0),
( 24014, 571, 1, 1, 0, 0, 2659.14, -3515.01, 161.464, 3.52865, 300, 0, 0, 7185, 7196, 0, 0),
( 24014, 571, 1, 1, 0, 0, 2800.49, -3556.2, 161.469, 0.610578, 300, 5, 0, 7185, 7196, 0, 1),
( 24014, 571, 1, 1, 0, 0, 2687.97, -3501.81, 161.464, 0.39604, 300, 0, 0, 7185, 7196, 0, 0),
( 24014, 571, 1, 1, 0, 0, 2582.45, -3600.96, 161.466, 4.16922, 300, 0, 0, 7185, 7196, 0, 0),
( 24014, 571, 1, 1, 0, 0, 2452.74, -3604.12, 232.291, 0.855211, 300, 0, 0, 7185, 7196, 0, 0),
(24014,571,1,1,21988,321,2811.26,-3786.01,255.23,2.138683,120,0,0,7220,7256,0,0),
(24014,571,1,1,21988,321,2793.07,-3798.74,255.49,2.380584,120,0,0,7220,7256,0,0),
(24014,571,1,1,21988,321,2863.66,-3898.51,248.486,5.371379,120,0,0,7220,7256,0,0),
(24014,571,1,1,21988,321,2879.80,-3887.77,248.486,5.440494,120,0,0,7220,7256,0,0);

-- Add spells and texts for Necrolord (24014)
UPDATE creature_template SET AIName='EventAI' WHERE entry=24014;

-- Text
DELETE FROM creature_ai_texts WHERE entry IN (-240141,-240142);
INSERT INTO creature_ai_texts VALUES
(-240141,'More ingredients to fuel our rituals here.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'Necrolord Say1'),
(-240142,'You too will serve the Lich King.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'Necrolord Say2');

-- EventAi
DELETE FROM creature_ai_scripts WHERE id IN (2401400,2401401,2401402);
INSERT INTO creature_ai_scripts VALUES
(2401400,24014,4,0,100,0,0,0,0,0,11,18267,1,0,23,1,0,0,1,-240238,-240142,0,'Necrolord - Cast Curse of Weakness and Say on Aggro'),
(2401401,24014,0,0,100,1,1000,1000,10000,10000,11,9613,1,0,0,0,0,0,0,0,0,0,'Necrolord - Cast Shadowbolt '),
(2401402,24014,0,0,100,1,4000,4000,10000,10000,11,17173,1,0,0,0,0,0,0,0,0,0,'Necrolord - Cast Drain Life');



-- Add missing NPCs - Gjalerbron Warrior (23991)
DELETE FROM creature WHERE id=23991;
INSERT INTO `creature` ( `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`) VALUES
( 23991, 571, 1, 1, 0, 0, 2589.63, -3294.62, 160.321, 1.46608, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2579.6, -3334.66, 166.911, 1.309, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2778.59, -3723.95, 223.692, 2.58309, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2490.73, -3397.37, 159.247, 2.11185, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2351.27, -3548.99, 158.661, 1.86203, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2714.61, -3578.08, 205.548, 2.30383, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2467.65, -3460.91, 178.671, 1.43163, 300, 5, 0, 8982, 0, 0, 1),
( 23991, 571, 1, 1, 0, 0, 2496.64, -3493.46, 183.705, 0.361672, 300, 5, 0, 8982, 0, 0, 1),
( 23991, 571, 1, 1, 0, 0, 2680.09, -3415.24, 197.853, -0.191645, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2595.56, -3454.66, 185.507, 2.32129, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2713.02, -3546.76, 207.441, 3.90954, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2698.64, -3523.15, 206.591, 3.4383, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2666.03, -3557.67, 205.333, 0.837758, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2649.52, -3558.31, 205.334, 2.28638, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2649.07, -3625.73, 206.012, 1.41372, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2744.24, -3749.73, 223.4, 1.72788, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2693.19, -3596.49, 206.132, 2.19912, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2557.15, -3484.74, 185.682, 2.42601, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2389.9, -3560.68, 165.733, 3.735, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2656.01, -3595.2, 205.355, 3.61924, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2442.41, -3515.73, 179.827, 3.82227, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2532.95, -3505.02, 185.22, 1.8675, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2596.71, -3567.49, 205.306, 1.36136, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2531.61, -3563.9, 203.093, 0.15708, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2597.38, -3495.83, 177.496, 5.33527, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2746.54, -3623.14, 223.258, 2.94961, 300, 0, 0, 8982, 0, 0, 0),
( 23991, 571, 1, 1, 0, 0, 2668.7, -3610.65, 205.545, 1.97222, 300, 0, 0, 8982, 0, 0, 0),
(23991,571,1,1,21961,720,2861.44,-3829.07,244.56,4.0574,120,0,0,9110,0,0,0),
(23991,571,1,1,21987,720,2874.01,-3846.63,244.56,3.76759,120,0,0,9090,0,0,0),
(23991,571,1,1,21961,720,2815.86,-3860.29,244.56,0.568663,120,0,0,8990,0,0,0),
(23991,571,1,1,21987,720,2827.73,-3878.89,244.56,0.519184,120,0,0,9291,0,0,0);


UPDATE creature_template SET AIName='EventAI' WHERE entry=23991;

-- Text
DELETE FROM creature_ai_texts WHERE entry=-239911;
INSERT INTO creature_ai_texts VALUES
(-239911,'Look what has come to play.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'Gjalerbron Warrior Say1');

-- EventAi
DELETE FROM creature_ai_scripts WHERE id IN (2399100,2399101);
INSERT INTO creature_ai_scripts VALUES
(2399100,23991,4,0,100,0,0,0,0,0,11,13730,1,0,23,1,0,0,1,-239911,0,0,'Gjalerbron Warrior - Cast Demoralizing Shout and Say on Aggro'),
(2399101,23991,0,0,100,1,1000,1000,10000,10000,11,10966,1,0,0,0,0,0,0,0,0,0,'Gjalerbron Warrior - Cast Uppercut');


-- Add missing NPCs - Gjalerbron Rune-Caster (23990)

DELETE FROM creature WHERE id=23990;
INSERT INTO `creature` ( `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`) VALUES
( 23990, 571, 1, 1, 0, 0, 2508.93, -3514.17, 185.844, 2.65047, 300, 5, 0, 8982, 3155, 0, 1),
( 23990, 571, 1, 1, 0, 0, 2676.95, -3486.91, 207.755, 5.48033, 300, 5, 0, 8982, 3155, 0, 1),
( 23990, 571, 1, 1, 0, 0, 2657.33, -3409.41, 187.719, 5.87093, 300, 0, 0, 8982, 3155, 0, 0),
( 23990, 571, 1, 1, 0, 0, 2677.52, -3502.65, 205.484, 2.8603, 300, 5, 0, 8982, 3155, 0, 1),
( 23990, 571, 1, 1, 0, 0, 2641.78, -3506.91, 206.403, 5.13127, 300, 5, 0, 8982, 3155, 0, 1),
( 23990, 571, 1, 1, 0, 0, 2651.64, -3583.68, 205.355, 0.095077, 300, 5, 0, 8982, 3155, 0, 1),
( 23990, 571, 1, 1, 0, 0, 2708.01, -3768.19, 232.505, 3.05433, 300, 5, 0, 8982, 3155, 0, 1),
( 23990, 571, 1, 1, 0, 0, 2758.18, -3671.48, 222.813, 1.95356, 300, 5, 0, 8982, 3155, 0, 1),
( 23990, 571, 1, 1, 0, 0, 2604.53, -3541.35, 206.246, 1.16937, 300, 5, 0, 8982, 3155, 0, 1),
(23990,571,1,1,21983,146,2862.34,-3915.29,248.54,2.136319,120,0,0,9110,3158,0,0),
(23990,571,1,1,21984,146,2877.62,-3901.39,248.57,2.104127,120,0,0,9090,3231,0,0),
(23990,571,1,1,21983,146,2895.04,-3892.45,248.54,2.211729,120,0,0,8990,3186,0,0);

UPDATE creature_template SET AIName='EventAI' WHERE entry=23990;

-- Text
DELETE FROM creature_ai_texts WHERE entry IN (-239901,-239902);
INSERT INTO creature_ai_texts VALUES
(-239901,'You tiny creatures disgust me.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'Gjalerbron Rune-Caster Say1'),
(-239902,'There will be no everlasting life for you.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'Gjalerbron Rune-Caster Say2');

-- EventAi
DELETE FROM creature_ai_scripts WHERE id IN (2399000,2399001,2399002);
INSERT INTO creature_ai_scripts VALUES
(2399000,23990,4,0,100,0,0,0,0,0,11,34787,1,0,23,1,0,0,1,-239901,-239902,0,'Gjalerbron Rune-Caster - Cast Freezing Circle and Say on Aggro'),
(2399001,23990,0,0,100,1,1000,1000,5000,5000,11,9672,1,0,0,0,0,0,0,0,0,0,'Gjalerbron Rune-Caster - Cast Frostbolt'),
(2399002,23990,0,0,100,1,4000,4000,15000,15000,11,43453,1,0,0,0,0,0,0,0,0,0,'Gjalerbron Rune-Caster - Cast Rune Ward');


-- Add missing NPC - Gjalerbron Sleep Watcher (23989)
DELETE FROM creature WHERE id=23989;
INSERT INTO `creature` ( `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`) VALUES
( 23989, 571, 1, 1, 0, 0, 2711.53, -3395.95, 223.595, 2.78364, 300, 5, 0, 7185, 7196, 0, 1),
( 23989, 571, 1, 1, 0, 0, 2496.53, -3516.9, 185.109, 1.39451, 300, 5, 0, 7185, 7196, 0, 1),
( 23989, 571, 1, 1, 0, 0, 2498.41, -3498.13, 183.955, 0.360934, 300, 5, 0, 7185, 7196, 0, 1),
( 23989, 571, 1, 1, 0, 0, 2677.51, -3503.06, 205.43, 2.58861, 300, 5, 0, 7185, 7196, 0, 1),
( 23989, 571, 1, 1, 0, 0, 2638.89, -3380.87, 184.897, 3.80693, 300, 5, 0, 7185, 7196, 0, 1),
( 23989, 571, 1, 1, 0, 0, 2642.74, -3520.91, 206.073, 1.07049, 300, 5, 0, 7185, 7196, 0, 1),
( 23989, 571, 1, 1, 0, 0, 2667.34, -3573.22, 205.315, 3.72785, 300, 5, 0, 7185, 7196, 0, 1),
( 23989, 571, 1, 1, 0, 0, 2727.32, -3767.63, 229.505, 0.261799, 300, 5, 0, 7185, 7196, 0, 1),
( 23989, 571, 1, 1, 0, 0, 2467.24, -3448.09, 173.55, 1.2121, 300, 5, 0, 7185, 7196, 0, 1),
( 23989, 571, 1, 1, 0, 0, 2680.21, -3675.94, 222.847, 5.42888, 300, 5, 0, 7185, 7196, 0, 1),
( 23989, 571, 1, 1, 0, 0, 2768.75, -3656.73, 224.478, 4.74729, 300, 5, 0, 7185, 7196, 0, 1),
( 23989, 571, 1, 1, 0, 0, 2610.26, -3603.94, 205.401, 2.40855, 300, 0, 0, 7185, 7196, 0, 0),
(23989,571,1,1,21985,237,2840.77,-3848.42,244.56,2.126903,120,0,0,7221,7189,0,0);

-- Add spell for NPC Gjalerbron Sleep Watcher (23989)
UPDATE creature_template SET AIName='EventAI' WHERE entry=23989;
-- EventAi
DELETE FROM creature_ai_scripts WHERE id=2398900;
INSERT INTO creature_ai_scripts VALUES
(2398900,23989,0,0,100,1,1000,1000,7000,7000,11,66290,1,0,0,0,0,0,0,0,0,0,'Gjalerbron Sleep Watcher - Cast Sleep');

-- Add spells for NPC Sepulchral Overseer (23993)
UPDATE creature_template SET AIName='EventAI' WHERE entry=23993;
-- EventAi
DELETE FROM creature_ai_scripts WHERE id IN (2399300,2399301,2399302);
INSERT INTO creature_ai_scripts VALUES
(2399300,23993,4,0,100,0,0,0,0,0,11,43556,1,0,23,1,0,0,1,-239901,-239902,0,'Sepulchral Overseer - Cast Curse of the Sepulcher on Aggro'),
(2399301,23993,0,0,100,1,1000,4000,10000,10000,11,12737,1,0,0,0,0,0,0,0,0,0,'Sepulchral Overseerr - Cast Frostbolt'),
(2399302,23993,0,0,100,1,5000,8000,10000,10000,11,22744,1,0,0,0,0,0,0,0,0,0,'Sepulchral Overseer - Cast Chains of Ice');
