matrix = [
    ['M', 'O', 'N', 'A', 'R'],
    ['C', 'H', 'Y', 'B', 'D'],
    ['E', 'F', 'G', 'I', 'K'],
    ['L', 'P', 'Q', 'S', 'T'],
    ['U', 'V', 'W', 'X', 'Z']
]

def prepareText(text):
    text = text.upper()
    new_text = ""
    for i in range(len(text)):
        if text[i] == "J":
            new_text = new_text + "I"
        elif text[i] >= "A" and text[i] <= "Z":
            new_text = new_text + text[i]
            
    res = ""
    i = 0
    while i < len(new_text):
        res = res + new_text[i]
        if i + 1 < len(new_text):
            if new_text[i] == new_text[i+1]:
                res = res + "X"
                i = i + 1
            else:
                res = res + new_text[i+1]
                i = i + 2
        else:
            res = res + "Z"
            i = i + 1
            
    return res

def findPosition(char):
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == char:
                return i, j
    return 0, 0

def encrypt(text):
    prepared = prepareText(text)
    ans = ""
    for i in range(0, len(prepared), 2):
        c1 = prepared[i]
        c2 = prepared[i+1]
        
        r1, col1 = findPosition(c1)
        r2, col2 = findPosition(c2)
        
        if r1 == r2:
            new_col1 = (col1 + 1) % 5
            new_col2 = (col2 + 1) % 5
            ans = ans + matrix[r1][new_col1] + matrix[r2][new_col2]
        elif col1 == col2:
            new_r1 = (r1 + 1) % 5
            new_r2 = (r2 + 1) % 5
            ans = ans + matrix[new_r1][col1] + matrix[new_r2][col2]
        else:
            ans = ans + matrix[r1][col2] + matrix[r2][col1]
            
    return ans

print("Playfair Cipher (Key: MONARCHY)")
text_input = input("Enter text: ")

result = encrypt(text_input)
print("Result: " + result)
