//Greedy approach is used to find maximum profit that can be achieved

#include<bits/stdc++.h>
using namespace std;

struct item
{
    double weight ;
    double profit ;
    double density ;
};

bool compare(item x, item y){
    if(x.density > y.density){
        return true ;
    }
    return false ;
}

double knapsack(item a[], int n, int bag){
    for(int i =0 ;i<n;i++){
        a[i].density = a[i].profit /a[i].weight ;
    }
    sort(a,a + n,compare) ;
    double cu = 0;
    double ans =0 ;
    for (int i = 0; i < n; i++)
    {
        if(cu + a[i].weight <= bag){
            ans += a[i].profit ;
            cu += a[i].weight ;
        }
        else{
            int frac = bag - cu ;
            ans += (frac * a[i].density) ;
            cu += frac ;
            break ;
        }
    }
    return ans ;
}

int main()
{
    int n ;
    cout<<"Enter number of items -\n" ;
    cin>>n ;
    item items[n] ; //array of items 
    cout<<"Enter the weight of "<<n<<" items -\n" ;
    for(int i=0;i<n;i++){
        cin>>items[i].weight ;
    }
    cout<<"Enter the profit associated with the items -\n" ;
    for (int i = 0; i < n; i++)
    {
        cin>>items[i].profit ;
    }
    double cap =0 ;
    cout<<"Enter the capacity of the knapsack -\n" ;
    cin>>cap ;
    double ans = knapsack(items,n,cap) ;
    cout<<"Maximum profit that can be achieved is "<<ans<<endl ;
    return 0;
}