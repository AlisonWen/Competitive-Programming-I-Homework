#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
int graph[105][105];
int used[105][105];
int row, col;
int ans = 0, len = 0;
int a, b;
bool inside(int i, int j){
    if(i >= 0 && i < row && j >= 0 && j < col) return true;
    return false;
}

vector <pair<int, int>> path;

bool adjacent(int x, int y, int i, int j){
	if(abs(x - i) <= 1 && abs(y - j) <= 1) return true;
	return false;
}

void DFS(int pre1, int pre2, int r, int c){
    path.emplace_back(pii{r, c});
    used[r][c] = 1;
    int flag = 0;
    for(int i = r - 1; i <= r + 1; i++){
        for(int j = c - 1; j <= c + 1; j++){
        	if(i == r && j == c) continue;
            if(graph[i][j] && inside(i, j) && (r != pre1 || c != pre2) && !used[i][j]){
                DFS(r, c, i, j);
            }
        }
    }
}

int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> row >> col;
    for(int i = 0; i < row; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '#') graph[i][j] = 1;
        }
    }
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(!used[i][j] && graph[i][j]){
                path.clear();
                DFS(-1, -1, i, j);
                if(adjacent(path.begin() -> first, path.begin() -> second, i, j) && path.size() >= 3) ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
