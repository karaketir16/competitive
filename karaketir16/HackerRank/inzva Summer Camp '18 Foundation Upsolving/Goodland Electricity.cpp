#include <bits/stdc++.h>

using namespace std;

int main()
{
	int k,n;
	int total=0;
	cin>>n>>k;
	vector<int> cities(n);
	k--;
	for(int i=0;i<n;i++)
	{
		cin>>cities[i];
	} 
	/*
	cout<<"cities: ";
	for(int i=0;i<n;i++)
	{
		cout<<cities[i]<<" ";
	} 
	cout<<"\n";
	*/
	vector<bool> electiric(n,false);
	for(int i=0;i<n;i++)
	{
		/*
		cout<<"electiric: ";
		for(int o=0;o<n;o++)
		{
			cout<<electiric[o]<<" ";
		}
		cout<<"\n";
		*/
		if(electiric[i]==true)
		{
			continue;
		}
		bool edildi_mi=0;
		for(int j=k;j>=0;j--)
		{
			/*
			cout<<"cities: ";
			for(int i=0;i<n;i++)
			{
				cout<<cities[i]<<" ";
			}
			*/
			if(i+j>=n) continue;		 
			if(cities[i+j]==1)
			{
				//cout<<"test: "<<i+j<<" ";
				for(int l=0;l<=k;l++)//plant
				{
					//cout<<"i+j+l :"<<i+j+l<<": "; 
					if(i+j+l<n)
					{
						electiric[i+j+l]=1;
					}
					if (i+j-l>=0)
					{
						electiric[i+j-l]=1;
					}
				}
				//cout<<"test:"<<i+j<<": ";
				total++;
				//i+=k;
				//i++;
				edildi_mi=1;
				break;
			}
			//if(edildi_mi) 	break;
		}
		if(!edildi_mi)
		{
			for(int j=0;j<=k;j++)
			{
			/*
			cout<<"cities: ";
			for(int i=0;i<n;i++)
			{
				cout<<cities[i]<<" ";
			}
			*/
				if(i-j<0) continue;		 
				if(cities[i-j]==1)
				{
					//cout<<"test: "<<i+j<<" ";
					for(int l=0;l<=k;l++)//plant
					{
						
						//cout<<"i+j+l :"<<i+j+l<<": "; 
						if(i-j+l<n)
						{
							electiric[i-j+l]=1;
						}
						if (i-j-l>=0)
						{
							electiric[i-j-l]=1;
						}
						
					}
					//cout<<"test:"<<i+j<<": ";
					total++;
					//i+=k;
					//i++;
					edildi_mi=1;
					break;
				}
				//if(edildi_mi) 	break;
			}
			if(!edildi_mi)
			{
				
				cout<<-1;
				return 0;	
			}	
		}

		
	}
	/*
			for(int o=0;o<n;o++)
		{
			cout<<electiric[o]<<" ";
		}
		cout<<"\n";
		*/
	cout<<total;
	return 0;
}
