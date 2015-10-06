//
//  constants.h
//  Mutation_080
//
//  Created by Martin Widyanata on 30.08.14.
//
//

#ifndef __Mutation_080__constants__
#define __Mutation_080__constants__


#define SERVER_TCP_IP "10.0.0.5"
#define PORT 12333
#define MAX_LIGHTS 8


extern const float factor;
// 1.0 = 1 meter
extern const float levelDistance;
extern const float f0f1Distance;
extern const float f3f4Distance;
extern const float f4f5Distance;
extern const float f5f6Distance;
extern const float f8f9Distance;
extern const float f0Long;
extern const float f0Short;
extern const float f1Long;
extern const float f1Short;
extern const float f2Long;
extern const float f2Short;
extern const float f3Long;
extern const float f3Short;
extern const float f4Long;
extern const float f4Short;
extern const float f5Long;
extern const float f5Short;
extern const float f6Long;
extern const float f6Short;
extern const float f7Long;
extern const float f7Short;
extern const float f8Long;
extern const float f8Short;
extern const float f9Long;
extern const float f9Short;

extern const float surfacesLong[10];
extern const float surfacesShort[10];

extern const float markerIds[10];

extern const float f0MarkerWidth;
extern const float f0MarkerHeight;
extern const float f1MarkerWidth;
extern const float f1MarkerHeight;
extern const float f2MarkerWidth;
extern const float f2MarkerHeight;
extern const float f3MarkerWidth;
extern const float f3MarkerHeight;
extern const float f4MarkerWidth;
extern const float f4MarkerHeight;
extern const float f5MarkerWidth;
extern const float f5MarkerHeight;
extern const float f6MarkerWidth;
extern const float f6MarkerHeight;
extern const float f7MarkerWidth;
extern const float f7MarkerHeight;
extern const float f8MarkerWidth;
extern const float f8MarkerHeight;
extern const float f9MarkerWidth;
extern const float f9MarkerHeight;

extern const float markerWidths[10];
extern const float markerHeights[10];

extern const float f0MarkerX;
extern const float f0MarkerY;
extern const float f1MarkerX;
extern const float f1MarkerY;
extern const float f2MarkerX;
extern const float f2MarkerY;
extern const float f3MarkerX;
extern const float f3MarkerY;
extern const float f4MarkerX;
extern const float f4MarkerY;
extern const float f5MarkerX;
extern const float f5MarkerY;
extern const float f6MarkerX;
extern const float f6MarkerY;
extern const float f7MarkerX;
extern const float f7MarkerY;
extern const float f8MarkerX;
extern const float f8MarkerY;
extern const float f9MarkerX;
extern const float f9MarkerY;

extern const float markerXs[10];
extern const float markerYs[10];

extern const int oscPorts[10];

enum{
    FLOOR,
    EAST,
    WEST,
    
};

extern const int orientations[10];

#endif /* defined(__Mutation_080__constants__) */
