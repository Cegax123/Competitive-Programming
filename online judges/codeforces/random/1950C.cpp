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
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int h = stoi(s.substr(0, 2));

        string xd = (h >= 0 and h <= 11 ? "AM" : "PM");

        if(h == 0) h = 12;
        else if(h >= 13) h -= 12;

        cout << h/10 << h%10 << s.substr(2, 3) << " " << xd << "\n";
    }

	
    return 0;
}


