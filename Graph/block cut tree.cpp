vector<pii> g[N]; /// input connected undirected graph

int tin[N];
int low[N];
int dfs_timer;
int total_tree_node ;

vector <int > nodes[N]; /// all input nodes contained in tree node u
int to_node[N]; /// to_node[u]  is tree node which contains u
vector<pii> tree[N]; /// edge of block-cut tree , output tree


void add_bridge_edge(int u,int v,ll w)
{
    tree[u].emplace_back(v , w);
    tree[v].emplace_back(u , w);
}

void dfs1(int u,int p = -1)
{
    low[u] = tin[u] = dfs_timer++;
    for(pii vw: g[u])
    {
        int v = vw.first;
        ll w = vw.second;

        if(v==p) continue;

        if(tin[v] == -1)
        {
            dfs1(v,u);
        }
        low[u] = min(low[u] , low[v]);
    }
}

void dfs2(int u,int p = -1)
{
    if(low[u] == tin[u])
    {
        to_node[u] = ++total_tree_node;
    }
    else to_node[u] = to_node[p];

    for(pii vw: g[u])
    {
        int v = vw.first;
        ll w = vw.second;

        if(v==p) continue;

        if(to_node[v] == -1)
            dfs2(v,u);

        if(low[v] > tin[u])
        {
            add_bridge_edge(to_node[u] , to_node[v]  , w);
        }
    }
    nodes[to_node[u]].push_back(u);
}

void block_cut_tree()
{
    dfs_timer = 1;
    total_tree_node = 0;
    memset(tin , - 1 , sizeof tin);
    memset(to_node , -1 , sizeof to_node);
    dfs1(1);
    dfs2(1);
}
