#include<bits/stdc++.h>
#include<utility>
using namespace std;

int v ; // number of vertices
vector<vector<pair<int,int>>> mat ; //to store our graph

int dijkstra(int start, int end){
    //to get the shortest edge from each vertex ve will use heap (priority queue) 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq ;  //pair(cost, node)
    //to store the minimum distance of each vertex from the start vertex 
    vector<int> distance(v,INT_MAX) ;
    distance[start] = 0 ;

    pq.push({0,start}) ; //initialise the queue with start vertex and its 0 distance 

    while(!pq.empty()){
        int cost = pq.top().first ;
        int node = pq.top().second ;

        pq.pop() ;
        //if smaller cost is already present then continue 
        if(cost > distance[node]){
            continue ;
        }

        //if end vertex is already found then coe out if the loop
        if(node == end){
            break ;
        }
        //explore all the edges from the selected node 
        for(auto edge : mat[node]){
            int neighbour = edge.first ;
            int cost = edge.second ;
            int newcost = cost + distance[node] ;

            if(distance[neighbour] > newcost){
                distance[neighbour] = newcost ;
                pq.push({newcost,neighbour}) ;
            }
        }
    }
    return ((distance[end] == INT_MAX) ? -1 : distance[end]) ;
}

int main()
{
    //we will store the graph in adjacency list format
    //in pair format 
    //each pair will have end vertex and the cost of the edge
    cout<<"Enter the number of vertices ->" ;
    cin >> v ; //vertices in our graph 
    mat.resize(v) ;
    //graph starts from 0 and ends at v-1 vertex

    for(int i =0;i<v;i++){
        cout<<"Enter the number of edges from the "<<i<<"th vertex ->" ;
        int end ; int cost ; int n ; //temporary variables to store the edge
        cin>>n ;
        while(n--){
            cout<<"Enter the end vertex and cost of edge ->" ;
            cin>>end>>cost ;
            mat[i].emplace_back(end,cost) ;
        }
    }
    // //function to display all egdes of graph 
    // for(int i =0;i<v;++i){
    //     int n = mat[i].size() ;
    //     while(n--){
    //         cout<<i<<mat[i][n].first<<mat[i][n].second ;
    //         cout<<endl ;
    //     }
    // }

    //take the starting and ending vertex as input 
    int s ; int e ;
    cout<<"Enter the starting vertex ->" ;
    cin>>s ;
    cout<<"Enter the ending vertex ->" ;
    cin>>e ;

    int ans = dijkstra(s,e) ;
    cout<<"The shortest path length between "<<s<<" and "<<e<<" is "<<ans ;

    return 0;
}