#!/usr/bin/env bash
set -euo pipefail

for i in {1..1000}; do
  ./push_swap $(shuf -i 0-19 -n 5) | wc -l
done | awk '$1 > 12'
