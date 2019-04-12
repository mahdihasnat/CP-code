struct node
{
    int asche,seshoise;
    node * next[10];
    node()
    {
        asche=seshoise=0;
        for(int i=0;i<10;i++) next[i]=0;
    }

};

node *add(node * head,const string &s,int i)
{
    if(!head) head=new node();
    if(i==s.size())
    {
        head->seshoise++;
        return head;
    }
    head->asche++;
    head->next[s[i]-'0']=add(head->next[s[i]-'0'],s,i+1);
    return head;
}
int getprefixcnt(node * head , string &s,int i)
{
    if(!head) return 0;
    if(i==s.size()) return head->asche;
    return getprefixcnt(head->next[s[i]-'0'],s,i+1);
}
void del(node * head)
{
    if(head)
    {
        for(int i=0;i<10;i++) del(head->next[i]);
        delete head;
    }
}
