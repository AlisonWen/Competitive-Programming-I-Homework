#include <iostream>
#include <algorithm>
using namespace std;
int p[200005];
int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}
void Union(int x, int y){
    if(find(x) == find(y)) return ;
    p[find(x)] = find(y);
}
bool same(int x, int y){
    if(find(x) == find(y)) return true;
    return false;
}
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++) p[i] = i;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    int flag = 0;
    for(int i = 1; i <= n; i++){
        if(!same(1, i)) cout << i << '\n', flag = 1;
    }
    if(!flag) cout << "Connected\n";
    return 0;
}
