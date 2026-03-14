#include <stdio.h>
#include <stdlib.h>

void imprimir_binario(int n) {
    // Array para armazenar os bits (32 bits para int)
    int bits[32];
    int i = 0;

    // Caso especial para 0
    if (n == 0) {
        printf("0");
        return;
    }

    // Converte para binário
    while (n > 0) {
        bits[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Imprime os bits na ordem correta (do último para o primeiro)
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bits[j]);
        // Adiciona espaço a cada 4 bits para melhor legibilidade
        if (j % 4 == 0 && j != 0) {
            printf(" ");
        }
    }
}

void imprimir_resultados(double resultado) {
    int parte_inteira = (int)resultado;
    double parte_fracionaria = resultado - parte_inteira;

    printf("\n=== MAIS RESULTADOS PARA PROGRAMADORES ===\n");
    printf("Decimal:      %.2f\n", resultado);

    // Parte inteira em hexadecimal (apenas se for inteiro ou positivo)
    if (parte_fracionaria == 0 && resultado >= 0) {
        printf("Hexadecimal:  0x%X\n", parte_inteira);
    } else {
        printf("Hexadecimal:  (apenas para números inteiros positivos)\n");
    }

    // Parte inteira em binário (apenas se for inteiro e positivo)
    if (parte_fracionaria == 0 && resultado >= 0) {
        printf("Binário:      ");
        imprimir_binario(parte_inteira);
        printf("\n");
    } else {
        printf("Binário:      (apenas para números inteiros positivos)\n");
    }

    printf("=====================================\n");
}

int main() {

    char operador;
    double num1, num2, resultado;
    char continuar;

    do {
        system("clear || cls"); // Limpa a tela (funciona em Linux/Windows)

        printf("=== CALCULADORA SIMPLES ===\n");
        printf("Operações disponíveis: +, -, *, /\n");
        printf("Digite 's' para sair a qualquer momento\n\n");

        // Entrada do primeiro número
        printf("Digite o primeiro número: ");
        if (scanf("%lf", &num1) != 1) {
            printf("Erro: Entrada inválida!\n");
            // Limpa o buffer do teclado
            while(getchar() != '\n');
            continue;
        }

        // Entrada do operador
        printf("Digite o operador (+, -, *, /): ");
        scanf(" %c", &operador);

        // Verifica se quer sair
        if (operador == 's' || operador == 'S') {
            printf("Calculadora encerrada.\n");
            break;
        }

        // Entrada do segundo número
        printf("Digite o segundo número: ");
        if (scanf("%lf", &num2) != 1) {
            printf("Erro: Entrada inválida!\n");
            while(getchar() != '\n');
            continue;
        }

        // Realiza o cálculo
        switch(operador) {
            case '+':
                resultado = num1 + num2;
                printf("\n%.2lf + %.2lf = %.2lf\n", num1, num2, resultado);
                imprimir_resultados(resultado);
                break;

            case '-':
                resultado = num1 - num2;
                printf("\n%.2lf - %.2lf = %.2lf\n", num1, num2, resultado);
                imprimir_resultados(resultado);
                break;

            case '*':
                resultado = num1 * num2;
                printf("\n%.2lf * %.2lf = %.2lf\n", num1, num2, resultado);
                imprimir_resultados(resultado);
                break;

            case '/':
                if (num2 != 0) {
                    resultado = num1 / num2;
                    printf("\n%.2lf / %.2lf = %.2lf\n", num1, num2, resultado);
                    imprimir_resultados(resultado);
                } else {
                    printf("\nErro: Divisão por zero não permitida!\n");
                }
                break;

            default:
                printf("\nErro: Operador inválido! Use +, -, *, / ou 's' para sair\n");
        }


        // Pergunta se quer continuar
        printf("\nDeseja fazer outro cálculo? (s/n): ");
        scanf(" %c", &continuar);

    } while(continuar == 's' || continuar == 'S');

    printf("\nObrigado por usar a calculadora!\n");
    return 0;
}
