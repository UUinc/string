#ifndef UI_H
#define UI_H

void rect(int width, int height, int x, int y)
{
    int i,j;

    gotoxy(x,y);
    //Top
    printf("\xDA");
    for(i=0; i<width; i++)
        printf("\xC4");
    printf("\xBF\n");

    gotoxy(x,wherey());
    //Left and Right
    for(i=0; i<height; i++)
    {
        printf("\xB3");
        for(j=0; j<width; j++)
            printf(" ");
        printf("\xB3\n");

        gotoxy(x,wherey());
    }

    //Bottom
    printf("\xC0");
    for(i=0; i<width; i++)
        printf("\xC4");
    printf("\xD9");
}

void Title(int x, int y)
{
    gotoxy(x,y);
    puts(" _ _ _          _     _");
    gotoxy(x,++y);
    puts("' ) ) )        ' )   /            /");
    gotoxy(x,++y);
    puts(" / / /    , ,   / / /   __ __  __/");
    gotoxy(x,++y);
    puts("/ ' (_ / (_/_  (_(_/   (_)/ (_(_/_ ");
    gotoxy(x,++y);
    puts("          /");
    gotoxy(x,++y);
    puts("         '");
}

void Desktop(int x, int y)
{
    gotoxy(x,y);
    puts("                _________________");
    gotoxy(x,++y);
    puts("               /                /|");
    gotoxy(x,++y);
    puts("              /                / |");
    gotoxy(x,++y);
    puts("             /________________/ /|");
    gotoxy(x,++y);
    puts("          ###|      ____      |//|");
    gotoxy(x,++y);
    puts("         #   |     /   /|     |/.|");
    gotoxy(x,++y);
    puts("        #  __|___ /   /.|     |  |_______________");
    gotoxy(x,++y);
    puts("       #  /      /   //||     |  /              /|                  ___");
    gotoxy(x,++y);
    puts("      #  /      /___// ||     | /              / |                 / \\ \\");
    gotoxy(x,++y);
    puts("      # /______/!   || ||_____|/              /  |                /   \\ \\");
    gotoxy(x,++y);
    puts("      #| . . .  !   || ||                    /  _________________/     \\ \\");
    gotoxy(x,++y);
    puts("      #|  . .   !   || //      ________     /  /\\________________  {   /  }");
    gotoxy(x,++y);
    puts("      /|   .    !   ||//~~~~~~/   0000/    /  / / ______________  {   /  /");
    gotoxy(x,++y);
    puts("     / |        !   |'/      /9  0000/    /  / / /             / {   /  /");
    gotoxy(x,++y);
    puts("    / #\\________!___|/      /9  0000/    /  / / /_____________/___  /  /");
    gotoxy(x,++y);
    puts("   / #     /_____\\/        /9  0000/    /  / / /_  /\\_____________\\/  /");
    gotoxy(x,++y);
    puts("  / #                      ``^^^^^^    /   \\ \\ . ./ / ____________   /");
    gotoxy(x,++y);
    puts(" +=#==================================/     \\ \\ ./ / /.  .  .  \\ /  /");
    gotoxy(x,++y);
    puts(" |#                                   |      \\ \\/ / /___________/  /");
    gotoxy(x,++y);
    puts(" #                                    |_______\\__/________________/");
    gotoxy(x,++y);
    puts(" |                                    |               |  |  / /");
    gotoxy(x,++y);
    puts(" |                                    |               |  | / /");
    gotoxy(x,++y);
    puts(" |                                    |       ________|  |/ /________");
    gotoxy(x,++y);
    puts(" |                                    |       ________|  |/ /________ ");
    gotoxy(x,++y);
    puts(" |                                    |      /_______/    \\_________/\\ ");
    gotoxy(x,++y);
    puts(" |                                    |     /        /  /           \\ ) ");
    gotoxy(x,++y);
    puts(" |____________________________________|    /OO^^^^^^/  / /^^^^^^^^^OO\\) ");
}
#endif