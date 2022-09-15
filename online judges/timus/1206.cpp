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
    vi ans(2);
    
    ans[0] = 6;
    ans[1] = 3;

    for(int i = 1; i < k; i++) {
        int t = ans.size();

        vi temp;
        int carry = 0;
        
        for(int j = 0; j <= t; j++) {
            if(j == 0) {
                temp.pb((ans[0]*5) % 10);
                carry += (ans[0] * 5) / 10;
            }
            else if(j < t) {
                int sum = ans[j] * 5 + ans[j-1] * 5 + carry;
                temp.pb(sum%10);
                carry = sum / 10;
            }
            else {
                int sum = ans[j-1] * 5 + carry;
                temp.pb(sum%10);
                carry = sum / 10;
            }
        }

        ans = temp;

        if(carry) {
            while(carry) {
                ans.pb(carry%10);
                carry /= 10;
            }
        }
    }
    
    reverse(all(ans));

    for(int d : ans)
        cout << d;

    cout << "\n";
	
	return 0;
}

