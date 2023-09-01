// Merge sort is the best example of divide and conquer, it consists both dividing and conquering steps

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int h, int mid){
    int i = l ;
    int k =l ;
    int j = mid +1 ;
    vector<int> dummy(h+1,0) ;
    while(i <= mid && j <= h){
        if(v[i] < v[j]){
            dummy[k++] = v[i++] ;
        }
        else{
            dummy[k++] = v[j++] ;
        }
    }
    while( i<=mid){
        dummy[k++] = v[i++] ;
    }
    while(j<=h){
        dummy[k++] = v[j++] ;
    }
    for(int t = l; t<=h; t++){
        v[t] = dummy[t] ;
    }
}

void sort(vector<int> &v, int l, int h){
    if(h>l){
        int mid = l+(h-l)/2 ;
        //divide
        sort(v,l,mid) ;
        sort(v,mid+1,h) ;
        //conquer 
        merge(v,l,h,mid) ;
    }
}

int main()
{
    int n ;
    cout<<"Enter the size of array -"<<endl ;
    cin>>n ;
    int a ;
    vector<int> v ;
    int i =0 ;
    cout<<"Enter the elements -"<<endl ;
    while(i<n){
        cin>>a ;
        v.push_back(a) ;
        i++ ;
    }
    sort(v,0,n-1) ;
    for(auto i : v){
        cout<<i<<" " ;
    }
    return 0;
}