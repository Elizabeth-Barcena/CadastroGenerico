typedef struct lista_gen lg;

typedef struct Alunos alunos;

lg*verifica(lg*lista);
lg* inserir_generico(lg* lista, void *a);
void percorrer(lg* lista, void(*cb)(void*));
void percorreListaGen(lg *l, lg *(*cb1)(void*), void (*cb2)(void*, void*, int), int m, int operacao);
lg *percorreRemocao(lg *l, int m);
lg*libera(lg*lista);

