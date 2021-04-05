#include <bits/stdc++.h>
using namespace std;

#define N 5

int minCost(int maze[N][N], int x, int y, int sol[N][N]);
int getDirection(int maze[N][N], int x, int y, int sol[N][N]);

void printSolution(int arr[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
}

void solveMaze(int maze[N][N])
{
    int sol[N][N] = {0};
    
    int x = minCost(maze, N - 1, 0, sol);
    cout<<"Cost: "<<x<<endl;
    
    if (x!=0) {
        cout<<"\nSolution:\n";
        printSolution(sol);
        cout<<"\n[1 denotes path taken]\n";
    }

    else cout<<"The least cost path was blocked by walls on all sides.\n";
}

int minCost(int maze[N][N], int x, int y, int sol[N][N]) {
    int cost = maze[x][y];
    while (x != 0 || y != N - 1){
        int dir = getDirection(maze, x, y, sol);
        sol[x][y] = 1;
        
        switch(dir){
            case 1: cost += maze[--x][y]; break;
            case 2: cost += maze[x][++y]; break;
            case 3: cost += maze[++x][y]; break;
            case 4: cost += maze[x][--y]; break;
            case 0: cost = 0; return cost;
        }
    }  
    sol[0][N-1] = 1;
    return cost; 
}

int getDirection(int maze[N][N], int x, int y, int sol[N][N])
{
    int min = 1000;
    int dir = 0;

    if (0 <= (x-1) && (x-1) < N && 0 <= y && y < N && sol[x-1][y] != 1) {
        if (maze[x-1][y] < min && maze[x-1][y] != 0) {
            min = maze[x-1][y];
            dir = 1; //up
        }
    }

    if (0 <= x && x < N && 0 <= (y+1) && (y+1) < N && sol[x][y+1] != 1) {
        if (maze[x][y+1] < min && maze[x][y+1] != 0) {
            min = maze[x][y+1];
            dir = 2; //right
        }
    }
    
    if (0 <= (x+1) && (x+1) < N && 0 <= y && y < N && sol[x+1][y] != 1) {
        if (maze[x+1][y] < min && maze[x+1][y] != 0){
            min = maze[x+1][y];
            dir = 3; //down
        }
    }
    
    if (0 <= x && x < N && 0 <= (y-1) && (y-1) < N && sol[x][y-1] != 1) {
        if (maze[x][y-1] < min && maze[x][y-1] != 0){
            min = maze[x][y-1];
            dir = 4; //left
        }
    }

    return dir;
}

int main()
{
    int maze[N][N] = { 		
        31, 100, 65, 12, 18, 
		    10, 13, 47, 157, 6, 
		    100, 113, 0, 11, 33, 
		    88, 0, 41, 0, 140, 
		    99, 32, 111, 42, 20 
	}; 

    cout<<"\nMaze: \n[0 denotes walls]\n\n";
    printSolution(maze);

    cout<<endl;
    solveMaze(maze);
    return 0;
}
