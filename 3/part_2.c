#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
#define LOG_DEBUG(...) printf(__VA_ARGS__)
#else
#define LOG_DEBUG(...) do {} while (0)
#endif

typedef struct Pair
{
	int value;
	int index;
} Pair;

Pair GetMaxInRange(char *buffer, int low, int high)
{
	int currentMaxValue = -1;
	int currentMaxIndex = -1;

	for (int i = low; i < high; i++)
	{
		if ((buffer[i] - '0') > currentMaxValue)
		{
			currentMaxValue = buffer[i] - '0';
			currentMaxIndex = i;
		}
	}
	return (Pair){.value = currentMaxValue, .index = currentMaxIndex};
}

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

	char line[101]; // Lines can be up to 100 characters long
	long long result = 0;
	long long helper[12] = {
		100000000000,
		10000000000,
		1000000000,
		100000000,
		10000000,
		1000000,
		100000,
		10000,
		1000,
		100,
		10,
		1};

	while (fscanf(f, "%s", line) == 1)
	{
		int low = 0;
		int high = strlen(line) - 11; // The highest number must be 12 digits
		long long tmp = 0;
		for (int i = 0; i < 12; i++)
		{
			Pair res = GetMaxInRange(line, low, high);
			low = res.index + 1;
			high = strlen(line) - (10 - i); // After We have found the max, We the length of the target is reduced by one
			tmp += helper[i] * res.value;
		}
		LOG_DEBUG("%lld\n", tmp);
		result += tmp;
	}
	printf("result = %lld\n", result);
	fclose(f);
	return 0;
}
