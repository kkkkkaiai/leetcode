#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
 
class Solution{
public:
	string longestPalindrome(string s){
		string ans;
		for(unsigned int i = 0; i < s.size(); ++i){
			for(unsigned int j = i; j < s.size(); ++j){
				string temp;
				temp = s.substr(i , j-i+1);
				if(isPalindrome(temp)){
					if(temp.size() > ans.size()){
							ans.clear();
							ans = temp;
					}
				}
			}
		}
		return ans;
	}

	bool isPalindrome(string s){
		if(s.size() == 1)
			return true;
		size_t  b, e;
		b = 0;
		e = s.size() - 1;
		if(s.size() < 4){
			return s[0] == s[e];
		}
		for(; b < s.size()/2 - 1; ++b,--e){
			if(s[b] != s[e])
				return false;
		}

		return true;
	}
};
