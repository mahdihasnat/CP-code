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

const int N=1e5+5;
const int oo=1e9+7;

int Lower_bound(int *a,int n,int val)
{
    int lo=0,hi=n,mi;
    while(lo<=hi)
    {
        mi=(lo+hi)/2;
        if(mi==n) break;
        if(a[mi] >= val)
            hi=mi-1;
        else lo=mi+1;
    }
    return lo;
}
int a[100000];
int32_t main()
{
//    int a[]={-1,0,1,2,2,4,4,5};
//    DBG(Lower_bound(a,8,3));
    srand(time(0));
    int T=100;
    while(T--)
    {
        int n=rand()%10000+1;
        for(int i=0;i<n;i++)
        {
            a[i]= rand()%100000;
        }
        sort(a,a+n);
        for(int i=0;i<=n;i++)
        {
            assert(Lower_bound(a,n,i)== (lower_bound(a,a+n,i)-a));
        }
    }
}
