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

const int maxn = (int) 5e6;

int marked[maxn];




int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    vi a[2];

    for(int i = 0; i < n; i++) {
        int t, d; cin >> t >> d;
        a[d].pb(t);
    }

    reverse(all(a[0]));
    reverse(all(a[1]));

    memset(marked, -1, sizeof(marked));

    for(int i = 1; i < (int) 5e6; i++) {
        if(marked[i] == -1) {
            if(a[0].empty() and a[1].empty()) {
                cout << i << "\n";
                break;
            }
            if(!a[0].empty()) {
                int cnt = 0;
                while(!a[0].empty() and a[0].back() <= i) {
                    cnt++;
                    a[0].pop_back();
                }

                if(cnt) {
                    for(int j = 0; j < 10; j++) {
                        marked[i+j] = 0;
                    }
                }
            }
            if(!a[1].empty()) {
                int cnt = 0;
                while(!a[1].empty() and a[1].back() <= i) {
                    cnt++;
                    a[1].pop_back();
                }

                if(cnt) {
                    for(int j = 0; j < 10; j++) {
                        marked[i+j] = 1;
                    }
                }
            }
        }
        else {
            if(!a[marked[i]].empty() and a[marked[i]].back() == i) {
                a[marked[i]].pop_back();
                for(int j = 0; j < 10; j++)
                    marked[i+j] = marked[i];
            }
        }
    }

    return 0;
}


