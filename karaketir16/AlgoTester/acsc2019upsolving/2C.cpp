#include <bits/stdc++.h>
using namespace std;

class Dis
{
public:
    double first;
    double second;
    bool operator< (const Dis& a) const
    {
        return (this->first / this->second) < (a.first / a.second);
    } 
};

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main()
{

    int n, m;
    cin>>n>>m;
    priority_queue<Dis> que;
    n--;
    while (n--)
    {
        int x;
        cin>>x;
        que.push({x*1.0, 1.0});
    }
    
    while(m--)
    {
        auto tp = que.top();
        que.pop();
        que.push({tp.first, tp.second+1});
    }
    auto tp = que.top();
    int gc = gcd(tp.first, tp.second);
    cout << (int) tp.first / gc <<'/' << (int) tp.second / gc;

    return 0;
}