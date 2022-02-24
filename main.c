#include<stdio.h>
#include<stdlib.h>
#include"aluno.h"

int main (){

    int op, m;
    char n[50];
    ListaGen *l = malloc(sizeof(ListaGen));
    l = criaLista();

    while (op!=0){
        system("cls");
        printf("\n\tMENU");
        printf("\n\t(1) Inserir aluno;");
        printf("\n\t(2) Buscar aluno (por matricula);");
        printf("\n\t(3) Imprimir alunos;");
        printf("\n\t(4) Retirar aluno (por matricula);");
        printf("\n\t(5) Verificar se a lista esta vazia;");
        printf("\n\t(6) Sair.\n\t");
        scanf("%d", &op);
        switch (op){
            case 1:
                printf("\n\tDigite o nome do aluno.\n\t");
                scanf("%s", &n);
                printf("\n\tDigite a matricula.\n\t");
                scanf("%d", &m);
                l = insereAluno(l, n, m);
                break;
            case 2:
                printf("\n\tDigite a matricula.\n\t");
                scanf("%d", &m);
                percorreListaGen(l, 0, buscarAluno, m, 0);
                break;
            case 3:
                percorreListaGen(l, imprime, 0, 0, 1);
                break;
            case 4:
                printf("\n\tDigite a matricula.\n\t");
                scanf("%d", &m);
                l = percorreRemocao(l, m);
                break;
            case 5:
                listaVazia(l);
                break;
            case 6:
                percorreListaGen(l, freeLista, 0, 0, 2);
                exit(1);
                break;
            default:
                printf("\n\tERRO!");
                break;
        }
    getch();
    }
}
