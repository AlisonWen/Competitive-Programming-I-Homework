#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
using ll = long long;
unordered_map <ll, ll> tbl;
ll sum[1000005], arr[1000005];
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        memset(sum, 0, sizeof(sum));
        tbl.clear();
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(i == 0) sum[i] = arr[i];
            else sum[i] = arr[i] + sum[i - 1];
            
        }
        ll ans = 0;
        tbl[0] = 1;
        for(int i = 0; i < n; i++){
            ans += tbl[sum[i] - 47];
            tbl[sum[i]]++;
        }
        cout << ans << "\n";
    }
    
    return 0;
}
