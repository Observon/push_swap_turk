# Testing Guide - Push Swap

## Overview

A complete, organized test suite with quick tests for development and comprehensive stress tests for validation.

## Quick Start

```bash
cd tests/

# Show all available tests
make help

# Run quick tests (26 cases, ~12 seconds)
make run_all

# Run specific stress test
make stress_100    # 1000 × 100-number tests
make stress_500    # 1000 × 500-number tests
```

## Test Organization

### Quick Tests (Development)

| Target | Cases | Time | Purpose |
|--------|-------|------|---------|
| `make basic` | 10 | ~5s | Core functionality |
| `make quick` | 8 | ~3s | Checker validation |
| `make extended` | 8 | ~4s | Limit compliance |
| **`make run_all`** | **26** | **~12s** | All quick tests |

### Stress Tests (Validation)

| Target | Cases | Limit | Time |
|--------|-------|-------|------|
| `make stress_3` | 1000 | 3 ops | ~15s |
| `make stress_5` | 1000 | 12 ops | ~25s |
| `make stress_100` | 1000 | 700 ops | ~120s |
| `make stress_500` |1000 | 5500 ops | ~180s |
| `make stress` | 500+ | various | ~90s |

## Usage

### Development Workflow

1. **Make code changes**
2. **Quick validation**: `make run_all` (~12s)
3. **Before committing**: `make stress_100` (~120s)

### Pre-Submission

```bash
# Complete validation
make run_all_comprehensive

# Or individually
make run_all
make stress_3
make stress_5
make stress_100
make stress_500
```

### Performance Testing

```bash
# Fast iteration (1000 cases)
make stress_100

# Comprehensive (200 cases)
make stress_500

# Full suite
make stress
```

## Performance Requirements

✅ **3 numbers**: ≤3 operations  
✅ **5 numbers**: ≤12 operations  
✅ **100 numbers**: ≤700 operations  
✅ **500 numbers**: ≤5500 operations  

All stress tests confirm 100% compliance with limits.

## File Structure

```
tests/
├── Quick Tests
│   ├── test_basic.sh
│   ├── test_checker_quick.sh
│   ├── test_extended.sh
│   └── run_all_tests.sh
├── Stress Tests
│   ├── run_wsl_stress_3.sh      (1000 × 3-number)
│   ├── run_wsl_stress_5.sh      (1000 × 5-number)
│   ├── run_wsl_stress_100.sh        (1000 × 100-number)
│   ├── run_wsl_stress_500.sh    (200 × 500-number)
│   └── test_stress.sh           (500+ comprehensive)
├── Control
│   ├── Makefile
│   ├── README.md
│   ├── TESTING_GUIDE.md (this file)
│   └── .gitignore
└── Reference
    ├── checker_linux
    ├── pro_checker
    └── PROJECT_SUMMARY.md
```

## Notes

- All tests reference binaries in parent directory (`../push_swap`, `../checker`)
- Tests automatically skip output when no violations occur
- Each stress test is independent and can run in parallel
- Makefile uses colored output for easy reading
- Tests clean up temporary files automatically
