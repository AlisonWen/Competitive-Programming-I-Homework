#include <bits/stdc++.h>
using namespace std;
unordered_map <string, vector<string>> graph;
unordered_map <string, int> used;
unordered_map <string, int> deg;
int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    cin.ignore();
    while (n--){
        string s;
        getline(cin, s);
        stringstream ss;
        ss << s;
        vector <string> buf;
        while (true){
            if(ss.fail()) break;
            string tmp;
            ss >> tmp;
            if(tmp == "") break;
            buf.emplace_back(tmp);
        }
        buf[0].pop_back();
        
        for(auto i : buf){
            if(i == buf[0]) continue;
            graph[i].emplace_back(buf[0]);
            deg[buf[0]]++;
            if(deg.find(i) == deg.end()) deg[i] = 0;
        }
    }
    string start;
    getline(cin, start);
    queue <string> q;
    for(auto &i : deg){
        //cout << i.first << " " << i.second << endl;
        if(i.second == 0 && i.first != start) q.push(i.first);
    }
    //cout << q.size() << endl;
    while (!q.empty()){
        string i = q.front();
        q.pop();
        for(auto j : graph[i]){
            deg[j]--;
            //cout << j << " " << deg[j] << endl;
            if(!deg[j] && j != start) q.push(j);
        }
    }
    cout << endl;
    q.push(start);
    while (!q.empty()){
        string i = q.front();
        q.pop();
        cout << i << "\n";
        for(auto j : graph[i]){
            deg[j]--;
            if(!deg[j]) q.push(j);
        }
    }
    
    
    return 0;
}
