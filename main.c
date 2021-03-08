#include <stdio.h>

void leArquivo();


int matriz[6][4];


int main() {
    leArquivo();
    return 0;
}






void leArquivo()
{
    FILE *arq;
    char Linha[100];
    char *result;
    int i;
    arq = fopen("jogadas.txt", "rt");
    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
        return;
    }
    for(int i=0; i<6; i++){
        for(int j=0; j<4; j++){
            fscanf(arq,"%i ", &matriz[i][j]);
        }
        fscanf(arq,"\n");
    }

    for(int i=0; i<6; i++){
        for(int j=0; j<4; j++){
            printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    fclose(arq);
}
