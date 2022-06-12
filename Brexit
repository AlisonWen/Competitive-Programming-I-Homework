#include <bits/stdc++.h>
using namespace std;
vector <int> graph[200005];
int deg[200005], leave[200005];
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m, x, start;
    cin >> n >> m >> x >> start;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
        deg[a]++;
        deg[b]++;
    }
    queue <int> q;
    q.push(start);
    leave[start] = 1;
    while (!q.empty()){
        int i = q.front();
        q.pop();
        if(i == x){
            cout << "leave\n";
            return 0;
        }
        for(auto j : graph[i]){
            if(!leave[j]){
                deg[j]--;
                if(deg[j] <= graph[j].size() / 2){
                    leave[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    if(leave[x]) cout << "leave\n";
    else cout << "stay\n";
    return 0;
}
