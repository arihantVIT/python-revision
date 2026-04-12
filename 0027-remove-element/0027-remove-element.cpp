#include <algorithm>
void display(vector<int> &v){
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto ne = remove(nums.begin(), nums.end(), val);
        nums.erase(ne,nums.end());
        display(nums);
        return nums.size();

    }
};