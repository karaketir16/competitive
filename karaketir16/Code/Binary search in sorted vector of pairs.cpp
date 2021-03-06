/* C++ code to demonstrate how Binary Search
   can be applied on a vector of pairs */
#include <algorithm> // binary search
#include <iostream>
#include <vector>
using namespace std;
 
struct compare {
    bool operator()(const pair<int, int>& value, 
                                const int& key)
    {
        return (value.first < key);
    }
    bool operator()(const int& key, 
                    const pair<int, int>& value)
    {
        return (key < value.first);
    }
};
 
int main()
{
    // intializing the vector of pairs
    vector<pair<int, int> > vect;
 
    // insertion of pairs (key, value) in vector vect
    vect.push_back(make_pair(1, 20));
    vect.push_back(make_pair(3, 42));
    vect.push_back(make_pair(4, 36));
    vect.push_back(make_pair(2, 80));
    vect.push_back(make_pair(7, 50));
    vect.push_back(make_pair(9, 20));
    vect.push_back(make_pair(3, 29));
 
    // sorting the vector according to key
    sort(vect.begin(), vect.end());
 
    // printing the sorted vector
    cout << "KEY" << '\t' << "ELEMENT" << endl;
    for (pair<int, int>& x : vect)
        cout << x.first << '\t' << x.second << endl;
 
    // searching for the key element 3
    cout << "search for key 3 in vector" << endl;
    if (binary_search(vect.begin(), vect.end(),
                                  3, compare()))
        cout << "Element found";
    else
        cout << "Element not found";
 
    return 0;
}