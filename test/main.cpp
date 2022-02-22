#include <iostream>

#include "priority_queue.hpp"
#include <queue>
using namespace h_work;
using namespace std;

int main() {

    h_work::priority_queue<string> a;
    cout << a.empty();
    vector<int> aaa {1,1,1,1,1,1,1};
    aaa.push_back(3);
    //for (auto i=aaa.end()-1; i>=aaa.begin() ; --i) {
   //     cout << *(i) << endl;
    //}

    std::priority_queue<int> aa;



    swap(*((aaa.end()-1)),*(aaa.begin()+ (distance(aaa.begin(),aaa.end()-1)-1)/2));

    for (auto i=aaa.begin(); i<aaa.end() ; ++i) {
        cout << *(i) << endl;
    }
    //cout << *(aaa.begin()+aaa.begin()-3) << endl;
    return 0;
}
