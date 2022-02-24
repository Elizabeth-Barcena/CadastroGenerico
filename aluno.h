#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno{
    int matricula;
    char nome[50];
}Aluno;

typedef struct listagen{
    void *info;
    struct listagen *prox;
}ListaGen;

ListaGen *criaLista();
ListaGen *insereListaGen(ListaGen *l, void *dado);
ListaGen *insereAluno(ListaGen *l, char n[50], int m);
ListaGen *percorreRemocao(ListaGen *l, int m);
ListaGen *freeLista(ListaGen *l);
void buscarAluno(ListaGen *l, Aluno *a, int m);
void percorreListaGen(ListaGen *l, ListaGen *(*cb1)(void*), void (*cb2)(void*, void*, int), int m, int operacao);
void imprime(void *info);
void listaVazia(ListaGen *l);

#endif
