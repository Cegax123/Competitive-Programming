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
    int n, k; cin >> n >> k;
    int f[n];

    for(int i = 0; i < n; i++) {
        cin >> f[i];
    }

    const int maxf = 1e6;
    int cnt[maxf+1];
    memset(cnt, 0, sizeof(cnt));

    for(int i = 0; i < n; i++) {
        cnt[f[i]]++;
    }

    for(int i = maxf; i >= 0; i--) {
        int tmp = i;
        int sum = 0;
        while(tmp) {
            sum += tmp%10;
            tmp /= 10;
        }

        if(cnt[i] >= k or i == 0) {
            cout << sum << "\n";
            break;
        }

        cnt[i-sum] += cnt[i];
        k -= cnt[i];
    }


	//const int maxf = 1e6 + 1;
    //const int LOGN = 20;
    //vector<vi> go(maxf+1, vi(LOGN));

    //for(int i = 0; i <= maxf; i++) {
        //int sumd = 0;
        //int tmp = i;
        //while(tmp) {
            //sumd += tmp%10;
            //tmp /= 10;
        //}
        //go[i][0] = i-sumd;
    //}

    //for(int i = 1; i < LOGN; i++) {
        //for(int j = 0; j <= maxf; j++) {
            //go[j][i] = go[go[j][i-1]][i-1];
        //}
    //}

    //auto get_op = [&](int s, int t) {
        //int cnt = 0;
        //for(int i = LOGN-1; i >= 0; i--) {
            //if(go[s][i] > t) {
                //cnt += (1 << i);
                //s = go[s][i];
            //}
        //}

        //return cnt+1;
    //};

    //int l = 0, r = 1e6;

    //while(l < r) {
        //int m = (l+r) >> 1;

        //ll op = 0;

        //for(int i = 0; i < n; i++) {
            //if(f[i] > m) {
                //op += get_op(f[i], m);
            //}
        //}

        //if(op < k) r = m;
        //else l = m+1;
    //}

    //int sumd = 0;
    //while(l) {
        //sumd += l%10;
        //l /= 10;
    //}

    //cout << sumd << "\n";

    return 0;
}


