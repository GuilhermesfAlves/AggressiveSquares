#include <stdlib.h>
#include "../headers/Bullet.h"

bullet* bullet_create(unsigned short x, unsigned short y, unsigned char trajectory_x, unsigned char trajectory_y, bullet *next){			//Implementação da função "bullet_create"

	if ((trajectory_x < 0) || (trajectory_x > 1)) return NULL;																				//Verifica se a trajetória informada do eixo x para o projétil é válida

	if ((trajectory_y < 0) || (trajectory_y > 2)) return NULL;																				//Verifica se a trajetória informada do eixo y para o projétil é válida

	bullet *new_bullet = (bullet*) malloc(sizeof(bullet));																					//Aloca memória na heap para uma instância de projétil
	if (!new_bullet) return NULL;																											//Verifica o sucesso da alocação de memória; retorna NULL em caso de falha
	new_bullet->x = x;																														//Armazena a posição X informada
	new_bullet->y = y;																														//Armazena a posição Y informada
	new_bullet->trajectory_x = trajectory_x;																								//Armazena a trajetória no eixo x informada
	new_bullet->trajectory_y = trajectory_y;																								//Armazena a trajetória no eixo y informada
	new_bullet->next = (struct bullet*) next;																								//Armazena o próximo projétil informado
	return new_bullet;																														//Retorna a instância criada de projétil
}

void bullet_destroy(bullet *element){																										//Implementação da função "bullet_destroy"

	free(element);																															//Libera a memória da instância de projétil
}