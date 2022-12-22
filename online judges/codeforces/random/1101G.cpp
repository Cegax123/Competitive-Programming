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

const int LOGN = 30;
int b[LOGN];

void insert_element(int x) {
    for(int i = 0; i < LOGN; i++) {
        if((x >> i)&1 and b[i] != -1) {
            x ^= b[i];
        }
    }

    if(x == 0) 
        return;

    for(int i = 0; i < LOGN; i++) {
        if((x >> i)&1 and b[i] == -1) {
            b[i] = x;
            return;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    memset(b, -1, sizeof(b));

    int n; cin >> n;
    int y = 0;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        y ^= a;
        insert_element(y);
    }

    if(y == 0) {
        cout << "-1\n";
        return 0;
    }

    int ans = 0;
    for(int i = 0; i < LOGN; i++) ans += b[i] != -1;

    cout << ans << "\n";
	
    return 0;
}


