import random

WORDS = [
    "campaign", "grace", "stunning", "chocolate", "comment", "construct", "edge", "prosper",
    "hallway", "soup", "torch", "stride", "archive", "clash", "fur", "father", "trance", "glow",
    "disgrace", "defeat", "fever", "locate", "frank", "class", "means", "reptile", "relieve", "gem",
    "voter", "art", "staff", "crude", "meal", "modest", "vote", "bare", "weed", "compete", "bless",
    "deal", "glimpse", "choose", "cheque", "export", "closed", "funny", "freight", "sheep", "orbit",
    "sweater", "snap", "tidy", "stamp", "settle", "morning", "bush", "convert", "symptom", "want",
    "knife", "role", "fog", "brand", "us", "retired", "sunshine", "rack", "unfair", "ignore",
    "remark", "tent", "duty", "exclude", "huge", "try", "wife", "dine", "reflect", "tile", "trend",
    "gem", "kit", "knowledge", "map", "sunrise", "tiger", "spill", "mushroom", "prefer", "sister",
]

def pick_word(seen_counts, new_pool):
    
    if new_pool and seen_counts:
        if random.random() < 0.5:
            return new_pool.pop(), True
        else:
            return random.choice(list(seen_counts.keys())), False
    elif new_pool:
        return new_pool.pop(), True
    else:
        return random.choice(list(seen_counts.keys())), False

def play(round_limit=100, lives=3):
    print("verbal memory test (cli)")
    print("------------------------")
    print("type 1 if you've seen the word before, 2 if it's new. q to quit.")
    print(f"you have {lives} lives.\n")

    seen_counts = {}
    new_pool = WORDS.copy()
    random.shuffle(new_pool)

    score = 0
    mistakes = 0
    round_num = 0

    while mistakes < lives and round_num < round_limit:
        round_num += 1
        word, is_new = pick_word(seen_counts, new_pool)

        print(f"\nround {round_num}: {word.upper()}")
        ans = input("seen before? (1=yes, 2=no, q=quit): ").strip().lower()

        if ans == "q":
            break
        if ans not in ("2", "1"):
            print("please type 1, 2, or q.")
            continue

        user_thinks_seen = (ans == "1")
        actually_seen = word in seen_counts

        if user_thinks_seen == actually_seen:
            score += 1
            print("correct!")
        else:
            mistakes += 1
            print(f"wrong. lives left: {lives - mistakes}")


        seen_counts[word] = seen_counts.get(word, 0) + 1
        print(f"score: {score} | unique seen: {len(seen_counts)}")

    print("\n— game over —")
    print(f"final score: {score}")
    print(f"rounds played: {round_num}")

if __name__ == "__main__":
    play()
