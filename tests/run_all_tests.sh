#!/bin/bash

# Master test runner script
# Runs all test suites with nice formatting

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

clear

echo -e "${BLUE}"
echo "╔════════════════════════════════════════════════════════════════╗"
echo "║          PUSH_SWAP TEST SUITE - COMPREHENSIVE TESTING          ║"
echo "╚════════════════════════════════════════════════════════════════╝"
echo -e "${NC}"
echo ""

# Check if binaries exist
if [ ! -f "../push_swap" ]; then
    echo -e "${RED}✗ ERROR: ../push_swap not found${NC}"
    exit 1
fi

if [ ! -f "../checker" ]; then
    echo -e "${RED}✗ ERROR: ../checker not found${NC}"
    exit 1
fi

echo -e "${GREEN}✓ Binaries found${NC}"
echo ""

# Test 1: Basic tests
echo -e "${YELLOW}┌─ Test 1: Basic Functionality${NC}"
echo -e "${YELLOW}└─────────────────────────────────${NC}"
bash test_basic.sh
BASIC_RESULT=$?
echo ""

# Test 2: Quick checker tests
echo -e "${YELLOW}┌─ Test 2: Checker Error Handling${NC}"
echo -e "${YELLOW}└─────────────────────────────────${NC}"
bash test_checker_quick.sh
QUICK_RESULT=$?
echo ""

# Test 3: Extended checker tests
echo -e "${YELLOW}┌─ Test 3: Extended Checker Tests${NC}"
echo -e "${YELLOW}└─────────────────────────────────${NC}"
bash test_extended.sh
EXTENDED_RESULT=$?
echo ""

# Summary
echo -e "${BLUE}"
echo "╔════════════════════════════════════════════════════════════════╗"
echo "║                         TEST SUMMARY                           ║"
echo "╚════════════════════════════════════════════════════════════════╝"
echo -e "${NC}"

if [ $BASIC_RESULT -eq 0 ]; then
    echo -e "${GREEN}✓ Basic tests${NC}"
else
    echo -e "${RED}✗ Basic tests${NC}"
fi

if [ $QUICK_RESULT -eq 0 ]; then
    echo -e "${GREEN}✓ Quick checker tests${NC}"
else
    echo -e "${RED}✗ Quick checker tests${NC}"
fi

if [ $EXTENDED_RESULT -eq 0 ]; then
    echo -e "${GREEN}✓ Extended checker tests${NC}"
else
    echo -e "${RED}✗ Extended checker tests${NC}"
fi

echo ""

if [ $BASIC_RESULT -eq 0 ] && [ $QUICK_RESULT -eq 0 ] && [ $EXTENDED_RESULT -eq 0 ]; then
    echo -e "${GREEN}🎉 All tests passed!${NC}"
    exit 0
else
    echo -e "${RED}❌ Some tests failed${NC}"
    exit 1
fi
