#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9)
//#define __ <<" "<<
typedef long long int lint;
class ST
{
    public:
    vector<lint> v;
    ST()
    {
        v = vector<lint> (7);
    }
    ST(vector<lint> a)
    {
        v = a;
    }
    ST operator+(ST x)
    {
        vector<lint> tmp(7);
        for(lint i =0; i < 7; i++)
        {
            tmp[i] = (*this)[i] + x[i];
        }
        return ST(tmp);
    }
    lint& operator[](lint x)
    {
        return v[x];
    }
    ST operator=(ST x)
    {
        this->v = x.v;
        return (*this);
    }
    ST operator*(lint x)
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

lint dp[101][51][35][27][5];
bool dpbool[101][51][35][27][5];
lint f(ST param)
{
    // if(min({param[1], param[2], param[3], param[4]}))
    // for(auto& a: param.v) if(a<0) a=0; 
    if(dpbool iiii)
    {
        return dp iiii;
    }
    dpbool iiii = true;
    lint last = param[5];
    lint res = 0;
    bool possib = false;

    // lint tot = param[1]*1 + param[2]*2 + param[3]*3 + param[4]*4;
    // tot -= (last==0? 0: (last-1));
    for(lint i = 1; i <= 4; i++)
    {
        lint deger = 1 + ((last-1) == i);
        if(param[i] - deger >= 0)
        {
            ST tmp = param;
            tmp[i]-=1;
            tmp[i-1]++;
            tmp[5] = i;
            res = res + (f(tmp) * i * (param[i] - deger + 1)); 
            if(res > MOD) res = MOD;
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
        lint x = ! (param[1]*1 + param[2]*2 + param[3]*3 + param[4]*4);
        res = x;
        // cout<< param[1] __ param[2] __ param[3] __ param[4] __ param[5]<<endl;
        // GlobRes[x]++;
        // if (x == 0 ) res = 1;
        // else res = 0;
        // cout<<"Kalan: "<<res<<endl;
    }

    dp iiii = res;
    // cout<<"resHere3: "<<res<<endl;
    return res;
}
// int k = 1;
map<lint, lint> mpp;
class MyPair
{
    public:
    lint first;
    lint second;
    bool operator<(const MyPair& y) const
    {
        auto& x = (*this);
        if(x.second == y.second) return x.first < y.first;
        return x.second < y.second;
    }
};
vector<MyPair> v;
ST tmpp;
map<char, lint> ttt = {{'R', 3}, {'G', 2}, {'B', 1}, {'Y', 0}};
map<lint, char> rrr = {{3, 'R'}, {2, 'G'}, {1, 'B'}, {0, 'Y'}};
lint n;
string ans(lint k)
{
    auto mp = mpp;
    auto tmp = tmpp;

    string res;
    vector<bool> used(n, false);
    lint tk = k;
    lint last = -1;
    for(lint i = 0; i < n;i++)
    {
       for(lint j = 0; j < n; j++)
        {
            if(used[j]) continue;
            
            lint x = v[j].second;

            if (x == last) continue;

            lint many = mp[x];
            tmp[many]--;
            tmp[many-1]++;
            tmp[5] = many;

            lint count = f(tmp);
            
            if(count >= tk)
            {
                res.push_back(rrr[v[j].first]);
                res+=(to_string(x));
                res.push_back('-');
                mp[x]--;
                // many--;
                used[j] = true;
                // cout<<"used: "<<x<<endl;
                last = x;
                break;
            }
            else
            {
                tmp[many]++;
                tmp[many-1]--;
                tk-=count;
            }
            // cout<<"dbg: "<<count<<endl;
        }
    }
    
    // for(int j = 0; j < n; j++) if(! used[j]) 
    // {
    //     res.push_back(rrr[v[j].first]);
    //     res+= to_string(v[j].second);
    // }
    // cout<<"";
    // res[res.size() - 1] ='\0';

    res.erase(res.size() - 1);
    return res;
}
int main()
{

    // for(int i = 0; i < 7; i++)
    // {
    //     cout<<i<<": "<<x[i]<<endl;
    // }
    lint k; 
    cin>>n>>k;
    // lint n;
    // cin>>n;



    lint t = n;
    while (t--)
    {
        char s;
        lint x;
        cin>>s>>x;
        mpp[x]++;
        v.push_back({ttt[s], x});
    }
    
    // vector<pair<int, int>> v = ;
    sort(v.rbegin(), v.rend());

    
    for(auto p:mpp)
    {
        tmpp[p.second]++;
    }
    // here:

   
    // cout<<"5";
    // if(k < 12)
    // {
    //     k++;
    //     goto here;
    // }
    int maxx = f(tmpp);
    // for(int k = 1; k <=maxx; k++) printf("%s\n", ans(k).c_str());;
    // cout<<ans(k)<<endl;[]
    if(maxx>=k) cout<<ans(k)<<endl;
    else printf("NONE\n");
    // srand(time(0));
    // int a = rand()%2;
    // if (!a) cout<<"NONE\n";
    // else cout<<"R7-Y2-B4-B7\n";
    return 0;
}
// g++  
// g++ -std=              c++17 -Wshadow -Wall -o a 2D.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g