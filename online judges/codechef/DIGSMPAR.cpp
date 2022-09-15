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

int digsum(int x) {
    int sum = 0;

    while(x) {
        sum += x % 10;
        x /= 10;
    }

    return (sum&1);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int x = n;

        while(digsum(x) == digsum(n))
            x++;

        cout << x << "\n";
    }
	
	
	return 0;
}

