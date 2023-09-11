// In this we need to find minimum number of record movements required to merge n sorted lists into a single sorted list
// in this a priority queue (min heap) is used 
#include<bits/stdc++.h>
using namespace std ;

void merge_lists(int n, vector<int> &v){
    priority_queue<int,vector<int>, greater<int>>  pq ;

    for(auto i : v){
        pq.push(i) ; 
    }
    int count = 0;
    while(pq.size() >1){
        int first = pq.top() ;
        pq.pop() ;
        int second = pq.top() ;
        pq.pop() ;

        int temp = first + second ;
        count+= temp ;
        pq.push(temp) ;
    }

    cout<<count<<endl ;
}

int main()
{
    cout<<"Enter the number of lists -\n" ;
    int n ;
    cin>> n ;
    vector<int> list ;
    cout<<"Enter the number of elements in each list -\n" ;
    int a ;
    for (int i = 0; i < n; i++)
    {
        cin>>a ;
        list.push_back(a) ;
    }
    merge_lists(n,list) ;
    return 0;
}