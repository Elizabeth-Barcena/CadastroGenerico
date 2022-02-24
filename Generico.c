#include <stdio.h>
#include <stdlib.h>
#include "Generico.h"


struct lista_gen{
	void* info;
	struct lista_gen* prox;
};
typedef struct lista_gen lg;
struct Alunos{
	char nome[100];
	int matricula;
	struct Alunos *prox;
};
typedef struct Alunos alunos;

lg* inserir_generico(lg* lista, void *a){
	lg* n=(lg*) malloc(sizeof(lg));
	n->info=a;
	n->prox=lista;
	lista=n;
	return lista;
	
}
void percorrer(lg* lista, void(*cb)(void*)){
	lg*alun;
	
	for(alun=lista; alun!=NULL; alun=alun->prox){
		cb(alun->info);	
	}
}
void percorreListaGen(lg *l, lg *(*cb1)(void*), void (*cb2)(void*, void*, int), int m, int operacao){
    lg *aux;
    for(aux = l; aux != NULL; aux = aux->prox){
        if(operacao == 1)
            cb1(aux->info);
        else if(operacao == 2)
            aux = cb1(aux);
        else
            cb2(aux, aux->info, m);
    }
}
lg *percorreRemocao(lg *l, int m){
    lg *aux = l, *aux2, *atual = l;
    alunos *a;
    while (atual != NULL){
        a = (alunos*)(atual->info);
        if ((a->matricula == m) && (aux == atual)){
            l = atual ->prox;
            aux2 = aux;
            free(aux2);
            return l;
        }
        else if (a->matricula == m){
            aux2 = atual;
            aux->prox = atual->prox;
            free(aux2);
            return l;
        }
        aux = atual;
        atual = atual->prox;
    }
    return l;
}
lg*verifica(lg*lista){
	if(lista==NULL)
	printf("Lista vazia\n");
	else
	printf("A lista nao esta vazia!\n");
}
lg*libera(lg*lista){	

	lg *aux;
    free(lista->info);
    aux = lista;
    lista = lista->prox;
    free(aux);
    return lista;
	 
}
