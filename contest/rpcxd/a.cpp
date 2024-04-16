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
    int n; cin >> n;
    if(n == 0) {
        cout << n << "\n";
        return 0;
    }

    vi cnt(10, 0);

    while(n) {
        cnt[n%10]++;
        n /= 10;
    }

    for(int i = 9; i >= 0; i--) {
        for(int j = 0; j < cnt[i]; j++)
            cout << i;
    }

    cout << "\n";

    return 0;
}


