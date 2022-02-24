#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "aluno.h"

ListaGen *criaLista(){
    return NULL;
}
ListaGen *insereListaGen(ListaGen *l, void *dado){
    ListaGen *n = (ListaGen*)malloc(sizeof(ListaGen));
    n->info = dado;
    n->prox = l;
    l = n;
    return l;
}
ListaGen *insereAluno(ListaGen *l, char n[50], int m){
    Aluno *a = malloc(sizeof(Aluno));
    strcpy(a->nome, n);
    a->matricula = m;
    return insereListaGen(l, a);
}
void buscarAluno(ListaGen *l, Aluno *a, int m){
    if(a->matricula == m)
        printf("\n\tNome: %s; Matricula: %d", a->nome, a->matricula);
}
void percorreListaGen(ListaGen *l, ListaGen *(*cb1)(void*), void (*cb2)(void*, void*, int), int m, int operacao){
    ListaGen *aux;
    for(aux = l; aux != NULL; aux = aux->prox){
        if(operacao == 1)
            cb1(aux->info);
        else if(operacao == 2)
            aux = cb1(aux);
        else
            cb2(aux, aux->info, m);
    }
}
ListaGen *percorreRemocao(ListaGen *l, int m){
    ListaGen *aux = l, *aux2, *atual = l;
    Aluno *a;
    while (atual != NULL){
        a = (Aluno*)(atual->info);
        if (a->matricula == m && aux == atual){
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
void imprime(void *info){
    Aluno *a = (Aluno*)info;
    printf("\n\tNome: %s; Matricula: %d", a->nome, a->matricula);
}
void listaVazia(ListaGen *l){
    if (l == NULL)
        printf("\n\tA lista esta vazia.");
    else
        printf("\n\tA lista contem elementos.");
}
ListaGen *freeLista(ListaGen *l){
    ListaGen *aux;
    free(l->info);
    aux = l;
    l = l->prox;
    free(aux);
    return l;
}
