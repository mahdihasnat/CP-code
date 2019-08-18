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
ostream &operator <<(ostream &os,const pair < T1,T2 > &p)
{
    os<<"{"<<p.first<<","<<p.second<<"}";
    return os;
}

const int N=3e5+5;
const int oo=1e9+7;


typedef double ftype;
struct PT
{
    ftype x,y;
    PT operator + (PT const &p) { return  {x+p.x, y+p.y}; }
    PT operator - (PT const &p) { return  {x-p.x, y-p.y}; }
    PT operator * (ftype const &d) { return  {x*d, y*d}; }
    PT operator / (ftype const &d) {assert(d!=0);  return  {x/d, y/d}; }
    bool operator==(PT const& p) {return x==p.x && y == p.y; }
    bool operator!=(PT const& p) {return !(*this == p); }
    PT(ftype x = 0 , ftype y=0):x(x),y(y) { }
};
ostream & operator<<(ostream &os,PT const &p)
{
    return os<<"< "<<p.x<<" , "<<p.y<<" >";
}
ftype sq(PT const &p)
{
    return p.x*p.x+p.y*p.y;
}
ftype abs(PT const &p)
{
    return sqrt(sq(p));
}
template<typename TT>
int sgn(TT x)
{
    return (TT(0)<x) - (x<TT(0));
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
}
