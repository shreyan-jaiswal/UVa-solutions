#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int n, m;
char type;
char B[500][500];

bool allOnes(int i1, int i2, int j1, int j2){
    for(int i = i1; i <= i2; i++)
        for(int j = j2; j <= j2; j++)
            if(B[i][j] != '1') return false;
    return true;
}

bool allZeros(int i1, int i2, int j1, int j2){
    for(int i = i1; i <= i2; i++)
        for(int j = j1; j <= j2; j++)
            if(B[i][j] != '0') return false;
    return true;
}

int BtoD(char* ss, int i1, int i2, int j1, int j2){
    if(allZeros(i1, i2, j1, j2)){
        *ss = '0';
        return 1;
    }
    if(allOnes(i1, i2, j1, j2)){
        *ss = '1';
        return 1;
    }
    int ret = 1;
    *ss = 'D';
    if(i2==i1){
        ret += BtoD(ss+ret, i1, i2, j1, (j1+j2)/2);
        ret += BtoD(ss+ret, i1, i2, (j1+j2)/2+1, j2);
    }
    else if(j2==j1){
        ret += BtoD(ss+ret, i1, (i1+i2)/2, j1, j2);
        ret += BtoD(ss+ret, (i1+i2)/2+1, i2, j1, j2);
    }
    else {
        ret += BtoD(ss+ret, i1, (i1+i2)/2, j1, (j1+j2)/2);
        ret += BtoD(ss+ret, i1, (i1+i2)/2, (j1+j2)/2+1, j2);
        ret += BtoD(ss+ret, (i1+i2)/2+1, i2, j1, (j1+j2)/2);
        ret += BtoD(ss+ret, (i1+i2)/2+1, i2, (j1+j2)/2+1, j2);
    }
    return ret;
}

int DtoB(char* ss, int i1, int i2, int j1, int j2){
    int ret = 1;
    if(*ss == 'D'){
        if(i2==i1){
            ret += DtoB(ss+ret, i1, i2, j1, (j1+j2)/2);
            ret += DtoB(ss+ret, i1, i2, (j1+j2)/2+1, j2);
        }
        else if(j2==j1){
            ret += DtoB(ss+ret, i1, (i1+i2)/2, j1, j2);
            ret += DtoB(ss+ret, (i1+i2)/2+1, i2, j1, j2);
        }
        else {
            ret += DtoB(ss+ret, i1, (i1+i2)/2, j1, (j1+j2)/2);
            ret += DtoB(ss+ret, i1, (i1+i2)/2, (j1+j2)/2+1, j2);
            ret += DtoB(ss+ret, (i1+i2)/2+1, i2, j1, (j1+j2)/2);
            ret += DtoB(ss+ret, (i1+i2)/2+1, i2, (j1+j2)/2+1, j2);
        }
    }
    else {
        for(int i = i1; i <= i2; i++){
            for(int j = j1; j <= j2; j++){
                B[i][j] = *ss;
            }
        }
    }
    return ret;
}

int main(){
    while(cin >> type, type != '#'){
        cin >> n >> m;
        char s[40000];
        cin.getline(s, 5);
        cin.getline(s, 40000);
        if(type == 'B'){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    B[i][j] = s[m*i+j];
                }
            }

            char ss[40000];
            int size = BtoD(ss, 0, n-1, 0, m-1);
            printf("D %d %d\n", n, m);
            for(int i = 0; i < size; i++){
                printf("%c", ss[i]);
            }
            printf("\n");
        }
        else {
            DtoB(s, 0, n-1, 0, m-1);
            printf("B %d %d\n", n, m);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    printf("%c", B[i][j]);
                }
            }
            printf("\n");
        }
    }

}