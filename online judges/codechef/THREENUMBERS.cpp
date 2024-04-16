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
        int a[3];
        for(int i = 0; i < 3; i++)
            cin >> a[i];

        sort(a, a+3);

        int cnt = 0;
        bool cmp = 1;

        int d1 = a[1]-a[0], d2 = a[2]-a[0];

        if(d1&1) cmp = 0;
        else cnt += d1/2;

        if(d2&1) cmp = 0;
        else cnt += d2/2;

        if(!cmp) cout << "-1\n";
        else cout << cnt << "\n";
    }

	
    return 0;
}


