-- Add movement and movement scripts for Dalaran Visitors (by Bastek)
DELETE FROM creature WHERE id IN (32598, 32601);
INSERT INTO creature VALUES
(@guid1, 32598, 571, 1, 1, 0, 0, 5789.176, 305.287, 715.711, 1.360, 5, 5, 0, 8225, 7809, 0, 2),
(@guid2, 32601, 571, 1, 1, 0, 0, 5844.434, 316.649, 720.824, 1.796, 5, 5, 0, 8225, 7809, 0, 2);

UPDATE creature_template SET InhabitType = 3 WHERE entry IN (32596, 32602, 32597, 32596, 32598, 32601);
UPDATE creature SET position_x = 5793.729, position_y = 313.460, position_z = 688.348, orientation = 1.398, spawntimesecs = 15, MovementType = 2 WHERE id = 32602;
UPDATE creature SET position_x = 5745.452, position_y = 333.738, position_z = 686.503, orientation = 1.128, spawntimesecs = 15, MovementType = 2 WHERE id = 32597;
UPDATE creature SET position_x = 5763.385, position_y = 326.184, position_z = 702.168, orientation = 1.072, spawntimesecs = 25, MovementType = 2 WHERE guid = 103474;
UPDATE creature SET position_x = 5745.451, position_y = 333.738, position_z = 729.273, orientation = 0.879, spawntimesecs = 25, MovementType = 2 WHERE guid = 103444;

DELETE FROM creature_template_addon WHERE entry IN (32598, 32601);
INSERT INTO creature_template_addon VALUES
(32598, 16314, 0, 1, 1, 0, 0, 0, NULL, NULL),
(32601, 22471, 0, 1, 1, 0, 0, 0, NULL, NULL);

DELETE FROM creature_movement_scripts WHERE id IN (3259701, 3259702);
INSERT INTO creature_movement_scripts (id, delay, command, datalong, comments) VALUES
(3259701, 0, 25, 1, 'Dalaran Visitor Start Fly'),
(3259702, 0, 24, 0, 'Dalaran Visitor Dismount'),
(3259702, 0, 25, 1, 'Dalaran Visitor Start Run');

DELETE FROM creature_movement WHERE id = 103589;
INSERT INTO creature_movement VALUES
(103589, 1, 5745.45, 333.738, 686.503, 0, 3259701, 0, 0, 0, 0, 0, 0, 0, 0, 1.11914, 0, 0),
(103589, 2, 5762.25, 363.1, 679.003, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.05474, 0, 0),
(103589, 3, 5786.39, 408.592, 669.682, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.09008, 0, 0),
(103589, 4, 5798.27, 433.071, 661.448, 0, 3259702, 0, 0, 0, 0, 0, 0, 0, 0, 1.10579, 0, 0),
(103589, 5, 5808.59, 449.782, 658.757, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.05473, 0, 0),
(103589, 6, 5814.5, 458.301, 658.761, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.964407, 0, 0),
(103589, 7, 5829.59, 478.386, 658.23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.21023, 0, 0),
(103589, 8, 5832.6, 515.395, 657.748, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.28001, 0, 0),
(103589, 9, 5838.85, 529.546, 658.081, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1.13714, 0, 0);

DELETE FROM creature_movement WHERE id = 103444;
INSERT INTO creature_movement VALUES
(103444, 1, 5745.45, 333.738, 729.273, 0, 3259701, 0, 0, 0, 0, 0, 0, 0, 0, 0.999696, 0, 0),
(103444, 2, 5768.64, 371.217, 701.405, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.00755, 0, 0),
(103444, 3, 5789.37, 406.123, 677.636, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.03504, 0, 0),
(103444, 4, 5808.26, 433.621, 658.771, 0, 3259702, 0, 0, 0, 0, 0, 0, 0, 0, 0.983989, 0, 0),
(103444, 5, 5821.68, 459.976, 658.765, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.12536, 0, 0),
(103444, 6, 5831.58, 484.884, 658.122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.24317, 0, 0),
(103444, 7, 5830.69, 512.652, 657.748, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.85186, 0, 0),
(103444, 8, 5814.15, 521.39, 658.111, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2.64611, 0, 0);

DELETE FROM creature_movement WHERE id = 103474;
INSERT INTO creature_movement VALUES
(103474, 1, 5763.38, 326.184, 702.168, 0, 3259701, 0, 0, 0, 0, 0, 0, 0, 0, 1.2492, 0, 0),
(103474, 2, 5777.89, 362.683, 689.182, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.14515, 0, 0),
(103474, 3, 5801.19, 414.491, 677.706, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.15692, 0, 0),
(103474, 4, 5812.42, 443.833, 658.758, 0, 3259702, 0, 0, 0, 0, 0, 0, 0, 0, 1.19317, 0, 0),
(103474, 5, 5829.3, 476.87, 658.231, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.38009, 0, 0),
(103474, 6, 5831.22, 513.454, 657.748, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.59606, 0, 0),
(103474, 7, 5813.74, 521.03, 658.104, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2.40833, 0, 0);

DELETE FROM creature_movement WHERE id = 104200;
INSERT INTO creature_movement VALUES
(104200, 1, 5793.73, 313.46, 688.348, 0, 3259701, 0, 0, 0, 0, 0, 0, 0, 0, 1.64268, 0, 0),
(104200, 2, 5804.48, 387.327, 673.251, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.41564, 0, 0),
(104200, 3, 5810.18, 424.468, 665.122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.42742, 0, 0),
(104200, 4, 5814.35, 447.203, 658.753, 0, 3259702, 0, 0, 0, 0, 0, 0, 0, 0, 1.10981, 0, 0),
(104200, 5, 5829.53, 478.83, 658.229, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.11766, 0, 0),
(104200, 6, 5832.12, 509.348, 657.702, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.65565, 0, 0),
(104200, 7, 5815.63, 520.666, 658.127, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2.55192, 0, 0);

DELETE FROM creature_movement WHERE id = 103474;
INSERT INTO creature_movement VALUES
(103474, 1, 5763.38, 326.184, 702.168, 0, 3259701, 0, 0, 0, 0, 0, 0, 0, 0, 1.2492, 0, 0),
(103474, 2, 5777.89, 362.683, 689.182, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.14515, 0, 0),
(103474, 3, 5801.19, 414.491, 677.706, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.15692, 0, 0),
(103474, 4, 5812.42, 443.833, 658.758, 0, 3259702, 0, 0, 0, 0, 0, 0, 0, 0, 1.19317, 0, 0),
(103474, 5, 5829.3, 476.87, 658.231, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.38009, 0, 0),
(103474, 6, 5831.22, 513.454, 657.748, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.59606, 0, 0),
(103474, 7, 5813.74, 521.03, 658.104, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2.40833, 0, 0);

SET @guid1 = (SELECT guid FROM creature WHERE id = 32598);
DELETE FROM creature_movement WHERE id = @guid1;
INSERT INTO creature_movement VALUES
(@guid1, 1, 5789.18, 305.287, 715.711, 0, 3259701, 0, 0, 0, 0, 0, 0, 0, 0, 1.18715, 0, 0),
(@guid1, 2, 5799.46, 357.02, 695.832, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.43967, 0, 0),
(@guid1, 3, 5809.73, 416.745, 672.087, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.40825, 0, 0),
(@guid1, 4, 5815.54, 447.626, 658.755, 0, 3259702, 0, 0, 0, 0, 0, 0, 0, 0, 1.25835, 0, 0),
(@guid1, 5, 5829.6, 478.895, 658.23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.27798, 0, 0),
(@guid1, 6, 5831.45, 512.73, 657.748, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.64492, 0, 0),
(@guid1, 7, 5838.68, 528.795, 658.121, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1.21453, 0, 0);

SET @guid2 = (SELECT guid FROM creature WHERE id = 32601);
DELETE FROM creature_movement WHERE id = @guid2;
INSERT INTO creature_movement VALUES
(@guid2, 1, 5844.43, 316.649, 720.824, 0, 3259701, 0, 0, 0, 0, 0, 0, 0, 0, 1.45419, 0, 0),
(@guid2, 2, 5834.78, 349.813, 704.938, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.83428, 0, 0),
(@guid2, 3, 5821, 408.936, 679.263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.7793, 0, 0),
(@guid2, 4, 5817.13, 441.839, 658.761, 0, 3259702, 0, 0, 0, 0, 0, 0, 0, 0, 1.31197, 0, 0),
(@guid2, 5, 5829.75, 479.093, 658.229, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.3591, 0, 0),
(@guid2, 6, 5830.68, 512.747, 657.748, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.75571, 0, 0),
(@guid2, 7, 5839.49, 530.256, 658.08, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1.20595, 0, 0);
