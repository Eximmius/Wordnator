#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palavra.h"

struct palavra {
    char* chave;
    char* significado;
};

palavra_t* cria_palavra (char* chave, char* significado){

    palavra_t* palavra = malloc(sizeof(palavra_t));
    if(!palavra){perror("cria_palavra"); exit(EXIT_FAILURE);};

    palavra->chave = malloc (strlen(chave)+1);
    if(!palavra->chave){perror("cria_no_arvore: chave"); exit(EXIT_FAILURE);};

    strcpy (palavra->chave, chave);

    palavra->significado = malloc (strlen(significado)+1);
    if(!palavra->significado){perror("cria_no_arvore: significado"); exit(EXIT_FAILURE);};

    strcpy (palavra->significado, significado);

    return palavra;
}

char* obtem_chave (palavra_t* palavra){
    return palavra->chave;
}

char* obtem_significado(palavra_t* palavra){
    return palavra->significado;
}

void libera_palavra (palavra_t* palavra){
    free(palavra->significado);
    free(palavra->chave);
    free(palavra);
}
