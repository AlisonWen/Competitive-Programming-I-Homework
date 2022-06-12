#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int paper[1005][1005];
int ans[1005];
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> paper[i][j];
            ans[i] |= paper[i][j];
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " "; cout << '\n';
    return 0;
}
