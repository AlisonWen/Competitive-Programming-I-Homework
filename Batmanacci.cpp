#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector <ll> Fib;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    Fib.resize(n + 2);
    Fib[1] = 1;
    Fib[2] = 1;
    for(int i = 3; i <= n + 1; i ++){
        Fib[i] = Fib[i - 1] + Fib[i - 2];
        if(Fib[i] > (ll)1e18) Fib[i] = 1e18 + 1;
    }
    while (n > 2){
        if(k > Fib[n - 2]){
            k -= Fib[n - 2];
            n--;
        }else n -= 2;
    }
    if(n == 1) cout << "N\n";
    else cout << "A\n";
    return 0;
}
