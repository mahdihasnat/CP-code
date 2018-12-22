

#define pc(x) putchar(x);
inline void writeInt (int n)
{
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0)
    {
        pc('0');
        pc('\n');
        return ;
    }
    while ((rev % 10) == 0)
    {
        count++;    //obtain the count of the number of 0s
        rev /= 10;
    }
    rev = 0;
    while (N != 0)
    {
        rev = (rev<<3) + (rev<<1) + N % 10;    //store reverse of N in rev
        N /= 10;
    }
    while (rev != 0)
    {
        pc(rev % 10 + '0');
        rev /= 10;
    }
    while (count--)
        pc('0');
}
inline void writeString(char *s)
{
    while(*s) { pc(*s);s++;}
}

inline int next_int() {
    int n = 0;
    char c = getchar();
    while (!('0' <= c && c <= '9')) {
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar();
    }
    return n;
}

inline void next_string(char *s)
{
    int i=0;
    while(1)
    {
        int ch =getchar();
        if((ch==' '|| ch == '\n') && i==0) continue;
        if(ch==' '|| ch==EOF || ch == '\n') break;
        s[i]=ch;
        s[++i]=0;
    }
}
