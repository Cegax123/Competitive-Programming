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

const int maxn = 1e5+5;
const int maxk = 8;
const int max_sz = 43046721;

vector<vi> comp(maxn, vi(maxk, 0));
vi cnt(max_sz, 0);

int n, k;

void update(int pos, int x, int accum, int ind) {
    if(pos >= k) {
        cnt[accum] += x;
        return;
    }

    for(int i = 0; i <= comp[ind][pos]; i++) {
        update(pos+1, x, accum * 9 + i, ind);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int ind = 0;
	
    while(n--) {
        char op; cin >> op;

        if(op == 'C') {
            int r; cin >> r;

            for(int i = 0; i < r; i++) {
                int t; cin >> t;
                comp[ind][t-1]++;
            }

            update(0, 1, 0, ind);
            ind++;
        }
        else if(op == 'D') {
            int j; cin >> j;
            j--;
            update(0, -1, 0, j);
        }
        else {
            vi Q(k, 0);
            int r; cin >> r;

            for(int i = 0; i < r; i++) {
                int t; cin >> t;
                Q[t-1]++;
            }

            int j = 0;
            for(int i = 0; i < k; i++)
                j = j * 9 + Q[i];

            cout << cnt[j] << "\n";
        }
    }
	
	return 0;
}

