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
    int n, k; cin >> n >> k;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        vector<bool> find(k+1, 0);
        while(a) {
            find[a%10] = 1;
            a /= 10;
        }

        bool cmp = 1;

        for(int i = 0; i <= k; i++)
            if(!find[i]) cmp = 0;

        cnt += cmp;
    }

	cout << cnt << "\n";
    return 0;
}


