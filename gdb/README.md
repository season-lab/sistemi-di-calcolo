Comandi `gdb`:
```
(gdb) start // si posiziona all'inizio del main
(gdb) file <nome_eseguibile> // per caricare un eseguibile
(gdb) run [<arg1> ...] // per lanciare l'esecuzione con eventuali argomenti
(gdb) quit // per uscire da gdb (o CTRL-d)
(gdb) break mio_file.c:20 // inserisco un breakpoint alla linea 20 di mio_file.c
(gdb) break mio_file.c:20 if x == 0 // breakpoint condizionale
(gdb) info break // per mostrare breakpoint attivi
(gdb) cont // per riprendere l'esecuzione normalmente dopo un breakpoint
(gdb) step // prosegue l'esecuzione di una singola istruzione
(gdb) print x // stampa il contenuto della variabile x nello stack frame corrente
(gdb) clear mio_file.c:20 // per eliminare breakpoint su una locazione di riferimento
(gdb) delete 1 // per eliminare il breakpoint contrassegnato come 1 da 'info break' 
(gdb) finish // esegue fino al termine della funzione corrente
(gdb) backtrace // elenco frame attivi
(gdb) frame n // selezione frame (utile per ispezionare lo stato)
(gdb) x/f addr // ispezionare dato ad indirizzo addr in base al formato f
(gdb) next // esegue una chiamata a funzione, bloccandosi dopo il suo ritorno
(gdb) where // mostra la posizione corrente nell'esecuzione
(gdb) list // mostra il contenuto del file sorgente che contiene la funzione corrente

Abbreviazioni:
- print -> p
- next -> n
- cont -> c
```

