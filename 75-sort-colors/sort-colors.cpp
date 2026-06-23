// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int red=0;
//         int white=0;
//         int blue=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0){
//                 red++;
//             }
//             if(nums[i]==1){
//                 white++;
//             }
//             if(nums[i]==2){
//                 blue++;
//             }
//         }
//         for(int i=0;i<red;i++){
//           nums[i]=0;

//         }
//         for(int i=red;i<red+white;i++){
//           nums[i]=1;

//         }
//         for(int i=white+red;i<red+white+blue;i++){
//           nums[i]=2;

//         }
        
//     }
// };


class Solution {
public:
    void sortColors(vector<int>& nums) {
      int red=0;
      int white=0;
      int blue=0;
      for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            red++;
        }
        else if(nums[i]==1){
            white++;
        }
        else{
            blue++;
        }
      }
      for(int i=0;i<nums.size();i++){
        if(red>0){
            nums[i]=0;
            red--;
        }
        else if(white>0){
            nums[i]=1;
            white--;
        }
        else{
            nums[i]=2;
            blue--;
        }
      }
        
    }
};


