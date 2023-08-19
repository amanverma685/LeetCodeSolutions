class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {   int n = wordList.size();
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string, int>> q;
        int steps =0;
        
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord)
            return steps;

            for(int i=0;i<word.size();i++)
            {   
                string temp = word;
                for(char chnge='a';chnge<='z';chnge++)
                {   
                    word[i]=chnge;

                    if(st.find(word)!= st.end())
                    {
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word = temp;
            }
        }
        return steps;
    }
};