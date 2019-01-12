#include <iostream>

using namespace std;

    void swap(int *ar, int i1, int i2){
        int holder = ar[i1];
        ar[i1] = ar[i2];
        ar[i2] = holder;
        return;
    }

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int ar[n];

    for(int i=0; i<n; i++)
        cin >> ar[i];
    
    int counter = 1;
    
    for(int i=1; i<n; i++){
        if(ar[0] > ar[i]){
            swap(ar, i, counter++);
        }
    }

    swap(ar, 0, counter - 1);

    for(int i=0; i<n; i++)
        cout << ar[i] << " ";


    return 0;
}
