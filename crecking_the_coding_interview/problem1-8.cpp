// Problem1.8
// Assume you have a method isSubstring which checks if one word is a
// substring of another. Given two strings, s1 and s2, write code to check if s2 is
// a rotation of s1 using only one call to isSubstring (e.g.,"waterbottle"is a rota-
// tion of "erbottlewat").

// time 15 min

#include<iostream>
#include<string>

using namespace std;

bool isRotation(string *str1, string *str2){
	if ((str1->length() <= 0) || (str2->length() <= 0) || (str1->length() != str2->length())){
		return false;
	}
	*str1 = *str1 + *str1;
	int res = str1->find(*str2);
	if( res != string::npos){
		return true;
	}
	return false;
}

int main(){

	string s1 = "waterbottle";
	string s2 = "erbottlewat";

	cout << isRotation(&s1,&s2) << endl;
	return 0;
}