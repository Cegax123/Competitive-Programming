// SOLVED

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

const int L = 22;

void add(ii& a, int x) {
    if(x > a.second) {
        a.first = a.second;
        a.second = x;
    }
    else if(x > a.first) 
        a.first = x;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vii f(1 << L, {-1, -1});

    for(int i = 0; i < n; i++) {
        add(f[a[i]], i);
    }
	
    for(int i = 0; i < L; i++) {
        for(int mask = 0; mask < (1 << L); mask++) {
            if((mask & (1 << i)) == 0) {
                add(f[mask], f[mask | (1 << i)].first);
                add(f[mask], f[mask | (1 << i)].second);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < n-2; i++) {
        int w = 0;
        for(int j = L-1; j >= 0; j--) {
            if((a[i] >> j) & 1) continue;
            
            int x = f[w | (1 << j)].first, y = f[w | (1 << j)].second;

            if(x > i and y > i) {
                w |= (1 << j);
            }
        }

        ans = max(ans, a[i] | w);
    }

    cout << ans << "\n";
	
	return 0;
}


