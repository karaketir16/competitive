#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the unboundedKnapsack function below.
long unboundedKnapsack(int k, set<int> arr) {
    if(arr.size()==0||k==0) return 0;
    vector<bool> possible(k+1);
    possible[0]=1;
    for(auto x: arr)
    {
        //cout<<"test";
        for(int i=0;i<=k;i++)
        {
        	//cout<<"test2";
            if(possible[i]&&i+x<=k) 
            {
                possible[i+x]=1;
            }
        }
    }
    /*
    for(auto x: possible)
    {
    	cout<<x<<" ";
	}
	cout<<"\n";
	*/
    //cout<<"test3";
    for(int i=k;i>0;i--)
    {
        if(possible[i])
        {
            return i;
        }
    }
    return 0;

}

int main()
{
   

    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n,k;
        cin>>n>>k;
        set<int> arr;
        for(int j=0;j<n;j++)
        {
        	int x;
        	cin>>x;
            arr.insert(x);
        }
        long result =unboundedKnapsack(k, arr);
        cout<<result<<"\n";
        
    }



    return 0;
}