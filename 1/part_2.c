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
#ifdef DEBUG
		printf("%c%d -- %d\n", rotation, move, position);
#endif

		int previous_zero = position == 0;

		result += (move / 100);
		move %= 100;
		position += (rotation == 'R') ? move : -move;

		int swaped = 0;
		if (position < 0)
		{
			position += 100;
			swaped = 1;
		}

		if (position > 99)
		{
			position -= 100;
			swaped = 1;
		}

		if (position == 0 || (!previous_zero && swaped == 1))
		{
#ifdef DEBUG
			printf("Add: %c%d\n", rotation, move);
#endif
			result++;
		}
	}

	printf("%d\n", result);
	fclose(f);
}
