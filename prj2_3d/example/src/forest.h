/*
 * screensaver.h
 *
 *  Created on: Oct 15, 2023
 *      Author: Checkout
 */

#ifndef SRC_FOREST_H_
#define SRC_FOREST_H_

#define LAMBDA_EIGHT 0.8
#define LAMBDA_TWO 0.2
#define MAX_LEVEL 8

typedef struct {
    float m[3][3];
} Matrix3x3;

typedef struct {
    float v[3];
} Vector3;

typedef struct {
    int xy[2];
} XYPoint;

// Define a structure for a stack item
typedef struct {
    int x1, y1, x2, y2, level;
} StackItem;

//void drawSquare(int x[4],int y[4], uint32_t color);
//void randomSquare(int lambda, uint32_t color);
//void childSquares(int lambda, int x[10][4],int y[10][4], uint32_t color);
void forest();
void drawTree();
XYPoint getx_irt(int x, int y, float angle, int delta_x, int delta_y);
XYPoint rotate(int x, int y, float angle);
void createTrees(int bx, int by, int tx, int ty);

// Define the tree node structure

typedef struct Tree {
	int base_x;
	int base_y;
	int tip_x;
	int tip_y;
	int level;

	struct Tree* branch_center;
	struct Tree* branch_left;
	struct Tree* branch_right;

} Tree;

Tree* createTree(int level, int bx, int by, int tx, int ty);
Tree* createCentreBranch(int level, int bx, int by, int tx, int ty);
Tree* createLeftBranch(int level, int bx, int by, int tx, int ty);
Tree* createRightBranch(int level, int bx, int by, int tx, int ty);

typedef struct TreeNode {
    int value;
    struct TreeNode* children[3];
} TreeNode;

TreeNode* createTreeNode(int value);
void freeTree(struct Tree* node);

#endif /* SRC_FOREST_H_ */
