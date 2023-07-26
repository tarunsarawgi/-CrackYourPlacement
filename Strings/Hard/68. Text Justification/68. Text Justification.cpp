class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        
        for(int i = 0, w; i < n; i = w) {
            // Length of text with 1 space (except at end of a line)              
            int len = -1; // last word in a line doesn't require space at end.
            // Check how much can be accomodated in a line
            for(w = i; w < n && len + words[w].length() + 1 <= maxWidth; w++) {
                len += words[w].length() + 1;
            }
            
            string str = words[i];
            
            // Initially only one space and zero extra spaces.
            int space = 1, extra = 0;
            if(w != i + 1 && w != words.size()) { // not 1 string, not last line -> ###
                // Spaces remaining at end -> (maxWidth - len)
                // Slots --> (w - i - 1)
                space = (maxWidth - len) / (w - i - 1) + 1;
                extra = (maxWidth - len) % (w - i - 1);
            }
            
            // Debug Info: (Uncomment to see)
            // cout<<"w: "<<w<<" ";
            // cout<<"len: "<<len<<" ";
            // cout<<"space: "<<space<<" ";
            // cout<<"extra: "<<extra<<endl;
            
            // Adjust spaces remaining in slots 
            for(int j = i + 1; j < w; ++j) {
                for(int s = space; s > 0; s--) str += ' ';
                // Put extra spaces in left aligned manner as we going left to right
                if(extra-- > 0) str += ' ';
                str += words[j];
            }
            
            // Putting extra spaces for last line -> ###
            int strLen = maxWidth - str.length();
            while(strLen-- > 0) str += ' ';
            ans.push_back(str);
        }
        return ans;
    }
};
