//Centro Universitário de Maringá

//MAPA Estrutura de Dados II

//Professores: Erinaldo Sanches e Robson da Mota

//Descrição: O algoritmo lê um arquivo CSV e faz sua ordenação 
//pelo método BubbleSort que foi sorteado com base no número do meu RA.

//Autor: Rafael Rodrigues de Souza

//Data: 07/07/2020

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define Tam 300

//Definindo a estrutura da lista
typedef struct no {
    char satelite[40];
	char orbita[40];
	char banda[50];
	char status[20];
	char posicao[10];
	char direito[20];
	char operador[50];
}no;

//Definindo variáveis
no lista[Tam];
no aux;
int op, cont;

//Prototipação
void prompt_field();
void lista_mostrar();
void lista_mostrar2();
int bubbleSort();
void troca();
void carregando();

//Função Principal
int main() {
	setlocale(LC_ALL, "Portuguese");
	cont = 0;
	printf("LISTA DE SATÉLITES OPERANDO COMERCIALMENTE NO BRASIL\n\n");
	printf("Carregando.");
	
	char buf[1024];
    char token[1024];

    int row_count = 0;
    int field_count = 0;
    int in_double_quotes = 0;
    int token_pos = 0;
    int i = 0;
    
    
	printf("\n\nAbrindo o arquivo CSV.");
	 FILE *fp = fopen("satelites_operando_comercialmente.csv", "r");

    if (!fp) {
        printf("Can't open file\n");
        return 0;
    }else{
    	printf("\n\nArquivo localizado com sucesso!\n\nExibindo a lista.");
		carregando();
		printf("\n\n");
	}


    while (fgets(buf, 1024, fp)) {
        row_count++;

        if (row_count == 1) {
            continue;
        }

        field_count = 0;
        i = 0;
        do {
            token[token_pos++] = buf[i];

            if (!in_double_quotes && (buf[i] == ',' || buf[i] == '\n')) {
                token[token_pos - 1] = 0;
                token_pos = 0;
                prompt_field(lista, field_count++, token);
            }

            if (buf[i] == '"' && buf[i + 1] != '"') {
                token_pos--;
                in_double_quotes = !in_double_quotes;
            }

            if (buf[i] == '"' && buf[i + 1] == '"')
                i++;

        } while (buf[++i]);

        printf("\n");
        lista_mostrar(lista);
        cont++;
    }
    bubbleSort(lista);
    lista_mostrar2(lista);
    fclose(fp);
	return(0);
}

//Desenha o conteúdo da Lista na tela
void lista_mostrar(no lista[]){
	printf("Nome do Satélite: \t%s\n", lista[cont].satelite);
	printf("Órbita: \t\t%s\n", lista[cont].orbita);
	printf("Banda: \t\t\t%s\n", lista[cont].banda);
	printf("Status do Satélite: \t%s\n", lista[cont].status);
	printf("Posição Orbital: \t%s\n", lista[cont].posicao);
	printf("Direito: \t\t%s\n", lista[cont].direito);
	printf("Operador Comercial:\t%s\n", lista[cont].operador);
}

//Desenha o conteúdo da Lista após a ordenação
void lista_mostrar2(no lista[]){
	int i;
	printf("\n");
	printf("\n==================================");
	printf("\nOrdenando.");
	carregando();
	printf("\n\nLista Ordenada:");
	printf("\n\n");
	for(i = 0; i < cont; i++){
		printf("Nome do Satélite: \t%s\n", lista[i].satelite);
		printf("Órbita: \t\t%s\n", lista[i].orbita);
		printf("Banda: \t\t\t%s\n", lista[i].banda);
		printf("Status do Satélite: \t%s\n", lista[i].status);
		printf("Posição Orbital: \t%s\n", lista[i].posicao);
		printf("Direito: \t\t%s\n", lista[i].direito);
		printf("Operador Comercial:\t%s\n", lista[i].operador);
		printf("\n");
	}
}

//Insere os elementos na lista que foram encontrados no arquivo CSV
void prompt_field(no lista[], int field_count, char *value) {
	if (field_count == 0) {
        strcpy(lista[cont].satelite, value);
    }
    if (field_count == 1) {
        strcpy(lista[cont].orbita, value);
    }
    if (field_count == 2) {
        strcpy(lista[cont].banda, value);
    }
    if (field_count == 3) {
        strcpy(lista[cont].status, value);
    }
    if (field_count == 4) {
        strcpy(lista[cont].posicao, value);
    }
	if (field_count == 5) {
        strcpy(lista[cont].direito, value);
    }
	if (field_count == 6) {
        strcpy(lista[cont].operador, value);
    }
}

//Faz a ordenação da lista com base no método BubbleSort
int bubbleSort(no lista[]){
	int qtd, i, j, tamanho;
	tamanho = cont;
	i = 0;
	qtd = 0;
	for (i = 0; i < tamanho -1; i++){
		for (j = i+1; j < tamanho; j++){
			if (lista[i].satelite[0] > lista[j].satelite[0]){
				strcpy(aux.satelite, lista[i].satelite);
				strcpy(aux.orbita, lista[i].orbita);
				strcpy(aux.banda, lista[i].banda);
				strcpy(aux.status, lista[i].status);
				strcpy(aux.posicao, lista[i].posicao);
				strcpy(aux.direito, lista[i].direito);
				strcpy(aux.operador, lista[i].operador);
				
				strcpy(lista[i].satelite, lista[j].satelite);
				strcpy(lista[i].orbita, lista[j].orbita);
				strcpy(lista[i].banda, lista[j].banda);
				strcpy(lista[i].status, lista[j].status);
				strcpy(lista[i].posicao, lista[j].posicao);
				strcpy(lista[i].direito, lista[j].direito);
				strcpy(lista[i].operador, lista[j].operador);
				
				strcpy(lista[j].satelite, aux.satelite);
				strcpy(lista[j].orbita, aux.orbita);
				strcpy(lista[j].banda, aux.banda);
				strcpy(lista[j].status, aux.status);
				strcpy(lista[j].posicao, aux.posicao);
				strcpy(lista[j].direito, aux.direito);
				strcpy(lista[j].operador, aux.operador);
			}
		qtd++;
		}
	}
	return(qtd);
}

//Função utilizada para gerar um delay na tela
void carregando(){
	int i;
	for(i = 0; i < 3; i++){
		sleep(1);
		printf(".");
	}
}


