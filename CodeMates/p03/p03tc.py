# gen_yv_easy_inputs.py
# Usage:
#   python3 gen_yv_easy_inputs.py              # writes 50 files into inputs/
#   python3 gen_yv_easy_inputs.py 200 my_inputs   # 200 files into my_inputs/

import os, random, sys

def make_edgecases():
    """Deterministic, useful edge cases for sum-of-digits steps."""
    ecs = [
        0,                      # trivial single digit
        *range(1, 10),          # all single digits
        10, 11, 19,             # 1 step
        99, 199999999,          # 2 steps (e.g., 99 -> 18 -> 9)
        991, 999999990,         # 3 steps (991 -> 19 -> 10 -> 1)
        1000000000 - 1,         # 999,999,999 (sum=81 -> 9)
        1000000000 - 10,        # 999,999,990 (sum=54 -> 9)
        808080808,              # alternating zeros
        135792468,              # mixed digits
    ]
    # deduplicate while preserving order
    seen, out = set(), []
    for x in ecs:
        if 0 <= x <= 10**9 and x not in seen:
            seen.add(x); out.append(x)
    return out

def rand_n():
    """Return a random n in [0, 1e9] without leading zeros (as an int)."""
    return random.randint(0, 10**9)

def main():
    total = int(sys.argv[1]) if len(sys.argv) > 1 else 50
    outdir = sys.argv[2] if len(sys.argv) > 2 else "inputs"
    os.makedirs(outdir, exist_ok=True)

    random.seed(42)

    # 1) write curated edgecases first
    cases = make_edgecases()
    written = 0
    for i, n in enumerate(cases):
        if written >= total: break
        with open(os.path.join(outdir, f"input{i:02d}.txt"), "w") as f:
            f.write(f"{n}\n")
        written += 1

    # 2) fill the rest with randoms
    idx = written
    while written < total:
        n = rand_n()
        with open(os.path.join(outdir, f"input{idx:02d}.txt"), "w") as f:
            f.write(f"{n}\n")
        idx += 1
        written += 1

    print(f"wrote {written} files to {outdir}/ (input00.txt .. input{written-1:02d}.txt)")

if __name__ == "__main__":
    main()
