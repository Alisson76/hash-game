#include <stdio.h>

int main(int argc, char* argv[])
{
    int line=0;
    int column=0;

    // Drawing board
    printf(" _______\n");
    printf("|       |\n");
    printf("|  | |  |\n");
    printf("|  | |  |\n");
    printf("|  | |  |\n");
    printf("|_______|\n");
    printf("\n\n");

    printf("--> Player 1:\n");

    printf("Line: ");
    scanf("%d", &line);
    printf("Column: ");
    scanf("%d", &column);


    return 0;
}
