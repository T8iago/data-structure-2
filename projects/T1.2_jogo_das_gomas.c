#include <stdio.h>
#include <stdlib.h>

/*
Decidi usar o Merge Sort para a atividade pois
tentei utilizar o Bubble Sort (O(n^2)) e o
Insertion Sort (O(n)), portanto, ambos nao
alcancavam a rapidez necessaria para todos os
casos teste. Logo, imaginei que uma ordenacao
O(n log n) fosse necessaria.
*/
long long merge(int *P, int *temp, int esq, int meio, int dir) {
    int i = esq, j = meio, k = esq; //onde i = esq por causa do subarray e k = esq para o preenchimento do array temp
    long long trocas = 0;

    while (i <= meio - 1 && j <= dir) {
        if (P[i] <= P[j]) {
            /*
            Se o elemento da esquerda estiver na 
            ordem, copia direto.
            */
            temp[k++] = P[i++];
        } else {
            /*
            Portanto, se o elemento da direita eh menor
            (ou seja, se o seu vizinho nao esta ordenado),
            haverao trocas.
            */
            temp[k++] = P[j++];
            trocas += (meio - i);
        }
    }

    /* 
    Aqui é pra fazer as trocas entre os elementos.
    */
    while (i <= meio - 1) {
        temp[k++] = P[i++]; 
    }

    while (j <= dir) {
        temp[k++] = P[j++];
    }

    for (i = esq; i <= dir; i++) {
        P[i] = temp[i];
    }

    return trocas;
}

long long merge_sort(int *P, int *temp, int esq, int dir) {
    long long trocas = 0;
    if (dir > esq) {
        int meio = (dir + esq) / 2;

        // Ordena e conta as inversoes na metade esquerda.
        trocas += merge_sort(P, temp, esq, meio);
        // Ordena e conta as inversoes na metade direita.
        trocas += merge_sort(P, temp, meio + 1, dir);
        // Junta ambas metades, contando as inversoes entre elas.
        trocas += merge(P, temp, esq, meio + 1, dir);
    }

    return trocas;
}

long long gomas(int N, int *P) {
    int *temp = (int *)malloc(N *sizeof(int));
    long long trocas = merge_sort(P, temp, 0, N-1);
    free(temp);

    return trocas;
}

int main() {
    int N;

    while (1) {
        scanf("%d",&N);

        if (N == 0) {
            break;
        }

        int *P = (int *)malloc(N *sizeof(int));
        if (P == NULL) {
            printf("Erro de alocação de memória \n");
            return 1;
        }

        for (int i = 0; i < N; i++) {
            scanf("%d", &P[i]);
        }

        long long trocas = gomas(N, P);

        if(trocas % 2 == 1) {
            printf("Fino\n");
        } else {
            printf("Jaques\n");
        }

        free(P);
    }

    
    return 0;
}