#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        priority_queue<int> bw, gw;
        int b, gs, bs, temp;
        cin >> b >> gs >> bs;
        for(int i = 0; i < gs; i++) {cin >> temp; gw.push(temp); }
        for(int i = 0; i < bs; i++) {cin >> temp; bw.push(temp); }

        while(!gw.empty() && !bw.empty()){
            vector<int> gf, bf;
            int fights = min(b, (int) min(gw.size(), bw.size()));
            for(int i = 0; i < fights; i++){
                gf.push_back(gw.top()); gw.pop();
                bf.push_back(bw.top()); bw.pop();
            }
            for(int i = 0; i < fights; i++){
                if(gf[i] < bf[i]) bw.push(bf[i]-gf[i]);
                else if(gf[i] > bf[i]) gw.push(gf[i] - bf[i]);
            }
        }

        if(gw.empty()){
            if(bw.empty()) cout << "green and blue died" << endl;
            else {
                cout << "blue wins" << endl;
                while(!bw.empty()) {cout << bw.top() << endl; bw.pop(); }
            }
        }
        else {
            cout << "green wins" << endl;
            while(!gw.empty()) {cout << gw.top() << endl; gw.pop(); }
        }

        if(t!=0) cout << endl;
    }
}