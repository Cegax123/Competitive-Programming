#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll v[20];

int main() {
    int t; cin >> t;
    while(t--) {
        ll a, b, c; cin >> a >> b >> c;
        v[0] = a;
        v[1] = b;
        v[2] = c;
        v[3] = 1;
        v[4] = 0;
        v[5] = -1;
        v[6] = 1;
        v[7] = -a;
        v[8] = a;
        v[9] = a + b;
        v[10] = 0;
        v[11] = 0;
        v[12] = 1;

        do {
            v[11] = v[11] + v[1];
            v[10] += v[0];
            v[13] = v[10];
            v[14] = v[4];
            v[15] = v[4];

            ll diff1 = v[13] - (v[1]/2 + 1);
            if(diff1 >= 0) {
                ll t = (diff1 % v[1] == 0 ? diff1 / v[1] + 1 : (diff1 + v[1] - 1) / v[1]);
                v[13] -= t * v[1];
                v[14] += t * v[3];
                v[15] += t * v[1];
            }

            //while(2 * v[13] > v[1]) {
                //v[13] -= v[1];
                //v[14] += v[3];
                //v[15] += v[1];
            //}

            if(v[13] <= v[4]) {
                v[13] = v[4] - v[13];
            }

            v[17] = v[4];
            v[18] = v[3];
            

            v[17] += v[13];
            v[18] += v[3];

            ll diff2 = v[6]-v[18];

            if(diff2 >= 0) {
                ll t = (diff2 % v[3] == 0 ? diff2 / v[3] + 1 : (diff2 + v[3] - 1) / v[3]);
                
                v[17] += t * v[13];
                v[18] += t * v[3];
            }

            //do {
                //v[17] += v[13];
                //v[18] += v[3];
            //} while(v[18] <= v[6]);

            v[18] = v[3];

            v[17] -= v[9];
            v[18] += v[3];

            ll diff3 = v[12] - v[18];
            if(diff3 >= 0) {
                ll t = (diff3 % v[3] == 0 ? diff3 / v[3] + 1 : (diff3 + v[3] - 1) / v[3]);
                v[17] -= t * v[9];
                v[18] += t * v[3];
            }

            //do {
                //v[17] -= v[9];
                //v[18] += v[3];
            //} while(v[18] <= v[12]);

            if(v[17] < v[4]) {
                v[5] = v[14];
                v[6] = v[12];
                v[7] = v[15];
                v[8] = v[10];
                v[9] = v[13];
            }

            v[12] += v[3];
        } while(v[12] <= v[2]);
        cout << v[6] << endl;
    }


    return 0;
}
