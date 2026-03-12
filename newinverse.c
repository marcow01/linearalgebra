#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// →

void show(float *p, int N){

    printf("\n");

    for(int i = 0; i < N * N; i++){

        //printf("→ %p → %.2f", p + i, *(p + i));
        printf("[%.2f]", *(p + i));

        if((i + 1) % N == 0){

            printf("\n");

        }
    }
}

void receive(float *p, int N, bool *ishomogeneouspointer){

    printf("\n");

    for(int i = 0; i < N * N; i++){
        printf("→ %p \n", p + i);
        scanf("%f", &*(p + i));

        if(*(p + i) != 0){

            *ishomogeneouspointer = false;

        }
    }


}

int verifyhomogeneity(bool *ishomogeneouspointer){

    if (*ishomogeneouspointer){
        printf("\nsistema indeterminado, infinitas soluções! \n");
        return 0;
    }
}

int pivot(float *p, int column, int N){

    printf("pivô → [%.2f]", *(p + (column * N)));
    int validcolumn = -1;

    if(*(p + (column * N)) == 0){
        printf(" → pivô inválido!");

        //quando o pivô é inválido, deve ir buscar uma linha com pivô válido;

        for(int i = column + 1; i < N; i++){
            
            if(p[i * N + column] != 0){
                printf(" → linha → %d válida", i);
                validcolumn = i;
                break;
            }
        }

        if(validcolumn != -1){

            printf(" → a coluna válida é → %d", validcolumn);
            for(int i = 0; i < N; i++){
                printf(" [%.2f]", p[validcolumn * N + i]);
            }
        }

        printf("\n nenhuma linha válida!");
        return 0;
    }

}

int main(void){

    int N;
    bool ishomogeneous = true;
    bool *ishomogeneouspointer = &ishomogeneous;

    printf("[N]: \n");
    scanf("%d", &N);

    float A[N][N];
    float *p = &A[0][0];
    receive(p, N, ishomogeneouspointer);
    show(p, N);
    // printf("[A] → %b \n", ishomogeneous);
    verifyhomogeneity(ishomogeneouspointer);

    for(int i = 0; i < N; i++){
        pivot(p, i, N);
        printf("\n");
    }
}