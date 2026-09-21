msg = input("Enter text: ")
k = "HACK"

cols = len(k)
rows = len(msg) // cols
if len(msg) % cols != 0:
    rows = rows + 1

while len(msg) < rows * cols:
    msg = msg + "X"

grid = []
for i in range(rows):
    row_data = []
    for j in range(cols):
        row_data.append(msg[i * cols + j])
    grid.append(row_data)

print("The Matrix:")
for i in range(rows):
    print(grid[i])

key_letters = []
for i in range(cols):
    key_letters.append(k[i])

for i in range(len(key_letters)):
    for j in range(len(key_letters) - 1):
        if key_letters[j] > key_letters[j+1]:
            temp = key_letters[j]
            key_letters[j] = key_letters[j+1]
            key_letters[j+1] = temp

order = []
for i in range(len(key_letters)):
    letter = key_letters[i]
    for j in range(len(k)):
        if k[j] == letter:
            already_used = False
            for used in order:
                if used == j:
                    already_used = True
            
            if already_used == False:
                order.append(j)
                break

print("Column Order: ", order)

ans = ""
for i in range(len(order)):
    col_idx = order[i]
    for j in range(rows):
        ans = ans + grid[j][col_idx]

print("Result: " + ans)
