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
    int k; cin >> k;
    int n = 1;

    while(k) {
        int sum = 0;
        int tmp = n;

        while(tmp) {
            sum += tmp % 10;
            tmp /= 10;
        }

        if(sum == 10) k--;

        if(k) n++;
    }

    cout << n << "\n";
	
    return 0;
}


