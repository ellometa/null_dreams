def create_playfair_grid(keyword):
    keyword = keyword.upper().replace(' ', '')
    seen = set()
    key_chars = []
    for char in keyword:
        if char not in seen:
            if char == 'J':
                char = 'I'
            if char.isalpha():
                key_chars.append(char)
                seen.add(char)
    for char in 'ABCDEFGHIKLMNOPQRSTUVWXYZ':
        if char not in seen:
            key_chars.append(char)
    return [key_chars[i*5:(i+1)*5] for i in range(5)]


def display_grid(grid):
    print("\n" + "=" * 35)
    print("Playfair Cipher Grid (5x5)")
    print("=" * 35)
    print("\n    ", end="")
    for j in range(5):
        print(f"  {j+1} ", end="")
    print()
    print("   " + "-" * 23)
    for i in range(5):
        print(f" {i+1} |", end="")
        for j in range(5):
            print(f" {grid[i][j]} ", end="")
        print("|")
    print("   " + "-" * 23)
    print("\nNote: I and J are treated as the same letter\n")


def prepare_plaintext(text):
    text = text.upper().replace(' ', '').replace('J', 'I')
    text = ''.join(c for c in text if c.isalpha())
    prepared = []
    i = 0
    while i < len(text):
        if i == len(text) - 1:
            prepared.append(text[i])
            break
        if text[i] == text[i + 1]:
            prepared.append(text[i])
            prepared.append('X')
            i += 1
        else:
            prepared.append(text[i])
            prepared.append(text[i + 1])
            i += 2
    if len(prepared) % 2 != 0:
        prepared.append('X')
    return ''.join(prepared)


def encrypt_pair(grid, char1, char2):
    row1 = col1 = row2 = col2 = None
    for i in range(5):
        for j in range(5):
            if grid[i][j] == char1:
                row1, col1 = i, j
            if grid[i][j] == char2:
                row2, col2 = i, j
    if row1 is None or row2 is None:
        return char1 + char2
    if row1 == row2:
        return grid[row1][(col1 + 1) % 5] + grid[row2][(col2 + 1) % 5]
    elif col1 == col2:
        return grid[(row1 + 1) % 5][col1] + grid[(row2 + 1) % 5][col2]
    else:
        return grid[row1][col2] + grid[row2][col1]


def encrypt(plaintext, keyword):
    grid = create_playfair_grid(keyword)
    display_grid(grid)
    prepared = prepare_plaintext(plaintext)
    digrams = [prepared[i:i+2] for i in range(0, len(prepared), 2)]
    print("Prepared text (after handling doubles/padding):", prepared)
    print("Digrams:", ' '.join(digrams))
    print()
    ciphertext = [encrypt_pair(grid, d[0], d[1]) for d in digrams]
    return ' '.join(ciphertext)


def main():
    print("=" * 50)
    print("Playfair Cipher Encryption")
    print("=" * 50)
    keyword = input("\nEnter the keyword: ").strip()
    if not keyword:
        keyword = "PLAYFAIR EXAMPLE"
        print(f"Using default keyword: {keyword}")
    plaintext = input("Enter the plaintext to encrypt: ").strip()
    if not plaintext:
        plaintext = "HELLO WORLD"
        print(f"Using default plaintext: {plaintext}")
    print("\n" + "=" * 50)
    ciphertext = encrypt(plaintext, keyword)
    print(f"\nPlaintext:  {plaintext}")
    print(f"Ciphertext: {ciphertext}")
    print("=" * 50)


if __name__ == "__main__":
    main()
