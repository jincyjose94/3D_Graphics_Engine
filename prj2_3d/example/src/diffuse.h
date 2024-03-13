/*
 * axis.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Checkout
 */
#include "3d_lcd__api.h"
#include "board.h"
#include <string.h>
#include <stdlib.h>

#ifndef SRC_AXIS_H_
#define SRC_AXIS_H_
#define GREY1 0x7A7C7B

#define points_threed_coord 4
#define points_cube 8
#define D 70
#define max(a,b) (a>b?a:b)

typedef struct {
	float x;
	float y;
	float z;
} points_3d;

typedef struct{
	float xp;
	float yp;
} projection_2d;

//struct Edge {
//    int yMin, yMax; // Minimum and maximum y-coordinates
//    float x; // Current x-coordinate of the edge
//    float slopeInv; // Inverse slope of the edge
//};

void draw3Daxis ();
void drawCube ();
float lambdaShadow(float Zi,float Zs);
points_3d getShadowPoints(points_3d Pi, points_3d Ps, float lambda);
void drawShadow();
projection_2d get3DTransform(points_3d Pi);
void colorPolygon(projection_2d pr[], uint32_t color);
int getDiffuseColor(points_3d Pi, int df);
projection_2d points3dto2d (points_3d Pi);
void LineDDA(float X1, float X2, float Y1, float Y2, uint32_t color);

//cos 30 = 0.866 = cos(-30) = rt(3)/2
//sin 30 = 0.5, sin(-30) = -.5
//SQRT(2) =1.414, 3 = 1.732,

#endif /* SRC_AXIS_H_ */
