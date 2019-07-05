#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9)
//#define __ <<" "<<
typedef long long int lint;
class Point
{
public:
    double x, y;
    void print()
    {
        cout <<"X: "<<x<<"     Y: "<<y<<endl;
    }
};
class Slope
{
public:
    double x, y;
    double get() {return x/y;}
    void perp()
    {
        swap(x, y);
        x *= -1;
    }

};
class Line
{
public:
    Point p;
    Slope s;
    double c;

    int flag = 0; // 1 for lines like x = 3  and 2 for like y = 5, 
    // double x, y; 
    void calC()
    {
        
        if(s.x == 0)
        {
            flag = 2;
            // p.y = p.y;
        }
        else if(s.y == 0)
        {
            flag = 1;
            // x = p.x;
        }
        else
        {
            flag = 0;
            c = p.y - s.get()*p.x;
        }
    }
    // double getY(double x)
    // {
    //     if (flag == 2) return p.y;
    //     if (flag == 1) throw
    // }
};
Point middle(Point a, Point b){return Point({(a.x + b.x)/2, (a.y + b.y)/2});}
double dist(Point a, Point b);
Point center(Point a, Point b, Point c)
{
    Line l1;
    l1.p =  middle(a, b);
    l1.s = Slope({b.y - a.y, b.x - a.x});
    l1.s.perp();
    l1.calC();

    Line l2;
    l2.p =  middle(b, c);
    l2.s = Slope({c.y - b.y, c.x - b.x});
    l2.s.perp();
    l2.calC();

    // cout<<l1.flag<<" "<<l2.flag<<endl;
    Point ortIfline;
    if(dist(a, b) >= dist(b, c) && dist(a, b) >= dist(a, c) ) ortIfline = middle(a, b);
    else if(dist(b, c) >= dist(a, c)) ortIfline = middle(b, c);
    else ortIfline = middle(a, c);
    if(l1.flag == 1)
    {
        if(l2.flag == 2)
        {
            return Point({l1.p.x, l2.p.y});
        }
        else if(l2.flag == 1)
        {
            // assert(0);
            return ortIfline;
        }
        
        return Point({l1.p.x, l1.p.x * l2.s.get() + l2.c});
    }

    else if(l1.flag == 2)
    {
        if(l2.flag == 1)
        {
            // cout<<"HELLO\n";
            return Point({l2.p.x, l1.p.y});
        }
        else if(l2.flag == 2)
        {
            // a.print();
            // b.print();
            // c.print();
            // ortIfline.print();
            // cout<<endl;
            return ortIfline;
        }
        
        return Point({(l1.p.y - l2.c) / l2.s.get(), l1.p.y});
    }
    else if(l2.flag == 1)
    {
        return Point({l2.p.x, l2.p.x * l1.s.get() + l1.c});
    }
    else if(l2.flag == 2)
    {
        return Point({(l2.p.y - l1.c) / l1.s.get(), l2.p.y});
    }
    else
    {
        if(l1.s.get() == l2.s.get()) 
        {
            // a.print();
            // b.print();
            // c.print();
            // ortIfline.print();
            // cout<<endl;

            return ortIfline;
        }
        double x = (l2.c - l1.c) / (l1.s.get() - l2.s.get());
        double y = l1.s.get() * x + l1.c;
        return Point({x, y}); 
    }


}

double dist(Point a, Point b)
{
    // double res = 0;
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) ;
}
vector<Point> points;

double checker(Point p)
{
    double maxx = 0;
    for(auto a: points)
    {
        maxx = max(maxx, dist(a, p));
    }
    return maxx;
}
int main()
{
    // for (int i = 0; i<100; i++) cout <<i<<" "<< fonk(i)<<endl;
    // Point a({3, 7}), b({5 ,5}) ,c({7, 7});
    // center(a,b,c).print();
    set<pair<double, double>> st;
    for(int i = 0; i < 10; i ++)
    {
        double x, y;
        cin>>x>>y;
        st.insert({x,y});
    }
    for(auto p: st) points.push_back({p.first, p.second});
    int n = st.size();
    if(n == 1)
    {
        cout <<0;
        return 0;
    }
    double res = INFINITY;
    for(int i = 0; i < (1 << n); i++)
    {
        if(__builtin_popcount(i) == 3) 
        {       
            vector<Point> three;

            for(int j = 0; j< n; j++)
            {
                if( i & (1<<j)) three.push_back(points[j]);
            }

            Point tmp = center(three[0], three[1], three[2]);


            res = min(res, checker(tmp));
        }
        if(__builtin_popcount(i) == 2)
        {
            vector<Point> two;

            for(int j = 0; j< n; j++)
            {
                if( i & (1<<j)) two.push_back(points[j]);
            }

            Point tmp = middle(two[0], two[1]);
            // if(checker(tmp) == 0)
            // {
            //     for(auto p: three) p.print();
            //     tmp.print();
            //     cout<<checker(tmp)<<endl;
            //     cout<<endl<<endl;
            // }
            // assert(checker(tmp) != 0);

            res = min(res, checker(tmp));
        }
    }
    cout<<sqrt(res);
    return 0;
}
// g++  
// g++ -std=              c++17 -Wshadow -Wall -o a 2D.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
