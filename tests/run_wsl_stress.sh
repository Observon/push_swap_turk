#!/usr/bin/env bash
set -euo pipefail

for i in {1..1000}; do
  ./push_swap $(shuf -i 0-99 -n 100) | wc -l
 done | awk '$1 > 700'
