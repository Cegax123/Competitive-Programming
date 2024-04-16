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

int get_num(string s) {
    int num = 0;
    int decimals = 0;
    bool after = false;
    for(char c : s) {
        if(c == '.') {
            after = true;
        }
        else {
            decimals += after;
            num = num * 10 + (c-'0');
        }
    }

    for(int i = decimals; i < 2; i++)
        num *= 10;

    return num;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a, b, c; cin >> a >> b >> c;
    int p = get_num(a);
    int q = get_num(b);
    int r = get_num(c);

    if(p == r) {
        double ans = p * 2ll * (p+q);
        ans /= 10000.0;

        cout << fixed << setprecision(4);
        cout << ans << "\n";
    }
    else {
        cout << 0 << "\n";
    }
	
    return 0;
}


