#include <unordered_map>


class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // 链表维护LRU（增删都是O(1)（存疑）），哈希表维护key-value
        vector<int> ans;
        list<int> lru;
        unordered_map<int, int> dict;
        int opt_type, key, value, cnt=0, num_op=operators.size();
        for(int i=0; i<num_op; i++){
            opt_type = operators[i][0];
            if(opt_type==1){
                key = operators[i][1];
                value = operators[i][2];
                cnt++;
                lru.push_back(key);
                if(cnt>k){
                    dict.erase(lru.front());
                    lru.pop_front();
                }
                dict.insert(pair<int, int>(key, value));
            }
            else{
                key = operators[i][1];
                if(dict.count(key)>0){
                    ans.push_back(dict[key]);
                    lru.remove(key);
                    lru.push_back(key);
                }
                else{
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};