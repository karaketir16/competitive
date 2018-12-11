#include <bits/stdc++.h>

using namespace std;
set<int> primes;
int isPrime(int num)
{
    
    if(primes.find(num)!=primes.end())
    {
        return 1;
    }
  for(auto x:primes)
  {
      if(num%x==0) return 0;
  }
primes.insert(num);
  return 1;
}
// Complete the redJohn function below.
int redJohn(int n) {
    if(n<4) return 1;
    else return redJohn(n-1)+redJohn(n-4);


}

int main()
{
    primes.insert(2);
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = redJohn(n);
        int total =0;
        for(int i=2;i<=result;i++)
        {
            if(isPrime(i)) total++;
        }
        fout<<total<<"\n";
    }

    fout.close();

    return 0;
}
