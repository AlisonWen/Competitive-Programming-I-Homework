#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector <pii> events;

bool cmp(pii A, pii B){
    if(B.second == A.second) return A.first < B.first;
    return A.second < B.second;
}

int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    events.resize(n);
    for(int i = 0; i < n; i++) cin >> events[i].first >> events[i].second;
    sort(events.begin(), events.end(), cmp);

    multiset <int> s;
    int ans = 0;

    for(int i = 0; i < n; i++){
        auto it = s.lower_bound(events[i].first);
        if(it == s.end()){
            if(s.size() < k){
                ans++;
                s.emplace(events[i].second);
            }
        }else{
            ans++;
            it--;
            s.erase(it);
            s.emplace(events[i].second);
        }
    }
    cout << ans << "\n";
    return 0;
}
