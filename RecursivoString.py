import string 
alfabeto = list(string.ascii_lowercase[:26])


def main():
    n=3
    i=0
    while(i<n):
        # print (i)
        # recursivePattern(alfabeto[i], n)
        i+=1
    recursivePattern(alfabeto[0], n)

def inJail(letter, jail):
    # print(len(jail))
    for i in range(0, len(jail)-1):
        # print (letter)
        # print (jail[i])
        if(letter == jail[i]):
            return True
    return False


def recursivePattern(jail, n):
    if(n==1):
        print (jail)   
    else:
        j=0
        while(j<n):
            if(inJail(alfabeto[j], jail) == False):
                jail+=(alfabeto[j])
                
                recursivePattern(jail, n-1)
            j+=1

print(len("aaa"))

print(inJail('a', 'ab'))
print(inJail('a', 'bc'))
print(inJail('a', 'cab'))

# main() 