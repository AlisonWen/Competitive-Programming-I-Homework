#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;
vector <int> p;

int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}
bool same(int x, int y){
    if(find(x) == find(y)) return true;
    return false;
}
void Union(int x, int y){
    p[find(x)] = find(y);
}
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, t;
    cin >> n >> t;
    p.resize(n + 1);
    for(int i = 1; i <= n; i++) p[i] = i;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        string judge;
        int a, b;
        stringstream ss;
        ss << s;
        ss >> judge >> a >> b;
        if(judge == "=") Union(a, b);
        else {
            if(same(a, b)) cout << "yes\n";
            else cout << "no\n";
        }
    }
    return 0;
}
