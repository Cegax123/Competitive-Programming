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
    multiset<int> a;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }

    int cnt = 0;
    while((int) a.size() > 1) {
        cnt++;
        int x = *a.rbegin(); a.erase(a.find(x));
        int mod = *a.begin();

        x %= mod;
        if(x) a.insert(x);
    }

    cout << cnt << "\n";
	
    return 0;
}


