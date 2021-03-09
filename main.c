#include <stdio.h>
#include <accctrl.h>
struct jogador {
    int id;
    int jogadas[6];
    int vitorias;
};

struct torneio {
    struct jogador chaveA[2];
    struct jogador chaveB[2];
    struct jogador final[2];
    struct jogador vencedor;
};

struct jogador j[4];
struct torneio t[2];



void leArquivo();

void validaJogadas(int jogadasJogador1[]);

void imprimeJogadores();

void torneio();

int jogada(int jogadasJogador1, int jogadasJogador2);

void criaJogadores(int id, int jogadas[]);

void placar(struct jogador resultado[]);

int matriz[6][4];
int indexJogador = 0;
int jogadasLidas[6];

int main() {
    leArquivo();
    imprimeJogadores();
    torneio();
    return 0;
}

void torneio() {

    for (int i = 0; i < 4; i++) {
        validaJogadas(j[i].jogadas);
    }
    printf("----Torneio Mundial de Pedra/papel/tesoura----- \n");
    printf("--------------------------------- \n");
    printf("------Semi Final------- \n");
    printf("Chave A: Jogador %d X Jogador %d \n", t[0].chaveA[0].id, t[0].chaveA[1].id);
    printf("Chave B: Jogador %d X Jogador %d \n", t[0].chaveB[0].id, t[0].chaveB[1].id);
    printf("--------------------------------- \n");
    printf(" \n");

    //logica vitoria chave A
    for (int i = 0; i < 6; i++) {
        if (jogada(t[0].chaveA[0].jogadas[i], t[0].chaveA[1].jogadas[i]) == 1) {
            t[0].chaveA[0].vitorias++;
        } else if (jogada(t[0].chaveA[0].jogadas[i], t[0].chaveA[1].jogadas[i]) == 2) {
            t[0].chaveA[1].vitorias++;
        }
    }

    placar(t[0].chaveA);

    if (t[0].chaveA[0].vitorias > t[0].chaveA[1].vitorias) {
        t[0].final[0] = t[0].chaveA[0];
        t[0].final[0].vitorias = 0;
    } else if (t[0].chaveA[0].vitorias < t[0].chaveA[1].vitorias) {
        t[0].final[0] = t[0].chaveA[1];
        t[0].final[0].vitorias = 0;
    }

    //Logica vitoria chave B
    for (int i = 0; i < 6; i++) {
        if (jogada(t[0].chaveB[0].jogadas[i], t[0].chaveB[1].jogadas[i]) == 1) {
            t[0].chaveB[0].vitorias++;
        } else if (jogada(t[0].chaveB[0].jogadas[i], t[0].chaveB[1].jogadas[i]) == 2) {
            t[0].chaveB[1].vitorias++;
        }
    }

    placar(t[0].chaveB);

    if (t[0].chaveB[0].vitorias > t[0].chaveB[1].vitorias) {
        t[0].final[1] = t[0].chaveB[0];
        t[0].final[1].vitorias = 0;
    } else if (t[0].chaveB[0].vitorias < t[0].chaveB[1].vitorias) {
        t[0].final[1] = t[0].chaveB[1];
        t[0].final[1].vitorias = 0;
    }
    printf("----------Grande Final----------- \n");
    printf("Final: Jogador %d X Jogador %d \n", t[0].final[0].id, t[0].final[1].id);
    printf("--------------------------------- \n");
    printf(" \n");

    //Logica vitoria final
    for (int i = 0; i < 6; i++) {
        if (jogada(t[0].final[0].jogadas[i], t[0].final[1].jogadas[i]) == 1) {
            t[0].final[0].vitorias++;
        } else if (jogada(t[0].final[0].jogadas[i], t[0].final[1].jogadas[i]) == 2) {
            t[0].final[1].vitorias++;
        }

    }

    placar(t[0].final);

    if (t[0].final[0].vitorias > t[0].final[1].vitorias) {
        t[0].vencedor = t[0].final[0];
    } else if (t[0].final[0].vitorias < t[0].final[1].vitorias) {
        t[0].vencedor = t[0].final[1];
    }
    printf(" \n");
    printf("----------Campeao----------- \n");
    printf("O grande campeao foi : JOGADOR %d \n", t[0].vencedor.id);
    printf("--------------------------------- \n");
    printf(" \n");

}

void imprimeJogadores() {
    for (int i = 0; i < 4; i++) {
        printf("Jogador: %d ", j[i].id);
        printf("\n");
        for (int jogada = 0; jogada < 6; jogada++) {
            printf("Jogada %d : %d | ", jogada, j[i].jogadas[jogada]);
        }
        printf("\n");
        printf("\n");
    }
}

void criaJogadores(int id, int jogadas[]) {
    j[indexJogador].id = id + 1;
    for (int jogada = 0; jogada < 6; jogada++) {
        j[indexJogador].jogadas[jogada] = jogadas[jogada];
    }
    indexJogador++;
    t[0].chaveA[0] = j[0];
    t[0].chaveA[1] = j[1];
    t[0].chaveB[0] = j[2];
    t[0].chaveB[1] = j[3];
}

void validaJogadas(int jogadasJogador1[]) {
    for (int i = 0; i < 6; i++) {
        if (!(jogadasJogador1[i] == 1 || jogadasJogador1[i] == 2 || jogadasJogador1[i] == 3)) {
            printf("Jogada invalida");
            exit(0);
        }
    }
}

int jogada(int jogadasJogador1, int jogadasJogador2) {
    switch (jogadasJogador1) {
        case 1: {
            if (jogadasJogador2 == 3) {
                return 1;
            } else if (jogadasJogador2 == 2) {
                return 2;
            }
        }
        case 2: {
            if (jogadasJogador2 == 1) {
                return 1;
            } else if (jogadasJogador2 == 3) {
                return 2;
            }
        }
        case 3: {
            if (jogadasJogador2 == 2) {
                return 1;
            } else if (jogadasJogador2 == 1) {
                return 2;
            }
        }
    }
}

void placar(struct jogador resultado[])
{
    printf("-----------Placar Da Partida----------\n");
    printf("Jogador %d||  %d X", resultado[0].id, resultado[0].vitorias);
    printf(" %d  ||%d Jogador", resultado[1].vitorias, resultado[1].id);
    printf("\n");
    printf("-----------Fim da partida----------\n");
    printf(" \n");
    printf(" \n");
}

void leArquivo() {
    FILE *arq;
    char Linha[100];
    char *result;
    int i;
    arq = fopen("jogadas.txt", "rt");
    if (arq == NULL) {
        printf("Problemas na abertura do arquivo\n");
        return;
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            fscanf(arq, "%i ", &matriz[i][j]);
        }
        fscanf(arq, "\n");
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            //printf("%i ", matriz[i][j]);
        }
        //printf("\n");
    }

    printf("-------- Jogadas lidas ---------\n");
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 6; i++) {
            jogadasLidas[i] = matriz[i][j];
        }
        printf("Jogador %d :", j);
        for (int i = 0; i < 6; i++) {
            printf(" %i ", jogadasLidas[i]);
        }

        criaJogadores(j, jogadasLidas);

        printf("\n");
    }

    printf("-------------------------------\n");

    printf("\n");
    printf("\n");
    fclose(arq);
}


