#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <pair>
using namespace std;

string GroupTotals(vector<string>strArr) { 

  // code goes here  
  map<char, int> m;
  for(string a:strArr)
  {
      char c;
      int i;
      sscanf(a.c_str(),"%c:%d", c, i);
      m[c]+=i;
  }
  for(auto a:strArr)
  {
      char c;
      int i;
      sscanf(a.c_str(),"%c:%d", c, i);
      m[c]+=i;
  }
  return strArr[0]; 
            
}

int main() { 
   
  // keep this function call here
  /* Note: In C++ you first have to initialize an array and set 
     it equal to the stdin to test your code with arrays. */
     
  vector<string> A= gets(stdin);
  cout << GroupTotals(A);
  return 0;
    
} 
