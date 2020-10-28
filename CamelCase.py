import os 

# Driver Code 
def main(): 
    s = input("Enter Name of the file")
    s = convert(s)
    ext = ['.cpp','py']
    choice = 0
    open(s+ext[choice], 'a').close()

def convert(s): 
    if(len(s) == 0): 
        return
    s1 = '' 
    s1 += s[0].upper() 
    for i in range(1, len(s)): 
        if (s[i] == ' '): 
            s1 += s[i + 1].upper() 
            i += 1
        elif(s[i - 1] != ' '): 
            s1 += s[i]  
    return s1   
      
if __name__=="__main__": 
    main()  
