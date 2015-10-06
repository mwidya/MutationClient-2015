//
//  constants.cpp
//  Mutation_080
//
//  Created by Martin Widyanata on 30.08.14.
//
//

#include "constants.h"

//const float factor = 0.1f;
const float factor = 0.2f;

const float levelDistance = 3000*factor;
const float f0f1Distance = 2150*factor;
const float f3f4Distance = 8600*factor;
const float f4f5Distance = 4300*factor;
const float f5f6Distance = 11100*factor;
const float f8f9Distance = 6000*factor;
const float f0Long = 4300*factor;
const float f0Short = 1700*factor;
const float f1Long = 4300*factor;
const float f1Short = 1700*factor;
const float f2Long = 3950*factor;
const float f2Short = 4300*factor;
const float f3Long = 3000*factor;
const float f3Short = 1700*factor;
const float f4Long = 3000*factor;
const float f4Short = 1700*factor;
const float f5Long = 3000*factor;
const float f5Short = 1700*factor;
const float f6Long = 4300*factor;
const float f6Short = 1700*factor;
const float f7Long = 4300*factor;
const float f7Short = 3950*factor;
const float f8Long = 4300*factor;
const float f8Short = 1700*factor;
const float f9Long = 4300*factor;
const float f9Short = 1700*factor;

// f2 has to be switched between long and short
const float surfacesLong[10] = {f0Long, f1Long, f2Short, f3Long, f4Long, f5Long, f6Long, f7Long, f8Long, f9Long};
const float surfacesShort[10] = {f0Short, f1Short, f2Long, f3Short, f4Short, f5Short, f6Short, f7Short, f8Short, f9Short};

const float markerIds[10] = {691, 268, 581, 761, 528, 286, 484, 99, 222, 903};

const float f0MarkerWidth = 700*factor;
const float f0MarkerHeight = 700*factor;
const float f1MarkerWidth = 700*factor;
const float f1MarkerHeight = 700*factor;
const float f2MarkerWidth = 700*factor;
const float f2MarkerHeight = 691.3*factor;
const float f3MarkerWidth = 700*factor;
const float f3MarkerHeight = 700*factor;
const float f4MarkerWidth = 700*factor;
const float f4MarkerHeight = 700*factor;
const float f5MarkerWidth = 700*factor;
const float f5MarkerHeight = 700*factor;
const float f6MarkerWidth = 700*factor;
const float f6MarkerHeight = 700*factor;
const float f7MarkerWidth = 700*factor;
const float f7MarkerHeight = 691.3*factor;
const float f8MarkerWidth = 700*factor;
const float f8MarkerHeight = 700*factor;
const float f9MarkerWidth = 700*factor;
const float f9MarkerHeight = 700*factor;

const float markerWidths[10] = {f0MarkerWidth, f1MarkerWidth, f2MarkerWidth, f3MarkerWidth, f4MarkerWidth, f5MarkerWidth, f6MarkerWidth, f7MarkerWidth, f8MarkerWidth, f9MarkerWidth};
const float markerHeights[10] = {f0MarkerHeight, f1MarkerHeight, f2MarkerHeight, f3MarkerHeight, f4MarkerHeight, f5MarkerHeight, f6MarkerHeight, f7MarkerHeight, f8MarkerHeight, f9MarkerHeight};

const float f0MarkerX = 100*factor;
const float f0MarkerY = 100*factor;
const float f1MarkerX = 3500*factor;
const float f1MarkerY = 100*factor;
const float f2MarkerX = 3500*factor;
const float f2MarkerY = 100*factor;
const float f3MarkerX = 100*factor;
const float f3MarkerY = 100*factor;
const float f4MarkerX = 2200*factor;
const float f4MarkerY = 100*factor;
const float f5MarkerX = 100*factor;
const float f5MarkerY = 100*factor;
const float f6MarkerX = 3500*factor;
const float f6MarkerY = 100*factor;
const float f7MarkerX = 3500*factor;
const float f7MarkerY = 100*factor;
const float f8MarkerX = 100*factor;
const float f8MarkerY = 100*factor;
const float f9MarkerX = 3500*factor;
const float f9MarkerY = 100*factor;

const float markerXs[10] = {f0MarkerX, f1MarkerX, f2MarkerX, f3MarkerX, f4MarkerX, f5MarkerX, f6MarkerX, f7MarkerX, f8MarkerX, f9MarkerX};
const float markerYs[10] = {f0MarkerY, f1MarkerY, f2MarkerY, f3MarkerY, f4MarkerY, f5MarkerY, f6MarkerY, f7MarkerY, f8MarkerY, f9MarkerY};

const int oscPorts[10] = {6000,6001,6002,6003,6004,6005,6006,6007,6008,6009};

const int orientations[10] = {WEST, EAST, FLOOR, WEST, EAST, WEST, EAST, FLOOR, WEST, EAST};

