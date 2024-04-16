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
        int sum = 0;

        int cntm1m1 = 0, ctns1m1 = 0, cnts1s1 = 0;

        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        for(int i = 0; i+1 < n; i++) {
            if(a[i] == -1 and a[i+1] == -1) cntm1m1++;
            if(a[i]+a[i+1] == 0) ctns1m1++;
            if(a[i]+a[i+1] == 2) cnts1s1++;
        }

        if(cntm1m1) sum += 4;
        else if(ctns1m1) sum += 0;
        else sum -= 4;

        cout << sum << "\n";
    }

	
    return 0;
}


