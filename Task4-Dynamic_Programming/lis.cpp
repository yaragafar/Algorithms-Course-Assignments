#include<iostream>
using namespace std;
#include <vector>

int lengthOfLIS(vector<int>& nums) {

	vector<int> LIS(nums.size(), 1);
	for (int i = nums.size()-1; i >= 0; i--)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if(nums[i]<nums[j])
			{
				LIS[i] = max(LIS[i], LIS[j] + 1);
			
			}
		}
	}
	int max_length=0;
	for (int k = 0; k < LIS.size(); k++)
	{
		if(LIS[k]> max_length)
		{
			max_length = LIS[k];
		}
	}
	return max_length;
}


int main(){
	int n;
	cout << "Enter the length of your sequence: " << endl;
	cin >> n;
	vector<int>nums(n);
	cout << "Enter the numbers of your sequence: " << endl;
		for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

		int max_sub_length = lengthOfLIS(nums);
		cout << "Length of longest increasing subsequence is: "<< max_sub_length;

}