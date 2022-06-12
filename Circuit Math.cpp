#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
int value[30];
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        if(tmp == "T") value[i] = 1;
        else value[i] = 0;
    }
    cin.ignore();
    stack <int> stk;
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '*' || s[i] == '+'){
            int tmp1 = stk.top();
            stk.pop();
            int tmp2 = stk.top();
            stk.pop();
            if(s[i] == '*') stk.push(tmp1 * tmp2);
            else if(tmp1 + tmp2 > 1) stk.push(1);
            else stk.push(tmp1 + tmp2);
        }else if(s[i] == '-'){
            int tmp = stk.top();
            stk.pop();
            if(tmp) stk.push(0);
            else stk.push(1);
        }else if(s[i] != ' '){
            stk.push(value[s[i] - 'A']);
        }
    }
    if(stk.top()) cout << "T\n";
    else cout << "F\n";
    return 0;
}
