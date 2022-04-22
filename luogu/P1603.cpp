#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    int n = 6;
    map<string, int> m;
    m["one"]=1;m["two"]=4;m["three"]=9;m["four"]=16;m["five"]=25;
    m["six"]=36;m["seven"]=49;m["eight"]=64;m["nine"]=81;m["ten"]=0;
    m["eleven"]=21;m["twelve"]=44;m["thirteen"]=69;m["fourteen"]=96;m["fifteen"]=25;
    m["sixteen"]=56;m["seventeen"]=89;m["eighteen"]=24;m["nineteen"]=61;m["twenty"]=0;
    m["a"]=1;m["both"]=4;m["another"]=1;m["first"]=1;m["second"]=4;m["third"]=9;

    priority_queue<int, vector<int>,  greater<int>> q;
    string code;
    for(int i = 0; i < n ; i++) {
        cin >> code;
        if(m.count(code) > 0) {
            q.push(m[code]);
        }
    }
    if(q.empty()) cout << 0;
    else {
        stringstream ss;
        while(q.top() == 0) q.pop();
        while(!q.empty()) {
            if(q.top() < 10) ss << 0;
            ss << q.top();
            q.pop();
        }
        string out = ss.str();
        int i = 0;
        while(out[i] == '0')i++;
        cout << out.substr(i, out.size()-i);
    }
    cout << endl;
    return 0;
}
