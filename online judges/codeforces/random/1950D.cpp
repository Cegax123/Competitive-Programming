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

bool cmp(int x) {
    while(x) {
        if(x % 10 > 1) return false;
        x /= 10;
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    vector<int> num;
    for(int i = 2; i <= 1e5; i++) {
        if(cmp(i)) {
            num.push_back(i);
        }
    }

    reverse(num.begin(), num.end());

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int x : num) {
            while(n % x == 0) n /= x;
        }

        cout << (n == 1 ? "YES\n" : "NO\n");
    }
	
    return 0;
}


