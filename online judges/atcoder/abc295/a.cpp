#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define pb push_back
#define all(c) (c).begin(), (c).end()

int main() {
    vector<string> s;

    s.pb({"and"});
    s.pb({"not"});
    s.pb({"that"});
    s.pb({"the"});
    s.pb({"you"});

    int n; cin >> n;
    bool ans = 0;
    for(int i = 0; i < n; i++) {
        string w; cin >> w;
        bool cmp = 0;
        for(auto y : s) if(w == y) cmp = 1;
        if(cmp) ans = 1;
    }
    cout << (ans ? "Yes\n" : "No\n");

    return 0;
}

