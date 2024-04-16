#include<bits/stdc++.h>
using namespace std;

int v[3];

int obt_inter(int a1, int a2, int b1, int b2, int c1, int c2) {
    int lenX = max(0, min(a1+7, a2+7)-max(a2, a1));
    int lenY = max(0, min(b1+7, b2+7)-max(b2, b1));
    int lenZ = max(0, min(c1+7, c2+7)-max(c2, c1));

    return lenX*lenY*lenZ;
}

bool  obt_vol(int a1, int a2, int a3, int b1, int b2, int b3, int c1, int c2, int c3) {
    int total1 = 3 * 343;
    int total2 = obt_inter(a1, a2, b1, b2, c1, c2) + obt_inter(a1, a3, b1, b3, c1, c3) + obt_inter(a2, a3, b2, b3, c2, c3);
    
    int lenX = max(0, min({a1+7, a2+7, a3+7}) - max({a1, a2, a3}));
    int lenY = max(0, min({b1+7, b2+7, b3+7}) - max({b1, b2, b3}));
    int lenZ = max(0, min({c1+7, c2+7, c3+7}) - max({c1, c2, c3}));

    int total3 = lenX*lenY*lenZ;

    int cv3 = total3;
    int cv2 = total2 - 3 * cv3;
    int cv1 = total1 - 2 * cv2 - 3 * cv3;

    if(cv1 == v[0] and cv2 == v[1] and cv3 == v[2]) return true;
    return false;
}

int main() {
    cin >> v[0] >> v[1] >> v[2];

    int a = 0, b = 0, c = 0;

    for(int a2 = -10; a2 <= 10; a2++) {
        for(int b2 = -10; b2 <= 10; b2++) {
            for(int c2 = -10; c2 <= 10; c2++) {
                for(int a3 = -10; a3 <= 10; a3++) {
                    for(int b3 = -10; b3 <= 10; b3++) {
                        for(int c3 = -10; c3 <= 10; c3++) {
                            if(obt_vol(a, a2, a3, b, b2, b3, c, c2, c3)) {
                                cout << "Yes\n";
                                cout << a << " " << b << " " << c << " " << a2 << " " << b2 << " " << c2 << " " << a3 << " " << b3 << " " << c3 << "\n";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << "No\n";

    return 0;
}
