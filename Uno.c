// Biblioteca que contém as funções da estrutura de dados "pilha".
#include "pilha.h"

// Biblioteca que contém as funções da estrutura de dados "lista simplesmente encadeada".
#include "listase.h"

// Biblioteca que possui funções envolvendo alocação de memória, controle de processos, dentre outras.
#include <stdlib.h>

// Biblioteca que possui as funções para manipulação de Strings.
#include <string.h>

// Biblioteca que possui as funções para manipulação de Char.
#include <ctype.h>

// Biblioteca que possui funções para manipulação de datas e horários.
#include <time.h>

// Biblioteca que possui funções de coloração de ambiente.
#include <conio2.h>

// Biblioteca que possui funções para mudar a linguagem do programa.
#include <locale.h>

// Biblioteca que possui funções de coordenadas, dentre outras.
#include <windows.h>

// Define a quantidade de cartas (108).
#define TAM 108

// Função pra deslocar o cursor.
void coordinates(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE), coord);
}

// Função contendo a tela de carregamento.
void loading() { 
	int x = 51, y = 10;
	cprintf("\n\n\n\n\n\n\n\n\n				                 CARREGANDO UNO\n");
	coordinates(x, y);
	
	// Comando responsável por segurar, neste caso, 1s antes de aparecer o próximo comando.
	sleep(1);
	cprintf("***");
	sleep(1);
	cprintf("***");
	sleep(2);
	cprintf("***");
}

// Função que possui o título.
void print_Title() {
	
	// Função da biblioteca conio2 para mudar a cor do output
	textcolor(RED + BLUE);
	printf("\n\n\n");
	
	// Foram utilizados vários output para que não houvesse nenhum tipo de bug, pois o título é muito grande.
	printf("	 		 		  :::    ::: ::::    :::  ::::::::  \n");
	printf("	 	 			  :+:    :+: :+:+:   :+: :+:    :+: \n");
	printf("	 		 		  +:+    +:+ :+:+:+  +:+ +:+    +:+ \n");
	printf("			 		  +#+    +:+ +#+ +:+ +#+ +#+    +:+ \n");
	printf("	 	 			  +#+    +#+ +#+  +#+#+# +#+    +#+ \n");
	printf("			 	 	  #+#    #+# #+#   #+#+# #+#    #+# \n");
	printf("	 		 		   ########  ###    ####  ########  \n\n\n\n");
}

// Função para armazenar qualquer tecla digitada.
void wait_For_Enter() {
	char erro;
	fflush(stdin);
	scanf("%c", &erro);
}

// Função contendo o menu principal do jogo.
int mainMenu() {
	int menu, x = 56, y = 21;
	
	/* Laço para fazer com que o usuário consiga voltar ao menu caso selecione a 
	segunda opção ou digite qualquer outro valor fora das opções do menu. */
	while (1) {
		system("cls");
		
		// Função da conio para mudar a cor do título para roxo.
		textcolor(RED + BLUE);
		
		// Função que contém o título, dessa forma o título vai sempre aparecer na tela, tornando o ambiente mais agradável.
		print_Title();
		
		// Menu de opções para o usuário.
		cprintf("  						 Novo Jogo -> [1]\n\n");
		cprintf(" 					 	 Créditos  -> [2]\n\n");
		cprintf(" 					 	 Regras    -> [3]\n\n");
		cprintf(" 						 Sair      -> [0]\n\n");
		cprintf("                                                       [ ]");
		
		// Centralizar o cursor.
		coordinates(x, y);
		scanf("%d", &menu);
		
		// Irá receber o número que o usuário digitou e entrar no switch.
		switch(menu) {
			
			// Finaliza o jogo.
			case 0: 
			
			// Inicia um novo jogo.
			case 1: {
				
				// Serve para parar o laço e retornar o valor 1 ou 0 para a função mainMenu.
				return menu;
			}
			
			// Contém os créditos do jogo
			case 2: {
				system("cls");
				print_Title();
				textcolor(RED + BLUE);
				cprintf("Jogo desenvolvido na disciplina de Estrutura de Dados, no curso de Ciência da Computação.\n\n");
				textcolor(RED + BLUE);
				cprintf("Professor:\n");
				textcolor(WHITE);
				cprintf("Márcio Soussa\n\n");
				textcolor(RED + BLUE);
				cprintf("Desenvolvedor:\n");
				textcolor(WHITE);
				cprintf("Rafael Luna\n\n");
				textcolor(RED + BLUE);
				cprintf("Precione Enter para retornar ao Menu Principal.");
				
				wait_For_Enter();
				break;
			}
			
			// Contém as regras do jogo.
			case 3: {
				system("cls");
				print_Title();
				textcolor(RED + BLUE);
				cprintf("Como jogar: \n");
				textcolor(WHITE);
				cprintf("Digite no formato CN (C = apenas a inicial da cor da carta em ingles) e N = Número da carta.");
				cprintf("\nPara as cartas de ataque C+ (+2), FC (+4), CB (bloqueio), CI (inverso).\n\n");
				textcolor(RED + BLUE);
				cprintf("Regras: \n");
				textcolor(WHITE);
				cprintf("O player pode jogar uma carta igual à da mesa (numeração ou ataque) ou de mesma cor.");
				cprintf("\nQuando restar apenas uma carta na mão do player ele deve pedir \"UNO\", caso contrário cava 2 cartas.\n\n");
				textcolor(RED + BLUE);
				cprintf("Precione enter para retornar ao Menu Principal. ");
				wait_For_Enter();
				break;
			}
			
			// Caso o usuário digite qualquer outra coisa que não esteja no menu de opções irá aparecer a seguinte mensagem.
			default: {
				system("cls");
				textcolor(RED);
				cprintf("Código inválido!!!\nPrecione Enter para retornar ao Menu Principal.");
				wait_For_Enter();
				break;
			}		 	
		}
	}
}

// Função que preenche o vetor com todas as cartas.
void cria_Baralho(tp_item baralhoAux[TAM]) {
	/*
	-Cor Vermelha "1" -
		10 = 0
		11 = 1
		12 = 2
		13 = 3
		14 = 4
		15 = 5
		16 = 6
		17 = 7
		18 = 8
		19 = 9
		.......
		50 = block
		51 = inverso
		52 = +2
	   
	-Cor Amarela "2"
		20 = 0
		21 = 1
		22 = 2
		.......
		53 = block
		54 = inverso
		55 = +2
		
	- Cor Verde "3" 
		30 = 0
		31 = 1
		32 = 2
		.......	
		56 = block
		57 = inverso
		58 = +2
		
	- Cor Azul "4"
		40 = 0
		41 = 1
		42 = 2s
		.......
		59 = block
		60 = inverso
		61 = +2
	
	- 62 = coringa
	- 63 = +4	*/
	int i = 0, aux = 10;
	
	// Laço para preencher o vetor com todas as 108 cartas.
	while (i < TAM) {
		
		/* Inicialmente preenche o vetor com as 52 primeiras cartas,
		sendo elas 1 de cada cor. */
		while (i < 52) {
			baralhoAux[i] = aux;
			aux += 1;
			i++;
		} 

		// Reseta a variável aux para 10 que corresponde à primeira carta 0.
		aux = 10;

		/* Como no tabuleiro só existe 4 cartas de número 0, e 8 cartas dos outros tipos
		preencha novamente sem colocar os números correspondentes à carta 0. */
		while (i >= 52 && i < 100) {
			if (aux == 10 || aux == 20 || aux == 30 || aux == 40) aux += 1;

			baralhoAux[i] = aux;
			aux += 1;
			i++;
		}

		// Laço para preencher o vetor com as cartas coringas (cor e +4).
		while (i < 108 && i >= 100) {
			aux = 62;
			baralhoAux[i] = aux;
			i++;
			
			aux = 63;
			baralhoAux[i] = aux;
			i++;
		}		
	}
}

// Função para embaralhar as cartas no vetor.
void embaralha(tp_item baralhoAux[TAM]) {
	
	// Semente para  função randômica.
	srand(time(NULL));

	int i = 0, aux, aux1, aux2;

	while (i < 200) {
		
		// Gera dois valores aleatórios para o índice do vetor com as cartas.
		aux1 = rand()%108;
		aux2 = rand()%108;

		/* Faz a troca entre esses dois valores gerados, 
		pega a carta X e troca de posição com a carta Y 
		embaralhando todas as cartas antes de empilhar.*/
		aux = baralhoAux[aux1];
		baralhoAux[aux1] = baralhoAux[aux2];
		baralhoAux[aux2] = aux;
	
		i++;
	}	
}

// Função que empilha o baralho.
void empilha_Baralho(tp_pilha *pbaralho, tp_item baralhoAux[TAM]) {
	int i = 0;
	
	// Função pra preencher a pilha com as cartas.
	for (i = 0; i < TAM; i++) {
		push(pbaralho, baralhoAux[i]);
	}
}

// Função que coloca a primeira carta na mesa.
// **baralho = ponteiro que aponta pro endereço de memória de *baralho, que este por sua vez, aponta para o meu baralho.
int inicializaJogo(tp_pilha **baralho, tp_pilha *mesa) {
	int i = 0;
	tp_item e;
	
	/* Vetor pra armazenar as cartas de ataque que não podem ser jogadas na mesa inicialmente.
	o jogo possui 32 cartas de ataque */
	tp_item *vet;
	vet = (tp_item *) malloc(sizeof(tp_item) * 32);
	if (vet == NULL) return 0;
		
	int cont = 1;
		
	// Repete até que a mesa esteja com a carta inicial.
	while (cont == 1) {
		pop(*baralho, &e);
	
		// Verifica se o elemento retirado do baralho é uma carta de ataque, se for entra no laço.
		while (e >= 50) {
				
			// Guarda essa carta no vetor.
			*(vet + i) = e;
			i++;
			pop(*baralho, &e);
		}
			
		// Se encontrar uma carta número, joga ela na mesa.
		push(mesa, e);
		cont = 2;
		i = 0;
			
		// Todas as cartas que foram guardadas no vetor são colocadas novamente no baralho.
		while (altura_pilha(*baralho) != TAM - 1) {
			e = *(vet + i);
			i++;
			push(*baralho, e);
		}
		
		// Libera vetor dinâmico. 
		free(vet);
		
		// Faz ele apontar pra nulo, assim evitando entrada de vírus.
		vet = NULL;
	}
}

// Função para preencher a mão dos players com as 7 primeiras cartas
void preenche(tp_listase **p1, tp_listase **p2, tp_listase **p3, tp_listase **p4, tp_pilha **baralho) {
	int i = 0;
	tp_item e;

	// Cada laço preenche a mão dos players com as 7 cartas iniciais.
	// Player 1.
	for (i = 0; i < 7; i++) {
		pop(*baralho, &e);
		insere_listase(p1, e);
	}
	
	// Player 2.
	for (i = 0; i < 7; i++) {
		pop(*baralho, &e);
		insere_listase(p2, e);
	}
	
	// Player 3.
	for (i = 0; i < 7; i++) {
		pop(*baralho, &e);
		insere_listase(p3, e);
	}
	
	// Player 4.
	for (i = 0; i < 7; i++) {
		pop(*baralho, &e);
		insere_listase(p4, e);
	}
}

// Função que verifica se a carta do jogador encaixa com a da mesa.
int verifica(tp_listase ***p, tp_pilha *mesa) {
	/* Verifica se a carta que está na mesa é compatível com alguma carta de mesmo número da mão do jogador.
	limita para pesquisar somente as cartas númericas que vão de 10 até 49. 
	Busca o elemento na lista e acrescenta ou decrementa até verificar todas as possibilidades. */
	// Logo depois ele vai verificar se o jogador tem alguma corta de cor compatível com a da mesa.
	// Por fim ele vai verificar se o player tem alguma carta de ataque.
	// Caso ele não tenha nada, então ele deve cavar da pilha.
	int cont = 0;
	int x = 10;
	tp_item e;

	// Busca carta de mesmo número.
	while (x <= 30) {
		if (top(mesa) >= 10 && top(mesa) <= 49) {
			if (busca_listase(*p, top(mesa)) || (busca(*p, top(mesa) + x) >= 10 && busca(*p, top(mesa) + x) <= 49) || (busca(*p, top(mesa) - x) >= 10 && busca(*p, top(mesa) - x) <= 49)) {	
				cont = 1;
			}
		}
		x += 10;
	}

	// Busca carta de ataque da mesma cor da carta da mesa.
	x = 50;
	while (x <= 61) {
		
		// Vermelho.
		if (x >= 50 && x <= 52) {
			if ((busca_listase(*p, x)) && ((top(mesa) >= 10 && top(mesa) <= 19) || (top(mesa) >= 50 && top(mesa) <= 52) || (top(mesa) == 62) || (top(mesa) == 66))) {
				cont = 1;
			}
		}
		
		// Amarelo.
		if (x >= 53 && x <= 55) {
			if ((busca_listase(*p, x)) && ((top(mesa) >= 20 && top(mesa) <= 29) || (top(mesa) >= 53 && top(mesa) <= 55) || (top(mesa) == 63) || (top(mesa) == 67))) {
				cont = 1;
			}
		}
		
		// Verde.
		if (x >= 56 && x <= 58)	 {
			if ((busca_listase(*p, x)) && ((top(mesa) >= 30 && top(mesa) <= 39) || (top(mesa) >= 56 && top(mesa) <= 58) || (top(mesa) == 64) || (top(mesa) == 68))) {
				cont = 1;
			}
		}
		
		// Azul.
		if (x >= 59 && x <= 61) {
			if ((busca_listase(*p, x)) && ((top(mesa) >= 40 && top(mesa) <= 49) || (top(mesa) >= 59 && top(mesa) <= 61) || (top(mesa) == 65) || (top(mesa) == 69))) {
				cont = 1;
			}
		}	
		x += 1;
	}
	
	// Busca carta de mesmo ataque.
	x = 0;
	while (x <= 9) {
		if (busca_listase(*p, top(mesa)) || (busca(*p, top(mesa) + x) >= 50 && busca(*p, top(mesa) + x) <= 61) || (busca(*p, top(mesa) - x) >= 50 && busca(*p, top(mesa) - x) <= 61)) {
			cont = 1;
		}
		x += 3;
	}
		
	// Busca carta coringa.
	if (busca_listase(*p, 62) || busca_listase(*p, 63)) {
		cont = 1;
	}
				
	// Busca carta da cor da mesa.
	// Vermelho.
	if ((top(mesa) >= 10 && top(mesa) <= 19) || (top(mesa) >= 50 && top(mesa) <= 52) || (top(mesa) == 62 || top(mesa) == 66)) {
		x = 10;	 
		while (x <= 19) {	
			if ((busca(*p, x) >= 10) && (busca(*p, x) <= 19)) {
				cont = 1;
			}
			x += 1;
		}
	}
			
	// Amarelo.
	if ((top(mesa) >= 20 && top(mesa) <= 29) || (top(mesa) >= 53 && top(mesa) <= 55) || (top(mesa) == 63 || top(mesa) == 67)) {
		x = 20;
		while (x <= 29) {			
			if ((busca(*p, x) >= 20) && (busca(*p, x) <= 29)) {
				cont = 1;
			}
			x += 1;
		}
	}
			
	// Verde.
	if ((top(mesa) >= 30 && top(mesa) <= 39) || (top(mesa) >= 56 && top(mesa) <= 58) || (top(mesa) == 64 || top(mesa) == 68)) {
		x = 30;
		while (x <= 39) {
			if ((busca(*p, x) >= 30) && (busca(*p, x) <= 39)) {
				cont = 1;
			}
			x += 1;
		}
	}
	
	// Azul.
	if ((top(mesa) >= 40 && top(mesa) <= 49) || (top(mesa) >= 59 && top(mesa) <= 61) || (top(mesa) == 65 || top(mesa) == 69)) {
		x = 40;
		while (x <= 49) {		
			if ((busca(*p, x) >= 40) && (busca(*p, x) <= 49)) {
				cont = 1;
			}
			x += 1;
		}
	}
	
	// Significa que achou uma carta compatível com a mesa.
	if (cont == 1) return 1;
	
	// Significa que não achou uma carta compatível com a mesa.
	else return 0;	
}

// Se a mão do jogador estiver vazia, significa que esse jogador ganhou o jogo.
int win(tp_listase **p1, tp_listase **p2, tp_listase **p3, tp_listase **p4) {
	if (listase_vazia(*p1)) {
		system("cls");
		printf("PARABÉNS, O PLAYER 1 VENCEU!!!");
		printf("\nPrecione enter para voltar ao menu!");
		wait_For_Enter();
		return main();
	}
	if (listase_vazia(*p2)) {
		system("cls");
		printf("PARABÉNS, O PLAYER 2 VENCEU!!!");
		printf("\nPrecione enter para voltar ao menu!");
		wait_For_Enter();
		return main();	
	}
	if (listase_vazia(*p3)) {
		system("cls");
		printf("PARABÉNS, O PLAYER 3 VENCEU!!!");
		printf("\nPrecione enter para voltar ao menu!");
		wait_For_Enter();
		return main();
	}
	if (listase_vazia(*p4)) {
		system("cls");
		printf("PARABÉNS, O PLAYER 4 VENCEU!!!");
		printf("\nPrecione enter para voltar ao menu!");
		wait_For_Enter();
		return main();
	}

	// Ninguém ganhou ainda.	
	return 1;
}

// Função que retorna o input do player da carta que ele quer jogar.
int converte(char *carta) {	
	// O player deve digitar primeiro a inicial da cor da carta em maiúsculo e logo em seguida o número ou a ação.
	// Exemplo "BB" == Blue BLock, FR == For Red (+4 vermelho), GI == Green inversor (vai e volta verde).
	// Carta vermelha (Red).
	// Red Número.
	if (strstr(carta, "R0")) return 10;
	if (strstr(carta, "R1")) return 11;
	if (strstr(carta, "R2")) return 12;
	if (strstr(carta, "R3")) return 13;
	if (strstr(carta, "R4")) return 14;
	if (strstr(carta, "R5")) return 15;
	if (strstr(carta, "R6")) return 16;
	if (strstr(carta, "R7")) return 17;
	if (strstr(carta, "R8")) return 18;
	if (strstr(carta, "R9")) return 19;
	// Red Block.
	if (strstr(carta, "RB")) return 50;
	// Red Inversor.
	if (strstr(carta, "RI")) return 51;
	// +2 Red.
	if (strstr(carta, "R+")) return 52;
	
	// Carta amarela (Yellow).
	if (strstr(carta, "Y0")) return 20;
	if (strstr(carta, "Y1")) return 21;
	if (strstr(carta, "Y2")) return 22;
	if (strstr(carta, "Y3")) return 23;
	if (strstr(carta, "Y4")) return 24;
	if (strstr(carta, "Y5")) return 25;
	if (strstr(carta, "Y6")) return 26;
	if (strstr(carta, "Y7")) return 27;
	if (strstr(carta, "Y8")) return 28;
	if (strstr(carta, "Y9")) return 29;
	if (strstr(carta, "YB")) return 53;
	if (strstr(carta, "YI")) return 54;
	if (strstr(carta, "Y+")) return 55;
	
	// Carta verde (Green).
	if (strstr(carta, "G0")) return 30;
	if (strstr(carta, "G1")) return 31;
	if (strstr(carta, "G2")) return 32;
	if (strstr(carta, "G3")) return 33;
	if (strstr(carta, "G4")) return 34;
	if (strstr(carta, "G5")) return 35;
	if (strstr(carta, "G6")) return 36;
	if (strstr(carta, "G7")) return 37;
	if (strstr(carta, "G8")) return 38;
	if (strstr(carta, "G9")) return 39;
	if (strstr(carta, "GB")) return 56;
	if (strstr(carta, "GI")) return 57;
	if (strstr(carta, "G+")) return 58;
			
	// Carta azul (Blue).
	if (strstr(carta, "B0")) return 40;
	if (strstr(carta, "B1")) return 41;
	if (strstr(carta, "B2")) return 42;
	if (strstr(carta, "B3")) return 43;
	if (strstr(carta, "B4")) return 44;
	if (strstr(carta, "B5")) return 45;
	if (strstr(carta, "B6")) return 46;
	if (strstr(carta, "B7")) return 47;
	if (strstr(carta, "B8")) return 48;
	if (strstr(carta, "B9")) return 49;
	if (strstr(carta, "BB")) return 59;
	if (strstr(carta, "BI")) return 60;
	if (strstr(carta, "B+")) return 61;

	// Cartas curingas (Cor e +4(Four)).
	if (strstr(carta, "CR")) return 62;	
	if (strstr(carta, "CY")) return 63;
	if (strstr(carta, "CG")) return 64;
	if (strstr(carta, "CB")) return 65;
	if (strstr(carta, "FR")) return 66;
	if (strstr(carta, "FY")) return 67;
	if (strstr(carta, "FG")) return 68;
	if (strstr(carta, "FB")) return 69;
	
	// Significa que ele digitou algo que não existe.
	return -5;
}

// Função para printar todo o tabuleiro.
void printTabuleiro(tp_listase **p1, tp_listase **p2, tp_listase **p3, tp_listase **p4, tp_pilha *mesa, tp_pilha **baralho, int cont) {	
	int x = 0;
	textcolor(WHITE);	
    cprintf("                                               (cave)");
	cprintf("\n                                                 [?]\n\n\n");
	printf("                                                        ");
	// Printa o topo da pilha que representa a mesa.
	top2(mesa);
	printf("\n\n\n ");
	textcolor(BROWN);
	
	/* Se for o player 1 a jogar, ele faz uma dinâmica para que só mostre as cartas do player 1 e a quantidade de cartas
	existentes na mão de todos os players. */
	if (cont == 0)	{
		textcolor(BROWN);
		cprintf("                                  P(%d) =  ", cont + 1);
		imprime(*p1);
		
		textcolor(BROWN);
		cprintf("\n\n                                   p(%d) =  ", cont + 2);
		textcolor(WHITE);
		while (x < tamanho_listase(p2)) {
			printf("[?] ");
			x++;
		}
		
		x = 0;
		textcolor(BROWN);
		cprintf("\n\n                                   p(%d) =  ", cont + 3);
		textcolor(WHITE);
		while (x < tamanho_listase(p3)) {
			printf("[?] ")/
			x++;
		}
		
		x = 0;
		textcolor(BROWN);
		cprintf("\n\n                                   p(%d) =  ", cont + 4);
		textcolor(WHITE);
		while (x < tamanho_listase(p4)) {
			printf("[?] ")/
			x++;
		}
		
	/* Se for o player 2 a jogar, ele faz uma dinâmica para que só mostre as cartas do player 1 e a quantidade de cartas
	existentes na mão de todos os players. */
	} else if (cont == 1) {
		textcolor(BROWN);
		cprintf("\n\n                                   P(%d) =  ", cont);
		textcolor(WHITE);
		while (x < tamanho_listase(p1)) {
			printf("[?] ");
			x++;
		}
		
		textcolor(BROWN);
		cprintf("\n\n                                   p(%d) =  ", cont + 1);
		imprime(*p2);
		
		x = 0;
		textcolor(BROWN);
		cprintf("\n\n                                   p(%d) =  ", cont + 2);
		textcolor(WHITE);
		while (x < tamanho_listase(p3)) {
			printf("[?] ")/
			x++;
		}
		
		x = 0;
		textcolor(BROWN);
		cprintf("\n\n                                   p(%d) =  ", cont + 3);
		textcolor(WHITE);
		while (x < tamanho_listase(p4)) {
			printf("[?] ")/
			x++;
		}
	
	/* Se for o player 3 a jogar, ele faz uma dinâmica para que só mostre as cartas do player 1 e a quantidade de cartas
	existentes na mão de todos os players. */
	} else if (cont == 2) {
		textcolor(BROWN);
		cprintf("\n\n                                   P(%d) =  ", cont - 1);
		textcolor(WHITE);
		while (x < tamanho_listase(p1)) {
			printf("[?] ");
			x++;
		}
		
		x = 0;
		textcolor(BROWN);
		cprintf("\n\n                                   p(%d) =  ", cont);
		textcolor(WHITE);
		while (x < tamanho_listase(p2)) {
			printf("[?] ");
			x++;
		}
		
		textcolor(BROWN);
		cprintf("\n\n                                   p(%d) =  ", cont + 1);
		imprime(*p3);
	
		
		x = 0;
		textcolor(BROWN);
		cprintf("\n\n                                   p(%d) =  ", cont + 2);
		textcolor(WHITE);
		while (x < tamanho_listase(p4)) {
			printf("[?] ")/
			x++;
		}
		
	/* Se for o player 4 a jogar, ele faz uma dinâmica para que só mostre as cartas do player 1 e a quantidade de cartas
	existentes na mão de todos os players. */
	} else {
		textcolor(BROWN);
		cprintf("\n\n                                   P(%d) =  ", cont - 2);
		textcolor(WHITE);
		while (x < tamanho_listase(p1)) {
			printf("[?] ");
			x++;
		}
		
		x = 0;
		textcolor(BROWN);
		cprintf("\n\n                                   p(%d) =  ", cont - 1);
		textcolor(WHITE);
		while (x < tamanho_listase(p2)) {
			printf("[?] ");
			x++;
		}
		
		x = 0;
		textcolor(BROWN);
		cprintf("\n\n                                   p(%d) =  ", cont);
		textcolor(WHITE);
		while (x < tamanho_listase(p3)) {
			printf("[?] ");
			x++;
		}
		
		textcolor(BROWN);
		cprintf("\n\n                                   p(%d) =  ", cont + 1);
		textcolor(WHITE);
		imprime(*p4);
	}
	textcolor(WHITE);	
}

int jogaCarta(tp_listase ***p, tp_pilha *mesa, char *carta) {
	tp_item e;
	static int aux = 2;
	
	/* -Retorna 1 se conseguir jogar uma carta númerica ou de cor
	-Retorna -1 se conseguir jogar uma carta bloqueio ou +2
	-Retorna aux (par) se o inverso for sentido horário ou aux(ímpar) se o inverso for sentiro anti horário
	-Retorna -2 se conseguir jogar uma carta +4
	-Retorna -5 se não conseguir jogar nenhuma carta (incompatível)*/
	int x = 10;
	// Se o player desejar jogar uma carta de mesmo número independente da cor.
	while (x <= 40) {
		if ((converte(carta) >= 10 && converte(carta) <= 49) && (top(mesa) >= 10 && top(mesa) <= 49)) {
			if ((converte(carta) == top(mesa)) || ((converte(carta) + x) >= 10 && (converte(carta) + x) <= 49 && (converte(carta) + x) == top(mesa)) || ((converte(carta) - x) >= 10 && (converte(carta) - x) <= 49 && (converte(carta) - x) == top(mesa))) {
				e = converte(carta);
				remove_listase(*p, e);
				push(mesa, e);
				return 1;
			}
		}
		x += 10;
	}
	
	// Se o player desejar jogar uma carta de mesma cor.
	// Vermelho.
	if (((top(mesa) >= 10 && top(mesa) <= 19) || (top(mesa) >= 50 && top(mesa) <= 52) || (top(mesa) == 62 || top(mesa) == 66)) && ((converte(carta) >= 10 && converte(carta) <= 19))) {
		e = converte(carta);
		remove_listase(*p, e);
		push(mesa, e);
		return 1;
	}
		
	// Amarelo.
	if (((top(mesa) >= 20 && top(mesa) <= 29) || (top(mesa) >= 53 && top(mesa) <= 55) || (top(mesa) == 63 || top(mesa) == 67)) && ((converte(carta) >= 20 && converte(carta) <= 29))) {
		e = converte(carta);
		remove_listase(*p, e);
		push(mesa, e);
		return 1;
	}
		
	// Verde.
	if (((top(mesa) >= 30 && top(mesa) <= 39) || (top(mesa) >= 56 && top(mesa) <= 58) || (top(mesa) == 64 || top(mesa) == 68)) && ((converte(carta) >= 30 && converte(carta) <= 39))) {
		e = converte(carta);
		remove_listase(*p, e);
		push(mesa, e);
		return 1;
	}
		
	// Azul.
	if (((top(mesa) >= 40 && top(mesa) <= 49) || (top(mesa) >= 59 && top(mesa) <= 61) || (top(mesa) == 65 || top(mesa) == 69)) && ((converte(carta) >= 40 && converte(carta) <= 49))) {
		e = converte(carta);
		remove_listase(*p, e);
		push(mesa, e);
		return 1;
	}
		
	// Se o player desejar jogar uma carta especial (bloqueio) ou (+2) da mesma cor da mesa.
	// Vermelho.
	if (((top(mesa) >= 10 && top(mesa) <= 19) || (top(mesa) >= 50 && top(mesa) <= 52) || (top(mesa) == 62 || top(mesa) == 66)) && ((converte(carta) == 50) || (converte(carta) == 52))) {
		e = converte(carta);
		remove_listase(*p, e);
		push(mesa, e);
		return -1;	
	}
	
	// Amarelo.
	if (((top(mesa) >= 20 && top(mesa) <= 29) || (top(mesa) >= 53 && top(mesa) <= 55) || (top(mesa) == 63 || top(mesa) == 67)) && ((converte(carta) == 53) || (converte(carta) == 55))) {
		e = converte(carta);
		remove_listase(*p, e);
		push(mesa, e);
		return -1;	
	}
		
	// Verde.
	if (((top(mesa) >= 30 && top(mesa) <= 39) || (top(mesa) >= 56 && top(mesa) <= 58) || (top(mesa) == 64 || top(mesa) == 68)) && ((converte(carta) == 56) || (converte(carta) == 58))) {
		e = converte(carta);
		remove_listase(*p, e);
		push(mesa, e);
		return -1;	
	}
		
	// Azul.
	if (((top(mesa) >= 40 && top(mesa) <= 49) || (top(mesa) >= 59 && top(mesa) <= 61) || (top(mesa) == 65 || top(mesa) == 69)) && ((converte(carta) == 59) || (converte(carta) == 61))) {
		e = converte(carta);
		remove_listase(*p, e);
		push(mesa, e);
		return -1;
	}
		
	// Se o player desejar jogar uma carta especial (bloqueio) ou (+2) igual à da mesa independe da cor.
	x = 0;
	while (x <= 9) {
		if ((top(mesa) >= 50 && top(mesa) <= 61) && ((converte(carta) == top(mesa)) || (converte(carta) == (top(mesa) + x)) || (converte(carta) == (top(mesa) - x)))) {
			if (!((converte(carta) == 51) || (converte(carta) == 54) || (converte(carta) == 57) || (converte(carta) == 60))) {
				e = converte(carta);
				remove_listase(*p, e);
				push(mesa, e);
				return -1;
			}
		}
		x += 3;
	}
		
	// Se o player desejar jogar uma carta especial (inverso) da mesma cor da mesa.
	// Vermelho.
	if (((top(mesa) >= 10 && top(mesa) <= 19) || (top(mesa) >= 50 && top(mesa) <= 52) || (top(mesa) == 62 || top(mesa) == 66)) && (converte(carta) == 51)) {
		e = converte(carta);
		remove_listase(*p, e);
		push(mesa, e);
		aux++;
		return aux;	
	}
		
	// Amarelo.
	if (((top(mesa) >= 20 && top(mesa) <= 29) || (top(mesa) >= 53 && top(mesa) <= 55) || (top(mesa) == 63 || top(mesa) == 67)) && (converte(carta) == 54)) {
		e = converte(carta);
		remove_listase(*p, e);
		push(mesa, e);
		aux++;
		return aux;
	}
		
	// Verde.
	if (((top(mesa) >= 30 && top(mesa) <= 39) || (top(mesa) >= 56 && top(mesa) <= 58) || (top(mesa) == 64 || top(mesa) == 68)) && (converte(carta) == 57)) {
		e = converte(carta);
		remove_listase(*p, e);
		push(mesa, e);
		aux++;
		return aux;		
	}
		
	// Azul.
	if (((top(mesa) >= 40 && top(mesa) <= 49) || (top(mesa) >= 59 && top(mesa) <= 61) || (top(mesa) == 65 || top(mesa) == 69)) && (converte(carta) == 60)) {
		e = converte(carta);
		remove_listase(*p, e);
		push(mesa, e);
		aux++;
		return aux;	
	}
		
	// Se o player desejar jogar uma carta especial (inverso) igual à da mesa independente da cor.
	x = 0;
	while (x <= 9) {
		if ((top(mesa) >= 50 && top(mesa) <= 61) && ((converte(carta) == top(mesa)) || ((converte(carta) + x) == top(mesa)) || ((converte(carta) - x) == top(mesa)))) {
			if ((converte(carta) == 51) || (converte(carta) == 54) || (converte(carta) == 57) || (converte(carta) == 60)) {
				e = converte(carta);
				remove_listase(*p, e);
				push(mesa, e);
				aux++;
				return aux;
			}
		}
		x += 3;
	}
		
	// Se o player desejar jogar uma carta coringa de cor:
	// vermelho.
	if (converte(carta) == 62) {
		if (remove_listase(*p, 62)) {
			push(mesa, 62);
			return 1;
		} else return -5;
	}
		
	// Amarelo.
	if (converte(carta) == 63) {
		if (remove_listase(*p, 62)) {
			push(mesa, 63);
			return 1;
		} else return -5;	
	}
		
	// Verde.
	if (converte(carta) == 64) {
		if (remove_listase(*p, 62)) {
			push(mesa, 64);
			return 1;
		} else return -5;
	}
		
	// Azul.
	if (converte(carta) == 65) {
		if (remove_listase(*p, 62)) {
			push(mesa, 65);
			return 1;
		} else return -5;	
	}
		
	// Se o player jogar uma carta coringa +4 retornando -2:
	// Vermelho.
	if (converte(carta) == 66) {
		if (remove_listase(*p, 63)) {
			push(mesa, 66);
			return -2;
		} else return -5;	
	}
		
	// Amarelo.
	if (converte(carta) == 67) {
		if (remove_listase(*p, 63)) {
			push(mesa, 67);
			return -2;
		} else -5;
	}
		
	// Verde.
	if (converte(carta) == 68) {
		if (remove_listase(*p, 63)) {
			push(mesa, 68);
			return -2;
		} else -5;
	}
		
	// Azul.
	if (converte(carta) == 69) {
		if (remove_listase(*p, 63)) {
			push(mesa, 69);
			return -2;
		} else -5;
	}
	return -5;
}

// Função que inverte o jogo e que faz passar a vez para o próximo player.
void inversor(int *inverte, int *cont) {
	// Lógica para inverter o game ou apenas passar a vez para o próximo player.
	// Sentido horário.
	if (*inverte % 2 == 0){
		*cont += 1;
		if (*cont > 3) *cont = 0;
		
	// Sentido anti horário.
	} else {
		*cont -= 1;
		if (*cont < 0) *cont = 3;
	}
}

// Função que bloqueia.
void block(int *bloqueio, int *inverte, int *cont) {
	// Lógica para bloquear o próximo player (faz basicamente a mesma coisa da função "inversor").
	if (*bloqueio == -1) {
		if (*inverte % 2 == 0) {
			*cont += 1;
			if (*cont > 3) *cont = 0;
		} else {
			*cont -= 1;
			if (*cont < 0) *cont =0;
		}
		*bloqueio = 0;
	}
}

// Função para as cartas +2 e +4.
int cavar(int *cave, char *carta, tp_listase ***p, tp_pilha **baralho) {
	tp_item e;
	int i = 0;
	// Payer cavar +2.
	if (*cave == -1) {
		while (i <= 1) {
			pop(*baralho, &e);
			insere_listase(*p, e);
			++i;
		}
		return 1;
	}
	
	// Player cavar +4.
	if (*cave == -2) {
		while (i <= 3) {
			pop(*baralho, &e);
			insere_listase(*p, e);
			++i;
		}
		return 1;
	}
	return 0;
}

// Função que verifica se o player pediu "UNO".
int gritaUno(tp_listase **p) {
	
	// Array pra armazenar a resposta do player.
	char grita[10];
	
	// Verifica se o player só resta jogar 1 carta.
	if (tamanho_listase(p) == 1) {
		printf("\n\n\n                                   UNO: ");
		fflush(stdin);
		scanf("%[^\n]s", &grita);
		
		// Se o player pedir "UNO", o jogo segue normalmente.
		if (strstr(grita, "UNO")) return 1;
		
		// Caso contrário ele retorna 0 e o player cava +2 cartas
		else return 0;
	}
	return 1;
}

/* Função que verifica se o baralho está vazio, caso esteja, 
retira todas as cartas da mesa e joga no baralho novamente, 
deixando apenas a que estava no topo. */
void verificaTabuleiro(tp_pilha **baralho, tp_pilha *mesa) {
	tp_item e;
	tp_item topo;
	
	if (pilha_vazia(*baralho)) {
		pop(mesa, &topo);
		while (!pilha_vazia(mesa)) {
			pop(mesa, &e);
			push(*baralho, e);
		}
		push(mesa, topo);
	}
}
// Função onde acontece a dinâmica do jogo.
int dinamica(tp_pilha *baralho) {
	// Cria e inicializa a lista simplesmente encadeada (p == player).
	tp_listase *p1, *p2, *p3, *p4;

	// Inicializa todas as "mãos" dos players.
	p1 = inicializa_listase();
	p2 = inicializa_listase();
	p3 = inicializa_listase();
	p4 = inicializa_listase();
	
	// Cria e inicializa a mesa do jogo.
	tp_pilha mesa;
	inicializa_pilha(&mesa);
	
	// Função que coloca a primeira carta na mesa.
	inicializaJogo(&baralho, &mesa);
	
	// Preenche a mão dos players com as 7 cartas.
	preenche(&p1, &p2, &p3, &p4, &baralho);
	
	// Array (char) para armazenar o input do player.
	char carta[10];
	int cont = 0, inverte = 2, bloqueio = 0, cave = 0, marcador = 0, aux = 1, aux2 = 0;
	
	// Ponteiro de ponteiro para apontar para a mão do player que vai jogar naquele momento.
	tp_listase **p;
	tp_item e;
	
	// Enquanto não houver um player vencedor o jogo continua.
	while (win(&p1, &p2, &p3, &p4)) {
		
		// Função que verifica se o baralho está vazio.
		verificaTabuleiro(&baralho, &mesa);
		// Responsável por mudar de player, de acordo com o cont (crescente ou decrescente).
		if (cont == 0) p = &p1;
		if (cont == 1) p = &p2;
		if (cont == 2) p = &p3;
		if (cont == 3) p = &p4;
		
		system("cls");
		print_Title();
		printTabuleiro(&p1, &p2, &p3, &p4, &mesa, &baralho, cont);
					
		// Verifica se o player tem alguma carta compatível com a mesa.			
		if (verifica(&p, &mesa)) {
			// Armazena o input do player
			printf("\n\n\n                                   Digite: ");
			fflush(stdin);
			scanf("%[^\n]s", &carta);
			
			// Verifica se o player desejou cavar, mesmo tendo cartas disponíveis.
			if (strstr(carta, "E")) {
				pop(baralho, &e);
				insere_listase(p, e);
				inversor(&inverte, &cont);
				aux = 2;
			} 
			
			// Verifica se o player tem a carta que ele desejou jogar.
			if (!(strstr(carta, "E"))) {
				
				// Se ele desejou jogar uma carta coringa e não tiver, na mão do jogador as cartas coringa são, apenas, 62 (COR) e 63(+4).
				if (converte(carta) >= 62 && converte(carta) <= 65) {
					if (!(busca_listase(p, 62))) aux = 3;
				} else if (converte(carta) >= 66 && converte(carta) <= 69) {
					if (!(busca_listase(p, 63))) aux = 3;
				} else if (!(busca_listase(p, converte(carta)))) aux = 3;
				else aux = 1;
				
			}
			
			// Verifica se a carta selecionada foi uma de ataque.
			if (converte(carta) >= 50 && converte(carta) <= 69 && aux == 1) {
				
				// Verifica se foi um bloqueio
				if (converte(carta) == 50 || converte(carta) == 53 || converte(carta) == 56 || converte(carta) == 59) {
					
					// Retorna -1 caso seja um bloqueio.
					bloqueio = jogaCarta(&p, &mesa, carta);
				}
				
				// Verifica se foi um inverso.
				if (converte(carta) == 51 || converte(carta) == 54 || converte(carta) == 57 || converte(carta) == 60) {
					
					// Guarda a ordem do jogo.
					aux2 = inverte;
					// Retorna aux com o valor par se for em ordem crescente ou ímpar se for em ordem decrescente.
					inverte = jogaCarta(&p, &mesa, carta);
					
					// Se não for compatível, atribuo o valor de inverte pra aux, e passo a ordem do jogo novamente.
					if (inverte == -5) {
						aux = inverte;
						inverte = aux2;
					}
				}
					
				// Verifica se foi um +2.
				if (converte(carta) == 52 || converte(carta) == 55 || converte(carta) == 58 || converte(carta) == 61) {
						
					// Retorna -1 caso seja um +2.
					cave = jogaCarta(&p, &mesa, carta);
				}
					
				// Verifica se foi uma carta coringa de cor.
				if (converte(carta) >= 62 && converte(carta) <= 65) {
					
					// Retorna 1.
					aux = jogaCarta(&p, &mesa, carta);
				}
					
				// Verifica se foi uma carta coringa +4.
				if (converte(carta) >= 66 && converte(carta) <= 69) {
					
					// Retorna -2 caso seja um +4.
					cave = jogaCarta(&p, &mesa, carta);
				}
				
				// Caso entre, siginifica que a função da dinâmica de carta de ataque foi acionada.
				marcador = 1;
			}
				
			// Verifica se a carta selecionada foi númerica.
			if(converte(carta) >= 10 && converte(carta) <= 49 && aux == 1) {
				
				// Retorna 1.
				aux = jogaCarta(&p, &mesa, carta);
					
				// Avança uma casa após a jogada.
				if (aux == 1) inversor(&inverte, &cont);
			}
				
			// Verifica se o player jogou uma carta que não é compatível com a da mesa.
			if (!(strstr(carta, "E"))) {
				if (((inverte == -5) || (cave == -5) || (bloqueio == -5) || (aux == -5) || (converte(carta) == -5) || (aux == 3))) {
					textcolor(RED);
					cprintf("\nEssa carta não é compatível, precione enter para jogar novamente!");
					wait_For_Enter();
					// Marcador é zerado e player joga novamente.
					marcador = 0;
				}
			}
		
				
		// Caso não encontre nenhuma carta compatível com a da mesa, o player cava 1 carta.
		} else {	
			pop(baralho, &e);
			insere_listase(p, e);
			
			// Avança para o próximo jogador.
			inversor(&inverte, &cont);
		}
		
		// Condição que, caso retorne 0, faz o player atual cavar +2 caso ele não peça "UNO".
		if (gritaUno(p) == 0) {
			cave = -1;
			cavar(&cave, carta, &p, &baralho);
		}
			
		/* Faz a dinâmica das cartas de ataque, caso algum player jogue o marcador passa a ser 1.
		informando que a dinâmica das cartas de ataque foi ativada. */
		if (marcador) {
				
			// Bloqueia o próximo jogador.
			block(&bloqueio, &inverte, &cont);
				
			// Avança 1, pois o jogador ou foi bloqueado ou vai cavar.
			inversor(&inverte, &cont);
			if (cont == 0) p = &p1;
			if (cont == 1) p = &p2;
			if (cont == 2) p = &p3;
			if (cont == 3) p = &p4;
		
			// Após avançar 1 casa, faz com que esse player cave e logo em seguida avance pro próximo jogador.
			if (cavar(&cave, carta, &p, &baralho)) {

				// Bloqueia o jogador que acabou de cavar.
				bloqueio = -1;
				block(&bloqueio, &inverte, &cont);
			}
		}
			
		// Reseta as variáveis.
		bloqueio = 0;
		cave = 0;
		aux = 1;
		marcador = 0;	
	}	
}

// Função game.
void game() {

	// Cria e inicializa o baralho.
	tp_pilha baralho;
	inicializa_pilha(&baralho);

	// Vetor para auxiliar no desenvolvimento do baralho.
	tp_item baralhoAux[TAM];

	// Função que preenche o array auxiliar com as cartas.
	cria_Baralho(baralhoAux);

	// Função que embaralha todas as cartas no array auxiliar.
	embaralha(baralhoAux);
	
	// Função que remove todas as cartas do array e empilha em uma estrutura de pilha.
	empilha_Baralho(&baralho, baralhoAux);
	
	// Função onde o jogo acontece.
	dinamica(&baralho);	
}

// Função principal.
int main() {
	// Permite que todos os printfs e interação do player seja em português
	setlocale(LC_ALL, "portuguese");

	textcolor(RED + BLUE);
	
	// Variável que faz com que a tela de carregamento apareça apenas 1 vez, após o jogo ser iniciado.
	static int x = 0;
	
	// Chama tela de carregamento.
	if (x == 0) loading();
	
	x = 1;
	system("cls");
	
	// Se mainMenu retornar 1, o jogo foi iniciado.
	if(mainMenu() == 1) {
		game();	
		
	// Do contrário escolheu sair do jogo.
	} else {
		system("cls");
		printf("FINALIZANDO...\n");
		system("pause");
	}
	
	return 0;
}
