#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;

int main()
{
    char ch;
    scanf("%c",&ch);
    int total=0;
    int s=0;//{}
    int n=0;//()
    int k=0;//[]
    int ku=0;//<>
    int say=0;
    stack<char> prt;
    while(ch!='\n')
    {
        if(ch=='{')
        {
            s++;
            total++;
            prt.push('}');
            
        }
        if(ch=='<')
        {
            ku++;
            total++;
            prt.push('>');
        }
        if(ch=='[')
        {
            k++;
            total++;
            prt.push(']');
        }
        if(ch=='(')
        {
            n++;
            total++;
            prt.push(')');
        }
        //
        //
        //
        if(ch=='}')
        {

            s--;
            total--;
            if(total<0)
            {
                cout<<"Impossible";
                exit(0);
            }
            if(prt.top()!=ch)
            {
                say++;
            }
            prt.pop();
        }
        if(ch=='>')
        {
            ku--;
            total--;
            if(total<0)
            {
                cout<<"Impossible";
                exit(0);
            }
            if(prt.top()!=ch)
            {
                say++;
            }
            prt.pop();
        }
        if(ch==']')
        {
            k--;
            total--;
            if(total<0)
            {
                cout<<"Impossible";
                exit(0);
            }
            if(prt.top()!=ch)
            {
                say++;
            }
            prt.pop();
        }
        if(ch==')')
        {
            n--;
            total--;
            if(total<0)
            {
                cout<<"Impossible";
                exit(0);
            }
            if(prt.top()!=ch)
            {
                say++;
            }
            prt.pop();
        } 
        scanf("%c",&ch);
    }

    if(total>0)
    {
        cout<<"Impossible";
        exit(0);
    }
    int test=abs(n)+abs(ku)+abs(k)+abs(s);
    cout<<say;

    return 0;
}