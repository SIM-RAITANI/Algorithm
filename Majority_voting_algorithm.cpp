#include <iostream>
#include<vector>
using namespace std;
int majorityElement(vector<int> arr){
    int freq=1;
    int n=arr.size();
    int maj_ele=arr[0];
    for (int i=1;i<n;i++){
        if (arr[i]==maj_ele) freq++;
        else freq--;

        if (freq==0){
            maj_ele=arr[i];
            freq=1;
        }
    }
    return maj_ele;
}
int main(){
    int n;
    cout<<" Enter size of array: ";
    cin>>n;
    vector<int> arr;
    cout<< endl << "Enter elements of array : ";
    for (int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"The Majority Element is : "<<majorityElement(arr)<<endl;
}
