#!/usr/bin/env python3
"""
Generate input files (input00.txt, input01.txt, ...) for the
'Residue 1 Forbidden' problem (Good Set).
Each file contains exactly one integer N (1 <= N <= 2e5).

Usage:
  python3 gen_goodset_inputs.py               # writes 50 files into ./inputs/
  python3 gen_goodset_inputs.py 200 outdir    # writes 200 files into ./outdir/

Design:
- Curated edge cases first (small N, boundaries, patterns).
- Then fill remaining with random N in [1, 2e5].
"""

import os
import sys
import random

MAXN_DEFAULT = 200_000

def curated_cases(maxn: int):
    cs = []

    # Smallest and tiny range
    cs += [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

    # Around even/odd boundaries
    for x in [11, 12, 13, 14, 15, 16, 17, 18, 19, 20]:
        cs.append(x)

    # Powers of two & neighbors
    for p in [16, 32, 64, 128, 256, 512, 1024, 2048,
              4096, 8192, 16384, 32768, 65536, 131072]:
        if p <= maxn:
            cs += [p-1, p, p+1] if p+1 <= maxn else [p-1, p]

    # Big boundaries
    cs += [max(1, maxn-10), max(1, maxn-1), maxn]

    # A few “nice” composite and prime-ish values scattered
    cs += [999, 1000, 1001, 50000, 50001, 99991, 100000, 150000, 199999]

    # Dedup and clamp to [1, maxn]
    seen, out = set(), []
    for x in cs:
        if 1 <= x <= maxn and x not in seen:
            seen.add(x)
            out.append(x)
    return out

def main():
    # Args
    total = int(sys.argv[1]) if len(sys.argv) >= 2 else 50
    outdir = sys.argv[2] if len(sys.argv) >= 3 else "inputs"
    maxn = MAXN_DEFAULT

    os.makedirs(outdir, exist_ok=True)
    random.seed(42)

    # 1) Write curated cases first
    cases = curated_cases(maxn)
    written = 0
    for i, n in enumerate(cases):
        if written >= total:
            break
        path = os.path.join(outdir, f"input{i:02d}.txt")
        with open(path, "w") as f:
            f.write(f"{n}\n")
        written += 1

    # 2) Fill the rest with random N in [1, maxn]
    idx = written
    while written < total:
        n = random.randint(1, maxn)
        path = os.path.join(outdir, f"input{idx:02d}.txt")
        with open(path, "w") as f:
            f.write(f"{n}\n")
        idx += 1
        written += 1

    print(f"Wrote {written} files to {outdir}/  (input00.txt .. input{written-1:02d}.txt)")

if __name__ == "__main__":
    main()
