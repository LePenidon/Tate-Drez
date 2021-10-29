/**---------------------------------------**|
|**                                       **|
|**               TateDrez                **|
|**                                       **|
|**                ALUNOS:                **|
|** Gabriel Penido de Oliveira (12558770) **|
|**     Marco Antonio Muller (12675962)   **|
|**                                       **|
|**            Data: 20/07/2021           **|
|**---------------------------------------**/

// Importar as bibliotecas utilizadas
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declaracao previa das funcoes
void pausar(void);
void limparTela(void);
int verificarFim(int tabuleiro[3][3], int trocarNome, int rodadas);
int verificarJogada(int tabuleiro[3][3], int movimento[2], char peca, int trocarNome, int rodadas);
void realizarMovimento(int tabuleiro[3][3], char *nome1, char *nome2, int trocarNome, int rodadas);
void realizarMovimento02(int tabuleiro[3][3], char *nome1, char *nome2, int trocarNome, int rodadas);
void jogadaComputador(int tabuleiro[3][3], int rodadas);
void escolha01(int tabuleiro[3][3], char *nome1, char *nome2);
void escolha02(int tabuleiro[3][3], char *nome1, char *nome2);
void escolha03(void);
void printarTabuleiro(int tabuleiro[3][3]);
void limparTabuleiro(int tabuleiro[3][3]);
int main(void);

// Definicao das cores utilizadas
#define ANSI_RESET "\x1b[0m"  // desativa os efeitos anteriores
#define ANSI_BOLD "\x1b[1m"   // coloca o texto em negrito
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_WHITE "\x1b[37m"

// Macros para facilitar o uso das cores
#define BOLD(string) ANSI_BOLD string ANSI_RESET
#define BLUE(string) ANSI_COLOR_BLUE string ANSI_RESET
#define RED(string) ANSI_COLOR_RED string ANSI_RESET
#define GREEN(string) ANSI_COLOR_GREEN string ANSI_RESET
#define CYAN(string) ANSI_COLOR_CYAN string ANSI_RESET
#define WHITE(string) ANSI_COLOR_WHITE string ANSI_RESET

// Pausa a execucao do programa
void pausar(void) {
    printf(BOLD(WHITE("\n\nAperte qualquer tecla pra continuar...")));
    getchar();

    return;
}

// Limpa o terminal
void limparTela(void) {
// Determina se o sistema e UNIX ou Windows
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif

    return;
}

// Verifica o fim do jogo
int verificarFim(int tabuleiro[3][3], int trocarNome, int rodadas) {
    int i, j, k, movimento[2], velha = 1, jogadas[3];

    /** Verifica o fim do jogo, caso algum jogador forme linha, coluna ou diagonal com suas pecas **/

    // Verifica se o vermelho venceu
    if ((((tabuleiro[0][0] + tabuleiro[0][1] + tabuleiro[0][2]) == 6) && tabuleiro[0][0] != 0 && tabuleiro[0][1] != 0 && tabuleiro[0][2] != 0) ||
        (((tabuleiro[1][0] + tabuleiro[1][1] + tabuleiro[1][2]) == 6) && tabuleiro[1][0] != 0 && tabuleiro[1][1] != 0 && tabuleiro[1][2] != 0) ||
        (((tabuleiro[2][0] + tabuleiro[2][1] + tabuleiro[2][2]) == 6) && tabuleiro[2][0] != 0 && tabuleiro[2][1] != 0 && tabuleiro[2][2] != 0) ||
        (((tabuleiro[0][0] + tabuleiro[1][0] + tabuleiro[2][0]) == 6) && tabuleiro[0][0] != 0 && tabuleiro[1][0] != 0 && tabuleiro[2][0] != 0) ||
        (((tabuleiro[0][1] + tabuleiro[1][1] + tabuleiro[2][1]) == 6) && tabuleiro[0][1] != 0 && tabuleiro[1][1] != 0 && tabuleiro[2][1] != 0) ||
        (((tabuleiro[0][2] + tabuleiro[1][2] + tabuleiro[2][2]) == 6) && tabuleiro[0][2] != 0 && tabuleiro[1][2] != 0 && tabuleiro[2][2] != 0) ||
        (((tabuleiro[0][0] + tabuleiro[1][1] + tabuleiro[2][2]) == 6) && tabuleiro[0][0] != 0 && tabuleiro[1][1] != 0 && tabuleiro[2][2] != 0) ||
        (((tabuleiro[0][2] + tabuleiro[1][1] + tabuleiro[2][0]) == 6) && tabuleiro[0][2] != 0 && tabuleiro[1][1] != 0 && tabuleiro[2][0] != 0)) {
        return 1;

        // Verifica se o azul venceu
    } else if ((((tabuleiro[0][0] + tabuleiro[0][1] + tabuleiro[0][2]) == 15) && tabuleiro[0][0] != 0 && tabuleiro[0][1] != 0 && tabuleiro[0][2] != 0) ||
               (((tabuleiro[1][0] + tabuleiro[1][1] + tabuleiro[1][2]) == 15) && tabuleiro[1][0] != 0 && tabuleiro[1][1] != 0 && tabuleiro[1][2] != 0) ||
               (((tabuleiro[2][0] + tabuleiro[2][1] + tabuleiro[2][2]) == 15) && tabuleiro[2][0] != 0 && tabuleiro[2][1] != 0 && tabuleiro[2][2] != 0) ||
               (((tabuleiro[0][0] + tabuleiro[1][0] + tabuleiro[2][0]) == 15) && tabuleiro[0][0] != 0 && tabuleiro[1][0] != 0 && tabuleiro[2][0] != 0) ||
               (((tabuleiro[0][1] + tabuleiro[1][1] + tabuleiro[2][1]) == 15) && tabuleiro[0][1] != 0 && tabuleiro[1][1] != 0 && tabuleiro[2][1] != 0) ||
               (((tabuleiro[0][2] + tabuleiro[1][2] + tabuleiro[2][2]) == 15) && tabuleiro[0][2] != 0 && tabuleiro[1][2] != 0 && tabuleiro[2][2] != 0) ||
               (((tabuleiro[0][0] + tabuleiro[1][1] + tabuleiro[2][2]) == 15) && tabuleiro[0][0] != 0 && tabuleiro[1][1] != 0 && tabuleiro[2][2] != 0) ||
               (((tabuleiro[0][2] + tabuleiro[1][1] + tabuleiro[2][0]) == 15) && tabuleiro[0][2] != 0 && tabuleiro[1][1] != 0 && tabuleiro[2][0] != 0)) {
        return 1;

        // Verifica a ocorrencia de velha
    } else {
        if (rodadas < 5) {
            return 0;
        } else if (rodadas > 4 && rodadas < 30) {
            if (trocarNome) {
                trocarNome = 0;
            } else {
                trocarNome = 1;
            }

            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    movimento[0] = i;
                    movimento[1] = j;

                    jogadas[0] = verificarJogada(tabuleiro, movimento, 'b', trocarNome, 30);
                    jogadas[1] = verificarJogada(tabuleiro, movimento, 'c', trocarNome, 30);
                    jogadas[2] = verificarJogada(tabuleiro, movimento, 't', trocarNome, 30);

                    for (k = 0; k < 3; k++) {
                        if (jogadas[k] == 0) {
                            velha = 0;
                        }
                    }
                }
            }
            if (velha) {
                return 2;
            } else {
                return 0;
            }

        } else {
            return 2;
        }
    }
}

// Verifica a validade das jogadas
int verificarJogada(int tabuleiro[3][3], int movimento[2], char peca, int trocarNome, int rodadas) {
    int i, j, jaTem = 0;

    /**Inicio do jogo, e necessario colocar todas as 6 pecas, essa parte do codigo garante que isso ocorra**/

    /*---------------------*|
    |* Bispo vermelho = 1  *|
    |* Bispo azul = 4      *|
    |* Cavalo vermelho = 2 *|
    |* Cavalo azul = 5     *|
    |* Torre vermelha = 3  *|
    |* Torre azul = 6      *|
    |*---------------------*/

    /*----------------------*|
    |* TrocarNome == 1      *|
    |* Vermelho             *|
    |*                      *|
    |* TrocarNome == 0      *|
    |* Azul                 *|
    |*----------------------*/

    if ((tabuleiro[movimento[0]][movimento[1]] == 1) ||
        (tabuleiro[movimento[0]][movimento[1]] == 2) ||
        (tabuleiro[movimento[0]][movimento[1]] == 3) ||
        (tabuleiro[movimento[0]][movimento[1]] == 4) ||
        (tabuleiro[movimento[0]][movimento[1]] == 5) ||
        (tabuleiro[movimento[0]][movimento[1]] == 6)) {
        return 1;
    } else if (movimento[0] > 2 || movimento[0] < 0 || movimento[1] < 0 || movimento[1] > 2) {
        return 1;
    } else {
        if (rodadas < 6) {
            /**Nas primeiras 6 rodadas, todas as pecas devem ser colocadas em tabuleiro**/

            switch (peca) {
                case 'b': /**Bispo Vermelho**/
                    if (trocarNome) {
                        for (i = 0; i < 3; i++) {
                            for (j = 0; j < 3; j++) {
                                if (tabuleiro[i][j] == 1) {
                                    jaTem = 1;
                                }
                            }
                        }
                    } else { /**Bispo Azul**/
                        for (i = 0; i < 3; i++) {
                            for (j = 0; j < 3; j++) {
                                if (tabuleiro[i][j] == 4) {
                                    jaTem = 1;
                                }
                            }
                        }
                    }

                    if (jaTem) {
                        return 1;
                    } else {
                        return 0;
                    }

                    break;

                case 'c': /**Cavalo Vermelho**/
                    if (trocarNome) {
                        for (i = 0; i < 3; i++) {
                            for (j = 0; j < 3; j++) {
                                if (tabuleiro[i][j] == 2) {
                                    jaTem = 1;
                                }
                            }
                        }
                    } else { /**Cavalo Azul**/
                        for (i = 0; i < 3; i++) {
                            for (j = 0; j < 3; j++) {
                                if (tabuleiro[i][j] == 5) {
                                    jaTem = 1;
                                }
                            }
                        }
                    }

                    if (jaTem) {
                        return 1;
                    } else {
                        return 0;
                    }

                    break;

                case 't': /**Torre Vermelha**/
                    if (trocarNome) {
                        for (i = 0; i < 3; i++) {
                            for (j = 0; j < 3; j++) {
                                if (tabuleiro[i][j] == 3) {
                                    jaTem = 1;
                                }
                            }
                        }
                    } else { /**Torre Azul**/
                        for (i = 0; i < 3; i++) {
                            for (j = 0; j < 3; j++) {
                                if (tabuleiro[i][j] == 6) {
                                    jaTem = 1;
                                }
                            }
                        }
                    }

                    if (jaTem) {
                        return 1;
                    } else {
                        return 0;
                    }

                    break;

                default:
                    return 1;
                    break;
            }
        } else {
            /** Apos a rodada 6 o jogo tem de fato seu inicio, essa parte do codigo garante **|
            |**            que cada peca faca seu movimento de forma correta                **/

            switch (peca) {
                case 'b': /** Bispo Vermelho **/
                    if (trocarNome) {
                        for (i = 0; i < 3; i++) {
                            for (j = 0; j < 3; j++) {
                                if (tabuleiro[i][j] == 1) {
                                    /* Verifica o movimento do bispo, permitindo apenas movimentacao em diagonais */

                                    if ((movimento[0] == i + 1 && movimento[1] == j + 1) ||
                                        (movimento[0] == i + 1 && movimento[1] == j - 1) ||
                                        (movimento[0] == i - 1 && movimento[1] == j + 1) ||
                                        (movimento[0] == i - 1 && movimento[1] == j - 1)) {
                                        return 0;
                                    }

                                    /*-Caso o jogador deseje mover o bispo nas grandes diagonais, e necessario----*|
                                    |*-verificar se ha alguma peca na casa central do tabuleiro-------------------*/

                                    if ((movimento[0] == i + 2 && movimento[1] == j + 2) ||
                                        (movimento[0] == i + 2 && movimento[1] == j - 2) ||
                                        (movimento[0] == i - 2 && movimento[1] == j + 2) ||
                                        (movimento[0] == i - 2 && movimento[1] == j - 2)) {
                                        if (tabuleiro[1][1] == 2 || tabuleiro[1][1] == 3 ||
                                            tabuleiro[1][1] == 4 || tabuleiro[1][1] == 5 ||
                                            tabuleiro[1][1] == 6) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else { /** Bispo azul **/
                        for (i = 0; i < 3; i++) {
                            for (j = 0; j < 3; j++) {
                                if (tabuleiro[i][j] == 4) {
                                    /* A logica e identica ao bispo vermelho */

                                    if ((movimento[0] == i + 1 && movimento[1] == j + 1) ||
                                        (movimento[0] == i + 1 && movimento[1] == j - 1) ||
                                        (movimento[0] == i - 1 && movimento[1] == j + 1) ||
                                        (movimento[0] == i - 1 && movimento[1] == j - 1)) {
                                        return 0;
                                    }
                                    if ((movimento[0] == i + 2 && movimento[1] == j + 2) ||
                                        (movimento[0] == i + 2 && movimento[1] == j - 2) ||
                                        (movimento[0] == i - 2 && movimento[1] == j + 2) ||
                                        (movimento[0] == i - 2 && movimento[1] == j - 2)) {
                                        if (tabuleiro[1][1] == 2 || tabuleiro[1][1] == 3 ||
                                            tabuleiro[1][1] == 1 || tabuleiro[1][1] == 5 ||
                                            tabuleiro[1][1] == 6) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }

                    break;

                case 'c': /** Cavalo vermelho **/
                    if (trocarNome) {
                        for (i = 0; i < 3; i++) {
                            for (j = 0; j < 3; j++) {
                                if (tabuleiro[i][j] == 2) {
                                    /* Verificacao do movimento do cavalo, o cavalo pode pular pular por cima *|
                                    |*           das outras pecas, e tem movimento em formato de L            */

                                    if ((movimento[0] == i + 1 && movimento[1] == j + 2) ||
                                        (movimento[0] == i + 1 && movimento[1] == j - 2) ||
                                        (movimento[0] == i - 1 && movimento[1] == j + 2) ||
                                        (movimento[0] == i - 1 && movimento[1] == j - 2) ||
                                        (movimento[0] == i + 2 && movimento[1] == j + 1) ||
                                        (movimento[0] == i + 2 && movimento[1] == j - 1) ||
                                        (movimento[0] == i - 2 && movimento[1] == j + 1) ||
                                        (movimento[0] == i - 2 && movimento[1] == j - 1)) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else { /** Cavalo azul **/
                        for (i = 0; i < 3; i++) {
                            for (j = 0; j < 3; j++) {
                                if (tabuleiro[i][j] == 5) {
                                    /* A logica e identica ao cavalo vermelho */

                                    if ((movimento[0] == i + 1 && movimento[1] == j + 2) ||
                                        (movimento[0] == i + 1 && movimento[1] == j - 2) ||
                                        (movimento[0] == i - 1 && movimento[1] == j + 2) ||
                                        (movimento[0] == i - 1 && movimento[1] == j - 2) ||
                                        (movimento[0] == i + 2 && movimento[1] == j + 1) ||
                                        (movimento[0] == i + 2 && movimento[1] == j - 1) ||
                                        (movimento[0] == i - 2 && movimento[1] == j + 1) ||
                                        (movimento[0] == i - 2 && movimento[1] == j - 1)) {
                                        return 0;
                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }

                    break;

                case 't': /** Torre vermelha **/
                    if (trocarNome) {
                        for (i = 0; i < 3; i++) {
                            for (j = 0; j < 3; j++) {
                                if (tabuleiro[i][j] == 3) {
                                    /* Verificacao do movimento da torre, a torre anda apenas em linhas e colunas */

                                    if ((movimento[0] == i + 0 && movimento[1] == j + 1) ||
                                        (movimento[0] == i + 0 && movimento[1] == j - 1) ||
                                        (movimento[0] == i + 1 && movimento[1] == j + 0) ||
                                        (movimento[0] == i - 1 && movimento[1] == j + 0)) {
                                        return 0;
                                    }

                                    /* Caso o jogador queira movimentar a sua torre 2 casas na mesma linha, e necessario verificar *|
                                    |*      se existe alguma peca no caminho da torre, que e realizado nessa area do codigo        */

                                    if ((movimento[0] == i + 0 && movimento[1] == j + 2) ||
                                        (movimento[0] == i + 0 && movimento[1] == j - 2)) {
                                        if (tabuleiro[0][0] == 3 || tabuleiro[0][2] == 3) {
                                            if (tabuleiro[0][1] == 2 || tabuleiro[0][1] == 4 ||
                                                tabuleiro[0][1] == 1 || tabuleiro[0][1] == 5 ||
                                                tabuleiro[0][1] == 6) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                        if (tabuleiro[1][0] == 3 || tabuleiro[1][2] == 3) {
                                            if (tabuleiro[1][1] == 2 || tabuleiro[1][1] == 4 ||
                                                tabuleiro[1][1] == 1 || tabuleiro[1][1] == 5 ||
                                                tabuleiro[1][1] == 6) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                        if (tabuleiro[2][0] == 3 || tabuleiro[2][2] == 3) {
                                            if (tabuleiro[2][1] == 2 || tabuleiro[2][1] == 4 ||
                                                tabuleiro[2][1] == 1 || tabuleiro[2][1] == 5 ||
                                                tabuleiro[2][1] == 6) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                    }

                                    /* Caso o jogador queira movimentar a sua torre 2 casas na mesma coluna, e necessario verificar *|
                                    |*       se existe alguma peca no caminho da torre, que e realizado nessa area do codigo        */

                                    if ((movimento[0] == i + 2 && movimento[1] == j + 0) ||
                                        (movimento[0] == i - 2 && movimento[1] == j + 0)) {
                                        if (tabuleiro[0][0] == 3 || tabuleiro[2][0] == 3) {
                                            if (tabuleiro[1][0] == 2 || tabuleiro[1][0] == 4 ||
                                                tabuleiro[1][0] == 1 || tabuleiro[1][0] == 5 ||
                                                tabuleiro[1][0] == 6) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                        if (tabuleiro[0][1] == 3 || tabuleiro[2][1] == 3) {
                                            if (tabuleiro[1][1] == 2 || tabuleiro[1][1] == 4 ||
                                                tabuleiro[1][1] == 1 || tabuleiro[1][1] == 5 ||
                                                tabuleiro[1][1] == 6) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                        if (tabuleiro[0][2] == 3 || tabuleiro[2][2] == 3) {
                                            if (tabuleiro[1][2] == 2 || tabuleiro[1][2] == 4 ||
                                                tabuleiro[1][2] == 1 || tabuleiro[1][2] == 5 ||
                                                tabuleiro[1][2] == 6) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }

                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    } else { /** Torre azul **/
                        for (i = 0; i < 3; i++) {
                            for (j = 0; j < 3; j++) {
                                if (tabuleiro[i][j] == 6) {
                                    /* A logica e identica ao da torre vermelha */

                                    if ((movimento[0] == i + 0 && movimento[1] == j + 1) ||
                                        (movimento[0] == i + 0 && movimento[1] == j - 1) ||
                                        (movimento[0] == i + 1 && movimento[1] == j + 0) ||
                                        (movimento[0] == i - 1 && movimento[1] == j + 0)) {
                                        return 0;
                                    }
                                    if ((movimento[0] == i + 0 && movimento[1] == j + 2) ||
                                        (movimento[0] == i + 0 && movimento[1] == j - 2)) {
                                        if (tabuleiro[0][0] == 6 || tabuleiro[0][2] == 6) {
                                            if (tabuleiro[0][1] == 2 || tabuleiro[0][1] == 4 ||
                                                tabuleiro[0][1] == 1 || tabuleiro[0][1] == 5 ||
                                                tabuleiro[0][1] == 3) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                        if (tabuleiro[1][0] == 6 || tabuleiro[1][2] == 6) {
                                            if (tabuleiro[1][1] == 2 || tabuleiro[1][1] == 4 ||
                                                tabuleiro[1][1] == 1 || tabuleiro[1][1] == 5 ||
                                                tabuleiro[1][1] == 3) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                        if (tabuleiro[2][0] == 6 || tabuleiro[2][2] == 6) {
                                            if (tabuleiro[2][1] == 2 || tabuleiro[2][1] == 4 ||
                                                tabuleiro[2][1] == 1 || tabuleiro[2][1] == 5 ||
                                                tabuleiro[2][1] == 3) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                    }
                                    if ((movimento[0] == i + 2 && movimento[1] == j + 0) ||
                                        (movimento[0] == i - 2 && movimento[1] == j + 0)) {
                                        if (tabuleiro[0][0] == 6 || tabuleiro[2][0] == 6) {
                                            if (tabuleiro[1][0] == 2 || tabuleiro[1][0] == 4 ||
                                                tabuleiro[1][0] == 1 || tabuleiro[1][0] == 5 ||
                                                tabuleiro[1][0] == 3) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                        if (tabuleiro[0][1] == 6 || tabuleiro[2][1] == 6) {
                                            if (tabuleiro[1][1] == 2 || tabuleiro[1][1] == 4 ||
                                                tabuleiro[1][1] == 1 || tabuleiro[1][1] == 5 ||
                                                tabuleiro[1][1] == 3) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }
                                        if (tabuleiro[0][2] == 6 || tabuleiro[2][2] == 6) {
                                            if (tabuleiro[1][2] == 2 || tabuleiro[1][2] == 4 ||
                                                tabuleiro[1][2] == 1 || tabuleiro[1][2] == 5 ||
                                                tabuleiro[1][2] == 3) {
                                                return 1;
                                            } else {
                                                return 0;
                                            }
                                        }

                                    } else {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }

                    break;

                default:
                    return 1;
                    break;
            }
        }
        return 1;
    }
}

// Realiza a movimentacao das pecas
void realizarMovimento(int tabuleiro[3][3], char *nome1, char *nome2, int trocarNome, int rodadas) {
    int jogada = 0, movimento[2], i, j;
    char peca;

    /**Essa parte do codigo, garante a realizacao do movimento, fazendo com**|
    |**               que cada peca va para seu devido local               **/

    if (rodadas < 6) {
        do {
            // Escreve informacoes, indicando por exemplo de quem e a vez de jogar

            if (trocarNome) {
                printf(BOLD(RED("\t\tVez de %s - Vermelhas\n\n")), nome1);
            } else {
                printf(BOLD(BLUE("\t\tVez de %s - Azuis\n\n")), nome2);
            }

            printarTabuleiro(tabuleiro);

            printf(BOLD(WHITE("Peca (b-c-t): ")));
            scanf("%c", &peca);
            getchar();

            printf(BOLD(WHITE("Linha: ")));
            scanf("%d", &movimento[0]);
            getchar();

            printf(BOLD(WHITE("Coluna: ")));
            scanf("%d", &movimento[1]);
            getchar();

            movimento[0] -= 1;
            movimento[1] -= 1;

            jogada = verificarJogada(tabuleiro, movimento, peca, trocarNome, rodadas);

            if (jogada) {
                printf(BOLD(WHITE("\n\nMovimento invalido... Tente novamente\n\n")));
                pausar();
                limparTela();
            } else {
                // Realiza o movimento para as 6 primeiras rodadas, colocando as pecas no tabuleiro

                if (trocarNome) {
                    switch (peca) {
                        case 'b':  //Bispo Vermelho
                            tabuleiro[movimento[0]][movimento[1]] = 1;
                            break;

                        case 'c':  //Cavalo Vermelho
                            tabuleiro[movimento[0]][movimento[1]] = 2;
                            break;

                        case 't':  //Torre Vermelha
                            tabuleiro[movimento[0]][movimento[1]] = 3;
                            break;
                    }
                } else {
                    switch (peca) {
                        case 'b':  //Bispo Azul
                            tabuleiro[movimento[0]][movimento[1]] = 4;
                            break;

                        case 'c':  //Cavalo Azul
                            tabuleiro[movimento[0]][movimento[1]] = 5;
                            break;

                        case 't':  //Torre Azul
                            tabuleiro[movimento[0]][movimento[1]] = 6;
                            break;
                    }
                }
            }

        } while (jogada);
    } else {
        do {
            // Escreve informacoes, indicando por exemplo de quem e a vez de jogar

            if (trocarNome) {
                printf(BOLD(RED("\t\tVez de %s - Vermelhas\n\n")), nome1);
            } else {
                printf(BOLD(BLUE("\t\tVez de %s - Azuis\n\n")), nome2);
            }

            printarTabuleiro(tabuleiro);

            printf(BOLD(WHITE("Peca (b-c-t): ")));
            scanf("%c", &peca);
            getchar();

            printf(BOLD(WHITE("Linha: ")));
            scanf("%d", &movimento[0]);
            getchar();

            printf(BOLD(WHITE("Coluna: ")));
            scanf("%d", &movimento[1]);
            getchar();

            movimento[0] -= 1;
            movimento[1] -= 1;

            jogada = verificarJogada(tabuleiro, movimento, peca, trocarNome, rodadas);

            if (jogada) {
                printf(BOLD(WHITE("\n\nMovimento invalido... Tente novamente\n\n")));
                pausar();
                limparTela();
            } else {
                /*Para rodadas maiores que 6, essa area do codigo faz os movimentos das pecas*|
                |*  movimentos esses que ja foram verificados na funcao verificarMovimento() */

                if (trocarNome) {
                    switch (peca) {
                        case 'b':  //Bispo Vermelho
                            for (i = 0; i < 3; i++) {
                                for (j = 0; j < 3; j++) {
                                    if (tabuleiro[i][j] == 1) {
                                        tabuleiro[i][j] = 0;
                                    }
                                }
                            }
                            tabuleiro[movimento[0]][movimento[1]] = 1;
                            break;

                        case 'c':  //Cavalo Vermelho
                            for (i = 0; i < 3; i++) {
                                for (j = 0; j < 3; j++) {
                                    if (tabuleiro[i][j] == 2) {
                                        tabuleiro[i][j] = 0;
                                    }
                                }
                            }
                            tabuleiro[movimento[0]][movimento[1]] = 2;
                            break;

                        case 't':  //Torre Vermelha
                            for (i = 0; i < 3; i++) {
                                for (j = 0; j < 3; j++) {
                                    if (tabuleiro[i][j] == 3) {
                                        tabuleiro[i][j] = 0;
                                    }
                                }
                            }
                            tabuleiro[movimento[0]][movimento[1]] = 3;
                            break;
                    }
                } else {
                    switch (peca) {
                        case 'b':  //Bispo Azul
                            for (i = 0; i < 3; i++) {
                                for (j = 0; j < 3; j++) {
                                    if (tabuleiro[i][j] == 4) {
                                        tabuleiro[i][j] = 0;
                                    }
                                }
                            }
                            tabuleiro[movimento[0]][movimento[1]] = 4;
                            break;

                        case 'c':  //Cavalo Azul
                            for (i = 0; i < 3; i++) {
                                for (j = 0; j < 3; j++) {
                                    if (tabuleiro[i][j] == 5) {
                                        tabuleiro[i][j] = 0;
                                    }
                                }
                            }
                            tabuleiro[movimento[0]][movimento[1]] = 5;
                            break;

                        case 't':  //Torre Azul
                            for (i = 0; i < 3; i++) {
                                for (j = 0; j < 3; j++) {
                                    if (tabuleiro[i][j] == 6) {
                                        tabuleiro[i][j] = 0;
                                    }
                                }
                            }
                            tabuleiro[movimento[0]][movimento[1]] = 6;
                            break;
                    }
                }
            }

        } while (jogada);
    }

    return;
}

// Realiza movimento para o modo JOGADOR X COMPUTADOR
void realizarMovimento02(int tabuleiro[3][3], char *nome1, char *nome2, int trocarNome, int rodadas) {
    int jogada = 0, movimento[2], i, j;
    char peca;

    /**Essa parte do codigo, garante a realizacao do movimento, fazendo com **|
    |**que cada peca va para seu devido local, alem de garantir que o compu **|
    |**tador tambem realize seu movimnto ao chamar a funcao jogadaComputador**/

    if (rodadas < 6) {
        do {
            // Escreve informacoes, indicando por exemplo de quem e a vez de jogar, nesse caso o computador
            //joga automaticamente e entao o jogador pode jogar, e essa parte do codigo tambem indica de quem eh a vez

            if (trocarNome) {
                printf(BOLD(RED("\t\tVez de %s - Vermelhas\n\n")), nome1);

                jogadaComputador(tabuleiro, rodadas);

                printarTabuleiro(tabuleiro);

                pausar();

                jogada = 0;

            } else {
                printf(BOLD(BLUE("\t\tVez de %s - Azuis\n\n")), nome2);

                printarTabuleiro(tabuleiro);

                printf(BOLD(WHITE("Peca (b-c-t): ")));
                scanf("%c", &peca);
                getchar();

                printf(BOLD(WHITE("Linha: ")));
                scanf("%d", &movimento[0]);
                getchar();

                printf(BOLD(WHITE("Coluna: ")));
                scanf("%d", &movimento[1]);
                getchar();

                movimento[0] -= 1;
                movimento[1] -= 1;

                jogada = verificarJogada(tabuleiro, movimento, peca, trocarNome, rodadas);

                if (jogada) {
                    printf(BOLD(WHITE("\n\nMovimento invalido... Tente novamente\n\n")));
                    pausar();
                    limparTela();
                } else {
                    // Realiza o movimento para as 6 primeiras rodadas, colocando as pecas no tabuleiro

                    if (trocarNome == 0) {
                        switch (peca) {
                            case 'b':  //Bispo Azul
                                tabuleiro[movimento[0]][movimento[1]] = 4;
                                break;

                            case 'c':  //Cavalo Azul
                                tabuleiro[movimento[0]][movimento[1]] = 5;
                                break;

                            case 't':  //Torre Azul
                                tabuleiro[movimento[0]][movimento[1]] = 6;
                                break;
                        }
                    }
                }
            }
        } while (jogada);
    } else {
        do {
            // Escreve informacoes, indicando por exemplo de quem e a vez de jogar, nesse caso o computador
            //joga automaticamente e entao o jogador pode jogar, e essa parte do codigo tambem indica de quem eh a vez

            if (trocarNome) {
                printf(BOLD(RED("\t\tVez de %s - Vermelhas\n\n")), nome1);

                jogadaComputador(tabuleiro, rodadas);

                printarTabuleiro(tabuleiro);

                pausar();

                jogada = 0;
            } else {
                printf(BOLD(BLUE("\t\tVez de %s - Azuis\n\n")), nome2);

                printarTabuleiro(tabuleiro);

                printf(BOLD(WHITE("Peca (b-c-t): ")));
                scanf("%c", &peca);
                getchar();

                printf(BOLD(WHITE("Linha: ")));
                scanf("%d", &movimento[0]);
                getchar();

                printf(BOLD(WHITE("Coluna: ")));
                scanf("%d", &movimento[1]);
                getchar();

                movimento[0] -= 1;
                movimento[1] -= 1;

                jogada = verificarJogada(tabuleiro, movimento, peca, trocarNome, rodadas);

                if (jogada) {
                    printf(BOLD(WHITE("\n\nMovimento invalido... Tente novamente\n\n")));
                    pausar();
                    limparTela();
                } else {
                    /*Para rodadas maiores que 6, essa area do codigo faz os movimentos das pecas*|
                    |*  movimentos esses que ja foram verificados na funcao verificarMovimento() */

                    if (trocarNome == 0) {
                        switch (peca) {
                            case 'b':  //Bispo Azul
                                for (i = 0; i < 3; i++) {
                                    for (j = 0; j < 3; j++) {
                                        if (tabuleiro[i][j] == 4) {
                                            tabuleiro[i][j] = 0;
                                        }
                                    }
                                }
                                tabuleiro[movimento[0]][movimento[1]] = 4;
                                break;

                            case 'c':  //Cavalo Azul
                                for (i = 0; i < 3; i++) {
                                    for (j = 0; j < 3; j++) {
                                        if (tabuleiro[i][j] == 5) {
                                            tabuleiro[i][j] = 0;
                                        }
                                    }
                                }
                                tabuleiro[movimento[0]][movimento[1]] = 5;
                                break;

                            case 't':  //Torre Azul
                                for (i = 0; i < 3; i++) {
                                    for (j = 0; j < 3; j++) {
                                        if (tabuleiro[i][j] == 6) {
                                            tabuleiro[i][j] = 0;
                                        }
                                    }
                                }
                                tabuleiro[movimento[0]][movimento[1]] = 6;
                                break;
                        }
                    }
                }
            }

        } while (jogada);
    }

    return;
}

// Realiza o movimento do computador
void jogadaComputador(int tabuleiro[3][3], int rodadas) {
    int movimento[2], i, j, trocarNome_V = 1, numRand = 0, colunaRand = 0, linhaRand = 0, trocarNome_A = 0;
    int movimentou = 1, k, l, m, n;
    //Tabuleiros auxiliares de movimentos
    int movimentosValidosB_V[3][3], movimentosValidosC_V[3][3], movimentosValidosT_V[3][3];
    int movimentosValidosB_A[3][3], movimentosValidosC_A[3][3], movimentosValidosT_A[3][3];
    //Tabuleiro auxiliar principal
    int tabuleiroAux[3][3];

    /**Essa parte do codigo se responsabiliza pelo movimento do computador, sao utilizados tabuleiros   **|
    |**auxiliares para cada peca, afim de verificar se um movimento pode ganhar o jogo ou impedir que   **|
    |**o jogador ganhe, caso um desses dois casos seja valido nessa sequencia, o computador se movimenta**/

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            //Eh zerado todas as casas dos tabuleiros auxiliares de movimentos, e o tabuleiro auxiliar
            //principal vai recebendo todas as informacoes do tabuleiro principal

            movimentosValidosB_V[i][j] = 0;
            movimentosValidosC_V[i][j] = 0;
            movimentosValidosT_V[i][j] = 0;
            movimentosValidosB_A[i][j] = 0;
            movimentosValidosC_A[i][j] = 0;
            movimentosValidosT_A[i][j] = 0;
            tabuleiroAux[i][j] = tabuleiro[i][j];

            movimento[0] = i;
            movimento[1] = j;

            //Os tabuleiros auxiliares de movimentos validos recebem 1 para onde as pecas podem se mover
            //e recebem 0, para onde o movimento eh invalido

            if (verificarJogada(tabuleiro, movimento, 'b', trocarNome_V, rodadas) == 0) {
                movimentosValidosB_V[i][j] = 1;
            }

            if (verificarJogada(tabuleiro, movimento, 'c', trocarNome_V, rodadas) == 0) {
                movimentosValidosC_V[i][j] = 1;
            }

            if (verificarJogada(tabuleiro, movimento, 't', trocarNome_V, rodadas) == 0) {
                movimentosValidosT_V[i][j] = 1;
            }

            if (verificarJogada(tabuleiro, movimento, 'b', trocarNome_A, rodadas) == 0) {
                movimentosValidosB_A[i][j] = 1;
            }

            if (verificarJogada(tabuleiro, movimento, 'c', trocarNome_A, rodadas) == 0) {
                movimentosValidosC_A[i][j] = 1;
            }

            if (verificarJogada(tabuleiro, movimento, 't', trocarNome_A, rodadas) == 0) {
                movimentosValidosT_A[i][j] = 1;
            }
        }
    }
    /** TAMV = Tabuleiro auxiliar de movimentos validos **|
    |**       TAP = Tabuleiro auxiliar principal        **/

    /**Essa area do codigo garante que o computador ganhe a partida quando possivel, entao para cada **|
    |**peca eh utilizado do TAMV da peca, e o computador joga no TAP, entao eh verificado se com esse**|
    |**movimento ele pode ganhar o jogo, caso sim, o computador joga no tabuleiro normal, caso contra**|
    |**rio, o movimento eh retirado do TAP, e entao eh verificado o proximo movimento valido e assim **|
    |**       por diante, e caso nao funcione pro bispo, vai pro cavalo e depois para a torre        **/

    if (rodadas < 6) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (movimentosValidosB_V[i][j] == 1) {  //Movimentos validos do bispo vermelho
                    tabuleiroAux[i][j] = 1;

                    if (verificarFim(tabuleiroAux, trocarNome_V, rodadas) == 1) {
                        tabuleiro[i][j] = 1;

                        return;
                    }

                    tabuleiroAux[i][j] = 0;

                } else if (movimentosValidosC_V[i][j] == 1) {  //Movimentos validos do cavalo vermelho
                    tabuleiroAux[i][j] = 2;
                    if (verificarFim(tabuleiroAux, trocarNome_V, rodadas) == 1) {
                        tabuleiro[i][j] = 2;

                        return;
                    }

                    tabuleiroAux[i][j] = 0;

                } else if (movimentosValidosT_V[i][j] == 1) {  //Movimentos validos da torre vermelha
                    tabuleiroAux[i][j] = 3;
                    if (verificarFim(tabuleiroAux, trocarNome_V, rodadas) == 1) {
                        tabuleiro[i][j] = 3;

                        return;
                    }

                    tabuleiroAux[i][j] = 0;
                }
            }
        }
    } else {  //O mesmo eh realizado para rodadas maiores que 6
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (movimentosValidosB_V[i][j] == 1) {  //Movimentos validos do bispo vermelho
                    for (k = 0; k < 3; k++) {
                        for (l = 0; l < 3; l++) {
                            if (tabuleiroAux[k][l] == 1) {
                                tabuleiroAux[k][l] = 0;
                                tabuleiroAux[i][j] = 1;

                                if (verificarFim(tabuleiroAux, trocarNome_V, rodadas) == 1) {
                                    tabuleiro[k][l] = 0;
                                    tabuleiro[i][j] = 1;

                                    return;
                                }

                                tabuleiroAux[k][l] = 1;
                                tabuleiroAux[i][j] = 0;
                            }
                        }
                    }
                }
                if (movimentosValidosC_V[i][j] == 1) {  //Movimentos validos do cavalo vermelho
                    for (k = 0; k < 3; k++) {
                        for (l = 0; l < 3; l++) {
                            if (tabuleiroAux[k][l] == 2) {
                                tabuleiroAux[k][l] = 0;
                                tabuleiroAux[i][j] = 2;

                                if (verificarFim(tabuleiroAux, trocarNome_V, rodadas) == 1) {
                                    tabuleiro[k][l] = 0;
                                    tabuleiro[i][j] = 2;

                                    return;
                                }
                                tabuleiroAux[k][l] = 2;
                                tabuleiroAux[i][j] = 0;
                            }
                        }
                    }
                }
                if (movimentosValidosT_V[i][j] == 1) {  //Movimentos validos da torre vermelha
                    for (k = 0; k < 3; k++) {
                        for (l = 0; l < 3; l++) {
                            if (tabuleiroAux[k][l] == 3) {
                                tabuleiroAux[k][l] = 0;
                                tabuleiroAux[i][j] = 3;

                                if (verificarFim(tabuleiroAux, trocarNome_V, rodadas) == 1) {
                                    tabuleiro[k][l] = 0;
                                    tabuleiro[i][j] = 3;

                                    return;
                                }

                                tabuleiroAux[k][l] = 3;
                                tabuleiroAux[i][j] = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    /**Caso o computador nao consiga ganhar, outra coisa eh necessaria, entao eh feito uma verificacao afim de **|
    |**que caso o Jogador possa ganhar na proxima rodada, o computador impeca isso, dessa forma, eh utilizado  **|
    |**o mesmo sistema apresentado acima, utiliza-se do TAMV do azul e novamente eh feito uma jogada no TAP,   **|
    |**caso esse movimento possa vencer, eh utilizado do TAMV das vermelhas pra ver qual peca pode impedir isso**|
    |**caso nenhuma consiga o jogador ja venceu, caso consiga eh feito o movimento, e entao eh verificado para **|
    |**todas as pecas se ha a possibilidade de vitoria do azul, para que o computador possa impedir se possivel**/

    if (rodadas < 6) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (movimentosValidosB_A[i][j] == 1) {  //Movimentos validos do bispo azul
                    tabuleiroAux[i][j] = 4;

                    if (verificarFim(tabuleiroAux, trocarNome_A, rodadas) == 1) {
                        if (movimentosValidosB_V[i][j] == 1) {  //Movimentos validos do bispo vermelho
                            tabuleiro[i][j] = 1;
                            return;
                        } else if (movimentosValidosC_V[i][j] == 1) {  //Movimentos validos do cavalo vermelho
                            tabuleiro[i][j] = 2;
                            return;
                        } else if (movimentosValidosT_V[i][j] == 1) {  //Movimentos validos da torre vermelha
                            tabuleiro[i][j] = 3;
                            return;
                        }
                    }
                    tabuleiroAux[i][j] = 0;

                } else if (movimentosValidosC_A[i][j] == 1) {  //Movimentos validos do cavalo azul
                    tabuleiroAux[i][j] = 5;

                    if (verificarFim(tabuleiroAux, trocarNome_A, rodadas) == 1) {
                        if (movimentosValidosB_V[i][j] == 1) {  //Movimentos validos do bispo vermelho
                            tabuleiro[i][j] = 1;
                            return;
                        } else if (movimentosValidosC_V[i][j] == 1) {  //Movimentos validos do cavalo vermelho
                            tabuleiro[i][j] = 2;
                            return;
                        } else if (movimentosValidosT_V[i][j] == 1) {  //Movimentos validos da torre vermelha
                            tabuleiro[i][j] = 3;
                            return;
                        }
                    }
                    tabuleiroAux[i][j] = 0;

                } else if (movimentosValidosT_A[i][j] == 1) {  //Movimentos validos da torre azul
                    tabuleiroAux[i][j] = 6;

                    if (verificarFim(tabuleiroAux, trocarNome_A, rodadas) == 1) {
                        if (movimentosValidosB_V[i][j] == 1) {  //Movimentos validos do bispo vermelho
                            tabuleiro[i][j] = 1;
                            return;
                        } else if (movimentosValidosC_V[i][j] == 1) {  //Movimentos validos do cavalo vermelho
                            tabuleiro[i][j] = 2;
                            return;
                        } else if (movimentosValidosT_V[i][j] == 1) {  //Movimentos validos da torre vermelha
                            tabuleiro[i][j] = 3;
                            return;
                        }
                    }
                    tabuleiroAux[i][j] = 0;
                }
            }
        }
    } else {  //Para rodadas maiores que 6 o mesmo eh realizado
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (movimentosValidosB_A[i][j] == 1) {  //Movimentos validos do bispo azul
                    for (k = 0; k < 3; k++) {
                        for (l = 0; l < 3; l++) {
                            if (tabuleiroAux[k][l] == 4) {
                                tabuleiroAux[k][l] = 0;
                                tabuleiroAux[i][j] = 4;

                                if (verificarFim(tabuleiroAux, trocarNome_A, rodadas) == 1) {
                                    if (movimentosValidosB_V[i][j] == 1) {  //Movimentos validos do bispo vermelho
                                        for (m = 0; m < 3; m++) {
                                            for (n = 0; n < 3; n++) {
                                                if (tabuleiro[m][n] == 1) {
                                                    tabuleiro[m][n] = 0;
                                                    tabuleiro[i][j] = 1;
                                                    return;
                                                }
                                            }
                                        }
                                    } else if (movimentosValidosC_V[i][j] == 1) {  //Movimentos validos do cavalo vermelho
                                        for (m = 0; m < 3; m++) {
                                            for (n = 0; n < 3; n++) {
                                                if (tabuleiro[m][n] == 2) {
                                                    tabuleiro[m][n] = 0;
                                                    tabuleiro[i][j] = 2;
                                                    return;
                                                }
                                            }
                                        }
                                    } else if (movimentosValidosT_V[i][j] == 1) {  //Movimentos validos da torre vermelha
                                        for (m = 0; m < 3; m++) {
                                            for (n = 0; n < 3; n++) {
                                                if (tabuleiro[m][n] == 3) {
                                                    tabuleiro[m][n] = 0;
                                                    tabuleiro[i][j] = 3;
                                                    return;
                                                }
                                            }
                                        }
                                    }
                                }

                                tabuleiroAux[k][l] = 4;
                                tabuleiroAux[i][j] = 0;
                            }
                        }
                    }
                }

                if (movimentosValidosC_A[i][j] == 1) {  //Movimentos validos do cavalo azul
                    for (k = 0; k < 3; k++) {
                        for (l = 0; l < 3; l++) {
                            if (tabuleiroAux[k][l] == 5) {
                                tabuleiroAux[k][l] = 0;
                                tabuleiroAux[i][j] = 5;

                                if (verificarFim(tabuleiroAux, trocarNome_A, rodadas) == 1) {
                                    if (movimentosValidosB_V[i][j] == 1) {  //Movimentos validos do bispo vermelho
                                        for (m = 0; m < 3; m++) {
                                            for (n = 0; n < 3; n++) {
                                                if (tabuleiro[m][n] == 1) {
                                                    tabuleiro[m][n] = 0;
                                                    tabuleiro[i][j] = 1;
                                                    return;
                                                }
                                            }
                                        }
                                    } else if (movimentosValidosC_V[i][j] == 1) {  //Movimentos validos do cavalo vermelho
                                        for (m = 0; m < 3; m++) {
                                            for (n = 0; n < 3; n++) {
                                                if (tabuleiro[m][n] == 2) {
                                                    tabuleiro[m][n] = 0;
                                                    tabuleiro[i][j] = 2;
                                                    return;
                                                }
                                            }
                                        }
                                    } else if (movimentosValidosT_V[i][j] == 1) {  //Movimentos validos da torre vermelha
                                        for (m = 0; m < 3; m++) {
                                            for (n = 0; n < 3; n++) {
                                                if (tabuleiro[m][n] == 3) {
                                                    tabuleiro[m][n] = 0;
                                                    tabuleiro[i][j] = 3;
                                                    return;
                                                }
                                            }
                                        }
                                    }
                                }

                                tabuleiroAux[k][l] = 5;
                                tabuleiroAux[i][j] = 0;
                            }
                        }
                    }
                }

                if (movimentosValidosT_A[i][j] == 1) {  //Movimentos validos da torre azul
                    for (k = 0; k < 3; k++) {
                        for (l = 0; l < 3; l++) {
                            if (tabuleiroAux[k][l] == 6) {
                                tabuleiroAux[k][l] = 0;
                                tabuleiroAux[i][j] = 6;

                                if (verificarFim(tabuleiroAux, trocarNome_A, rodadas) == 1) {
                                    if (movimentosValidosB_V[i][j] == 1) {  //Movimentos validos do bispo vermelho
                                        for (m = 0; m < 3; m++) {
                                            for (n = 0; n < 3; n++) {
                                                if (tabuleiro[m][n] == 1) {
                                                    tabuleiro[m][n] = 0;
                                                    tabuleiro[i][j] = 1;
                                                    return;
                                                }
                                            }
                                        }
                                    } else if (movimentosValidosC_V[i][j] == 1) {  //Movimentos validos do cavalo vermelho
                                        for (m = 0; m < 3; m++) {
                                            for (n = 0; n < 3; n++) {
                                                if (tabuleiro[m][n] == 2) {
                                                    tabuleiro[m][n] = 0;
                                                    tabuleiro[i][j] = 2;
                                                    return;
                                                }
                                            }
                                        }
                                    } else if (movimentosValidosT_V[i][j] == 1) {  //Movimentos validos da torre vermelha
                                        for (m = 0; m < 3; m++) {
                                            for (n = 0; n < 3; n++) {
                                                if (tabuleiro[m][n] == 3) {
                                                    tabuleiro[m][n] = 0;
                                                    tabuleiro[i][j] = 3;
                                                    return;
                                                }
                                            }
                                        }
                                    }
                                }

                                tabuleiroAux[k][l] = 6;
                                tabuleiroAux[i][j] = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    /**Caso o computador nao possa nem ganhar nem impedir que o azul ganhe eh feito um movimento aleatorio**/

    srand(time(0));
    do {
        numRand = (rand() % 3);

        if (numRand == 0) {
            if (rodadas < 6) {
                linhaRand = (rand() % 3);

                colunaRand = (rand() % 3);

                if (movimentosValidosB_V[linhaRand][colunaRand] == 1) {  //Movimentos validos do bispo vermelho
                    tabuleiro[linhaRand][colunaRand] = 1;

                    movimentou = 0;
                    return;
                }

            } else {
                linhaRand = (rand() % 3);

                colunaRand = (rand() % 3);

                if (movimentosValidosB_V[linhaRand][colunaRand] == 1) {  //Movimentos validos do bispo vermelho
                    for (i = 0; i < 3; i++) {
                        for (j = 0; j < 3; j++) {
                            if (tabuleiro[i][j] == 1) {
                                tabuleiro[i][j] = 0;
                                tabuleiro[linhaRand][colunaRand] = 1;

                                movimentou = 0;
                                return;
                            }
                        }
                    }
                }
            }
        } else if (numRand == 1) {
            if (rodadas < 6) {
                linhaRand = (rand() % 3);

                colunaRand = (rand() % 3);

                if (movimentosValidosC_V[linhaRand][colunaRand] == 1) {  //Movimentos validos do cavalo vermelho
                    tabuleiro[linhaRand][colunaRand] = 2;

                    movimentou = 0;
                    return;
                }

            } else {
                linhaRand = (rand() % 3);

                colunaRand = (rand() % 3);

                if (movimentosValidosC_V[linhaRand][colunaRand] == 1) {  //Movimentos validos do cavalo vermelho
                    for (i = 0; i < 3; i++) {
                        for (j = 0; j < 3; j++) {
                            if (tabuleiro[i][j] == 2) {
                                tabuleiro[i][j] = 0;
                                tabuleiro[linhaRand][colunaRand] = 2;

                                movimentou = 0;
                                return;
                            }
                        }
                    }
                }
            }
        } else if (numRand == 2) {
            if (rodadas < 6) {
                linhaRand = (rand() % 3);

                colunaRand = (rand() % 3);

                if (movimentosValidosT_V[linhaRand][colunaRand] == 1) {  //Movimentos validos da torre vermelha
                    tabuleiro[linhaRand][colunaRand] = 3;

                    movimentou = 0;
                    return;
                }

            } else {
                linhaRand = (rand() % 3);

                colunaRand = (rand() % 3);

                if (movimentosValidosT_V[linhaRand][colunaRand] == 1) {  //Movimentos validos da torre vermelha
                    for (i = 0; i < 3; i++) {
                        for (j = 0; j < 3; j++) {
                            if (tabuleiro[i][j] == 3) {
                                tabuleiro[i][j] = 0;
                                tabuleiro[linhaRand][colunaRand] = 3;

                                movimentou = 0;
                                return;
                            }
                        }
                    }
                }
            }
        }

    } while (movimentou);

    return;
}

// Entra no modo JOGADOR x JOGADOR
void escolha01(int tabuleiro[3][3], char *nome1, char *nome2) {
    int parar = 0, trocarNome = 1, rodadas = 0;

    /**Recebe os nomes dos jogadores**/

    limparTela();

    printf(BOLD(WHITE("\t\tNome dos jogadores")));
    printf(BOLD(RED("\n\n\nJogador 01 - Vermelhas: ")));
    scanf("%s", nome1);
    getchar();

    printf(BOLD(BLUE("Jogador 02 - Azuis: ")));
    scanf("%s", nome2);
    getchar();

    limparTabuleiro(tabuleiro);

    do {
        /**-----------------------------------------------------------------------------**|
        |** Utilizando das funcoes criadas, essa area faz o jogo, no comeco e realizado **|
        |** os movimentos, entao sera atribuido a variavel 'parar' um valor, caso esse  **|
        |** valor seja igual a zero, o jogo continua, caso seja igual a um, algum joga- **|
        |** dor venceu, e por fim se igual a 2 deu velha, e entao, repete-se o processo **|
        |**-----------------------------------------------------------------------------**/

        limparTela();

        realizarMovimento(tabuleiro, nome1, nome2, trocarNome, rodadas);

        parar = verificarFim(tabuleiro, trocarNome, rodadas);

        if (parar == 1) {  // Algum jogador venceu
            limparTela();

            if (trocarNome) {
                printf(BOLD(WHITE("\n\n\t\tFIM DE JOGO!!!\n\n")));
                pausar();
                limparTela();

                printf(BOLD(RED("\t\tVENCEDOR - %s (Vermelhas)\n\n")), nome1);

                printarTabuleiro(tabuleiro);

            } else {
                printf(BOLD(WHITE("\n\n\t\tFIM DE JOGO!!!\n\n")));
                pausar();
                limparTela();

                printf(BOLD(BLUE("\t\tVENCEDOR - %s (Azuis)\n\n")), nome2);

                printarTabuleiro(tabuleiro);
            }
        } else if (parar == 2) {  // Empate
            limparTela();

            printf(BOLD(WHITE("\n\n\t\tFIM DE JOGO!!!\n\n")));
            pausar();
            limparTela();

            printf(BOLD(WHITE("\t\tVELHA!!!\n\n")));

            printarTabuleiro(tabuleiro);
        }

        if (trocarNome) {
            trocarNome = 0;
        } else {
            trocarNome = 1;
        }

        rodadas++;
    } while (parar == 0);

    return;
}

// Entra no modo COMPUTADOR x JOGADOR
void escolha02(int tabuleiro[3][3], char *nome1, char *nome2) {
    int parar = 0, trocarNome = 1, rodadas = 0;

    /**Recebe os nomes dos jogadores**/

    limparTela();

    printf(BOLD(WHITE("\t\tNome do jogador\n\n\n")));
    nome1 = "Computador";

    printf(BOLD(BLUE("Humano - Azuis: ")));
    scanf("%s", nome2);
    getchar();

    limparTabuleiro(tabuleiro);

    do {
        /**-----------------------------------------------------------------------------**|
        |** Utilizando das funcoes criadas, essa area faz o jogo, no comeco e realizado **|
        |** os movimentos, entao sera atribuido a variavel 'parar' um valor, caso esse  **|
        |** valor seja igual a zero, o jogo continua, caso seja igual a um, algum joga- **|
        |** dor venceu, e por fim se igual a 2 deu velha, e entao, repete-se o processo **|
        |**-----------------------------------------------------------------------------**/

        limparTela();

        realizarMovimento02(tabuleiro, nome1, nome2, trocarNome, rodadas);

        parar = verificarFim(tabuleiro, trocarNome, rodadas);

        if (parar == 1) {  // Algum jogador venceu
            limparTela();

            if (trocarNome) {
                printf(BOLD(WHITE("\n\n\t\tFIM DE JOGO!!!\n\n")));
                pausar();
                limparTela();

                printf(BOLD(RED("\t\tVENCEDOR - %s (Vermelhas)\n\n")), nome1);

                printarTabuleiro(tabuleiro);

            } else {
                printf(BOLD(WHITE("\n\n\t\tFIM DE JOGO!!!\n\n")));
                pausar();
                limparTela();

                printf(BOLD(BLUE("\t\tVENCEDOR - %s (Azuis)\n\n")), nome2);

                printarTabuleiro(tabuleiro);
            }
        } else if (parar == 2) {  // Empate
            limparTela();

            printf(BOLD(WHITE("\n\n\t\tFIM DE JOGO!!!\n\n")));
            pausar();
            limparTela();

            printf(BOLD(WHITE("\t\tVELHA!!!\n\n")));

            printarTabuleiro(tabuleiro);
        }

        if (trocarNome) {
            trocarNome = 0;
        } else {
            trocarNome = 1;
        }

        rodadas++;
    } while (parar == 0);

    return;
}

// Entra no tutorial do jogo
void escolha03(void) {
    int tabuleiroTutorial[3][3];

    /**Nessa area do codigo eh feita uma pequena expllicacao do funcionamento do jogo **|
    |**como regras e funcionamento das pecas, alem de um rapido tutorial de como jogar**/

    limparTela();
    limparTabuleiro(tabuleiroTutorial);

    // Sao escritos pequenos textos sobre o que eh o jogo, regras e funcionamento das pecas
    printf(BOLD(WHITE("\tO TateDrez e um jogo que provem da mistura do Xadrez com o Jogo da Velha. Para joga-lo, e preciso entender as pecas e os movimentos:\n\n* Existem 3 pecas: o bispo, o cavalo e a torre;\n* O bispo se movimenta em casas nas diagonais;\n* O cavalo se movimenta em L - uma casa na horizontal ou vertical + uma casa na diagonal;\n* A torre se movimenta em casas nas verticais ou nas horizontais;\n\n\tO jogo e dividido em duas etapas:\n* Na primeira etapa, ate a 6 jogada, cada jogador, alternadamente, deve colocar suas pecas em qualquer coordenada valida no tabuleiro; Isso deve ser feito sem movimentar uma peca ja colocada, apenas adicionando uma nova;\n* Na segunda etapa, cada jogador, alternadamente, deve mover uma de suas pecas no tabuleiro, para uma casa em que seja possivel movimentar a peca desejada. Em seguida, o outro jogador se movimenta da mesma forma, mas com suas respectivas pecas. Nessa etapa, as pecas nao saem mais do tabuleiro, ou seja, nao e possivel 'comer' as pecas do adversario;\n\n\tO jogo acaba em 3 ocasioes:\n* Quando nao ha movimentos validos na vez do jogador atual;\n* Quando 3 casas consecutivas sao ocupadas pelas 3 pecas do mesmo jogador, ou vermelhas ou azuis. As casas ocupadas podem ser nas diagonais; nas horizontais; ou nas verticais;\n* Quando o numero de rodadas chega a 30;\n\n\tVejamos um exemplo: \n\n\n")));

    pausar();
    limparTela();

    // A partir da aqui eh feito um pequeno tutorial
    printf(BOLD(RED("\t\tVez de Jogador 01 - Vermelhas\n\n")));
    printarTabuleiro(tabuleiroTutorial);
    printf(BOLD(WHITE("\n\n Eis aqui o ambiente de jogo. Primeiro, as pecas vermelhas jogam:\n\nPeca: b\nLinha: 3\nColuna: 2")));

    pausar();
    limparTela();

    // Utiliza-se de um tabuleiro para mostrar ao usuario
    tabuleiroTutorial[2][1] = 1;

    printf(BOLD(BLUE("\t\tVez de Jogador 02 - Azuis\n\n")));
    printarTabuleiro(tabuleiroTutorial);
    printf(BOLD(WHITE("\n\n Agora, as azuis jogam:\n\nPeca: t\nLinha: 1\nColuna: 3")));

    pausar();
    limparTela();

    tabuleiroTutorial[0][2] = 6;

    //Para detalhe, como eh um tutorial eh escrito 'vez de' em cores sortidas
    printf(BOLD(RED("\t\tV")));
    printf(BOLD(BLUE("e")));
    printf(BOLD(RED("z")));
    printf(BOLD(BLUE(" d")));
    printf(BOLD(RED("e")));

    printf(BOLD(BLUE(" .")));
    printf(BOLD(RED(".")));
    printf(BOLD(BLUE(".")));
    printf(BOLD(RED(" - ")));
    printf(BOLD(BLUE(".")));
    printf(BOLD(RED(".")));
    printf(BOLD(BLUE(".\n\n")));

    printarTabuleiro(tabuleiroTutorial);
    printf(BOLD(WHITE("\n\n E assim segue ate a rodada 6, onde comeca o jogo de fato...")));

    pausar();
    limparTela();

    tabuleiroTutorial[0][1] = 5;
    tabuleiroTutorial[1][0] = 3;
    tabuleiroTutorial[1][1] = 4;
    tabuleiroTutorial[2][2] = 2;

    printf(BOLD(RED("\t\tVez de Jogador 01 - Vermelhas\n\n")));
    printarTabuleiro(tabuleiroTutorial);

    printf(BOLD(WHITE("\n\n Agora, nesse exemplo, basta a torre vermelha se movimentar para a casa (Linha 3 - Coluna 1) que ela ganha;\n\nPeca: t\nLinha: 3\nColuna: 1")));

    pausar();
    limparTela();

    tabuleiroTutorial[2][0] = 3;
    tabuleiroTutorial[1][0] = 0;
    printf(BOLD(RED("\t\tVENCEDOR - Jogador 01 (Vermelhas)\n\n")));
    printarTabuleiro(tabuleiroTutorial);

    printf(BOLD(WHITE("\n\n Fim de jogo :)\n")));

    pausar();
    limparTela();

    return;
}

// Imprime o menu do jogo
int menu(void) {
    int escolha;

    limparTela();

    do {
        printf(BOLD(WHITE("\t\tTateDrez\n\n\n")));

        printf(BOLD(WHITE("1 - Jogador x Jogador\n")));
        printf(BOLD(WHITE("2 - Jogador x Computador\n")));
        printf(BOLD(WHITE("3 - Tutorial\n")));
        printf(BOLD(WHITE("4 - Sair\n\n")));

        printf(BOLD(WHITE("Escolha: ")));
        scanf("%d", &escolha);
        getchar();

        if (escolha < 1 || escolha > 4) {  // Nao permite a escolha de valores diferentes de 1, 2, 3 e 4
            printf(BOLD(WHITE("\nOpcao invalida!!! Escolha outra...\n\n")));
            pausar();
            limparTela();
        }

    } while (escolha < 1 || escolha > 4);

    return escolha;
}

// Imprime o tabuleiro
void printarTabuleiro(int tabuleiro[3][3]) {
    int i, j;

    /**Imprime o tabuleiro do jogo, alem das legendas de apoio**/

    /*---------------------*|
    |* Bispo vermelho = 1  *|
    |* Bispo azul = 4      *|
    |* Cavalo vermelho = 2 *|
    |* Cavalo azul = 5     *|
    |* Torre vermelha = 3  *|
    |* Torre azul = 6      *|
    |*---------------------*/

    printf(BOLD(WHITE("\n      1     2     3\t\t\t\t\t\tLEGENDA:\n")));
    for (i = 1; i <= 3; i++) {
        printf("\n");
        printf(BOLD(WHITE("%d  ")), i);
        for (j = 0; j < 3; j++) {
            if (tabuleiro[i - 1][j] == 0) {
                printf(BOLD(WHITE(" {   }")));
            } else if (tabuleiro[i - 1][j] == 1) {
                printf(BOLD(RED(" { b }")));
            } else if (tabuleiro[i - 1][j] == 2) {
                printf(BOLD(RED(" { c }")));
            } else if (tabuleiro[i - 1][j] == 3) {
                printf(BOLD(RED(" { t }")));
            } else if (tabuleiro[i - 1][j] == 4) {
                printf(BOLD(BLUE(" { b }")));
            } else if (tabuleiro[i - 1][j] == 5) {
                printf(BOLD(BLUE(" { c }")));
            } else if (tabuleiro[i - 1][j] == 6) {
                printf(BOLD(BLUE(" { t }")));
            }
        }
        switch (i) {
            case 0:
                printf(BOLD(RED("\t\t\t\tVermelhas")));
                printf(BOLD(WHITE(" // ")));
                printf(BOLD(BLUE("Azuis\n")));
                break;

            case 1:
                printf(BOLD(WHITE("\t\t\t\tb: bispo // c: cavalo // t: torre\n")));
                break;

            case 2:
                printf(BOLD(WHITE("\t\t\t\tExemplo: ")));
                printf(BOLD(BLUE("t")));
                printf(BOLD(WHITE(" (Azuis - torre)\n")));
                break;
        }
    }
    printf("\n\n\n");

    return;
}

// Limpa o tabuleiro
void limparTabuleiro(int tabuleiro[3][3]) {
    int i, j;

    /**Atribui 0 a todas as casas do tabuleiro**/

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    return;
}

// Funcao principal do programa
int main(void) {
    int tabuleiro[3][3];
    int escolha;
    char nome1[50], nome2[50];

    /**Estrutura principal do codigo, que apos a escolha no menu, realizara tudo por funcoes**/

    while (1) {
        escolha = menu();

        if (escolha == 1) {
            escolha01(tabuleiro, nome1, nome2);
            pausar();
        } else if (escolha == 2) {
            escolha02(tabuleiro, nome1, nome2);
            pausar();
        } else if (escolha == 3) {
            escolha03();
        } else if (escolha == 4) {
            exit(EXIT_SUCCESS);
        }
    }

    return (EXIT_SUCCESS);
}
