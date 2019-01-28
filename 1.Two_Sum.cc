#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;



class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> find;
		vector<int> ans;

		for(unsigned int i = 0; i < nums.size(); ++i){
			if(find.count(target - nums[i])){
				ans.push_back(find[target - nums[i]]);
				ans.push_back(i);
			}else{
				find.insert({nums[i], i});
			}
		}

		return ans;
	}
};

