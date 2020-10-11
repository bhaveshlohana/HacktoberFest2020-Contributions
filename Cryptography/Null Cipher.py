# Function to decode the message.  
def decode(string): 
      
    res = "" 

    found = False
  
    for charcter in string: 

        if charcter == ' ': 
            found = False
            continue
  
        if not found: 
            if charcter>='A' and charcter<='Z' or charcter>='a' and charcter<='z': 
                res += charcter 
                found = True
  
    return res.lower()  
  
# Driver code 
if __name__ == "__main__": 
    print("Enter Your Text: ")
    input = input()
    print("Enciphered Message:",decode(input)) 
  
