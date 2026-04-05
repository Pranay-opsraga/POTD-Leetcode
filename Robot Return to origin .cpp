class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int>mpp;
        int n = moves.size();
        for(int i = 0 ; i < n ; i++){
             mpp[moves[i]]++;
        }
       
              if(mpp['U'] == mpp['D'] && mpp['L'] == mpp['R']) return true;
              return false;
        
    }
};
