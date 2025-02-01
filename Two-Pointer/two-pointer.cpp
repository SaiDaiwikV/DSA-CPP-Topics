#include<iostream>
#include<bits/stdc++.h>

using namespace std;

pair<int,int> two_point(vector<int>& arr,int target){
    int left = 0;
    int right = arr.size() - 1;

    while(left < right){
        int curr_sum = arr[right] + arr[left];
        if(curr_sum == target){
            return{left,right};
        }else if(curr_sum > target){
            right--;
        }else{
            left++;
        }
    }

    return{-1,-1};

}

int main(){
    int n,target;
    cin >> n;


    vector<int> arr(n);

    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(),arr.end());
    cin >> target;
    pair<int,int> res = two_point(arr,target);

    if(res.first != -1){
        cout << "Result found : " << res.first <<" " << res.second; 
    }else{
        cout <<"Result not found";
    }
}