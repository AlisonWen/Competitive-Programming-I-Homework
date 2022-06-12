#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector <double> plot, house;

vector <pii> houses;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    plot.resize(n);
    house.resize(m + k);
    for(int i = 0; i < n; i++) {
        cin >> plot[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> house[i];
    }
    for(int i = m; i < m + k; i++) {
        cin >> house[i];
        house[i] /= 2;
        house[i] *= sqrt(2);
    }

    sort(plot.begin(), plot.end());
    sort(house.begin(), house.end());
    
    int cnt = 0;
    for(int i = 0, j = 0; i < m + k && j < n; i++){
        while(j < n && house[i] >= plot[j]) j++;
        if(j < n && house[i] < plot[j]){
            cnt++;
            j++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
