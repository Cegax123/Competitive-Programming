#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5;

double dealer[maxn];
double pdealer[maxn];
double ppdealer[maxn];
double rest[maxn];

double player[maxn];

double get_sum(int i, int j) {
    if(i > j) return 0.0;
    return pdealer[j] - (i == 0 ? 0 : pdealer[i-1]);
}

double pget_sum(int i, int j) {
    if(i > j) return 0.0;
    return ppdealer[j] - (i == 0 ? 0 : ppdealer[i-1]);
}

int main() {


    int n, l, d; cin >> n >> l >> d;

    dealer[0] = 1.0;
    double curr = 0.0;

    for(int i = 0; i < l + d; i++) {
        curr -= rest[i];
        dealer[i] += curr;

        if(i < l) {
            curr += dealer[i] / d;
            rest[i + d + 1] += dealer[i] / d;
        }
    }

    pdealer[l] = dealer[l];
    for(int i = l+1; i < maxn; i++) {
        pdealer[i] = pdealer[i-1] + dealer[i];
    }

    ppdealer[l] = pdealer[l];
    for(int i = l+1; i < maxn; i++) {
        ppdealer[i] = ppdealer[i-1] + pdealer[i];
    }

    double secure = get_sum(n+1, l+d-1);

    for(int i = 0; i < maxn; i++) rest[i] = 0.0;

    double global = 0.0;

    player[0] = 1;
    double local = secure;
    global = local;
    curr = 0.0;

    for(int i = 0; i <= n; i++) {
        curr -= rest[i];
        player[i] += curr;

        local -= secure * player[i];
        local -= get_sum(l, i-1) * player[i];


        int cnt = n-i;
        local += secure * cnt * player[i] / d;
        local += pget_sum(i, min(i+d, n) - 1) * player[i] / d;

        global = max(global, local);
        
        
        curr += player[i] / d;
        rest[i + d + 1] += player[i] / d;
    }

    cout << setprecision(12) << fixed;
    cout << global << "\n";

    return 0;
}
