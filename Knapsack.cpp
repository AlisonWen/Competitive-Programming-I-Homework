#include <bits/stdc++.h>
#define val first
#define w second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
pii obj[2005]; // <val, w>
int dp[2005];
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int capacity, n;
    bool inside[2005][2005];
    while (cin >> capacity >> n){
        memset(dp, 0, sizeof(dp));
        memset(inside, 0, sizeof(inside));
        for(int i = 0; i < n; i++) cin >> obj[i].first >> obj[i].second;
        for(int i = 0; i < n; i++){
            for(int j = capacity; j >= obj[i].w ; j--){
               if(dp[j - obj[i].w] + obj[i].val > dp[j]){
                   dp[j] =  dp[j - obj[i].w] + obj[i].val;
                    inside[i][j] = true;
               }
            }
        }
        //cout << dp[capacity] << endl;
        int cnt = 0;
        vector <int> ans;
        for(int i = n - 1, j = capacity; i >= 0; i--){
            if(inside[i][j]){
                cnt++;
                ans.emplace_back(i);
                j -= obj[i].w;
            }
        }
        cout << cnt << "\n";
        for(auto i : ans) cout << i << " ";
        cout << "\n";
    }
    
    return 0;
}
