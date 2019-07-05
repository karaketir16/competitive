#include <bits/stdc++.h>
using namespace std;

typedef long long int lint;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
    lint n, a, b;
    cin>>n>>a>>b;

    vector<set<lint>> groups;

    set<lint> s;
    set<lint> sss;

    for(lint i = 0; i< n; i++){

        lint x;
        cin>>x;

        if(x<=b && x>=a){
            s.insert(x);
            sss.insert(x);
        }
        else
        {
            if(s.size()>0)
            {
                groups.push_back(s);
                s.clear();
            }

        }
    }
    if(s.size()>0) groups.push_back(s);

    lint k = b - a + 1;

    if(sss.size() < k)
    {
        cout<<-1;
        return 0;
    }

    lint ald = 0;
    vector<bool> erased(groups.size());
    for(lint i = 0; i < groups.size(); i++){
        if(erased[i]) continue;
        if(groups[i].size() == 1)
        {
            auto x = *(groups[i].begin());
            // it++;
            lint cnt = 0;
            for(lint j = 0; j < groups.size(); j++)
            {
                if(erased[j]) continue;
                cnt += groups[j].count(x);
        //         // if(a.count(x))
        //         // {
        //         //     groups.erase(it);
        //         //     flag = false;
        //         //     break;
        //         // }
            }
            if(cnt == 0) abort();
            if(cnt == 1)
            {
                k--;
                ald++;
                erased[i]=true;
                // flag = false;
            }
            if(cnt > 1)
            {
                erased[i]=true;
                // groups.erase(it);
                // flag = false;
            }
        }
    }

    vector<set<lint>> tmp; 

    for(int i = 0; i < groups.size(); i++) if(!erased[i]) tmp.push_back(groups[i]);

    groups = tmp;

    lint sz = groups.size();
    if(k == 0) 
    {
        // abort();
        cout<<ald;
        return 0;
    }
    // assert(sz > 0);
    // cout<<"sz: "<<sz<<endl;
    // cout<<"k: "<<k<<endl;
    // for(lint j =0 ; j< sz; j++){
    //      for(auto aa:groups[j]) cout<<aa<<" ";
    //      cout<<endl;
    // }
    // cout<<"Hello";
    lint minGr = 1e18;
    for(lint i =0; i< (1<<sz); i++)
    {
        lint gr = __builtin_popcount(i);
        if(gr >= minGr) continue;
        set<lint> ss;
        for(lint j =0 ; j< sz; j++)
        {
            if(i & (1<<j)) ss.insert(groups[j].begin(), groups[j].end());
        }
        if(ss.size() == k) minGr = min(minGr, gr);
    }
    cout<<(minGr + ald);

	return 0;
}

//	g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o a a.cpp
//	g++ -std=c++11 -Wshadow -Wall 4F.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
