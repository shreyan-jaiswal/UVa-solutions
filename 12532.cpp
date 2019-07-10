#include <iostream>
#include <vector>

using namespace std;

class BIT{
private:
    vector<int> ft;
    int n;
    int LS1(int i) {return (i&-i); }
public:
    BIT(int n){
        this->n = n;
        ft.assign(n+1, 0);
    }
    BIT(const vector<int> &A){
        this -> n = A.size() + 1;
        ft.assign(n+1, 0);
        for(int i = 0; i < n; i++) ft[i+1] = A[i];
        for(int i = 0; i < n; i++){
            int j = i + LS1(i);
            if (j <= n) ft[j]+=ft[i];
        }
    }
    void update(int i, int v){
        for(i++; i <= n; i += LS1(i)) ft[i] += v;
    }
    int rsq(int i){
        int total = 0;
        for(i++; i > 0; i -= LS1(i)) total += ft[i];
        return total;
    }
};

char query(int i, int j, BIT &z, BIT &m){
    int numZeros = z.rsq(j) - z.rsq(i-1);
    int numMinus = m.rsq(j) - m.rsq(i-1);
    if(numZeros > 0) return '0';
    if(numMinus % 2 == 0) return '+';
    return '-';
}

int main(){
    int n, k;
    while(cin >> n >> k){
        vector<int> A(n+5);
        vector<int> MINUS(n+5);
        vector<int> ZERO(n+5);
        A.assign(n+5, 0); MINUS.assign(n+5, 0); ZERO.assign(n+5, 0);
        for(int i = 1; i <= n; i++){
            cin >> A[i];
            if(A[i] < 0) MINUS[i] = 1;
            else if(A[i] == 0) ZERO[i] = 1;
        }
        BIT minus = BIT(MINUS);
        BIT zero = BIT(ZERO);
        while(k--){
            char type; int i,j;
            cin >> type >> i >> j;
            if(type == 'P') cout << query(i, j, zero, minus);
            else{
                if(A[i] == 0) zero.update(i, -1);
                if(A[i] < 0) minus.update(i, -1);
                A[i] = j;
                if(A[i] == 0) zero.update(i, 1);
                if(A[i] < 0) minus.update(i, 1);
            }
        }
        cout << endl;
    }
}