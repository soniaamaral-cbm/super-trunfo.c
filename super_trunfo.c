#include <stdio.h>

int main() {
    /* ===== Declaração das variáveis da Carta 1 ===== */
   int populacao1;
   int pontosTuristicos1;
   float area1;
   float pib1;
   float densidade1;
   float pibPerCapita1;
   char estado1;
   char codigo1[4];
   char cidade1[50];

    /* ===== Declaração das variáveis da Carta 2 ===== */
    int populacao2;
    int pontosTuristicos2;
    float area2;
    float pib2;
    float densidade2;
    float pibPerCapita2;
    char estado2;
    char codigo2[4];
    char cidade2[30];

    /* ===== Entrada de dados da Carta 1 ===== */
    printf("Cadastro da Carta 1\n");

    printf("estado (A a H): \n");
    scanf(" %c", &estado1);

    printf("Codigo da Carta (ex: A01): \n");
    scanf("%s", codigo1);

    printf("Nome da Cidade: \n");
    scanf(" %[^\n]", cidade1);

    printf("Populacao: \n");
    scanf("%d", &populacao1);

    printf("Area (km²): \n");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): \n");
    scanf("%f", &pib1);

    printf("Numero de Pontos Turisticos: \n");
    scanf("%d", &pontosTuristicos1);

    /* Cálculos da Carta 1 */
    densidade1=populacao1/area1;
    pibPerCapita1=(pib1*1000000000) / populacao1;


    /* ===== Entrada de dados da Carta 2 ===== */
    printf("\nCadastro da Carta 2\n");

    printf("Estado (A a H): \n");
    scanf(" %c", &estado2);

    printf("Codigo da Carta (ex: B02): \n");
    scanf("%s", codigo2);

    printf("Nome da Cidade: \n");
    scanf(" %[^\n]", cidade2);

    printf("Populacao: \n");
    scanf("%d", &populacao2);

    printf("Area (km²): \n");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): \n");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: \n");
    scanf("%d", &pontosTuristicos2);

     /* Cálculos da Carta 1 */
    densidade2=populacao2/area2;
    pibPerCapita2=(pib2*1000000000) / populacao2;

    /* ===== Exibição da Carta 1 ===== */
    
    printf("\n===Carta 1===\n");

    printf("Estado: %c ", estado1);
    printf("Codigo: %s ", codigo1);
    printf("Nome da Cidade: %s ", cidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    /* ===== Exibição da Carta 2 ===== */

    printf("\n===Carta 2===\n");

    printf("Estado: %c ", estado2);
    printf("Codigo: %s ", codigo2);
    printf("Nome da Cidade: %s", cidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);


    return 0;
}