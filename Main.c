#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "forcaBruta.c"
#include "rabinKarp.c"

int main () {
    setlocale(LC_ALL, "Portuguese");

    //SOLICITA NOME DO ARQUIVO QUE SERÁ CARREGADO
    char nomeArquivo[30];
    printf("Digite o nome do arquivo que deseja carregar: ");
    fgets(nomeArquivo, 30, stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")] = 0;
    //NOME DO ARQUIVO DIGITADO


    //FUNÇÃO PARA CARREGAR O ARQUIVO
    char palavras[5000];
    FILE *arq;
 
    arq = fopen(nomeArquivo, "r");
    if(arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    else
        while( (fgets(palavras, sizeof(palavras), arq))!=NULL )
    fclose(arq);
    printf("\nO array do arquivo carregado contem: %s\n", palavras);
    //ARQUIVO CARREGADO


    //SOLICITA FRASE QUE SERÁ PROCURA NO ARRAY
    char frase[50];
    printf("Digite uma frase que deseja buscar: ");
    fgets(frase, 50, stdin);
    frase[strcspn(frase, "\n")] = 0; //Exemplo: BROWN FOX
    printf("A frase que voce busca e: %s\n", frase);
    //FRASE DIGITADA


    //PROCURA STRING POR RABIN KARP
    rabinKarp(palavras, frase);

    //PROCURA STRING POR FORÇA BRUTA
    forcaBruta(palavras, frase);

    return 0;   
}