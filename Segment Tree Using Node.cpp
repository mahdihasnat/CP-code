/***

https://codeforces.com/contest/380/submission/50286373

Problem : https://codeforces.com/contest/380/problem/C 

***/


#include <bits/stdc++.h>
using namespace std;

// limit for array size
const int N = 100000;

int n; // array size

// Max size of tree

struct Node
{
    int a,b,c;
    Node *l,*r;
    Node() : a(0) , b(0), c(0),l(0),r(0) { }
    Node(int a,int b,int c) : a(a),b(b),c(c),l(0),r(0) { }
    Node operator + ( const Node & n)
    {
        int t= min(b,n.c);
        return Node(a+n.a+t,b+n.b-t,c+n.c-t);
    }
    void setLeft(Node *x)
    {
        l=x;
    }
    void setRight(Node *x)
    {
        r=x;
    }
};

// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }

/*  A recursive function to get the sum of values in given range
    of the array. The following are parameters for this function.

    st    --> Pointer to segment tree
    si    --> Index of current node in the segment tree. Initially
              0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented
                 by current node, i.e., st[si]
    qs & qe  --> Starting and ending indexes of query range */
Node getSumUtil( int ss, int se, int qs, int qe, Node *node)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    if (qs <= ss && qe >= se)
        return *node;

    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return Node();

    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return getSumUtil( ss, mid, qs, qe,node->l) +
           getSumUtil( mid+1, se, qs, qe, node->r);
}

/* A recursive function to update the nodes which have the given
   index in their range. The following are parameters
    st, si, ss and se are same as getSumUtil()
    i    --> index of the element to be updated. This index is
             in the input array.
   diff --> Value to be added to all nodes which have i in range */

   /*
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
{
    // Base Case: If the input index lies outside the range of
    // this segment
    if (i < ss || i > se)
        return;

    // If the input index is in range of this node, then update
    // the value of the node and its children
    st[si] = st[si] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
    }
}

// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }

    // Get the difference between new value and old value
    int diff = new_val - arr[i];

    // Update the value in array
    arr[i] = new_val;

    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
*/
// Return sum of elements in range from index qs (quey start)
// to qe (query end).  It mainly uses getSumUtil()
int getSum(Node* st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return 2*getSumUtil( 0, n-1, qs, qe, st).a;
}

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
Node *constructSTUtil(char *s, int ss, int se)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    //st= new Node();
    if (ss == se)
    {
        Node *st=new Node();
        st->b=(s[ss]=='(');
        st->c=(s[ss]==')');
        return st;
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(ss, se);
    Node *lft = constructSTUtil(s, ss, mid) ;
    Node * rt=  constructSTUtil(s, mid+1, se);
    Node *st= new Node( (*lft) + (* rt) );
    st->setLeft(lft);
    st->setRight(rt);
    return st;
}

/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
Node *constructST(char *s, int n)
{

    // Fill the allocated memory st


    // Return the constructed segment tree
    return constructSTUtil(s, 0, n-1);
}

int main()
{
    char s[1000006];
    cin>>s;
    n= strlen(s);
        Node * head = constructST(s,n);
    int m;
    cin>>m;
    while(m--)
    {
        int l,r;
        cin>>l>>r;

        cout<<getSum(head,n,l-1,r-1)<<endl;
    }
    return 0;
}
