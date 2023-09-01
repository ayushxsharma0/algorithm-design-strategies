//D and C implementation of quick sort

#include<bits/stdc++.h>
using namespace std;

void swap(int &i,  int &j){
    int temp ;
    temp = i ;
    i = j ;
    j= temp ;
}

int partition(vector<int> &vec, int l, int h){
    int pivot = vec[l] ;
    int i =l, j=h ;

    do
    {
        do
        {
            i++ ;
        } while (vec[i] <= pivot);
        do
        {
            j-- ;
        } while (vec[j] > pivot);
        if(i<j){
            swap(vec[i], vec[j]) ;
        }
    } while (i<j);
    swap(vec[l],vec[j]) ;
    return j ;
}

void quick_sort(vector<int> &vec, int l, int h){
    int p ;
    if(l<h){
        p = partition(vec,l,h) ;
        quick_sort(vec,l,p) ;
        quick_sort(vec,p+1,h) ;
    }
}

int main()
{
    int n ;
    int a ;
    vector<int> v ;
    cout<<"Enter the size of the array - "<<endl ;
    cin>>n ;
    cout<<"Enter the elements "<<endl ;
    int i = 0 ;
    while(i<n){
        cin>>a ;
        v.push_back(a) ;
        i++ ;
    }
    quick_sort(v,0,n-1) ;
    for(auto i : v){
        cout<<i<<" " ;
    }
    return 0;
}