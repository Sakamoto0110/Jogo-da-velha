#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

    int menu;
    int x2 = 0;
    int x1 = 0;
    int x;
    int c; /* contador   */
    int i; /* contador   */
    int z;
    char palavras[200] = "";
    int ascii[20];
    int palavras1;
    int status_palavra = 0;
    int tam_palavra_inserida;
    char palavra_real[20] = "";
    char palavra_secreta[20] = "";
    char letra1[20];
    int main_engine = 1;
    int engine;
    int exit_code;
    int ui;
    int dificuldade ;
    int vida = 6;
    int erros;
    int acertos_erros[50];
    char letras_erradas[40] = "  ";
    char stick1[3]= " ";
    char stick2[3]= " ";
    char stick3[3]= " ";
    char stick4[3]= " ";
    char stick5[3]= " ";
    char stick6[3]= " ";
    char key1[5] = "menu";
    char espacos[100];
    char vidas[18] = "<3 <3 <3 <3 <3 <3 ";
    char espacos1[100];
    char espacos2[100] = "               ";

    int numeroLetrasDif = 0;
    int ascii1[20];
    char key2[5] = "admin";
    int x3 = 0;



void death_animation(){
    if ( erros == 0){
        if ( dificuldade != 0){
            strcpy(espacos1, "           ");
        }
        if ( dificuldade == 0){
            strcpy(espacos1, "           ");
        }
    }
    if ( erros == 1 ){
        strcpy(stick1, "o");
        strcpy(vidas, "<3 <3 <3 <3 <3    ");
        if ( dificuldade != 0){
            strcpy(espacos1, "         ");
        }
        if ( dificuldade == 0){
            strcpy(espacos1, "         ");
        }
    }
    if ( erros == 2 ){
        strcpy(stick2, "|");
        strcpy(vidas, "<3 <3 <3 <3       ");
         if ( dificuldade != 0){
            strcpy(espacos1, "       ");
        }
        if ( dificuldade == 0){
            strcpy(espacos1, "       ");
        }
    }
    if ( erros == 3 ){
        strcpy(stick3, "/");
        strcpy(vidas, "<3 <3 <3          ");
         if ( dificuldade != 0){
            strcpy(espacos1, "     ");
        }
        if ( dificuldade == 0){
            strcpy(espacos1, "     ");
        }
    }
    if ( erros == 4 ){
        strcpy(stick4, "\\");
        strcpy(vidas, "<3 <3             ");
         if ( dificuldade != 0){
            strcpy(espacos1, "   ");
        }
        if ( dificuldade == 0){
            strcpy(espacos1, "   ");
        }
    }
    if ( erros == 5 ){
        strcpy(stick5, "/");
        strcpy(vidas, "<3                ");
         if ( dificuldade != 0){
            strcpy(espacos1, " ");
        }
        if ( dificuldade == 0){
            strcpy(espacos1, " ");
        }
    }
    if ( erros == 6 ){
        strcpy(stick6, "\\");

    }
}
void reset_all(){
     menu = "";
     x1 = 0;
     x2 = 0;
     x = 0;
     c = 0;
     i = 0;
     tam_palavra_inserida = 0;
     palavra_real[20] = "";
     palavra_secreta[20] = "";
     letra1[20] = "";
     status_palavra = 0;
     engine = 1;
     exit_code;
     ui = 1;
     vida = 6;
     erros = 0;
     acertos_erros[50] = "";
     strcpy(letras_erradas, "  ");
     strcpy(stick1, " ");
     strcpy(stick2, " ");
     strcpy(stick3, " ");
     strcpy(stick4, " ");
     strcpy(stick5, " ");
     strcpy(stick6, " ");
     strcpy(vidas, "<3 <3 <3 <3 <3 <3 ");
     //strcpy(espacos1, "            ");
     espacos[100] = "";

     numeroLetrasDif = 0;
}
void num_erro(){
    i = 0;
    for (c = 0; c < tam_palavra_inserida; c++){
        if ( acertos_erros[c] == 1){
            i = i + 1;
        }
        if ( acertos_erros[c] == 0){
            i = (i + 2);
        }
    }
    for ( c = 0; c < tam_palavra_inserida; c++){
        acertos_erros[c] = 0;
    }
        if ( i == (2*tam_palavra_inserida)){
            erros = erros + 1;
            strncat(letras_erradas, letra1, 1);
            strncat(letras_erradas, " ", 2);
        }
}
void exit_codes(){
    if (exit_code == 001){
        loose();
    }
    if (exit_code == 002){
        win();
    }
    if (exit_code == 005){
        menu = 1;
    }
}
void palavra_codigo(){
    x = 0;
    x = 29 - ((tam_palavra_inserida * 2) - 1);
    if ( dificuldade != 2 ){
        x = x - 6;
    }
    if ( dificuldade == 2){
        x = x - 6;
    }
    for ( c = 0; c <= x; c++){
        strcat(espacos, " ");
    }
    printf(" |                                                               ");
    for (c = 0; c < tam_palavra_inserida; c++){
        printf(" %c",palavra_secreta[c]);
    }
    printf("%s", espacos);
    printf("__|__    |");
    printf("\n");
    strcpy(espacos,"");
}
void win(){
    system("cls");
    printf("Parabens, voce ganhou\n\n\n");
    printf("       ___________      \n");
    printf("      '._==_==_=_.'     \n");
    printf("      .-\\:      /-.    \n");
    printf("     | (|:.     |) |    \n");
    printf("      '-|:.     |-'     \n");
    printf("        \\::.    /      \n");
    printf("         '::. .'        \n");
    printf("           ) (          \n");
    printf("         _.' '._        \n");
    printf("        '-------'       \n\n");
    main_engine = 1;
}
void loose(){
    system("cls");
    printf("\n  Poxa, voce foi enforcado!\n");
    printf("  A palavra era ** %s **\n\n", palavra_real);
    printf("      _______________         \n");
    printf("     /               \\       \n");
    printf("    /                 \\      \n");
    printf("  //                   \\/\\  \n");
    printf("  \\|   XXXX     XXXX   | /   \n");
    printf("   |   XXXX     XXXX   |/     \n");
    printf("   |   XXX       XXX   |      \n");
	printf("   |                   |      \n");
	printf("   \\__      XXX      __/     \n");
	printf("     |\\     XXX     /|       \n");
	printf("     | |           | |        \n");
	printf("     | I I I I I I I |        \n");
	printf("     |  I I I I I I  |        \n");
	printf("     \\_             _/       \n");
	printf("       \\_         _/         \n");
	printf("         \\_______/           \n");
}
void ler_arquivo(){
    srand(time(NULL));
    while ( status_palavra !=1 ){
        strcpy(palavras,"");
        x2 = 0;
        z = rand() %10000;
        FILE * fp = fopen("palavras.txt", "r");
        for ( c = 0; c < z; c++){
            fscanf(fp, "%s", palavras);
        }
        tam_palavra_inserida = strlen(palavras);
        for ( c = 0; c < tam_palavra_inserida; c++){
            x1 = 0;
            ascii[c] = palavras[c];
            if (ascii[c] < 123){
                x1 = 0;
                if (ascii[c] > 96){
                    x2 = x2 + 1;
                }
            }
        }
        if ( x2 == tam_palavra_inserida ){
            numLetras();
            switch (dificuldade){
        case 0:
            if ( numeroLetrasDif == 4){
                strcpy(palavra_real, palavras);
                status_palavra = 1;
            }
            break;
            case 1:
                if ( numeroLetrasDif == 5){
                    strcpy(palavra_real, palavras);
                    status_palavra = 1;
            }
            break;
            case 2:
                if ( numeroLetrasDif >= 6){
                    strcpy(palavra_real, palavras);
                    status_palavra = 1;
            }
            break;
            }
        }
        fclose(fp);
        }
    tam_palavra_inserida = strlen(palavra_real);
    for ( c = 0; c < tam_palavra_inserida; c++){
        palavra_secreta[c] ='_';
    }
}
void print_dificuldade1(){
    switch (dificuldade){
        case 0:
            printf(" | Dificuldade: Facil                                                                              |");
            break;
        case 1:
            printf(" | Dificuldade: Media                                                                              |");
            break;
        case 2:
            printf(" | Dificuldade: Dificil                                                                            |");
            break;
        default:
            printf("-------------");
            break;
    }
}
void print_dificuldade(){
    switch (dificuldade){
        case 0:
            printf("Facil");
            break;
        case 1:
            printf("medio");
            break;
        case 2:
            printf("dificil");
            break;
        default:
            printf("-------------");
            break;
    }
}
void menu_dificuldade(){
    printf(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
    printf("|                                                                                                 |\n");
    printf("|                                       Forca v1.12                                               | \n");
    printf("|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n\n");
    printf("                                   ESCOLHA A DIFICULDADE                                     \n");
    printf("\n                                     0)     FACIL                                         \n\n");
    printf("\n                                     1)     MEDIO                                         \n\n");
    printf("\n                                     2)    DIFICIL                                         \n\n");
    scanf("");
    scanf("%d", &dificuldade);

}
void menu_principal(){
    system("cls");
    status_palavra = 0;
    ler_arquivo();
    system("cls");
    printf(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
    printf("|                                                                                                 |\n");
    printf("|                                       Forca v1.12                                               | \n");
    printf("|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n\n");
    printf("                                      MENU PRINCIPAL                                     \n");
    printf("\n                                  1)       Jogar                                       \n");
    printf("\n                                  2)    Dificuldade                                       \n");
    printf("\n                                  3)     Creditos                                        \n");
    printf("\n                                  4)       Sair                                         \n");
    printf("\n\n");
    printf("Dificuldade selecionada: ");
    print_dificuldade();
    printf("\n");
    scanf("%d", &menu);
}
void creditos(){
    system("cls");
    printf(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
    printf("|                                                                                                 |\n");
    printf("|                                       Forca v1.12                                               | \n");
    printf("|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n\n");
    printf("                                         CREDITOS                                     \n");
    printf("\n\n");
    printf("                               Desenvolvimento:_____________Rafael Sakamoto                              \n\n");
    printf("                               Art&design:__________________Rafael Sakamoto                                  \n\n");
    printf("                               Acabamento:__________________Rafael Sakamoto                                      \n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    system("pause");
}
void numLetras(){
        numeroLetrasDif = 0;
        for ( c = 0; c <= tam_palavra_inserida; c++){
            ascii[c] = palavras[c];
            ascii1[c] = palavras[c];
        }
        for (c = 0; c <= tam_palavra_inserida; c++){
            for (i = 0; i <= tam_palavra_inserida; i++){
                if (ascii[c] == ascii1[i]){
                    if ( c != i ){
                        x3 = x3 + 1;
                    }
                }
            }
            numeroLetrasDif = tam_palavra_inserida - x3;
            x3 = 0;
        }
}

int main(void){
    while (main_engine == 1){
        if (exit_code != 005){
            menu_principal();
        }
        switch (menu){
            case 1:
                engine = 1;
                erros = 0;
                i = 0;
                ui = 1;
                for ( c = 0; c < 50; c++){
                    acertos_erros[c] = 0;
                }
                system("cls");
                printf("\n");
                ler_arquivo();

                while ( ui == 1) {
                    system("cls");
                    death_animation();
                    if ( erros != 6 ) {
                        engine = 1;
                    }
                    printf("\n\n\n\n");
                    printf("                                                           Insira \"menu\" para voltar para o menu \n");
                    printf(" +-------------------------------------------------------------------------------------------------+\n");
                    printf(" | Vidas: %s%s                                                        |\n", vidas, espacos2);
                    print_dificuldade1();
                    printf("\n");
                    printf(" |                                                                               +----------+      |\n");
                    printf(" |                                                                               |          |      |\n");
                    printf(" |                                                                               |          |      |\n");
                    printf(" |                                                                               %s          |      |\n", stick1);
                    printf(" |                                                                              %s%s%s         |      |\n", stick3, stick2, stick4);
                    printf(" |                                                                              %s %s         |      |\n", stick5, stick6);
                    printf(" |                                                                                          |      |\n");
                    printf(" |                                                                                          |      |\n");
                    printf(" |  Tentativas anteriores:                                                                  |      |\n");
                    printf(" |      %s%s                                                                       |      |\n", letras_erradas, espacos1);
                    palavra_codigo();
                    printf(" |                                                                                       /     \\   |\n");
                    printf(" |                                                                                      /_______\\  |\n");
                    printf(" +-------------------------------------------------------------------------------------------------+\n");
                    printf("                            ");
                    if ( erros == 6 ){
                        ui = 0;
                        exit_code = 001;
                    }
                    if ( strcmp(palavra_real,palavra_secreta) == 0){
                        exit_code = 002;
                        engine = 0;
                        ui = 0;
                    }
                    while ( engine == 1 && erros < 6 ){
                        engine = 0;
                        printf("          ");
                        printf(" digite uma letra     ");
                        scanf("%s", &letra1);
                        printf("\n");
                        if ( strcmp(letra1,key2) == 0){
                            printf("\n\n%s", palavra_real);
                            printf("\n%s\n\n", palavra_secreta);
                            system("pause");
                        }
                        if ( strcmp(letra1, key1) == 0 ){
                            engine = 0;
                            ui = 0;
                        }
                        for (c = 0; c <= tam_palavra_inserida; c++){
                            if ( letra1[0] == palavra_real[c]){
                            palavra_secreta[c] = letra1[0];
                            acertos_erros[c] = 1;
                            }
                        }
                        num_erro();
                    }
                }
                exit_codes();
                printf("\n\n");
                system("pause");
                break;
            case 2:
                system("cls");
                menu_dificuldade();
                break;
            case 3:
                creditos();
                break;
            case 4:
                system("cls");
                printf("nooooooooo, por favor nao va\n");
                printf("La em baixo e escuro\n");
                printf("Tenho medo do escuro ;-;");
                printf("\n\n\n\n");
                printf("           _     __ \n");
                printf("      _   |_|   | _|\n");
                printf("     |_|       | |  \n");
                printf("      _        | |  \n");
                printf("     |_|       | |_  \n");
                printf("                |__| \n");
                printf("\n\n\n\n");
                system("pause");
                main_engine = 0;
                break;
            break;
            default:
                printf("\nerror 000000x4\nInvalid input\nProcess will be terminated.\n");
                main_engine = 0;
                break;
            }
            reset_all();
        }
}







