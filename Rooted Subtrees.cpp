#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
vector <int> graph[200005];
int n, q;
ll depth[200005];
int ancestor[200005][20];

void BFS(){
    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    queue <int> q;
    q.emplace(1);
    while (!q.empty()){
        int i = q.front();
        q.pop();
        for(auto j : graph[i]){
            if(depth[j] == -1){
                depth[j] = depth[i] + 1;
                ancestor[j][0] = i;
                q.emplace(j);
            }
        }
    }
    //for(int i = 1; i <= n; i++) cout << depth[i] << " "; cout << endl;
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
    //int n, q;
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    BFS();
    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= n; j++){
            ancestor[j][i] = ancestor[ancestor[j][i - 1]][i - 1];
        }
    }
    while (q--){
        int u, v;
        cin >> u >> v;
        ll l = depth[u] + depth[v] - 2*depth[LCA(u, v)] + 1;
        cout << l * (l + 1) / 2 + n - l << "\n";
    }
    
    return 0;
}
