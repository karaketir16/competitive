#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, m;
  cin>>n>>m;
  std::vector<pair<int, int>> sorted;
  std::vector<pair<int, int>> notSorted;

  for (size_t i = 0; i < m; i++) {
    int t, l, r;
    cin>>t>>l>>r;

    if(t) sorted.push_back({l,r});
    else notSorted.push_back({l,r});
  }
  vector<int> v(n+1, -1);
  for(auto [l, r]: sorted)
  {
    for(int i = l;i <r; i++)
    {
      v[i] = 0;
    }
  }
  // for(int i = 1;i<n;i++) cout<<v[i]<<" ";
  for(auto [l, r]: notSorted)
  {
    bool ok = false;
    for(int i = l;i <r; i++)
    {
      if(v[i] == 0) continue;
      ok = true;
      break;
    }

    if(ok) continue;

    cout<<"NO\n";
    return 0;

  }

  cout<<"YES\n";
  int ss = 50000;
  for(int i = 1;i<=n;i++) {

    cout<<ss<<" ";
    ss+=v[i];
  }
  cout<<endl;
  return 0;
}
