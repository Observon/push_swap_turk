NAME = test
SHELL = /bin/bash

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
NC=\033[0m

.PHONY: all basic quick extended stress help run_all run_all_comprehensive

all: help

help:
	@echo "$(BLUE)════════════════════════════════════════════════════════$(NC)"
	@echo "$(BLUE)           PUSH_SWAP COMPREHENSIVE TEST SUITE$(NC)"
	@echo "$(BLUE)════════════════════════════════════════════════════════$(NC)"
	@echo ""
	@echo "Quick Tests (recommended for development):"
	@echo "  $(YELLOW)make basic$(NC)       - Basic functionality tests (10 cases)"
	@echo "  $(YELLOW)make quick$(NC)       - Checker validation tests (8 cases)"
	@echo "  $(YELLOW)make extended$(NC)    - Extended checker tests (8 cases)"
	@echo "  $(YELLOW)make run_all$(NC)     - All quick tests in sequence (26 cases)"
	@echo ""
	@echo "Comprehensive Tests (for validation):"
	@echo "  $(YELLOW)make stress$(NC)      - Comprehensive stress test (500+ cases)"
	@echo "  $(YELLOW)make stress_quick$(NC) - Quick stress test variant"
	@echo ""
	@echo "Combined:"
	@echo "  $(YELLOW)make run_all_comprehensive$(NC) - All tests including stress"
	@echo ""

basic:
	@echo "$(GREEN)Running basic tests (10 cases)...$(NC)"
	@bash test_basic.sh

quick:
	@echo "$(GREEN)Running quick checker tests (8 cases)...$(NC)"
	@bash test_checker_quick.sh

extended:
	@echo "$(GREEN)Running extended checker tests (8 cases)...$(NC)"
	@bash test_extended.sh

stress:
	@echo "$(GREEN)Running comprehensive stress test (500+ cases)...$(NC)"
	@bash test_stress_wrapper.sh

stress_quick:
	@echo "$(GREEN)Running quick stress test variant...$(NC)"
	@./push_swap_test_linux.sh -b

run_all: basic quick extended
	@echo ""
	@echo "$(GREEN)✓ All quick test suites completed (26 cases)!$(NC)"

run_all_comprehensive: basic quick extended stress
	@echo ""
	@echo "$(GREEN)✓ All tests completed including stress test (500+ cases)!$(NC)"

clean:
	@rm -f traces.txt test_check.txt
	@rm -rf 0/
	@echo "$(GREEN)Cleaned temporary files$(NC)"
