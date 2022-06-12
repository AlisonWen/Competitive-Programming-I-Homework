#include <bits/stdc++.h>
using namespace std;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    if(n <= 25){
        cout << "a" << (char)('a' + n) << "\n";
    }else if(n % 25 == 0){
        string s = "a";
        while(n >= 25){
            n -= 25;
            if(s.back() == 'a') s.push_back('z');
            else s.push_back('a');
        }
        cout << s << "\n";
    }else{
        int r1 = n % 25;
        string s = "a";
        s = s + char('n' + r1 / 2);
        while(n >= 25){
            n -= 25;
            if(s.back() == 'a') s.push_back('z');
            else s.push_back('a');
        }
        if(r1 % 2 == 0){
            if(s.back() == 'a') s.back()++;
            else s.back()--;
        }
        cout << s << "\n";
    }
    return 0;
}
