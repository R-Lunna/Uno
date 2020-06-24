// Serve para não gerar ambiguidade de bibliotecas em tempo de compilação.
#ifndef PILHA_H 
#define PILHA_H

#include <stdio.h>
#include <conio2.h>

// Define o tamanho da pilha.
#define MAX 108

// Determina qual o tipo de dados da pilha;
typedef int	tp_item;

// Dado abstrato do tipo tp_pilha que é uma struct. 	
typedef struct {
	// Armazena o indíce do vetor(pilha).
	int topo;
	
	// Vetor(pilha) do tipo tp_item.
	tp_item item[MAX];
	
// Tipo da minha estrutura.
}tp_pilha;

/* Função que inicializa a pilha
ela sempre deve ser inicializada no 
programa antes de utilizar a pilha,
para indicar que a mesma está vazia */
void inicializa_pilha(tp_pilha *p) {
	p->topo = -1;	
}

// Função que verifica se a pilha está ou não vazia.
int pilha_vazia(tp_pilha *p) {
	if (p->topo == -1) return 1;
	return 0;
}

// Função que verifica se a pilha está ou não cheia.
int pilha_cheia(tp_pilha *p) {
	if (p->topo == MAX -1) {
		return 1;
	} else {
		return 0;
	}
}

// Função que empilha.
int push(tp_pilha *p, tp_item e) {
	if (pilha_cheia(p) == 1) return 0;
	p->topo++;
	p->item[p->topo] = e;
	return 1;
}

// Função que desempilha.
int pop(tp_pilha *p, tp_item *e) {
	if (pilha_vazia(p)) return 0;
	*e = p->item[p->topo];
	p->topo--;	
	return 1;
}

/* Função que verifica qual elemento está no topo
sem desempilhar e printa em tela*/
int top2(tp_pilha *p) {
	if (pilha_vazia(p)) return 0;
	switch (p->item[p->topo]) {
			case 10: {
				textcolor(RED);
				cprintf("[0] ");
				break;
			}
			case 11: {
				textcolor(RED);
				cprintf("[1] ");
				break;
			}	
			case 12: {
				textcolor(RED);
				cprintf("[2] ");
				break;
			}	
			case 13: {
				textcolor(RED);
				cprintf("[3] ");
				break;
			}	
			case 14: {
				textcolor(RED);
				cprintf("[4] ");
				break;	
			}
			case 15: {
				textcolor(RED);
				cprintf("[5] ");
				break;
			}
			case 16: {
				textcolor(RED);
				cprintf("[6] ");
				break;
			}
			case 17: {
				textcolor(RED);
				cprintf("[7] ");
				break;
			}
			case 18: {
				textcolor(RED);
				cprintf("[8] ");
				break;
			}
			case 19: {
				textcolor(RED);
				cprintf("[9] ");
				break;
			}
			case 20: {
				textcolor(YELLOW);
				cprintf("[0] ");
				break;
			}
			case 21: {
				textcolor(YELLOW);
				cprintf("[1] ");
				break;
			}
			case 22: {
				textcolor(YELLOW);
				cprintf("[2] ");
				break;
			}
			case 23: {
				textcolor(YELLOW);
				cprintf("[3] ");
				break;
			}
			case 24: {
				textcolor(YELLOW);
				cprintf("[4] ");
				break;
			}
			case 25: {
				textcolor(YELLOW);
				cprintf("[5] ");
				break;
			}
			case 26: {
				textcolor(YELLOW);
				cprintf("[6] ");
				break;
			}
			case 27: {
				textcolor(YELLOW);
				cprintf("[7] ");
				break;
			}
			case 28: {
				textcolor(YELLOW);
				cprintf("[8] ");
				break;
			}
			case 29: {
				textcolor(YELLOW);
				cprintf("[9] ");
				break;
			}
			case 30: {
				textcolor(GREEN);
				cprintf("[0] ");
				break;
			}
			case 31: {
				textcolor(GREEN);
				cprintf("[1] ");
				break;
			}
			case 32: {
				textcolor(GREEN);
				cprintf("[2] ");
				break;
			}
			case 33: {
				textcolor(GREEN);
				cprintf("[3] ");
				break;
			}
			case 34: {
				textcolor(GREEN);
				cprintf("[4] ");
				break;
			}
			case 35: {
				textcolor(GREEN);
				cprintf("[5] ");
				break;
			}
			case 36: {
				textcolor(GREEN);
				cprintf("[6] ");
				break;
			}
			case 37: {
				textcolor(GREEN);
				cprintf("[7] ");
				break;
			}
			case 38: {
				textcolor(GREEN);
				cprintf("[8] ");
				break;
			}
			case 39: {
				textcolor(GREEN);
				cprintf("[9] ");
				break;
			}
			case 40: {
				textcolor(BLUE);
				cprintf("[0] ");
				break;
			}
			case 41: {
				textcolor(BLUE);
				cprintf("[1] ");
				break;
			}
			case 42: {
				textcolor(BLUE);
				cprintf("[2] ");
				break;
			}
			case 43: {
				textcolor(BLUE);
				cprintf("[3] ");
				break;
			}
			case 44: {
				textcolor(BLUE);
				cprintf("[4] ");
				break;
			}
			case 45: {
				textcolor(BLUE);
				cprintf("[5] ");
				break;
			}
			case 46: {
				textcolor(BLUE);
				cprintf("[6] ");
				break;
			}
			case 47: {
				textcolor(BLUE);
				cprintf("[7] ");
				break;
			}
			case 48: {
				textcolor(BLUE);
				cprintf("[8] ");
				break;
			}
			case 49: {
				textcolor(BLUE);
				cprintf("[9] ");
				break;
			}
			case 50: {
				textcolor(RED);
				cprintf("[B] ");
				break;
			}
			case 51: {
				textcolor(RED);
				cprintf("[<->] ");
				break;
			}
			case 52: {
				textcolor(RED);
				cprintf("[+2] ");
				break;
			}
			case 53: {
				textcolor(YELLOW);
				cprintf("[B] ");
				break;
			}
			case 54: {
				textcolor(YELLOW);
				cprintf("[<->] ");
				break;
			}
			case 55: {
				textcolor(YELLOW);
				cprintf("[+2] ");
				break;
			}
			case 56: {
				textcolor(GREEN);
				cprintf("[B] ");
				break;
			}
			case 57: {
				textcolor(GREEN);
				cprintf("[<->] ");
				break;
			}
			case 58: {
				textcolor(GREEN);
				cprintf("[+2] ");
				break;
			}
			case 59: {
				textcolor(BLUE);
				cprintf("[B] ");
				break;
			}
			case 60: {
				textcolor(BLUE);
				cprintf("[<->] ");
				break;
			}
			case 61: {
				textcolor(BLUE);
				cprintf("[+2] ");
				break;
			}
			case 62: {
				textcolor(RED);
				cprintf("[C] ");
				break;
			}
			case 63: {
				textcolor(YELLOW);
				cprintf("[C] ");
				break;
			}
			case 64: {
				textcolor(GREEN);
				cprintf("[C] ");
				break;
			}
			case 65: {
				textcolor(BLUE);
				cprintf("[C] ");
				break;
			}
			case 66: {
				textcolor(RED);
				cprintf("[+4] ");
				break;
			}
			case 67: {
				textcolor(YELLOW);
				cprintf("[+4] ");
				break;
			}
			case 68: {
				textcolor(GREEN);
				cprintf("[+4] ");
				break;
			}
			case 69: {
				textcolor(BLUE);
				cprintf("[+4] ");
				break;
			}
			default: {
				break;
			}
		}
	return 1;
}

tp_item top(tp_pilha *p) {
	if (pilha_vazia(p)) return 0;
	return p->item[p->topo];
}

// Função que me diz quantos elementos tem na minha pilha.
int altura_pilha(tp_pilha *p) {
	return p->topo +1;	
}

// Função que imprime, desempilhando, uma cópia da minha pilha.
void imprime_pilha(tp_pilha p) {
	tp_item e;
	while (!pilha_vazia(&p)) {
		pop(&p, &e);
		printf("                                  [%d]\n", e);
	}
}

// Fim do if.
#endif
