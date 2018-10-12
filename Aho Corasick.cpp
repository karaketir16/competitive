
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
State *root;
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

        if(currentBest==root) 
        {
            state->suffixLink = root;
            break;
        }
        
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


void deleteStates()
{
    queue<State*> state_q;
    state_q.push(root);
    while(!state_q.empty())
    {
        State *current = state_q.front();
        state_q.pop();
        
        for(auto x:current->children)
        {
            if(x.sc!=NULL) state_q.push(x.sc);
        }
        delete current;

    }
}
int main(int argc, char const *argv[])
{

    string text;//text that pattern search in
    cin>>text;
    text+='$';
    root = new State;
    int q;
    cin>>q;
    vector<string> queries;// patterns
    vector<bool> results(q,0);// pattern found or not
    for(int i=0;i<q;i++)
    {
        string s;
        cin>>s;
        queries.pb(s);
        trieFonk(root, s, i);
    }
    prepare();

    State *state=root;
    for(auto s:text)
    {
        while(true)
        {
            if(!state->wordIds.empty())
            {
                for(auto x:state->wordIds)
                {
                    results[x]=1;
                }
            }
            if(state->children[s]!=0)
            {
                state=state->children[s];
                break;
            }
            if(state==root) break;
            state=state->suffixLink;
        }
    }
    for(auto x:results)
    {
        if(x) cout<<"y\n";
        else cout<<"n\n";
    }
    deleteStates();
    return 0;
}
