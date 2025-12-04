#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	long long result = 0;
	char line[100];
	while (fscanf(f, "%s", line) == 1)
	{
		int last[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
		int second_to_last[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
		for (int i = strlen(line) - 1; i >= 0; i--)
		{
			int n = line[i] - '0' - 1;
			if (last[n] == -1)
			{
				last[n] = i;
			}
			else if (second_to_last[n] == -1)
			{
				second_to_last[n] = i;
			}
		}

		for (int i = 8; i >= 0; i--)
		{
			int ctrl = 0;
			if (last[i] != -1)
			{
				for (int j = 8; j >= 0; j--)
				{
					if (last[j] != -1 && ((i!=j && last[j] > last[i]) || (i==j && second_to_last[i] != -1)))
					{
						result += 10 * (i+1) + j + 1;
						ctrl = 1;
						printf("%d\n", 10 * (i + 1) + j + 1);
						break;
					}
				}
				if (ctrl == 1)
				{
					break;
				}
			}
		}
	}
	printf("result = %lld\n", result);
	fclose(f);
}
