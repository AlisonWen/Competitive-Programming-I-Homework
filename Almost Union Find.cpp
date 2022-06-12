#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll p[200005], _size[200005], sum[200005];

ll find(ll x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}

bool same(ll x, ll y){
    if(find(x) == find(y)) return true;
    return false;
}

void Union(ll x, ll y){
    if(same(x, y)) return;
    x = find(x), y = find(y);
    _size[y] += _size[x];
    sum[y] += sum[x];
    p[x] = y;
}

void Move(ll x, ll y){
    ll x_root = find(x), y_root = find(y);
    if(x_root == y_root) return;
    _size[x_root]--;
    _size[y_root]++;
    sum[x_root] -= x;
    sum[y_root] += x;
    p[x] = y_root;
    return;
}

int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, t;
    while(cin >> n >> t){
        for (int i = 1, j = n + 1; i <= n; i++, j++) {
            p[i] = j;
            p[j] = j;
            _size[j] = 1;
            sum[j] = i;
        }
        while(t--){
            int op, a, b; 
            cin >> op;
            if(op == 1){
                cin >> a >> b; 
                Union(a, b);
            }else if(op == 2){
                cin >> a >> b; 
                Move(a, b);
            }else{
                cin >> a;
                cout << _size[find(a)] << " " << sum[find(a)] << '\n';
            }
            
        }
    }
    
    return 0;
}
