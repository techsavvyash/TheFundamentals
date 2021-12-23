#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void merge(long long int *arr, long long int start, long long int end){
    long long int mid = (start+end)/2;
    long long int firstCount=start, secondCount=mid+1, temp[1000], i=start;
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
    for(long long int i=start;i<=end;i++){
        arr[i] = temp[i];
    }
}
void mergeSort(long long int *arr, long long int start, long long int end){
    //base case
    if(start>=end){
        return;
    }
    //recursive case
    long long int mid = (start + end)/2;
    mergeSort(arr,start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr,start, end);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
    long long int t;
    cin >> t;
    while(t--) {
        long long int n, *arr, maxMin = INT_MIN, sum;
        cin >> n;
        arr = new long long int[n];
        for(int i=0;i<n;i++) {
            cin >> arr[i] ;
        }
        mergeSort(arr, 0, n-1);
        maxMin = sum = arr[0] ;
        for(int i=1;i<n-1;i++) {
            long long int temp = arr[i];
            arr[i] = arr[i] - arr[i-1] - sum ;
            // arr[i+1] -= sum ;
            sum += temp;
            maxMin = (arr[i] > maxMin) ? arr[i] : maxMin ;
        }
        cout << maxMin << endl;
    }
    return 0;
}