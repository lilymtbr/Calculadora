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
    printf("\nPasso a passo: convertendo %d para binário.\n\n", numero);
    printf("Primeiro, cria-se um vetor para armazenar os dígitos binários e uma variável i, que representa o índice dos elementos do vetor.\n\n");
    printf("Em seguida, divide-se o número por 2 repetidamente, armazenando os restos no vetor até que o número seja menor ou igual a zero.\n\n");

    int vetor[100];
    int i = 0;

    while (numero>0) {
        printf("%d dividido por 2: %d\n", numero, numero/2);
        vetor[i] = numero % 2;
        printf("Resto: %d\n\n", vetor[i]);
        numero=numero/2;
        i++;
    }
    printf("Por fim, imprime-se o vetor em ordem inversa para formar o número binário.\n\n");
    printf("Resposta: ");
    for (i = i - 1; i >= 0; i--) {
        printf("%d", vetor[i]);
    }
    printf("\n\n");
}

void base_10_para_base8 (int numero) {
    printf("\nPasso a passo: convertendo %d para octal.\n\n", numero);
    printf("Primeiro, cria-se um vetor para armazenar os dígitos octais e uma variável i, que representa o índice dos elementos do vetor.\n\n");
    printf("Em seguida, divide-se o número por 8 sucessivamente até que o número seja menor ou igual a zero, armazenando os restos nos índices do vetor.\n\n");

    int vetor[100];
    int i = 0;

    while (numero>0) {
        printf("%d dividido por 8: %d\n", numero, numero/8);
        vetor[i] = numero % 8;
        printf("Resto: %d\n\n", vetor[i]);
        numero=numero/8;
        i++;
    }

    printf("Por fim, imprimem-se os elementos do vetor em ordem inversa para formar o número na base 8.\n\nResposta: ");
    for (i = i - 1; i >= 0; i--) {
        printf("%d", vetor[i]);
    }
    printf("\n\n");
}

void base_10_para_base16 (int numero) {
    printf("\nPasso a passo: convertendo %d para hexadecimal.\n\n", numero);
    printf("Primeiro, cria-se um vetor de caracteres para armazenar os dígitos hexadecimais e uma variável i, que representa o índice dos elementos do vetor.\n\n");
    printf("Em seguida, divide-se o número por 16 sucessivamente até que o número seja menor ou igual a zero, armazenando os restos nos índices do vetor.\n\n");
    printf("Quando o resto for 10, deve-se armazenar o caractere 'A'; se for 11, 'B'; e assim sucessivamente até que o resto 15 corresponda ao caractere 'F'.\n\n");

    char vetor[100];
    int elemento;
    int i = 0;
    
    while (numero>0) {
        printf("%d dividido por 16: %d\n", numero, numero/16);
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
        printf("Resto: %c\n\n", vetor[i]);
        numero=numero/16;
        i++;
    }

    printf("Por fim, imprimem-se os elementos do vetor em ordem inversa para formar o número na base 16.\n\nResposta: ");
    for (i = i - 1; i >= 0; i--) {
        printf("%c", vetor[i]);
    }
    printf("\n\n");
}

void base_10_para_BCD (int numero) {
    printf("\nPasso a passo: convertendo %d para BCD.\n\n", numero);
    printf("Primeiro, cria-se um vetor de inteiros para armazenar os dígitos em BCD e uma variável i, que representa o índice dos elementos do vetor.\n\n");
    printf("Em seguida, extrai-se cada dígito decimal do número, começando pelo menos significativo, e converte-se esse dígito em seu equivalente binário de 4 bits.\n\n");
    printf("Enquanto houver dígitos a serem processados, a conversão é realizada e os bits resultantes são armazenados no vetor.");

    int vetor[100];
    int digito;
    int i = 0;
    while (numero>0) {
        digito = numero%10;
        printf("\n\nDigito %d em binário: ", digito);
        for (int j = 0; j<4; j++) {
            vetor[i] = digito % 2;
            digito=digito/2;
            i++;
        }

        numero=numero/10;
        for (int j = i - 1; j >= i - 4; j--) {
            printf("%d", vetor[j]);
        }
        printf("\n\n");
    }
    
    printf("Por fim, os bits armazenados são impressos em ordem inversa, formando a representação final do número em BCD.\n\nResposta: ");
    int cont=1;
    for (i = i - 1; i >= 0; i--) {
        printf("%d", vetor[i]);
        if (cont % 4 == 0) {
            printf(" ");
        }
        cont++;
    }
    printf("\n\n");
}

void base_10_para_base_sinal_16bits (int numero) {
    printf("\nPasso a passo: convertendo %d para base com sinal com 16 bits (complemento a 2).\n\n", numero);
    
    int vetor[16];
    int i = 0; 
    
    if (numero >= 0) {
        printf("Como o número é positivo, ele é convertido diretamente para binário, preenchendo os 15 primeiros bits do vetor com os dígitos correspondentes.\n\n");
        while (i<15) {
            printf("%d dividido por 2: %d\n", numero, numero/2);
            vetor[i] = numero % 2;
            printf("Resto: %d\n\n", vetor[i]);
            numero=numero/2;
            i++;
        }
        vetor[i] = 0;
        printf("O último bit é definido como 0 (bit de sinal)\n\n");
        printf("Por fim, os bits do vetor são impressos na ordem inversa, com o primeiro bit representando o sinal e os outros 15 correspondendo ao número.\n\n");
    }

    else {
        printf("Visto que o número é negativo, o valor absoluto é convertido para binário e armazenado nos 15 primeiros bits do vetor.\n\n");
        printf("%d é convertido para seu valor absoluto %d\n\n", numero, -numero);
        numero = -numero;
        while (i < 15) {
            printf("%d dividido por 2: %d\n", numero, numero/2);
            vetor[i] = numero % 2;
            printf("Resto: %d\n\n", vetor[i]);
            numero=numero/2;
            i++;
        }

        printf("Valor em binário: ");
        for (i = i-1; i >= 0; i--) {
            printf("%d", vetor[i]);
        }

        printf("\n\n");
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
        printf("Em seguida, aplica-se o complemento de 2: da direita para esquerda, os bits permanecem inalterados até o primeiro '1', e todos os bits subsequentes são invertidos.\n\n");
        printf("O bit de sinal é definido como 1.\n\n");
        printf("Por fim, os bits do vetor são impressos, com o primeiro bit representando o sinal e os outros 15 correspondendo ao número.\n\n");

    }
        
    for (i = i; i >= 0; i--) {
        printf("%d", vetor[i]);
    }
    printf("\n\n");
}

void real_para_float (double numero) {
    printf("\nPasso a passo: convertendo %lf para float.\n\n", numero);
    printf("Separa-se a parte inteira e a parte fracionária do número.\n\n");
       
    int vetor[32];
    int vetor2[8];
    int vetor3[23];
    int vetor4[32];
    int i = 0;
    int cont = -1;
    int numero_inteiro = (int)numero;
    double fracao = numero - (int)numero;
    int indice_vetor4=0;

    printf("Parte inteira: %d\n", numero_inteiro);
    printf("Parte fracionária: %lf\n\n", fracao);
    printf("Reserva-se o primeiro bit para sinal (0 para positivo, 1 para negativo).\n\n");

    if (numero_inteiro >= 0) {
        printf("Bit de sinal: 0\n\n");
        vetor4[indice_vetor4 ] = 0;
        indice_vetor4++;
    }
    
    else {
        printf("Bit de sinal: 1\n\n");
        vetor4[indice_vetor4] = 1;
        indice_vetor4++;
        numero_inteiro = -numero_inteiro;
        fracao = -fracao;
        }

    printf("Converte-se a parte inteira para binário.\n\n");
    while (numero_inteiro > 0) {
            printf("%d dividido por 2: %d\n", numero_inteiro, numero_inteiro/2);
            vetor[i] = numero_inteiro % 2;
            printf("Resto: %d\n\n", vetor[i]);
            numero_inteiro=numero_inteiro/2;
            i++;
            cont++;
    }
    printf("Em binário: ");
    for (int l = cont; l >= 0; l--) {
        printf("%d", vetor[l]);
    }
    printf("\n\n");

    int expoente = cont + 127;
    printf("Calcula-se o expoente ajustado com o bias de 127.\n\nExpoente = %d + 127 = %d.\n\n", cont, expoente);
    printf("Converte-se o expoente ajustado para binário.\n\n");

    for (int j = 0; j < 8; j++) {
            vetor2[j] = expoente % 2;
            expoente = expoente/2;
    }
    printf("Expoente em binário: ");
    for (int k = 7; k >= 0; k--) {
        printf("%d", vetor2[k]);
        vetor4[indice_vetor4] = vetor2[k];
        indice_vetor4++;
    }
    printf("\n\n");
    printf("Constrói-se a mantissa primeiramente a partir da parte inteira em binário (exceto o primeiro bit).\n\nPrimeira parte da mantissa: ");

    for (int l = cont-1; l >= 0; l--) {
        printf("%d", vetor[l]);
        vetor4[indice_vetor4] = vetor[l];
        indice_vetor4++;
    }
    printf("\n\nPosteriormente, combina-se a parte fracionária.\n\n");
    printf("A parte fracionária é convertida para binário multiplicando-a por 2 repetidamente e guardando e subtraindo a parte inteira de cada resultado.\n\n");
   
    for (int m = 0; m < 23 - cont; m++) {
        printf("%lf multiplicado por dois é: %lf\n\n", fracao, fracao*2);
        fracao = fracao * 2;
        printf("Parte inteira é: %d\n\n", (int)fracao);
        if (fracao >= 1.0) {
            printf("Subtrai 1.0.\n\n", (int)fracao);
            vetor3[m]=  1;
            fracao = fracao - 1.0;
        }
        
        else {
            printf("Não subtrai nada.\n\n", (int)fracao);
            vetor3[m] = 0;
        }
    }
    printf("Segunda parte da mantissa: ");
    for (int n = 0; n < 23 - cont; n++) {
        printf("%d", vetor3[n]);
        vetor4[indice_vetor4] = vetor3[n];
        indice_vetor4++;
    }
    printf("\n\n");
    printf("Imprime-ese o sinal (1 bit), o expoente (8 bits) e a mantissa (23 bits) na ordem correta para a representação em float.\nResposta:\n\n");

    for (int o = 0; o < 32; o++) {
        printf("%d", vetor4[o]);
        if (o==0 || o==8) {
            printf(" ");
        }
    }
    printf("\n\n");
}

void real_para_double (double numero) {
    printf("\nPasso a passo: convertendo %lf para double.\n\n", numero);
    printf("Separa-se a parte inteira e a parte fracionária do número.\n\n");

    int vetor[32];
    int vetor2[11];
    int vetor3[52];
    int vetor4[64];
    int i = 0;
    int cont = -1;
    int numero_inteiro = (int)numero;
    double fracao = numero - (int)numero;
    int indice_vetor4=0;

    printf("Parte inteira: %d\n", numero_inteiro);
    printf("Parte fracionária: %lf\n\n", fracao);
    printf("Reserva-se o primeiro bit para sinal (0 para positivo, 1 para negativo).\n\n");
    
    if (numero_inteiro >= 0) {
        printf("Bit de sinal: 0\n\n");
        vetor4[indice_vetor4 ] = 0;
        indice_vetor4++;
    }
    
    else {
        printf("Bit de sinal: 1\n\n");
        vetor4[indice_vetor4] = 1;
        indice_vetor4++;
        numero_inteiro = -numero_inteiro;
        fracao = -fracao;
        }

    printf("Converte-se a parte inteira para binário.\n\n");
    while (numero_inteiro > 0) {
        printf("%d dividido por 2: %d\n", numero_inteiro, numero_inteiro/2);
        vetor[i] = numero_inteiro % 2;
        printf("Resto: %d\n\n", vetor[i]);
        numero_inteiro=numero_inteiro/2;
        i++;
        cont++;
    } 

    printf("Em binário: ");
    for (int l = cont; l >= 0; l--) {
        printf("%d", vetor[l]);
    }
    printf("\n\n");

    
    int expoente = cont + 1023;
    printf("Calcula-se o expoente ajustado com o bias de 1023.\n\nExpoente = %d + 1023 = %d.\n\n", cont, expoente);
    printf("Converte-se o expoente ajustado para binário.\n\n");

    for (int j = 0; j < 11; j++) {
            vetor2[j] = expoente % 2;
            expoente = expoente/2;
    }
    
    printf("Expoente em binário: ");
    for (int k = 10; k >= 0; k--) {
        printf("%d", vetor2[k]);
        vetor4[indice_vetor4] = vetor2[k];
        indice_vetor4++;
    }
    
    printf("\n\n");
    printf("Constrói-se a mantissa primeiramente a partir da parte inteira em binário (exceto o primeiro bit).\n\nPrimeira parte da mantissa: ");

    for (int l = cont-1; l >= 0; l--) {
        printf("%d", vetor[l]);
        vetor4[indice_vetor4] = vetor[l];
        indice_vetor4++;
    }
    
    printf("\n\nPosteriromente, combina-se a parte fracionária.\n\n");
    printf("A parte fracionária é convertida para binário multiplicando-a por 2 repetidamente e guardando e subtraindo a parte inteira de cada resultado.\n\n");

    for (int m = 0; m < 52-cont; m++) {
        printf("%lf multiplicado por dois é: %lf\n\n", fracao, fracao*2);
        fracao = fracao * 2;
        printf("Parte inteira é: %d\n\n", (int)fracao);
        if (fracao >= 1.0) {
            printf("Subtrai 1.0.\n\n", (int)fracao);
            vetor3[m]=  1;
            fracao = fracao - 1.0;
        }
        else {
            printf("Não subtrai nada.\n\n", (int)fracao);
            vetor3[m] = 0;
        }
    }

    printf("Segunda parte da mantissa: ");
    for (int n = 0; n < 52 - cont; n++) {
        printf("%d", vetor3[n]);
        vetor4[indice_vetor4] = vetor3[n];
        indice_vetor4++;
    }

    printf("\n\n");
    printf("Imprime-ese o sinal (1 bit), o expoente (11 bits) e a mantissa (52 bits) na ordem correta para a representação em double.\nResposta:\n");

    for (int o = 0; o < 64; o++) {
        printf("%d", vetor4[o]);
        if (o==0 || o==11) {
            printf(" ");
        }
    }
    printf("\n\n");
}

int main(void) {
    int operacao, continuar = 1;
    int numero;
    double numero2;

    while (continuar == 1) {
        printf("Digite que operação você deseja realizar na calculadora: \n\n1- Para converter um número inteiro de base 10 para base 2\n2- Para converter um número inteiro de base 10 para base 8\n3- Para converter um número inteiro de base 10 para base 16\n4- Para converter um número inteiro de base 10 para código BCD\n5- Para converter um número inteiro de base 10 para base com sinal com 16 bits (complemento a 2)\n6- Para converter real em decimal para float e double\n7- Para encerrar o programa\n");
        scanf("%d", &operacao);

        switch(operacao) {
            case 1:
                printf("\nDigite um número inteiro: \n");
                scanf("%d", &numero);
                base_10_para_base2 (numero);
                break;

            case 2:
                printf("\nDigite um número inteiro: \n");
                scanf("%d", &numero);
                base_10_para_base8 (numero);
                break;

            case 3:
                printf("\nDigite um número inteiro: \n");
                scanf("%d", &numero);
                base_10_para_base16 (numero);
                break;

            case 4:
                printf("\nDigite um número inteiro: \n");
                scanf("%d", &numero);
                base_10_para_BCD (numero);
                break;

            case 5:
                printf("\nDigite um número inteiro: \n");
                scanf("%d", &numero);
                base_10_para_base_sinal_16bits (numero);
                break;

            case 6:
                printf("\nDigite um número real: \n");
                scanf("%lf", &numero2);
                real_para_float (numero2);
                real_para_double (numero2);
                break;
            
            case 7:
                printf("\nVocê encerrou o programa!\n");
                continuar = 0;
                break;

            default:
                printf("\nVocê digitou uma alternativa inválida. Digite novamente!\n");
        }
    }
}