#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
ll x[1000005];
int n, mod, a, c; 
bool BinarySearch(int target){
    int left = 1, right = n;
    int mid = (left + right) / 2;
    while (left <= right){
        mid = (left + right) / 2;
        if(x[mid] == target) return true;
        if(x[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    if(x[mid] == target) return true;
    return false;
}

int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> mod >> a >> c >> x[0];
    for(int i = 1; i <= n; i++){
        x[i] = (a * x[i - 1] + c) % mod; 
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(BinarySearch(x[i])) ans++;
    }
    cout << ans << "\n";
    return 0;
}
