#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)2e5+5)
#define MOD ((int)1e9 + 7) 
#define lint long long
#define _ << " " <<
#define TRACE(x) cerr << #x << " = " << x << endl;
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"

vector <vector <pair <int,int>>> w(100005, vector<pair <int,int>>());
vector <bool> is_centr(100005, 0);
//vector <bool> visited(100005, 0);
vector <vector <int>> adj(100005, vector<int>());

lint gres;
int centroid;

int dfs(int i, int tree_size, int par, bool start=false){
	//cerr << "dfs for " << i <<endl;
	bool centr = true;
	int tot = 1;
	for(int chi: adj[i]){
		if(chi != par and !is_centr[chi]){
			int subw = dfs(chi, tree_size, i);
			tot += subw;
			if(2*subw > tree_size) centr = false; // buraya dikkat
			w[i].pb({chi, subw});
		}
	}


	int kalan_w = tree_size - tot;
	if(kalan_w)
		w[i].pb({par, kalan_w});
    //if(start) w[i].pb({par, 1});
    
    if(kalan_w * 2 > tree_size) centr = false;

	if(centr and !is_centr[i]){
		centroid = i;
	}
	
	return tot;

}

lint C(lint a){
    return (a * (a-1)) / 2;
}

void calc(int i){
	lint sum = 1;
    // cout << "centr: " << i << endl;
    for(auto chi: w[i]){
        // cout << chi.second << " ";
        sum += chi.second;
    }

    
    lint a = 0;
    for(auto g1: w[i]){
            a += C(g1.second) * C(sum - g1.second); 
            //gres += a; 
    }

    gres += a;

    // cout << endl << a << endl;

}

void perform(int i, int tree_size, int par){
	dfs(i, tree_size, par, 1);
    is_centr[centroid] = 1;
	calc(centroid);
    vector <vector <pair <int,int>>> wcp = w;
    w = vector <vector <pair <int,int>>> (100005, vector<pair <int,int>>());
	for(auto wei: wcp[centroid]){
		if(par != wei.first and !is_centr[wei.first])
        {
            // cout << "gönderdim " << wei.first << endl;
            perform(wei.first, wei.second, centroid);
        }
	}
}


int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);

	int n;
	cin >> n;

	for(int i=0; i<n-1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	perform(1, n, 0);
	// cout << w[4][0] << " " << endl;

	cout << gres * 2 << endl;
	//cout << " kjhsadf ";

	return 0;
}

//	g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o a a.cpp
//	g++ -std=c++17 -Wshadow -Wall -o a.out G.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
