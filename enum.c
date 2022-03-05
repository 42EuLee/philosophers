//#include "philosopher.h"
#include <stdio.h>

enum e_status { eating, sleeping, thinking, die };

int	main(int argc, char **argv)
{
	enum e_status	state;

	state = eating;
	printf("enum: %d\n\n", state);
	state = sleeping;
	printf("enum: %d\n\n", state);
	state = thinking;
	printf("enum: %d\n\n", state);
}
