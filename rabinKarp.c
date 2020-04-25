void rabinKarp(char palavras[], char frase[]) {

    printf("\n\n=============Atraves da busca por Rabin Karp chegamos ao seguinte resultado=============\n");
    int d = 256, q = 29;
    int tPalavra = strlen(palavras); //Define tamanho da string
    int tFrase = strlen(frase); //Define tamanho da frase que busca
    int i, h = 1;
    int hPalavra = 0; //Hash (tamanho) para string
    int hFrase = 0; //Hash (tamanho) para frase

    for (i = 0; i < tFrase - 1; i++)
        h = d * h % q;
    //Calcula o valor do hash da frase e o primeiro da string (palavra)
    for (i = 0; i < tFrase; i++)
    {
        hFrase = (d * hFrase + frase[i]) % q;
        hPalavra = (d * hPalavra + palavras[i]) % q;
    }

    for (i = 0; i <= tPalavra - tFrase; i++)
    {
        if (hFrase == hPalavra) //Compara o hash da string atual com o hash da frase, se for igual ele compara cada caractere para garantir que a frase corresponde a string.
        {
            int j;
            for (j = 0; j < tFrase; j++)
            {
                if (frase[j] != palavras[i + j])
                    break;
            }
            if (tFrase == j){ //Se o tamanho da String (tFrase) for do mesmo tamanho do (j) quer dizer que a string foi encontrada.
                int k = i + tFrase -1; //Calcula posição final da frase para imprimir na tela
                printf("A frase mencionada comeca na posicao %d e termina na posicao %d do array.\n", i, k); //Imprimi a posicao de inicio e fim
                for (i; i <= k; i++){ //Imprimir cada letra
                    printf("%c", palavras[i]);
                }
                printf("\n");
                return 0; //Finaliza
            }
        }
        hPalavra = (d * (hPalavra - palavras[i] * h) + palavras[i + tFrase]) % q; //Calcula o valor do hash para a proxima string removendo os elementos do hash atual e jogando para o final.
        if (hPalavra < 0) //Converte o valor do hash para positivo, quando o mesmo for negativo
            hPalavra = hPalavra + q;
    }
    printf("Frase nao encontrada.\n");
    return 0; //Se a frase não for encontrada imprimi a mensagem e finaliza.
}