#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(const vector<int>& s) {
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}


int main() {
    int n, w; cin >> n >> w;

    if(w == 1) {
        cout << n << "\n";
        return 0;
    }

    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i) b[i-1] = a[i] - a[i-1];
    }

    int c[n], d[n];
    for(int i = 0; i < w; i++) {
        cin >> c[i];
        if(i) d[i-1] = c[i] - c[i-1];
    }

    vector<int> tot;

    for(int i = 0; i < w-1; i++) tot.push_back(d[i]);
    tot.push_back(-2e9-100);
    for(int i = 0; i < n-1; i++) tot.push_back(b[i]);

    //for(int x : tot) cout << x << " ";
    //cout << endl;

    vector<int> z = z_function(tot);

    int cnt = 0;

    for(int i = w; i < (int) z.size(); i++) {
        if(z[i] == w-1) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}
