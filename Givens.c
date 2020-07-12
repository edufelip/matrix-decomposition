#include <stdio.h>
#include <math.h>

int main (void) {
    int dim, i, j, z, w, p, cont = 0;
    printf("INSERT THE MATRIX'S DIMENSION?\n");
    scanf("%d", &dim);
    double a[dim][dim], q[dim][dim], total[dim], qTrans[dim][dim], rDep[dim][dim], r[dim][dim], sup, soma, cos, sen;
    double g[dim][dim];

    printf("INSERT THE MATRIX\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            scanf("%lf", &a[i][j]);
        }
    }
    
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            r[i][j] = a[i][j];
        }
    }
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            if(i == j){
                qTrans[i][j] = 1;
            } else {
                qTrans[i][j] = 0;
            }
        }
    }

    for(i = 0; i < dim; i++){
        for(j = i+1; j < dim; j++){
            if(a[j][i] != 0) {
                for(w = 0; w < dim; w++){
                    for(z = 0; z < dim; z++){
                        if(w == z) {
                            g[w][z] = 1;
                        } else {
                            g[w][z] = 0;
                        }
                    }
                }
                cos = r[i][i]/sqrt(pow(r[i][i],2)+pow(r[j][i],2));
                sen = sqrt(1 - (cos*cos));
                if(r[j][i] < 0) sen = sen * -1;
                g[i][i] = cos;
                g[j][j] = cos;
                g[i][j] = sen;
                g[j][i] = sen * -1;
                for(w = 0; w < dim; w++){
                    for(z = 0; z < dim; z++){
                        sup = 0;
                        for(p = 0; p < dim; p++){
                            sup += g[w][p] * r[p][z];
                        }
                        rDep[w][z] = sup;
                    }
                }
                for(w = 0; w < dim; w++){
                    for(z = 0; z < dim; z++){
                        if(rDep[w][z] > pow(-10, -7) && rDep[w][z] < 0){
                            r[w][z] = rDep[w][z] * -1;
                        } else {
                            r[w][z] = rDep[w][z];
                        }
                    }
                }
                // Multiplicar a matriz g pela qTrans;
                for(w = 0; w < dim; w++){
                    for(z = 0; z < dim; z++){
                        sup = 0;
                        for(p = 0; p < dim; p++){
                            sup += g[w][p] * qTrans[p][z];
                        }
                        qTrans[w][z] = sup;
                    }
                }
            }
        }
    }
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            q[i][j] = qTrans[j][i];
        }
    }
    printf("MATRIX Q\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            printf("%lf ", q[i][j]);
        }
        printf("\n");
    }
    printf("MATRIX R\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            printf("%lf ", r[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}