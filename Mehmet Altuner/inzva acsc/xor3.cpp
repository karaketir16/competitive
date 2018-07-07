https://www.hackerrank.com/contests/inzva-acsc-foundation-upsolving/challenges/xor-3-3
#include <bits/stdc++.h>

using namespace std;

int tree[2 * 1000000 + 5];
int ar[1000005];

int construct(int start, int end, int tree_index){
    if(start==end){
        tree[tree_index] = ar[start];
        return tree[tree_index];
    }
    
    int mid = start + (end - start) / 2; 
    //cout << "akjsh " << mid << '\n';
    tree[tree_index] = construct(start, mid, tree_index*2) ^ construct(mid+1, end, tree_index*2 + 1); 
    return tree[tree_index];
}

int get_xor(int start, int end, int q_s, int q_e, int tree_index){
  //cout << "start: " << start << " end: " << end << '\n';
  if(q_s <= start && q_e >= end)
    return tree[tree_index];
  
  if(start > q_e || end < q_s)
    return 0;

  int mid = start + (end - start) / 2; 
  return get_xor(start, mid, q_s, q_e, tree_index*2) ^ get_xor(mid+1, end, q_s, q_e, tree_index*2 + 1);
}

int main(){
  int n;
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> ar[i];
  }
  construct(1, n, 1); // fill the tree
  int q;
  cin >> q;
  while(q--){
    int q_s, q_e;
    cin >> q_s >> q_e;
    cout << get_xor(1, n, q_s, q_e, 1) << '\n';
  }
  return 0;
}
