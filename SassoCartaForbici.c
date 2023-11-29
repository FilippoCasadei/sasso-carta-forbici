/**********************************************/
/* programma per il gioco sasso carta forbici */
/**********************************************/

/*****************************/
/* inclusione delle librerie */
/*****************************/

#include <stdio.h>
#include <ctype.h>           /* fuznione tolower() */

/************************/
/* definizione dei tipi */
/************************/
/* NOTA: Era possibile, e forse anche piu' facile, non usare un tipo di dato definito */
typedef enum {sasso,
              carta,
              forbici} scelta_t;  /* possibilita' scelta gioco */

/********************************/
/* dichiarazione delle funzioni */
/********************************/

scelta_t acquisizione_scelta(int num_giocatore);

int comparazione(scelta_t scelta_giocatore1,
                 scelta_t scelta_giocatore2);

void stampa_risultato(int num_giocatore);

/******************************/
/* definizione della funzioni */
/******************************/

/* definizione della funzione main */
int main(void)
{
    /* dichiarazione delle variabili locali */
    scelta_t      scelta_giocatore1;    /* input: scelta del giocatore 1 */
    scelta_t      scelta_giocatore2;    /* input: scelta del giocatore 2 */
    int           risultato_partita;    /* output: risultato della partita*/

    
    do
    {   
        /* acquisizione dati di input */
        scelta_giocatore1 = acquisizione_scelta(1);
        scelta_giocatore2 = acquisizione_scelta(2);

        /* risultato della partita */
        risultato_partita = comparazione(scelta_giocatore1, scelta_giocatore2);
        
        /* stampa del vincitore */
        stampa_risultato(risultato_partita);
    }
    /* ripeti la partita se il risultato e' pareggio */
    while (risultato_partita == 0 || risultato_partita == -1);

    return 0;
}

/* definizione della funzione per l'acquisizione delle scelte dei giocatori */
scelta_t acquisizione_scelta(int num_giocatore)
{
    /* dichiarazione delle variabili locali alla funzione */
    char     input[8];  /* input: scelta del giocatore di tipo stringa */
    int      errore;    /* lavoro: se viene inizializzato a -1 riscontra errore */
    scelta_t scelta;    /* output: scelta del giocatore di tipo scelta_t */
    
    /* acquisizione scelta */
    do
    {
        errore = 0;
        printf("Giocatore %d: Scegli sasso, carta o forbici: ",
               num_giocatore);
        scanf("%8s",
              input);
        switch (tolower(input[0]))     /* prende solo il primo carattere della stringa in input e lo rende minuscolo */
        {
            case 's':
                scelta = sasso;
                break;
            case 'c':
                scelta = carta;
                break;
            case 'f':
                scelta = forbici;
                break;
            default:
                errore = -1;
                printf("Scelta non valida. Inserisci una parola tra quelle proposte\n");
                while (getchar() != '\n');    /* pulizia del buffer di input*/
        }
    }
    while (errore == -1);

    return scelta;
}

/* definizione della funzione per la comparazione tra le scelte dei giocatori */
int comparazione(scelta_t scelta_giocatore1,
                 scelta_t scelta_giocatore2)
{
    /* caso di pareggio */
    if (scelta_giocatore1 == scelta_giocatore2)
        return 0;
    
    /* caso in cui giocatore 1 sceglie sasso */
    else if (scelta_giocatore1 == sasso)
    {
        if (scelta_giocatore2 == forbici)
            return 1;
        else if (scelta_giocatore2 == carta)
            return 2;
    }
    
    /* caso in cui giocatore 1 sceglie forbici */
    else if (scelta_giocatore1 == forbici)
    {
        if (scelta_giocatore2 == carta)
            return 1;
        else if (scelta_giocatore2 == sasso)
            return 2;
    }
    
    /* caso in cui giocatore 1 sceglie carta */
    else if (scelta_giocatore1 == carta)
    {
        if (scelta_giocatore2 == sasso)
            return 1;
        else if (scelta_giocatore2 == forbici)
            return 2;
    }
    
    /* caso di errore (nessuno dei precedenti casi) */
    return -1;
}

/* definizione della funzione per la stampa del risultato */
void stampa_risultato(int risultato)
{
    switch(risultato)
    {
        /* caso di errore */
        case -1:
            printf("ERRORE GENERICO: fallita determinazione del risultato!!!");
            break;
        
        /* caso di pareggio */
        case 0:
            printf("PAREGGIO!!!\n");
            break;
        
        /* caso di vittoria giocatore 1 */
        case 1:
            printf("VITTORIA GIOCATORE 1!!!\n");
            break;
        
        /* caso di vittoria giocatore 2 */
        case 2:
            printf("VITTORIA GIOCATORE 2!!!\n");
            break;
    }
}
