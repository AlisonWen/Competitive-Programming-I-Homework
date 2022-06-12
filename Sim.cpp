#include <iostream>
#include <cstring>
#include <list>
using namespace std;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--){
        list <char> screen;
        auto pos = screen.begin();
        string s;
        getline(cin, s);
        for(auto c : s){
            if(c == '<'){
                if(pos != screen.begin()) pos = screen.erase(--pos);
            }else if(c == ']') pos = screen.end();
            else if(c == '[') pos = screen.begin();
            else{
                pos = screen.insert(pos, c);
                pos++;
            }
        }
        for(auto i : screen) cout << i;
        cout << '\n';
        
    }
    
    return 0;
}
