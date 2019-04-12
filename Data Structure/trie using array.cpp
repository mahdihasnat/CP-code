/// idea : "k790alex" in cf 11-4-19

//let f be the matrix representation of your trie

//let f[k] be the list of links for the k-th node

//let f[k][x] = m, the node who represents the son of k-th node using x-th character, m = -1 is there is not a link.

int MAX = Max number of nodes
int CHARSET = 52
int ROOT = 0
int sz = 1;

int f[MAX][CHARSET]

void init() {
 memset(f,-1,sizeof f);
}

void add(string & s) {
 int node = ROOT;
 for (int i = 0; i < s.size(); i++) {
   if ( f[node][ s[i] ] == -1 )
      f[node][ s[i] ] = sz++;
   node = f[node][ s[i] ];
 }
}
//Notes: Root node is at f[0] sz is the numbers of nodes currently in trie
