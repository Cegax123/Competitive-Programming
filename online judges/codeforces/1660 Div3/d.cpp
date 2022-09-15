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
        int n; cin >> n;
        int a[n];

        for(int i = 0; i < n; i++)
            cin >> a[i];

        ii ans = {n, 0};
        int prod = 0;

        int l = 0;

        while(l < n) {
            if(a[l] == 0) {
                l++;
                continue;
            }

            int r = l;
            while(r < n and a[r]) {
                r++;
            }

            r--;

            int f_n = -1, l_n = -1;
            int cnt_neg = 0, cnt_2 = 0;

            for(int i = l; i <= r; i++) {
                if(a[i] < 0) {
                    cnt_neg++;
                    if(f_n == -1) f_n = i;
                    l_n = i;
                }
                if(abs(a[i]) == 2) cnt_2++;
            }

            if(cnt_neg % 2 == 0) {
                if(cnt_2 > prod) {
                    prod = cnt_2;
                    ans = {l, n-1-r};
                }
            }
            else {
                int currL = 0, currR = 0;

                for(int i = l; i <= r; i++) {
                    if(abs(a[i]) == 2) {
                        if(i < l_n) currL++;
                        if(i > f_n) currR++;
                    }
                }

                if(currL > prod) {
                    prod = currL;
                    ans = {l, n-l_n};
                }
                if(currR > prod) {
                    prod = currR;
                    ans = {f_n+1, n-1-r};
                }
            }
            l = r+1;
        }

        cout << ans.first << " " << ans.second << "\n";
    }
	
	
	return 0;
}

