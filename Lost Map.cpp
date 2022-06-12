#include <iostream>
#include <algorithm>
#include <vector>
#define A second.first
#define B second.second
using namespace std;
using pii = pair<int, int>;
int graph[3000][3000];
vector <pair<int, pii>> edges;
vector <pii> ans;
int p[3000];
int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}
void Union(int x, int y){
    p[find(x)] = find(y);
}
bool same(int x, int y){
    if(find(x) == find(y)) return true;
    return false;
}
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> graph[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            edges.emplace_back(pair<int, pii>{graph[i][j], {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    for(int i = 0; i <= n; i++) p[i] = i;
    for(auto e : edges){
        if(!same(e.A, e.B)){
            ans.emplace_back(min(e.A, e.B), max(e.A, e.B));
            Union(e.A, e.B);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto e : ans) cout << e.first << " " << e.second << '\n';
    return 0;
}
