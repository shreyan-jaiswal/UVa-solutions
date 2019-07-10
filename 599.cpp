#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string buffer;
        int e = 0;
        bitset<26> bs;
        while(cin >> buffer, buffer[0] != '*'){
            bs[buffer[1] - 'A'] = 1;
            bs[buffer[3] - 'A'] = 1;
            e++;
        }
        cin >> buffer;
        int v = (buffer.size()+1)/2;
        int acorns = 0;
        for(int i = 0; i < v; i++){
            if (!bs[buffer[2*i]-'A']){
                acorns++;
            }
        }
        cout << "There are " << v-e-acorns << " tree(s) and " << acorns << " acorn(s)" << endl;
    }
}