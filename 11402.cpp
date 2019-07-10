#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N 1024005
bitset<N> pirates;
vector<int> st;
vector<char> lazy;

int left(int p){return p << 1;}
int right(int p){return (p << 1) + 1;}

void build(int p = 1, int L = 0, int R = N-1){
    if(L == R){st[p] = pirates[L]; return; }
    int mid = (L+R)/2;
    build(left(p), L, mid);
    build(right(p), mid+1, R);
    st[p] = st[left(p)] + st[right(p)];
}

char invert(char u){
    if(u == 'F') return 'E';
    if(u == 'E') return 'F';
    if(u == 'I') return 0;
    return 'I';
}

void lazy_update(int p, int L, int R){
    if(lazy[p] =='F') st[p] = (R - L + 1);
    else if(lazy[p] == 'E') st[p] = 0;
    else if(lazy[p] == 'I') st[p] = (R - L + 1) - st[p];
    if(L != R){
        if(lazy[p] == 'I'){
            lazy[left(p)] = invert(lazy[left(p)]);
            lazy[right(p)] = invert(lazy[right(p)]);
        }
        else if(lazy[p] == 'F' || lazy[p] == 'E'){
            lazy[left(p)] = lazy[p];
            lazy[right(p)] = lazy[p];
        }
    }
    lazy[p] = 0;
}

int rsq(int i, int j, int p = 1, int L =0 , int R = N-1){
    if(j < L || R < i) return 0;
    if(lazy[p] != 0) lazy_update(p, L, R);
    if(i <= L && R <= j) return st[p];
    int mid = (L+R)/2;
    return rsq(i, j, left(p), L, mid) + rsq(i, j, right(p), mid+1, R);
}

void update(int i, int j, char u, int p = 1, int L = 0, int R = N-1){
    if(lazy[p] != 0) lazy_update(p, L, R);
    if(j < L || R < i) return;
    if(i <= L && R <= j){
        lazy[p] = u;
        lazy_update(p, L, R);
        return;
    }
    int mid = (L+R)/2;
    update(i, j, u, left(p), L, mid);
    update(i, j, u, right(p), mid+1, R);
    st[p] = st[left(p)] + st[right(p)];
}

int main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    
    for(int tt = 1; tt <= t; tt++){
        pirates.reset();
        st.assign(4*N, 0);
        lazy.assign(4*N, 0);
        int m; cin >> m;
        int n = 0;
        while(m--){
            string p; int r;
            cin >> r >> p;
            while(r--){
                for(char c : p){
                    if (c == '1') pirates.set(n);
                    n++;
                }
            }
        }
        build();
        cout << "Case " << tt << ":\n";
        int q; cin >> q; int qq = 0;
        while(q--){
            char type; int i, j;
            cin >> type >> i >> j;
            if(type == 'S'){
                cout << "Q" << ++qq << ": " << rsq(i,j) << "\n";
            }
            else{
                if(type == 'F') update(i, j, 'F');
                else if(type == 'E') update(i, j, 'E');
                else update(i, j, 'I');
            }
        }
    }
}