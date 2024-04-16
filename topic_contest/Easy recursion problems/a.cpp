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

int f91(int n) {
    if(n <= 100) return f91(f91(n+11));
    else return n-10;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin >> n and n) {
        cout << "f91(" << n << ") = " << f91(n) << "\n";
    }

	
    return 0;
}


