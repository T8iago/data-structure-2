#include <stdio.h>
#include <stdlib.h>

/*
essa funcao preenche o vetor bolsa (como se as 
moedas fossem colocadas em uma bolsa de moedas)
e preenche cada soma com programacao dinamica,
indo decrescentemente de soma_total até o peso da 
moeda em cada iteracao dos for's
*/
void bolsa_dp(int N, int *W, int sup, int *bolsa) {
    for (int i = 0; i < N; i++) {
        for (int j = sup; j >= W[i]; j--) {
            if(bolsa[j - W[i]] == 1) {
                bolsa[j] = 1;
            }
        }
    }
}


int main() {
    int N;

    scanf("%d", &N);

    int *W = (int *)malloc(N *sizeof(int));
    if (W == NULL) {
        printf("Erro de alocação de memória 1 \n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &W[i]);
    }

    int soma_total = 0;
    for (int i = 0; i < N; i++) {
        soma_total += W[i];
    }

    int sup = soma_total / 2;

    int *bolsa = (int *)malloc((sup + 1) *sizeof(int));
    if (bolsa == NULL) {
        printf("Erro na alocação de memória 2\n");
        return 1;
    }

    bolsa[0] = 1;
    for (int i = 1; i < sup + 1; i++) {
        bolsa[i] = 0;
    }

    bolsa_dp(N, W, sup, bolsa);

    /*
    aqui eh feito uma busca reversa, apos realizar 
    o preenchimento do vetor bolsa, para encontrar 
    a maior soma de pesos encontrada dentro da bolsa,
    assim, conseguimos encontrar uma das bolsas em
    que as moedas foram colocadas
    */
    int maior_soma;
    for (maior_soma = sup; maior_soma >= 0; maior_soma--) {
        if (bolsa[maior_soma] == 1) {
            break;
        }
    }

    /*
    a equacao para encontrar a diferenca entre os 
    valores se da em subtrair a soma total encontrada
    somando todos os pesos (W) com duas vezes a maior
    soma, sabendo que a maior soma sempre será menor 
    ou igual a soma total dividido por dois  
    */
    int diferenca = soma_total - (2 * maior_soma);

    printf("%d\n", diferenca);

    return 0;
}