//Aluno: Vinícius Nunes Cabral de Souza
//Matricula: 493613

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "conio.h"

int tempo = 1;  
int draw[13][28];
int desenho_casa[13][28] = {
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0
                           };
int desenho_aviao[13][28] = {
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                            };
int desenho_predio[13][28] = {
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0
                            };
int desenho_creeper[13][28] = {
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
                            0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,
                            0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,
                            0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,
                            0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,
                            0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,
                            0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,
                            0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,
                            0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,
                            0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0
                            };
int desenho_coracao[13][28] = {
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,
                            0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
                            0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
                            0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                            };
int desenho_cogu[13][28] = {
                            0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
                            0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,
                            0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,0,0,0,1,1,0,0,
                            0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,0,
                            1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,
                            1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,
                            1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,
                            1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                            0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,
                            0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,
                            0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,
                            0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0
                            };
int text_menu[9][50] = {
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,
                            0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,
                            0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,
                            0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,
                            0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                            };
int text_level[9][56] = {
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
                            0,0,0,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,
                            0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,
                            0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                            };
int sprite1_introduction[16][72] = {
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                            };
int sprite2_introduction[6][12] = {
                            1,1,0,0,0,0,0,0,0,0,0,0,
                            1,1,0,0,1,1,1,1,1,1,1,1,
                            1,1,0,0,0,0,0,0,0,0,0,0,
                            1,1,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,1,1,1,1,1,1,1,1,
                            1,1,0,0,0,0,0,0,0,0,0,0
                            };
int sprite3_introduction[16][72] = {
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                            };

void sleepTimer();
void background();
void screenMenu();
void writing();
void originalDraw();
void matrizDraw();
void paint();
void compare();
void cursor();
void play();
void selection();
void screenIntroduction();
void screenLevels();
void screenCredits();
void screenTutorial();

int main(){
    screenIntroduction();
    return 0;
}

void sleepTimer(int miliseconds){
    usleep(miliseconds*1000);
}

void background(char text[], int color, int x, int y){
    c_textbackground(color);
    c_gotoxy(x,y);
    printf("%s", text);
    return;
}

void screenMenu(){
    c_clrscr();
    int index = 0;
    for (int i = 0; i < 50;i++){
        for (int j = 0; j < 9; j++){
            if (text_menu[j][i] == 1){
                background(" ", 15, i + 30, j + 4);
                
            }
            if (text_menu[j][i] == 0){
                background(" ", 4, i + 30, j + 4);
            }
            sleepTimer(2);
        }
    }
    c_textcolor(14);
    writing("Jogar", 14, 0, 29, 15);
    writing("Tutorial", 14, 0, 43, 15);
    writing("Creditos", 14, 0, 60, 15);
    writing("Sair", 14, 0, 77, 15);    
    writing("Controles ", 14, 0, 51, 18); 
    writing("SETAS - Movimenta no menu | ENTER - Seleciona no menu", 14, 0, 29, 20); 
    writing("(c) Vinicius Nunes - 493613", 14, 0, 42, 23);
    writing(">>", 14, 0, 26, 15);
    writing("<<", 14, 0, 35, 15);
    int tecla;
    while (1){
        tecla = c_getch(); 
        switch (tecla){
            case 10: //tecla enter
                switch (index){
                    case 0: // index jogar
                        screenLevels();
                    break;
                    case 1:
                        screenTutorial();
                    break;
                    case 2: // index creditos
                        screenCredits();
                    break;
                    case 3: // index sair
                        c_clrscr();
                        writing("Obrigado por jogar!", 14, 0, 51, 15);
                        sleepTimer(1000);
                        c_clrscr();
                        exit(0);  
                    break;    
                }
            break;            
            case 67: // seta direita
                switch (index){
                    case 0: // index jogar
                        selection(5, 29, 15, 8, 43, 15);                
                        index++;
                    break;
                    case 1: // index tutorial
                        selection(8, 43, 15, 8, 60, 15);                
                        index++;
                    break;
                    case 2: // index creditos
                        selection(8, 60, 15, 4, 77, 15);  
                        index++;
                    break;
                    case 3: // index sair
                        selection(4, 77, 15, 5, 29, 15);  
                        index -= 3;
                    break;
                }
            break;
            case 68: // seta esquerda
                switch (index){
                    case 0: // index jogar
                        selection(5, 29, 15, 4, 77, 15); 
                        index += 3;
                    break;
                    case 1: // index tutorial
                        selection(8, 43, 15, 5, 29, 15); 
                        index--;
                    break;
                    case 2: // index creditos
                        selection(8, 60, 15, 8, 43, 15); 
                        index--;
                    break;
                    case 3: // index sair
                        selection(4, 77, 15, 8, 60, 15); 
                        index--;
                    break;
                }
            break;
        }
    }   
}

void writing(char text[], int cor_text, int cor_background,int x, int y){
    int len = strlen(text);
    c_textbackground(cor_background);
    c_textcolor(cor_text);
    for(int i = 0; i <= len; i++){
        c_gotoxy(i + x, y);
        printf("%c", text[i]);
        sleepTimer(25);
    }
}

void originalDraw(int fase){ 
    int desenho[13][28];

    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 28; j++){            
            switch (fase)
            {
                case 0: desenho[i][j] = desenho_casa[i][j];
                break;
                case 1: desenho[i][j] = desenho_aviao[i][j];
                break;
                case 2: desenho[i][j] = desenho_predio[i][j];
                break;
                case 3: desenho[i][j] = desenho_creeper[i][j];
                break;
                case 4: desenho[i][j] = desenho_coracao[i][j];
                break;
                case 5: desenho[i][j] = desenho_cogu[i][j];
                break;
            }
        }
    }

    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 28; j++){
            if(desenho[i][j] == 0){
                background(" ", 0, j + 42, i + 3);              
            } else {
                background(" ", 4, j + 42, i + 3);
                sleepTimer(25);        
            }
        }
    }
}

void matrizDraw(int x, int y) {
    x -= 6;
    y -= 3;
    draw[y][x] = 1;
    x++;
    draw[y][x] = 1;
}

void paint(int x, int y){
    int j = x - 6, i = y - 3;
    if (draw[i][j] == 1){
        background("  ", 6, x, y); 
    } else {
        background("  ", 0, x, y);
    }
    c_textbackground(0);           
}

void compare(int fase){
    int precisao = 0;
    int pintado = 0;
    int desenho[13][28];
    int precisaoPorcent;
    int numPre = 0;
    int numVer = 0;
    int minPorcent;

    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 28; j++){            
            switch (fase)
            {
                case 0: desenho[i][j] = desenho_casa[i][j];
                break;
                case 1: desenho[i][j] = desenho_aviao[i][j];
                break;
                case 2: desenho[i][j] = desenho_predio[i][j];
                break;
                case 3: desenho[i][j] = desenho_creeper[i][j];
                break;
                case 4: desenho[i][j] = desenho_coracao[i][j];
                break;
                case 5: desenho[i][j] = desenho_cogu[i][j];
                break;
            }
        }
    }

    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 28; j++){        
            if (desenho[i][j] == 0){
                numPre++;               
            } 
            if (draw[i][j] == desenho[i][j]){
                ++precisao;
            }                    
        }
    }

    minPorcent = 100 - ((100*numPre)/364);
    precisaoPorcent = 100 - (100*precisao)/364;
    precisaoPorcent = 100 - (100*precisaoPorcent)/minPorcent;      
    for (int i = 4; i <= 40; i++){
        for (int j = 2; j <= 18; j++){      
            background("  ", 0, i + 34, j); 
        }
    }
    for (int i = 4; i <= 34; i++){
        background(" ", 15, i + 36, 2); //parade cima 
        background(" ", 15, i + 36, 16); //parede baixo 
        sleepTimer(25);  
    }
    for (int i = 2; i <= 16; i++){
        background("  ", 15, 70, i); //parede direita 
        background("  ", 15, 40, i); //parede esquerda 
        sleepTimer(50);
    }
    originalDraw(fase);
    writing("Seu desenho", 14, 0, 6, 17);
    background("                 ", 0, 17,17);
    writing("Desenho orginal", 14, 0, 42, 17);
    writing(">> Resultado <<", 14, 0, 74, 3);
    writing(">> Sua precisao: ", 14, 0, 74, 5);
    c_gotoxy(91, 5);
    if (precisaoPorcent < 0){
        printf("0%%");
    } else {
        printf("%d%%", precisaoPorcent);
    }
    writing(">> Suas estrelas: ", 14, 0, 74, 7);
    background("  ", 15, 92, 7);
    background("  ", 15, 95, 7);
    background("  ", 15, 98, 7);
    if (precisaoPorcent >= 40 && precisaoPorcent <= 60) {
        background("  ", 14, 92, 7);
    } else if (precisaoPorcent > 60 && precisaoPorcent <= 85) {
        background("  ", 14, 92, 7);
        background("  ", 14, 95, 7);
    } else if (precisaoPorcent > 85 && precisaoPorcent <= 100) {
        background("  ", 14, 92, 7);
        background("  ", 14, 95, 7);
        background("  ", 14, 98, 7);
    }
    writing(">> Aperte ENTER para continuar jogando", 14, 0, 74, 9);
    int tecla;
    while(1){
        tecla = c_getch();
        if (tecla == 10){
            screenLevels();
        }        
    }

}

void cursor(int fase){
    int x = 6, y = 15;
    while (1)
    {   
        background("  ", 3, x, y);
        int tecla = c_getch();
        c_textbackground(0);
        if (tecla == 65 && y != 3){//cima
            paint(x, y);
            y--;
            c_gotoxy(31,17);
            if(y - 3 < 10) printf("0%d", y - 3);
            else printf("%d", y - 3);  
            background("  ", 6, x, y);
        } else if (tecla == 66 && y != 15) {//baixo
            paint(x, y);
            y++;
            c_gotoxy(31,17);
            if(y - 3 < 10) printf("0%d", y - 3);
            else printf("%d", y - 3);  
            background("  ", 6, x, y);
        } else if (tecla == 67 && x != 32) {//esquerda
            paint(x, y);
            x += 2;
            c_gotoxy(28,17);
            if((x/2) - 3 < 10) printf("0%d", (x/2) - 3);
            else printf("%d", (x/2) - 3);         
            background("  ", 6, x, y);
        } else if (tecla == 68 && x != 6){//direita
            paint(x, y);
            x -= 2;
            c_gotoxy(28,17);
            if((x/2) - 3 < 10) printf("0%d", (x/2) - 3);
            else printf("%d", (x/2) - 3);   
            background("  ", 6, x, y);            
        } else if (tecla == 32){
            matrizDraw(x, y);  
        } else if (tecla == 10){
            compare(fase);
            break;
        }
    }  
}

void play(int fase){
    c_clrscr();
    for (int i = 4; i <= 34; i++){
        background(" ", 15, i, 2); //parade cima 
        background(" ", 15, i, 16); //parede baixo  

        background(" ", 15, i + 36, 2); //parade cima 
        background(" ", 15, i + 36, 16); //parede baixo 
        sleepTimer(25);  
    }
    for (int i = 2; i <= 16; i++){
        background("  ", 15, 34, i); //parede direita 
        background("  ", 15, 4, i); //parede esquerda   
        
        background("  ", 15, 70, i); //parede direita 
        background("  ", 15, 40, i); //parede esquerda 
        sleepTimer(50);
    }

    originalDraw(fase);

    writing("Memorize o desenho", 14, 0, 42, 18);

    c_gotoxy(61, 18);
    if (tempo < 10) printf("(0%d)", tempo);        
    else printf("(%d)", tempo);

    while(tempo > 0)
    {
        tempo--;
        c_gotoxy(61, 18);
        if (tempo < 10) printf("(0%d)", tempo);        
        else printf("(%d)", tempo);
        
        sleepTimer(1000);
    }

    for (int i = 4; i <= 34; i++){
        for (int j = 2; j <= 18; j++){      
            background("  ", 0, i + 36, j); 
        }
    }
    writing("(00,12)", 14, 0, 27, 17);
    writing("Desenhe igual", 14, 0, 6, 17);
    writing(">> Controles <<", 14, 0, 38, 3);
    writing(">> SETAS - Movimenta o cursor", 14, 0, 38, 5);
    writing(">> ESPACO - Pinta o pixel selecionado", 14, 0, 38, 7);
    writing(">> ENTER - Finaliza o desenho", 14, 0, 38, 9);

    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 28; j++){
            draw[i][j] = 0;
        }
    }
    cursor(fase);
         
}

void selection(int leng1, int x1, int y1, int leng2, int x2, int y2) {
                c_gotoxy(x1 - 3 ,y1);
                printf("  ");
                c_gotoxy(x1 + leng1 + 1 ,y1);
                printf("  ");
                c_gotoxy(x2 - 3 ,y2);
                printf(">>");
                c_gotoxy(x2 + leng2 + 1 ,y2);
                printf("<<");
}

void screenIntroduction(){
    for (int i = 5; i < 80; i++){
        background(" ", 15, i, 3);
        background(" ", 15, i, 20);
        sleepTimer(10);
    }    
    for (int i = 3; i < 21; i++){
        background("  ", 15, 5, i);
        background("  ", 15, 79, i);
        sleepTimer(20);
    }

    for (int i = 0; i < 72; i++){
        for (int j = 0; j < 16; j++){
            if (sprite1_introduction[j][i] == 1){
                background(" ", 4, i + 8, j + 4);
                sleepTimer(25);
            }
            
        }
    }
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 6; j++){
            if (sprite2_introduction[j][i] == 1){
                background(" ", 4, i + 38, j + 9);
                sleepTimer(25);
            } 
            if (sprite2_introduction[j][i] == 0){
                background(" ", 0, i + 38, j + 9);
            } 
        }
    }
    sleepTimer(500);
    for (int i = 0; i < 16; i++){
        for (int j = 0; j < 72; j++){
            if (sprite3_introduction[i][j] == 1){
                background(" ", 3, j + 7, i + 4);
                sleepTimer(25);
            }
            if (sprite3_introduction[i][j] == 0){
                background(" ", 0, j + 7, i + 4);
            }
            
        }
    }

    int piscar = 0;
    int tecla;
    writing("Aperte qualquer TECLA para iniciar", 14, 0, 26,22);         
    while(!c_kbhit()){
        if (piscar == 0){ 
            background("  ", 0, 22, 22);            
            background(">>", 0, 22, 22);
            piscar++;
        } else if (piscar == 1) {
            background("<<", 0, 62, 22);
            background("  ", 0, 62, 22);
            piscar--;
        }        
        sleepTimer(1000);        
    }
    c_getch();
    screenMenu();
}

void screenLevels(){ 
    c_clrscr();

    for (int i = 0; i < 56;i++){
        for (int j = 0; j < 9; j++){
            if (text_level[j][i] == 1){
                background(" ", 15, i + 29, j + 4);
                sleepTimer(1);
            }
            if (text_level[j][i] == 0){
                background(" ", 4, i + 29, j + 4);
                sleepTimer(1);
            }
        }
    } 

    c_textcolor(14);
    writing("Facil", 14, 0, 36, 15);
    writing("Medio", 14, 0, 46, 15);
    writing("Dificil", 14, 0, 56, 15);
    writing("Aleatorio", 14, 0, 68, 15);  
    writing("Aperte BACKSPACE para voltar", 14, 0, 44, 18); 
    writing(">>", 14, 0, 33, 15);
    writing("<<", 14, 0, 42, 15);    

    srand(time(NULL));
    int index = 0;
    int indexDificuldade = 0;
    int tecla;
    while (1){
        tecla = c_getch();
        if (tecla == 67) {// seta direita
            if (indexDificuldade == 0){ // index facil
                selection(5, 36, 15, 5, 46, 15);
                indexDificuldade++;               
            } else if (indexDificuldade == 1){ // index medio
                selection(5, 46, 15, 7, 56, 15);
                indexDificuldade++; 
            } else if (indexDificuldade == 2){ // index dificil
                selection(7, 56, 15, 9, 68, 15);
                indexDificuldade++; 
            } else if (indexDificuldade == 3) { // index aleatorio
                selection(9, 68, 15, 5, 36, 15);
                indexDificuldade = 0;
            }
        } else if (tecla == 68){// seta esquerda
            if (indexDificuldade == 0){ // index facil
                selection(5, 36, 15, 9, 68, 15);
                indexDificuldade = 3;               
            } else if (indexDificuldade == 1){ // index medio
                selection(5, 46, 15, 5, 36, 15);
                indexDificuldade--; 
            } else if (indexDificuldade == 2){ // index dificil
                selection(7, 56, 15, 5, 46, 15);
                indexDificuldade--; 
            } else if (indexDificuldade == 3) { // index aleatorio
                selection(9, 68, 15, 7, 56, 15);
                indexDificuldade--;
            }      
        } else if (tecla == 127){
            screenMenu();
        } else if (tecla == 10) {
            if (indexDificuldade == 0){ // index facil
                tempo = 10;                
            } else if (indexDificuldade == 1){ // index medio
                tempo = 5;
            } else if (indexDificuldade == 2){ // index dificil
                tempo = 1;
            } else if (indexDificuldade == 3){ // index aleatorio
                indexDificuldade = rand() % 3;
                if (indexDificuldade == 0){
                    tempo = 10;                
                } else if (indexDificuldade == 1){
                    tempo = 5;
                } else if (indexDificuldade == 2){
                    tempo = 1;
                }       
                index = rand() % 6;
                play(index);
            }
            break; 
        }   
    }
    c_textbackground(0);
    c_gotoxy(44,18);
    printf("                            ");
    writing("Desenho 1", 14, 0, 45, 18);
    writing("Desenho 2", 14, 0, 45, 20);
    writing("Desenho 3", 14, 0, 45, 22);
    writing("Desenho 4", 14, 0, 61, 18);
    writing("Desenho 5", 14, 0, 61, 20);
    writing("Desenho 6", 14, 0, 61, 22);
    writing("Aperte BACKSPACE para voltar", 14, 0, 44, 25); 
    writing(">>", 14, 0, 42, 18);
    writing("<<", 14, 0, 55, 18);   

    while (1){
        tecla = c_getch();
        if (tecla == 10) { // tecla enter
            play(index);  
        } else if (tecla == 65){// seta cima
            if (index == 0){// index desenho 1
                selection(9, 45, 18, 9, 61, 22);
                index =+ 5;
            } else if (index == 1){// index desenho 2
                selection(9, 45, 20, 9, 45, 18);
                index--;
            } else if (index == 2){// index desenho 3
                selection(9, 45, 22, 9, 45, 20);
                index--;
            } else if (index == 3){// index desenho 4
                selection(9, 61, 18, 9, 45, 22);
                index--;
            } else if (index == 4) {// index desenho 5
                selection(9, 61, 20, 9, 61, 18);
                index--;
            } else if (index == 5) {// index desenho 6
                selection(9, 61, 22, 9, 61, 20);
                index--;
            }            
        } else if (tecla == 66) {// seta baixo
            if (index == 0){// index desenho 1
                selection(9, 45, 18, 9, 45, 20);    
                index++;
            } else if (index == 1){// index desenho 2
                selection(9, 45, 20, 9, 45, 22);
                index++;
            } else if (index == 2){// index desenho 3
                selection(9, 45, 22, 9, 61, 18);
                index++;
            } else if (index == 3){// index desenho 4
                selection(9, 61, 18, 9, 61, 20);
                index++;
            } else if (index == 4) {// index desenho 5
                selection(9, 61, 20, 9, 61, 22);
                index++;
            } else if (index == 5) {// index desenho 6
                selection(9, 61, 22, 9, 45, 18);
                index = 0;
            }    
        } else if (tecla == 127){// tecla BACKSPACE
            screenMenu();
        }   
    }    
}

void screenCredits(){
    c_clrscr();
    writing(">> Creditos de desenvolvimento <<", 14, 0, 3, 2);
    writing(">> Projeto de jogo desenvolvido atraves da materia de Fundamentos da Programacao (FUP)", 14, 0, 3, 4);
    writing(">> Desenvolvedor: Vinicius Nunes Cabral de Souza", 14, 0, 3, 6);
    writing(">> Numero da matricula: 493613", 14, 0, 3, 8);
    writing(">> Professor: Rafael Ivo", 14, 0, 3, 10);
    writing(">> Universidade: UFC - Universidade Federal do Ceara", 14, 0, 3, 12);
    writing(">> Repositorio do codigo: https://github.com/vininunes/drawlike", 14, 0, 3, 14);
    writing(">> Aperte BACKSPACE para voltar", 14, 0, 3, 16);

    int tecla;
    while(1){
        tecla = c_getch();
        if (tecla == 127){
            screenMenu();
        }
    }
}

void screenTutorial(){   
    c_clrscr(); 
    writing(">> Tutorial <<", 14, 0, 3, 2);
    writing("- Draw Like eh um jogo onde voce tera que tentar copiar um desenho com a maior precisao possivel!", 14, 0, 3, 4);
    writing(">> Precisao <<", 14, 0, 3, 6);
    writing("- A precisao pode varia de 0% a 100% e pode ser classificada de 0 - ", 14, 0, 3, 8);
    background("  ", 15, 72, 8);
    background("  ", 15, 75, 8);
    background("  ", 15, 78, 8);
    writing(" a 3 - ", 14, 0, 80, 8); 
    background("  ", 14, 87, 8);
    background("  ", 14, 90, 8);
    background("  ", 14, 93, 8);
    writing("estrelas", 14, 0, 96, 8);
    writing(">> Controle <<", 14, 0, 3, 10);
    writing("- Os controles do jogo estao somente no teclado", 14, 0, 3, 12);
    writing(">> No jogo <<", 14, 0, 3, 14);
    writing("- SETAS movimentam o cursor no quadro", 14, 0, 3, 16);
    writing("- ESPACO pinta o pixel em que o cursor esta", 14, 0, 3, 18);
    writing("- ENTER envia o desenho para comparacao", 14, 0, 3, 20); 
    writing(">> Aperte BACKSPACE para voltar", 14, 0, 3, 22); 
    int tecla;
    while(1){
        tecla = c_getch();
        if(tecla == 127){
            screenMenu();
        }
    }
}
