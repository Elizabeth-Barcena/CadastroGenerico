//Nome: Maria Elizabeth Bárcena Silva Matricula:1801570092   

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Generico.h"

struct Alunos{
	char nome[100];
	int matricula;
	struct Alunos *prox;
};
typedef struct Alunos alunos;

static lg* inserir(lg* lista, char n[],int mat){
	alunos* a= (alunos*) malloc(sizeof(alunos));
	strcpy(a->nome, n);
	a->matricula=mat;
	return inserir_generico(lista, a);
}
static void imprime(void *info){
	alunos*a=(alunos*)info;
	printf(" Nome: %s \n Matricula: %d \n",a->nome, a->matricula);
}
void buscarAluno(lg *l, alunos *a, int m){
    if(a->matricula == m)
        printf("\n\tNome: %s; Matricula: %d", a->nome, a->matricula);
}
int main(){
	int menu;
	lg*lista=NULL;
	alunos* a=NULL;
	char n[100];
	int mat,m;
	
	do{ printf("\n");
		printf("\t\t ______________________________________\n");
		printf("\t\t|::::::::::::  MENU :::::::::::::::::::|\n");
		printf("\t\t|______________________________________|\n");
		printf("\t\t| 1 - Inserir Alunos                   |\n");
		printf("\t\t| 2 - Buscar Alunos(por matricula)     |\n");
		printf("\t\t| 3 - Imprimir Alunos                  |\n");
		printf("\t\t| 4 - Retirar Alunos(Por matricula)    |\n");
		printf("\t\t| 5 - Verifica se lista esta vazia     |\n");
		printf("\t\t| 6 - Libera lista                     |\n");
		printf("\t\t|______________________________________|\n");
		scanf("%d", &menu);
		
		switch(menu){
			
			case 1:
				printf("Digite o nome do Aluno:\n-->");
				scanf("%s", &n);
				printf("Digite a matricula:\n-->");
				scanf("%d", &mat);
				
				lista=inserir(lista, n, mat);
				
				break;
			case 2:
				printf("\n\tDigite a matricula.\n\t");
                scanf("%d", &m);
                percorreListaGen(lista, 0, buscarAluno, m, 0);
			break;
			
			case 3:
				percorrer(lista, imprime);
				break;
			case 4:
				printf("\n\tDigite a matricula.\n\t");
                scanf("%d", &m);
                lista = percorreRemocao(lista, m);
				break;
			case 5:
				verifica(lista);
				break;
			case 6:
				percorreListaGen(lista, libera, 0, 0, 2);
				exit(1);    
				break;	
				
		}
		
	}while(menu!=0);
	return 0;
}
