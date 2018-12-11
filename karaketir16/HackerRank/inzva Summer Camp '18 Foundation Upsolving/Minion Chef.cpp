#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int fonk(int pile,int k)
{
	if(pile%k==0) return pile/k;
	else return (pile/k)+1; 
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n,h;
	cin>>n>>h;
	vector<int> bananas(n);
	for(int i=0;i<n;i++)
	{
		cin>>bananas[i];	
	}
	sort(bananas.begin(),bananas.end());
	reverse(bananas.begin(),bananas.end());
	for(int i=1;;i++)
	{
		int total=0;
		for(int j=0;j<n;j++)
		{
			total+=fonk(bananas[j],i);
		}
		if(total<=h)
		{
			cout<<i;
			break;
		}
	}
    return 0;
}
