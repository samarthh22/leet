class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int dol5=0,dol10=0;
        for(auto it: bills){
            if(it == 5) {
                dol5++;
                continue;
            }
            else if(it == 10) {
                if(dol5 == 0) return false;
                else {
                    dol10++;
                    dol5--;
                }
            }else {
                if(dol5 > 0 && dol10 > 0) {
                    dol10--;
                    dol5--;
                }else if(dol5 > 2) {
                    dol5 -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};