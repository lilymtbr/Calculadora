#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void base_10_para_base2 (int numero) {
    int vetor[100];
    int i = 0;
    while (numero>0) {
        vetor[i] = numero % 2;
        numero=numero/2;
        i++;
    }

    for (i = i - 1; i >= 0; i--) {
        printf("%d", vetor[i]);
    }
    printf("\n");
}

void base_10_para_base8 (int numero) {
    int vetor[100];
    int i = 0;
    while (numero>0) {
        vetor[i] = numero % 8;
        numero=numero/8;
        i++;
    }

    for (i = i - 1; i >= 0; i--) {
        printf("%d", vetor[i]);
    }
    printf("\n");
}

void base_10_para_base16 (int numero) {
    char vetor[100];
    int elemento;
    int i = 0;
    while (numero>0) {
        elemento = numero % 16;
        if (elemento == 10) {
            vetor[i] = 'A';
        } 
        else if (elemento == 11) {
            vetor[i] = 'B';
        } 
        else if (elemento == 12) {
            vetor[i] = 'C';
        } 
        else if (elemento == 13) {
            vetor[i] = 'D';
        } 
        else if (elemento == 14) {
            vetor[i] = 'E';
        } 
        else if (elemento == 15) {
            vetor[i] = 'F';
        }
        else {
            vetor[i] = 48 + elemento;
        }
        numero=numero/16;
        i++;
    }

    for (i = i - 1; i >= 0; i--) {
        printf("%c", vetor[i]);
    }
    printf("\n");
}

int base_10_para_BCD (int numero) {
    printf("Nada ainda.\n");
    return 0;
}

int base_10_para_base_sinal_16bits (int numero) {
    printf("Nada ainda.\n");
    return 0;
}

double real_para_float (int numero) {
    printf("Nada ainda.\n");
    return 0;
}

double real_para_double (int numero2) {
    printf("Nada ainda.\n");
    return 0;
}

int main(void) {
    int operacao, continuar = 1;
    int numero;
    double numero2;

    while (continuar == 1) {
        printf("Digite que operação você deseja realizar na calculadora: \n1- Para converter um número inteiro de base 10 para base 2\n2- Para converter um número inteiro de base 10 para base 8\n3- Para converter um número inteiro de base 10 para base 16\n4- Para converter um número inteiro de base 10 para código BCD\n5- Para converter um número inteiro de base 10 para base com sinal com 16 bits (complemento a 2)\n6- Para converter real em decimal para float e double\n7- Para encerrar o programa\n ");
        scanf("%d", &operacao);

        switch(operacao) {
            case 1:
                printf("Digite um número inteiro: \n");
                scanf("%d", &numero);
                base_10_para_base2 (numero);
                break;

            case 2:
                printf("Digite um número inteiro: \n");
                scanf("%d", &numero);
                base_10_para_base8 (numero);
                break;

            case 3:
                printf("Digite um número inteiro: \n");
                scanf("%d", &numero);
                base_10_para_base16 (numero);
                break;

            case 4:
                printf("Digite um número inteiro: \n");
                scanf("%d", &numero);
                break;

            case 5:
                printf("Digite um número inteiro: \n");
                scanf("%d", &numero);
                break;

            case 6:
                printf("Digite um número real: \n");
                scanf("%lf", &numero2);
                break;
            
            case 7:
                printf("Você encerrou o programa!\n");
                continuar = 0;
                break;

            default:
                printf("Você digitou uma alternativa inválida. Digite novamente!\n");
        }
    }
}