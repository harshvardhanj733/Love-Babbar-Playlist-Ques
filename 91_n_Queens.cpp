#include <bits/stdc++.h> 

bool isSafe(int row, int col, vector<vector<int>> board, int n){
	//check in same column
	int k = row;
	while(k>=0){
		if(board[k][col] == 1){
			return false;
		}
		k--;
	}

	//check for north-west diagonal
	int i = row, j = col;
	while(i>=0 && j>=0){
		if(board[i][j] == 1){
			return false;
		}
		i--; j--;
	}

	//check for north-east diagonal
	i = row, j = col;
	while(i>=0 && j<n){
		if(board[i][j] == 1){
			return false;
		}
		i--; j++;
	}

	//return true if everything checks
	return true;
}

void soln(vector<vector<int>> & res, vector<vector<int>> & board, int n, int row){
	if(row == n){
		vector<int> temp;
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				temp.push_back(board[i][j]);
			}
		}
		res.push_back(temp);
		return;
	}

	for(int i = 0; i<n; i++){
		if(isSafe(row, i, board, n)){
			board[row][i] = 1;
			soln(res, board, n, row+1);
			board[row][i] = 0;
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	// Write your code here
	vector<vector<int>> res;
	vector<vector<int>> board(n, vector<int>(n, 0));

	soln(res, board, n, 0);
	return res;
}