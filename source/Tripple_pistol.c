#include <stdlib.h>
#include "../headers/Tripple_pistol.h"

tripple_pistol* tripple_pistol_create(){                                                                                //Implementação da função "tripple_pistol_create"
    tripple_pistol* new_pistol;

    if(!(new_pistol = (tripple_pistol*) malloc(sizeof(tripple_pistol))))                                                //Aloca a memória na heap para uma instância de pistola e confere o sucesso
        return NULL;

    new_pistol -> timer = TRIPPLE_PISTOL_COOLDOWN;                                                                      //Inicializa o relógio de disparos no máximo, ou seja, tem que esperar
    new_pistol -> shots = NULL;                                                                                         //Inicializa a lista de disparos com NULL, ou seja, sem disparos

    return new_pistol;
}

bullet* tripple_pistol_shot(unsigned short x, unsigned short y, unsigned char trajectory, tripple_pistol *gun){         //Implementação da função "tripple_pistol_shot"
    bullet* bullet_up = bullet_create(x, y, trajectory, UP, gun->shots);                                                //Cria uma nova instância de disparo na diagonal da direção apontada e para cima
    bullet* bullet_straight = bullet_create(x, y, trajectory, STRAIGHT, bullet_up);                                     //Cria uma nova instância de disparo na mesma reta que o disparo normal é efetuado
    bullet* bullet_down = bullet_create(x, y, trajectory, DOWN, bullet_straight);                                       //Cria uma nova instância de disparo na diagonal da direção apontada e para baixo
    
    return bullet_down; 
}

void tripple_pistol_destroy(tripple_pistol *element){                                                                   //Implementação da função "tripple_pistol_destroy"
    bullet *sentinel;																					                //Sentinela para a remoção de projéteis ativos 

	for (bullet *index = element->shots; index != NULL; index = sentinel){								                //Para cada projétil na lista de disparos 
		sentinel = (bullet*) index->next;																                //Armazena o próximo projétil 
		bullet_destroy(index);																			                //Chama o destrutor do projétil atual 
	}
    free(element);
}
