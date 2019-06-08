/****** BISMILLAH HIR RAHMANIR RAHIM ******/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef long long ll;
typedef pair <int, int> pii;
/* Special functions:

        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


#define EPS 1e-9
#define NL cout<<endl;
#define MP make_pair
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
template < class T1,class T2>
pair <T1,T2> operator + ( const  pair < T1,T2 > &p1,const pair < T1,T2 > &p2)
{
    return make_pair(p1.first+p2.first,p1.second+p2.second);
}
/****** END OF HEADER ******/
const int N=1e5+5;
const int oo=1e9+7;

int main()
{
    FastIO;
    IN;
    OUT;
    int T,cs=0;
    cin>>T;
    while(T--)
    {
        cout<<"Case "<<++cs<<": ";
    }
}
