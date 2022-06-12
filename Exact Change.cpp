#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[100005], coin[100005];
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--){
        int target, n;
        cin >> target;
        cin >> n;
        
        for(int i = 0; i < 100005; i++) dp[i] = 1e9 + 7;
        ll sum = 0;
        for(int i = 0; i < n; i++) {
        	cin >> coin[i];
        	if(sum < target) sum += coin[i];
        }
        dp[0] = 0;
        for(int i = 0; i < n; i++){
        	for(int j = sum; j >= coin[i]; j--){
        		dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        	}
        }
        while(dp[target] == 1e9 + 7) target++;
        cout << target << " " << dp[target] << endl;
    }
    
    return 0;
}
