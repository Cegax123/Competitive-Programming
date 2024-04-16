#include<bits/stdc++.h>
using namespace std;

const int maxa = 1e5+5;
int cnt[maxa];
vector<int> fi(maxa, -1);

int main() {



    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = 0; i < n; i++) {
            if(fi[a[i]] == -1) fi[a[i]] = i;
            cnt[a[i]]++;
        }

        bool poss = 1;
        int mex;
        for(int i = 0; i < maxa; i++) {
            if(cnt[i] == 1) {
                poss = 0;
                break;
            }
            else if(cnt[i] == 0) {
                mex = i;
                break;
            }
        }


        if(!poss) {
            cout << -1 << "\n";
            for(int i = 0; i < n; i++) {
                cnt[a[i]] = 0;
                fi[a[i]] = -1;
            }


            continue;
        }

        if(mex == 0) {
            cout << 2 << "\n";
            cout << "1 1\n";
            cout << 2 << " " << n << "\n";

            for(int i = 0; i < n; i++) {
                cnt[a[i]] = 0;
                fi[a[i]] = -1;
            }


            continue;
        }

        int minl = -1;

        for(int i = 0; i < mex; i++) minl = max(minl, fi[i]);

        vector<int> cntr(mex, 0);

        for(int i = minl+1; i < n; i++) {
            if(a[i] < mex) cntr[a[i]]++;
        }

        for(int x : cntr) if(x == 0) poss = 0;

        if(!poss) {
            cout << -1 << "\n";
            for(int i = 0; i < n; i++) {
                cnt[a[i]] = 0;
                fi[a[i]] = -1;
            }


            continue;
        }

        cout << 2 << "\n";
        cout << 1 << " " << minl+1 << "\n";
        cout << minl+2 << " " << n << "\n";

        for(int i = 0; i < n; i++) {
            cnt[a[i]] = 0;
            fi[a[i]] = -1;
        }


    }



    return 0;
}
