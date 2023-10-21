    /*autore : Amedeo Piras*/
    #include <stdio.h>
    #include <time.h>
    #include <math.h>
    #include <stdlib.h>
    main(){
        char menu;
        int i;
        int j;
        while(1)
        {
            fflush(stdin);
            system("cls");
            printf("menu: \na. tris \nb. roulet russa \nc. morra cinese \nd. black jack \nx. uscire\n\ncosa scegli? ");
            scanf("%c",&menu);
            switch(menu)
            {
                case 'a': printf("\nusi esercizio 1\n");
                    char board[3][3];
                    void printBoard() {
                    printf("-------------\n");
                    for(i = 0; i < 3; i++) 
                    {
                        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
                        printf("-------------\n");
                    }
                    }
                    int checkWin()
                    {
                        for(i = 0; i < 3; i++)
                        {
                            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
                            {
                                return 1;
                            }
                            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') 
                            {
                                return 1; 
                            }
                        }
                        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') 
                        {
                                return 1;
                        }
                        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
                        {
                            return 1;
                        }
                        return 0; 
                    }
                    for (i = 0; i < 3; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            board[i][j] = ' ';
                        }
                    }
                    int player = 1; 
                    int row, col;
                    printf("Benvenuto nel gioco del Tris!\n");
                    do 
                    {
                        printf("Giocatore %d, inserisci riga (0, 1, 2) e colonna (0, 1, 2) separate da un invio: ", player);
                        scanf("%d %d", &row, &col);
                        if (board[row][col] == ' ') 
                        {
                            if (player == 1) 
                            {
                                board[row][col] = 'X';
                                player = 2;
                            } 
                                else 
                                {
                                    board[row][col] = 'O';
                                       player = 1;
                                }
                                printBoard();
                        } 
                        else 
                        {
                            printf("Casella occupata. Riprova.\n");
                        }
                    } 
                    while (!checkWin());
                    printf("Giocatore %d ha vinto! Congratulazioni!\n", player == 1 ? 2 : 1);
                    ;getch();break;
            
                case 'b': printf("\nusi esercizio 2\n");
                    int colpi, giocatore = 1, posizione = 1;
                    srand(time(0));
                    printf("Benvenuti alla Roulette Russa!\n");
                    while (1) 
                    {
                        printf("Giocatore %d, premi INVIO per sparare...", giocatore);
                        getchar(); 
                        colpi = rand() % 6+1;
                        printf("Click...");
                        clock_t start_time = clock();
                        while (clock() < start_time + CLOCKS_PER_SEC);
                        if (posizione == colpi) 
                        {
                            printf("BANG! Il giocatore %d ha perso!\n", giocatore);
                               break;
                        } 
                        else 
                        {
                            printf("Il giocatore %d è al sicuro.\n", giocatore);
                        }
                        giocatore = (giocatore % 2) + 1;
                        posizione = (posizione % 6) + 1;
                    }
                    ;getch();break;
                        
                case 'c': printf("\nusi esercizio 3\n");
                    int sceltaGiocatore1, sceltaGiocatore2, sceltaMacchina;
                     printf("Benvenuti a Sasso, Carta, Forbice!\n");
                    printf("1 - Sasso, 2 - Carta, 3 - Forbice\n");
                    printf("Scegli se vuoi giocare contro un altro giocatore (1) o contro la macchina (2): ");
                    int modalitaGioco;
                        scanf("%d", &modalitaGioco);
                        if (modalitaGioco == 1)
                        {
                            printf("Giocatore 1, fai la tua scelta: ");
                            scanf("%d", &sceltaGiocatore1);
                            printf("Giocatore 2, fai la tua scelta: ");
                            scanf("%d", &sceltaGiocatore2);
                            if ((sceltaGiocatore1 == 1 && sceltaGiocatore2 == 3) ||
                                (sceltaGiocatore1 == 2 && sceltaGiocatore2 == 1) ||
                                (sceltaGiocatore1 == 3 && sceltaGiocatore2 == 2)) 
                            {
                                    printf("Complimenti, Giocatore 1 ha vinto!\n");
                            } 
                            else if ((sceltaGiocatore2 == 1 && sceltaGiocatore1 == 3) ||
                                   (sceltaGiocatore2 == 2 && sceltaGiocatore1 == 1) ||
                                   (sceltaGiocatore2 == 3 && sceltaGiocatore1 == 2))
                            {
                                printf("Complimenti, Giocatore 2 ha vinto!\n");
                            } 
                            else
                            {
                                printf("Pareggio, nessun vincitore.\n");
                            }
                        } 
                        else if (modalitaGioco == 2)
                        {
                            srand(time(0));
                            printf("Giocatore, fai la tua scelta: ");
                            scanf("%d", &sceltaGiocatore1);
                            sceltaMacchina = rand() % 3 + 1;
                            printf("Hai scelto: %d\n", sceltaGiocatore1);
                            printf("La macchina ha scelto: %d\n", sceltaMacchina);
                            if ((sceltaGiocatore1 == 1 && sceltaMacchina == 3) ||
                                (sceltaGiocatore1 == 2 && sceltaMacchina == 1) ||
                                (sceltaGiocatore1 == 3 && sceltaMacchina == 2))
                            {
                                printf("Complimenti, hai vinto!\n");
                            }
                            else if (sceltaGiocatore1 == sceltaMacchina)
                            {
                                printf("Pareggio, nessun vincitore.\n");
                            } else
                            {
                                printf("Mi dispiace, hai perso. Ritenta!\n");
                            }
                        }
                    else
                    {
                        printf("Modalità non valida. Scegli 1 per giocare contro un altro giocatore o 2 per giocare contro la macchina.\n");
                    }
                    getch();break;
                
                case 'd': 
                    srand(time(NULL));
                    int numGiocatori;
                        printf("Benvenuto al gioco del Blackjack!\n");
                        printf("Scegli il numero di round (1, 2 o 3): ");
                        scanf("%d", &numGiocatori);
                        while (numGiocatori < 1 || numGiocatori > 3)
                        {
                            printf("Numero di round non valido. Inserisci 1, 2 o 3: ");
                            scanf("%d", &numGiocatori);
                        }
                        for (i = 0; i < numGiocatori; i++)
                        {
                            int carta1 = rand() % 11 + 1;
                            int carta2 = rand() % 11 + 1;
                            int bank = rand()%21+1;
                            int punteggio = carta1 + carta2;
                                printf("\nround %d, le tue carte sono: %d e %d\n", i + 1, carta1, carta2);
                                printf("\nIl tuo punteggio totale è: %d\n", punteggio);
                                printf("\nIl punteggio del tavolo è: %d\n", bank);
                                char risposta;
                                printf("\nVuoi pescare un'altra carta? (y/n): ");
                                scanf(" %c", &risposta);
                                while (risposta == 'y')
                                {
                                    int nuova_carta = rand() % 11 + 1;
                                    punteggio += nuova_carta;
                                    printf("\nHai pescato una carta con valore %d\n", nuova_carta);
                                    printf("\nIl tuo punteggio totale è: %d\n", punteggio);
                                    if (punteggio > 21)
                                    {
                                        printf("\nMi dispiace, hai superato 21. Hai perso!\n");
                                        break;
                                    }
                                    printf("\nVuoi pescare un'altra carta? (y/n): ");
                                    scanf(" %c", &risposta);
                                }
                                printf("Il tuo punteggio finale è: %d\n", punteggio);
                        }
                                getch();break;
                
                            case 'x': getch(); 
                            return(0);break;
                                
                            default: printf("\nfuori,ascolta la consegna\n");
            }
        }
            printf("\n\n");
    }
    
    