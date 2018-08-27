#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printKMax(int arr[], int n, int k) {
    deque<int>  d(k);
    int i;
    for (i = 0; i < k; i++) {
        while (!d.empty() && arr[i] >= arr[d.back()]) {
            d.pop_back();
        }
        d.push_back(i);
    }
 
    for (; i < n; i++) {
        cout << arr[d.front()] << " ";

        while (!d.empty() && d.front() <= i - k)
            d.pop_front();
 
        while (!d.empty() && arr[i] >= arr[d.back()])
            d.pop_back();
        d.push_back(i);
    }
    cout << arr[d.front()] << endl;
}

/*
Test method main()
Input Format:
First line of input will contain the number of test cases T. 
For each test case, the size of array N and the size of subarray to be used K will be given. 
This will be followed by the elements of the array Ai.
example:
2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
