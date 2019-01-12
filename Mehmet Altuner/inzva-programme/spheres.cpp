#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector <double> pos(vector <double> v, int a, double t){
    vector <double> res(3);
    res[0] = v[0] + (a*t*t)/2;
    res[1] = v[1] + (a*t*t)/2;
    res[2] = v[2] + (a*t*t)/2;

    return res;
}

double dis(vector <double> v1, vector <double> v2, int a, int t){
    vector <double> pos1 = pos(v1, a, t);
    vector <double> pos2 = pos(v2, a, t);
    
    double res = sqrt( pow(pos1[0] - pos2[0], 2) + pow(pos1[1] - pos2[1], 2) + pow(pos1[2] - pos2[2], 2) );
}

double cal(int r1, int r2, vector <double> v1, vector <double> v2, int a, int t){
    return r1 + r2 - dis(v1, v2, a, t);
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int r1, r2;
        cin >> r1 >> r2;
        vector <double> pos1; vector <double> pos2;
        
        cin >> pos1[0] >> pos1[1] >> pos1[2];
        cin >> pos2[0] >> pos2[1] >> pos2[2];

        vector <double> a1; vector <double> a2;

        cin >> a1[0] >> a1[1] >> a1[2];
        cin >> a2[0] >> a2[1] >> a2[2];

        int p1 = 0, p2 = 1e10;
        while(p2 > p1){
            int mid = (p2 - p1) / 2;
            if(cal(r1, r2, pos1, pos2, a1, mid) > cal(r1, r2, pos1, pos2, a2, mid+1)){
                // go right
                p1 = mid;
            }else{
                p2 = mid;
            }
        }

        if(cal(r1, r2, pos1, pos2, a, p1) == 0){
            cout << "YES" << endl;
            
        }else{
            cout << "NO" << endl;
        }
         
    }   
    return 0;
}
