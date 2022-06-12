#include <bits/stdc++.h>
using namespace std;
vector <int> q;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        string s;
        cin >> s;
        bool undo = false;
        if(s == "undo") {
            cin >> s;
            undo = true;
            int cnt = strtol(s.c_str(), nullptr, 10);
            while (cnt--){
                q.pop_back();
            }
        }else q.emplace_back(strtol(s.c_str(), nullptr, 10));
    }
    int pos = 0;
    for(auto cur : q){
        cur %= n;
        pos += cur;
        pos %= n;
        while (pos < 0){
            pos += n;
        }
        
    }
    cout << pos << "\n";
    return 0;
}
