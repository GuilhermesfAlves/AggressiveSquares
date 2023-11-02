#ifndef __TRIPPLE_PISTOL__
#define __TRIPPLE_PISTOL__

#include "Bullet.h"

#define TRIPPLE_PISTOL_COOLDOWN 80                                                                                   //Cooldown para cada disparo realizado

typedef struct{
    unsigned char timer;                                                                                             //Ticks restantes para o próximo disparo poder ser efetuado
    bullet* shots;                                                                                                   //Lista de disparos efetuados por tripple_pistol
} tripple_pistol;                                                                                                    //TAD tripple_pistol

tripple_pistol* tripple_pistol_create();                                                                             //Protótipo da função "tripple_pistol_create"
bullet* tripple_pistol_shot(unsigned short x, unsigned short y, unsigned char trajectory, tripple_pistol *gun);      //Protótipo da função "tripple_pistol_shot"
void tripple_pistol_destroy(tripple_pistol *element);		                                                         //Protótipo da função "tripple_pistol_destroy"

#endif //__TRIPPLE_PISTOL__