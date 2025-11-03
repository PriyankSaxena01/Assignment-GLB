int countWords(string s) {
    int wordCount = 0;
    bool inWord = false;

    for (int i = 0; i < s.length(); ++i) {

        if (s[i] == ' ') {
            inWord = false;
        } 
        else if (s[i] == '\\') {
            if (i + 1 < s.length() && (s[i + 1] == 'n' || s[i + 1] == 't')) {
                inWord = false;
                i++; 
            }
            else {
                if (!inWord) {
                    wordCount++;
                    inWord = true; 
                }
            }
        }

        else {
            if (!inWord) {
                wordCount++;  
                inWord = true; 
            }
        }
    }
    
    return wordCount;
}
