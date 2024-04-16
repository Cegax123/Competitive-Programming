#include<bits/stdc++.h>
using namespace std;
int main(){
    int x1,y1,x2,y2,v1,v2,v3;
    cin>>x1>>y1>>v1>>x2>>y2>>v2>>v3;
    double t1=sqrt(x1*x1+y1*y1)/v1;
    double t2=sqrt(x2*x2+y2*y2)/v2;
    cout<<fixed<<setprecision(10)<<max(t1,t2)*v3<<"\n";
    return 0;
}
