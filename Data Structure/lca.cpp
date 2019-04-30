#define mx 50005
int W[mx];
int L[mx]; //লেভেল
int P[mx][22]; //স্পার্স টেবিল
int PW[mx][22]; //স্পার্স টেবিল
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
        if(v==from)
            continue;
        W[v]=w;
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
        if((1<<next)>L[p])
            break;
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
    memset (PW,0,sizeof(PW)); //শুরুতে সবগুলো ঘরে 0 থাকবে
    int i, j;
    for (i = 0; i < N; i++)
        P[i][0] = T[i],PW[i][0]=W[i];

    for (j = 1; 1 << j < N; j++)
        for (i = 0; i < N; i++)
            if (P[i][j - 1] != -1)
            {
                P[i][j] = P[P[i][j - 1]][j - 1];
                PW[i][j]= max(W[P[i][j-1]],max(PW[i][j-1],PW[P[i][j-1]][j-1]));
            }


}
int kthParent(int N,int p,int k)
{
    int lg ;
    for( lg = 1 ; (1 << lg) <= L[p] ; ++lg )
        ;
    lg--;
    for( int i = lg ; i >= 0 ; i-- )
    {
        if( (1 << i) <= k )
        {
            p = P[p][i];
            k -= ( 1 << i );
        }
    }
    return p;
}
int kthParentW(int N,int p,int k)
{
    int lg ;
    for( lg = 1 ; (1 << lg) <= L[p] ; ++lg )
        ;
    lg--;
    int res=0;
    for( int i = lg ; i >= 0 ; i-- )
    {
        if( (1 << i) <= k )
        {
            res=max(res,PW[p][i]);
            p = P[p][i];
            k -= ( 1 << i );
        }
    }
    return res;
}

void initCase()
{
    for(int i=0; i<mx; i++)
    {
        g[i].clear();
    }
    memset(W,0,sizeof W);

}
int main(void)
{
    dfs(-1,0,0);
    lca_init(n);
}
