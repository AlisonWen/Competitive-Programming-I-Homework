#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        priority_queue <ll, vector<ll>, greater<ll> > pq;
        for(int i = 0; i < n; i++){
            ll tmp;
            cin >> tmp;
            pq.push(tmp);
        }
        ll ans = 0;
        while (pq.size() > 1){
            ll tmp = pq.top();
            pq.pop();
            tmp += pq.top();
            pq.pop();
            ans += tmp;
            pq.push(tmp);
        }
        cout << ans << '\n';
    }
    
    return 0;
}
