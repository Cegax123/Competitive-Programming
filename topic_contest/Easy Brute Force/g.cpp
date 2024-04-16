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

    int cnt = 0;
    for(int a = 1; a <= n; a++) {
        for(int b = a; b <= n; b++) {
            int c = a ^ b;
            if(c < b or c > n) continue;

            if(c < a+b and c-b < a and c-a < b) {
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
	
    return 0;
}


