#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector <int> p;
vector <pair<pii, int>> Tree;
map <int, int> Mapping;

int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}

bool same(int x, int y){
    if(find(x) == find(y)) return true;
    return false;
}

void Union(int x, int y){
    if(find(x) == find(y)) return;
    p[find(x)] = find(y);
}

int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m;
    cin >> n;
    p.resize(n + 1);
    for(int i = 0; i <= n; i++) p[i] = i;
    //int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> m;
        while (m--){
            int x;
            cin >> x;
            if(!Mapping[x]) Mapping[x] = i;
            else{
                int v = Mapping[x];
                if(!same(v, i)){
                    Union(v, i);
                    Tree.emplace_back(pair<pii, int>{{min(v, i), max(v, i)}, x});
                }
            }
        }
    }
    if(Tree.size() != n - 1) cout << "impossible\n";
    else{
        sort(Tree.begin(), Tree.end());
        for(auto e : Tree){
            cout << e.first.first << " " << e.first.second << " " << e.second << "\n";
        }
    }
    return 0;
}
