#include <stdio.h>

int potencia_dc(int n, int k, int mod) {
    int resultado = 1; // o resultado começa como 1 até chegar no resultado final

    while (k > 0) {
        if (k % 2 == 0) { // caso o exponencial seja par, se multiplica n por n
            n = (n * n) % mod;
            k = k / 2;  // diminui k pela metade para o proximo caso
        } else { // caso o exponencial seja impar, ele multiplica o resultado atual por n
            resultado = (resultado * n) % mod;
            k--; // transforma k em um numero par 
        }
    }

    return resultado;
}

int main() {
    int n, k, mod = 1000;

    scanf("%d %d", &n, &k);
    
    int resultado = potencia_dc(n, k, mod);

    printf("%d", resultado);
    return 0;
}