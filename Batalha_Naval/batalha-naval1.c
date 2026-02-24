#include <stdio.h>

#define TAM 10
#define HAB 5

#define AGUA 0
#define HABIL 5

/* ================= TABULEIRO ================= */

void inicializar(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = AGUA;
}

void mostrar(int tab[TAM][TAM]) {

    printf("   ");
    for (int c = 0; c < TAM; c++) printf("%d ", c);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d | ", i);
        for (int j = 0; j < TAM; j++)
            printf("%d ", tab[i][j]);
        printf("\n");
    }
}

/* ================= MATRIZES ================= */

void criarCone(int m[HAB][HAB]) {

    int centro = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            if (i <= 2) {
                int dist = j - centro;
                if (dist < 0) dist = -dist;

                if (dist <= i) m[i][j] = 1;
                else m[i][j] = 0;
            } else m[i][j] = 0;
        }
    }
}

void criarCruz(int m[HAB][HAB]) {

    int centro = HAB / 2;

    for (int i = 0; i < HAB; i++)
        for (int j = 0; j < HAB; j++)
            m[i][j] = (i == centro || j == centro);
}

void criarOctaedro(int m[HAB][HAB]) {

    int centro = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            int dist = (i - centro);
            if (dist < 0) dist = -dist;

            int dist2 = (j - centro);
            if (dist2 < 0) dist2 = -dist2;

            if (dist + dist2 <= centro) m[i][j] = 1;
            else m[i][j] = 0;
        }
    }
}

/* ================= MOSTRAR MATRIZ ================= */

void mostrarHab(char nome[], int m[HAB][HAB]) {

    printf("\n%s:\n", nome);

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

/* ================= APLICAR ================= */

int dentro(int l, int c) {
    return (l >= 0 && l < TAM && c >= 0 && c < TAM);
}

/* cone usa topo como origem */
void aplicarCone(int tab[TAM][TAM], int hab[HAB][HAB], int origemL, int origemC) {

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            if (hab[i][j] == 1) {

                int l = origemL + i;
                int c = origemC + (j - HAB/2);

                if (dentro(l,c) && tab[l][c] == 0)
                    tab[l][c] = HABIL;
            }
        }
    }
}

/* centro */
void aplicarCentro(int tab[TAM][TAM], int hab[HAB][HAB], int origemL, int origemC) {

    int centro = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            if (hab[i][j] == 1) {

                int l = origemL + (i - centro);
                int c = origemC + (j - centro);

                if (dentro(l,c) && tab[l][c] == 0)
                    tab[l][c] = HABIL;
            }
        }
    }
}

/* ================= MAIN ================= */

int main() {

    int tab[TAM][TAM];

    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int oct[HAB][HAB];

    inicializar(tab);

    /* navio exemplo professor */
    tab[1][1] = 3;
    tab[1][2] = 3;
    tab[1][3] = 3;

    tab[5][8] = 3;
    tab[6][8] = 3;
    tab[7][8] = 3;

    tab[3][2] = 3;
    tab[4][3] = 3;
    tab[5][4] = 3;

    tab[6][5] = 3;
    tab[5][6] = 3;
    tab[4][7] = 3;

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(oct);

    mostrarHab("CONE", cone);
    mostrarHab("CRUZ", cruz);
    mostrarHab("OCTAEDRO", oct);

    /* posições iguais professor */
    aplicarCone(tab, cone, 0, 6);
    aplicarCentro(tab, cruz, 2, 3);
    aplicarCentro(tab, oct, 5, 7);

    printf("\nTABULEIRO FINAL:\n");
    mostrar(tab);

    return 0;
}