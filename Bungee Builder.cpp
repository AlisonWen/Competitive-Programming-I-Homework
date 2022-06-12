#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
stack <pii> stk;
int arr[1000005];
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++){
        int cur_min = arr[i];
        while(!stk.empty()){
            pii cur = stk.top();
            stk.pop();
            cur_min = min(cur.second, cur_min);
            if(cur.first > arr[i]){
                stk.emplace(cur.first, cur_min);
                ans = max(ans, arr[i] - cur_min);
                break;
            }
            ans = max(ans, cur.first - cur_min);
        }
        stk.emplace(arr[i], arr[i]);
    }
    cout << ans << '\n';
    return 0;
}
