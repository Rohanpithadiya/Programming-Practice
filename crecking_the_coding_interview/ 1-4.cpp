// Problem 1.4
// Write a method to replace all spaces in a string with'%20'. You may assume that
// the string has sufficient space at the end of the string to hold the additional
// characters, and that you are given the "true" length of the string. (Note: if imple-
// menting in Java, please use a character array so that you can perform this opera-
// tion in place.)
// EXAMPLE
// Input:
// "Mr John Smith
// Output: "Mr%20Dohn%20Smith"

#include<iostream>
#include<cstring>

using namespace std;

void replace_space(char *str){
	int str_len = strlen(str);
	int i,j;

	for(i=str_len-1;str[i]==' '; i--);
	int last_char_index =i;

	for(i=last_char_index, j=str_len-1 ; i!=0&j!=0 ; i--, j--){
		if(str[i]==' '){
			str[j--] = '0';
			str[j--] = '2';
			str[j] = '%';
		}
		else{
			str[j]=str[i];
		}
	}
}

int main(){
	char mystr[]="my name is rohan      ";
	cout << mystr << endl;
	replace_space(mystr);
	cout << mystr << endl;
}