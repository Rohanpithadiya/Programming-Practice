// problem 1.6
// Given an image represented by an NxN matrix, where each pixel in the image is
// 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
// place?

#include<iostream>

using namespace std;

void print(int **img , int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << img[i][j] <<",";
		}
		cout <<endl;
	}
}

void rotate_90(int **img, int n,int depth){
	if (n <= 1)
		return;

	int i;
	for(i=0 ; i <= n-2 ; i++){
		
		int t1 = img[i+depth][n-1+depth];
		int t2 = img[n-1+depth][n-1-i+depth];
		int t3 = img[n-1-i+depth][depth];

		img[i+depth][n-1+depth] = img[+depth][i+depth];
		img[n-1+depth][n-1-i+depth] = t1;
		img[n-1-i+depth][depth] = t2;
		img[depth][i+depth] = t3;
	}

	rotate_90(img,n-2,depth+1);

}


int main(){
	int n=10;
	int **myimg = new int*[n];
	for(int i =0;i<n;i++){
		myimg[i] = new int[n];
	}
	int count = 1;	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			myimg[i][j] = count++;
		}
	}
	cout << "--- original ---" << endl;
	print(myimg,n);
	rotate_90(myimg,n,0);
	cout << "--- rotate 90 ---" << endl;
	print(myimg,n);
}