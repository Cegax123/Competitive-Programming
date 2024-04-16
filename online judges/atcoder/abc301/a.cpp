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
    string s; cin >> s;

    int t = 0, a = 0;
    for(int i = 0; i < n; i++) {
        t += s[i] == 'T';
        a += s[i] == 'A';
    }

    if(t > a) cout << "T\n";
    else if(a > t) cout << "A\n";
    else cout << (s.back() == 'T' ? "A\n" : "T\n");

	
    return 0;
}


