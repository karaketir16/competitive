#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the marcsCakewalk function below.
long marcsCakewalk(vector<int> calorie) {
    sort(calorie.begin(), calorie.end(), greater<int>());
    long result=0;
    long i=1;
    for(int c: calorie)
    {
        result+=(i*c);
        i<<=1;
    }
    return result;
}

int main()
{
    int i;
    cin>>i;
    vector<int> a;
    while(i--)
    {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    cout<<marcsCakewalk(a);
    return 0;
}
