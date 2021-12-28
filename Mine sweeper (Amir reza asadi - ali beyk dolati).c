#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>

int n1, n2, n3;

void printBoard(char bz[n1][n1]);
int check(char bz[n1][n1]);
int game(int x, int y, int mn[n1][n1], char bz[n1][n1]);
void loading (void);
void ending(void);
void display_welcome();
void print_mineboard();

void main(void)
{
    int i,j,x,y,r;

    system ("color 09");
    display_welcome();
    printf("\n");
    printf("which level you want to play ? \n\n\n");
    printf(" 'b' for Beginner \n 'i' for Intermediate \n 'e' for Expert \n");

    char a;
    a = getchar();
    switch (a){
        case 'b':
            n1 = 9;
            n2 = 9;
            n3 = 10;
            break;
        case 'i':
            n1 = 16;
            n2 = 16;
            n3 = 40;
            break;
        case 'e':
            n1 = 30;
            n2 = 16;
            n3 = 99;
            break;

    }


    int mn[n1][n2],m[n3];
    char bz[n1][n2];
    system("pause");

    srand(time(NULL));
    for(i = 0; i < n3; i++){
        m[i] = rand() % (n1 * n2) + 1;
        for(j = 0; j < i; j++)
            if(m[i] == m[j])
                i--;
    }
    for(i = 0; i < n1; i++)
        for(j = 0; j < n2; j++){
            mn[i][j] = 0;
            bz[i][j] = '-';
        }
    for(i = 0; i < n3; i++)
        mn[m[i] % n1][m[i] / n2] = 1;
    printBoard(bz);
    while(1)
    {

        printBoard(bz);
        printf("1) clean map.\n2) I found a mine.\n? ");
        scanf("%d",&r);
        printf("(x , y):\n  x: ");
        scanf("%d",&y); y--;
        printf("  y: ");
        scanf("%d",&x); x--;
        if(r == 1 && bz[x][y] != '?')
        {
            if(mn[x][y]){
                bz[x][y] = '*';
                for(i = 0; i < n1; i++)
                    for(j = 0; j < n2; j++)
                        if(mn[i][j] && bz[i][j] != '*')
                            bz[i][j] = '*';

            printBoard(bz);
            printf("                   you lost\n");
            system("color 04");

            break;
		}
		game(x,y,mn,bz);
		if(check(bz))
            break;
        }
        else if(r == 2 && bz[x][y] == '-'){
           bz[x][y] = '?';
        }
        else if(r == 2 && bz[x][y] == '?'){
           bz[x][y] = '-';
        }
    }
}



void printBoard(char bz[n1][n2])
{
    int i,j;
    for(i = 0; i < n1; i++){
        for(j = 0; j < n2; j++)
            printf("%4c",bz[i][j]);
        printf("\n\n");
	 }
}

int check(char bz[n1][n2])
{
    int i,j,k = 0;
    for(i = 0; i < n1; i++)
        for(j = 0; j < n2; j++)
            if(bz[i][j] == '-' || bz[i][j] == '?')
                k++;
    if(k == n3){
        for(i = 0; i < n1; i++)
        for(j = 0; j < n2; j++)
            if(bz[i][j] == '-' || bz[i][j] == '?')
                bz[i][j] = 'G';
        printBoard(bz);
        ending();
        return 1;
    }
    return 0;
}

int game(int x, int y, int mn[n1][n2], char bz[n1][n2])
{
    int k = 0,i,j;
    if (x < n2-1 && mn[x+1][y]) k++;
    if (y < n1-1 && mn[x][y+1]) k++;
    if (x > 0 && mn[x-1][y]) k++;
    if (y > 0 && mn[x][y-1]) k++;
    if (x < n2-1 && y > 0 && mn[x+1][y-1]) k++;
    if (x > 0 && y < n1-1 && mn[x-1][y+1]) k++;
    if (x < n2-1 && y < n1-1 && mn[x+1][y+1]) k++;
    if (x > 0 && y > 0 && mn[x-1][y-1]) k++;
    bz[x][y] = k + 48;

    if (k == 0){
        if (x < n2-1 && bz[x+1][y] == '-') game(x+1,y,mn, bz);
        if (y < n1-1 && bz[x][y+1] == '-') game(x,y+1,mn, bz);
        if (x > 0 && bz[x-1][y] == '-') game(x-1,y,mn, bz);
        if (y > 0 && bz[x][y-1] == '-') game(x,y-1,mn,bz);
        if (x < n2-1 && y > 0 && bz[x+1][y-1] == '-') game(x+1, y-1, mn, bz);
        if (x > 0 && y < n1-1 && bz[x-1][y+1] == '-') game(x-1, y+1, mn, bz);
        if (x < n2-1 && y < n1-1 && bz[x+1][y+1] == '-') game(x+1, y+1, mn, bz);
        if (x > 0 && y > 0 && bz[x-1][y-1] == '-') game(x-1, y-1, mn, bz);
    }
}


// Displays the welcome message
void display_welcome()
{
    loading();
    system("pause");
    printf("\n\n\t\t\t-----------------------Welcome to Minesweeper!---------------------------\n\n\n");
    Sleep(200) ;
    printf("Written by:\n\t Amir Reza Asadi - Ali Beik Dolati\n\n\n\nOstad:\n\tRahimi\n\n\n\n\n\n\n");
    Sleep(200) ;
    printf("\t\t\t\t\t\t\tMabani 96\n\n\n\n\n");
    Sleep(200) ;

}


void loading (void)
{

    system ("color 06") ;

    printf("\n\n\n\n\n                      ##      ## ######## ##        ######   #######  ##     ## ######## \n") ;
    Sleep (200) ;
    printf("                      ##  ##  ## ##       ##       ##    ## ##     ## ###   ### ##       \n") ;
    Sleep (200) ;
    printf("                      ##  ##  ## ##       ##       ##       ##     ## #### #### ##       \n") ;
    Sleep (200) ;
    printf("                      ##  ##  ## ######   ##       ##       ##     ## ## ### ## ######   \n") ;
    Sleep (200) ;
    printf("                      ##  ##  ## ##       ##       ##       ##     ## ##     ## ##       \n") ;
    Sleep (200) ;
    printf("                      ##  ##  ## ##       ##       ##    ## ##     ## ##     ## ##       \n") ;
    Sleep (200) ;
    printf("                       ###  ###  ######## ########  ######   #######  ##     ## ######## \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
    Sleep(2500) ;

}


void ending(void)
{
system("color 05") ;
printf("\n                                                   ##      ##   ####   ##    ##\n") ;
Sleep (200) ;
printf("                                                     ##  ##  ##    ##    ###   ##\n") ;
Sleep (200) ;
printf("                                                     ##  ##  ##    ##    ## ## ##\n") ;
Sleep (200) ;
printf("                                                     ##  ##  ##    ##    ##  ####\n") ;
Sleep (200) ;
printf("                                                     ##  ##  ##    ##    ##   ###\n") ;
Sleep (200) ;
printf("                                                      ###  ###    ####   ##    ##") ;
printf("\n\n\n\n\n\n\n\n\n\n");
}






