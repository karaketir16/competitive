#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
class ST
{
    public:
    vector<int> v;
    ST()
    {
        v = vector<int> (7);
    }
    ST(vector<int> a)
    {
        v = a;
    }
    ST operator+(ST x)
    {
        vector<int> tmp(7);
        for(int i =0; i < 7; i++)
        {
            tmp[i] = (*this)[i] + x[i];
        }
        return ST(tmp);
    }
    int& operator[](int x)
    {
        return v[x];
    }
    ST operator=(ST x)
    {
        this->v = x.v;
        return (*this);
    }
    ST operator*(int x)
    {
        auto tmp = v;
        for(auto& a:tmp)
        {
            a*=x;
        }
        return ST(tmp);
    }
};

#define iiii [param[1]][param[2]][param[3]][param[4]][param[5]]

ST GlobRes;

double dp[101][51][35][27][5];
bool dpbool[101][51][35][27][5];
double f(ST param)
{
    // if(min({param[1], param[2], param[3], param[4]}))
    if(dpbool iiii)
    {
        return dp iiii;
    }
    dpbool iiii = true;
    int last = param[5];
    double res = 0;
    bool possib = false;

    double tot = param[1]*1 + param[2]*2 + param[3]*3 + param[4]*4;
    tot -= (last==0? 0: (last-1));
    for(int i = 1; i <= 4; i++)
    {
        int deger = 1 + ((last-1) == i);
        if(param[i] - deger >= 0)
        {
            ST tmp = param;
            tmp[i]-=1;
            tmp[i-1]++;
            tmp[5] = i;
            // cout << "Kendi: ";
            // for(int i = 1; i <= 5; i++)
            // {
            //     cout<<i<<":"<<param[i]<<' ';
            // }
            // cout<<endl;
            // cout << "Cagirdi: ";
            // for(int i = 1; i <= 5; i++)
            // {
            //     cout<<i<<":"<<tmp[i]<<' ';
            // }
            // cout<<endl;
            // cout<<"totHere1: "<<tot<<endl;
            res = res + (f(tmp) * i * (param[i] - deger + 1) / tot); //NOT SURE
            
            // cout<<"resHere1: "<<res<<endl;
            possib = true;
            
        }
    }

    if(possib == false)
    {
        // cout << "Kendi, HicbiseyCagirmadi: ";
        // for(int i = 1; i <= 5; i++)
        // {
        //     cout<<i<<":"<<param[i]<<' ';
        // }
        // cout<<endl;
        double x = param[1]*1 + param[2]*2 + param[3]*3 + param[4]*4;
        // GlobRes[x]++;
        
        res = x;
        // cout<<"Kalan: "<<res<<endl;
    }

    dp iiii = res;
    // cout<<"resHere3: "<<res<<endl;
    return res;
}

int main()
{
    ST tmp;

    // for(int i = 0; i < 7; i++)
    // {
    //     cout<<i<<": "<<x[i]<<endl;
    // }
    int n;
    cin>>n;
    map<int, int> mp;
    while (n--)
    {
        string s;
        int x;
        cin>>s>>x;
        mp[x]++;
    }
    for(auto p:mp)
    {
        tmp[p.second]++;
    }
    auto x = f(tmp);
    cout<<x;
    return 0;
}