
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;
#define pp pair<int,int>

typedef long long int lint;

int totalstate=0;
struct State
{
    State* suffixLink=NULL;
    State* parent=NULL;
    char parentChar='\0';
    map<char,State*> children;
    vector<int> wordIds;
};
void trieFonk(State *state, string s, int wId)
{
    for(char ch:s)
    {
        if(state->children[ch]!=0)
        {
            state=state->children[ch];
        }
        else
        {
            State *t =new State;
            totalstate++;
            state->children[ch]=t;
            t->parent=state;
            state=t;
            state->parentChar=ch;
        }
    }
    state->wordIds.pb(wId);
}
State *root = new State;
void bfs(State *state)
{
    if(state==root)
    {
        state->suffixLink=root;
        return;
    }
    if(state->parent==root)
    {
        state->suffixLink=root;
        return;
    }

    State *currentBest = state->parent->suffixLink;

    if(currentBest->children[state->parentChar]!=NULL)
    {
        state->suffixLink = currentBest->children[state->parentChar];
        
    } 
    while(true)
    {
        if(currentBest->children[state->parentChar]!=NULL)
		{
			state->suffixLink = currentBest->children[state->parentChar];
			break;
		}

        if(currentBest==root) state->suffixLink = root;
        
        currentBest = currentBest->suffixLink;
    }  
}
void prepare()
{
    queue<State*> state_q;
    state_q.push(root);
    while(!state_q.empty())
    {
        State *current = state_q.front();
        state_q.pop();
        bfs(current);
        for(auto x:current->children)
        {
            if(x.sc!=NULL) state_q.push(x.sc);
        }

    }
}
int main(int argc, char const *argv[])
{
    totalstate++;//   0       1       2      3       4    5        6
    string strs[]={ "abba", "cab", "baba", "caab", "ac", "abac", "bac" };
    for(int i=0;i<7;i++)
    {
        string s=strs[i];
        trieFonk(root, s, i);
    }
    prepare();
    string text = "abbacabbabacaabacabacbac$";
    State *state=root;
    for(auto s:text)
    {
        //cout<<s<<endl;
        
        while(true)
        {
            if(!state->wordIds.empty()) cout<<state->wordIds[0]<<" Bulundu\n";
            if(state->children[s]!=0)
            {
                state=state->children[s];
                break;
            }
            if(state==root) break;

            state=state->suffixLink;
            //cout<<state<<' '<<root<<endl;
        }
    }
/*     map<string,int> test;
    test["ahmet"]=5;
    test["mehemt"]=3;
    cout<<"test: "<<test.at("hasan")<<endl;
    for(auto x:test) cout<<x.sc<<endl;
    cout<<totalstate<<endl; */
    return 0;
}
