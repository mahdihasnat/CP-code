///****In the name of Allah, most Gracious, most Compassionate****//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define NL cout<<"\n";
#define ALL(a) a.begin(), a.end()
#define DBG(a) cout<< #a <<" --> "<<(a)<<endl;
#define FastIO ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
#define IN freopen("input.txt","r+",stdin)
#define OUT freopen("output.txt","w+",stdout)

template < class T1,class T2>
ostream operator <<(ostream os, pair < T1,T2 > p)
{
    os<<"{"<<p.first<<","<<p.second<<"}";
    return os;
}

int N=3e5+5;
int oo=1e9+7;


typedef double ftype;
struct PT
{
    ftype x,y;
    PT operator + (PT  p)
    {
        return  {x+p.x, y+p.y};
    }
    PT operator - (PT  p)
    {
        return  {x-p.x, y-p.y};
    }
    PT operator * (ftype  d)
    {
        return  {x*d, y*d};
    }
    PT operator / (ftype  d)
    {
        assert(d!=0);
        return  {x/d, y/d};
    }
    bool operator==(PT  p)
    {
        return x==p.x && y == p.y;
    }
    bool operator!=(PT  p)
    {
        return !(*this == p);
    }
    PT(ftype x = 0, ftype y=0):x(x),y(y) { }
};
ostream & operator<<(ostream &os,PT const& p)
{
    return os<<"< "<<p.x<<" , "<<p.y<<" >";
}
ftype sq(PT  p)
{
    return p.x*p.x+p.y*p.y;
}
ftype abs(PT  p)
{
    return sqrt(sq(p));
}
ftype arg(PT p)
{
    return atan2(p.y,p.x); /// (-PI , PI]
}
template<typename TT>
int sgn(TT x)
{
    return (TT(0)<x) - (x<TT(0));
}
PT translate( PT v, PT p)
{
    return p+v;
}
PT scale(PT  c, ftype  factor, PT p)
{
    return c+(p-c)*factor;
}
PT rot(PT  p, double  a)
{
    return { p.x*cos(a)-p.y*sin(a), p.x*sin(a)+ p.y*cos(a)};
}
PT perp(PT  p)
{
    return {-p.y, p.x};
}
ftype dot(PT  v, PT  w)
{
    return v.x*w.x+v.y*w.y;
}
bool isPerp(PT  v, PT  w)
{
    return dot(v,w)==0 ;
}
ftype angle(PT  v, PT  w)
{
    double cosTheta = dot(v,w)/abs(v)/abs(w);
    return acos(max(-1.0,min(1.0,cosTheta)));
}
ftype cross(PT v, PT w) /// v*w
{
    return v.x*w.y-v.y*w.x;
}
ftype orient(PT a, PT b, PT c)
/*
    is positive if when going from A to B to C we turn left , negative if we turn right , and zero if A ,B ,C are collinear
*/
{
    return cross(b-a, c-a);
}

bool isAngle(PT a, PT b,PT c,PT p)  /// checks if p is in angle <CAB
{
    assert(orient(a,b, c)!= 0);
    if(orient(a,b,c)<0) swap(b,c);
    return orient(a,b,p)>=0 && orient(a,c,p)<=0 ;
}

////**** LINE *****////

struct LINE
{
    PT v ;
    ftype c;
    /// from direction vector v ,and offset c
    LINE( PT v,ftype c):v(v), c(c) { }
    /// from equation ax+ by  = c
    LINE(ftype a,ftype b,ftype c) : v(b,-a),c(c) {}
    /// from points p and q
    LINE (PT p, PT q) : v(q-p), c(cross(v,p)) {}

    int side(PT p)
    {
        return  cross(v,p)-c ;
    }
    ftype dist(PT p )
    {
        return 1.0*abs(side(p))/abs(v);
    }
    ftype sqDist(PT p)
    {
        return side(p)*side(p)/(double) sq(v);
    }
    LINE perpThrough(PT p )
    {
        return {p,p+perp(v)};
    }
    bool cmpProj(PT p, PT q)
    {
        return dot(v,p)<dot(v,q);
    }
    LINE translate(PT ftype)
    {
        return {v,c+cross(v,ftype)};
    }
    LINE shiftLeft (ftype dist)
    {
        return {v,c+dist*abs(v)};
    }
    bool inter(LINE l1, LINE l2, PT & out)
    {
        ftype d = cross(l1.v, l2.v);
        if (d == 0) return false;
        out = (l2.v*l1.c - l1.v*l2.c) / d; // requires floating-pointcoordinates
        return true;
    }
    PT proj(PT p)
    {
        return p - perp(v)*side(p)/sq(v);
    }
    PT refl(PT p)
    {
        return p - perp(v)*2*side(p)/sq(v);
    }

    line bisector(line l1, line l2, bool interior)
    {
        assert(cross(l1.v, l2.v) != 0); // l1 and l2 cannot be parallel!
        double sign = interior ? 1 : -1;
        return {l2.v/abs(l2.v) + l1.v/abs(l1.v) * sign,
                l2.c/abs(l2.v) + l1.c/abs(l1.v) * sign};
    }
};
ftype segPoint(PT a, PT b, PT c) ///distance between segment AB and point c
{
    if (a != b)
    {
        line l(a,b);
        if (l.cmpProj(a,p) && l.cmpProj(p,b)) // if closest to projection
            return l.dist(p); // output distance to line
    }
    return min(abs(p-a), abs(p-b)); // otherwise distance to A or B
}
int32_t main()
{
    PT a(1,2);
    DBG(a); /// <1,2>
    DBG( a+PT(10,10)); /// 11,12
    DBG( a-PT(10,10)); /// -9,-8
    DBG(a*10); /// 10,20
    DBG(a/10); /// 0.1 , 0.2
    DBG(a== PT(1,2)) /// true
    DBG(a == PT(1,20)) /// false
    DBG(a != PT(1,20)) /// true
    DBG(sgn(1.0)); /// 1
    DBG(sgn(0.0)); /// 0
    DBG(sgn(-1.0)); /// -1


}
