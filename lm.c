/*
* Autora: Lisa Matubara
* Período: 3º A
* Disciplina: Infraestrutura de Hardware
* Atividade: Calculadora didática de conversão entre bases e ponto flutuante de precisão simpes e dupla
* Data: 30/08/24
*
* Revisões e Atualizações:
* 1ª Questão A: Fri Aug 30 09:08:12 2024
* 1ª Questão B: Fri Aug 30 10:05:57 2024
* 1ª Questão C: Fri Aug 30 10:30:25 2024
* 1ª Questão D: Fri Aug 30 10:54:38 2024
* 2ª Questão: Fri Aug 30 11:31:16 2024
* 3ª Questão: Fri Aug 30 14:24:48 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void base_10_para_base2 (int numero) {
    printf("Primeiro, cria-se um vetor para armazenar os dígitos binários e uma variável i, que representa o índice dos elementos do vetor.\n");
    printf("Em seguida, divide-se o número por 2 repetidamente, armazenando os restos no vetor até que o número seja menor ou igual a zero.\n");
    printf("Por fim, imprime-se o vetor em ordem inversa para formar o número binário.\nResposta:\n");

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
    printf("Primeiro, cria-se um vetor para armazenar os dígitos octais e uma variável i, que representa o índice dos elementos do vetor.\n");
    printf("Em seguida, divide-se o número por 8 sucessivamente até que o número seja menor ou igual a zero, armazenando os restos nos índices do vetor.\n");
    printf("Por fim, imprimem-se os elementos do vetor em ordem inversa para formar o número na base 8.\nResposta:\n");

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
    printf("Primeiro, cria-se um vetor de caracteres para armazenar os dígitos hexadecimais e uma variável i, que representa o índice dos elementos do vetor.\n");
    printf("Em seguida, divide-se o número por 16 sucessivamente até que o número seja menor ou igual a zero, armazenando os restos nos índices do vetor.\n");
    printf("Quando o resto for 10, deve-se armazenar o caractere 'A'; se for 11, 'B'; e assim sucessivamente até que o resto 15 corresponda ao caractere 'F'.\n");
    printf("Por fim, imprimem-se os elementos do vetor em ordem inversa para formar o número na base 16.\nResposta:\n");

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

void base_10_para_BCD (int numero) {
    printf("Primeiro, cria-se um vetor de inteiros para armazenar os dígitos em BCD e uma variável i, que representa o índice dos elementos do vetor.\n");
    printf("Em seguida, extrai-se cada dígito decimal do número, começando pelo menos significativo, e converte-se esse dígito em seu equivalente binário de 4 bits.\n");
    printf("Enquanto houver dígitos a serem processados, a conversão é realizada e os bits resultantes são armazenados no vetor.\n");
    printf("Por fim, os bits armazenados são impressos em ordem inversa, formando a representação final do número em BCD.\nResposta:\n");

    int vetor[100];
    int digito;
    int i = 0;
    while (numero>0) {
        digito = numero%10;
        for (int j = 0; j<4; j++) {
            vetor[i] = digito % 2;
            digito=digito/2;
            i++;
        }
        numero=numero/10;
    }
    
    int cont=1;
    for (i = i - 1; i >= 0; i--) {
        printf("%d", vetor[i]);
        if (cont % 4 == 0) {
            printf(" ");
        }
        cont++;
    }
    printf("\n");
}

void base_10_para_base_sinal_16bits (int numero) {
    printf("Se o número for positivo, ele é convertido diretamente para binário, preenchendo os 15 primeiros bits do vetor com os dígitos correspondentes, e o último bit é definido como 0 (bit de sinal).\n");
    printf("Se o número for negativo, o valor absoluto é convertido para binário e armazenado nos 15 primeiros bits do vetor.\n");
    printf("Se o número for negativo, em seguida, aplica-se o complemento de 2: os bits permanecem inalterados até o primeiro '1', e todos os bits subsequentes são invertidos.\n");
    printf("Se o número for negativo, o bit de sinal é definido como 1.\n");
    printf("Por fim, os bits do vetor são impressos na ordem inversa, com o primeiro bit representando o sinal e os outros 15 correspondendo ao número.\nResposta:\n");

    int vetor[16];
    int i = 0; 
    
    if (numero >= 0) {
        while (i<15) {
            vetor[i] = numero % 2;
            numero=numero/2;
            i++;
        }
        vetor[i] = 0;
    }

    else {
        numero = -numero;
        while (i < 15) {
            vetor[i] = numero % 2;
            numero=numero/2;
            i++;
        }

        i=0;
        while (vetor[i] != 1 && i < 15) {
            i++;
        }
        
        i++;
        while (i < 15) {
            if (vetor[i] == 1) {
            vetor[i] = 0;
            }
            else if (vetor[i] == 0) {
                vetor[i] = 1;
            }
            i++;
        }
        vetor[i] = 1;
    }
        
    for (i = i; i >= 0; i--) {
        printf("%d", vetor[i]);
    }
    printf("\n");
}

void real_para_float (double numero) {
    printf("Reserva-se o primeiro bit para sinal (0 para positivo, 1 para negativo).\n");
    printf("Separa-se a parte inteira e a parte fracionária do número.\n");
    printf("Converte-se a parte inteira para binário e calcula o expoente ajustado com o bias de 127.\n");
    printf("Converte-se o expoente ajustado para binário.\n");
    printf("Constrói-se a mantissa a partir da parte fracionária do número e completa com a parte inteira.\n");
    printf("Imprime-ese o sinal (1 bit), o expoente (8 bits) e a mantissa (23 bits) na ordem correta para a representação em float.\n");
    
    int vetor[32];
    int vetor2[8];
    int vetor3[23];
    int i = 0;
    int cont = -1;
    int numero_inteiro = (int)numero;
    double fracao = numero - (int)numero;
    
    if (numero_inteiro >= 0) {
        printf("0 ");
    }
    
    else {
        printf("1 ");
        numero_inteiro = -numero_inteiro;
        fracao = -fracao;
        }

    while (numero_inteiro > 0) {
            vetor[i] = numero_inteiro % 2;
            numero_inteiro=numero_inteiro/2;
            i++;
            cont++;
    }
    
    int expoente = cont + 127;
    for (int j = 0; j < 8; j++) {
            vetor2[j] = expoente % 2;
            expoente = expoente/2;
    }
    
    for (int k = 7; k >= 0; k--) {
        printf("%d", vetor2[k]);
    }
    
    printf(" ");
    for (int l = cont-1; l >= 0; l--) {
        printf("%d", vetor[l]);
    }
    
    for (int m = 0; m < 23 - cont; m++) {
        fracao = fracao * 2;
        if (fracao >= 1.0) {
            vetor3[m]=  1;
            fracao = fracao - 1.0;
        }
        
        else {
            vetor3[m] = 0;
        }
    }
    
    for (int n = 0; n < 23 - cont; n++) {
        printf("%d", vetor3[n]);
    }
    printf("\n");
}

void real_para_double (double numero) {
    printf("Reserva-se o primeiro bit para sinal (0 para positivo, 1 para negativo).\n");
    printf("Separa-se a parte inteira e a parte fracionária do número.\n");
    printf("Converte-se a parte inteira para binário e calcula o expoente ajustado com o bias de 1023.\n");
    printf("Converte-se o expoente ajustado para binário.\n");
    printf("Constrói-se a mantissa a partir da parte fracionária do número e completa com a parte inteira.\n");
    printf("Imprime-ese o sinal (1 bit), o expoente (11 bits) e a mantissa (52 bits) na ordem correta para a representação em double.\n");
    
    int vetor[32];
    int vetor2[11];
    int vetor3[52];
    int i = 0;
    int cont = -1;
    int numero_inteiro = (int)numero;
    double fracao = numero - (int)numero;
    
    if (numero_inteiro >= 0) {
        printf("0 ");
    }
    
    else {
        printf("1 ");
        numero_inteiro = -numero_inteiro;
        fracao = -fracao;
        }
    
    while (numero_inteiro > 0) {
            vetor[i] = numero_inteiro % 2;
            numero_inteiro=numero_inteiro/2;
            i++;
            cont++;
    }    
    
    int expoente = cont + 1023;
    for (int j = 0; j < 11; j++) {
            vetor2[j] = expoente % 2;
            expoente = expoente/2;
    }
    
    for (int k = 10; k >= 0; k--) {
        printf("%d", vetor2[k]);
    }
    
    printf(" ");
    for (int l = cont-1; l >= 0; l--) {
        printf("%d", vetor[l]);
    }
    
    for (int m = 0; m < 52-cont; m++) {
        fracao = fracao * 2;
        if (fracao >= 1.0) {
            vetor3[m]=  1;
            fracao = fracao - 1.0;
        }
        else {
            vetor3[m] = 0;
        }
    }
    
    for (int n = 0; n < 52-cont; n++) {
        printf("%d", vetor3[n]);
    }
    printf("\n");
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
                base_10_para_BCD (numero);
                break;

            case 5:
                printf("Digite um número inteiro: \n");
                scanf("%d", &numero);
                base_10_para_base_sinal_16bits (numero);
                break;

            case 6:
                printf("Digite um número real: \n");
                scanf("%lf", &numero2);
                real_para_float (numero2);
                real_para_double (numero2);
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