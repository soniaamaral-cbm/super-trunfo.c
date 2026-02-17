#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
int main() { 
    int resultado1 = 0, resultado2 = 0; 
    char primeiroAtributo, segundoAtributo; 
    int ataque1, ataque2, defesa1, defesa2, recuo1, recuo2; 
 
    // Gerar números aleatórios (aqui você travou valores para testar) 
    srand(time(0)); 
    ataque1 = 1; 
    ataque2 = 0; 
    defesa1 = 1; 
    defesa2 = 0; 
    recuo1  = 0; 
    recuo2  = 1; 
 
    // Início do jogo 
    printf("Bem-vindo ao jogo!\n"); 
    printf("Escolha o primeiro atributo.\n"); 
    printf("A. Ataque \n"); 
    printf("D. Defesa \n"); 
    printf("R. Recuo \n"); 
 
    printf("Escolha a comparação: "); 
    scanf(" %c", &primeiroAtributo); 
 
    switch (primeiroAtributo) { 
        case 'A': 
        case 'a': 
            printf("Você escolheu a opção de Ataque!\n"); 
            resultado1 = (ataque1 > ataque2) ? 1 : 0; 
            break; 
 
        case 'D': 
        case 'd': 
            printf("Você escolheu a opção de Defesa!\n"); 
            resultado1 = (defesa1 > defesa2) ? 1 : 0; 
            break; 
 
        case 'R': 
        case 'r': 
            printf("Você escolheu a opção de Recuo!\n"); 
            resultado1 = (recuo1 > recuo2) ? 1 : 0; 
            break; 
 
        default: 
            printf("Opção de jogo inválida!\n"); 
            return 0; // encerra o programa 
    } 
 
    printf("\nEscolha o segundo atributo.\n");
    printf("Atenção: Escolha os Atributos diferente dos Atributos do primeiro!\n");
    printf("A. Ataque \n"); 
    printf("D. Defesa \n"); 
    printf("R. Recuo \n"); 
 
    printf("Escolha a comparação: "); 
    scanf(" %c", &segundoAtributo);  // <-- sem espaço depois do %c 

     switch (segundoAtributo) { 
        case 'A': 
        case 'a': 
            printf("Você escolheu a opção de Ataque!\n"); 
            resultado2= (ataque1 > ataque2) ? 1 : 0; 
            break; 
 
        case 'D': 
        case 'd': 
            printf("Você escolheu a opção de Defesa!\n"); 
            resultado1 = (defesa1 > defesa2) ? 1 : 0; 
            break; 
 
        case 'R': 
        case 'r': 
            printf("Você escolheu a opção de Recuo!\n"); 
            resultado1 = (recuo1 > recuo2) ? 1 : 0; 
            break; 
 
        default: 
            printf("Opção de jogo inválida!\n"); 
            return 0; // encerra o programa 
    } 
 
 
    // Agora sim faz sentido comparar (e sem ponto-e-vírgula no if!) 
    if (primeiroAtributo == segundoAtributo) { 
        printf("Você escolheu o mesmo atributo!\n"); 
        return 0; // encerra para não continuar errado 
    } else { 
        switch (segundoAtributo) { 
            case 'A': 
            case 'a': 
                printf("Você escolheu a opção Ataque!\n"); 
                resultado2 = (ataque1 > ataque2) ? 1 : 0; 
                break; 
 
            case 'D': 
            case 'd': 
                printf("Você escolheu a opção Defesa!\n"); 
                resultado2 = (defesa1 > defesa2) ? 1 : 0; 
                break; 
 
            case 'R': 
            case 'r': 
                printf("Você escolheu a opção Recuo!\n"); 
                resultado2 = (recuo1 > recuo2) ? 1 : 0; 
                break; 
 
            default: 
                printf("Opção de jogo inválida!\n"); 
                return 0; 
        } 
    } 
 
// Resultado final 
if (resultado1 && resultado2) { 
printf("\nParabéns, você venceu!\n"); 
} else if (resultado1 == resultado2) { 
printf("\nEmpatou!\n"); 
} else { 
printf("\nInfelizmente você perdeu!\n"); 
} 
return 0;
}