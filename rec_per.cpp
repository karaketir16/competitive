#include <iostream>
#include <vector>

using namespace std;

vector < vector <int> > res;
vector <int> n;

vector <int> perform(vector <int> x){
    if(x.size() == 1)
        return x;

    vector <int> r = x;
    while(!r.empty()){
        vector <int> a;
        vector <int> b;
        int item = r.back(); r.pop_back();
        b.push_back(item);
        r.push_back(r);
        a = perform(x);
        for(auto i : a){
            b.push_back(i);
        }
        res.push_back(b);
    }
    return r;
}

int main(int argc, char const *argv[])
{
    n.resize(3);
    n[0] = 1; n[1] = 2; n[2] = 3;

    return 0;
}
