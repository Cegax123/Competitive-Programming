#include<bits/stdc++.h>
using namespace std;
int main(){

    for(int i = 1; i <= 20; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j;
            if(i != j) cout << " ";
        }
        cout << "\n";
    }

    //for(int i = 1; i <= 20; i++) {
        //vector<int> v;

        //for(int j = 1; j <= i; j++) v.push_back(j);

        //bool cmp = 1;
        //for(int j = 0; j < i; j++) {
            //for(int k = j+1; k < i; k++) {
                //int diff = min(k-j, i-1-k+1+j);

                //if(diff < __gcd(v[j], v[k])) {
                    //cmp = 0;
                //}
            //}
        //}

        //if(cmp) {
            //for(int x : v) cout << x << " ";
        //}
        //cout << endl;
    //}
    

    return 0;
}
