#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int H, B;
int hotdog[105], buns[105];
ll dp1[10000005], dp2[10000005];
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> H;
    for(int i = 0; i <= 1100000; i++) dp1[i] = 1e9 + 7, dp2[i] = 1e9 + 7; 
    dp1[0] = 0, dp2[0] = 0;
    for(int i = 1; i <= H; i++) {
        cin >> hotdog[i];
        for(int j = 1100000; j >= hotdog[i]; j--) dp1[j] = min(dp1[j - hotdog[i]] + 1, dp1[j]);
    }
    cin >> B;
    for(int i = 1; i <= B; i++) {
        cin >> buns[i];
        for(int j = 1100000; j >= buns[i]; j--) dp2[j] = min(dp2[j - buns[i]] + 1, dp2[j]);
    }
    ll ans = 1e7;
    for(int i = 1; i <= 1100000; i++) ans = min(ans, dp1[i] + dp2[i]);
    //for(int i = 1 ; i <= H; i++) cout << dp1[i] << " " ; cout << endl;
    if(ans == 1e7) cout << "impossible\n";
    else cout << ans << "\n";
    return 0;
}
