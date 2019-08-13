const int N=3e5+5;
const int K = 23 ; /// k >= ceil(lg22(n)) +1
int st[N][K + 1];
int lg2[N+1];
void ini()
{
    lg2[1] = 0;
    for (int i = 2; i <= N; i++)
        lg2[i] = lg2[i/2] + 1;
}
int f(const vector<int > &array ,int i,int j)
{
    if(array[i]==array[j]) return i<j ? j: i;
    return array[i]<array[j] ? i: j;
}

void pre(const vector<int> &array, int n)
{

    for (int i = 0; i < n; i++)
        st[i][0] = f(array, i,i);

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = f(array, st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}
int getf(const vector<int > &array, int L,int R)
{
    if(L>R) swap(L,R);
    int j = lg2[R - L + 1];
    return  f(array,st[L][j], st[R - (1 << j) + 1][j]);
} 
