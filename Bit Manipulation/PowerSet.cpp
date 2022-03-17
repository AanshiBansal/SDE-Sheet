class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string>ans;
		    int n=s.size();
		    for(int i=0;i<(1<<n);i++){
		        string curr="";
		        for(int j=0;j<n;j++){
		            if((i&(1<<j))!=0)
		                curr.push_back(s[j]);
		        }
		        if(curr!="")
		        ans.push_back(curr);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

class Solution{
    private:
        void recursive(string &s, int index, string curr, vector<string>&ans){
            if(index==s.size()){
                if(curr!="")
                    ans.push_back(curr);
                return;
            }
            curr.push_back(s[index]);
            recursive(s,index+1,curr,ans);
            curr.pop_back();
            recursive(s,index+1,curr,ans);
        }
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string>ans;
		    recursive(s,0,"",ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};