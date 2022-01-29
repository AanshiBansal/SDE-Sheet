//Time: O(n*n)
//Space: O(1)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int left=i-1;
            int right=i+1;
            for(;left>=0;left--){
                if(heights[left]<heights[i])
                    break;
            }
            for(;right<n;right++){
                if(heights[right]<heights[i])
                    break;
            }
            ans=max(ans,heights[i]*(right-left-1));
        }
        return ans;
    }
};

//Time: O(n) in 2 or 3 passes
//Space: O(3*n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
        vector<int>left(n,-1);
        vector<int>right(n,n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            if(!s.empty())
                left[i]=s.top();
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--){
             while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();
            if(!s.empty())
                right[i]=s.top();
            s.push(i);
        }
        for(int i=0;i<n;i++){
			//Can also be clubbed with the previous pass
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};

//Time: O(n) in 1 pass
//Space: O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                int index=s.top();
                s.pop();
                int left=!s.empty()?s.top():-1;
                ans=max(ans,heights[index]*(i-left-1));
            }
            s.push(i);
        }
        while(!s.empty()){
            int index=s.top();
            s.pop();
            int left=!s.empty()?s.top():-1;
            int right=n;
            ans=max(ans,heights[index]*(right-left-1));
        }
        return ans;
    }
};

//Code improvisation
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
        stack<int>s;
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || heights[s.top()]>=heights[i])){
                int index=s.top();
                s.pop();
                int left=!s.empty()?s.top():-1;
                ans=max(ans,heights[index]*(i-left-1));
            }
            s.push(i);
        }
        return ans;
    }
};