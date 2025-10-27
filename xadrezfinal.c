#include <stdio.h>

// =====================
// MOVIMENTAÇÃO DAS PEÇAS
// =====================

// Bispo - anda na diagonal (recursão + loops aninhados)
void moverBispo(int passo)
{
    if (passo == 0)
        return; // condição de parada

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            printf("Bispo moveu 1 casa para cima e 1 para a direita.\n");
        }
    }

    moverBispo(passo - 1); // chamada recursiva até acabar os passos
}

// Torre - anda para a direita (recursão simples)
void moverTorre(int passo)
{
    if (passo == 0)
        return; // condição de parada

    printf("Torre moveu 1 casa para a direita.\n");
    moverTorre(passo - 1); // chamada recursiva
}

// Rainha - anda para a esquerda (recursão)
void moverRainha(int passoAtual, int total)
{
    if (passoAtual > total)
        return; // para quando atingir o total

    printf("Rainha moveu 1 casa para a esquerda.\n");
    moverRainha(passoAtual + 1, total); // chamada recursiva
}

// Cavalo - movimento em L (2 pra cima e 1 pra direita)
// Usa loops com múltiplas variáveis, continue e break
void moverCavalo()
{
    printf("Cavalo iniciou o movimento em L:\n");

    for (int i = 0, j = 0; i < 3 && j < 3; i++, j++)
    {
        if (i < 2)
        {
            printf("Cavalo moveu 1 casa para cima.\n");
            continue; // pula o resto do loop até subir 2 vezes
        }

        if (i == 2)
        {
            printf("Cavalo moveu 1 casa para a direita.\n");
            break; // encerra o movimento em L
        }
    }
}

// =====================
// MENU PRINCIPAL
// =====================
int main()
{
    int opcao, movimentos, casas, contador = 0;

    printf("=== DESAFIO FINAL DE XADREZ ===\n");
    printf("Quantos movimentos voce quer fazer? ");
    scanf("%d", &movimentos);

    do
    {
        printf("\n--- Movimento %d de %d ---\n", contador + 1, movimentos);
        printf("Escolha a peca para mover:\n");
        printf("1 - Bispo (diagonal)\n");
        printf("2 - Torre (para a direita)\n");
        printf("3 - Rainha (para a esquerda)\n");
        printf("4 - Cavalo (movimento em L)\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0)
        {
            printf("Saindo do jogo...\n");
            break;
        }

        switch (opcao)
        {
        case 1:
            printf("Quantas casas o Bispo deve andar? ");
            scanf("%d", &casas);
            printf("Movendo o Bispo:\n");
            moverBispo(casas);
            break;
        case 2:
            printf("Quantas casas a Torre deve andar? ");
            scanf("%d", &casas);
            printf("Movendo a Torre:\n");
            moverTorre(casas);
            break;
        case 3:
            printf("Quantas casas a Rainha deve andar (max 8)? ");
            scanf("%d", &casas);
            if (casas > 8)
                casas = 8; // limita a 8 casas
            printf("Movendo a Rainha:\n");
            moverRainha(1, casas);
            break;
        case 4:
            printf("Movendo o Cavalo:\n");
            moverCavalo();
            break;
        default:
            printf("Opcao invalida!\n");
        }

        contador++;
    } while (contador < movimentos);

    printf("\nTodos os movimentos foram realizados! Fim do jogo.\n");
    return 0;
}
