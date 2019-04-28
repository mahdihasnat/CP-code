#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef pair<int,int > pii;
#define pb(x) push_back(x)
#define DBG(x) cout<< #x<<" ---> "<<(x)<<endl;
#define NL cout<<endl;
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//LCA using sparse table
//Complexity: O(NlgN,lgN)
#define mx 10010
int W[mx];
int L[mx]; //লেভেল
int P[mx][22]; //স্পার্স টেবিল
int T[mx]; //প্যারেন্ট
vector<pii>g[mx];
void dfs(int from,int u,int dep)
{
    T[u]=from;
    L[u]=dep;
    for(int i=0; i<(int)g[u].size(); i++)
    {
        pii vw= g[u][i];
        int v=vw.first;
        int w=vw.second;
        if(v==from) continue;
        W[v]=W[u]+w;
        dfs(u,v,dep+1);
    }
}

int lca_query(int N, int p, int q) //N=নোড সংখ্যা
{
    int tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    log=1;
    while(1)
    {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;
    }

    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return T[p];
}

void lca_init(int N)
{
    memset (P,-1,sizeof(P)); //শুরুতে সবগুলো ঘরে -১ থাকবে
    int i, j;
    for (i = 0; i < N; i++)
        P[i][0] = T[i];

    for (j = 1; 1 << j < N; j++)
        for (i = 0; i < N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}

int kthParent(int N,int u,int k)
{
    int now=u;
    for(int j=0; (1<<j) <= k ; j++)
    {
        if(k & ( 1<<j))
            now=P[now][j];
    }
    return now;
}
/*
int kthParent(int N,int p,int k)
{
    int lg ; for( lg = 1 ; (1 << lg) <= L[p] ; ++lg ); lg--;
//    k--;
    for( int i = lg ; i >= 0 ; i-- ){
        if( (1 << i) <= k ){
            p = P[p][i];
            k -= ( 1 << i );
        }
    }
    return p;
}
*/
int main(void)
{

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    FastIO;

    int T,cs=0;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n-1; i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            a--;
            b--;
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }
        dfs(-1,0,0);
        lca_init(n);
//        for(int i=0;i<n;i++)
//        {
//            DBG(i);
//            DBG(W[i]);
//            NL;
//        }
        string s;
        while(1)
        {
            cin>>s;
            if(s=="DIST")
            {
                int a,b;
                cin>>a>>b;
                a--;
                b--;
                int ans= W[a]+W[b]- 2* W[lca_query(n,a,b)];
                cout<<ans<<"\n";
            }
            else if(s=="KTH")
            {
                int a,b,k;
                cin>>a>>b>>k;
                a--;
                b--;
                k--;
                int lc = lca_query(n,a,b);

//                DBG(lc);
//                DBG(a);
//                DBG(b);
//
//                DBG(L[a]);
//                DBG(L[b]);
//                DBG(L[lc]);
//                for(int i=0;i<5;i++)
//                {
//                    DBG(i);
//                    DBG(kthParent(n,a,i));
//                }

//                NL;
                int ans;
                if(L[a]-L[lc]>=k)
                {
//                    cout<<"aise\n";
                    ans=kthParent(n,a,k);
                }
                else
                {
                    ans=kthParent(n,b,L[a]+L[b]- 2 * L[lc] -k);
                }
                ans++;
                cout<<ans<<"\n";

            }
            else break;
        }
        for(int i=0; i<n; i++)
        {
            g[i].clear();
        }
        memset(L,0,sizeof L);
        memset(W,0,sizeof W);
        memset(P,0,sizeof P);
        cout<<"\n";
    }
    return 0;

}
