#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<vi> v;
    v.pb({7});
    v.pb({4});
    v.pb({2, 8});
    v.pb({1, 5});
    v.pb({3, 9});
    v.pb({6});
    v.pb({10});

    string s; cin >> s;
    if(s[0] != '0') {
        cout << "No\n";
        return 0;
    }

    auto cmp_k = [&](vi a) {
        for(int x : a)
            if(s[x-1] == '1') return 1;
        return 0;
    };

    auto cmp_s = [&](vi a) {
        for(int x : a)
            if(s[x-1] == '1') return 0;
        return 1;
    };


    bool found = 0;
    for(int i = 0; i < 7; i++) {
        for(int j = i + 1; j < 7; j++) {
            for(int k = i + 1; k < j; k++) {
                if(cmp_k(v[i]) and cmp_k(v[j]) and cmp_s(v[k])) 
                    found = 1;
            }
        }
    }
	
    if(found) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}


