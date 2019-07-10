#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class segment_tree{
private:
    vector<int> st, A;
    int size;
    int left(int p) {return p << 1; }
    int right(int p) {return (p << 1) + 1; }
    void build(int p, int L, int R){
        if(R - L <= 0) {throw "Build failed"; }
        else if (R - L == 1) {st[p] = L; return; }
        int mid = L + (R-L)/2;
        build(left(p), L, mid);
        build(right(p), mid, R);
        int p1 = st[left(p)], p2 = st[right(p)];
        st[p] = A[p1] >= A[p2] ? p1 : p2;
    }
    int rmq_helper(int p, int L, int R, int i, int j){
        if(R <= i || j <= L) {return -1; }
        if(i <= L && R <= j) {return st[p]; }
        int mid = L + (R-L)/2;
        int p1 = rmq_helper(left(p), L, mid, i, j);
        int p2 = rmq_helper(right(p), mid, R, i, j);
        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return A[p1] >= A[p2] ? p1 : p2;
    }
    void update_helper(int p, int L, int R, int i){
        if(R <= i || i < L) {return; }
        int mid = L + (R-L)/2;
        if(i < mid){update_helper(left(p), L, mid, i); }
        else {update_helper(mid, right(p), R, i); }
        int p1 = st[left(p)], p2 = st[right(p2)]; 
        st[p] = A[p1] >= A[p2] ? p1 : p2;
    }
public:
    segment_tree(const vector<int> &A){
        this->A = A;
        st.assign(4 * A.size(), 0);
        build(1, 0, A.size());
    }
    int rmq(int i, int j) {return rmq_helper(1, 0, A.size(), i, j+1); }
    void update(int i, int x) {A[i] = x; update_helper(1, 0, A.size(), i); }
};

void print(const vector<int> &v){
    for(int i = 0; i< v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

int main(){
    int n;
    while(cin >> n, n){
        int q;
        cin >> q;
        vector<int> A(n+1);
        unordered_map<int, int> freqtable;
        int first = 1;
        for(int i = 1; i <= n; i++) {
            cin >> A[i];
            freqtable[A[i]]++;
        }
        vector<int> freq(n+3);
        vector<int> firstt(n+1);
        vector<int> lastt(n+1);
        for(int i = 1; i <= n; i++) {freq[i] = freqtable[A[i]]; }
        int f = 1;
        firstt[1] = 1;
        for(int i = 2; i <= n; i++){
            if(A[i] != A[i-1]) f = i;
            firstt[i] = f;
        }
        int l = n; lastt[n] = n;
        for(int i = n-1; i >= 1; i--){
            if(A[i] != A[i+1]) l = i;
            lastt[i] = l;
        }
        segment_tree st = segment_tree(freq);
        while(q--){
            int qb, qe;
            cin >> qb >> qe;
            int freqb = min(qe, lastt[qb]) - qb + 1;
            int freqe = qe - max(qb, firstt[qe]) + 1;
            int rb = lastt[qb] + 1;
            int re = firstt[qe] - 1;
            int freqm = rb <= re ? freq[st.rmq(rb, re)] : 0;
            if(qb == 1 && qe == 8){
            /*cout << "query: " << qb << " " << qe << endl;
            cout << "rquery: " << rb << " " << re << " " << st.rmq(rb, re) << endl;
            cout << "first: " << firstt[qe] << " last: " << lastt[qb] << endl;
            cout << "b: " << freqb << " m: " << freqm << " e: " << freqe << endl;*/
            }
            cout << max(max(freqb, freqm), freqe) << endl;
        }
    }
}