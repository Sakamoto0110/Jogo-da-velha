#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int c1,c2,c3,c4,c5,c6,c7,c8,c9;
int jogada = 0;
int iniciador;
int x = 0;
int nowPlaying = 0;
int input = 0;
int slotData[10];
int slotStatus[10];

void inputGame(){
    switch(input){
        case 1:
            slotStatus[input] = 1;
            if ( nowPlaying == 1 ){
                c1 = 88;
            }
            if ( nowPlaying == 2 ){
                c1 = 79;
            }
        break;
        case 2:
            slotStatus[input] = 1;
            if ( nowPlaying == 1 ){
                c2 = 88;
            }
            if ( nowPlaying == 2 ){
                c2 = 79;
            }
        break;
        case 3:
            slotStatus[input] = 1;
            if ( nowPlaying == 1 ){
                c3 = 88;
            }
            if ( nowPlaying == 2 ){
                c3 = 79;
            }
        break;
        case 4:
            slotStatus[input] = 1;
            if ( nowPlaying == 1 ){
                c4 = 88;
            }
            if ( nowPlaying == 2 ){
                c4 = 79;
            }
        break;
        case 5:
            slotStatus[input] = 1;
            if ( nowPlaying == 1 ){
                c5 = 88;
            }
            if ( nowPlaying == 2 ){
                c5 = 79;
            }
        break;
        case 6:
            slotStatus[input] = 1;
            if ( nowPlaying == 1 ){
                c6 = 88;
            }
            if ( nowPlaying == 2 ){
                c6 = 79;
            }
        break;
        case 7:
            slotStatus[input] = 1;
            if ( nowPlaying == 1 ){
                c7 = 88;
            }
            if ( nowPlaying == 2 ){
                c7 = 79;
            }
        break;
        case 8:
            slotStatus[input] = 1;
            if ( nowPlaying == 1 ){
                c8 = 88;
            }
            if ( nowPlaying == 2 ){
                c8 = 79;
            }
        break;
        case 9:
            slotStatus[input] = 1;
            if ( nowPlaying == 1 ){
                c9 = 88;
            }
            if ( nowPlaying == 2 ){
                c9 = 79;
            }
        break;
    }
}

void Player1(){
    printf("[PLAYER 1] = X");
    printf("\nDigite a casa desejada: \n");
    printf(":>");
    AGAIN:scanf("%d", &input);
    if (slotStatus[input] != 1 ){
        inputGame();
    }else{
        printf("\nCasa ja ocupada, por favor tente novamente: ");
        goto AGAIN;
    }
}
void Player2(){
    printf("[PLAYER 2] = O");
    printf("\nDigite a casa desejada: \n");
    printf(":>");
    AGAIN:scanf("%d", &input);
    if (slotStatus[input] != 1 ){
        inputGame();
    }else{
        printf("\nCasa ja ocupada, por favor tente novamente: ");
        goto AGAIN;
    }
}
void bot(){
    Sleep(1000);
    input = rand()%9;
    if (input != 1 ){
        inputGame();
    }
}
int winConditions(){
    if ( c1 + c2 + c3 == 237){
        x = -1;
    }
    if ( c1 + c2 + c3 == 264){
        x = -1;
    }
    if ( c4 + c5 + c6 == 237){
        x = -1;
    }
    if ( c4 + c5 + c6 == 264){
        x = -1;
    }
    if ( c7 + c8 + c9 == 237){
        x = -1;
    }
    if ( c7 + c8 + c9 == 264){
        x = -1;
    }
    if ( c1 + c4 + c7 == 237){
        x = -1;
    }
    if ( c1 + c4 + c7 == 264){
        x = -1;
    }
    if ( c2 + c5 + c8 == 237){
        x = -1;
    }
    if ( c2 + c5 + c8 == 264){
        x = -1;
    }
    if ( c3 + c6 + c9 == 237){
        x = -1;
    }
    if ( c3 + c6 + c9 == 264){
        x = -1;
    }
    if ( c1 + c5 + c9 == 237){
        x = -1;
    }
    if ( c1 + c5 + c9 == 264){
        x = -1;
    }
    if ( c3 + c5 + c7 == 237){
        x = -1;
    }
    if ( c3 + c5 + c7 == 264){
        x = -1;
    }

}

void engine(){
    if ( iniciador == 1){
        if ( jogada % 2 == 0){
            nowPlaying = 1;
            Player1();
        }
        if ( jogada % 2 > 0){
            nowPlaying  = 2;
            Player2();
        }
    }
    if ( iniciador == 2){
        if ( jogada % 2 == 0){
            nowPlaying = 2;
            Player2();
        }
        if ( jogada % 2 > 0){
            nowPlaying = 1;
            Player1();
        }
    }
}

void display(){
    system("cls");
    printf("\n\n");
    printf("   %c | %c | %c  \n", c1, c2, c3);
    printf("   ---------\n");
    printf("   %c | %c | %c  \n", c4, c5, c6);
    printf("   ---------\n");
    printf("   %c | %c | %c  \n", c7, c8, c9);
    printf("\n\n");
    printf("jogada: %d", jogada);
    printf("\n");
    if ( x != -1){
        engine();
    }
}
void display1(){
    system("cls");
    printf("\n\n");
    printf("   %c | %c | %c  \n", c1, c2, c3);
    printf("   ----------\n");
    printf("   %c | %c | %c  \n", c4, c5, c6);
    printf("   ----------\n");
    printf("   %c | %c | %c  \n", c7, c8, c9);
    printf("\n\n");
    printf("jogada: %d", jogada);
    printf("\n");
}
int main()
{
    int c;
    char gameState[20] = "running";
        printf("Quem gostaria de iniciar?\n");
        printf("1 para Player1\n");
        printf("2 para Player2\n");
        scanf("%d", &iniciador);
        if ( iniciador == 1){
            nowPlaying = 1;
        }
        if ( iniciador == 2){
            nowPlaying = 2;
        }
        for ( jogada = 0;jogada <= 10 ; jogada++){
            display();
            winConditions();
            if ( x == -1){
                display();
                if ( iniciador == 1){
                    if (jogada%2 == 0){
                        printf("Player 1 ganhou.");
                    }else{
                        printf("Player 2 ganhou.");
                    }
                }
                if (iniciador == 2){
                    if (jogada%2 == 0){
                        printf("Player 2 ganhou.");
                    }else{
                        printf("Player 1 ganhou.");
                    }
                }
                break;
            }
        }
        getch();
    return 0;
}
