#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> arr;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 0, loc = 0, i;
    for(i = 0; i < n; i++){
        if(arr[i] - ans > n) break;
        if(arr[i] > ans) ans++;
    }
    ans += n - i;
    cout << ans << '\n';
    return 0;
}
