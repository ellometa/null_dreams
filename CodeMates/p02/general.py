
import os, random

OUT_DIR = "tests/general"
NUM_FILES = 15
N_RANGE = (50, 400)   

random.seed(42)

def to_hhmm(minutes):
    h = minutes // 60
    m = minutes % 60
    return h * 100 + m

def rand_time():
    return to_hhmm(random.randint(0, 23) * 60 + random.randint(0, 59))

def min_platforms(pairs):
    ev = []
    for a, d in pairs:
        ev.append((a, +1))
        ev.append((d, -1))
    ev.sort(key=lambda x: (x[0], x[1]))  # dep (-1) before arr (+1)
    cur = ans = 0
    for _, delta in ev:
        cur += delta
        ans = max(ans, cur)
    return ans

def make_case(n):
    pairs = []
    for _ in range(n):
        a_h = random.randint(5, 22)
        a_m = random.randint(0, 59)
        a_min = a_h * 60 + a_m
        dwell = random.randint(5, 120)
        d_min = min(23 * 60 + 59, a_min + dwell)
        pairs.append((to_hhmm(a_min), to_hhmm(d_min)))
    return pairs

os.makedirs(OUT_DIR, exist_ok=True)
for t in range(NUM_FILES):
    n = random.randint(*N_RANGE)
    pairs = make_case(n)
    need = min_platforms(pairs)

    fin = os.path.join(OUT_DIR, f"input{t:02d}.txt")
    fout = os.path.join(OUT_DIR, f"output{t:02d}.txt")
    with open(fin, "w") as f:
        f.write(str(n) + "\n")
        for a, d in pairs:
            f.write(f"{a} {d}\n")
    with open(fout, "w") as f:
        f.write(str(need) + "\n")
print(f"[general] wrote {NUM_FILES} cases → {OUT_DIR}")
