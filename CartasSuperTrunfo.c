#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TOTAL_CARTAS 5

// Definindo as cartas do jogo como as capitais de 5 países

typedef struct {
    char  nome[20];            // Brasil, Japão, etc                     
    char  cidade[30];          // Capital                                
    int   codigo;              // Código numérico                        
    long  populacao;           // Habitantes                             
    double area;               // km²                                    
    double pib;                // PIB em R$ (aproximado)                 
    int   pontos_turisticos;   // Nº de principais atrações turísticas   
} Carta;

// Baralho

Carta baralho[TOTAL_CARTAS] = {
    { "Brasil",         "Brasília",       76,  214300000, 8515767, 11774, 23 },
    { "Coreia do Sul",  "Seul",          410,   51700000,   100363, 10122, 16 },
    { "Japão",          "Tóquio",        392,  125200000,   377975, 24527, 20 },
    { "Canadá",         "Ottawa",        124,   40000000, 9984670, 12236, 20 },
    { "Estados Unidos", "Washington DC", 840,  335000000, 9833517,161294, 21 }
};

// Atributos (informações das cidades) 

void mostrarCarta(const Carta *c) {
    printf("País: %s\n",                c->nome);
    printf("1. Código ISO-numérico: %d\n", c->codigo);
    printf("2. População: %ld\n",       c->populacao);
    printf("3. Área (km²): %.0f\n",     c->area);
    printf("4. PIB (R$ bi): %.0f\n",   c->pib);
    printf("5. Pontos turísticos: %d\n",c->pontos_turisticos);
}
int comparar(const Carta *jog, const Carta *cpu, int atributo) {
 double vJog = 0, vCpu = 0;
    switch (atributo) {
        case 1: vJog = jog->codigo;             vCpu = cpu->codigo;             break;
        case 2: vJog = jog->populacao;          vCpu = cpu->populacao;          break;
        case 3: vJog = jog->area;               vCpu = cpu->area;               break;
        case 4: vJog = jog->pib;                vCpu = cpu->pib;                break;
        case 5: vJog = jog->pontos_turisticos;  vCpu = cpu->pontos_turisticos;  break;
        default: return -1;
    }

    printf("\nSeu valor: %.0f  x  Valor CPU: %.0f\n", vJog, vCpu);

    if      (vJog > vCpu) return 1;
    else if (vJog < vCpu) return 2;
    else                  return 0;
}
//  main  
int main(void) {
    srand((unsigned)time(NULL));

    int i = rand() % TOTAL_CARTAS;      // carta do jogador     
    int j;
    do { j = rand() % TOTAL_CARTAS; }   // carta do computador  
    while (j == i);

    Carta jogador   = baralho[i];
    Carta computador= baralho[j];

    puts("\n  Sua carta:");
    mostrarCarta(&jogador);

    int escolha;
    puts("\nEscolha o atributo para competir:");
    puts("   1-Código  2-População  3-Área  4-PIB  5-Pontos Turísticos");
    printf("Digite de 1 a 6: ");
    if (scanf("%d", &escolha) != 1 || escolha < 1 || escolha > 6) {
        puts("Entrada inválida. Encerrando.");
        return 1;
    }

    puts("\n  Carta do Computador:");
    mostrarCarta(&computador);

    int resultado = comparar(&jogador, &computador, escolha);
    
    switch (resultado) {
        case 1: puts("\n Você venceu!");  break;
        case 2: puts("\n Você perdeu.");  break;
        case 0: puts("\n Empate!");       break;
        default:puts("\nErro na comparação");
    }

    return 0;
}







