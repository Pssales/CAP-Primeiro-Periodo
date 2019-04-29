#include <iostream>

int main(int argc, char *argv[])
{

    return 0;
}

void eliminacao(a, b,n):
    for (k=1; k<n-1; k++){
        for (i=k+1; i<n; i++){
            m = a[i][k]/a[k][k];
            a[i][k] = 0
            for (j=k+1; <n; j++){
                a[i][j] = a[i][j] - (m * a[k][j]);
            }
            b[i] = b[i] - (m * b[k])
        }
    }
}

void resolcao(a, b, n){
    int res[n];

    res[n-1] = b[b]/a[n-1][n-1];
    for(i=n-2; i>=0; i--){
        soma = 0;
        for(j=i+1; i<n; i--){
            soma = soma+a[i][j]*res[j];
        }
        res[i]= (b[i] - soma)/a[i][i];    
    }
    print(res);
}