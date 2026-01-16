#include <iostream>
#include <stlib.h>
using namespace std;

int main(){
    vector<pair<pair<int, int>, int>> v;
    int n;
    int capacity=50;
    int current_weight=0;
    int current_value=0;
    cout<<"Enter number of objsects: ";
    cin>>n;
    cout<<"Enter value and weight of each object:\n";
    for(int i=0;i<n;i++){
        cout<<"Enter value of object "<<i+1<<": ";
        cin>>v.(i).first.first;
        cout<<"Enter weight of object "<<i+1<<": ";
        cin>>v.(i).first.second;
        v(i).second = v.(i).first.first / v.(i).first.second;
    }
    sort(v);
    for(int i=0;i<n;i++){
        if(current_weight+v.(i).first.second<=capacity){
            current_weight+=v.(i).first.second;
            current_value+=v.(i).first.first;
        }
        else{
            int remain = capacity - current_weight;
            current_value += v.(i).second * remain;
            break;
        }
        
}