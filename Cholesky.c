#include <stdio.h>
#include <math.h>

int main (void) {
    int dim, i, j, k, w, maiorInd, worstScenario = 0;
    printf("INSERT THE MATRIX'S DIMENSION?\n");
    scanf("%d", &dim);
    double a[dim][dim], c;
    double maior, sup, comp;
    double soma;
    //
    double l[dim][dim];
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            l[i][j] = 0;
        }
    }
    //
    printf("INSERT THE MATRIX\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            scanf("%lf", &a[i][j]);
        }
    }
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            soma = 0;
            if(i == 0){
                if(i == j) {
                    l[i][j] = sqrt(a[i][j]);
                } else {
                    l[i][j] = a[i][j]/l[0][0];
                }                
            } else {
                if(i == j){
                    for(k = 0; k < i; k++){
                        soma += l[k][i] * l[k][i];
                    }
                    l[i][i] = a[i][i] - soma;
                    l[i][i] = sqrt(l[i][i]);
                }
                if (j > i){
                    for(k = 0; k < i; k++){
                        soma += l[k][i] * l[k][j];
                    }
                    l[i][j] = a[i][j] - soma;
                    l[i][j] = l[i][j] / l[i][i];
                }
            }
        }
    }
    printf("\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            a[i][j] = l[j][i];
        }
    }
    printf("MATRIX L\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("MATRIX L TRANSPOSED\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            printf("%lf ", l[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}