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
        vi a(n);
        int cnt_pos = 0, cnt_neg = 0, cnt0 = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] > 0) cnt_pos++;
            else if(a[i] == 0) cnt0++;
            else cnt_neg++;
        }

        sort(all(a));

        if(cnt_pos >= 3 or cnt_neg >= 3) {
            cout << "NO\n";
            continue;
        }
        if(cnt0 >= 1 and (cnt_pos >= 2 or cnt_neg >= 2)) {
            cout << "NO\n";
            continue;
        }
        if(cnt_pos == 1 and cnt_neg == 1) {
            if(a[0] + a[n-1] == 0) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        if(cnt_pos == 0 and cnt_neg == 0) {
            cout << "YES\n";
            continue;
        }
        if(cnt_pos + cnt_neg == 1) {
            cout << "YES\n";
            continue;
        }

        bool cmp = true;
        set<int> x;

        for(int e : a)
            x.insert(e);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(i == j or j == k or i == k) continue;
                    if(x.count(a[i] + a[j] + a[k]) == 0)
                        cmp = false;
                }
            }
        }

        if(cmp) cout << "YES\n";
        else cout << "NO\n";
    }

	
    return 0;
}


