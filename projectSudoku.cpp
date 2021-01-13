#include<stdio.h>
#include<stdlib.h>
#define n 9
void print(int arr[n][n])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		printf("%d",arr[i][j]);
		printf("\n");
	}
}
int isSafe(int grid[n][n],int row,int col,int num)
{
	for(int x=0;x<=8;x++)
	    if(grid[row][x] == num)
	        return 0;
	        
    for(int x=0;x<=8;x++)
        if(grid[x][col] == num)
            return 0;
            
    int startrow = row-row%3,startcol = col-col%3;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(grid[i + startrow][j + startcol] == num)
                return 0;
				
	return 1;
}
int solveSudoku(int grid[n][n],int row,int col)
{
	if(row == n-1 && col == n)
	    return 1;
	if(col == n)
	{
		row++;
		col = 0;
	}
	if(grid[row][col]> 0)
	    return solveSudoku(grid,row,col + 1);
	for(int num = 1;num <= n;num++)
	{
		if(isSafe(grid,row,col,num)==1)
		{
			grid[row][col] = num;
			if(solveSudoku(grid,row,col + 1)==1)
			    return 1;
		}
		grid[row][col] = 0;
	}
	return 0;
}
int main()
{
	int grid[n][n],i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		scanf("%d",&grid[i][j]);
	}
	if(solveSudoku(grid,0,0)==1)
	    print(grid);
	else
	    printf("No Solution exists for the sudoku!!!");
	return 0;
}

