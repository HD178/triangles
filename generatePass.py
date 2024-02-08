import random
import string

'''
- generates a password of completely random numbers and letters of a set length
function generateBasicPass() 
    params: 
        length : int
    return 
        password : string 
'''
def generateBasicPass(length):
    characters = string.ascii_letters + string.digits + string.punctuation
    list = []
    for char in range(length): 
        list.append(random.choice(characters))
    
    password = ''.join(list)

    return password


'''
- generates a password of a set number of letters, digits and punctuations
function generatePass() 
    params: 
        numLetters : int
        numDigits : int 
        numPunc : int
    return 
        password : string 
'''
def generatePass(numLetters, numDigits, numPunc):
    list = []
    letters = string.ascii_letters
    for tmp in range(numLetters): 
        list.append(random.choice(letters))

    digits = string.digits
    for tmp in range(numDigits):
        list.append(random.choice(digits))

    punc = string.punctuation
    for tmp in range(numPunc):
        list.append(random.choice(punc))

    random.shuffle(list)  #randomise list contents 
    password = ''.join(list) #make string 

    return password


print()
print("Press 1 to generate password by length")
print("Press 2 to generate password by specifications (letter, number, symbol)")
try: 
    x = int(input(""))

except: 
    print("Enter an integer")

print()

if (x == 1):
    length = int(input("Length of Password: "))
    password = generateBasicPass(length)
    print(password)

elif (x == 2):
    numLetters = int(input("Number of Letters: "))
    numDigits = int(input("Number of Digits: "))
    numPunc = int(input("Number of Symbols: "))
    password = generatePass(numLetters, numDigits, numPunc)

    print(password)

else: 
    print("invalid input")