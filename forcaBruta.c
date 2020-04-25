void forcaBruta(char palavras[], char frase[]){

    printf("\n\n=============Atraves da busca por forca bruta chegamos ao seguinte resultado=============\n");
    int tPalavra = strlen(palavras); 
    int tFrase = strlen(frase);
    
    int cont = 0;
    int k = 0;
    int j = 0;
    int i = 0;

    for (i=0;  i < tPalavra - tFrase; i++) {
        k=i;  cont=1;
        for(j=0 ; j < tFrase; j++) {
            if ((palavras[k]==frase[j])  && (cont != tFrase)){
            cont++;k++;
            }
        }
            if (cont == tFrase){
                printf("A palavra mencionada comeca na posicao %d e termina na posicao %d do array.\n", i, k);
                for (i; i <= k; i++){
                    printf("%c", palavras[i]);
                }
            }  
    }
}