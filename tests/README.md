# Push Swap Test Suite

Organized test suite for the push_swap project with Makefile support and comprehensive stress testing.

## Directory Structure

```
tests/
├── Makefile                       # Main test control file
├── README.md                      # This file (documentation)
├── TESTING_GUIDE.md               # Detailed testing workflow documentation
│
├── QUICK TESTS (22 cases total)
├── test_basic.sh                  # 10 basic functionality & edge case tests
├── test_checker.sh                # 4 error detection & validation tests
├── test_performance.sh            # 8 operation limit tests (3/5/100/500 numbers)
│
├── STRESS TESTS (WSL/Linux optimized)
├── run_wsl_stress_100.sh              # Stress test: 1000× 100-number cases (limit: 700 ops)
├── run_wsl_stress_3.sh            # Stress test: 1000× 3-number cases (limit: 3 ops)
├── run_wsl_stress_5.sh            # Stress test: 1000× 5-number cases (limit: 12 ops)
├── run_wsl_stress_500.sh          # Stress test: 200× 500-number cases (limit: 5500 ops)
│
├── REFERENCE BINARIES
├── checker_linux                  # Official checker binary
├── pro_checker                    # Professional checker for stress tests
│
├── DOCUMENTATION & LEGACY
├── PROJECT_SUMMARY.md             # Project completion summary
├── push_swap_test_linux.sh        # Original comprehensive tester
├── run_all_tests.sh               # Master runner (now uses test_basic + test_checker + test_performance)
├── run_official_tester.sh         # Official project tester wrapper
└── traces.txt                     # Test trace logs
```

## Quick Start

```bash
cd tests/

# View all test options
make help

# QUICK TESTS (recommended for development - 22 cases, ~5-8 seconds)
make run_all              # All quick tests (basic + checker + performance)

# SPECIFIC QUICK TESTS
make basic                # 10 basic functionality & edge case tests
make checker              # 4 error detection & validation tests
make performance          # 8 operation limit tests for various sizes

# STRESS TESTS (WSL/Linux optimized - fast and focused)
make stress_3             # 1000 cases: 3 numbers (limit: 3 ops)
make stress_5             # 1000 cases: 5 numbers (limit: 12 ops)
make stress_100           # 1000 cases: 100 numbers (limit: 700 ops)
make stress_500           # 200 cases: 500 numbers (limit: 5500 ops)

# CLEANUP
make clean                # Remove temporary test files
make fclean               # Full clean (removes binaries)
```

### Using Makefile (Recommended)

```bash
cd tests/

# Show available tests
make help

# QUICK TESTS (development workflow - 22 cases total)
make basic        # 10 basic functionality & edge case tests
make checker      # 4 error detection & validation tests
make performance  # 8 operation limit tests
make run_all      # All quick tests (~5-8 seconds)

# STRESS TESTS (optimized for robustness validation)
make stress_3     # 1000 random 3-element cases
make stress_5     # 1000 random 5-element cases
make stress_100   # 1000 random 100-element cases
make stress_500   # 200 random 500-element cases

# CLEANUP
make clean        # Remove temporary artifacts
```

### Running Master Script

```bash
cd tests/
bash run_all_tests.sh  # Runs basic + quick + extended with formatted output
```

### Running Stress Tests Individually

```bash
cd tests/

# New optimized stress tests (WSL/Linux)
bash run_wsl_stress_100.sh       # 1000 × 100-number tests
bash run_wsl_stress_3.sh     # 1000 × 3-number tests
bash run_wsl_stress_5.sh     # 1000 × 5-number tests
bash run_wsl_stress_500.sh   # 200 × 500-number tests
```

## Test Coverage

### Quick Tests (22 cases total)

#### test_basic.sh (10 cases)
Core functionality and edge case tests:
- Already sorted numbers
- Two numbers
- Three numbers  
- Five numbers
- Negative numbers
- Mixed (negative and positive)
- Duplicate detection error
- 10 random numbers
- 100 random numbers
- Large number handling

#### test_checker.sh (4 cases)
Error detection and validation:
- Duplicate error detection
- Non-numeric error detection
- Invalid instruction detection
- Already-sorted case validation

#### test_performance.sh (8 cases)
Operation limit tests with strict validation:
- **3 numbers** (max 3 ops) ✓
- **5 numbers** (max 12 ops) ✓
- **10 numbers** (max 150 ops) ✓
- **20 numbers** (max 400 ops) ✓
- **50 numbers** (max 1350 ops) ✓
- **100 numbers** (max 700 ops) ✓
- Negative numbers performance
- Mixed numbers performance

### Stress Tests (Optimized for WSL/Linux)

#### run_wsl_stress_100.sh (1000 cases)
**100-element tests with 700-operation limit**
- 1000 iterations with random 100-number arrays
- All cases ≤700 operations ✅

#### run_wsl_stress_3.sh (1000 cases)
**3-element tests with 3-operation limit**
- 1000 iterations with random 3-number arrays
- All cases ≤3 operations ✅

#### run_wsl_stress_5.sh (1000 cases)
**5-element tests with 12-operation limit**
- 1000 iterations with random 5-number arrays
- All cases ≤12 operations ✅

#### run_wsl_stress_500.sh (200 cases)
**500-element tests with 5500-operation limit**
- 200 iterations with random 500-number arrays
- All cases ≤5500 operations ✅

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

| Test Suite | Cases | Time | Purpose |
|-----------|-------|------|---------|
| test_basic.sh | 10 | ~1-2s | Core functionality |
| test_checker.sh | 4 | ~1s | Error detection |
| test_performance.sh | 8 | ~2-3s | Operation limits |
| **make run_all** | **22** | **~5-8s** | All quick tests |
| run_wsl_stress_3.sh | 1000 | ~15s | 3-element stress |
| run_wsl_stress_5.sh | 1000 | ~25s | 5-element stress |
| run_wsl_stress_100.sh | 1000 | ~120s | 100-element stress |
| run_wsl_stress_500.sh | 200 | ~180s | 500-element stress |

## Requirements

- `bash`
- `../push_swap` binary (one level up)
- `../checker` binary (one level up)
- `../pro_checker` binary (for stress test)
- `python3` (for random number generation)
- Standard Unix tools (`wc`, `shuf`, `tr`, `seq`, etc.)

## Makefile Targets Reference

| Command | Tests | Cases | Time | Purpose |
|---------|-------|-------|------|---------|
| `make help` | - | - | - | Show available commands |
| `make basic` | test_basic.sh | 10 | ~5s | Basic functionality |
| `make quick` | test_checker_quick.sh | 8 | ~3s | Checker validation |
| `make extended` | test_extended.sh | 8 | ~4s | Extended checker |
| `make run_all` | All quick | 26 | ~12s | Quick tests combined |
| `make stress_3` | run_wsl_stress_3.sh | 1000 | ~15s | 3-element stress |
| `make stress_5` | run_wsl_stress_5.sh | 1000 | ~25s | 5-element stress |
| `make stress_100` | run_wsl_stress_100.sh | 1000 | ~120s | 100-element stress |
| `make stress_500` | run_wsl_stress_500.sh | 200 | ~180s | 500-element stress |
| `make stress` | test_stress.sh | 500+ | ~90s | Comprehensive stress |
| `make run_all_comprehensive` | Everything | 500+ | ~105s | All tests |
| `make clean` | - | - | - | Clean temp files |

## Recommended Workflow

### Development Cycle
1. **Make code changes**
2. **Quick validation**: `make run_all` (~12 seconds)
   - Catches basic errors fast
   - 26 test cases covering essential functionality
3. **Before committing**: `make stress_100` (~120 seconds)
   - Validates 100-element performance
   - Ensures limit compliance (≤700 ops)

### Pre-Submission Validation
```bash
# Run complete test suite
make run_all_comprehensive

# Or individually for focused testing
make run_all          # Quick tests (26 cases)
make stress_3         # 3-element limit compliance
make stress_5         # 5-element limit compliance
make stress_100       # 100-element limit compliance
make stress_500       # 500-element limit compliance
```

### Performance Testing
```bash
# For optimization iterations
make stress_100       # Fast iteration (1000 cases, ~120s)
make stress_500       # Comprehensive (200 cases, ~180s)

# Check for edge cases
make stress_3         # Check 3-op edge cases
make stress_5         # Check 12-op edge cases
```

## Notes

- All tests reference binaries in parent directory (`../push_swap`, `../checker`, `../pro_checker`)
- Stress tests (`run_wsl_stress_*.sh`) optimized for WSL and Linux environments
- Random number generation for reproducible testing
- Tests automatically clean up temporary files on completion
- Each stress test is independent and can run in parallel
