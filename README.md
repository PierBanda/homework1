# homework 1

Homework 1 per il corso di laboratorio ciberfisico
di Pierluigi Bandino id VR400076


Funzionamento:
------------------------------------------------------------------------------------------------------------------------------
il pogetto è composto da tre nodi:

info_pub

pubblica il nome l'età e il corso di studio di una persona i cui dati sono salvati in my_database.h
i dati di una persona vengono pubblicati tramitte un messaggio del tipo info_msg
info_msg formato da 
string name -> nome di una persona
uint8 age -> la sua età
string corso -> il corso che sta frequentando

option

il nodo option indica a viewer la forma in cui verrà stampato il messaggio distribuito da info_pub
le opzioni possibili sono:
a all
n solo il nome
e solo l'età
c solo il corso
di default il viewer stampa tutti i dati (a)
l'opzione è configurabile tramite console dall'utente

viewer
stampa nella console i dati ricevuti nella forma stabilita

rappresentazione grafica dei nodi:
------------------------------------------------------------------------------------------------------------------------------
esempio esecuzione
------------------------------------------------------------------------------------------------------------------------------
installazione:
------------------------------------------------------------------------------------------------------------------------------

da console entrare nel propio workspase di catkin con 
'cd catkin_ws/src/'
