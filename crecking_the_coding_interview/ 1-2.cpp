// Problem 1.2
// Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string.

#include<iostream>
#include<cstring>

using namespace std;

void swap(char *str, int i, int j){
	char temp;
	temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

void reverse(char *str){
	int len = strlen(str);
	for(int i=0,j=len-1; i<j ; i++, j--){
		swap(str, i, j);
	}
}

int main(){
	char mystr[] = "my name is rohan";
	cout << mystr << endl;
	reverse(mystr);
	cout << mystr << endl;
	return(0);
}