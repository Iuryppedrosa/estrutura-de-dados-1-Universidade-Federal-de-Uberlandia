#include <stdio.h>
#include <stdlib.h>
#include "numero_complexo.h"

int menu(){
    int escolha_usuario;
    printf("Calculadora de numeros complexos.\n");
    printf("1. Criar e mostrar numero complexo.\n");
    printf("2. Somar dois numeros complexos e mostrar o resultado.\n");
    printf("3. Subtrair dois numeros complexos e mostrar o resultado.\n");
    printf("4. Multiplicar dois numeros complexos.\n");
    printf("6. Sair.\n");
    printf("Escolha uma opcao acima: ");
    scanf("%d", &escolha_usuario);
    return escolha_usuario;
}

void *criar_numero_complexo(){

    NC *nc;
    nc = cria();

    double parte_real;
    double parte_imaginaria;


    printf("Digite um numero real (parte real): ");
    scanf("%lf", &parte_real);

    printf("Digite outro numero real (parte imaginaria): ");
    scanf("%lf", &parte_imaginaria);


    if(set_nro(nc, parte_real, parte_imaginaria) == 1){
        if(get_nro(nc, &parte_real, &parte_imaginaria) == 1){
            printf("Parte real: %2.f\nParte imaginaria: %.2f\n", parte_real, parte_imaginaria);
            printf("Numero complexo nc = %.2f + %.2fi\n", parte_real, parte_imaginaria);
        }else{
            printf("Nao foi possivel exibir o numero complexo!");
        };
    }else{
        printf("Nao foi possivel criar o numero complexo!");
    };

    return nc;
}

void operations(int operations){
    NC *nc_1;
    nc_1 = criar_numero_complexo();

    NC *nc_2;
    nc_2 = criar_numero_complexo();

    double parte_real;
    double parte_imaginaria;

    NC *nc_result;
    nc_result = cria();

    switch(operations){
        case 1:
            if(soma(nc_1, nc_2, nc_result) == 1){
                if(get_nro(nc_result, &parte_real, &parte_imaginaria) == 1){
                    printf("Parte real: %2.f\nParte imaginaria: %.2f\n", parte_real, parte_imaginaria);
                    printf("Numeros complexo somas: nc_soma = %.2f + %.2fi\n", parte_real, parte_imaginaria);
                }else{
                    printf("Nao foi possivel exibir o numero complexo!");
                };
            }
        break;
        case 2:
            if(sub(nc_1, nc_2, nc_result) == 1){
                if(get_nro(nc_result, &parte_real, &parte_imaginaria) == 1){
                    printf("Parte real: %2.f\nParte imaginaria: %.2f\n", parte_real, parte_imaginaria);
                    printf("Numeros complexo substraidos: nc_sub = %.2f + %.2fi\n", parte_real, parte_imaginaria);
                }else{
                    printf("Nao foi possivel exibir o numero complexo!");
                };
            }
        break;
        case 3:
            if(multi(nc_1, nc_2, nc_result) == 1){
                if(get_nro(nc_result, &parte_real, &parte_imaginaria) == 1){
                    printf("Parte real: %2.f\nParte imaginaria: %.2f\n", parte_real, parte_imaginaria);
                    printf("Numeros complexo multiplicados: nc_multi = %.2f + %.2fi\n", parte_real, parte_imaginaria);
                }else{
                    printf("Nao foi possivel exibir o numero complexo!");
                };
        }
        break;

    }
    apaga(&nc_1);
    apaga(&nc_2);
    apaga(&nc_result);
}

int main()
{
    int sair = 1;

    while(1){
        switch(menu()){
            case 1:
                criar_numero_complexo();
                break;
            case 2:
                operations(1);
                break;
            case 3:
                operations(2);
                break;
            case 4:
                operations(3);
                break;
            case 6:
                sair = 0;
                break;
            default:
                printf("Valor invalido!");
        }
        if(sair == 0){
            break;
        }

    }

    return 0;
}
