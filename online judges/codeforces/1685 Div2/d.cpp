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
    int t; cin >> t;
    while(t--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        string s; cin >> s;
        int n = s.size();

        bool cmp = 1;
        int sumA = 0, sumB = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'A') sumA++;
            else sumB++;
        }

        if(sumA != a + c + d or sumB != b + c + d) {
            cout << "NO\n";
            continue;
        }

        if(n == 1) {
            cout << "YES\n";
            continue;
        }

        vi p(n, 0);

        for(int i = 0; i < n-1; i++) {
            if(s[i] == 'A' and s[i+1] == 'B') p[i] = 1;
            else if(s[i] == 'B' and s[i+1] == 'A') p[i] = -1;
            else p[i] = 0;
        }

        p[n-1] = 0;

        vi L(n, 0), R(n, 0);
        vi mL(n, 0), mR(n, 0);
        int target = c-d;

        L[0] += p[0];
        R[0] += p[0];

        if(L[0] > 0) L[0] = 0;
        if(R[0] < 0) R[0] = 0;

        L[1] += p[1];
        R[1] += p[1];

        if(L[1] > 0) L[1] = 0;
        if(R[1] < 0) R[1] = 0;

        mL[0] = L[0], mR[0] = R[0];
        mL[1] = min(L[0], L[1]), mR[1] = max(R[0], R[1]);

        for(int i = 2; i < n; i++) {
            L[i] = mL[i-2] + p[i];
            R[i] = mR[i-2] + p[i];

            if(L[i] > 0) L[i] = 0;
            if(R[i] < 0) R[i] = 0;

            mL[i] = min(mL[i], L[i]);
            mR[i] = max(mR[i], R[i]);
        }

        cmp = 0;
        for(int i = 0; i < n; i++) {
            if(target <= mR[i] and target >= mL[i])
                cmp = 1;
        }

        cout << (cmp ? "YES\n" : "NO\n");
    }

   
    return 0;
}


