/*
 * screensaver.c
 *
 *  Created on: Oct 15, 2023
 *      Author: Checkout
 */
#define M_PI 3.141592653


#include "forest.h"

#include "3d_lcd__api.h"
#include "board.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
//	Tree treeNodes[210]; // Define an array of Tree instances
//	int current_index = 0;


XYPoint vtop(int x, int y){
	XYPoint xyp;
	x = x + (ST7735_TFTWIDTH/2);
	y = -y + (ST7735_TFTHEIGHT/2);
	xyp.xy[0]=x;
	xyp.xy[1]=y;

}


void forest(){
	// fill background color with BLUE AND GREEN color
//	printf("First Name: Jincy Jose\n");
//	printf("Last Name: Thottathil\n")
//	printf("SID: 016903978\n");
	fillrect(0, 0, ST7735_TFTWIDTH/2, ST7735_TFTHEIGHT, DARK_BROWN);
	fillrect(ST7735_TFTWIDTH/2, 0, ST7735_TFTWIDTH, ST7735_TFTHEIGHT, LIGHTBLUE);
//	createTrees (0, 10, 0, -10);
	createTrees (-10, 0, 10, 0);

//	drawLine (-10, 50, 10, 50, RED);
	createTrees (-10, 20, 10, 20);

//	for (int i =0; i<3; i++){
//		createTrees (0, -10, 0, 10);
//	}
//	int rand_bx1 = rand()%64;
//	int rand_by1 = rand()%80;
	for(int i=0;i<1;i++){
		int randomValue = rand() - RAND_MAX / 2;
		int rand_bx1 = randomValue % (ST7735_TFTWIDTH/2);
		randomValue = rand() - RAND_MAX / 2;
		int rand_by1 = randomValue % (ST7735_TFTHEIGHT/2);

		createTrees (rand_bx1, rand_by1, rand_bx1+20, rand_by1);

	}
	for(int i=0;i<1;i++){
			int randomValue =RAND_MAX / 2 - rand();
			int rand_bx1 = randomValue % (ST7735_TFTWIDTH/2);
			randomValue = RAND_MAX / 2 - rand();
			int rand_by1 = randomValue % (ST7735_TFTHEIGHT/2);

//			createTrees (rand_bx1, rand_by1, rand_bx1+20, rand_by1);

		}
}

void createTrees(int bx, int by, int tx, int ty){
//	static struct Tree* treeNodes[20];
	 struct Tree* treeNodes[20];

		struct Tree* root = createTree (0, bx, by, tx, ty);

		int i = 0;
		struct Tree* currentTree = NULL;
		treeNodes [i] = root;

		while(i > -1){
			printf("i = %d", i);
			currentTree = treeNodes[i];

			i--;

			if(currentTree->level == MAX_LEVEL){
				free(currentTree);
				continue;
			}


			currentTree->branch_center = createCentreBranch(currentTree->level, currentTree->base_x, currentTree->base_y, currentTree->tip_x, currentTree->tip_y);
			currentTree->branch_left = createLeftBranch(currentTree->level, currentTree->branch_center->base_x, currentTree->branch_center->base_y, currentTree->branch_center->tip_x, currentTree->branch_center->tip_y);
			currentTree->branch_right = createRightBranch(currentTree->level, currentTree->branch_center->base_x, currentTree->branch_center->base_y, currentTree->branch_center->tip_x, currentTree->branch_center->tip_y);

			i++;
			treeNodes[i] = currentTree->branch_right;
			i++;
			treeNodes[i] = currentTree->branch_center;
	        i++;
	        treeNodes[i] = currentTree->branch_left;
	        free(currentTree);

		}

//	    for (int i = 0; i < 50; i++) {
//	        treeNodes[i] = NULL;
//	    }

		 freeTree(root);


}



XYPoint getx_irt(int x, int y, float angle, int delta_x, int delta_y) {
	XYPoint translated;
	translated.xy[0] = x + delta_x;
	translated.xy[1] = y + delta_y;

	XYPoint rotated;
	rotated.xy[0] = (int)((cos(angle) *translated.xy[0]) - (sin(angle) * translated.xy[1]));
	rotated.xy[1] = (int)((sin(angle) * translated.xy[0]) + (cos(angle) * translated.xy[1]));

	XYPoint inverseTranslated;
	inverseTranslated.xy[0] = rotated.xy[0] - delta_x;
	inverseTranslated.xy[1] = rotated.xy[1] - delta_y;
	return  inverseTranslated;

}

//Creates a tree with only the base
Tree* createTree (int level, int bx, int by, int tx, int ty) {
	struct Tree* newTree = (struct Tree*)malloc(sizeof(struct Tree));
//	Tree* newTree = &treeNodes[current_index];
//	current_index++;
	newTree->level = level;
	newTree->base_x = bx;
	newTree->base_y = by;
	newTree->tip_x = tx;
	newTree->tip_y = ty;

	newTree->branch_center = NULL;
	newTree->branch_left = NULL;
	newTree->branch_right = NULL;

//	newTree->branch_center = createCentreBranch(level, bx, by, tx, ty);
//	newTree->branch_left = createLeftBranch(level, newTree->branch_center->base_x, newTree->branch_center->base_y, newTree->branch_center->tip_x, newTree->branch_center->tip_y);
//	newTree->branch_right = createRightBranch(level, newTree->branch_center->base_x, newTree->branch_center->base_y, newTree->branch_center->tip_x, newTree->branch_center->tip_y);
	drawLine(newTree->base_x, newTree->base_y, newTree->tip_x, newTree->tip_y, BLACK);

	return newTree;
}

//Creates the centre branch
Tree* createCentreBranch(int level, int bx, int by, int tx, int ty){
	struct Tree* newTree = (struct Tree*)malloc(sizeof(struct Tree));
//	Tree* newTree = &treeNodes[current_index];
//	current_index++;
	newTree->level = level + 1;
	newTree->base_x = tx;
	newTree->base_y = ty;
//	newTree->tip_x = tx + ((tx-bx)*LAMBDA_EIGHT);
//	newTree->tip_y = ty + ((ty-by)*LAMBDA_EIGHT);
	newTree->tip_x = tx + ((tx-bx)*0.6);
	newTree->tip_y = ty + ((ty-by)*0.6);
	newTree->branch_center = NULL;
	newTree->branch_left = NULL;
	newTree->branch_right = NULL;

	drawLine(newTree->base_x, newTree->base_y, newTree->tip_x, newTree->tip_y, DARK_GREEN);

	return newTree;

}

//Creates the left branch
Tree* createLeftBranch(int level, int bx, int by, int tx, int ty){
	struct Tree* newTree = (struct Tree*)malloc(sizeof(struct Tree));
//	Tree* newTree = &treeNodes[current_index];
//	current_index++;
	newTree->level = level + 1;

	float angle = 50 * (M_PI / 180.0); // Convert angle to radians
	int delta_x = -(bx);
	int delta_y = -(by);
//	int delta_x = -(tx - bx);
//	int delta_y = -(ty - by);

//	int delta_y = -(y_3-y_2);
	XYPoint new_points = getx_irt(tx, ty, angle, delta_x, delta_y);
	drawLine(bx,by,new_points.xy[0],new_points.xy[1],DARK_GREEN);

	newTree->base_x = bx;
	newTree->base_y = by;
	newTree->tip_x = new_points.xy[0];
	newTree->tip_y = new_points.xy[1];
	newTree->branch_center = NULL;
	newTree->branch_left = NULL;
	newTree->branch_right = NULL;
	return newTree;

}

//Creates the right branch
Tree* createRightBranch(int level, int bx, int by, int tx, int ty){
	struct Tree* newTree = (struct Tree*)malloc(sizeof(struct Tree));
//	Tree* newTree = &treeNodes[current_index];
//	current_index++;
	newTree->level = level + 1;

	float angle = -50 * (M_PI / 180.0); // Convert angle to radians
//	int delta_x = -(tx - bx);
//	int delta_y = -(ty - by);
	int delta_x = -(bx);
	int delta_y = -(by);

//	int delta_y = -(y_3-y_2);
	XYPoint new_points = getx_irt(tx, ty, angle, delta_x, delta_y);
	drawLine(bx,by,new_points.xy[0],new_points.xy[1],DARK_GREEN);

	newTree->base_x = bx;
	newTree->base_y = by;
	newTree->tip_x = new_points.xy[0];
	newTree->tip_y = new_points.xy[1];
	newTree->branch_center = NULL;
	newTree->branch_left = NULL;
	newTree->branch_right = NULL;
	return newTree;

}

void freeTree(struct Tree* node) {
    if (node == NULL) {
        return;
    }

    freeTree(node->branch_center);
    freeTree(node->branch_left);
    freeTree(node->branch_right);

    free(node);
}

