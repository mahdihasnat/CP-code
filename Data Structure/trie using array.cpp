/// idea : "k790alex" in cf 11-4-19

//let f be the matrix representation of your trie

//let to[k] be the list of links for the k-th node

//let to[k][x] = m, the node who represents the son of k-th node using x-th character, m = -1 is there is not a link.

const int MAX = N ;
const int CHARSET = 2;
const int ROOT = 0;
int sz = 1;

int to[MAX][CHARSET];

void init()
{
    sz=1;
    memset(to,-1,sizeof to);
}

void add(const string & s)
{
    int node = ROOT;
    for (int i = 0; i < s.size(); i++)
    {
        if ( to[node][ s[i] ] == -1 )
            to[node][ s[i] ] = sz++;
        node = to[node][ s[i] ];
    }
}
//Notes: Root node is at to[0] sz is the numbers of nodes currently in trie
