#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<climits>
#include<complex>
#define mp make_pair
#define pb push_back
#define ll long long
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)

using namespace std;
const long double eps=1e-8;
const long double pi=acos(-1.0);
const long double inf=1e20;
const int maxp=1e5;
int dblcmp(long double d)
{
    if (fabs(d)<eps)return 0;
    return d>eps?1:-1;
}
inline long double sqr(long double x){return x*x;}
struct point
{
    long double x,y;
    point(){}
    point(long double _x,long double _y):
    x(_x),y(_y){};
    void input()
    {
        cin>>x>>y;
    }
    void output()
    {
        cout<<x<<" "<<y<<"\n";
    }
    bool operator==(point a)const
    {
        return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
    }
    bool operator<(point a)const
    {
        return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
    }
    long double len()
    {
        return hypot(x,y);
    }
    long double len2()
    {
        return x*x+y*y;
    }
    long double distance(point p)
    {
        return hypot(x-p.x,y-p.y);
    }
    point add(point p)
    {
        return point(x+p.x,y+p.y);
    }
    point sub(point p)
    {
        return point(x-p.x,y-p.y);
    }
    point mul(long double b)
    {
        return point(x*b,y*b);
    }
    point div(long double b)
    {
        return point(x/b,y/b);
    }
    long double dot(point p)
    {
        return x*p.x+y*p.y;
    }
    long double det(point p)
    {
        return x*p.y-y*p.x;
    }
    long double rad(point a,point b)
    {
        point p=*this;
        return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
    }
    point trunc(long double r)
    {
        long double l=len();
        if (!dblcmp(l))return *this;
        r/=l;
        return point(x*r,y*r);
    }
    point rotleft()
    {
        return point(-y,x);
    }
    point rotright()
    {
        return point(y,-x);
    }
    point rotate(point p,long double angle)//Rotar un ‡ngulo angle en sentido contrario a las agujas del reloj alrededor del punto p
    {
        point v=this->sub(p);
        long double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
};
struct line
{
    point a,b;
    line(){}
    line(point _a,point _b)
    {
        a=_a;
        b=_b;
    }
    bool operator==(line v)
    {
        return (a==v.a)&&(b==v.b);
    }
    //çngulo de inclinaci—n angle
    line(point p,long double angle)
    {
        a=p;
        if (dblcmp(angle-pi/2)==0)
        {
            b=a.add(point(0,1));
        }
        else
        {
            b=a.add(point(1,tan(angle)));
        }
    }
    //ax+by+c=0
    line(long double _a,long double _b,long double _c)
    {
        if (dblcmp(_a)==0)
        {
            a=point(0,-_c/_b);
            b=point(1,-_c/_b);
        }
        else if (dblcmp(_b)==0)
        {
            a=point(-_c/_a,0);
            b=point(-_c/_a,1);
        }
        else
        {
            a=point(0,-_c/_b);
            b=point(1,(-_c-_a)/_b);
        }
    }
    void input()
    {
        a.input();
        b.input();
    }
    void adjust()
    {
        if (b<a)swap(a,b);
    }
    long double length()
    {
        return a.distance(b);
    }
    long double angle()//inclinaci—n en l’nea recta 0<=angle<180
    {
        long double k=atan2(b.y-a.y,b.x-a.x);
        if (dblcmp(k)<0)k+=pi;
        if (dblcmp(k-pi)==0)k-=pi;
        return k;
    }
    // relaci—n punto y l’nea
    //1 en sentido antihorario
    //2 en el sentido de las agujas del reloj
    //3 paralelo
    int relation(point p)
    {
        int c=dblcmp(p.sub(a).det(b.sub(a)));
        if (c<0)return 1;
        if (c>0)return 2;
        return 3;
    }
    bool pointonseg(point p)
    {
        return dblcmp(p.sub(a).det(b.sub(a)))==0&&dblcmp(p.sub(a).dot(p.sub(b)))<=0;
    }
    bool parallel(line v)
    {
        return dblcmp(b.sub(a).det(v.b.sub(v.a)))==0;
    }
    //2 intersecci—n can—nica
    //1 intersecci—n no can—nica
    //0 disjunto
    int segcrossseg(line v)
    {
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        int d3=dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
        int d4=dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
        if ((d1^d2)==-2&&(d3^d4)==-2)return 2;
        return (d1==0&&dblcmp(v.a.sub(a).dot(v.a.sub(b)))<=0||
                d2==0&&dblcmp(v.b.sub(a).dot(v.b.sub(b)))<=0||
                d3==0&&dblcmp(a.sub(v.a).dot(a.sub(v.b)))<=0||
                d4==0&&dblcmp(b.sub(v.a).dot(b.sub(v.b)))<=0);
    }
    int linecrossseg(line v)//*this seg v line
    {
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        if ((d1^d2)==-2)return 2;
        return (d1==0||d2==0);
    }
    //0 paralelo
    //1 superposici—n
    //2 se cruzan
    int linecrossline(line v)
    {
        if ((*this).parallel(v))
        {
            return v.relation(a)==3;
        }
        return 2;
    }
    point crosspoint(line v)
    {
        long double a1=v.b.sub(v.a).det(a.sub(v.a));
        long double a2=v.b.sub(v.a).det(b.sub(v.a));
        return point((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
    }
    long double dispointtoline(point p)
    {
        return fabs(p.sub(a).det(b.sub(a)))/length();
    }
    long double dispointtoseg(point p)
    {
        if (dblcmp(p.sub(b).dot(a.sub(b)))<0||dblcmp(p.sub(a).dot(b.sub(a)))<0)
        {
            return min(p.distance(a),p.distance(b));
        }
        return dispointtoline(p);
    }
    point lineprog(point p)
    {
        return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a))/b.sub(a).len2()));
    }
    point symmetrypoint(point p)
    {
        point q=lineprog(p);
        return point(2*q.x-p.x,2*q.y-p.y);
    }
};
struct circle
{
    point p;
    long double r;
    circle(){}
    circle(point _p,long double _r):
    p(_p),r(_r){};
    circle(long double x,long double y,long double _r):
    p(point(x,y)),r(_r){};
    circle(point a,point b,point c)//circunferencia de un triangulo
    {
        p=line(a.add(b).div(2),a.add(b).div(2).add(b.sub(a).rotleft())).crosspoint(line(c.add(b).div(2),c.add(b).div(2).add(b.sub(c).rotleft())));
        r=p.distance(a);
    }
    circle(point a,point b,point c,bool t)//circulo inscrito de un triangulo
    {
        line u,v;
        long double m=atan2(b.y-a.y,b.x-a.x),n=atan2(c.y-a.y,c.x-a.x);
        u.a=a;
        u.b=u.a.add(point(cos((n+m)/2),sin((n+m)/2)));
        v.a=b;
        m=atan2(a.y-b.y,a.x-b.x),n=atan2(c.y-b.y,c.x-b.x);
        v.b=v.a.add(point(cos((n+m)/2),sin((n+m)/2)));
        p=u.crosspoint(v);
        r=line(a,b).dispointtoseg(p);
    }
    void input()
    {
        p.input();
        cin>>r;
    }
    void output()
    {
        cout<<p.x<<" "<<p.y<<" "<<r<<"\n";
    }
    bool operator==(circle v)
    {
        return ((p==v.p)&&dblcmp(r-v.r)==0);
    }
    bool operator<(circle v)const
    {
        return ((p<v.p)||(p==v.p)&&dblcmp(r-v.r)<0);
    }
    long double area()
    {
        return pi*sqr(r);
    }
    long double circumference()
    {
        return 2*pi*r;
    }
    //0 fuera del circulo
    //1 ronda
    //2 dentro del circulo
    int relation(point b)
    {
        long double dst=b.distance(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    int relationseg(line v)
    {
        long double dst=v.dispointtoseg(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    int relationline(line v)
    {
        long double dst=v.dispointtoline(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    //Por dos puntos a y b, dos circunferencias de radio r
    int getcircle(point a,point b,long double r,circle&c1,circle&c2)
    {
        circle x(a,r),y(b,r);
        int t=x.pointcrosscircle(y,c1.p,c2.p);
        if (!t)return 0;
        c1.r=c2.r=r;
        return t;
    }
    //tangente a la recta u, pasando por el punto q, una circunferencia de radio r1
    int getcircle(line u,point q,long double r1,circle &c1,circle &c2)
    {
        long double dis=u.dispointtoline(q);
        if (dblcmp(dis-r1*2)>0)return 0;
        if (dblcmp(dis)==0)
        {
            c1.p=q.add(u.b.sub(u.a).rotleft().trunc(r1));
            c2.p=q.add(u.b.sub(u.a).rotright().trunc(r1));
            c1.r=c2.r=r1;
            return 2;
        }
        line u1=line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
        line u2=line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
        circle cc=circle(q,r1);
        point p1,p2;
        if (!cc.pointcrossline(u1,p1,p2))cc.pointcrossline(u2,p1,p2);
        c1=circle(p1,r1);
        if (p1==p2)
        {
            c2=c1;return 1;
        }
        c2=circle(p2,r1);
        return 2;
    }
    //A su vez, la circunferencia de radio r1 es tangente a la recta u y v
    int getcircle(line u,line v,long double r1,circle &c1,circle &c2,circle &c3,circle &c4)
    {
        if (u.parallel(v))return 0;
        line u1=line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
        line u2=line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
        line v1=line(v.a.add(v.b.sub(v.a).rotleft().trunc(r1)),v.b.add(v.b.sub(v.a).rotleft().trunc(r1)));
        line v2=line(v.a.add(v.b.sub(v.a).rotright().trunc(r1)),v.b.add(v.b.sub(v.a).rotright().trunc(r1)));
        c1.r=c2.r=c3.r=c4.r=r1;
        c1.p=u1.crosspoint(v1);
        c2.p=u1.crosspoint(v2);
        c3.p=u2.crosspoint(v1);
        c4.p=u2.crosspoint(v2);
        return 4;
    }
    //Al mismo tiempo es tangente a las circunferencias disjuntas cx y cy.Una circunferencia de radio r1
    int getcircle(circle cx,circle cy,long double r1,circle&c1,circle&c2)
    {
        circle x(cx.p,r1+cx.r),y(cy.p,r1+cy.r);
        int t=x.pointcrosscircle(y,c1.p,c2.p);
        if (!t)return 0;
        c1.r=c2.r=r1;
        return t;
    }
    int pointcrossline(line v,point &p1,point &p2)//Para intersecar con un segmento de l’nea, primero debe juzgar las relaciones
    {
        if (!(*this).relationline(v))return 0;
        point a=v.lineprog(p);
        long double d=v.dispointtoline(p);
        d=sqrt(r*r-d*d);
        if (dblcmp(d)==0)
        {
            p1=a;
            p2=a;
            return 1;
        }
        p1=a.sub(v.b.sub(v.a).trunc(d));
        p2=a.add(v.b.sub(v.a).trunc(d));
        return 2;
    }
    //5 separaci—n
    //4 circuncisi—n
    //3 se cruzan
    //2 interviene
    //1 contiene
    int relationcircle(circle v)
    {
        long double d=p.distance(v.p);
        if (dblcmp(d-r-v.r)>0)return 5;
        if (dblcmp(d-r-v.r)==0)return 4;
        long double l=fabs(r-v.r);
        if (dblcmp(d-r-v.r)<0&&dblcmp(d-l)>0)return 3;
        if (dblcmp(d-l)==0)return 2;
        if (dblcmp(d-l)<0)return 1;
    }
    int pointcrosscircle(circle v,point &p1,point &p2)
    {
        int rel=relationcircle(v);
        if (rel==1||rel==5)return 0;
        long double d=p.distance(v.p);
        long double l=(d+(sqr(r)-sqr(v.r))/d)/2;
        long double h=sqrt(sqr(r)-sqr(l));
        p1=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotleft().trunc(h)));
        p2=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotright().trunc(h)));
        if (rel==2||rel==4)
        {
            return 1;
        }
        return 2;
    }
    //Hacer la tangente del c’rculo despuŽs de un punto (primero juzgar la relaci—n entre el punto y el c’rculo)
    int tangentline(point q,line &u,line &v)
    {
        int x=relation(q);
        if (x==2)return 0;
        if (x==1)
        {
            u=line(q,q.add(q.sub(p).rotleft()));
            v=u;
            return 1;
        }
        long double d=p.distance(q);
        long double l=sqr(r)/d;
        long double h=sqrt(sqr(r)-sqr(l));
        u=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotleft().trunc(h))));
        v=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotright().trunc(h))));
        return 2;
    }
    long double areacircle(circle v)
    {
        int rel=relationcircle(v);
        if (rel>=4)return 0.0;
        if (rel<=2)return min(area(),v.area());
        long double d=p.distance(v.p);
        long double hf=(r+v.r+d)/2.0;
        long double ss=2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
        long double a1=acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
        a1=a1*r*r;
        long double a2=acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d));
        a2=a2*v.r*v.r;
        return a1+a2-ss;
    }
    long double areatriangle(point a,point b)
    {
        if (dblcmp(p.sub(a).det(p.sub(b))==0))return 0.0;
        point q[5];
        int len=0;
        q[len++]=a;
        line l(a,b);
        point p1,p2;
        if (pointcrossline(l,q[1],q[2])==2)
        {
            if (dblcmp(a.sub(q[1]).dot(b.sub(q[1])))<0)q[len++]=q[1];
            if (dblcmp(a.sub(q[2]).dot(b.sub(q[2])))<0)q[len++]=q[2];
        }
        q[len++]=b;
        if (len==4&&(dblcmp(q[0].sub(q[1]).dot(q[2].sub(q[1])))>0))swap(q[1],q[2]);
        long double res=0;
        int i;
        for (i=0;i<len-1;i++)
        {
            if (relation(q[i])==0||relation(q[i+1])==0)
            {
                long double arg=p.rad(q[i],q[i+1]);
                res+=r*r*arg/2.0;
            }
            else
            {
                res+=fabs(q[i].sub(p).det(q[i+1].sub(p))/2.0);
            }
        }
        return res;
    }
};
struct polygon
{
    int n;
    point p[maxp];
    line l[maxp];
    void input()
    {
        n=4;
        for (int i=0;i<n;i++)
        {
            p[i].input();
        }
    }
    void add(point q)
    {
        p[n++]=q;
    }
    void getline()
    {
        for (int i=0;i<n;i++)
        {
            l[i]=line(p[i],p[(i+1)%n]);
        }
    }
    struct cmp
    {
        point p;
        cmp(const point &p0){p=p0;}
        bool operator()(const point &aa,const point &bb)
        {
            point a=aa,b=bb;
            int d=dblcmp(a.sub(p).det(b.sub(p)));
            if (d==0)
            {
                return dblcmp(a.distance(p)-b.distance(p))<0;
            }
            return d>0;
        }
    };
    void norm()
    {
        point mi=p[0];
        for (int i=1;i<n;i++)mi=min(mi,p[i]);
        sort(p,p+n,cmp(mi));
    }
    void getconvex(polygon &convex)
    {
        int i,j,k;
        sort(p,p+n);
        convex.n=n;
        for (i=0;i<min(n,2);i++)
        {
            convex.p[i]=p[i];
        }
        if (n<=2)return;
        int &top=convex.n;
        top=1;
        for (i=2;i<n;i++)
        {
            while (top&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0)
                top--;
            convex.p[++top]=p[i];
        }
        int temp=top;
        convex.p[++top]=p[n-2];
        for (i=n-3;i>=0;i--)
        {
            while (top!=temp&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0)
                top--;
            convex.p[++top]=p[i];
        }
    }
    bool isconvex()
    {
        bool s[3];
        memset(s,0,sizeof(s));
        int i,j,k;
        for (i=0;i<n;i++)
        {
            j=(i+1)%n;
            k=(j+1)%n;
            s[dblcmp(p[j].sub(p[i]).det(p[k].sub(p[i])))+1]=1;
            if (s[0]&&s[2])return 0;
        }
        return 1;
    }
    //3 en punto
    //2 lados
    //1 adentro
    //0 externo
    int relationpoint(point q)
    {
        int i,j;
        for (i=0;i<n;i++)
        {
            if (p[i]==q)return 3;
        }
        getline();
        for (i=0;i<n;i++)
        {
            if (l[i].pointonseg(q))return 2;
        }
        int cnt=0;
        for (i=0;i<n;i++)
        {
            j=(i+1)%n;
            int k=dblcmp(q.sub(p[j]).det(p[i].sub(p[j])));
            int u=dblcmp(p[i].y-q.y);
            int v=dblcmp(p[j].y-q.y);
            if (k>0&&u<0&&v>=0)cnt++;
            if (k<0&&v<0&&u>=0)cnt--;
        }
        return cnt!=0;
    }
    //1 longitud es positiva dentro del pol’gono
    //2 interseca o es paralelo al borde
    //0 sin intersecci—n
    int relationline(line u)
    {
        int i,j,k=0;
        getline();
        for (i=0;i<n;i++)
        {
            if (l[i].segcrossseg(u)==2)return 1;
            if (l[i].segcrossseg(u)==1)k=1;
        }
        if (!k)return 0;
        vector<point>vp;
        for (i=0;i<n;i++)
        {
            if (l[i].segcrossseg(u))
            {
                if (l[i].parallel(u))
                {
                    vp.pb(u.a);
                    vp.pb(u.b);
                    vp.pb(l[i].a);
                    vp.pb(l[i].b);
                    continue;
                }
                vp.pb(l[i].crosspoint(u));
            }
        }
        sort(vp.begin(),vp.end());
        int sz=vp.size();
        for (i=0;i<sz-1;i++)
        {
            point mid=vp[i].add(vp[i+1]).div(2);
            if (relationpoint(mid)==1)return 1;
        }
        return 2;
    }
    //La l’nea recta u corta el lado izquierdo del pol’gono convexo
    //Presta atenci—n a la direcci—n de la l’nea
    void convexcut(line u,polygon &po)
    {
        int i,j,k;
        int &top=po.n;
        top=0;
        for (i=0;i<n;i++)
        {
            int d1=dblcmp(p[i].sub(u.a).det(u.b.sub(u.a)));
            int d2=dblcmp(p[(i+1)%n].sub(u.a).det(u.b.sub(u.a)));
            if (d1>=0)po.p[top++]=p[i];
            if (d1*d2<0)po.p[top++]=u.crosspoint(line(p[i],p[(i+1)%n]));
        }
    }
    long double getcircumference()
    {
        long double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=p[i].distance(p[(i+1)%n]);
        }
        return sum;
    }
    long double getarea()
    {
        long double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=p[i].det(p[(i+1)%n]);
        }
        return fabs(sum)/2;
    }
    bool getdir()//1 significa en sentido antihorario, 0 significa en sentido horario
    {
        long double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=p[i].det(p[(i+1)%n]);
        }
        if (dblcmp(sum)>0)return 1;
        return 0;
    }
    point getbarycentre()
    {
        point ret(0,0);
        long double area=0;
        int i;
        for (i=1;i<n-1;i++)
        {
            long double tmp=p[i].sub(p[0]).det(p[i+1].sub(p[0]));
            if (dblcmp(tmp)==0)continue;
            area+=tmp;
            ret.x+=(p[0].x+p[i].x+p[i+1].x)/3*tmp;
            ret.y+=(p[0].y+p[i].y+p[i+1].y)/3*tmp;
        }
        if (dblcmp(area))ret=ret.div(area);
        return ret;
    }
    long double areaintersection(polygon po)
    {
        return 0;
    }
    long double areaunion(polygon po)
    {
        return getarea()+po.getarea()-areaintersection(po);
    }
    long double areacircle(circle c)
    {
        int i,j,k,l,m;
        long double ans=0;
        for (i=0;i<n;i++)
        {
            int j=(i+1)%n;
            if (dblcmp(p[j].sub(c.p).det(p[i].sub(c.p)))>=0)
            {
                ans+=c.areatriangle(p[i],p[j]);
            }
            else
            {
                ans-=c.areatriangle(p[i],p[j]);
            }
        }
        return fabs(ans);
    }
    //Relaci—n entre pol’gono y c’rculo
    //0 parte esta fuera del circulo
    //1 es tangente a un borde del c’rculo
    //2 est‡ completamente dentro del c’rculo
    int relationcircle(circle c)
    {
        getline();
        int i,x=2;
        if (relationpoint(c.p)!=1)return 0;
        for (i=0;i<n;i++)
        {
            if (c.relationseg(l[i])==2)return 0;
            if (c.relationseg(l[i])==1)x=1;
        }
        return x;
    }
    void find(int st,point tri[],circle &c)
    {
        if (!st)
        {
            c=circle(point(0,0),-2);
        }
        if (st==1)
        {
            c=circle(tri[0],0);
        }
        if (st==2)
        {
            c=circle(tri[0].add(tri[1]).div(2),tri[0].distance(tri[1])/2.0);
        }
        if (st==3)
        {
            c=circle(tri[0],tri[1],tri[2]);
        }
    }
    void solve(int cur,int st,point tri[],circle &c)
    {
        find(st,tri,c);
        if (st==3)return;
        int i;
        for (i=0;i<cur;i++)
        {
            if (dblcmp(p[i].distance(c.p)-c.r)>0)
            {
                tri[st]=p[i];
                solve(i,st+1,tri,c);
            }
        }
    }
    circle mincircle()//cobertura m’nima del c’rculo del conjunto de puntos
    {
        random_shuffle(p,p+n);
        point tri[4];
        circle c;
        solve(n,0,tri,c);
        return c;
    }
    int circlecover(long double r)//cobertura del c’rculo unitario
    {
        int ans=0,i,j;
        vector<pair<long double,int> >v;
        for (i=0;i<n;i++)
        {
            v.clear();
            for (j=0;j<n;j++)if (i!=j)
            {
                point q=p[i].sub(p[j]);
                long double d=q.len();
                if (dblcmp(d-2*r)<=0)
                {
                    long double arg=atan2(q.y,q.x);
                    if (dblcmp(arg)<0)arg+=2*pi;
                    long double t=acos(d/(2*r));
                    v.push_back(make_pair(arg-t+2*pi,-1));
                    v.push_back(make_pair(arg+t+2*pi,1));
                }
            }
            sort(v.begin(),v.end());
            int cur=0;
            for (j=0;j<v.size();j++)
            {
                if (v[j].second==-1)++cur;
                else --cur;
                ans=max(ans,cur);
            }
        }
        return ans+1;
    }
    int pointinpolygon(point q)//test de si el punto est‡ dentro de un pol’gono convexo
    {
        if (getdir())reverse(p,p+n);
        if (dblcmp(q.sub(p[0]).det(p[n-1].sub(p[0])))==0)
        {
            if (line(p[n-1],p[0]).pointonseg(q))return n-1;
            return -1;
        }
        int low=1,high=n-2,mid;
        while (low<=high)
        {
            mid=(low+high)>>1;
            if (dblcmp(q.sub(p[0]).det(p[mid].sub(p[0])))>=0&&dblcmp(q.sub(p[0]).det(p[mid+1].sub(p[0])))<0)
            {
                polygon c;
                c.p[0]=p[mid];
                c.p[1]=p[mid+1];
                c.p[2]=p[0];
                c.n=3;
                if (c.relationpoint(q))return mid;
                return -1;
            }
            if (dblcmp(q.sub(p[0]).det(p[mid].sub(p[0])))>0)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return -1;
    }
};

struct halfplane:public line
{
    long double angle;
    halfplane(){}
    //Representa el semiplano del vector a->b en sentido antihorario (izquierda)
    halfplane(point _a,point _b)
    {
        a=_a;
        b=_b;
    }
    halfplane(line v)
    {
        a=v.a;
        b=v.b;
    }
    void calcangle()
    {
        angle=atan2(b.y-a.y,b.x-a.x);
    }
    bool operator<(const halfplane &b)const
    {
        return angle<b.angle;
    }
};
struct halfplanes
{
    int n;
    halfplane hp[maxp];
    point p[maxp];
    int que[maxp];
    int st,ed;
    void push(halfplane tmp)
    {
        hp[n++]=tmp;
    }
    void unique()
    {
        int m=1,i;
        for (i=1;i<n;i++)
        {
            if (dblcmp(hp[i].angle-hp[i-1].angle))hp[m++]=hp[i];
            else if (dblcmp(hp[m-1].b.sub(hp[m-1].a).det(hp[i].a.sub(hp[m-1].a))>0))hp[m-1]=hp[i];
        }
        n=m;
    }
    bool halfplaneinsert()
    {
        int i;
        for (i=0;i<n;i++)hp[i].calcangle();
        sort(hp,hp+n);
        unique();
        que[st=0]=0;
        que[ed=1]=1;
        p[1]=hp[0].crosspoint(hp[1]);
        for (i=2;i<n;i++)
        {
            while (st<ed&&dblcmp((hp[i].b.sub(hp[i].a).det(p[ed].sub(hp[i].a))))<0)ed--;
            while (st<ed&&dblcmp((hp[i].b.sub(hp[i].a).det(p[st+1].sub(hp[i].a))))<0)st++;
            que[++ed]=i;
            if (hp[i].parallel(hp[que[ed-1]]))return false;
            p[ed]=hp[i].crosspoint(hp[que[ed-1]]);
        }
        while (st<ed&&dblcmp(hp[que[st]].b.sub(hp[que[st]].a).det(p[ed].sub(hp[que[st]].a)))<0)ed--;
        while (st<ed&&dblcmp(hp[que[ed]].b.sub(hp[que[ed]].a).det(p[st+1].sub(hp[que[ed]].a)))<0)st++;
        if (st+1>=ed)return false;
        return true;
    }
    void getconvex(polygon &con)
    {
        p[st]=hp[que[st]].crosspoint(hp[que[ed]]);
        con.n=ed-st+1;
        int j=st,i=0;
        for (;j<=ed;i++,j++)
        {
            con.p[i]=p[j];
        }
    }
};

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cout << setprecision(12) << fixed;
	int n;
    long double d;
    cin>>n>>d;
    vector<point> p(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        p[i]=point(x,y);
    }
    reverse(all(p));;
    long double l=0,r=3e7;
    int niter=60;
    while(niter--){
        long double m=(l+r)/2;
        halfplanes hps;
        hps.n=0;
        for(int i=0;i<n;i++){
            point v=p[(i+1)%n].sub(p[i]);
            v=v.rotleft().trunc(m);
            halfplane hp(p[i].add(v),p[(i+1)%n].add(v));
            hps.push(hp);
        }
        /*cout<<hps.n<<"\n";
        for(int i=0;i<hps.n;i++){
        	cout<<hps.hp[i].a.x<<" "<<hps.hp[i].a.y<<"\n";
        	cout<<hps.hp[i].b.x<<" "<<hps.hp[i].b.y<<"\n";
        }*/
        bool ok=hps.halfplaneinsert();
        //cout<<"kek "<<ok<<"\n";
        if(ok){
        	
        	polygon ch;
        	ch.n=0;
            hps.getconvex(ch);
            auto maxd=[&](long double angle){
                long double minx=1e8,maxx=-1e8;
                for(int i=0;i<ch.n;i++){
                    long double x=ch.p[i].rotate(point(0,0),angle).x;
                    minx=min(minx,x);
                    maxx=max(maxx,x);
                }
                return maxx-minx;
            };
            long double lo=0,hi=pi;
            int kek=20;
            while(kek--){
                long double m1=(lo*2+hi)/3,m2=(lo+hi*2)/3;
                if(maxd(m1)<maxd(m2)) lo=m1;
                else hi=m2;
            }
            ok=dblcmp(maxd(lo)-d)>=0;
        }
        if(ok) l=m;
        else r=m;
    }
    cout<<l<<"\n";
	return 0;
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* bitwise and boolean operations
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

