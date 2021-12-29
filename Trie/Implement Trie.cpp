struct TrieNode{
    bool word;
    vector<TrieNode*>children;
    TrieNode(){
        word=false;
        children=*new vector<TrieNode*>(26,NULL);
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root= new TrieNode();
    }
    
    void insert(string word) {
        int i=0;
        TrieNode* curr=root;
        while(i<word.size()){
            if(curr->children[word[i]-'a']==NULL){
                curr->children[word[i]-'a']=new TrieNode(); 
            }
            curr=curr->children[word[i]-'a'];
            i++;
        }
        curr->word=true;
    }
    
    bool search(string word) {
        int i=0;
        TrieNode* curr=root;
        while(i<word.size()){
            if(curr->children[word[i]-'a']==NULL){
                return false; 
            }
            curr=curr->children[word[i]-'a'];
            i++;
        }
        return curr->word;
    }
    
    bool startsWith(string prefix) {
        int i=0;
        TrieNode* curr=root;
        while(i<prefix.size()){
            if(curr->children[prefix[i]-'a']==NULL){
                return false; 
            }
            curr=curr->children[prefix[i]-'a'];
            i++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */