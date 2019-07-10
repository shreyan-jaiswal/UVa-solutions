#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        bool is_s = true, is_q = true, is_pq = true;
        stack<int> s;
        priority_queue<int> pq;
        queue<int> q;
        while(n--){
            int r, x;
            cin >> r >> x;
            if(r == 1) {
                s.push(x); pq.push(x); q.push(x);
            }
            else {
                if (x != s.top()) is_s = false;
                if (x != q.front()) is_q = false;
                if (x != pq.top()) is_pq = false;
                s.pop(); q.pop(); pq.pop();
            }
        }
        if(is_s + is_q + is_pq == 0) cout << "impossible" << endl;
        else if(is_s + is_q + is_pq >= 2) cout << "not sure" << endl;
        else{
            if(is_s) cout << "stack" << endl;
            else if (is_q) cout << "queue" << endl;
            else cout << "priority queue" << endl;
        }
    }
}