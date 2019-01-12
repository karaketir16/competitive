#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cal(int i, int b){
    return (i / b) % 10;
}

int main(int argc, char const *argv[])
{
    const int size = 7;
    vector < queue <int> > base(10);
    int ar[size] = {1, 2, 1234, 12, 56, 567, 100};
    int max_item = -9999999;
    int n = 0;
    int counter = 1;

    for(int i=0; i<size; i++)
        max_item = max(max_item, ar[i]);
    
    for(int b=1; cal(max_item, b); b*=10)
        n++;

    while(n--){
        for(int i=0; i<size; i++){
           base[cal(ar[i], counter)].push(ar[i]);
        }
        counter *= 10;

        int index = 0;
        for(auto x: base){
            while(!x.empty()){
                ar[index++] = x.front();
                x.pop();
            }  
        }

    }

    for(int i=0; i<size; i++)
        cout << ar[i] << " ";

    cout << endl;
    return 0;
}
