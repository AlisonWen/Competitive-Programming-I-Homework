#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector <int> graph[200005];
int n;
int depth[200005], pre[200005], Size[200005], used[200005];
int query[25];
int ancestor[200005][20];
int root;

int DFS(int cur, int cur_depth){
    depth[cur] = cur_depth + 1;
    if(graph[cur].empty()){
        Size[cur] = 1;
        return 1;
    }
    int sum = 1;
    for(auto i : graph[cur]){
        sum += DFS(i, cur_depth + 1);
    }
    Size[cur] = sum;
    return Size[cur];
}

int LCA(int a, int b){
    if(depth[b] < depth[a]) swap(a, b);
    if(depth[a] != depth[b]){
        int delta = depth[b] - depth[a];
        for(int i = 0; i < 20; i++){
            if(delta & 1) b = ancestor[b][i];
            delta >>= 1;
        }
    }
    if(a == b) return a;
    for(int i = 19; i >= 0; i--){
        if(ancestor[a][i] != ancestor[b][i]){
            a = ancestor[a][i];
            b = ancestor[b][i];
        }
    }
    return ancestor[a][0];
}

int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        graph[tmp].emplace_back(i);
        ancestor[i][0] = tmp;
    }
    DFS(0, 0);
    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= n; j++){
            ancestor[j][i] = ancestor[ancestor[j][i - 1]][i - 1];
        }
    }
    //for(int i = 1; i <= n; i++) cout << Size[i] << " "; cout << endl;
    int q;
    cin >> q;
    while (q--){
        int m;
        cin >> m;
        ll ans = 0;
        for(int i = 0; i < m; i++) cin >> query[i];
        bool flag = 0;
        if(m == 1) cout << Size[query[0]] << "\n";
        else {
            for(int i = 0; i < m; i++){
                flag = true;
                for(int j = 0; j < m; j++){
                    if(i == j) continue;
                    if(LCA(query[i], query[j]) == query[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag) ans += Size[query[i]];
            }
            cout << ans << "\n";
        }
    }
    
    return 0;
}
