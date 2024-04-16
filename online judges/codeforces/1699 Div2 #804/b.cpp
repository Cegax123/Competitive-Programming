#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        int b[n][m];

        for(int i = 0; i < n; i+=2) {
            for(int j = 0; j < m; j+=2) {
                int sum = i/2 + j/2;
                if(sum&1) {
                    b[i][j] = 0;
                    b[i+1][j] = 1;
                    b[i][j+1] = 1;
                    b[i+1][j+1] = 0;
                }
                else {
                    b[i][j] = 1;
                    b[i+1][j] = 0;
                    b[i][j+1] = 0;
                    b[i+1][j+1] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << b[i][j] << " ";
            }
            cout << "\n";
        }
    }
    

    return 0;
}
