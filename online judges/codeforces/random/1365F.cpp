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
        int a[n], b[n];

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        multiset<ii> s;
        for(int i = 0; i < n/2; i++) {
            int l = min(a[i], a[n-1-i]), r = max(a[i], a[n-1-i]);
            s.insert({l, r});
        }

        bool cmp = 1;
        for(int i = 0; i < n/2; i++) {
            int l = min(b[i], b[n-1-i]), r = max(b[i], b[n-1-i]);
            ii curr = {l, r};

            if(s.count(curr) == 0) {
                cmp = 0;
                break;
            }
            
            s.erase(s.find(curr));
        }

        if(n&1) {
            if(a[n/2] != b[n/2]) cmp = 0;
        }

        if(cmp) cout << "Yes\n";
        else cout << "No\n";
    }
	
    for(int i=0;i<n;i++){
        int x;
        cin>>x;

    }
	
	return 0;
}

