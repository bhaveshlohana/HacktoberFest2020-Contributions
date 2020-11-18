"""Returns words from the given paragraph which has been repeated most,
incase of more than one words, latest most common word is returned. """

import string
def mostCommonWord(paragraph: str) -> str:
    
    # translate function maps every punctuation in given string to white space
    words = paragraph.translate(str.maketrans(string.punctuation, ' '*len(string.punctuation)))
    words = words.lower().split()
    
    unique_words = {}
    highest = 0
    res = ''
    
    for word in words:
        if word not in unique_words:
            unique_words[word] = 0
        unique_words[word] += 1
        if unique_words[word] >= highest:
            highest = unique_words[word]
            res = word
            
    return res

print(mostCommonWord("HacktoberFest is live! Riddhi is participating in HACKtoBERfEST.Happy Coding.")) #Output: hacktoberfest