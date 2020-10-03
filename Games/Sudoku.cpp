#include<bits/stdc++.h>

using namespace std;
int grid[i][j];

void grid_input(){

    int  i,j ;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            
            cin>>grid[i][j];

            
        }
    }
}

void grid_print(){
    int i,j;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j];
        }
    }
}


void solve_sudo(int row,int col){
    


    if(row==n && col==0){
        grid_print();
        return;




        
    }

    if (grid[row][col] == 0) {
        for (int num = 1; num <= n; num++) {
                grid[row][col] = 0;
            }
        }
    }

}




int main(){
    grid_input();

    solve_sudo(0,0);
}
