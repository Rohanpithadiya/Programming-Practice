// Gamooga Interview Problem
// find palindroms in a string.
// input: WABCDCBASWXYZYXWWXYZA
// out put:
// ABCDCBA
// WXYZYXW
// ZYXWWXYZ

#include <iostream>
#include<cstring>

using namespace std;

bool in_boundry(int i, int min, int max){
	if (i >= min)
		if(i < max)
			return true;
	return false;
}

void print_str(char *str, int start, int end){
	for(int i =start; i<=end ;i++){
		cout << str[i];
	}
	cout << endl;
}

void max_pal(char *str, int len, int low, int high){
	while(str[high] == str[low]){
		high ++;
		low --;
		if (!in_boundry(high,0,len) || !in_boundry(low,0,len)){
			break;
		}
	}	
	print_str(str,low+1,high-1);
}

void find_palindrom(char * str){
	int len = strlen(str);

	for(int i=0; i < len;i++){
		int low = i;
		int high = i;
		if( in_boundry(i+1,0,len) && str[i] == str[i+1])
		{
			high = i+1;
			max_pal(str,len,i,i+1);
		}
		else if(in_boundry(i-1,0,len) && in_boundry(i+1,0,len) && str[i-1] == str[i+1]){
			max_pal(str,len, i-1,i+1);
		}	
	}	
}

int main(){
	
	char str[] = "WABCDCBASWXYZYXWWXYZA";
	// char str[] = "abracarbradabra";
	find_palindrom(str);
	return 0;
}

