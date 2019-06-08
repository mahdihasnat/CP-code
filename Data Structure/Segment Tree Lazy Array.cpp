const int N= 1e5+5;
int value[4*N];
int lazy[4*N];
void UpdateRange(int node , int ss, int se, int us,int ue, int diff)
{
    int mid = ss+(se-ss)/2;

    if (lazy[node] != 0)
    {
        value[node] += (se-ss+1)*lazy[node];
        if (ss != se)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node] = 0;
    }

    if (ss>se || ss>ue || se<us)
        return ;

    if (ss>=us && se<=ue)
    {
        value[node] += (se-ss+1)*diff;

        if (ss != se)
        {
            lazy[2*node]+=diff;
            lazy[2*node+1]+=diff;
        }
        return;
    }


    UpdateRange(2*node, ss, mid, us, ue, diff);
    UpdateRange(2*node+1, mid+1, se, us, ue, diff);

    value[node]=value[2*node]+value[2*node+1];

}
int GetSum(int node,int ss, int se, int qs, int qe)
{

    int mid = ss+(se-ss)/2;

    if (lazy[node] != 0)
    {
        value[node] += (se-ss+1)*lazy[node];
        if (ss != se)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node] = 0;
    }

    if (ss>se || ss>qe || se<qs)
        return 0;

    if (ss>=qs && se<=qe)
        return value[node];

    return GetSum(2*node,ss,mid,qs,qe)+GetSum(2*node+1,mid+1,se,qs,qe);
}

void Build(int node,int *a,int ss,int se)
{
    lazy[node]=0;
    if(ss==se)
    {
        value[node]=a[ss];
        return ;
    }
    int mid = ss+(se-ss)/2;
    Build(2*node,a,ss,mid);
    Build(2*node+1,a,mid+1,se);
    value[node]=value[2*node]+value[2*node+1];
}
