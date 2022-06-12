#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using T = pair<long long, pair<int, int>>;
ll mud[1005][1005], path[1005][1005], used[1005][1005];
ll row, col;

bool inside(int x, int y){
    if(x >= 0 && x < row && y >= 0 && y < col) return true;
    return false;
}

ll Dijkstra(){
    priority_queue <T, vector<T>, greater<T>> pq;

    for(int i = 0; i < row; i++){
        path[i][0] = mud[i][0];
        pq.push(T{path[i][0], {i, 0}});
    }
    
    while (!pq.empty()){
        int i = pq.top().second.first, j = pq.top().second.second;
        pq.pop();
        if(inside(i - 1, j)){
            if(max(mud[i - 1][j], path[i][j]) < path[i - 1][j]){
                path[i - 1][j] = max(mud[i - 1][j], path[i][j]);
                pq.emplace(T{path[i - 1][j], {i - 1, j}});
            }
        }
        if(inside(i + 1, j)){
            if(max(mud[i + 1][j], path[i][j]) < path[i + 1][j]){
                path[i + 1][j] = max(mud[i + 1][j], path[i][j]);
                pq.emplace(T{path[i + 1][j], {i + 1, j}});
            }
        }
        if(inside(i, j - 1)){
            if(max(mud[i][j - 1], path[i][j]) < path[i][j - 1]){
                path[i][j - 1] = max(mud[i][j - 1], path[i][j]);
                pq.emplace(T{path[i][j - 1], {i, j - 1}});
            }
        }
        if(inside(i, j + 1)){
            if(max(mud[i][j + 1], path[i][j]) < path[i][j + 1]){
                path[i][j + 1] = max(mud[i][j + 1], path[i][j]);
                pq.emplace(T{path[i][j + 1], {i, j + 1}});
            }
        }
    }

    ll ans = 1e18;
    for(int i = 0; i < row; i++) ans = min(ans, path[i][col - 1]);
    return ans;
}

int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> row >> col;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++) path[i][j] = 1e18;
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++) cin >> mud[i][j];
    }
    cout << Dijkstra() << "\n";
    
    return 0;
}
