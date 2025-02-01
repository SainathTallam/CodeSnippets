class TrieNode{
public:
    TrieNode* children[26] ;
    bool is_leaf ;
    
    TrieNode()
    {
        for(int i=0;i<26;i++)
            children[i] = NULL ;
        is_leaf = false ;
    }
};

class Trie {
public:
    TrieNode* root ;
    

    Trie()
    {
        root = new TrieNode() ;
    }
    
    void insert(string word)
    {
        int n = word.size() ;
        
        TrieNode* curr = root ;
        
        for(int i=0;i<n;i++)
        {
            int ind = word[i]-'a' ;
            
            if(curr->children[ind]==NULL)
                curr->children[ind] = new TrieNode() ;
                
            curr = curr->children[ind] ;
        }
        
        curr->is_leaf = true ;
        return ;
        
    }
    
    bool search(string word)
    {
        int n = word.size() ;
        
        TrieNode* curr = root ;
        
        for(int i=0;i<n;i++)
        {
            int ind = word[i]-'a' ;
            
            if(curr->children[ind]==NULL)
                return false ;
                
            curr = curr->children[ind] ;
        }
        
        return curr->is_leaf ;
        
    }
    
    bool startsWith(string prefix)
    {
        int n = prefix.size() ;
        
        TrieNode* curr = root ;
        
        for(int i=0;i<n;i++)
        {
            int ind = prefix[i]-'a' ;
            
            if(curr->children[ind]==NULL)
                return false ;
            curr = curr->children[ind] ;
        }
        
        return true ;
    }
    
    ~Trie()
    {
        clear(root) ;
    }
    
    void clear(TrieNode* curr)
    {
        for(int i=0;i<26;i++)
        {
            if(curr->children[i] != NULL)
                clear(curr->children[i]) ;
        }
        
        delete curr ;
    }
};
