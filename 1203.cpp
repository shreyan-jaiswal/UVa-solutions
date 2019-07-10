#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

void printpq(priority_queue<ii, vector<ii>, greater<ii> > pq){
    while(!pq.empty()){ cout << pq.top().first << " " << pq.top().second << "; "; pq.pop(); }
    cout << endl;
}

int main(){
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    string s;
    map<int, int> m;
    while(cin >> s, s!= "#"){
        int id, period;
        cin >> id >> period;
        pair<int, int> temp; temp.first = 0; temp.second = id;
        m[id] = period;
        pq.push(make_pair(period, id));
    }
    int n;
    cin >> n;
    while(n--){
        ii temp = pq.top(); pq.pop();
        cout << temp.second << endl;
        pq.push(make_pair(temp.first + m[temp.second], temp.second));
    }
}

