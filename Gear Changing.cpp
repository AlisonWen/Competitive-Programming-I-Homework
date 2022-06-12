#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector <double> q;
    vector <double> Front, Back;
    double P = (double)p / 100.0;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        Front.emplace_back((double)tmp);
    }
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        Back.emplace_back((double)tmp);
    }
    for(auto i : Front){
        for(auto j : Back){
            q.emplace_back(i / j);
        }
    }
    sort(q.begin(), q.end());
    for(int i = 0; i < q.size() - 1; i++){
    	//cout << q[i + 1] / q[i] << endl;
        if(((q[i + 1] - q[i])/ q[i]) - P > 0.0000001){
            cout << "Time to change gears!\n";
            return 0;
        }
    }
    cout << "Ride on!\n";
    return 0;
}
