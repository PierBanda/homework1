# homework 1

Homework 1 per il corso di laboratorio ciberfisico
di Pierluigi Bandino id VR400076


Funzionamento:
------------------------------------------------------------------------------------------------------------------------------
il pogetto è composto da tre nodi:

info_pub

pubblica il nome l'età e il corso di studio di una persona i cui dati sono salvati in my_database.h
i dati di una persona vengono pubblicati tramitte un messaggio del tipo info_msg tramite il topic info_persona

info_msg è formato da 
* string name -> nome di una persona
* uint8 age -> la sua età
* string corso -> il corso che sta frequentando

option

il nodo option indica a viewer la forma in cui verrà stampato il messaggio distribuito da info_pub
con un messaggio composto solo da una stringa tramite il topic viewOption
le opzioni possibili sono:
* a all
* n solo il nome
* e solo l'età
* c solo il corso

di default il viewer stampa tutti i dati (a)

l'opzione è configurabile tramite console dall'utente

viewer
stampa nella console i dati ricevuti nella forma stabilita

rappresentazione grafica dei nodi:
------------------------------------------------------------------------------------------------------------------------------
![Schema dei nodi](https://github.com/PierBanda/homework1/blob/master/img/rosgraph.png)

esempio esecuzione
------------------------------------------------------------------------------------------------------------------------------
![esempio esecuzione](https://github.com/PierBanda/homework1/blob/master/img/Schermata%20del%202018-04-14%2011-39-40.png)

verranno aperti due nuovi terminali uno per options e per viewer tramite tastiera si potrà cambiare l'opzione nel terminale 
seguendo le istruzione che compaiono a schermo.
Il nodo info_pub stamperà eventuali messaggi di errore nella console da dove avete eseguito il laucher (vedi in basso per il laucher)

installazione:
------------------------------------------------------------------------------------------------------------------------------

da console entrare nel propio workspase di catkin con 

`cd catkin_ws/src/`

e clonare homework1 con 

`git clone https://github.com/PierBanda/homework1.git`

tornare in catkin 

`cd ..`

ed eseguire il makefile con

`catkin_make --pkg homework1`

esecuzione:
------------------------------------------------------------------------------------------------------------------------------

si può eseguire il tutto con il laucher digitando

`roslaunch homework1 homework1.launch`
