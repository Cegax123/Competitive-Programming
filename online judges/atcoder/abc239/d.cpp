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

bool isP(int x) {
    if(x <= 1) return 0;

    for(int i = 2; i*i <= x; i++)
        if(x%i == 0) return 0;

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a, b, c, d; cin >> a >> b >> c >> d;

    string winner = "Aoki";

    for(int i = a; i <= b; i++) {
        bool cmp = 1;

        for(int j = c; j <= d; j++) 
            if(isP(i+j)) cmp = 0;

        if(cmp) winner = "Takahashi";
    }
	
    cout << winner << "\n";
	
	return 0;
}

