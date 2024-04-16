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
    int a, b; cin >> a >> b;

    int c = a+1;
    while(true) {
        int tmp = c;

        int num = 0;
        int p10 = 1;

        while(tmp) {
            int d = tmp % 10;
            tmp /= 10;

            if(d == 4 or d == 7) {
                num = num + d * p10;
                p10 *= 10;
            }
        }

        if(num == b) break;

        c++;
    }

    cout << c << "\n";
	
    return 0;
}


