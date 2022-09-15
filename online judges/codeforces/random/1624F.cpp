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

int n;
int l, r;
int target = 1;
int add = 0;

void query() {
    int m = (l+r+1) >> 1;

    int x = target * n - m - add;
    add += x;

    cout << "+ " << x << endl;

    int ans; cin >> ans;
    if(ans >= target) {
        l = m;
    }
    else {
        r = m-1;
    }

    if(l == m)
        target++;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;

    l = 1, r = n;

    while(l < r) {
        query();
    }
	
    cout << "! " << add + l << endl;
	
	return 0;
}

