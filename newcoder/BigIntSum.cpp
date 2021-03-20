#include<algorithm>

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        // write code here
        string ans;
        int p1=s.size(), p2=t.size(), up=0, p=min(p1, p2), res;
        
        // add the common part
        for(int i=0;i<p;i++){
            res = s[p1-i-1] - '0' + t[p2-i-1] - '0' + up;
            up = res / 10;
            res = res % 10;
            ans.push_back(res+'0');
        }
        
        // add the rest part
        if(p1>p){
            for(int i=p;i<p1;i++){
                res = s[p1-i-1] - '0' + up;
                up = res / 10;
                res = res % 10;
                ans.push_back(res+'0');
            }
        }
        else{
            if(p2>p){
                for(int i=p;i<p2;i++){
                    res = t[p2-i-1] - '0' + up;
                    up = res / 10;
                    res = res % 10;
                    ans.push_back(res+'0');
                }
            }
        }
        
        // there might be a final digit
        if(up>0){ans.push_back('1');}
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};