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
        int a[m];

        for(int i = 0; i < m; i++) cin >> a[i];

        sort(a, a+m);

        int c1 = n/k, c2 = (n+k-1)/k;
        int cnt2 = n % k, cnt1 = k-cnt2;

        if(c1 == c2) {
            bool cmp = 1;
            for(int i = 0; i < m; i++)
                if(a[i] > c1) cmp = 0;

            cout << (cmp ? "YES\n" : "NO\n");
            continue;
        }

        int lmt = (cnt2 ? c2 : c1);
        bool cmp = 1;
        int cnt_1 = 0, cnt_2 = 0;

        for(int i = 0; i < m; i++) {
            if(a[i] > lmt) cmp = 0;
            else if(a[i] == c2) cnt_2++;
            else if(a[i] == c1) cnt_1++;
        }

        if(cnt_2 > cnt2) cmp = 0;
        else {
            cnt1 += cnt2-cnt_2;
        }
        if(cnt_1 > cnt1) cmp = 0;

        cout << (cmp ? "YES\n" : "NO\n");
    }

	
    return 0;
}


