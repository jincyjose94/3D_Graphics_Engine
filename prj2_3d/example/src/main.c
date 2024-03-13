#include "3d_lcd__api.h"
#include "board.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "diffuse.h"

int main(void)
{
	board_init();

	ssp0_init();

	lcd_init();


	draw3Daxis();
	drawShadow();
	drawCube ();
	while (1) {
	}
	return 0;
}

