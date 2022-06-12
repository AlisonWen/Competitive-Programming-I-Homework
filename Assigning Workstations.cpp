#include <bits/stdc++.h>
#define start first
#define leave second
using namespace std;
using pii = pair<long long, long long>;
vector <pii> users; // <arrive, end>
multiset <int> computer;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    users.resize(n);
    for(int i = 0; i < n; i++){
        int stay;
        cin >> users[i].start >> stay;
        users[i].leave = users[i].start + stay;
    }
    sort(users.begin(), users.end());
    int cnt = 0;
    for(auto cur : users){
        auto pos = computer.lower_bound(cur.first - m);
        if(pos != computer.end() && *pos <= cur.start){
            computer.erase(pos);
            cnt++;
        }
        computer.emplace(cur.leave);
    }
    cout << cnt << "\n";
    return 0;
}
