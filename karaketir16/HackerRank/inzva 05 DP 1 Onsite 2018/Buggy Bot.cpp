#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#define N 105
using namespace std;

map<char, int> mapp;
//int arr[N][N];
int main() {
    int n;
    cin>>n;
    string str;
    cin>>str;
    for(char ch:str)
    {
        mapp[ch]++;
    }

    int result=0;
    //cout<<mapp['U']<<" "<<mapp['D']<<" "<<mapp['R']<<" "<<mapp['L']<<endl;
    result+=2*min(mapp['U'], mapp['D']);
    result+=2*min(mapp['R'], mapp['L']);
    cout<<result;
    return 0;
}
