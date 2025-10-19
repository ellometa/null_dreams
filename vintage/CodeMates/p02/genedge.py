# gen_edgecases.py
import os

OUT_DIR = "tests/edge"

def to_hhmm(m): return (m // 60) * 100 + (m % 60)

def min_platforms(pairs):
    ev = []
    for a, d in pairs:
        ev.append((a, +1))
        ev.append((d, -1))
    ev.sort(key=lambda x: (x[0], x[1]))  # departures first at tie
    cur = ans = 0
    for _, delta in ev:
        cur += delta
        ans = max(ans, cur)
    return ans

CASES = []

# 0) sample from statement (converted to per-train lines)
pairs = [(1000,1030),(1010,1020),(1025,1035)]
CASES.append(("sample_basic", pairs))

# 1) all overlap -> answer = n
pairs = [(900, 950)] * 7
CASES.append(("all_overlap", pairs))

# 2) no overlap -> answer = 1
pairs = [(900, 910), (910, 920), (920, 930), (930, 940)]
CASES.append(("no_overlap", pairs))

# 3) equal timestamps (tie handling): departures before arrivals
pairs = [(900, 900), (900, 930), (930, 930), (930, 1000)]
CASES.append(("equal_times_zero_stays", pairs))

# 4) zero-length stays mixed with normal
pairs = [(1000,1000), (1000,1010), (1010,1020), (1020,1020)]
CASES.append(("zero_length_mixed", pairs))

# 5) tiny dwell times (1–2 min) dense
pairs = [(to_hhmm(600+i), to_hhmm(600+i+1)) for i in range(10)]
CASES.append(("tiny_dwell_dense", pairs))

# 6) boundary around midnight
pairs = [(to_hhmm(5), to_hhmm(20)),
         (to_hhmm(15), to_hhmm(30)),
         (to_hhmm(25), to_hhmm(40)),
         (to_hhmm(23*60+30), to_hhmm(23*60+59))]
CASES.append(("midnight_boundary", pairs))

# 7) big cluster then gap then mini cluster
pairs = []
for i in range(8): pairs.append((1000 + (i%3), 1030))   # near-same arrivals
for i in range(3): pairs.append((1200 + i*2, 1210 + i*2))
CASES.append(("cluster_gap_cluster", pairs))

# 8) same arrival & different departures (sorting stability)
pairs = [(915, 930), (915, 920), (915, 940), (915, 915)]
CASES.append(("same_arr_diff_dep", pairs))

# 9) minutes sanity (<60)
pairs = [(959, 1001), (1001, 1015), (1059, 1100)]
CASES.append(("minute_edges", pairs))

os.makedirs(OUT_DIR, exist_ok=True)
for idx, (name, pairs) in enumerate(CASES):
    fin = os.path.join(OUT_DIR, f"input{idx:02d}_{name}.txt")
    fout = os.path.join(OUT_DIR, f"output{idx:02d}_{name}.txt")
    with open(fin, "w") as f:
        f.write(str(len(pairs)) + "\n")
        for a, d in pairs:
            f.write(f"{a} {d}\n")
    with open(fout, "w") as f:
        f.write(str(min_platforms(pairs)) + "\n")
print(f"[edge] wrote {len(CASES)} curated edgecases → {OUT_DIR}")
