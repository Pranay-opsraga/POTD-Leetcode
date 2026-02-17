class Solution {
public:
    void solve(int idx , int ledsleft , int hr , int min , vector<string>&ans){
          if( hr > 11 || min > 59) return; //Base Case

          if(ledsleft == 0){
              string time = to_string(hr) + ":"; // Base Case
              if( min < 10) time += "0";
              time += to_string(min);
              ans.push_back(time);
              return;
          }

          if(idx == 10) return ; //Base Case

          if(idx < 4){
             solve(idx+1 , ledsleft-1 , hr + (1 << (3 - idx)) , min , ans);
          } else solve (idx+1 , ledsleft-1 , hr , min + (1 << (9 - idx)) , ans);

          solve(idx+1 , ledsleft , hr , min , ans);
    }
    vector<string> readBinaryWatch(int turnedOn) {
          vector<string>ans;
          solve(0 , turnedOn , 0,0, ans);
          return ans;
    }
};
