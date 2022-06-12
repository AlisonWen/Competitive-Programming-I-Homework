#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector <char> ans;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    string s;
    getline(cin, s);
    //stack <char> stk;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '<') ans.emplace_back(s[i]);
        else if(!ans.empty()) ans.pop_back();
    }
    if(!ans.empty()){
        for(auto i : ans) cout << i; cout << '\n';
    }else cout << "";
    return 0;
}
