class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        unordered_map<char, int>m;
        queue<int>q;

        for(int i=0;i<n;i++){
            if(m.find(s[i])==m.end()){
                q.push(i);
            }

            m[s[i]]++;
        }
        while(q.size()>0 && m[s[q.front()]]>1){
            q.pop();
        }
        return q.empty()?-1:q.front();
        
    }
};