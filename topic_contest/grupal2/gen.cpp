#include<bits/stdc++.h>
using namespace std;

bool comp(int n, int num) {
    vector<int> v;

    for(int i = 0; i < n; i++) 
        v.push_back((num>>i)&1);
    for(int i = 0; i < n; i++) 
        v.push_back((num>>i)&1);

    for(int i = 1; i < 2 * n; i++) if(v[i] == 1 and v[i-1] == 1) return false;

    set<int> s;
    for(int i = 0; i < n; i++) {
        int x = 0;
        for(int j = 0; j < n; j++) {
            x = x * 2 + v[i+j];
        }
        if(s.count(x)) return 0;
        s.insert(x);
    }

    reverse(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        int x = 0;
        for(int j = 0; j < n; j++) {
            x = x * 2 + v[i+j];
        }
        if(s.count(x)) return 0;
        s.insert(x);
    }

    return true;
}

int main() {
    int n = 3;

    for(int i = 0; i < (1 << n); i++) {
        if(comp(n, i)) {
            cout << i << endl;

            for(int j = 0; j < n; j++) {
                cout << ((i>>j)&1) << " ";
            }
            cout << endl;

            return 0;
        }
    }


    return 0;
}
