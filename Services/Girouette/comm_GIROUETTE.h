#ifndef COMM_GIROUETTE_H
#define COMM_GIROUETTE_H

/*
**************************************************************************************************
* @param : 
* Permet d'initialiser la girouette et ses p�riph�riques de mani�re � �tre capable de l'utiliser
***************************************************************************************************/
void comm_girouette_init(void);

/*
**************************************************************************************************
* @param : 
* update la position du servo moteur par rapport � la girouette
***************************************************************************************************/
void comm_servo_moteur_update(void);

#endif
