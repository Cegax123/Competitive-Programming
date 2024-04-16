#include<bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
   return uniform_int_distribution<long long>(l,r)(rng);
}

int main() {
    cout << 1 << "\n";
    int n = 14;
    cout << n << "\n";

    for(int i = 1; i <= n; i++) {
        cout << random(0, (int) 1e6) << " ";
    }



    return 0;
}
