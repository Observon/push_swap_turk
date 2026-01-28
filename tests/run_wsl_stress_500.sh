#!/usr/bin/env bash
set -euo pipefail

for i in {1..1000}; do
  ./push_swap $(shuf -i 0-499 -n 500) | wc -l
 done | awk '$1 > 5500'
