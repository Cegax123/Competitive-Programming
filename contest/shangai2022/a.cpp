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
    string S, R;
    cin >> S >> R;

    int s[3];
    s[0] = (S[0]-'0') * 10 + (S[1]-'0');
    s[1] = (S[3]-'0') * 10 + (S[4]-'0');
    s[2] = (S[6]-'0') * 10 + (S[7]-'0');

    string r[3];
    r[0] += R[0];
    r[0] += R[1];

    r[1] += R[3];
    r[1] += R[4];

    r[2] += R[6];
    r[2] += R[7];
    
    auto compG = [&](int x, int i) {
        if(r[i][0] == 'G') {
            if(x / 10 != s[i] / 10) return false;
        }
        if(r[i][1] == 'G') {
            if(x % 10 != s[i] % 10) return false;
        }
        return true;
    };

    auto compPB = [&](int x, int i) {
        if(r[i][0] == 'P' or r[i][0] == 'B') {
            if(x / 10 == s[i] / 10) return false;
        }

        if(r[i][1] == 'P' or r[i][1] == 'B') {
            if(x % 10 == s[i] % 10) return false;
        }

        return true;
    };

    vector<string> ans;

     for(int i = 0; i <= 99; i++) {
         for(int j = 0; j <= 99; j++) {
            int k = i + j;
            if(k >= 100) continue;
            
            int n[3];
            n[0] = i;
            n[1] = j;
            n[2] = k;

            if(!compG(i, 0) or !compG(j, 1) or !compG(k, 2)) continue;
            if(!compPB(i, 0) or !compPB(j, 1) or !compPB(k, 2)) continue;

            int cntcurr[10];
            int cnt[10];

            memset(cnt, 0, sizeof(cnt));
            memset(cntcurr, 0, sizeof(cntcurr));



            bool rest[10];
            memset(rest, 0, sizeof(rest));
            
            for(int l = 0; l < 3; l++) {
                if(r[l][0] == 'B') {
                    rest[s[l]/10] = 1;
                }
                else if(r[l][0] == 'P') {
                    cnt[s[l]/10]++;
                }

                if(r[l][0] != 'G') {
                    cntcurr[n[l] / 10] ++;
                }

                if(r[l][1] == 'B') {
                    rest[s[l]%10] = 1;
                }
                else if(r[l][1] == 'P') cnt[s[l]%10]++;

                if(r[l][1] != 'G') {
                    cntcurr[n[l] % 10]++;
                }
            }

            bool cmp =1;
            for(int i = 0; i < 10; i++) {
                if(rest[i]) {
                    if(cntcurr[i] != cnt[i]) cmp = 0;
                }
                else if(cnt[i] > cntcurr[i]) cmp = 0;
            }

            if(cmp) {
                string currans;
                currans += (char) n[0] / 10 + '0';
                currans += (char) n[0] % 10 + '0';
                currans += '+';
                currans += (char) n[1] / 10 + '0';
                currans += (char) n[1] % 10 + '0';
                currans += '=';
                currans += (char) n[2] / 10 + '0';
                currans += (char) n[2] % 10 + '0';
                ans.pb(currans);
            }
         }
     }

     cout << ans.size() << "\n";

     for(string x : ans) {
         cout << x << "\n";
     }
	
    return 0;
}


