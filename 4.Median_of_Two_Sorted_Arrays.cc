#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class Solution{
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
			vector<double> ans;
			size_t size = nums1.size() + nums2.size();
			if(nums1.empty() || nums2.empty()){
				if(!nums1.empty()){
					if(size % 2 == 1){
						return nums1[size/2];
					}else
						return ((double)nums1[size/2] + nums1[size/2 - 1])/2;
				}else{
					if(size % 2 == 1){
						return nums2[size/2];
					}else
						return ((double)nums2[size/2] + nums2[size/2 - 1])/2;
				}
			}
			size_t i,j,sum;
			for(i = j = sum = 0; sum < size/2 + 1; ++sum){
				if (i < nums1.size() && (j == nums2.size() ||nums1[i] <= nums2[j] )  ) {
					ans.push_back(nums1[i]);
					++i;
				}else{
					ans.push_back(nums2[j]);
					++j;
				}
			}
			size_t it = ans.size();
			if(size % 2 == 1){
				return (double)ans[it - 1];
			}else{
				return (double)(ans[it - 1] + ans[it - 2]) / 2;
			}
		}
};


