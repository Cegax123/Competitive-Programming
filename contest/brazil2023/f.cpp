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
    int d, c, r; cin >> d >> c >> r;
    int a[c], b[r];

    for(int i = 0; i < c; i++) cin >> a[i];
    for(int i = 0; i < r; i++) cin >> b[i];

    int cnt = 0;
    int x = 0, y = 0;

    while(x < c or y < r) {
        if(x < c) {
            if(d >= a[x]) {
                d -= a[x];
                cnt++;
                x++;
                continue;
            }
            else {
                if(y < r) {
                    d += b[y];
                    cnt++;
                    y++;
                }
                else break;
            }
        }
        else {
            d += b[y];
            cnt++;
            y++;
        }
    }

    cout << cnt << "\n";
	
    return 0;
}


