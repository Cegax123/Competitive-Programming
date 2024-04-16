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

int n, k;
const int maxn = 10;
string s[maxn];
bool used[maxn];
int ans = 1e9;
int nums[maxn];

void backtrack(int pos=0) {
    if(pos == k) {
        //cout << endl;
        ans = min(ans, *max_element(nums, nums+n) - *min_element(nums, nums+n));
        return;
    }

    for(int i = 0; i < k; i++) {
        if(used[i]) continue;

        for(int j = 0; j < n; j++) 
            nums[j] = nums[j] * 10 + (s[j][i] - '0');

        used[i] = 1;

        backtrack(pos+1);


        used[i] = 0;
        for(int j = 0; j < n; j++)
            nums[j] /= 10;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> s[i];

    backtrack();
    cout << ans << "\n";
	
    return 0;
}


