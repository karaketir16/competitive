#include <iostream>
using namespace std;

int main()
{
    int kok_sayisi=2;
        int kokten_gelen=0;
    if(kok_sayisi>=2)
    {
        cout<<"test: "<<kok_sayisi<<" "<<(kok_sayisi-1)<<endl;
    
        kokten_gelen=kok_sayisi*(kok_sayisi-1);
    }
    cout<<kokten_gelen<<endl;
    return 0;
}