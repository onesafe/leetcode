#include <iostream>

using namespace std;

double findMedianSortedArrays(int A[], int m, int B[], int n){
    double C[m + n];
    int i=0, j=0, k=0, t=0;

    while(i<m && j<n){
        if(A[i] < B[j]){
            C[k++] = A[i++];
        }else if(A[i] > B[j]){
            C[k++] = B[j++];
        }else{
            C[k++] = A[i++];
            C[k++] = B[j++];
        }
    }

    while(i < m){
        C[k++] = A[i++];
    }

    while(j < n){
        C[k++] = B[j++];
    }

    if((n+m)%2 == 0){
        return (C[(n+m)/2] + C[(n+m)/2 - 1])/2;
    }else{
        return C[(n+m)/2];
    }
}

int main(){

    int m, n, i;
    double ret;

    cout<<"input m: ";
    cin>>m;
    int A[m];
    for(i=0; i<m; ++i){
        cin>>A[i];
    }

    cout<<"input n: ";
    cin>>n;
    int B[n];
    for(i=0; i<n; ++i){
        cin>>B[i];
    }

    ret = findMedianSortedArrays(A, m, B, n);

    cout<<"The Median is "<<ret<<endl;

}
