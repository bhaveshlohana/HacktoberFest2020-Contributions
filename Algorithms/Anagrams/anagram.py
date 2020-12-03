str1=input()
str2=input()

def anagram(str1, str2): 
 
    if(sorted(str1)== sorted(str2)): 
        return("The strings_are_anagrams.")  
    else: 
        return("The strings_are_not_anagrams.")          
 
print(anagram(str1, str2))
