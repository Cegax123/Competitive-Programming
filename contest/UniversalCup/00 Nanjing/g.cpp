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

const int maxn = 1e6 + 6;
int a[maxn], b[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi pos;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == 0) pos.pb(i);
        }

        auto cmp = [&](int x) {
            for(int i = 0; i < n; i++)
                b[i] = a[i];

            for(int i = 0; i < (int) pos.size(); i++) {
                if(i < x) b[pos[i]] = 1;
                else b[pos[i]] = -1;
            }

            int st = 1;

            for(int i = 0; i < n; i++) {
                st += b[i];
                if(st == 0) return false;
            }

            return true;
        };

        int l = 0, r = pos.size();

        while(l < r) {
            int m = (l+r) >> 1;
            if(cmp(m)) r = m;
            else l = m+1;
        }

        if(!cmp(l)) {
            cout << -1 << "\n";
        }
        else {
            int num = 1, den = 1;

            for(int i = 0; i < (int) pos.size(); i++) {
                if(i < l) a[pos[i]] = 1;
                else a[pos[i]] = -1;
            }

            for(int i = 0; i < n; i++) {
                if(a[i] == 1) num++, den++;
                else den--;
            }

            int g = __gcd(num, den);

            cout << num/g << " " << den/g << "\n";
        }
    }

	
    return 0;
}


