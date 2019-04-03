

struct Node
{
    int value,lazy;
    Node * left, * right;
    Node(int l,int r)
    {
        left=right=0;
        lazy=0;
        value= (r*r+r-l*l+l)/2;
    }
    Node* getLeft(int leftL,int leftR) /// left left ,  left right
    {
        if(left) return left;
        else return left= new Node(leftL,leftR);
    }
    Node* getRight(int rightL,int rightR) /// right left ,  right right
    {
        if(right) return right;
        else return right= new Node(rightL,rightR);
    }
};

void UpdateRange(Node * head, int ss, int se, int us,int ue, int diff)
{
    int mid = ss+(se-ss)/2;

    if (head->lazy != 0)
    {
        head->value += (se-ss+1)*head->lazy;
        if (ss != se)
        {
            head->getLeft(ss,mid)->lazy+=head->lazy;
            head->getRight(mid+1,se)->lazy+=head->lazy;
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
            head->getLeft(ss,mid)->lazy+=diff;
            head->getRight(mid+1,se)->lazy+=diff;
        }
        return;
    }


    UpdateRange(head->getLeft(ss,mid), ss, mid, us, ue, diff);
    UpdateRange(head->getRight(mid+1,se), mid+1, se, us, ue, diff);

    head->value=head->getLeft(ss,mid)->value+head->getRight(mid+1,se)->value;

}
int GetSum(Node * head,int ss, int se, int qs, int qe)
{

    int mid = ss+(se-ss)/2;

    if (head->lazy != 0)
    {
        head->value += (se-ss+1)*head->lazy;
        if (ss != se)
        {
            head->getLeft(ss,mid)->lazy+=head->lazy;
            head->getRight(mid+1,se)->lazy+=head->lazy;
        }
        head->lazy = 0;
    }

    if (ss>se || ss>qe || se<qs)
        return 0;

    if (ss>=qs && se<=qe)
        return head->value;

    return GetSum(head->getLeft(ss,mid),ss,mid,qs,qe)+GetSum(head->getRight(mid+1,se),mid+1,se,qs,qe);
}

