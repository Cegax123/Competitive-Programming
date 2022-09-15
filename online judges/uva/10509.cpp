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

	double n;
	
    while(cin >> n and n) {
        double a = 0;

        while(a*a*a <= n)
            a++;

        a--;

        cout << setprecision(4) << fixed << a + (n-a*a*a) / (3 * a * a) << "\n";
    }
	
	return 0;
}

