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
    int t; cin >> t;
    while(t--) {
        int n, m, k; cin >> n >> m >> k;
        string a, b; cin >> a >> b;

        sort(all(a));
        sort(all(b));

        reverse(all(a));
        reverse(all(b));

        string c;

        int curr = k;
        int last = -1;

        while(1) {
            if(a.empty() or b.empty())
                break;

            if(a.back() < b.back()) {
                if(last != 0) {
                    curr = k-1;
                    last = 0;
                    c += a.back();
                    a.pop_back();
                }
                else {
                    if(curr) {
                        curr--;

                        c += a.back();
                        a.pop_back();
                    }
                    else {
                        curr = k-1;
                        last = 1;

                        c += b.back();
                        b.pop_back();
                    }
                }
            }
            else {
                if(last != 1) {
                    curr = k-1;
                    last = 1;
                    c += b.back();
                    b.pop_back();
                }
                else {
                    if(curr) {
                        curr--;
                        c += b.back();
                        b.pop_back();
                    }
                    else {
                        curr = k-1;
                        last = 0;
                        c += a.back();
                        a.pop_back();
                    }
                }
            }
        }

        cout << c << "\n";
    }



    return 0;
}


