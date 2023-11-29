# sasso-carta-forbici 
29/11/2023 (Primo programma realizzato)

FINALITA'
- Giocare tra due giocatori al "sasso carta forbici" tramite ausilio della linea di comando 
per inserire i dati di input.

CONCETTI TEORIA
- definizione di tipo tramite enum
- uso istruzioni switch e if
- validazione tipo stringa in input

PROBLEMATICHE
- I dati di input vengono controllati osservando solamente il primo carattere della stringa scritta, quindi "sorbici" verrebbe interpretato come sasso.
- La lunghezza dei dati di input viene limitata nella scanf tramite "%8s", tuttavia nel caso si inserisse una stringa di lunghezza maggiore a 7 caratteri (+ il carattere 'O') la parte in eccesso diventa input della scanf successiva (non da problemi al programma poiche' per la validazione darebbe comunque "Scelta non valida", a meno che l'iniziale non sia 's', 'f' o 'c').
- Non so se e' stato efficiente l'utilizzo del tipo di dato definito scelta_t oppure si sarebbe potuto evitare. Inoltre forse avrei potuto dichiare inizialmente come costanti i numeri -1, 0, 1, 2 che ricorrono spesso nel programma.
