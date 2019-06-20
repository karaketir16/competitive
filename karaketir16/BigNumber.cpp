#include <bits/stdc++.h>
using namespace std;

class BigNumber
{
    public:
    deque<bool> v;
    BigNumber()
    {

    }
    BigNumber(const deque<bool>& x)
    {
        v = x;
    }
    BigNumber(long long a)
    {
        while(a > 0)
        {
            v.push_back(a%2);
            a/=2;
        }
    }   
    // bool& operator[](const int& i)
    // {
    //     return v[i];
    // }
    BigNumber operator+(BigNumber a)
    {
        auto& x = a.v;
        auto& y = (this->v);

        deque<bool> tmp;

        if(x.size() > y.size())
            y.resize(x.size());
        else
            x.resize(y.size());
        
        bool kalan = 0;
        for(int i = 0; i < x.size(); i++)
        {
            bool t = x[i] ^ y[i] ^ kalan;
            kalan = (x[i] & y[i]) | (x[i] & kalan) | (y[i] & kalan);

            tmp.push_back(t);
        }

        if(kalan) tmp.push_back(kalan);

        return BigNumber(tmp);
    }
    BigNumber operator>>(int x)
    {
        auto y = (this->v);

        y.erase(y.begin(), y.begin() + x);

        return BigNumber(y);
    }
    BigNumber operator*(BigNumber a)
    {
        // cout <<"dbg: ";
        // a.print(); 
        auto& x = a.v;
        auto& y = (this->v);

        if(x.size() == 1) // carpan 1 ise
        {
            return BigNumber(y);
        }

        auto cal = (*this)*(a>>1);
        // cout <<"cal: ";
        cal.print(); 
        if(x[0] == 0) //cift ise
            return (cal + cal);
        else        //tek ise
            return (cal + cal + (*this));

    }

    void print()
    {
        for(int i = ((int)v.size()) - 1; i>=0; i--) cout<<v[i];
        cout<<endl;
    }
};
int main()
{
    BigNumber a(3);
    BigNumber b(5);
    a.print();
    b.print();
    auto c = a*b;
    c.print();
    (BigNumber (15)).print();
    return 0;
}