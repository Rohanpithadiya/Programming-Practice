// problem 1.3
// Given two strings, write a method to decide if one is a permutation of the other.

#include<iostream>
#include<cstring>

using namespace std;

bool is_permutation(char *str1, char *str2){
	cout << "comparing "<< str1 << " with " << str2 << endl;

	int charArray[26] = {0};
	int str1_len = strlen(str1);
	int str2_len = strlen(str2); 

	if( str1_len != str2_len)
		return false;
	// for(int i = 0; i < str1_len; i++){
	// 	if('A' <= str1[i]){
	// 		if(str1[i] <= 'Z'){
	// 			str1[i]= 'a'-'A' + str1[i];
	// 		}
	// 	}
	// 	charArray[str1[i]-'a']++;
	// }

	// for(int i = 0; i < str2_len; i++){
	// 	if('A' <= str2[i]){
	// 		if(str2[i] <= 'Z'){
	// 			str2[i]= 'a'-'A' + str2[i];
	// 		}
	// 	}
	// 	charArray[str2[i]-'a']--;
	// }
	
	while(*str1){
		if('A' <= *str1){
			if(*str1 <= 'Z'){
				*str1 = 'a' - 'A' + *str1;
			}
		}
		charArray[*str1-'a']++;
		*str1++;
	}

	while(*str2){
		if('A' <= *str2){
			if(*str2 <= 'Z'){
				*str2 = 'a' - 'A' + *str2;
			}
		}
		charArray[*str2-'a']--;
		*str2++;
	}

	for(int i=0;i<26;i++){
		if(charArray[i] != 0)
			return false;
	}
	return true;
}

int main()
{
	char str1[] = "cat";
	char str2[] = "act";
	char str3[] = "aabbc";
	char str4[] = "abcba";
	char str5[] = "ababa";
	char str6[] = "TAC";

	cout << is_permutation(str1,str2) << endl;
	cout << is_permutation(str3,str4) << endl;
	cout << is_permutation(str4,str5) << endl;
	cout << is_permutation(str1,str5) << endl;
	cout << is_permutation(str6,str1) << endl;
}