###############################################################################  Question  #############################################################################################################################################


Given a matrix mat[][] with r rows and c columns, where some cells are landmines (marked as 0) and others are safe to traverse. Your task is to find the shortest safe route from any cell in the leftmost column to any cell in the rightmost column of the mat. You cannot move diagonally, and you must avoid both the landmines and their adjacent cells (up, down, left, right), as they are also unsafe.

Example 1:

Input:
mat = [1, 0, 1, 1, 1],
      [1, 1, 1, 1, 1],
      [1, 1, 1, 1, 1],
      [1, 1, 1, 0, 1],
      [1, 1, 1, 1, 0]
Output: 
6
Explanation: 
We can see that length of shortest
safe route is 6
[1 0 1 1 1]
[1 1 1 1 1]
[1 1 1 1 1]
[1 1 1 0 1] 
[1 1 1 1 0]
Example 2:

Input:
mat = [1, 1, 1, 1, 1],
      [1, 1, 0, 1, 1],
      [1, 1, 1, 1, 1]
Output: 
-1
Explanation: There is no possible path from
first column to last column.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findShortestPath() which takes the matrix as an input parameter and returns an integer denoting the shortest safe path from any cell in the leftmost column to any cell in the rightmost column of mat. If there is no possible path, return -1. 

Expected Time Complexity: O(r * c)
Expected Auxiliary Space: O(r * c)

Constraints:
1 <= r, c <= 103
0 <= mat[][] <= 1




###############################################################################  Solution  #############################################################################################################################################

  //{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
       int r = mat.size(), c = mat[0].size();
       int dir[5] = {-1, 0, 1, 0, -1};
       
       for(int i=0; i<r; i++)
       {
           for(int j=0; j<c; j++)
           {
               if(mat[i][j] == 0)
               {
                   for(int d=0; d<4; d++)
                   {
                       int x = i+dir[d], y = j+dir[d+1];
                       
                       if(x >= 0 and x < r and y >= 0 and y < c and mat[x][y] == 1)
                        mat[x][y] = 2;
                   }
               }
           }
       }
       
       vector<vector<bool>> visited(r, vector<bool> (c, false));
       queue<pair<int,int>> Q;
       
       for(int i=0; i<r; i++)
       {
           if(mat[i][0] == 1)
           {
               Q.push({i,0});
               visited[i][0] = true;
           }
       }
       
       int level = 1;
       
       while(!Q.empty())
       {
           int sz = Q.size();
           
           while(sz--)
           {
               auto cur = Q.front();
               Q.pop();
               
               int X = cur.first, Y = cur.second;
               
               if(Y == c-1)
                    return level;
                
                for(int d=0; d<3; d++)
                {
                    int x = X+dir[d], y = Y+dir[d+1];
                    
                    if(x >= 0 and x < r and y >= 0 and y < c and mat[x][y] == 1 and !visited[x][y])
                    {
                        Q.push({x,y});
                        visited[x][y] = true;
                    }
                }
           }
           
           level++;
       }
       
       return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
