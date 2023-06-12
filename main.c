#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "socket/socketServer.h"

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

// Endgame horizontal
static int endgameH (char p, char m[4][4])
{
    int ret=1;

    for (int i=1; i < 4; i++) {
        ret = 1;
        for (int j=1; j < 4; j++) {
            if (m[i][j] != p) {
                ret = 0;
                break;
            }
        }
        if (ret == 1) {
            printf("Player %c Wins!!\n", p);
            break;
        }
    }

    return ret;
}

// Endgame vertical
static int endgameV (char p, char m[4][4])
{
    int ret=1;

    for (int i=1; i < 4; i++) {
        ret = 1;
        for (int j=1; j < 4; j++) {
            if (m[j][i] != p) {
                ret = 0;
                break;
            }
        }
        if (ret == 1) {
            printf("Player %c Wins!!\n", p);
            break;
        }
    }

    return ret;
}

// Endgame diagonal left
static int endgameDL (char p, char m[4][4])
{
    int ret=1;

    for (int i=1; i < 4; i++) {
        if (m[i][i] != p) {
            ret = 0;
        }
    }

    if (ret == 1)
        printf("Player %c Wins!!\n", p);

    return ret;
}

// Endgame diagonal right
static int endgameDR (char p, char m[4][4])
{
    int ret=1;

    if (m[1][3] != p || m[2][2] != p || m[3][1] != p)
        ret = 0;

    if (ret == 1)
        printf("Player %c Wins!!\n", p);

    return ret;
}

int main(int argc, char* argv[])
{
    socketServer();
    // line and column
    int l=0, c=0;
    // matrix and player
    char m[4][4], p='x';
    memset(&m, ' ', sizeof(m));

    int end=0;
    int online=1;

    // Drawing board
    printf(" _______\n");
    printf("|       |\n");
    printf("|  | |  |\n");
    printf("|  | |  |\n");
    printf("|  | |  |\n");
    printf("|_______|\n");
    printf("\n\n");

    while(!end) {
        printf("--> Player %c:\n", p);

        while (1) {
            printf("Line: ");
            if (online == 0) {
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

        }

        m[l][c]=p;

        play(p, m);

        end = endgameH(p, m) || endgameV(p,m) || endgameDL(p,m) || endgameDR(p,m);

        // Alternating player
        if (p == 'x') {
            p = 'O';
        } else {
            p = 'x';
        }
    }

    return 0;
}
