#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
unordered_map <char, int> list;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    string s;
    list['a'] = 10; list['A'] = 10;
    list['b'] = 11; list['B'] = 11;
    list['c'] = 12; list['C'] = 12;
    list['d'] = 13; list['D'] = 13;
    list['e'] = 14; list['E'] = 14;
    list['f'] = 15; list['F'] = 15;
    while (getline(cin, s)){
        int i = 0;
        while(i < s.size() - 1){
            int start;
            if(s[i] == '0' && (s[i + 1] == 'X' || s[i + 1] == 'x')){
                start = i;
                string name = "";
                int j = i + 2;
                while (j < s.size()){
                    if(isdigit(s[j])) name = name + s[j];
                    else if(isalpha(s[j])){
                        if(isupper(s[j])){
                            if(s[j] - 'A' < 6) name = name + s[j];
                            else break;
                        }
                        if(islower(s[j])){
                            if(s[j] - 'a' < 6) name = name + s[j];
                            else break;
                        }
                    }else break;
                    j++;
                }
                long long value = 0;
                for(auto j : name){
                    if(isdigit(j)) value = 16 * value + j - '0';
                    else value = 16 * value + list[j];
                }
                cout  << s[start] << s[start + 1] << name << " " << value << '\n';
            }
            i++;
        }
    }
    
    return 0;
}
