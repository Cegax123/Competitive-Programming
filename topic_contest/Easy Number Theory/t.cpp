#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
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


const int maxn = 61;
ll f[maxn];

string get(ll x) {
    string sx = string(maxn, '0');
    for(int i = maxn-1; i >= 0; i--) {
        if(x >= f[i]) {
            x -= f[i];
            sx[i] = '1';
        }
    }

    while(not sx.empty() and sx[(int) sx.size()-1] == '0') sx = sx.substr(0, (int) sx.size()-1);
    if(sx.empty()) sx += '0';

    reverse(all(sx));
    return sx;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    f[0] = 1;
    f[1] = 2;

    for(int i = 2; i < maxn; i++) {
        f[i] = f[i-1] + f[i-2];
    }

    string a, b;
    while(cin >> a >> b) {
        ll na = 0, nb = 0;

        reverse(all(a)); reverse(all(b));

        for(int i = 0; i < (int) a.size(); i++)
            na += (a[i] == '1' ? f[i] : 0ll);

        for(int i = 0; i < (int) b.size(); i++) 
            nb += (b[i] == '1' ? f[i] : 0ll);

        ll nc = na + nb;

        string sa = get(na), sb = get(nb), sc = get(nc);
        int spaces = sc.size();

        cout << "  " << setw(spaces) << sa << "\n";
        cout << "+ " << setw(spaces) << sb << "\n";
        cout << "  " << string(spaces, '-') << "\n";
        cout << "  " << sc << "\n\n";
    }
	
    return 0;
}


