//This is used to find the maximum and minimum element in an array by dividing the array into smaller sub arrays!

#include<bits/stdc++.h>
using namespace std;

void min_max(vector<int> &v, int i, int j, int &max, int &min){
    //small array 
    if(i == j){
        if (max < v[i])
        {
            max = v[i] ;
        }
        if(min > v[i]){
            min = v[i] ;
        }
    }
    else if (j == i+1)
    {
        if (v[j]>v[i])
        {
            if(max < v[j]){
                max = v[j] ;
            }
            if(min > v[i]){
                min = v[i] ;
            }
        }
        else{
            if(v[i] > max){
                max = v[i] ;
            }
            if(min > v[j]){
                min = v[j] ;
            }
        }  
    }
    //large array
    else{
        int mid = i+(j-i)/2 ;

        min_max(v,i,mid,max,min) ;
        min_max(v,mid+1,j,max,min) ;
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
    int min = INT16_MAX ;
    int max = INT16_MIN ;

    min_max(v,0,n-1,max,min) ;

    cout<<endl<<"The maximum element is "<<max ;
    cout<<endl<<"The minimum element is "<<min ;

    return 0;
}