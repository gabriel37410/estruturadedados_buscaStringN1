#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "forcaBruta.c"

int main () {
    setlocale(LC_ALL, "Portuguese");

/*
    //SOLICITA NOME DO ARQUIVO QUE SERÁ CARREGADO
    char nomeArquivo[30];
    printf("Digite o nome do arquivo que deseja carregar: ");
    fgets(nomeArquivo, 30, stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")] = 0;
    //NOME DO ARQUIVO DIGITADO
APAGAR*/ char nomeArquivo[30] = "teste.txt"; //Caracter 29 e o espaço em branco de um total de 33


    //FUNÇÃO PARA CARREGAR O ARQUIVO
    char palavras[50];
    FILE *arq;
 
    arq = fopen(nomeArquivo, "r");
    if(arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    else
        while( (fgets(palavras, sizeof(palavras), arq))!=NULL )
    fclose(arq);
    printf("\nO array do arquivo carregado e: %s\n", palavras);
    //ARQUIVO CARREGADO


/*
    //SOLICITA FRASE QUE SERÁ PROCURA NO ARRAY
    char frase[50];
    printf("Digite uma frase que deseja buscar: ");
    fgets(frase, 50, stdin);
    frase[strcspn(frase, "\n")] = 0;
    printf("A frase que voce busca e: %s\n", frase);
    //FRASE DIGITADA
APAGAR*/ char frase[50] = "BABCCBAA"; printf("A frase que voce busca e: %s\n", frase);  
 
    forcaBruta(palavras, frase);



    return 0;   
}