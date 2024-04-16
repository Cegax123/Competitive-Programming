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

const int L = 30;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int a, b, c; cin >> a >> b >> c;

        int x = 0;
        
        bool find_three = true;
        bool find_two = false;

        for(int i = L-1; i >= 0; i--) {
            if(find_three) {
                int da = (a >> i)&1;
                int db = (b >> i)&1;
                int dc = (c >> i)&1;

                if(da == db and db == dc) continue;

                int xda = 1 ^ da;
                int xdb = 1 ^ db;
                int xdc = 1 ^ dc;
                if(da <= db and db <= dc) {
                    find_three = false;
                    if(db == dc) find_two = true;
                }
                else if(xda <= xdb and xdb <= xdc) {
                    find_three = false;
                    x ^= (1 << i);
                    if(xdb == xdc) find_two = true;
                }
            }
            else {
                int da = (a >> i)&1;
                int db = (b >> i)&1;
                int dc = (c >> i)&1;

                if(find_two) {
                    if(db == dc) continue;
                    if(db > dc) {
                        x ^= (1 << i);
                    }

                    break;
                }
                else {
                    if(da == db) continue;
                    if(da > db) x ^= (1 << i);
                    break;
                }
            }
        }

        int xa = a ^ x, xb = x ^ b, xc= c ^ x;

        if(xa < xb and xb < xc) {
            cout << x << "\n";
        }
        else cout << -1 << "\n";
    }

	
    return 0;
}


