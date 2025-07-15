#include<stdio.h>

int main()
{
    int funcionarios, i, l, tempo, n_maior_func, n_menor_func, n_maior_temp, depto_maior, maior_tempo = 0, depto_menor, depto;
    float salario, total = 0, maior = 0, menor = 2000;

        for(i = 0; i < 3; i++)
        {
            printf("\n -> Digite a quantidade de funcionarios no setor %d: ", i + 1);
            scanf("%d", &funcionarios);
            total = 0;

                for(l = 0; l < funcionarios; l++)
                {
                    printf("\n      |Digite o salario do funcionario numero %d: ", l + 1);
                    scanf("%f", &salario);

                    printf("\n      |Digite quanto tempo o funcionario numero %d esta na empresa(em meses): ", l + 1);
                    scanf("%d", &tempo);

                            if(salario > maior)
                            {
                                maior = salario;
                                depto_maior = i + 1;
                                n_maior_func = l + 1;
                            }
                            if(salario < menor)
                            {
                                menor = salario;
                                depto_menor = i + 1;
                                n_menor_func = l + 1;
                            }
                            if(tempo > maior_tempo)
                            {
                                maior_tempo = tempo;
                                n_maior_temp = l + 1;
                                depto = i + 1;
                            }

                            total += salario;
                }
                    printf("\n - O total de salario no departamento %d foi de R$ %.2f\n", i + 1, total);
        }

        printf("\n\n|O funcionario com maior tempo de empresa foi o numero %d do departamento %d", n_maior_temp, depto);
        printf("\n|O maior salario foi de: R$ %.2f do departamento %d", maior, depto_maior);
        printf("\n|O menor salario foi de: R$ %.2f do departamento %d\n\n", menor, depto_menor);

}
