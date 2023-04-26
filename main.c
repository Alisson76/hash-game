#include <stdio.h>

int main(int argc, char* argv[])
{
    int line=0;
    int column=0;

    printf("--> Player 1:\n");

    printf("Line: ");
    scanf("%d", &line);
    printf("Column: ");
    scanf("%d", &column);

    // Drawing board
    printf("\n\n | | \n");
    printf(" | | \n");
    printf(" | | \n");


    return 0;
}
