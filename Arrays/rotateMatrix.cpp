/*
	Q.  Write a method to rotate a square matrix (N x N) by 90 degrees. Can you do this is in place.
*/


#include<iostream>
#include <ctime>

using namespace std;

void rotate90(int mat[][4], int size);

int main()
{
	clock_t begin = clock();
	int mat[4][4] = {{1,2,3,4},{9,8,5,6},{6,5,3,7},{9,2,6,8}};



	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<endl;

	rotate90(mat,4);
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout<<"Time of execution: "<<elapsed_secs<<endl;

}

void rotate90(int mat[][4], int size){
	for(int layer=0; layer<size/2; layer++){
		int first = layer;
		int last = size-1-layer;

		for(int i=first; i<last; i++){
			int offset = i-first;
			int top = mat[first][i];

			mat[first][i] = mat[last-offset][first];

			mat[last-offset][first] = mat[last][last-offset];

			mat[last][last-offset] = mat[i][last];

			mat[i][last] = top;
		}
	}
}