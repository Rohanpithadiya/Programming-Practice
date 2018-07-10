// problem 1.5
// Implement a method to perform basic string compression using the counts
// of repeated characters. For example, the string aabcccccaaa would become
// a2blc5a3. If the "compressed" string would not become smaller than the orig-
// inal string, your method should return the original string

#include<iostream>
#include<cstring>
#include<string>
#include<sstream>

using namespace std;

string convert_str(char *mystr){
	char *str = mystr;

	int str_len = strlen(str);
	string new_str;


	for(int i=0;i<str_len;i++){
		char cur_char = str[i];
		int count =1;
		while(i<str_len-1 && str[i]==str[i+1]){
			count++;
			i++;
		}
		new_str += cur_char;
		stringstream c;
		c << count;
		new_str += c.str();
		
		// cout << new_str << endl;
		if(str_len < new_str.size()){
			return mystr;
		}
	}
return new_str;
}


int main(){
	char str1[] ="aabcccccaaa";
	char str2[] ="";
	char str3[] ="aabbccaa";
	char str4[] ="abcdefgh";
	char str5[] ="aaaaah";
	cout << convert_str(str5) << endl;
}