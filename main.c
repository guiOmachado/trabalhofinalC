#include <stdio.h>

void leArquivo();
void imprimeJogadores();

int matriz[6][4];
int indexJogador=0;
int jogadasLidas[6];

struct jogador {
    int id;
    int jogadas[6];
};

struct jogador j[4];

int main() {
    leArquivo();

    imprimeJogadores();

    return 0;
}

void torneio()
{

}

void imprimeJogadores()
{
    for(int i=0; i<4; i++){
        printf("Jogador: %d ",j[i].id);
        printf("\n");
        for(int jogada=0; jogada<6; jogada++) {
            printf("Jogada %d : %d | ", jogada, j[i].jogadas[jogada]);
        }
        printf("\n");
        printf("\n");
    }
}

void criaJogadores(int id,int jogadas[])
{
    j[indexJogador].id = id+1;
    for(int jogada=0; jogada<6; jogada++){
        j[indexJogador].jogadas[jogada] = jogadas[jogada];
    }

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
            //printf("%i ",matriz[i][j]);
            jogadasLidas[i] = matriz[i][j];
        }
        for(int i=0; i<6; i++){
            printf("%i ",jogadasLidas[i]);
        }

        criaJogadores(j,jogadasLidas);

        printf("\n");
    }

    printf("\n");
    printf("\n");
    fclose(arq);
}
