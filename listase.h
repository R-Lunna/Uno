#ifndef LISTASE_H
#define LISTASE_H

#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

typedef int tp_item;

typedef struct tp_no {
  tp_item info;
  struct tp_no *prox;
}tp_listase;


tp_listase *inicializa_listase() {
	return NULL;
}
	
int listase_vazia(tp_listase *l) {
	if(l==NULL) return 1;
	return 0;
}

// ela irá alocar um espaço na memória;
tp_listase *aloca_listase() { 
	tp_listase *novo_no;
	novo_no = (tp_listase*) malloc(sizeof(tp_listase));
	return novo_no;
}

/* Esse **l é um ponteiro que está apontando para outro 
ponteiro para o endereço de memória original da listase*,
o que está apontando para o NULL */
int insere_listase(tp_listase **l, tp_item e) { 
	tp_listase *novo_no, *atu, *ant;

	// aqui está pegando o novo nó e apontando para o NULL;
	novo_no = aloca_listase();

	atu = *l;
	ant = NULL;

	// Não alocou memória 
	if(novo_no == NULL) return 0; 

	// atribuir os valores para o novo nó;
	novo_no->info = e;
	while ((atu != NULL) && (atu->info < novo_no->info)) { 	
		ant = atu;
		atu = atu->prox;
	}
		
	if (ant == NULL) *l = novo_no;
	else ant->prox = novo_no;
	
	novo_no->prox = atu;
		
	return 1;
}

/* Esse **l é um ponteiro que está apontando para outro 
ponteiro para o endereço de memória original da listase*,
o que está apontando para o NULL */
int insere_listase_inicio(tp_listase **l, tp_item e){ 
	tp_listase *novo_no, *atu;
	
	// aqui está pegando o novo nó e apontando para o NULL;
	novo_no=aloca_listase(); 

	// Não alocou memória
	if (novo_no==NULL) return 0; 
	
	// atribuir os valores para o novo nó;
	novo_no->info= e;
	novo_no->prox=NULL;
	// finaliza o encadeamento do nó
	
	// se for o primeiro nó entra aqui
	if (listase_vazia(*l)) {
		*l=novo_no;
	} else {
		// add
		novo_no->prox= *l; 
		// add
		*l=novo_no; 
	}
	
	return 1;
}

// Verifica qual o número que está na pilha e imprime a partir disso, como um CPF, imprime o elemento.
void imprime(tp_listase *l) {
	tp_listase *aux;
	aux=l;
	
	while (aux!=NULL){
		
		switch (aux->info) {
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
				textcolor(WHITE);
				cprintf("[C] ");
				break;
			}
			case 63: {
				textcolor(WHITE);
				cprintf("[+4] ");
				break;
			}
		}
		aux=aux->prox;
	}
}

void imprime_listase(tp_listase *l) {
	tp_listase *aux;
	aux=l;
	
	while (aux!=NULL){
		printf("%d ", aux->info);
		aux = aux->prox;
	}
}

int remove_listase(tp_listase **l, tp_item e) {
	tp_listase * ant, *atu;
	atu=*l;
	ant=NULL;
	
	while ((atu!=NULL) && (atu->info!=e)) {
		ant=atu;
		atu=atu->prox;	
	}
	
	// não foi encontrado o elemento
	if (atu==NULL) return 0; 
	
	// se for retirado o primeiro termo
	if (ant==NULL) {
		
		// fazendo a lista apontar para o termo subsequente que foi retirado
		*l=atu->prox; 
	} else {
		
		// fazendo a interligação entre o termo anterior e o termo subsequente ao termo retirado
		ant->prox=atu->prox; 
	}
	
	free(atu);
	atu=NULL;
	
	return 1;
}

tp_item busca(tp_listase **l, tp_item e) {
	tp_listase *atu;
	atu=*l;
	
	while((atu!=NULL) && (atu->info!=e)) {
		atu=atu->prox;
	}
	
	if (atu==NULL) return 0;
	
	return atu->info;
}

tp_item busca_listase(tp_listase **l, tp_item e) {
	tp_listase *atu;
	atu=*l;
	
	while((atu!=NULL) && (atu->info!=e)) {
		atu=atu->prox;
	}
	
	if (atu==NULL) return 0;

	return 1;
}

int tamanho_listase(tp_listase **l) {
    int cont=0;
    
    tp_listase *atu;
    atu=*l;
    
    while (atu!=NULL) {
        cont++;
        atu=atu->prox;
    }
    
    return cont;
}

void destroi_listase(tp_listase **l) {
	tp_listase *atu;
	atu=*l;
	
	while (atu!=NULL) {
		*l=atu->prox;
		free(atu);
		atu=*l;
	}
	
	*l=NULL;
}

#endif


