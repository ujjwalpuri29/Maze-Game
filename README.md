# Maze-Game

## :grey_question: Problem Statement

Maze game is a well-known problem, where we are given a grid of 0’s and 1’s, 0’s corresponds to a place that can be traversed, and 1 corresponds to a place that cannot be traversed (i.e. a wall or barrier); the problem is to find a path from the bottom left corner of the grid to top right corner; immediate right, immediate left, immediately up and immediate down only are possible (no diagonal moves). We consider a variant of the maze problem where a cost (positive value) or profit (negative value) is attached to visiting each location in the maze, and the problem is to find a path of least cost through the maze.

You may solve the problem after imposing/relaxing other restrictions on the above problem on:
- Values of cost/profit (but not the same cost/profit for all traversable cells in the grid)  
- Moves possible (but you cannot trivialize the problem by making the grid linear or partly linear in any way)  
- No. of destinations possible

Choose the most efficient algorithm possible for your specific case.

## ✏️ Approach Used: Greedy Algorithm

In this algorithm, at each point, the left, top, right, and bottom nodes are compared and we move to the node with the minimum value among all compared. This means at every step we take the least expensive move for the optimal solution.

## 🚧 Algorithm 

- We initialize a matrix having different costs at each node with 0 as walls and pass it into a function minCost() to find the least cost.
- Inside this function, we make another matrix called sol with the same dimensions, and each element initialized to 0 and the value changing to 1 when the element is visited during the path.
- Next we loop from the bottom left corner node in the original matrix and increment till we reach the top right corner without encountering any wall.
- Inside the loop we call a function getDirection() which compares the costs in different directions from that node, keeping within limits of the matrix.
- Based on the direction returned by getDirection(), we move in that direction and the expense of that step is added to the total expense, and getDirection() is called again.
- After we reach the destination or a wall is encountered, the final cost and path is passed to the main function where it is displayed.

## :bulb: Language Used
- C++

# 👻 Created by:
- This is in collaboration with [Hansika Sacheva](https://github.com/HansikaSachdeva) 
