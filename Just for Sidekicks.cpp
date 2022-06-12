#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll arr[200005], value[10];
ll sum[10][200005]; // sum[type][有幾個為 i type]
int n, q;

int lowbit(int x){
    return x & (-x);
}

void Modify(int pos, int type, int op){
    while(pos <= n){
        sum[type][pos] += op;
        pos += lowbit(pos);
    }
}

ll query(int pos, int type){
    ll ans = 0;
    while(pos){
        ans += sum[type][pos];
        pos -= lowbit(pos);
    }
    return ans;
}

int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 1; i <= 6; i++) cin >> value[i];
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++) {
        arr[i] = s[i - 1] - '0';
        Modify(i, arr[i], 1);
    }
    while (q--){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            Modify(x, arr[x], -1);
            Modify(x, y, 1);
            arr[x] = y;
        }else if(op == 2){
            value[x] = y;
        }else{
            ll ans = 0;
            for(int i = 1; i <= 6; i++){
                ans += (query(y, i) - query(x - 1, i)) * value[i];
            }
            cout << ans << "\n";
        }
    }
    
    return 0;
}
