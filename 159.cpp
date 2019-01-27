class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
       nums.push_back(lower-1);
       nums.push_back(upper+1);
       vector<string> ans;
       std::sort(nums.begin(),nums.end());
       //corner case
        if((lower==upper)&&(nums.size()!=2)){
          return ans; 
        }
        if((lower==upper)&&(nums.size()==2)){
          ans.push_back(to_string(lower));
          return ans;
        }
        //general case
         for(int i=0;i<nums.size()-1;i++){
             if(nums[i+1]==nums[i]+1){
                 continue;
             }
             else if(nums[i+1]==nums[i]+2){
                 long num=nums[i]+1;
                 ans.push_back(to_string(num));         
             }
             else{
                 int low=nums[i]+1;
                 int upp=nums[i+1]-1;
                 ans.push_back(to_string(low)+"->"+to_string(upp));
             }
         }
        return ans;
    }
};
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        vector<string> ans;
        if (nums.empty()){
            add_range((long)lower - 1, (long)upper + 1, ans); 
        }
        else {
            add_range((long)lower - 1, nums.front(), ans); 
            
            for (int i = 0; i < nums.size() - 1; ++i)
                add_range(nums[i], nums[i+1], ans);
            
            add_range(nums.back(), (long)upper + 1, ans); 
        }
        return ans; 
    }
private:
    void add_range(long a, long b, vector<string>& ans){
        if (a + 1 == b - 1){
            ans.push_back(to_string(a+1)); 
        }
        else if( a + 1 < b - 1){
            ans.push_back(to_string(a+1) + "->" + to_string(b-1)); 
        }
    }
};
