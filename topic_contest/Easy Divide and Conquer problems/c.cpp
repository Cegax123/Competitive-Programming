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

string s, t;

bool is_eq(int l1, int r1, int l2, int r2) {
    int len = r1-l1+1;
    for(int i = 0; i < len; i++)
        if(s[l1+i] != t[l2+i]) return false;
    return true;
}


bool equiv(int l1, int r1, int l2, int r2) {
    int len = r1-l1+1;

    if(len&1) {
        return is_eq(l1, r1, l2, r2);
    }

    int nxt = len/2;

    if(equiv(l1, l1+nxt-1, l2, l2+nxt-1) and equiv(l1+nxt, r1, l2+nxt, r2)) return true;
    if(equiv(l1, l1+nxt-1, l2+nxt, r2) and equiv(l1+nxt, r1, l2, l2+nxt-1)) return true;
    return false;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s >> t;

    int n = s.size();

    cout << (equiv(0, n-1, 0, n-1) ? "YES\n" : "NO\n");
	
    return 0;
}


