#include<stdio.h>

int main()
{
    float gasto_total, valor_desconto = 0, valor_a_pagar;

        printf("Quanto gastou na compra: ");
        scanf("%f", &gasto_total);

            if(gasto_total > 300)
            {
                valor_desconto = (gasto_total - 300) * 0.10;
                valor_a_pagar = gasto_total - valor_desconto;

                printf("\nValor da compra: R$ %.2f", gasto_total);
                printf("\nValor do desconto: R$ %.2f", valor_desconto);
                printf("\nValor a pagar: R$ %.2f\n\n", valor_a_pagar);
            }
            else
            {
                valor_a_pagar = gasto_total;

                printf("\nValor da compra: R$ %.2f", gasto_total);
                printf("\nValor do desconto: R$ %.2f", valor_desconto);
                printf("\nValor a pagar: R$ %.2f\n\n", valor_a_pagar);
            }
}
