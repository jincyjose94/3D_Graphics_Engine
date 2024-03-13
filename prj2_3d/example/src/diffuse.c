/*
 * axis.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Jincy
 */


#include "diffuse.h"
#include "forest.h"


#include "3d_lcd__api.h"
#include "board.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void draw3Daxis () {
	// fill background color with BLACK color
	fillrect(0, 0, ST7735_TFTWIDTH, ST7735_TFTHEIGHT, BLACK);

	/*coordinates to define world, view and projection */
	const points_3d world_coordinates[points_threed_coord] = {
	    {0, 0, 0},
	    {120, 0, 0},
	    {0, 120, 0},
	    {0, 0, 120}
	};
	points_3d view_coordinates[points_threed_coord];
	projection_2d projection_coordinates[points_threed_coord];

	/* placing camera at (200, 200, 200) */
	float camera_coordinate[3] = {100, 100, 100};
	float xe = camera_coordinate[0];
	float ye = camera_coordinate[1];
	float ze = camera_coordinate[2];

	/* calculate sin and cosine values and rho */
	float rho = sqrt(pow(xe, 2) + pow(ye, 2) + pow(ze, 2));
	float calc_temp = sqrt(pow(xe, 2) + pow(ye, 2));
	float sin_theta = ye / calc_temp;
	float cos_theta = xe / calc_temp;
	float sin_phi = calc_temp / rho;
	float cos_phi = ze / rho;

	/*transformation pipeline*/
	for(int i=0;i<points_threed_coord;i++){
		view_coordinates[i].x = (-world_coordinates[i].x * sin_theta) + (world_coordinates[i].y * cos_theta);
		view_coordinates[i].y = (-world_coordinates[i].x * cos_theta * cos_phi) +
				(-world_coordinates[i].y * cos_phi *sin_theta) + (world_coordinates[i].z * sin_phi);
		view_coordinates[i].z = (-world_coordinates[i].x * cos_theta * sin_phi) +
						(-world_coordinates[i].y * sin_phi *cos_theta) + (-world_coordinates[i].z * cos_phi) + rho;
	}

	/* projection */
	for(int i=0;i<points_threed_coord;i++){
		projection_coordinates[i].xp = (view_coordinates[i].x * D) / view_coordinates[i].z;
		projection_coordinates[i].yp = (view_coordinates[i].y * D) / view_coordinates[i].z;
	}

	/* convert to physical coordinate and draw line */
	drawLine(projection_coordinates[0].xp,projection_coordinates[0].yp,
			projection_coordinates[1].xp,projection_coordinates[1].yp,RED);
	drawLine(projection_coordinates[0].xp,projection_coordinates[0].yp,
				projection_coordinates[2].xp,projection_coordinates[2].yp,GREEN);
	drawLine(projection_coordinates[0].xp,projection_coordinates[0].yp,
				projection_coordinates[3].xp,projection_coordinates[3].yp,BLUE);
}

void drawCube () {
	// fill background color with BLACK color
//	fillrect(0, 0, ST7735_TFTWIDTH, ST7735_TFTHEIGHT, BLACK);

	/*coordinates to define world, view and projection */
	const points_3d world_coordinates[points_cube] = {

	    {50, 50, 50},
		{0, 50, 50},
	    {0, 0, 50},
	    {50, 0, 50},
		{50, 50, 0},
		{0, 50, 0},
		{0, 0, 0},
		{50, 0, 0}
//	    {50, 50, 115},
//		{-50, 50, 115},
//	    {-50, -50, 115},
//	    {50, -50, 115},
//		{50, 50, 15},
//		{-50, 50, 15},
//		{-50, -50, 15},
//		{50, -50, 15}

	};
	points_3d view_coordinates[points_cube];
	projection_2d projection_coordinates[points_cube];

	/* placing camera at (200, 200, 200) */
	float camera_coordinate[3] = {100, 100, 100};
	float xe = camera_coordinate[0];
	float ye = camera_coordinate[1];
	float ze = camera_coordinate[2];

	/* calculate sin and cosine values and rho */
	float rho = sqrt(pow(xe, 2) + pow(ye, 2) + pow(ze, 2));
	float calc_temp = sqrt(pow(xe, 2) + pow(ye, 2));
	float sin_theta = ye / calc_temp;
	float cos_theta = xe / calc_temp;
	float sin_phi = calc_temp / rho;
	float cos_phi = ze / rho;

	/*transformation pipeline*/
	for(int i=0;i<points_cube;i++){
		view_coordinates[i].x = (-world_coordinates[i].x * sin_theta) + (world_coordinates[i].y * cos_theta);
		view_coordinates[i].y = (-world_coordinates[i].x * cos_theta * cos_phi) +
				(-world_coordinates[i].y * cos_phi *sin_theta) + (world_coordinates[i].z * sin_phi);
		view_coordinates[i].z = (-world_coordinates[i].x * cos_theta * sin_phi) +
						(-world_coordinates[i].y * sin_phi *cos_theta) + (-world_coordinates[i].z * cos_phi) + rho;
	}

	/* projection */
	for(int i=0;i<points_cube;i++){
		projection_coordinates[i].xp = (view_coordinates[i].x * D) / view_coordinates[i].z;
		projection_coordinates[i].yp = (view_coordinates[i].y * D) / view_coordinates[i].z;
	}

	/* convert to physical coordinate and draw top */
	for(int i=0;i<4;i++){
		drawLine(projection_coordinates[i].xp,projection_coordinates[i].yp,
					projection_coordinates[(i+1)%4].xp,projection_coordinates[(i+1)%4].yp,RED);
//		lcddelay(400);
	}

	//RED TOP SIDE FILL
	float diff_color;
	for(int y=0;y<=50;y++){
//		int d_int = 300 - (((y/15)+ 1)*50);
		for(int x=0;x<=50;x++){
//			int d_int = (((x + y)/25 + 2) * 50);
//			int d_int = ((x+y+1)/10)*15 + 100;
			int d_int = 208 - ((x*y)/12);
			points_3d diffuse_pt3d;
			projection_2d diffuse_pt2d;
			diffuse_pt3d.x=x;
			diffuse_pt3d.y=y;
			diffuse_pt3d.z=50;
			diffuse_pt2d = points3dto2d(diffuse_pt3d);
			// RED DIFFUSE
			diff_color = getDiffuseColor(diffuse_pt3d, d_int);
			int x1 = diffuse_pt2d.xp + (ST7735_TFTWIDTH/2);
			int y1 = -diffuse_pt2d.yp + (ST7735_TFTHEIGHT/2);
			drawPixel(x1, y1, diff_color);
		}
	}

//	float diff_color4[4];
//	points_3d diffuse_pt3d;
//	projection_2d diffuse_pt2d;
//	for(int i=0;i<4;i++){
//		diffuse_pt3d = world_coordinates[i];
//		diffuse_pt2d = projection_coordinates[i];
//		// RED DIFFUSE
//		diff_color = getDiffuseColor(diffuse_pt3d);
//		int x1 = diffuse_pt2d.xp + (ST7735_TFTWIDTH/2);
//		int y1 = -diffuse_pt2d.yp + (ST7735_TFTHEIGHT/2);
//		drawPixel(x1, y1, diff_color);
//		diff_color4[i] = getDiffuseColor(diffuse_pt3d);
//	 }
//	for(int i=projection_coordinates[1].xp;i<projection_coordinates[3].xp;i++){
//		for(int j=projection_coordinates[2].yp;j<projection_coordinates[3].yp;j++){
//			LineDDA(projection_coordinates[0].xp, i, projection_coordinates[0].yp, j, diff_color4[i%12]);
//		}
//	}


	/* convert to physical coordinate and draw lines to connect top and base */
	for(int i=0;i<4;i++){
		if(i!=2){
			drawLine(projection_coordinates[i].xp,projection_coordinates[i].yp,
							projection_coordinates[(i+4)].xp,projection_coordinates[(i+4)].yp,GREEN);

		}
//			lcddelay(50);

	}
	projection_2d pr_2d_s1[] = {projection_coordinates[0],projection_coordinates[1],projection_coordinates[5],projection_coordinates[4]};
	colorPolygon(pr_2d_s1, PURPLE);
	projection_2d pr_2d_s2[] = {projection_coordinates[3],projection_coordinates[0],projection_coordinates[4],projection_coordinates[7]};
	colorPolygon(pr_2d_s2, MAGENTA);


	/*linear decoration algorithm */
	float bx = 0, by = 0, tx = 0, ty = 20, bz, tz;
	bz = bx;
	tz = tx;
	by = 50;
	ty = 50;
	bx = by;
	tx = ty;
//	points_3d tree_3db = {bx,by,bz};
//	points_3d tree_3dt = {tx,ty,tz};
	points_3d tree_3db = {25,50,0};
	points_3d tree_3dt = {25,50,10};
	projection_2d tree_2d[2];
	tree_2d[0] = points3dto2d(tree_3db);
	tree_2d[1] = points3dto2d(tree_3dt);
//	fillrect(0, 0, ST7735_TFTWIDTH/2, ST7735_TFTHEIGHT, DARK_BROWN);
//	fillrect(ST7735_TFTWIDTH/2, 0, ST7735_TFTWIDTH, ST7735_TFTHEIGHT, LIGHTBLUE);

	createTrees (tree_2d[0].xp, tree_2d[0].yp, tree_2d[1].xp, tree_2d[1].yp);
//	createTrees (0, 0, 0, 7);


}

void LineDDA(float X1, float X2, float Y1, float Y2, uint32_t color)
{
  double dx=(X2-X1);
  double dy=(Y2-Y1);
  double steps;
  float xInc,yInc,x=X1,y=Y1;

  /* Find out whether to increment x or y */
  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;

  /* Plot the first point */
  int x1 = x + (ST7735_TFTWIDTH/2);
  int y1 = -y + (ST7735_TFTHEIGHT/2);
  drawPixel(x1, y1, color);

  int k;
  /* For every step, find an intermediate vertex */
  for(k=0;k<steps;k++)
  {
    x+=xInc;
    y+=yInc;
    x1 = x + (ST7735_TFTWIDTH/2);
    y1 = -y + (ST7735_TFTHEIGHT/2);
    drawPixel(x1, y1, color);
  }
}

int getDiffuseColor(points_3d Pi, int df)
{
	uint32_t print_diffuse_color;
	points_3d ls = {-5, 60, 100};
	int diff_red, diff_green, diff_blue;
	float new_red, new_green, new_blue,
	r1=0.9, r2=0.0, r3=0.0,
	scaling = 1000;
	float_t temp = ((ls.z - Pi.z)/sqrt(pow((ls.x - Pi.x),2)+ pow((ls.y - Pi.y),2)+ pow((ls.z - Pi.z),2)))/
			(pow((ls.x - Pi.x),2)+ pow((ls.y - Pi.y),2)+ pow((ls.z - Pi.z),2));
	temp *= scaling;
	diff_red = r1 * temp * df;
	diff_green = r2 * temp;
	diff_blue = r3 * temp;
//	diff_red = ((diff_red - 0.00156)*235/0.0016)+40;
//		diff_green = ((diff_green - 0.00156)*255/0.0016);
//		diff_green = max(diff_green,0);
//		diff_blue = ((diff_blue - 0.00156)*255/0.0016);
//		diff_blue = max(diff_blue,0);
	new_red = (diff_red << 16);
	new_green = (diff_green << 8);
	new_blue = (diff_blue);
	print_diffuse_color = new_red + new_green +new_blue;
	return print_diffuse_color;
}

projection_2d points3dto2d (points_3d Pi){
	points_3d view_coordinates;
	projection_2d projection_coordinates;

	/* placing camera at (200, 200, 200) */
	float camera_coordinate[3] = {100, 100, 100};
	float xe = camera_coordinate[0];
	float ye = camera_coordinate[1];
	float ze = camera_coordinate[2];

	/* calculate sin and cosine values and rho */
	float rho = sqrt(pow(xe, 2) + pow(ye, 2) + pow(ze, 2));
	float calc_temp = sqrt(pow(xe, 2) + pow(ye, 2));
	float sin_theta = ye / calc_temp;
	float cos_theta = xe / calc_temp;
	float sin_phi = calc_temp / rho;
	float cos_phi = ze / rho;

	/*transformation pipeline*/

		view_coordinates.x = (-Pi.x * sin_theta) + (Pi.y * cos_theta);
		view_coordinates.y = (-Pi.x * cos_theta * cos_phi) +
				(-Pi.y * cos_phi *sin_theta) + (Pi.z * sin_phi);
		view_coordinates.z = (-Pi.x * cos_theta * sin_phi) +
						(-Pi.y * sin_phi *cos_theta) + (-Pi.z * cos_phi) + rho;

	/* projection */
		projection_coordinates.xp = (view_coordinates.x * D) / view_coordinates.z;
		projection_coordinates.yp = (view_coordinates.y * D) / view_coordinates.z;

		return projection_coordinates;
}


// Function to check if a point is inside the polygon (basic implementation)
int pointInPolygon(int x, int y, projection_2d vertices[]) {
    int crossings = 0;
    for (int i = 0; i < 4; i++) {
        int j = (i + 1) % 4;
        if (((vertices[i].yp > y) != (vertices[j].yp > y)) &&
            (x < (vertices[j].xp - vertices[i].xp) * (y - vertices[i].yp) / (vertices[j].yp - vertices[i].yp) + vertices[i].xp)) {
            crossings++;
        }
    }
    return (crossings % 2 == 1);
}

float lambdaShadow(float Zi,float Zs){
	float s_lambda;
	s_lambda = -Zi/(Zs-Zi);
	return s_lambda;
}

points_3d getShadowPoints(points_3d Pi, points_3d Ps, float lambda){
	points_3d shadow_pt;
	shadow_pt.x = (Pi.x + (lambda*(Ps.x-Pi.x)));
	shadow_pt.y = (Pi.y + (lambda*(Ps.y-Pi.y)));
	shadow_pt.z = (Pi.z + (lambda*(Ps.z-Pi.z)));
	return shadow_pt;
}

void drawShadow(){

	/*coordinates to define world, view and projection */
		const points_3d cube_shadow[points_cube] = {

			    {50, 50, 50},
				{0, 50, 50},
			    {0, 0, 50},
			    {50, 0, 50},
				{50, 50, 0},
				{0, 50, 0},
				{0, 0, 0},
				{50, 0, 0}

		};
		points_3d view_coordinates[points_cube];
		projection_2d projection_coordinates[points_cube];

		/*point light source*/
		points_3d ls = {-5, 60, 100};

		/*normal vector*/
		points_3d n = {0, 0, 1};

		/*shadow points*/
		points_3d sh_points[5];

		float lambda_s = lambdaShadow(cube_shadow[0].z, ls.z);
		for(int i=0; i<4; i++){
			sh_points[i] = getShadowPoints(cube_shadow[i], ls, lambda_s);
		}

		/* placing camera at (200, 200, 200) */
		float camera_coordinate[3] = {100, 100, 100};
		float xe = camera_coordinate[0];
		float ye = camera_coordinate[1];
		float ze = camera_coordinate[2];

		/* calculate sin and cosine values and rho */
		float rho = sqrt(pow(xe, 2) + pow(ye, 2) + pow(ze, 2));
		float calc_temp = sqrt(pow(xe, 2) + pow(ye, 2));
		float sin_theta = ye / calc_temp;
		float cos_theta = xe / calc_temp;
		float sin_phi = calc_temp / rho;
		float cos_phi = ze / rho;

		/*add 5th element of shadow point as light source for computation efficiency*/
		sh_points[4]=ls;

		/*transformation pipeline*/
		for(int i=0;i<5;i++){
			view_coordinates[i].x = (-sh_points[i].x * sin_theta) + (sh_points[i].y * cos_theta);
			view_coordinates[i].y = (-sh_points[i].x * cos_theta * cos_phi) +
					(-sh_points[i].y * cos_phi *sin_theta) + (sh_points[i].z * sin_phi);
			view_coordinates[i].z = (-sh_points[i].x * cos_theta * sin_phi) +
							(-sh_points[i].y * sin_phi *cos_theta) + (-sh_points[i].z * cos_phi) + rho;
		}

		/* projection */
		for(int i=0;i<5;i++){
			projection_coordinates[i].xp = (view_coordinates[i].x * D) / view_coordinates[i].z;
			projection_coordinates[i].yp = (view_coordinates[i].y * D) / view_coordinates[i].z;
		}


		/* convert to physical coordinate and draw shadow */
		for(int i=0;i<4;i++){
			drawLine(projection_coordinates[i].xp,projection_coordinates[i].yp,
				projection_coordinates[(i+1)%4].xp,projection_coordinates[(i+1)%4].yp,GREY1);
//			lcddelay(400);
		}
		colorPolygon(projection_coordinates, GREY1);

		/*draw rays*/
		projection_2d sh_rays;
		for(int i=0;i<4;i++){
			drawLine(projection_coordinates[4].xp,projection_coordinates[4].yp,
				projection_coordinates[i].xp,projection_coordinates[i].yp,WHITE);
//			lcddelay(400);
		}

}


void colorPolygon(projection_2d pr[], uint32_t color){
	 int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
	    for (int i = 0; i < 4; i++) {
	        minX = (minX< pr[i].xp)?minX:pr[i].xp;
	        minY = (minY< pr[i].yp)?minY:pr[i].yp;
	        maxX = (maxX> pr[i].xp)?maxX:pr[i].xp;
	        maxY = (maxY> pr[i].yp)?maxY:pr[i].yp;
	    }

	    // Iterate through the bounding box and draw pixels inside the polygon
	    for (int y = minY + 1; y < maxY; y++) {
	        for (int x = minX + 1; x < maxX; x++) {
	            // Check if the point is inside the polygon using a point-in-polygon algorithm
	            // You might need to implement a point-in-polygon algorithm here
	            if (pointInPolygon(x, y, pr)) {
	            	int x1 = x + (ST7735_TFTWIDTH/2);
	            	int y1 = -y + (ST7735_TFTHEIGHT/2);
	                drawPixel(x1, y1, color);
	            }
	        }
	    }

}
