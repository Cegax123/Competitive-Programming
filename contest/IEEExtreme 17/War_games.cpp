#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
    int n; cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++) {
        string a, b; getline(cin, a); getline(cin, b);
        
        deque<int> ca, cb;
        
        for(char c : a) {
            if(c == ' ') continue;
            if(c == 'A') ca.pb(14);
            if(c == 'T') ca.pb(10);
            if(c == 'J') ca.pb(11);
            if(c == 'Q') ca.pb(12);
            if(c == 'K') ca.pb(13);
            if(c >= '2' and c <= '9') ca.pb(c-'0');
        }
        
        for(char c : b) {
            if(c == ' ') continue;
            if(c == 'A') cb.pb(14);
            if(c == 'T') cb.pb(10);
            if(c == 'J') cb.pb(11);
            if(c == 'Q') cb.pb(12);
            if(c == 'K') cb.pb(13);
            if(c >= '2' and c <= '9') cb.pb(c-'0');
        }
        
        for(int i = 0; i < 1000; i++) {
            int x = ca.front(), y = cb.front();
            ca.pop_front(); cb.pop_front();
            if(x < y) {
                cb.push_back(x);
            }
            else if(x > y) {
                ca.push_back(y);
            }
            else {
                ca.push_back(x);
                cb.push_back(y);
            }
            
            if(ca.empty() or cb.empty()) break;
        }
        
        if(ca.empty()) cout << "player 2\n";
        else if(cb.empty()) cout << "player 1\n";
        else cout << "draw\n";
    }
    
    
    return 0;
}
