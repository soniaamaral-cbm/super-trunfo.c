#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3

#define AGUA 0
#define NAVIO 3
#define EFEITO 5

#define HAB 5  // tamanho das matrizes de habilidade (5x5)

/* =========================================================
   Inicializa o tabuleiro com 0 (água)
========================================================= */
void inicializarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tab[i][j] = AGUA;
        }
    }
}

/* =========================================================
   Exibe o tabuleiro (0 = água, 3 = navio, 5 = habilidade)
========================================================= */
void exibirTabuleiro(int tab[TAM][TAM]) {
    printf("\nTABULEIRO (0=água, 3=navio, 5=habilidade)\n\n");

    printf("    ");
    for (int c = 0; c < TAM; c++) printf("%d ", c);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d | ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

/* =========================================================
   Verifica se uma coordenada (linha/coluna) é válida no tabuleiro
========================================================= */
int coordenadaValida(int linha, int coluna) {
    return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM);
}

/* =========================================================
   Verifica se um navio cabe no tabuleiro (H/V/Diagonais)
   'H' horizontal (coluna +)
   'V' vertical   (linha +)
   'D' diagonal "\" (linha +, coluna +)
   'I' diagonal "/"  (linha +, coluna -)
========================================================= */
int cabeNoTabuleiro(int linha, int coluna, char orientacao) {
    if (!coordenadaValida(linha, coluna)) return 0;

    if (orientacao == 'H') {
        if (coluna + NAVIO_TAM - 1 >= TAM) return 0;
    } else if (orientacao == 'V') {
        if (linha + NAVIO_TAM - 1 >= TAM) return 0;
    } else if (orientacao == 'D') { // "\"
        if (linha + NAVIO_TAM - 1 >= TAM) return 0;
        if (coluna + NAVIO_TAM - 1 >= TAM) return 0;
    } else if (orientacao == 'I') { // "/"
        if (linha + NAVIO_TAM - 1 >= TAM) return 0;
        if (coluna - (NAVIO_TAM - 1) < 0) return 0;
    } else {
        return 0; // orientação inválida
    }

    return 1;
}

/* =========================================================
   Verifica se a área para o navio está livre (sem sobreposição)
========================================================= */
int areaLivre(int tab[TAM][TAM], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        for (int k = 0; k < NAVIO_TAM; k++) {
            if (tab[linha][coluna + k] != AGUA) return 0;
        }
    } else if (orientacao == 'V') {
        for (int k = 0; k < NAVIO_TAM; k++) {
            if (tab[linha + k][coluna] != AGUA) return 0;
        }
    } else if (orientacao == 'D') { // "\"
        for (int k = 0; k < NAVIO_TAM; k++) {
            if (tab[linha + k][coluna + k] != AGUA) return 0;
        }
    } else if (orientacao == 'I') { // "/"
        for (int k = 0; k < NAVIO_TAM; k++) {
            if (tab[linha + k][coluna - k] != AGUA) return 0;
        }
    } else {
        return 0;
    }

    return 1;
}

/* =========================================================
   Posiciona navio usando um vetor 1D (valores 3) copiando pro tabuleiro
========================================================= */
int posicionarNavio(int tab[TAM][TAM], int navio[NAVIO_TAM],
                    int linha, int coluna, char orientacao) {

    // 1) valida se cabe
    if (!cabeNoTabuleiro(linha, coluna, orientacao)) return 0;

    // 2) valida se não sobrepõe
    if (!areaLivre(tab, linha, coluna, orientacao)) return 0;

    // 3) copia vetor para tabuleiro conforme orientação
    if (orientacao == 'H') {
        for (int k = 0; k < NAVIO_TAM; k++) tab[linha][coluna + k] = navio[k];
    } else if (orientacao == 'V') {
        for (int k = 0; k < NAVIO_TAM; k++) tab[linha + k][coluna] = navio[k];
    } else if (orientacao == 'D') { // "\"
        for (int k = 0; k < NAVIO_TAM; k++) tab[linha + k][coluna + k] = navio[k];
    } else if (orientacao == 'I') { // "/"
        for (int k = 0; k < NAVIO_TAM; k++) tab[linha + k][coluna - k] = navio[k];
    }

    return 1;
}

/* =========================================================
   (MESTRE) Construção dinâmica das matrizes de habilidade (0/1)
   - cone: ponto no topo (linha 0, col centro) expandindo para baixo
   - cruz: centro
   - octaedro: losango (distância Manhattan ao centro)
========================================================= */

/* Cone apontando para baixo (5x5):
   linha 0: 00100
   linha 1: 01110
   linha 2: 11111 (mantemos tamanho razoável, cone "cheio" após expandir)
   linha 3: 11111 
   linha 4: 11111 
   Regra usada:
   - para cada linha r, o "raio" cresce: raio = r
   - marca colunas entre (centro - raio) e (centro + raio)
   - limitado ao tamanho da matriz
*/
void criarCone(int cone[HAB][HAB]) {
    int centro = HAB / 2;

    for (int r = 0; r < HAB; r++) {
        for (int c = 0; c < HAB; c++) {
            int raio = r; // expande para baixo
            if (c >= centro - raio && c <= centro + raio) cone[r][c] = 1;
            else cone[r][c] = 0;
        }
    }
}

/* Cruz (5x5) centro:
   marca linha do centro e coluna do centro
*/
void criarCruz(int cruz[HAB][HAB]) {
    int centro = HAB / 2;

    for (int r = 0; r < HAB; r++) {
        for (int c = 0; c < HAB; c++) {
            if (r == centro || c == centro) cruz[r][c] = 1;
            else cruz[r][c] = 0;
        }
    }
}

/* Octaedro (losango) - vista frontal:
   usa distância Manhattan ao centro:
   |r-centro| + |c-centro| <= raio
   Para HAB=5, raio=2 => losango bem definido
*/
void criarOctaedro(int oct[HAB][HAB]) {
    int centro = HAB / 2;
    int raio = HAB / 2;

    for (int r = 0; r < HAB; r++) {
        for (int c = 0; c < HAB; c++) {
            int dist = (r - centro);
            if (dist < 0) dist = -dist;
            int dist2 = (c - centro);
            if (dist2 < 0) dist2 = -dist2;

            if (dist + dist2 <= raio) oct[r][c] = 1;
            else oct[r][c] = 0;
        }
    }
}

/* =========================================================
   (MESTRE) Sobrepor habilidade no tabuleiro
   - origemTab (linha,coluna) é o "centro" da habilidade no tabuleiro
   - para cada célula da matriz de habilidade:
       se for 1, calcula a posição correspondente no tabuleiro
       e marca com 5, MAS sem apagar NAVIO (3)
========================================================= */
void aplicarHabilidadeNoTabuleiro(int tab[TAM][TAM], int hab[HAB][HAB],
                                 int origemLinha, int origemColuna) {

    int centro = HAB / 2;

    for (int r = 0; r < HAB; r++) {
        for (int c = 0; c < HAB; c++) {

            if (hab[r][c] == 1) {
                int linhaTab = origemLinha + (r - centro);
                int colTab   = origemColuna + (c - centro);

                // garante que não sai do tabuleiro
                if (coordenadaValida(linhaTab, colTab)) {
                    // não apaga navio: se já for 3, mantém 3
                    if (tab[linhaTab][colTab] == AGUA) {
                        tab[linhaTab][colTab] = EFEITO;
                    }
                }
            }
        }
    }
}

/* =========================================================
   (Opcional) Mostrar uma matriz de habilidade (0/1) no console
========================================================= */
void exibirMatrizHabilidade(const char *nome, int hab[HAB][HAB]) {
    printf("\nMATRIZ %s (0/1)\n", nome);
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            printf("%d ", hab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Navios como vetores 1D (tamanho fixo 3)
    int navioH[NAVIO_TAM] = {NAVIO, NAVIO, NAVIO};
    int navioV[NAVIO_TAM] = {NAVIO, NAVIO, NAVIO};
    int navioD1[NAVIO_TAM] = {NAVIO, NAVIO, NAVIO}; // diagonal "\"
    int navioD2[NAVIO_TAM] = {NAVIO, NAVIO, NAVIO}; // diagonal "/"

    // Matrizes de habilidade (0/1)
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    inicializarTabuleiro(tabuleiro);

    /* =====================================================
       (AVENTUREIRO) Posiciona 4 navios:
       - 2 horizontais/verticais
       - 2 diagonais
       Coordenadas definidas no código (simplificação)
    ===================================================== */

    // Navio horizontal
    if (!posicionarNavio(tabuleiro, navioH, 1, 1, 'H')) {
        printf("Erro: não foi possível posicionar navio horizontal.\n");
    }

    // Navio vertical
    if (!posicionarNavio(tabuleiro, navioV, 5, 8, 'V')) {
        printf("Erro: não foi possível posicionar navio vertical.\n");
    }

    // Navio diagonal "\" (linha+, coluna+)
    if (!posicionarNavio(tabuleiro, navioD1, 3, 2, 'D')) {
        printf("Erro: não foi possível posicionar navio diagonal \\.\n");
    }

    // Navio diagonal "/" (linha+, coluna-)
    if (!posicionarNavio(tabuleiro, navioD2, 6, 5, 'I')) {
        printf("Erro: não foi possível posicionar navio diagonal /.\n");
    }

    /* =====================================================
       (MESTRE) Cria matrizes de habilidade dinamicamente
    ===================================================== */
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // (Opcional) ver as matrizes 0/1
    exibirMatrizHabilidade("CONE", cone);
    exibirMatrizHabilidade("CRUZ", cruz);
    exibirMatrizHabilidade("OCTAEDRO", octaedro);

    /* =====================================================
       (MESTRE) Aplicar as habilidades no tabuleiro
       Define pontos de origem (linha/coluna) no tabuleiro
    ===================================================== */
    int origemConeLinha = 2, origemConeCol = 7;
    int origemCruzLinha = 7, origemCruzCol = 2;
    int origemOctLinha  = 4, origemOctCol  = 4;

    aplicarHabilidadeNoTabuleiro(tabuleiro, cone, origemConeLinha, origemConeCol);
    aplicarHabilidadeNoTabuleiro(tabuleiro, cruz, origemCruzLinha, origemCruzCol);
    aplicarHabilidadeNoTabuleiro(tabuleiro, octaedro, origemOctLinha, origemOctCol);

    /* =====================================================
       Exibir tabuleiro final com navios + áreas de efeito (5)
    ===================================================== */
    exibirTabuleiro(tabuleiro);

    return 0;
}