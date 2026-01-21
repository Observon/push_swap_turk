# Push Swap Test Suite

Organized test suite for the push_swap project with Makefile support.

## Directory Structure

```
tests/
├── Makefile                       # Main test control file
├── README.md                      # This file
├── .gitignore                     # Ignore test artifacts
├── run_all_tests.sh              # Master test runner with nice formatting
├── test_basic.sh                 # Basic functionality tests (10 cases)
├── test_checker_quick.sh          # Quick checker validation tests (8 cases)
├── test_extended.sh              # Extended checker tests with limits (8 cases)
├── test_stress.sh                # Full stress test (5365 lines, 500+ cases)
├── test_stress_wrapper.sh         # Wrapper to run stress test
├── push_swap_test_linux.sh        # Original comprehensive tester
└── run_official_tester.sh         # Official tester wrapper (optional)
```

## Quick Start

```bash
# View all test options
cd tests/
make help

# Run quick tests (recommended during development)
make run_all              # 26 cases in ~12 seconds

# Run specific test suites
make basic                # 10 basic tests
make quick                # 8 quick validation tests
make extended             # 8 extended tests

# Run comprehensive validation
make stress               # 500+ case stress test
make run_all_comprehensive # Everything

# Clean temporary files
make clean
```

### Using Makefile (Recommended)

```bash
cd tests/

# Show available tests
make help

# Quick Tests (recommended for development)
make basic        # Basic functionality
make quick        # Checker validation
make extended     # Extended checker
make run_all      # All quick tests (26 cases total)

# Comprehensive Tests
make stress       # Full stress test (500+ cases, takes 1-2 min)
make stress_quick # Quick stress variant

# Everything
make run_all_comprehensive  # All tests including stress
```

### Running Master Script

```bash
cd tests/
bash run_all_tests.sh  # Runs basic + quick + extended with formatted output
```

### Running Individual Tests

```bash
cd tests/

bash test_basic.sh              # 10 cases
bash test_checker_quick.sh      # 8 cases
bash test_extended.sh           # 8 cases
bash test_stress_wrapper.sh     # 500+ cases (comprehensive)
```

## Test Coverage

### test_basic.sh (10 cases)
Tests push_swap functionality:
- Already sorted numbers
- Two numbers
- Three numbers
- Five numbers
- Negative numbers
- Mixed (negative and positive)
- Duplicate detection
- 10 random numbers
- 100 random numbers
- Performance limits

### test_checker_quick.sh (8 cases)
Tests checker and error handling:
- 5 random test cases with push_swap + checker
- Duplicate error detection
- Non-numeric error detection
- Invalid instruction detection
- Valid already-sorted case
- 3 number case validation
- 5 number case validation

### test_extended.sh (8 cases)
Tests push_swap + checker with operation limits:
- 3 numbers (max 3 ops)
- 5 numbers (max 12 ops)
- Negative numbers
- Mixed numbers
- 10 random numbers (max 150 ops)
- 20 random numbers (max 400 ops)
- 50 random numbers
- 100 random numbers (max 1200 ops)

### test_stress.sh / test_stress_wrapper.sh (500+ cases)
Comprehensive stress test covering:
- Error detection (non-numeric, duplicates, invalid args)
- Memory validation
- Performance testing from 3 to 500+ numbers
- All operation types (push, rotate, reverse rotate, swap)
- Random input generation and validation

## Expected Output

Successful test runs show:
- ✅ `✓ PASS` for successful tests
- ✅ `✅ Error detectado` for error handling
- ✅ `OK` for checker validation
- ✅ Operation counts within expected limits
- ✅ `[OK]` for stress test cases
- ✅ `[MEMORY OK]` for memory validation in stress tests
- ✅ Final message: "Congrats, all tests have been completed successfully"

## Test Execution Times

- **Quick tests (make run_all)**: ~10-15 seconds (26 cases)
- **Stress test (make stress)**: ~60-120 seconds (500+ cases)
- **Full suite (make run_all_comprehensive)**: ~2-3 minutes

## Requirements

- `bash`
- `../push_swap` binary (one level up)
- `../checker` binary (one level up)
- `../pro_checker` binary (for stress test)
- `python3` (for random number generation)
- Standard Unix tools (`wc`, `shuf`, `tr`, `seq`, etc.)

## Makefile Targets Reference

| Command | Tests | Time | Purpose |
|---------|-------|------|---------|
| `make help` | - | - | Show available commands |
| `make basic` | 10 | ~5s | Basic functionality |
| `make quick` | 8 | ~3s | Checker validation |
| `make extended` | 8 | ~4s | Extended checker |
| `make run_all` | 26 | ~12s | All quick tests |
| `make stress` | 500+ | ~90s | Comprehensive stress |
| `make stress_quick` | 500+ | ~90s | Stress variant |
| `make run_all_comprehensive` | 500+ | ~105s | Everything |
| `make clean` | - | - | Clean temp files |

## Recommended Workflow

1. **During development**: Use `make run_all` for quick feedback (26 cases, ~12 seconds)
2. **Before committing**: Use `make run_all_comprehensive` for full validation
3. **For debugging**: Run individual test script for specific cases

## Notes

- All tests reference binaries in parent directory (`../push_swap`, `../checker`)
- Stress test (`push_swap_test_linux.sh`) is now in tests/ folder
- Random number generation uses fixed seeds for reproducibility
- Tests clean up temporary files on completion
