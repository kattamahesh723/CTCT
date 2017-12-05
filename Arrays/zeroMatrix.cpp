/*
	Q. Write an algorithm such that if an element in an M x N matrix is 0, its row and column are set to 0.
*/

#include<iostream>

using namespace std;


void makeZeroMatrix(int mat[][4], int rows, int cols);

int main(){
	int mat[3][4] = {{1,2,3,4},{0,5,4,7},{2,7,0,9}}; // Hard coding the input just to make it easy

	int rows = 3;	//Comment this if your are using input from stdin
	int cols = 4;

	for(int r=0; r<rows; r++){
		for(int c=0; c<cols; c++){
			cout<<mat[r][c]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	/*
		Uncomment below code to use input dyanmically (from stdin)
	*/
	// int rows, cols;
	// cin>>rows>>cols;
	// int** mat = new int*[rows];
	// for(int i=0; i<rows; i++){
	// 	mat[i] = new int[cols];
	// }

	// for(int r=0; r<rows; r++){
	// 	for(int c=0; c<cols; c++){
	// 		cin>>mat[r][c];
	// 	}
	// }

	

	makeZeroMatrix(mat, 3, 4);	// Entire row and columns are set to zero if they have at least one zero in respective row and column

	for(int r=0; r<rows; r++){
		for(int c=0; c<cols; c++){
			cout<<mat[r][c]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

}

void makeZeroMatrix(int mat[][4], int rows, int cols){

	bool rowHasZero = false;	// To check if first row or col has any zeros
	bool colHasZero = false;

	for(int r=0; r<rows; r++){
		if(mat[r][0] == 0){
			rowHasZero = true;
			break;
		}
	}

	for(int c=0; c<cols; c++){
		if(mat[0][c] == 0){
			colHasZero = true;
			break;
		}
	}

	for(int r=1; r<rows; r++){
		for(int c=1; c<cols; c++){
			if(mat[r][c] == 0){		// Using and storing information about which row and col can be made to zero in the first row and col
				mat[r][0] = 0;
				mat[0][c] = 0;
			}
		}
	}



	for(int r=0; r<rows; r++){
		for(int c=0; c<cols; c++){
			cout<<mat[r][c]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	for(int r=1; r<rows; r++){		// Setting all rows to zero if they have any zero value in them
		if(mat[r][0] == 0){
			for(int c=1; c<cols; c++)
				mat[r][c] = 0;
		}
	}

	for(int c=1; c<cols; c++){		// Setting all columns to zero if they have any zero value in them
		if(mat[c][0] == 0){
			for(int r=1; r<rows; r++)
				mat[r][c] = 0;
		}
	}

	if(rowHasZero){
		for(int r=0; r<rows; r++)
			mat[r][0] = 0;
	}

	if(colHasZero){
		for(int c=0; c<cols; c++)
			mat[0][c] = 0;
	}

}