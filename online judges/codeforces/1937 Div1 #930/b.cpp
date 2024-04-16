#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;

typedef long long ll;

ll ans[maxn];
int cntR[maxn], cntL[maxn];
vector<ll> pL, pR;
int bef[maxn], nxt[maxn];

void solve(const string& s, bool rev) {
    int n = s.size();
    cntR[0] = s[0] == '>';
    for(int i = 1; i < (int) s.size(); i++) {
        cntR[i] = cntR[i-1];
        cntR[i] += s[i] == '>';
    }

    cntL[(int) s.size()-1] = s.back() == '<';

    for(int i = (int) s.size()-2; i >= 0; i--) {
        cntL[i] = cntL[i+1];
        cntL[i] += s[i] == '<';
    }

    pL.clear(); pR.clear();
    int last = -1; 

    for(int i = 0; i < (int) s.size(); i++) {
        if(s[i] == '>') {
            continue;
        }

        if(i == 0) bef[i] = -1;
        else bef[i] = bef[i-1];
        
        if(pR.empty()) pR.push_back(i-last);
        else pR.push_back(pR.back() + i-last);
        last = i;
   }

    if(pR.empty()) pR.push_back(n-last);
    else pR.push_back(pR.back() + n - last);

   for(int i = 0; i < (int) s.size(); i++) {
       if(i == 0 or s[i-1] == '>') bef[i] = i-1;
       else bef[i] = bef[i-1];
   }

   for(int i = (int) s.size(); i >= 0; i--) {
       if(i == (int) s.size() - 1 or s[i+1] == '<') nxt[i] = i+1;
       else nxt[i] = nxt[i+1];
   }

    for(int i = 1; i < (int) pR.size(); i++) {
        pR[i] += pR[i-1];
    }
    last = n;
    for(int i = (int) s.size(); i >= 0; i--) {
        if(s[i] == '<') {
            continue;
        }

        if(pL.empty()) pL.push_back(last-i);
        else pL.push_back(pL.back() + last-i);
        last = i;
    }

    if(pL.empty()) pL.push_back(last+1);
    else pL.push_back(pL.back() + last + 1);

    for(int i = 1; i < (int) pL.size(); i++) {
        pL[i] += pL[i-1];
    }

    for(int i = 0; i < n; i++) {
        if(s[i] == '<') continue;

        int pos = (rev ? n-1-i : i);
        ans[pos] = 0;


        int lft = cntR[i] - 1;
        int rgt = cntL[i];

        int len = 0;

        if(lft >= rgt) len = 1 + 2 * rgt;
        else len = 2 * (lft+1);

        int d2 = nxt[i] - i;
        int d1 = i - bef[i];

        ans[pos] += d2 * len;
        ans[pos] += d1 * (len-1);

        swap(lft, rgt);

        if(lft >= 1) {
            if((len-1) / 2 - 1 >= 0) ans[pos] += 2ll * (pR[lft - 1 + (len-1)/2 - 1] - pR[lft - 1]);


            if(len % 2 == 1) {
                int add = lft - 1 + len / 2;

                ans[pos] += pR[add];
                if(add-1 >= 0) ans[pos] -= 2 * pR[add-1];
                if(add-2 >= 0) ans[pos] += pR[add-2];
                //if(add > lft-1) ans[pos] += pR[add] - pR[add-1] - (pR[add-1] - pR[add-2]);

            }
        }

        if(len >= 2) {
            len --;
            rgt++;

            if((len-1) / 2 - 1 >= 0) ans[pos] += 2ll * (pL[rgt - 1 + (len-1) / 2 - 1] - pL[rgt-1]);


            if(len % 2 == 1) {
                int add = rgt - 1 + len / 2;

                ans[pos] += pL[add];
                if(add-1 >= 0) ans[pos] -= 2 * pL[add-1];
                if(add-2 >= 0) ans[pos] += pL[add-2];
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        solve(s, false);

        reverse(s.begin(), s.end());
        for(char& c : s) {
            if(c == '>') c = '<';
            else c = '>';
        }

        solve(s, true);

        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;
    }



    return 0;
}
