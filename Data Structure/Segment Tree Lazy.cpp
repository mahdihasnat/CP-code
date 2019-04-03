struct Node
{
    int value,lazy;
    Node * left, * right;
    Node(Node *left,Node * right): lazy(0)
    {
        this->left=left;
        this->right=right;
        value=left->value+right->value;
    }
    Node(int value) : value(value),lazy(0) {}
};
void UpdateRange(Node * head, int ss, int se, int us,int ue, int diff)
{
    int mid = ss+(se-ss)/2;

    if (head->lazy != 0)
    {
        head->value += (se-ss+1)*head->lazy;
        if (ss != se)
        {
            head->left->lazy+=head->lazy;
            head->right->lazy+=head->lazy;
        }
        head->lazy = 0;
    }

    if (ss>se || ss>ue || se<us)
        return ;

    if (ss>=us && se<=ue)
    {
        head->value += (se-ss+1)*diff;

        if (ss != se)
        {
            head->left->lazy+=diff;
            head->right->lazy+=diff;
        }
        return;
    }


    UpdateRange(head->left, ss, mid, us, ue, diff);
    UpdateRange(head->right, mid+1, se, us, ue, diff);

    head->value=head->left->value+head->right->value;

}
int GetSum(Node * head,int ss, int se, int qs, int qe)
{

    int mid = ss+(se-ss)/2;

    if (head->lazy != 0)
    {
        head->value += (se-ss+1)*head->lazy;
        if (ss != se)
        {
            head->left->lazy+=head->lazy;
            head->right->lazy+=head->lazy;
        }
        head->lazy = 0;
    }

    if (ss>se || ss>qe || se<qs)
        return 0;

    if (ss>=qs && se<=qe)
        return head->value;

    return GetSum(head->left,ss,mid,qs,qe)+GetSum(head->right,mid+1,se,qs,qe);
}

Node * Build(int *a,int ss,int se)
{
    if(ss==se)
    {
        return new Node(a[ss]);
    }
    int mid = ss+(se-ss)/2;
    return new Node(Build(a,ss,mid),Build(a,mid+1,se));
}
