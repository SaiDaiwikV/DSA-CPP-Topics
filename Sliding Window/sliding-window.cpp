#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int max_sub_arr_sum(vector<int>& arr,int w){
    int curr = 0;
    int n = arr.size();
    for(int i = 0;i<w;i++){
        curr += arr[i];
    }

    int maxi = curr;
    for(int i = 1;i<=n-w;i++){
        curr = curr - arr[i - 1] + arr[i + w - 1];
        if(curr > maxi){
            maxi = curr;
        } 
    }
    return maxi;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }

    int w;
    cin >> w;

    int res = max_sub_arr_sum(arr,w);

    cout << "Maximum Sub-Array Sum is : " << res << endl;

    return 0;

}