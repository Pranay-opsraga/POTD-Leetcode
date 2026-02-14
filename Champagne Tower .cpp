class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
            
            vector<double>row = {double(poured)};

            for(int i = 0 ; i < query_row ; i++){
                   vector<double>next(i+2 , 0.0);

                   for(int j = 0 ; j < row.size() ; j++){
                         if(row[j] > 1.0 ){
                             double split = (row[j] - 1)/2;
                             next[j] += split;
                             next[j+1] += split;
                         }
                   }
                    row = next;
            }

            return min(1.0 ,row[query_glass]); 

    }
};
