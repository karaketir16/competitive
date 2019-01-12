#include <bits/stdc++.h>
#define N 100000

using namespace std;

typedef long long int lli;

vector <lli> ar;
vector <lli> tree;

// builds the segment tree
void build(lli index, lli l, lli r){
    if(l == r){
        tree[index] = ar[l];
        return;
    }

    lli mid = (r + l) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);

    tree[index] = tree[index * 2] ^ tree[index * 2 + 1];
    return;
}

// current index, current left, current right, asked left, asked right
lli query(lli index, lli l, lli r, lli al, lli ar){
    if(r < al || l > ar)
        return 0;

    if(l >= al && r <= ar)
        return tree[index];

    lli mid = (l + r) / 2;
    return query(index * 2, l, mid, al, ar) ^ query(index * 2 + 1, mid + 1, r, al, ar);
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    ar.resize(N, 0);
    tree.resize(N+5, 0);
    for(int i=0; i<n; i++)
        scanf("%lli", &ar[i]);

    build(1, 0, n);

    lli q;
    scanf("%lli", &q);
    while(q--){
        lli al, ar;
        scanf("%lli %lli", &al, &ar);
        printf("%lli\n", query(1, 0, n, al, ar));
    }

    return 0;
}