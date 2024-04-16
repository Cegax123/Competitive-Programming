#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<string> cc;
        while(!s.empty()) {
            int k = s.size();
            if(s.back() == 'a' or s.back() == 'e') {
                cc.push_back(s.substr(k-2, 2));
                s.pop_back();
                s.pop_back();
            }
            else {
                cc.push_back(s.substr(k-3, 3));
                s.pop_back();
                s.pop_back();
                s.pop_back();
            }
        }

        reverse(cc.begin(), cc.end());
        for(int i = 0; i < (int) cc.size()-1; i++) cout << cc[i] << ".";
        cout << cc.back() << "\n";
    }


    return 0;
}
