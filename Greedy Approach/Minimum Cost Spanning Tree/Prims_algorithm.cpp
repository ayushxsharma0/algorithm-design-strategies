#include<bits/stdc++.h>
using namespace std;

#define z 32767

void prim(int v, int size, vector<vector<int>> m){
 //initial steps 
 // first we find the egde with the minimum cost edge in the matrix
    vector<int> track(size,z) ;
    int t[2][v-1] ;
    //find minimum 
    int min = z ;
    int sum = 0 ; // to calculate minimum cost 
    int x,y;
    for(int i=1;i<=v;i++){
        for(int j=i;j<=v;j++){
            if(m[i][j] < min){
                min = m[i][j] ;
                x = i ;
                y = j ;
            }
        }
    }
    t[0][0] = x ;
    t[1][0] = y ;
    sum += m[x][y] ;
    track[x] = track[y] = 0 ;
    //now update track array to get distance of all vertices from nodes of built tree 
    for(int i=1;i<=v;i++){
        if(track[i] != 0){
            if(m[i][x] < m[i][y]){
                track[i] = x ;
            }
            else{
                track[i] = y ;
            }
        }
    }
    // reapeated steps
    for(int i=1;i<v-1;i++){
        int minimum = z ;
        int k ;
        //find minimum edge from track array 
        for(int j =1;j<=v;j++){
            if(track[j] != 0 && m[j][track[j]] < minimum){
                minimum = m[j][track[j]] ;
                k = j ;
            }
        }
        //include that edge in t array
        t[1][i] = k;
        t[0][i] = track[k] ;
        sum += m[k][track[k]] ;
        track[k] = 0 ; //update to know it has already include 
        // update the track array taking newly included vertex in consideration
        for(int j=1;j<=v;j++){
            if(track[j] != 0 && m[j][k] < m[j][track[j]]){
                track[j] = k ;
            }
        } 
    }
    // print the t vertex as it include all vertex in mcst 
    for(int i =0;i<v-1;i++){
        cout<<t[0][i]<<" -- "<<t[1][i] <<endl;
    }
    cout<<"minimum cost = "<<sum ;
}

int main()
{
    int v ;
    cout<<"Enter the number of vertices -\n" ;
    cin>>v ;
    int size = v+1 ;
    vector<vector<int>> mat ;
    vector<int> dum(size,0) ;
    cout<<"Enter the entries of the matrix, if there is no edge enter 0\n" ;
    mat.push_back(dum) ;
    dum.clear() ;
    //take the entries of the matrix 
    for(int i =1;i<size;i++){
        dum.push_back(z) ;
        cout<<"Enter the "<<i<<"th row of matrix -"<<endl ;
        for(int j=1;j<size;j++){
            int a ;
            cin>>a ;
            if(a == 0){
                dum.push_back(z) ;
            }
            else{
                dum.push_back(a) ;
            }
        }
        mat.push_back(dum) ;
        dum.clear() ;
    }  

    prim(v,size,mat) ;
    return 0;
}
