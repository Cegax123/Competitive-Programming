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
    string A[n + 5];

    for(int i = 0; i < n; i++)
        cin >> A[i];

    bool cmp = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;

            if(A[i][j] == 'W' and A[j][i] != 'L') cmp = 0;
            if(A[i][j] == 'L' and A[j][i] != 'W') cmp = 0;
            if(A[i][j] == 'D' and A[j][i] != 'D') cmp = 0;
        }
    }

    cout << (cmp ? "correct" : "incorrect");
	
    return 0;
}


