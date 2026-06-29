// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int i=0;
//         int j=0;
//         while(j<nums.size()){
//             if(nums[i]==nums[j]){
//                 j++;
//             }
//             else if(nums[i]!=nums[j]){
//                 i++;
//                 nums[i]=nums[j];
//                 j++;
//             }
//         }
//         return i+1;
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0;
        unordered_set<int>seen;
        for(int num:nums){
            if(seen.find(num)==seen.end()){
                seen.insert(num);
                nums[index]=num;
                index++;
            }
        }
        
        return index;
    }
};