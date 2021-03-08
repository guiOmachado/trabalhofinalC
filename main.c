#include <stdio.h>

void leArquivo();


int matriz[6][4];
int indexJogador=0;
int jogadasLidas[6];

struct jogador {
    int id;
    int *jogadas;
};

struct jogador j[4];

int main() {
    leArquivo();

    for(int i=0; i<4; i++){
        printf("Jogador: %d ",j[i].id);
        printf("\n");
        for(int jogada=0; jogada<4; jogada++) {
            printf("Jogada %d : %d ", jogada, j[i].jogadas[jogada]);
        }
        printf("\n");
        printf("\n");
    }

    return 0;
}

void torneio()
{

}

void criaJogadores(int id,int *jogadas)
{
    j[indexJogador].id = id;
    j[indexJogador].jogadas = jogadas;
    indexJogador++;
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

    for(int j=0; j<4; j++){
        for(int i=0; i<6; i++){
            printf("%i ",matriz[i][j]);
            jogadasLidas[i] = matriz[i][j];
        }
        criaJogadores(j,jogadasLidas);
        printf("\n");
    }

    printf("\n");
    fclose(arq);
}
