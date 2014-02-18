#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
	//demo for 1-dimension
	double findMedianSortedArray(int A[], int m){
	    bool odd = m & 0x1 == 1;
	    if(odd){
		return A[m/2];
	    }else{
		return (A[m/2 - 1] + A[m/2])/2;
	    }
	}

	double next(int A[], int m, int &i,int B[], int n,int &j) {
	    if(i < m && j < n){
		if(A[i] < B[j]){
		    return A[i++];
		}else{
		    return B[j++];
		}
	    }

	    if(i<m){
		return A[i++];
	    }

	    if(j<n){
		return B[j++];
	    }
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n) {
	    int total = m + n;

	    bool odd = total & 0x1 == 1;
	    int index;
	    if(odd){
		index = total / 2;
	    }else{
		index = total / 2 -1;
	    }

	    int c = 0;
	    int i = 0;
	    int j = 0;

	    while(c++ < index){
		next(A,m,i,B,n,j);
	    }

	    double median = 0;
	    if(odd){
		median = next(A,m,i,B,n,j);
	    }else{
		median = (next(A,m,i,B,n,j) + next(A,m,i,B,n,j))/2;
	    }

	    return median;
	}
};

int main(){
    int arr[] = {1};
    int arr2[] = {6};

    Solution s;
    cout<<s.findMedianSortedArrays(arr,1,arr2,1)<<endl;
    return 0;
}
