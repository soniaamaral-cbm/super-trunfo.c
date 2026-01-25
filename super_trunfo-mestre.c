#include <stdio.h>

int main() {
    /* variáveis da Carta 1 */
    unsigned long int populacao1;   // mestre: unsigned long int
    int pontos1;
    float area1;
    float pib1;                     // em bilhões
    float densidade1;
    float pibPerCapita1;
    float superPoder1;
    float inversoDens1;
    char estado1;
    char codigo1[4];
    char cidade1[50];

    /* variáveis da Carta 2 */
    unsigned long int populacao2;   // mestre: unsigned long int
    int pontos2;
    float area2;
    float pib2;                     // em bilhões
    float densidade2;
    float pibPerCapita2;
    float superPoder2;
    float inversoDens2;
    char estado2;
    char codigo2[4];
    char cidade2[50];

    /* Leitura dos dados da Carta 1 */
    printf("=== Carta 1 ===\n");
    printf("Estado: ");
    scanf(" %c", &estado1);

    printf("Código: ");
    scanf("%3s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", cidade1);

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos1);

    /* Cálculos da Carta 1 */
    densidade1 = (area1 > 0) ? (float)populacao1 / area1 : 0.0f;
    pibPerCapita1 = (populacao1 > 0) ? (pib1 * 1000000000.0f) / (float)populacao1 : 0.0f;

    inversoDens1 = (densidade1 > 0) ? 1.0f / densidade1 : 0.0f;

    superPoder1 =
        (float)populacao1 +
        area1 +
        pib1 +
        (float)pontos1 +
        pibPerCapita1 +
        inversoDens1;

    /* Leitura dos dados da Carta 2 */
    printf("\n=== Carta 2 ===\n");
    printf("Estado: ");
    scanf(" %c", &estado2);

    printf("Código: ");
    scanf("%3s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", cidade2);

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos2);

    /* Cálculos da Carta 2 */
    densidade2 = (area2 > 0) ? (float)populacao2 / area2 : 0.0f;
    pibPerCapita2 = (populacao2 > 0) ? (pib2 * 1000000000.0f) / (float)populacao2 : 0.0f;

    inversoDens2 = (densidade2 > 0) ? 1.0f / densidade2 : 0.0f;

    superPoder2 =
        (float)populacao2 +
        area2 +
        pib2 +
        (float)pontos2 +
        pibPerCapita2 +
        inversoDens2;

    /* resultados (mantém a exibição dos níveis anteriores) */
    printf("\n=== Resultado ===\n");

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    /* Comparações (mestre) */
    int vPop   = (populacao1 > populacao2) ? 1 : 0;
    int vArea  = (area1 > area2) ? 1 : 0;
    int vPIB   = (pib1 > pib2) ? 1 : 0;
    int vPonto = (pontos1 > pontos2) ? 1 : 0;

    /* densidade: menor vence */
    int vDens  = (densidade1 < densidade2) ? 1 : 0;

    int vPibPc = (pibPerCapita1 > pibPerCapita2) ? 1 : 0;
    int vSuper = (superPoder1 > superPoder2) ? 1 : 0;

    printf("\n=============================\n");
    printf("Comparação de Cartas:\n\n");

    printf("População: %s venceu (%d)\n", (vPop == 1) ? "Carta 1" : "Carta 2", vPop);
    printf("Área: %s venceu (%d)\n", (vArea == 1) ? "Carta 1" : "Carta 2", vArea);
    printf("PIB: %s venceu (%d)\n", (vPIB == 1) ? "Carta 1" : "Carta 2", vPIB);
    printf("Pontos Turísticos: %s venceu (%d)\n", (vPonto == 1) ? "Carta 1" : "Carta 2", vPonto);
    printf("Densidade Populacional: %s venceu (%d)\n", (vDens == 1) ? "Carta 1" : "Carta 2", vDens);
    printf("PIB per Capita: %s venceu (%d)\n", (vPibPc == 1) ? "Carta 1" : "Carta 2", vPibPc);
    printf("Super Poder: %s venceu (%d)\n", (vSuper == 1) ? "Carta 1" : "Carta 2", vSuper);

    return 0;
}
