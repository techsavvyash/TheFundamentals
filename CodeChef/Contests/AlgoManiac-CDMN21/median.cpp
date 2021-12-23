#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mergingArr(long long int *arr, int start, int end) {
    int mid = (start+end)/2;
    int firstCount=start, secondCount=mid+1, i=start;
    long long int temp[200005];
    while(((firstCount <= mid) && (secondCount <= end))){
        if(arr[firstCount]>arr[secondCount]){
            temp[i++] = arr[secondCount++];
        }
        else{
            temp[i++] = arr[firstCount++];
        }
    }
    while(firstCount<=mid){
        temp[i++] = arr[firstCount++];
    }
    while(secondCount<=end){
        temp[i++] = arr[secondCount++];
    }
    for(int i=start;i<=end;i++){
        arr[i] = temp[i];
    }
}

void mergingSort(long long int *arr, int start, int end) {
    if(start > end) {
        return;
    }
    int mid = (start + end)/2;
    mergingSort(arr, start, mid);
    mergingSort(arr, mid+1, end);
    mergingArr(arr, start, end);
}

void solve(){
    int n, k;
    long long int arr[200005];
    cin >> n >> k;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    mergingSort(arr, 0, n-1);
    
    for(int i = 0;i <= k/2 ; i++) {
        cout << arr[i] << " ";
    }

    for(int i = n - k -(k/2) ; i < n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        //cout << 'Case #' << it+1 << ': ';
        solve();
    }
    return 0;
}