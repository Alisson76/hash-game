#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static int validateInput (int l, int c, char m[4][4])
{
    int ret=0;

    if (l < 1 || l > 3) {
        printf("Line must be a number from 1 to 3\n\n");
        ret=1;
    }

    if (c < 1 || c > 3) {
        printf("Column must be a number from 1 to 3\n\n");
        ret=1;
    }

    if (m[l][c] != ' ') {
        printf("Already used Line %d and column %d, by %c\n", l, c, m[l][c]);
        ret=1;
    }

    return ret;
}

// Receives int line (l), int column (c) and char play (p, which can be x or o)
/*
static int play (int l, int c, char p, char m[3][3])
{
    printf(" _______\n");
    printf("|       |\n");
    for (int i=1; i < 4; i++) {
        if (l == i) {
            switch (c) {
                case 1:
                    printf("| %c| |  |\n", p);
                    break;
                case 2:
                    printf("|  |%c|  |\n", p);
                    break;
                case 3:
                    printf("|  | |%c |\n", p);
                    break;
            }
        } else {
            printf("|  | |  |\n");
        }
    }
    printf("|_______|\n");
    printf("\n\n");

    return 0;
}
*/
// Receives int line (l), int column (c) and char play (p, which can be x or o)
static int play (char p, char m[4][4])
{
    printf(" _______\n");
    printf("|       |\n");
    for (int i=1; i < 4; i++) {
        printf("| %c|%c|%c |\n", m[i][1], m[i][2], m[i][3]);
    }
    printf("|_______|\n");
    printf("\n\n");

    return 0;
}

int main(int argc, char* argv[])
{
    // line and column
    int l=0, c=0;
    char m[4][4];
    memset(&m, ' ', sizeof(m));

    int end=0;

    // Drawing board
    printf(" _______\n");
    printf("|       |\n");
    printf("|  | |  |\n");
    printf("|  | |  |\n");
    printf("|  | |  |\n");
    printf("|_______|\n");
    printf("\n\n");

    while(!end) {
        printf("--> Player 1:\n");

        while (1) {
            printf("Line: ");
            if (scanf("%d", &l) != 1) {
                fprintf(stderr, "Input is not a number\n");
                exit(EXIT_FAILURE);
            }
            printf("Column: ");
            if (scanf("%d", &c) != 1) {
                fprintf(stderr, "Input is not a number\n");
                exit(EXIT_FAILURE);
            }

            if (validateInput(l, c, m) == 0) {
                break;
            }

        }

        m[l][c]='x';

        play('x', m);

        //printf("--> Player 2:\n");

        //play(l, c, 'O');
    }

    return 0;
}
