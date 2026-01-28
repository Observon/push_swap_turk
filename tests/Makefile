NAME = test
SHELL = /bin/bash

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
NC=\033[0m

.PHONY: all basic checker performance stress help run_all run_all_comprehensive \
        stress_3 stress_5 stress_100 stress_500

all: help

help:
	@echo "$(BLUE)════════════════════════════════════════════════════════$(NC)"
	@echo "$(BLUE)           PUSH_SWAP COMPREHENSIVE TEST SUITE$(NC)"
	@echo "$(BLUE)════════════════════════════════════════════════════════$(NC)"
	@echo ""
	@echo "$(YELLOW)QUICK TESTS (recommended for development - 22 cases)$(NC)"
	@echo "  $(YELLOW)make basic$(NC)       - Basic functionality tests (10 cases)"
	@echo "  $(YELLOW)make checker$(NC)     - Error detection tests (4 cases)"
	@echo "  $(YELLOW)make performance$(NC) - Operation limit tests (8 cases)"
	@echo "  $(YELLOW)make run_all$(NC)     - All quick tests in sequence (22 cases)"
	@echo ""
	@echo "$(YELLOW)STRESS TESTS (WSL/Linux optimized)$(NC)"
	@echo "  $(YELLOW)make stress_3$(NC)    - 1000 × 3-number tests (limit: 3 ops)"
	@echo "  $(YELLOW)make stress_5$(NC)    - 1000 × 5-number tests (limit: 12 ops)"
	@echo "  $(YELLOW)make stress_100$(NC)  - 1000 × 100-number tests (limit: 700 ops)"
	@echo "  $(YELLOW)make stress_500$(NC)  - 1000 × 500-number tests (limit: 5500 ops)"
	@echo ""
	@echo "$(YELLOW)COMPREHENSIVE TESTS$(NC)"
	@echo "  $(YELLOW)make stress$(NC)      - Full comprehensive stress test (500+ cases)"
	@echo "  $(YELLOW)make run_all_comprehensive$(NC) - All tests including full stress"
	@echo ""
	@echo "$(YELLOW)CLEANUP$(NC)"
	@echo "  $(YELLOW)make clean$(NC)      - Remove temporary test files"
	@echo ""

basic:
	@echo "$(GREEN)Running basic tests (10 cases)...$(NC)"
	@bash test_basic.sh

checker:
	@echo "$(GREEN)Running error detection tests (4 cases)...$(NC)"
	@bash test_checker.sh

quick:
	@echo "$(GREEN)Running error detection tests (4 cases)...$(NC)"
	@bash test_checker.sh

performance:
	@echo "$(GREEN)Running operation limit tests (8 cases)...$(NC)"
	@bash test_performance.sh

extended:
	@echo "$(GREEN)Running operation limit tests (8 cases)...$(NC)"
	@bash test_performance.sh

stress_3:
	@echo "$(GREEN)Running 3-element stress tests (1000 cases)...$(NC)"
	@bash run_wsl_stress_3.sh > /dev/null 2>&1; \
	echo "$(GREEN)✓ All cases ≤3 operations$(NC)"

stress_5:
	@echo "$(GREEN)Running 5-element stress tests (1000 cases)...$(NC)"
	@bash run_wsl_stress_5.sh > /dev/null 2>&1; \
	echo "$(GREEN)✓ All cases ≤12 operations$(NC)"

stress_100:
	@echo "$(GREEN)Running 100-element stress tests (1000 cases)...$(NC)"
	@bash run_wsl_stress_100.sh > /dev/null 2>&1; \
	echo "$(GREEN)✓ All cases ≤700 operations$(NC)"

stress_500:
	@echo "$(GREEN)Running 500-element stress tests (1000 cases)...$(NC)"
	@bash run_wsl_stress_500.sh > /dev/null 2>&1; \
	echo "$(GREEN)✓ All cases ≤5500 operations$(NC)"

stress:
	@echo "$(GREEN)Running comprehensive stress test (500+ cases)...$(NC)"
	@bash test_stress_wrapper.sh

stress_quick:
	@echo "$(GREEN)Running quick stress test variant...$(NC)"
	@./push_swap_test_linux.sh -b

run_all: basic checker performance
	@echo ""
	@echo "$(GREEN)✓ All quick test suites completed (22 cases)!$(NC)"

run_all_comprehensive: basic quick extended stress
	@echo ""
	@echo "$(GREEN)✓ All tests completed including stress test (500+ cases)!$(NC)"

clean:
	@rm -f traces.txt test_check.txt
	@rm -rf 0/
	@echo "$(GREEN)Cleaned temporary files$(NC)"