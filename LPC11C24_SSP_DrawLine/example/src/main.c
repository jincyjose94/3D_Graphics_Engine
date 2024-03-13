#include "lcd__api.h"
#include "board.h"
#include <string.h>
#include <stdlib.h>

int main(void)
{
	board_init();

	ssp0_init();

	lcd_init();

	while (1) {

	}
	return 0;
}

