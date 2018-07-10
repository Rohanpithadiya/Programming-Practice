// problem 1.7
// Write an algorithm such that if an element in an MxN matrix is 0, its entire row
// and column are set to 0.

#include<iostream>
#include<vector>

using namespace std;


void printvector(vector<int> v){
std::vector<int>::size_type sz = v.size();
for (unsigned i=0; i<sz; i++){
 	cout<< v[i] << ", ";
}
cout << endl;
}

void print(int **img , int r, int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout << img[i][j] <<",";
		}
		cout <<endl;
	}
}


void cleanup(int **mat, int r, int c){
	vector<int> z_row(r);
	vector<int> z_col(c);
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(mat[i][j] == 0){
				z_row[i] = 1;
				z_col[j] = 1;
			}
		}
	}
	cout <<"z_col"<<endl;
	printvector(z_col);

	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(z_row[i] | z_col[j]){
				mat[i][j]=0;
			}
		}
	}
}

int main(){
	int r=4;
	int c=6;
	int **myimg = new int*[r];
	for(int i =0;i<r;i++){
		myimg[i] = new int[c];
	}
	int count = 1;	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			myimg[i][j] = count;
		}
	}
	myimg[0][4]=0;
	myimg[2][1]=0;
	myimg[3][3]=0;
	cout << "--- original ---" << endl;
	print(myimg,r,c);
	cleanup(myimg,r,c);
	cout << "--- after cleanup ---" << endl;
	print(myimg,r,c);
}