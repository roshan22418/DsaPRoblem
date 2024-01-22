#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int row,int col,int newx,int newy,vector<vector<bool>> &visited,int maze[][4]){
    //out of bound 
    //visited
    // free hole or not 
    if((newx>=0 &&newx<row)&&
    (newy>=0&&newy<col)&&
    visited[newx][newy]==false&&
    maze[newx][newy]==1){
        return true;
    }
    else
    {
        return false;
    }
    

}


void pathPRint(int maze[][4],int row,int col,int srcx,int srcy,vector<vector<bool>> &visited,string &output){
    if (srcx==row-1&&srcy==col-1)
    {
        cout<<output<<" "<<endl;
        return;
    }
    int newx = srcx-1;
    int newy = srcy;
    if(isSafe(row,col,newx,newy,visited,maze)){
        visited[newx][newy] = true;
        output.push_back('U');
        pathPRint(maze,row,col,newx,newy,visited,output);
        visited[newx][newy] =false;
        output.pop_back();
    }
    newx = srcx+1;
    newy = srcy;
    if(isSafe(row,col,newx,newy,visited,maze)){
        visited[newx][newy] = true;
        output.push_back('D');
        pathPRint(maze,row,col,newx,newy,visited,output);
        visited[newx][newy] =false;
        output.pop_back();
    }
    //left
    newx = srcx;
    newy = srcy-1;
    if(isSafe(row,col,newx,newy,visited,maze)){
        visited[newx][newy] = true;
        output.push_back('L');
        pathPRint(maze,row,col,newx,newy,visited,output);
        visited[newx][newy] =false;
        output.pop_back();
    }
    //right
    newx = srcx;
    newy = srcy+1;
    if(isSafe(row,col,newx,newy,visited,maze)){
        visited[newx][newy] = true;
        output.push_back('R');
        pathPRint(maze,row,col,newx,newy,visited,output);
        visited[newx][newy] =false;
        output.pop_back();
    }
}

int main(){
    int maze[4][4] = {
        {1,0,0,0},
        {1,0,0,0},
        {1,0,0,1},
        {1,1,1,1}
    };
    int col = 4;
    int row = 4;
    int srcx = 0;
    int srcy = 0;
    string output = "";
    vector<vector<bool>> visited(row,vector<bool>(col,false));
    visited[srcx][srcy] = true;
    pathPRint(maze,row,col,srcx,srcy,visited,output);
    return 0;
}