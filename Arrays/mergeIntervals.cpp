class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
    vector<vector<int>>res;
    if(intervals.size() == 0) return res;

    // sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
    //     return a[0] < b[0];
    // });
    sort(intervals.begin(), intervals.end());
    vector<int> curr = intervals[0];
    for(int i =1 ; i< intervals.size(); i++){
        if(curr[1] < intervals[i][0]){
            res.push_back(curr);
            curr = intervals[i];
        }else{
            curr[1] = max(curr[1], intervals[i][1]);
        }
    }
    res.push_back(curr);
    return res;
    }
};

// TC : O(nlogn)
// SC : O(n)

// Striver's Soln
vector < vector < int >> merge(vector < vector < int >> & intervals) {

  sort(intervals.begin(), intervals.end());
  vector < vector < int >> merged;

  for (int i = 0; i < intervals.size(); i++) {
    if (merged.empty() || merged.back()[1] < intervals[i][0]) {
      vector < int > v = {
        intervals[i][0],
        intervals[i][1]
      };

      merged.push_back(v);
    } else {
      merged.back()[1] = max(merged.back()[1], intervals[i][1]);
    }
  }

  return merged;
}

//Time Complexity: O(NlogN) + O(N). O(NlogN) for sorting and O(N) for traversing through the array.

//Space Complexity: O(N) to return the answer of the merged intervals.
