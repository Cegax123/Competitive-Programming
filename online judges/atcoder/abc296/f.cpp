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
    vii c(n);

    map<int, int> cnta, cntb;

    for(int i = 0; i < n; i++) {
        cin >> c[i].first;
        cnta[c[i].first]++;
    }

    for(int i = 0; i < n; i++) {
        cin >> c[i].second;
        cntb[c[i].second]++;
    }

    bool cmp = 1;
    for(auto e : cnta) {
        if(cntb[e.first] != e.second) {
            cmp = 0;
        }
    }

    if(!cmp) {
        cout << "No\n";
        continue;
    }

    sort(all(c));

    vi b(n);

    for(int i = 0; i < n; i++)
        b[i] = c[i].second;

    
	
    return 0;
}


