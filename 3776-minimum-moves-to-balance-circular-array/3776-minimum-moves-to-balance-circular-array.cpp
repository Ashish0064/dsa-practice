class Solution {
public:
    typedef long long ll;
    ll minMoves(vector<int>& balance) {
        int n = balance.size();
        ll sum = 0;
        long long culprit = -1;
        for(int i = 0;i<n;i++){
            sum += balance[i];

            if(balance[i] < 0){
                culprit = i;
            }
        }
        if(sum <0){
            return -1;
        }
        if(culprit == -1){
            return 0;
        }

        ll moves = 0;
        ll distance = 1;
        while(balance[culprit]<0){
            ll right = (culprit + distance) % n;
            ll left = (culprit - distance + n)% n;

            ll available = balance[right] + balance[left];
            if(left == right){
                available -= balance[right];
            }
            ll needed = -balance[culprit];
            ll taken = min(needed,available);

            moves += distance * taken;
            balance[culprit] += taken;
            distance++;
        }

        return moves;
    }
};