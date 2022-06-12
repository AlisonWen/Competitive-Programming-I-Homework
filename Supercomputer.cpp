#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll sum[1000005], arr[1000005];
int n, q;

int lowbit(int x){
    return x & (-x);
}

void Modify(int pos, int op){
    while(pos <= n){
        sum[pos] += op;
        pos += lowbit(pos);
    }
}

ll query(int pos){
    ll ans = 0;
    while (pos){
        ans += sum[pos];
        pos -= lowbit(pos);
    }
    return ans;
}

int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> q;
    while (q--){
        string op;
        int x, y;
        cin >> op >> x;
        if(op == "F"){
            if(arr[x]) Modify(x, -1);
            else Modify(x, 1);
            arr[x] = ~arr[x];
        }else{
            cin >> y;
            cout << query(y) - query(x - 1) << endl;
        }
    }
    
    return 0;
}
