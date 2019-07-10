#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        priority_queue<int, vector<int>, greater<int> > pq;
        int cost = 0;
        while(n--){int x; cin >> x; pq.push(x); }
        while(pq.size() > 1){
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            cost += x+y;
            pq.push(x+y);
        }
        cout << cost << endl;
    }
}