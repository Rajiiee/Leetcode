class Solution {
public:
    int passThePillow(int n, int time) {
        int duration=time/(n-1);
        int pos=time%(n-1);
        if(duration%2 == 0){
            return pos+1;
        }else{
            return n-pos;
        }
    }
};