#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        int pos = 0;

        for(int i = 1; i < n; i++) {
            cout << "? " << pos << " " << pos << " " << i << " " << i << endl;
            char result; cin >> result;

            if(result == '<') {
                pos = i;
            }
        }

        int pos_other = pos;
        vector<int> other;
        other.push_back(pos);

        for(int i = 0; i < n; i++) {
            if(i == pos) continue;

            cout << "? " << pos << " " << pos_other << " " << pos << " " << i << endl;
            char result; cin >> result;

            if(result == '=') {
                other.push_back(i);
            }
            else if(result == '<') {
                other.clear();
                other.push_back(i);
                pos_other = i;
            }
        }

        int ans = other[0];

        for(int x : other) {
            if(x == ans) continue;

            cout << "? " << ans << " " << ans << " " << x << "  " << x << endl;

            char result; cin >> result;
            if(result == '>') {
                ans = x;
            }
        }

        cout << "! " << pos << " " << ans << endl;
    }


    return 0;
}
