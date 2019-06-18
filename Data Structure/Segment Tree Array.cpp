const int N= 1e5+5;
int value[4*N];
void UpdatePoint(int node , int ss, int se, int u, int diff)
{
    int mid = ss+(se-ss)/2;

    if (ss>se || ss>u || se<u)
        return ;

    if (ss==se&& ss==u)
    {
        value[node] += diff;
        return;
    }

    UpdatePoint(2*node, ss, mid, u, diff);
    UpdatePoint(2*node+1, mid+1, se, u, diff);

    value[node]=value[2*node]+value[2*node+1];

}
int GetSum(int node,int ss, int se, int qs, int qe)
{
    int mid = ss+(se-ss)/2;

     if (ss>se || ss>qe || se<qs)
        return 0;

    if (ss>=qs && se<=qe)
        return value[node];

    return GetSum(2*node,ss,mid,qs,qe)+GetSum(2*node+1,mid+1,se,qs,qe);
}

void Build(int node,int *a,int ss,int se)
{
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
