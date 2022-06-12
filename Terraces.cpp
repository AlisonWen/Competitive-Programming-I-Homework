#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
using pii = pair<int, int>;
int h[505][505], record[505][505];
vector <int> graph[250005];
pii p[505][505];
int _size[505][505];
int row, col;
set <pair<int, pii>> Sorted;
vector <pair<int, pii>> vertices;
int outDeg[250005];
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};
unordered_map <pii, int, pair_hash> Get_Idx;
bool inside(int x, int y){
    if(x >= 0 && x < row && y >= 0 && y < col) return true;
    return false;
}

pii find(pii x){
    if(x == p[x.first][x.second]) return x;
    return p[x.first][x.second] = find(p[x.first][x.second]);
}

void Union(pii x, pii y){
    x = find(x), y = find(y);
    if(x == y) return;
    _size[y.first][y.second] += _size[x.first][x.second];
    p[x.first][x.second] = y;
}

bool same(pii x, pii y){
    if(find(x) == find(y)) return true;
    return false;
}

int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> col >> row;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++) cin >> h[i][j];
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++) p[i][j] = make_pair(i, j), _size[i][j] = 1;
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(inside(i - 1, j) && h[i - 1][j] == h[i][j]) Union(make_pair(i - 1, j), make_pair(i, j));
            if(inside(i + 1, j) && h[i + 1][j] == h[i][j]) Union(make_pair(i + 1, j), make_pair(i, j));
            if(inside(i, j - 1) && h[i][j - 1] == h[i][j]) Union(make_pair(i, j - 1), make_pair(i, j));
            if(inside(i, j + 1) && h[i][j + 1] == h[i][j]) Union(make_pair(i, j + 1), make_pair(i, j));
        }
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(Sorted.find(pair<int, pii>{h[i][j], find(pii{i, j})}) == Sorted.end()) Sorted.emplace(h[i][j], find(make_pair(i, j)));
        }
    }
    int idx = 0;
    for(auto &i : Sorted){
        Get_Idx[i.second] = idx++;
        vertices.emplace_back(i);
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(inside(i - 1, j) && h[i - 1][j] != h[i][j]){
                if(h[i - 1][j] < h[i][j]) outDeg[Get_Idx[find(pii{i, j})]]++;
                else outDeg[Get_Idx[find(pii{i - 1, j})]]++;
            }
            if(inside(i + 1, j) && h[i + 1][j] != h[i][j]){
                if(h[i + 1][j] < h[i][j]) outDeg[Get_Idx[find(pii{i, j})]]++;
                else outDeg[Get_Idx[find(pii{i + 1, j})]]++;
            }
            if(inside(i, j - 1) && h[i][j - 1] != h[i][j]){
                if(h[i][j - 1] < h[i][j]) outDeg[Get_Idx[find(pii{i, j})]]++;
                else outDeg[Get_Idx[find(pii{i, j - 1})]]++;
            }
            if(inside(i, j + 1) && h[i][j + 1] != h[i][j]){
                if(h[i][j +1] < h[i][j]) outDeg[Get_Idx[find(pii{i, j})]]++;
                else outDeg[Get_Idx[find(pii{i, j + 1})]]++;
            }
        }
    }
    long long ans = 0;
    idx = 0;
    for(auto v : vertices){
        if(outDeg[idx] == 0){
            ans += _size[v.second.first][v.second.second];
        }
        idx++;
    }
    cout << ans << "\n";
    return 0;
}
