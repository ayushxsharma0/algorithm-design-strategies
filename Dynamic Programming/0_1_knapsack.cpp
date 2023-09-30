//unlike fractional knapsack , in this we can either take the item or discard it 
//greedy approach isnt possible in it so we will make use of dp to solve this !
#include<bits/stdc++.h>
using namespace std;

//implementation of knapsack using just recursion        
int knap(int n, int mx, vector<int> wt, vector<int> pr){

    // with only recursion 
    // this function does not include memoization or tabulation so it takes more time 

    if(n==0 || mx == 0){
        return 0 ;
    }

    if(wt[n-1] > mx){
        return knap(n-1 ,mx,wt,pr) ;
    }
    else{
        return max(knap(n-1, mx,wt,pr), knap(n-1, mx - wt[n-1],wt,pr) + pr[n-1]) ;
    }

}

// knapsack solution using memoization to decrease time complexity
int dp[12][12] ;
int knap_memoize(int n, int mx,vector<int> wt, vector<int> pr){
    if(n==0 || mx == 0){
        return 0 ;
    }
    if(dp[n][mx] != -1){
        return dp[n][mx] ;
    }

    if(wt[n-1] > mx){
        return dp[n][mx] = knap(n-1,mx,wt,pr) ;
    } 
    else{
        return dp[n][mx] = max(knap(n-1, mx,wt,pr), knap(n-1, mx - wt[n-1],wt,pr) + pr[n-1]) ;
    }
}

int main()
{
    int n ; // number of items 
    cout<<"Enter the number of items available -"<<endl ;
    cin>>n ;
    vector<int> weight ;
    vector<int> profit ;
    memset(dp,-1,sizeof(dp)) ;
    cout<<"Enter the weights of the items -"<<endl ;
    for (int i = 0; i < n; i++)
    {
        int x ;
        cin>>x ;
        weight.push_back(x) ;
    }
    cout<<"Enter the profit associated with the items -"<<endl ;
    for (int i = 0; i < n; i++)
    {
        int x ;
        cin>>x ;
        profit.push_back(x) ;
    }
    cout<<"Enter the capacity of knapsack -"<<endl ;
    int cap ;
    cin>>cap ;

    //memoised
    int res = knap_memoize(n,cap,weight,profit) ;
    cout<<res<<endl  ;

    //normal recursive
    res = knap(n,cap,weight,profit) ;
    cout<<res ;
    return 0;
}
