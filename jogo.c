/*
Aluno: Vinícius Nunes Cabral de Souza
Matricula: 493613

Descrição do jogo
Draw Like é um jogo de precisão entre desenhos, no qual o usuário tem que memorizar um desenho em um determinado 
tempo (definido pela dificuldade escolhida) e após o termino desse tempo deve tentar replicar o desenho com a maior
precisão possível. 
O jogo possui três dificuldade: 
-Fácil, no qual o tempo de memorização é de 10 segundos; 
-Médio, no qual o tempo de memorização é de 5 segundos; 
-Díficil, no qual o tempo de memorização é de 1 segundo. 
Possui também p modo aleatório, no qual é escolhido aleatóriamente uma dificuldade e um desenho. 
O jogo possui 6 desenhos a serem replicados, que são: 
-Desenho 1: Casa; 
-Desenho 2: Avião; 
-Desenho 3: Prédio; 
-Desenho 4: Creeper; 
-Desenho 5: Coração; 
-Desenho 6: Cogumelo do Mário. 
A pontuação é dada através da precisão atingida pelo usuário, que vária entre 0 a 100% e pode ser classificada entre 
0 a 3 estrelas:
-De 0 a 39% são 0 estrelas; 
-De 40 a 60% 1 estrela;
-De 61 a 85% 2 estrelas;
-De 86 a 100% 3 estrelas.
*/

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

void screenIntroduction(); // imprime a tela de introdução do jogo
void screenMenu(); // tela de menu
void screenLevels(); // imprime a tela de levels do jogo
void screenCredits(); // imprime a tela de créditos do jogo
void screenTutorial(); // imprime a tela de tutorial do jogo
void sleepTimer(); // delay em milissegundos
void background(); // define a cor do background em uma determinada posição
void writing(); // efeito de escrita
void selection(); // indica a opção selecionada no menu
void originalDraw(); // define qual desenho foi selecionado e o imprime na tela
void matrizDraw(); // gera uma matriz para o desenho feito pelo usuário
void play(); // inicia a rodada de desenho, mostrando o desenho o orginal por um determinado tempo, dependendo da dificuldade
void paint(); // pinta no quadro de pintura os pixels que possuem valor 1 na matriz
void cursor(); // movimenta o cursor no quadro de desenho
void compare(); // compara os desenhos, o feito pelo usuário e o original, calcula a precisão e mostra as informações finais da rodada na tela

int main(){ 
    c_textbackground(0);
    c_clrscr(); // limpar a tela
    printf("Instalar xTerm para redimensionar o terminal (linux)? [s/n]: ");
    char resposta = c_getche();
    printf("\n");
    switch(resposta){
        case 's': // permissão do usuário para instalar
            system("sudo apt-get install xterm"); // instalação da xterm para redimensionar o terminal no linux
            system("resize -s 30 120"); // tamanho de 120 colunas e 30 linhas (padrão no windows)
            c_clrscr(); // limpar a tela
            c_setcursortype(0); // desativa o cursor do console
            screenIntroduction(); // introdução do jogo
        break;
        case 'n':
            c_clrscr(); // limpar a tela
            c_setcursortype(0); // desativa o cursor do console
            screenIntroduction(); // introdução do jogo
        break;
        default: 
            printf("Resposta invalida");
            main();
        break;
    } 
    c_clrscr(); // limpar a tela
    c_setcursortype(0); // desativa o cursor do console
    screenIntroduction(); // introdução do jogo
    return 0;
}

void screenIntroduction(){
    for (int i = 5; i < 80; i++){ // bordas da animação de introdução
        background(" ", 15, i, 3);
        background(" ", 15, i, 20);
        sleepTimer(10);
    }    
    for (int i = 3; i < 21; i++){ // bordas da animação de introdução
        background("  ", 15, 5, i);
        background("  ", 15, 79, i);
        sleepTimer(20);
    }

    for (int i = 0; i < 72; i++){ // imprime primero sprite da animação 
        for (int j = 0; j < 16; j++){
            if (sprite1_introduction[j][i] == 1){
                background(" ", 4, i + 8, j + 4);
                sleepTimer(25);
            }
            
        }
    }
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 6; j++){
            if (sprite2_introduction[j][i] == 1){ // imprime segundo sprite da animação 
                background(" ", 4, i + 38, j + 9);
                sleepTimer(25);
            } 
            if (sprite2_introduction[j][i] == 0){
                background(" ", 0, i + 38, j + 9);
            } 
        }
    }
    sleepTimer(500); // intervalo de meio segundo
    for (int i = 0; i < 16; i++){ // imprime terceiro sprite da animação 
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
    while(!c_kbhit()){ // ao usuário pressionar qualquer telca ele inicia o menu
        if (piscar == 0){ // animação piscante
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
    screenMenu(); // inicia tela de menu
}

void screenMenu(){ 
    c_clrscr();
    for (int i = 0; i < 50;i++){ // cria a imagem do menu a partir da text_menu
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
    // opções e informações do menu
    writing("Jogar", 14, 0, 29, 15); 
    writing("Tutorial", 14, 0, 43, 15);                                                  
    writing("Creditos", 14, 0, 60, 15);                                                             
    writing("Sair", 14, 0, 77, 15);    
    writing("Controles ", 14, 0, 51, 18); 
    writing("SETAS - Movimenta no menu | ENTER - Seleciona no menu", 14, 0, 29, 20); 
    writing("(c) Vinicius Nunes - 493613", 14, 0, 42, 23);
    writing(">>", 14, 0, 26, 15);
    writing("<<", 14, 0, 35, 15);
    int index = 0; // index de seleção do menu
    int tecla; // armazena código ascii da tecla presionada
    while (1){
        tecla = c_getch(); // (conio.h) coleta a tecla presionada sem imprimir na tela
        switch (tecla){
            case 10: //tecla enter código ascii 10
                switch (index){
                    case 0: // opção jogar 
                        screenLevels(); // tela de dificuldade e desenhos
                    break;
                    case 1: // opção tutorial
                        screenTutorial(); // tela de tutorial
                    break;
                    case 2: // opção creditos
                        screenCredits(); // tela de créditos
                    break;
                    case 3: // opção sair
                        c_clrscr(); 
                        writing("Obrigado por jogar!", 14, 0, 51, 15);
                        sleepTimer(1000);
                        c_clrscr();
                        exit(0); // para a execução do programa
                    break;    
                }
            break;            
            case 67: // seta direita
                switch (index){
                    case 0: // opção jogar
                        selection(5, 29, 15, 8, 43, 15);             
                        index++;
                    break;
                    case 1: // opção tutorial
                        selection(8, 43, 15, 8, 60, 15);                
                        index++;
                    break;
                    case 2: // opção creditos
                        selection(8, 60, 15, 4, 77, 15);  
                        index++;
                    break;
                    case 3: // opção sair
                        selection(4, 77, 15, 5, 29, 15);  
                        index -= 3;
                    break;
                }
            break;
            case 68: // seta esquerda
                switch (index){
                    case 0: // opção jogar
                        selection(5, 29, 15, 4, 77, 15); 
                        index += 3;
                    break;
                    case 1: // opção tutorial
                        selection(8, 43, 15, 5, 29, 15); 
                        index--;
                    break;
                    case 2: // opção creditos
                        selection(8, 60, 15, 8, 43, 15); 
                        index--;
                    break;
                    case 3: // opção sair
                        selection(4, 77, 15, 8, 60, 15); 
                        index--;
                    break;
                }
            break;
        }
    }   
}

void screenLevels(){
    c_clrscr();

    for (int i = 0; i < 56;i++){ // cria a imagem do menu a partir da text_level
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
    // imprime as opções de dificuldade
    c_textcolor(14);
    writing("Facil", 14, 0, 36, 15);
    writing("Medio", 14, 0, 46, 15);
    writing("Dificil", 14, 0, 56, 15);
    writing("Aleatorio", 14, 0, 68, 15);  
    writing("Aperte BACKSPACE para voltar", 14, 0, 44, 18); 
    writing(">>", 14, 0, 33, 15);
    writing("<<", 14, 0, 42, 15);    

    srand(time(NULL)); // inicializa a aletoriedade através do tempo
    int index = 0; // index do desenho
    int indexDificuldade = 0; // index da dificuldade
    int tecla; // ascii da tecla pressionada
    while (1){
        tecla = c_getch(); // coleta código ascii da tecla pressionada
        if (tecla == 67) {// seta direita
            if (indexDificuldade == 0){ // index facil
                selection(5, 36, 15, 5, 46, 15);
                indexDificuldade++; // define o index da dificuldade selecionada             
            } else if (indexDificuldade == 1){ // index medio
                selection(5, 46, 15, 7, 56, 15);
                indexDificuldade++; // define o index da dificuldade selecionada  
            } else if (indexDificuldade == 2){ // index dificil
                selection(7, 56, 15, 9, 68, 15);
                indexDificuldade++; // define o index da dificuldade selecionada  
            } else if (indexDificuldade == 3) { // index aleatorio
                selection(9, 68, 15, 5, 36, 15);
                indexDificuldade = 0; // define o index da dificuldade selecionada  
            }
        } else if (tecla == 68){// seta esquerda
            if (indexDificuldade == 0){ // index facil
                selection(5, 36, 15, 9, 68, 15);
                indexDificuldade = 3; // define o index da dificuldade selecionada                  
            } else if (indexDificuldade == 1){ // index medio
                selection(5, 46, 15, 5, 36, 15);
                indexDificuldade--; // define o index da dificuldade selecionada   
            } else if (indexDificuldade == 2){ // index dificil
                selection(7, 56, 15, 5, 46, 15);
                indexDificuldade--; // define o index da dificuldade selecionada  
            } else if (indexDificuldade == 3) { // index aleatorio
                selection(9, 68, 15, 7, 56, 15);
                indexDificuldade--; // define o index da dificuldade selecionada  
            }      
        } else if (tecla == 127){ // BACKSPACE
            screenMenu(); // retorna para o menu
        } else if (tecla == 10) {
            if (indexDificuldade == 0){ // index facil
                tempo = 10; // para dificuldade fácil define o tempo de 10 segundos para memorização                   
            } else if (indexDificuldade == 1){ // index medio
                tempo = 5;  // para dificuldade médio define o tempo de 5 segungos para memorização 
            } else if (indexDificuldade == 2){ // index dificil
                tempo = 1;  // para dificuldade difícil define o tempo de 1 segundo para memorização
            } else if (indexDificuldade == 3){ // index aleatorio
                indexDificuldade = rand() % 3; // dificuldade aletória
                if (indexDificuldade == 0){
                    tempo = 10; // para dificuldade fácil define o tempo de 10 segundos para memorização          
                } else if (indexDificuldade == 1){
                    tempo = 5; // para dificuldade médio define o tempo de 5 segungos para memorização 
                } else if (indexDificuldade == 2){
                    tempo = 1; // para dificuldade difícil define o tempo de 1 segundo para memorização
                }       
                index = rand() % 6; // desenho aleatório
                play(index); // inicio do jogo no modo aletorio
            }
            break; 
        }   
    }
    // opções de desenhos
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
        tecla = c_getch(); // coleta código ascii da tecla pressionada
        if (tecla == 10) { // tecla enter
            play(index); // inicia o jogo com o desenho e dificuldade selecionados
        } else if (tecla == 65){// seta cima
            if (index == 0){// index desenho 1
                selection(9, 45, 18, 9, 61, 22);
                index =+ 5; // define o index do desenho selecionado
            } else if (index == 1){// index desenho 2
                selection(9, 45, 20, 9, 45, 18);
                index--; // define o index do desenho selecionado
            } else if (index == 2){// index desenho 3
                selection(9, 45, 22, 9, 45, 20);
                index--; // define o index do desenho selecionado
            } else if (index == 3){// index desenho 4
                selection(9, 61, 18, 9, 45, 22);
                index--; // define o index do desenho selecionado
            } else if (index == 4) {// index desenho 5
                selection(9, 61, 20, 9, 61, 18);
                index--; // define o index do desenho selecionado
            } else if (index == 5) {// index desenho 6
                selection(9, 61, 22, 9, 61, 20);
                index--; // define o index do desenho selecionado
            }            
        } else if (tecla == 66) {// seta baixo
            if (index == 0){// index desenho 1
                selection(9, 45, 18, 9, 45, 20);    
                index++; // define o index do desenho selecionado
            } else if (index == 1){// index desenho 2
                selection(9, 45, 20, 9, 45, 22);
                index++; // define o index do desenho selecionado
            } else if (index == 2){// index desenho 3
                selection(9, 45, 22, 9, 61, 18);
                index++; // define o index do desenho selecionado
            } else if (index == 3){// index desenho 4
                selection(9, 61, 18, 9, 61, 20);
                index++; // define o index do desenho selecionado
            } else if (index == 4) {// index desenho 5
                selection(9, 61, 20, 9, 61, 22);
                index++; // define o index do desenho selecionado
            } else if (index == 5) {// index desenho 6
                selection(9, 61, 22, 9, 45, 18);
                index = 0;
            }    
        } else if (tecla == 127){// tecla BACKSPACE
            screenMenu(); // retona para o menu
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
        tecla = c_getch(); // coleta código ascii da tecla pressionada
        if (tecla == 127){ // BACKSPACE(127) para voltar ao screenMenu
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
        tecla = c_getch(); // coleta código ascii da tecla pressionada
        if(tecla == 127){ // BACKSPACE(127) para voltar ao screenMenu
            screenMenu();
        }
    }
}

void sleepTimer(int miliseconds){
    usleep(miliseconds*1000); // função sleep da biblioteca <unistd.h>
}

void background(char text[], int color, int x, int y){ 
    c_textbackground(color); // (conio.h) define a cor do background
    c_gotoxy(x,y); // (conio.h) move o cursor para as coordenadas x e y
    printf("%s", text); // imprime na tela uma string ou char
}

void writing(char text[], int cor_text, int cor_background,int x, int y){
    int len = strlen(text); // (string.h) coleta o tamanha do texto
    c_textbackground(cor_background); // (conio.h) altera a cor do background
    c_textcolor(cor_text); // (conio.h) altera a cor do texto
    for(int i = 0; i <= len; i++){ // escreve o texto com um intervalo de 25 milissegundos entre as letras
        c_gotoxy(i + x, y); // define a posição do cursor no console
        printf("%c", text[i]); // imprime o caractere
        sleepTimer(25); // intervalo de 25 milissegundos
    }
}

void selection(int leng1, int x1, int y1, int leng2, int x2, int y2) {
                c_gotoxy(x1 - 3 ,y1); // coordenada da opção anterior
                printf("  "); // apaga a seleção da opção anterior
                c_gotoxy(x1 + leng1 + 1 ,y1);
                printf("  "); // apaga a seleção da opção anterior
                c_gotoxy(x2 - 3 ,y2); // coordenada da opção posterior
                printf(">>"); // mostra a seleção da opção posterior
                c_gotoxy(x2 + leng2 + 1 ,y2);
                printf("<<"); // mostra a seleção da opção posterior
} 

void originalDraw(int fase){ 
    int desenho[13][28]; //matriz do desenho selecionado

    for(int i = 0; i < 13; i++){ // define a matriz com os valores da matriz do desenho selecionado
        for(int j = 0; j < 28; j++){            
            switch (fase){
                case 0: desenho[i][j] = desenho_casa[i][j]; // caso for o desenho 1, será a matriz desenho_casa
                break;
                case 1: desenho[i][j] = desenho_aviao[i][j]; // caso for o desenho 2, será a matriz desenho_aviao
                break;
                case 2: desenho[i][j] = desenho_predio[i][j]; // caso for o desenho 3, será a matriz desenho_predio
                break;
                case 3: desenho[i][j] = desenho_creeper[i][j]; // caso for o desenho 4, será a matriz desenho_creeper
                break;
                case 4: desenho[i][j] = desenho_coracao[i][j]; // caso for o desenho 5, será a matriz desenho_coracao
                break;
                case 5: desenho[i][j] = desenho_cogu[i][j]; // caso for o desenho 6, será a matriz desenho_cogu
                break;
            }
        }
    }

    for(int i = 0; i < 13; i++){ // imprime o desenho selecionado no quadro de memorização
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
    x -= 6; // arruma a coordenada x
    y -= 3; // arruma a coordenada y
    draw[y][x] = 1; // atribui o valor 1 na coordenada y,x 
    x++;
    draw[y][x] = 1; // atribui o valor 1 na coordenada y,x + 1
}

void paint(int x, int y){
    int j = x - 6, i = y - 3;
    if (draw[i][j] == 1){ // as coordenadas na matriz que tiverem valor 1 serão pintadas de vermelho
        background("  ", 6, x, y); 
    } else { // as coordenadas na matriz que tiverem valor 0 serão pintadas de preto
        background("  ", 0, x, y);
    }
    c_textbackground(0); // define o background como preto          
}

void play(int fase){
    c_clrscr(); 
    for (int i = 4; i <= 34; i++){ // imprime os quadros de pintura e de memorização na tela
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

    originalDraw(fase); // imprime no quadro de memorização o desenho escolhido

    writing("Memorize o desenho", 14, 0, 42, 18); 

    c_gotoxy(61, 18);
    if (tempo < 10) printf("(0%d)", tempo); // imprime o tempo de memorização seleciona pelo usuário        
    else printf("(%d)", tempo);

    while(tempo > 0){ // loop que definira o tempo de memorização, roda com um intervalo de 1 segundo
        tempo--;
        c_gotoxy(61, 18);
        if (tempo < 10) printf("(0%d)", tempo);        
        else printf("(%d)", tempo);
        
        sleepTimer(1000); // intervalo de 1 segundo
    }

    for (int i = 4; i <= 34; i++){ // apaga o quadro de memorização 
        for (int j = 2; j <= 18; j++){      
            background("  ", 0, i + 36, j); 
        }
    }
    // informações de desenho do usuário
    writing("(00,12)", 14, 0, 27, 17);
    writing("Desenhe igual", 14, 0, 6, 17);
    writing(">> Controles <<", 14, 0, 38, 3);
    writing(">> SETAS - Movimenta o cursor", 14, 0, 38, 5);
    writing(">> ESPACO - Pinta o pixel selecionado", 14, 0, 38, 7);
    writing(">> ENTER - Finaliza o desenho", 14, 0, 38, 9);

    for(int i = 0; i < 13; i++){ // define a matriz desenho inteira como 0, ou seja, preto
        for(int j = 0; j < 28; j++){
            draw[i][j] = 0;
        }
    }
    cursor(fase); // função que irá movimentar o cursor no quadro de desenho         
}

void cursor(int fase){
    int x = 6, y = 15; //define o x e y iniciais do cursor
    while (1){   
        background("  ", 3, x, y); // define a posição do cursor
        int tecla = c_getch();
        c_textbackground(0);
        if (tecla == 65 && y != 3){// seta cima, com limite do y igual a 3
            paint(x, y); // atualiza o quadro de pintura  
            y--; // muda a posição do cursor uma coordenada y para cima
            c_gotoxy(31,17); 
            if(y - 3 < 10) printf("0%d", y - 3); // muda a coordenada y do cursor indicada para o usuário
            else printf("%d", y - 3);  
        } else if (tecla == 66 && y != 15) {// seta baixo, com limite do y igual a 15
            paint(x, y); // atualiza o quadro de pintura
            y++; // muda a posição do cursor uma coordenada y para baixo
            c_gotoxy(31,17);
            if(y - 3 < 10) printf("0%d", y - 3); // muda a coordenada y do cursor indicada para o usuário
            else printf("%d", y - 3);  
        } else if (tecla == 67 && x != 32) {// seta esquerda, com limite do x igual a 32
            paint(x, y); // atualiza o quadro de pintura
            x += 2; // muda a posição do cursor duas coordenadas para esquerda (a cada linha são duas colunas)
            c_gotoxy(28,17); 
            if((x/2) - 3 < 10) printf("0%d", (x/2) - 3); // muda a coordenada x do cursor indicada para o usuário
            else printf("%d", (x/2) - 3);         
        } else if (tecla == 68 && x != 6){// seta direita, com limite do x igual a 6
            paint(x, y); // atualiza o quadro de pintura
            x -= 2; // muda a posição do cursor duas coordenadas para direita (a cada linha são duas colunas)
            c_gotoxy(28,17);
            if((x/2) - 3 < 10) printf("0%d", (x/2) - 3); // muda a coordenada x do cursor indicada para o usuário
            else printf("%d", (x/2) - 3);             
        } else if (tecla == 32){
            matrizDraw(x, y);  // pinta o pixel que o cursor está caso a tecla ESPAÇO (32) for pressionada  
        } else if (tecla == 10){
            compare(fase); // compara o desenho pintado com o original caso a teclha ENTER (10) for pressionada
            break;
        }
    }  
}

void compare(int fase){
    int desenho[13][28];
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 28; j++){ // indentifica qual o desenho original, através do parametro fase            
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

    int precisao = 0; 
    int pintado = 0;
    int precisaoPorcent;
    int numPre = 0;
    int numVer = 0;
    int minPorcent;
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 28; j++){        
            if (desenho[i][j] == 0){ // calcula o número de pixels pretos na original
                numPre++;               
            } 
            if (draw[i][j] == desenho[i][j]){ // calcula o número de valores iguais entre a matriz original e a desenhada
                ++precisao;
            }                    
        }
    }
    // calculo da precisão do usuário
    minPorcent = 100 - ((100*numPre)/364); // calcula a porcentagem mínima, ou seja, caso o usuário aperte enter sem desenhar nada
    precisaoPorcent = 100 - (100*precisao)/364; // calcula a porcentagem de semelhanca entre a matriz original e a desenhada
    precisaoPorcent = 100 - (100*precisaoPorcent)/minPorcent; // transforma a escala da porcentagem de semelhança para a escala minima      
    for (int i = 4; i <= 40; i++){ // apaga as informações de controles presente na tela
        for (int j = 2; j <= 18; j++){      
            background("  ", 0, i + 34, j); 
        }
    }
    for (int i = 4; i <= 34; i++){ // imprime o quadro onde vai aparecer o desenho original
        background(" ", 15, i + 36, 2); //parade cima 
        background(" ", 15, i + 36, 16); //parede baixo 
        sleepTimer(25);  
    }
    for (int i = 2; i <= 16; i++){ // imprime o quadro onde vai aparecer o desenho original
        background("  ", 15, 70, i); //parede direita 
        background("  ", 15, 40, i); //parede esquerda 
        sleepTimer(50);
    }
    originalDraw(fase); // imprime o desenho original no quadro
    // informações finais da rodada
    writing("Seu desenho", 14, 0, 6, 17);
    background("                 ", 0, 17,17);
    writing("Desenho orginal", 14, 0, 42, 17);
    writing(">> Resultado <<", 14, 0, 74, 3);
    writing(">> Sua precisao: ", 14, 0, 74, 5);
    c_gotoxy(91, 5);
    if (precisaoPorcent < 0){ // imprime a precisão obitida pelo usuário
        printf("0%%");
    } else {
        printf("%d%%", precisaoPorcent);
    }
    //imprime as estrelas obtidas pelo usuário
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
    // retonra para a screenLevels caso o usuário aperte ENTER
    while(1){
        tecla = c_getch();
        if (tecla == 10){
            screenLevels();
        }        
    }
}
