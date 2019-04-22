#include <bits/stdc++.h>
using namespace std;
inline double dst(int x0, int y0, int x1, int y1)
{
    return (sqrt(  ((x0 - x1)^2) + ((y0 - y1)^2))  );
}
int main()
{
    double xa, xb, ya, yb;
    cin>>xa>>ya>>xb>>yb;

    int n;
    cin>>n;
    vector<pair<pair<int, int>, int>> v;
    for(int i=0;i<n;i++)
    {
        double x, y, r;
        cin>>x>>y>>r;
        v.push_back({{x, y}, r});
    }
    

}
