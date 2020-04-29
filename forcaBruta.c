void forcaBruta(char palavras[], char frase[]){

    printf("\n\n=============Atraves da busca por forca bruta chegamos ao seguinte resultado=============\n");
    int tPalavra = strlen(palavras); //Define tamanho da string
    int tFrase = strlen(frase); //Define tamanho da frase que busca
    
    int cont = 0; //Contador para conclusão
    int k = 0; //contador usado na string e na frase
    int j = 0; //Contador usado na frase
    int i = 0; //Contador usado na string

    for (i=0;  i < tPalavra - tFrase; i++) { //Define o tamanho da string qual ainda é valido tentar a comparação, e define primeira letra da string.
        k=i;  cont=1;
        for(j=0 ; j < tFrase; j++) { //Define primeira letra da string
            if ((palavras[k]==frase[j])  && (cont != tFrase)){ //Compara primeira letra da frase com a posição atual da string
                cont++;
                k++; //Se igual soma o contador para conclusão e a posição da string (k)
            }//Ao retornar para o for soma a posição da frase (j)
        }//Ao retornar para o primeiro for soma a posição da string (i)
            if (cont == tFrase){ //Se o tamanho do contador de conclusão somar ate chegar ao tamanho da frase quer dizer que a string foi encontrada.
                printf("A frase mencionada comeca na posicao %d e termina na posicao %d do array.\n", i, k); //Imprimi a posicao de inicio e fim
                for (i; i <= k; i++){ //Imprimir cada letra
                    printf("%c", palavras[i]);
                }
                printf("\n");
                return 0; //Finaliza
            } 
    }
    printf("Frase nao encontrada.\n");
    return 0; //Se a frase não for encontrada imprimi a mensagem e finaliza.
}