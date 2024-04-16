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
    string s; cin >> s;

    int global = 0;

    int a = 0, b = 0, c = 0;

    for(char d : s) {
        int new_a = a, new_b = b, new_c = c;
        if(d == 'a') {
            new_a = a + 1;
            new_c = max(b + 1, c + 1);
        }
        else {
            new_b = max(a + 1, b + 1);
        }

        a = new_a;
        b = new_b;
        c = new_c;

        global = max({global, a, b, c});
    }

    cout << global << "\n";
	
    return 0;
}


