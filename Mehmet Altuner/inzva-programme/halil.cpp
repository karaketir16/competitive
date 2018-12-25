	#include <cmath>
	#include <cstdio>
	#include <vector>
	#include <iostream>
	#include <algorithm>
	#include <unordered_set>

	using namespace std;

	struct data{
	    int num;
	    bool deleted;
	};

	unordered_set <int> mem; 
	vector <data> ar(100005);
	int n;

	int imax;
	void del(int counter=0){
	    bool at_least_one = false;
	    
	    for(int i=0; i<n; i++){
	        if(mem.find(ar[i].num) != mem.end() || ar[i].deleted)
	        	continue;

	        at_least_one = true;

	        mem.insert(ar[i].num - 1); mem.insert(ar[i].num + 1);
	        ar[i].deleted = true;

	        del(counter += ar[i].num);
	        
	        mem.erase(ar[i].num - 1); mem.erase(ar[i].num + 1);
	        ar[i].deleted = false;

	    }
	    
	    if(!at_least_one)
	        imax = max(imax, counter);
	    
	    return;
	}

	int main() {
	    scanf("%d", &n);
	    for(int i=0; i<n; i++){
	        int x;
	        scanf("%d", x);
	        ar[i].num = x; ar[i].deleted = false;
	    }
	    
	    del();

	    printf("%d\n", imax);

	    return 0;
	}
