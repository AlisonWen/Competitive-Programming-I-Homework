#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    stack <char> stk;
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == ' ') continue;
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
        else{
            if(stk.empty()) {
                cout << s[i] << " " << i << '\n';
                flag = 1;
                break;
            }else{
                if(s[i] == ')'){
                    if(stk.top() == '(') stk.pop();
                    else {
                        flag = 1;
                        cout << s[i] << " " << i << '\n';
                        break;
                    }
                }
                if(s[i] == ']'){
                    if(stk.top() == '[') stk.pop();
                    else {
                        flag = 1;
                        cout << s[i] << " " << i << '\n';
                        break;
                    }
                }
                if(s[i] == '}'){
                    if(stk.top() == '{') stk.pop();
                    else {
                        flag = 1;
                        cout << s[i] << " " << i << '\n';
                        break;
                    }
                }
            }
        }
    }
    if(flag == 0) cout << "ok so far\n";
    return 0;
}
