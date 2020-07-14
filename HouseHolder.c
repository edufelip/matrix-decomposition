#include <stdio.h>
#include <math.h>

int main (void) {
    int dim, i, j, z, w, k, p;
    printf("WHAT'S THE DIMENSION OF THE MATRIX?\n");
    scanf("%d", &dim);
    double a[dim][dim], g[dim][dim], q[dim][dim], qTrans[dim][dim], r[dim][dim], u[dim], id[dim][dim], num[dim][dim], rDep[dim][dim], soma, sup, den;
    for(i = 0; i < dim; i++){
        for(k = 0; k < dim; k++){
            if(i == k) {
                qTrans[i][k] = 1;
            } else {
                qTrans[i][k] = 0;
            }
        }
    }
    printf("INSERT THE MATRIX\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            scanf("%lf", &a[i][j]);
        }
    }
    for(i = 0; i < dim-1; i++){
        soma = 0;
        den = 0;
        for(w = 0; w < dim; w++){
            u[w] = 0;
            for(k = 0; k < dim; k++){
                if(k == w) {
                    id[w][k] = 1;
                } else {
                    id[w][k] = 0;
                }
                num[w][k] = 0;
            }
        }
        for(w = i; w < dim; w++){
            u[w] = a[w][i];
            soma += pow(u[w], 2);
        }
        soma = sqrt(soma);
        u[i] -= soma;
        for(w = i; w < dim; w++){
            den += pow(u[w], 2);
        }
        for(w = i; w < dim; w++){
            for(k = i; k < dim; k++){
                num[w][k] = 2 * u[w] * u[k];
                num[w][k] /= den;
            }
        }
        for(w = i; w < dim; w++){
            for(k = i; k < dim; k++){
                id[w][k] -= num[w][k];
            }
        }
        for(w = 0; w < dim; w++){
            for(z = 0; z < dim; z++){
                sup = 0;
                for(p = 0; p < dim; p++){
                    sup += id[w][p] * qTrans[p][z];
                }
                rDep[w][z] = sup;
            }
        }
        for(w = 0; w < dim; w++){
            for(z = 0; z < dim; z++){
                if(rDep[w][z] > pow(-10, -7) && rDep[w][z] < 0){
                    qTrans[w][z] = rDep[w][z] * -1;
                } else {
                    qTrans[w][z] = rDep[w][z];
                }
            }
        }
        for(w = 0; w < dim; w++){
            for(z = 0; z < dim; z++){
                sup = 0;
                for(k = 0; k < dim; k++){
                    sup += id[w][k] * a[k][z];
                }
                if(sup < 0 && sup > pow(-10, -7)) sup *= -1;
                r[w][z] = sup;
            }
        }
        for(w = 0; w < dim; w++){
            for(k = 0; k < dim; k++){
                a[w][k] = r[w][k];
            }
        }
    }
    for(i = 0; i < dim; i++){
        for(k = 0; k < dim; k++){
            q[i][k] = qTrans[k][i];
        }
    }
    printf("MATRIX Q\n");
    for(i = 0; i < dim; i++){
        for(k = 0; k < dim; k++){
            printf("%lf  ", q[i][k]);
        }
        printf("\n");
    }
    printf("MATRIX R\n");
    for(i = 0; i < dim; i++){
        for(k = 0; k < dim; k++){
            printf("%lf  ", r[i][k]);
        }
        printf("\n");
    }
    return 0;
}