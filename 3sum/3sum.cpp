class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    
    vector<vector<int> > res;

    sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        
        int target = -num[i];
        int j = i + 1;
        int k = num.size() - 1;

        while (j < k) {

            int sum = num[j] + num[k];
            if (sum < target)
                j++;

            else if (sum > target)
                k--;

            else {
                vector<int> triplet = {num[i], num[j], num[k]};
                res.push_back(triplet);
                while (j < k && num[j] == triplet[1]) j++;

                while (j < k && num[k] == triplet[2]) k--;
            }
            
        }

        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }
    
    return res;
    
}
};