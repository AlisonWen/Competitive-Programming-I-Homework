#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <map>
#include <set>
using namespace std;
map <string, set<string>> list;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    stringstream ss;
    while (cin >> t && t){
        list.clear();
        cin.ignore();
        while (t--){
            string s;
            getline(cin, s);
            ss.str();
            ss.clear();
            int times = 0;
            string name;
            ss << s;
            while (true){
                if(ss.fail()) break;
                string tmp;
                ss >> tmp;
                if(tmp == "") break;
                if(times == 0) name = tmp;
                else list[tmp].emplace(name);
                times++;
            }
            
        }
        for(auto i = list.begin(); i != list.end(); i++){
            cout << i -> first << " ";
            for(auto j = i -> second.begin(); j != i -> second.end(); j++){
                cout << *j << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
    
    
    return 0;
}
