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

char get_nxt(char c) {
    if(c == 'a') return 'b';
    if(c == 'b') return 'c';
    return 'a';
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int x[k], c[k];
        for(int i = 0; i < k; i++) 
            cin >> x[i];
        for(int i = 0; i < k; i++)
            cin >> c[i];

        bool cmp = 1;

        if(x[0] < c[0]) cmp = 0;

        for(int i = 1; i < k; i++) {
            if(x[i]-x[i-1] < c[i]-c[i-1]) cmp = 0;
        }

        if(cmp == 0) {
            cout << "NO\n";
            continue;
        }

        int p = c[0]-3;

        char last = 'c';

        cout << "YES\n";

        for(int i = 0; i < x[0]-p; i++) {
            last = get_nxt(last);
            cout << last;
        }

        cout << string(p, last);

        for(int i = 1; i < k; i++) {
            int len = x[i]-x[i-1];
            int need = c[i]-c[i-1];

            int lft = len-need;

            char st = get_nxt(last);

            char c = 'c' + i;

            cout << string(need, c);
            
            for(int i = 0; i < lft; i++) {
                cout << st;
                last = st;
                st = get_nxt(st);
            }
        }

        cout << "\n";
    }

	
    return 0;
}


