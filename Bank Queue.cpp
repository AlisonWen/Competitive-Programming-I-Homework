#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector <int> selected;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, t;
    cin >> n >> t;
    selected.resize(t + 1);
    for(int i = 0; i < n; i++){
        int cash, Time;
        cin >> cash >> Time;
        for(int j = Time; j >= 0 ; j--){
            if(cash > selected[j]) swap(cash, selected[j]);
        }
    }
    int ans = 0;
    for(auto i : selected) ans += i;
    cout << ans << '\n';
    return 0;
}
