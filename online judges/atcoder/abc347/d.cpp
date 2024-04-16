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
    int a, b; cin >> a >> b;
    ll c; cin >> c;

    int bc = __builtin_popcountll(c);

    for(int i = 0; i <= min(a, b); i++) {
        int lfta = a - i;
        int lftb = b - i;

        if(lfta + lftb == bc and i + bc <= 60) {
            ll numa = 0, numb = 0;
            int cnt = 0;
            int cnt2 = 0;
            for(int j = 0; j < 60; j++) {
                if((c>>j)&1ll) {
                    if(cnt < lfta) numa ^= (1ll << j);
                    else numb ^= (1ll << j);

                    cnt++;
                }
                else {
                    if(cnt2 < i) {
                        numa ^= (1ll << j);
                        numb ^= (1ll << j);
                    }
                    cnt2++;
                }
            }

            cout << numa << " " << numb << "\n";
            cout << (numa^numb) << endl;
            
            return 0;
        }
    }

    cout << -1 << "\n";
	
    return 0;
}


