# gen_heavy.py
import os, random

OUT_DIR = "tests/heavy"
NUM_FILES = 10        # number of heavy inputs
N = 1000              # max trains per file (problem constraint)
random.seed(7)

def to_hhmm(m):
    return (m // 60) * 100 + (m % 60)

def min_platforms(pairs):
    ev = []
    for a, d in pairs:
        ev.append((a, +1))
        ev.append((d, -1))
    ev.sort(key=lambda x: (x[0], x[1]))
    cur = ans = 0
    for _, delta in ev:
        cur += delta
        ans = max(ans, cur)
    return ans

def all_overlap(n):
    # same arrival minute, departures stagger slightly after
    base = 9 * 60  # 09:00
    pairs = []
    for i in range(n):
        a = to_hhmm(base)
        d = to_hhmm(min(23*60+59, base + 30 + (i % 30)))  # 30..59 min dwell
        pairs.append((a, d))
    return pairs

def equal_time_bursts(n):
    # many trains with exact same arrival & same departure in tight bursts
    pairs = []
    t = 8 * 60
    left = n
    while left > 0:
        k = min(left, random.randint(20, 80))
        a = to_hhmm(t)
        d = to_hhmm(min(23*60+59, t + 15))
        pairs += [(a, d)] * k
        left -= k
        t = min(23*60+30, t + random.choice([5, 10, 15]))  # tiny gaps
    return pairs[:n]

def staircase_dense(n):
    # arrivals every minute; 10–40 min dwells → dense overlap window
    pairs = []
    start = 10 * 60
    for i in range(n):
        a_min = start + i % 120   # wrap through a 2h window
        dwell = random.randint(10, 40)
        d_min = min(23*60+59, a_min + dwell)
        pairs.append((to_hhmm(a_min), to_hhmm(d_min)))
    return pairs

def mix(n):
    A = n//3
    B = n//3
    C = n - A - B
    pairs = all_overlap(A) + equal_time_bursts(B) + staircase_dense(C)
    random.shuffle(pairs)
    return pairs

os.makedirs(OUT_DIR, exist_ok=True)
builders = [all_overlap, equal_time_bursts, staircase_dense, mix]
for t in range(NUM_FILES):
    pairs = builders[t % len(builders)](N)
    need = min_platforms(pairs)
    fin = os.path.join(OUT_DIR, f"input{t:02d}.txt")
    fout = os.path.join(OUT_DIR, f"output{t:02d}.txt")
    with open(fin, "w") as f:
        f.write(str(len(pairs)) + "\n")
        for a, d in pairs:
            f.write(f"{a} {d}\n")
    with open(fout, "w") as f:
        f.write(str(need) + "\n")
print(f"[heavy] wrote {NUM_FILES} cases of n={N} → {OUT_DIR}")
