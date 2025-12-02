#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		fprintf(stderr, "Invalid argument\n");
		exit(1);
	}

	char *file = (argc == 2) ? argv[1] : "input.txt";
	FILE *f = fopen(file, "r");
	if (f == NULL)
	{
		fprintf(stderr, "Could not open an input file\n");
		exit(1);
	}

	int result = 0;
	char rotation;
	int move;
	int position = 50;
	while (fscanf(f, "%c%d\n", &rotation, &move) == 2)
	{
		if (rotation == 'L')
		{
			position -= move;
		}
		else
		{
			position += move;
		}

		while (position < 0)
		{
			position = 100 + position;
		}

		if (position >= 100)
		{
			position %= 100;
		}

#ifdef DEBUG
		printf("%c%d -- %d\n", rotation, move, position);
#endif

		if (position == 0)
		{
			result++;
		}
	}
	printf("%d\n", result);
	fclose(f);
}
