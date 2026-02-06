int lengthOfLongestSubstring(char* s) {
    int left=0;
    int last[256];
    int maxlen=0;
    int start=0;
    for(int i=0;i<256;i++){
        last[i]=-1;
    }
    for(int right=0;s[right]!='\0';right++){
        if(last[(unsigned char)s[right]]>=left){
            left=last[(unsigned char)s[right]]+1;
            
        }
            last[(unsigned char)s[right]]=right;
        if(right-left+1>maxlen){
            maxlen=right-left+1;
            start=left;
        }
        
    }
    
    return maxlen;
}