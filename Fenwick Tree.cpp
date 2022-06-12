#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll sum[5000005];
int n, t;

ll query(int idx){
    ll ans = 0;
    //if(idx == 0) return sum[0];
    while (idx){
        ans += sum[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

void Modify(ll idx, ll val){
    while(idx){
				sum[idx] += val;
				idx -= idx & (-idx);
		}
}

int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> t;
    while (t--){
        string type;
        ll a, b; 
        cin >> type ; 
        if(type == "?"){
            cin >> a;
            cout << query(a) << "\n";
        }else{
            cin >> a >> b; 
            Modify(a + 1, b);
        }
    }
    //for(int i = 0; i <= n; i++) cout << sum[i] << " "; cout << endl;
    return 0;
}
