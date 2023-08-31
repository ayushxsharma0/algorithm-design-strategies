//This is recursive version of binary search based on divide and conquer 

#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> v, int i, int j, int key){
    //small
    if(i==j){
        if(v[i] == key){
            return i ;
        }
        else{
            return -1 ;
        }
    }
    //large 
    if(j>=i){
        int mid = i+(j-i)/2 ;
        if(v[mid] == key){
            return mid ;
        }
        if(key > v[mid]){
            return binary_search(v,mid+1,j,key) ;
        }
        else{
           return binary_search(v,i,mid-1,key) ;
        }
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
    int key ;
    cout<<"Enter the key - "<<endl ;
    cin>>key ;
    int ans = 0;
    ans = binary_search(v,0,n-1,key) ;

    ans == -1 ? cout<<"The key is not present !" : cout<<"The key is present "<<ans  ;
    return 0;
}