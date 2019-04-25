
struct TrieMap
{
    struct node
    {
        bool val;
        node * next[10];
        node(int val=0) : val(val)
        {
            memset(next,0,sizeof next);
        }
    };
    node *head;
    TrieMap()
    {
        head= new node();
    }
    void del(node *head)
    {
        if(head)
        {
            for(int i=0; i<10; i++)
                del(head->next[i]);
            delete head;
        }
    }
    ~TrieMap()
    {
        del(head);
    }
    bool & operator[] ( string s)
    {
        node * now= head;
        for(int i=0; i<s.size(); i++)
        {
            if(now->next[s[i]-'a'])
                now = now->next[s[i]-'a'];
            else
            {
                now->next[s[i]-'a'] = new node();
                now =now->next[s[i]-'a'];
            }
        }
//        DBG(s);
//        DBG(head->val);
        return now->val;
    }


};
