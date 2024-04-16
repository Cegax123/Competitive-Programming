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

void hanoi(int n, char from, char to, char tmp) {
    if(n == 0) return;

    hanoi(n-1, from, tmp, to);
    cout << "Move from " << from << " to " << to << ".\n";
    hanoi(n-1, tmp, to, from);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    char poss[3] = {'A', 'B', 'C'};
    while(t--) {
        int n; cin >> n;
        char from, to; cin >> from >> to;

        char tmp='A';

        for(int i = 0; i < 3; i++)
            if(poss[i] != from and poss[i] != to) tmp = poss[i];

        hanoi(n, from, to, tmp);
        cout << "Done!\n";
    }

	
    return 0;
}


