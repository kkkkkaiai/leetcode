#include <iostream>
#include <string>


using std::string;
using std::cout;
using std::endl;
 
class Solution{
public:
	bool isPalindrome(string s){
		if(s.size() == 0)
			return true;
		size_t b,e;
		b = 0;
		e = s.size() - 1;
		while(b < e){
			if(isalnum(s[b]) && isalnum(s[e])){
				if(toupper(s[b]) != toupper(s[e]))
					return false;
				else{
					b++;e--;
				}
			}else{
				while(!isalnum(s[b]) && e > b)
					++b;
				while(!isalnum(s[e]) && e > b)
					--e;
			}
		}
		return true;
	}


};

