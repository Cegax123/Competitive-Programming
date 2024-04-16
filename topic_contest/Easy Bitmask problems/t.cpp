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

const int N = 0, C = 1, ON = 2, OFF = 3;
const int L = 10;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q; cin >> q;
    vi st(L, 0);

    for(int i = 0; i < q; i++) {
        char op; cin >> op;
        int x; cin >> x;

        for(int j = 0; j < L; j++) {
            if((x >> j)&1) {
                if(op == '|') st[j] = ON;
                if(op == '^') {
                    if(st[j] == N) st[j] = C;
                    else if(st[j] == C) st[j] = N;
                    else if(st[j] == ON) st[j] = OFF;
                    else if(st[j] == OFF) st[j] = ON;
                }
            }
            else {
                if(op == '&') st[j] = OFF;
            }
        }
    }

    cout << "3\n";
    int mask = (1 << L) - 1;
    for(int i = 0; i < L; i++) 
        if(st[i] == OFF) mask ^= (1 << i);

    cout << "& " << mask << "\n";

    mask = 0;

    for(int i = 0; i < L; i++)
        if(st[i] == ON) mask ^= (1 << i);

    cout << "| " << mask << "\n";

    mask = 0;

    for(int i = 0; i < L; i++)
        if(st[i] == C) mask ^= (1 << i);

    cout << "^ " << mask << "\n";
	
    return 0;
}


