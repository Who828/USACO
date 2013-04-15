/*
USER: who8281
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char *line;
    size_t len = 0;
    int a, sum[2] = { 1, 1};
    int i, j;

    j = 0;
    while (getline(&line, &len, fin) != -1) {
        for(i=0; i < (strlen(line) - 1); i++) {
            a = line[i];
            a -= 64;
            sum[j] *= a;
        }
        j++;
    }

    if (sum[0] % 47 == sum[1] % 47)
        fprintf(fout, "GO\n");
    else
        fprintf(fout, "STAY\n");

    return 0;
}
