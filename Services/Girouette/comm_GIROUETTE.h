#ifndef COMM_GIROUETTE_H
#define COMM_GIROUETTE_H

/*
**************************************************************************************************
* @param : 
* Permet d'initialiser la girouette et ses périphériques de manière à être capable de l'utiliser
***************************************************************************************************/
void comm_girouette_init(void);

/*
**************************************************************************************************
* @param : 
* update la position du servo moteur par rapport à la girouette
***************************************************************************************************/
void comm_servo_moteur_update(void);

#endif
