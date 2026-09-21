
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> freq(101, 0);
        for (int i = nums.size(); i >=0; i--){
            if (freq[nums[i]] == 0){
                freq[nums[i]]+=1;
            }
            else{
                cout << ceil(i/3) ;
            }
        }
        
    }
};