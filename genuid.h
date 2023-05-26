#ifndef GENUID_H
#define GENUID_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


int generate_uid_str(const char*, char*);

/* Example
    char bf[30] = { "A1-A1-A1-A1-A1-A1-A1-A1-A1-A1" };
    int stat = 0;

    for (int x = 0; x < 4000; x++)
    {
        printf("\n\r");
        stat = generate_uid_str(bf, bf);
        if (!stat)
        {
            for (int x = 0; x < sizeof(bf); x++)
            {
                printf("%c", bf[x]);
            }
        }
        else
        {
            printf("Error - %d", stat);
            while (1);
        }
    }

*/
#endif