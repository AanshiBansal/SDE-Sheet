// https://leetcode.com/problems/maximum-frequency-stack/

// Time: O(1)
// Space: O(n)
// Elegant Solution
class FreqStack {
private:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>freqStack;
    int freqMax;
public:
    FreqStack() {
        freqMax=0;
    }
    
    void push(int val) {
        freq[val]++;
        freqMax=max(freqMax,freq[val]);
        freqStack[freq[val]].push(val);
    }
    
    int pop() {
        int ans=freqStack[freqMax].top();
        freqStack[freqMax].pop();
        if(freqStack[freqMax].empty())
            freqMax--;
        freq[ans]--;
        return ans;
    }
};

// Time: O(log(n)) both push and pop because of heap
// Space: O(n)
// Brute Force Solution
class FreqStack {
private:
    unordered_map<int,int>freq;
    priority_queue<vector<int>>pq;
    int count;
public:
    FreqStack() {
        count=0;
    }
    
    void push(int val) {
        freq[val]++;
        pq.push({freq[val],count++,val});
    }
    
    int pop() {
        vector<int>ans=pq.top();
        freq[pq.top()[2]]--;
        pq.pop();
        return ans[2];
    }
};