-- Killing Machine
DELETE FROM `spell_proc_event` WHERE `entry` IN (51123, 51127, 51128, 51129, 51130);
INSERT INTO `spell_proc_event` VALUES
(51123, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4|16, 0, 1, 0, 0),
(51127, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4|16, 0, 2, 0, 0),
(51128, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4|16, 0, 3, 0, 0),
(51129, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4|16, 0, 4, 0, 0),
(51130, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4|16, 0, 5, 0, 0);