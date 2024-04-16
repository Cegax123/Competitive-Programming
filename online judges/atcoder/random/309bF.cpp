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
    int n; cin >> n;

    vector<pair<int, ii>> v;

    for(int i = 0; i < n; i++) {
        int a[3];

        for(int j = 0; j < 3; j++) cin >> a[j];

        sort(a, a+3);

        do {
            v.pb({a[0], {a[1], a[2]}});
        } while(next_permutation(a, a+3));
    }

    sort(all(v));

    set<ii> s;
    int ind = 0;
    bool ans = false;

    while(ind < (int) v.size()) {
        int r = ind;

        while(r < (int) v.size() and v[ind].first == v[r].first) r++;

        for(int i = ind; i < r; i++) {
            if(s.empty()) continue;

            auto it = s.lower_bound({v[i].second.first, 0});

            if(it == s.begin()) continue;

            it = prev(it);

            if(it -> second < v[i].second.second) {
                ans = true;
            }
        }

        for(int i = ind; i < r; i++) {
            s.insert(v[i].second);

            auto it = s.find(v[i].second);

            if(it != s.begin()) {
                auto bef = prev(it);
                
                if((bef -> first == it -> first) or (bef -> second <= it -> second)) {
                    s.erase(it);
                    continue;
                }
            }

            while(next(it) != s.end()) {
                if(it -> second <= next(it) -> second) s.erase(next(it));
                else break;
            }
        }

        ind = r;
    }

    cout << (ans ? "Yes\n" : "No\n");

    return 0;
}


