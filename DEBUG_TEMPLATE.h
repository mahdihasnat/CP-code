
void err(vector<string>::iterator it)
{
    cerr<<endl;
}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args)
{
    cerr << *it << " = " << a << " ";
    err(++it, args...);
}

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
    }
    os<<" ]";
    return os;
}
template <class T,size_t N>
ostream &operator <<(ostream &os, array<T,N>&v)
{
    os<<"{ ";
    for(auto const&i: v)
    {
        os<<i<<" " ;
    }
    os<<" }";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, deque<T>&v)
{
    os<<"[ ";
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
    }
    os<<" ]";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}


template <class T>
ostream &operator <<(ostream &os, multiset<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}
template <class T1, class T2>
ostream &operator <<(ostream &os, map<T1,T2>&v)
{
    for(auto i:v)
    {
        os<<"Key : "<<i.first<<" , Value : "<<i.second<<endl;
    }
    return os;
}
template <class T1, class T2>
ostream &operator <<(ostream &os, unordered_map<T1,T2>&v)
{
    for(auto i:v)
    {
        os<<"Key : "<<i.first<<" , Value : "<<i.second<<endl;
    }
    return os;
}

vector<string> splitbalanced(string s, string delemeters)
{
	vector<string> ret;
	int bal = 0;
	int prev = 0;
	int n = s.size();
	for(int i=0;i<n;i++)
	{
		auto c = s[i];
		if(c =='(' or c=='[' or c=='{') bal++;
		else if(c ==')' or c==']' or c=='}') bal--;
		else if(bal==0 and delemeters.find(c)!=string::npos)
		{
			ret.push_back(s.substr(prev,i-prev));
			prev = i+1;
		}
	}
	if(prev<n) ret.push_back(s.substr(prev,n-prev));
	return ret;
}

#define HERE cout<<"here - "<<__LINE__<<"\n";
#define debug(args...) { \
	 string _s = #args; \
	 auto _ss = splitbalanced(_s, ","); \
	 vector<string>::iterator _it = _ss.begin(); \
	 cerr<<"Line "<<__LINE__<<" -> "; \
	 err(_it, args); \
	}

//__int128

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int >,rb_tree_tag,tree_order_statistics_node_update>indexed_set;

//order_of_key
//find_by_order

//this memsets by 2e9
//memset(x,127,sizeof x);

//this memsets by 1e9
//memset(x,63,sizeof x);

