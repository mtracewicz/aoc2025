#include <stdio.h>
#include <stdlib.h>

long long invalidIds(long long low, long long high)
{
    long long sum = 0;
    char buffer[100];
    for (long long i = low; i <= high; i++)
    {
        int len = sprintf(buffer, "%lld", i);
        if (len % 2 == 1)
        {
            continue;
        }
        int ctrl = 0;
        for (int x = 0, y = len / 2; x < len / 2; x++, y++)
        {
            if (buffer[x] != buffer[y])
            {
                ctrl = 1;
                break;
            }
        }
        if (ctrl == 0)
        {
            #ifdef DEBUG
                printf("%lld\n", i);
            #endif
            sum += i;
        }
    }
    return sum;
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

    long long result = 0;
    long long low, high;
    while (fscanf(f, "%lld-%lld,", &low, &high) == 2)
    {
        result += invalidIds(low, high);
    }
    printf("%lld\n", result);
    fclose(f);
}
