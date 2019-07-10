#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <iterator>
using namespace std;

typedef map<string, int> msi;

int main(){
    int n, total;
    string curr;
    msi m;

    scanf("%d\n\n", &n);
    while(n--){
        total = 0;
        m.clear();
        while(getline(cin, curr)){
            if(curr.size() == 0) break;
            ++m[curr]; ++total;
        }
        for(msi::iterator it = m.begin(); it!=m.end(); ++it){
            cout << it->first;
            printf(" %.4f\n", 100*double(it->second)/total);
        }
        if(n!=0) cout << endl;
    }

    return 0;
}