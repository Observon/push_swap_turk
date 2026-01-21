#!/bin/bash

# Stress test wrapper - Comprehensive push_swap and checker testing
# Based on GEMARTIN's tester (modified to run from tests/ folder)

BLUE='\033[0;94m'
GREEN='\033[1;92m'
RED='\033[1;91m'
YELLOW='\033[0;93m'
CYAN='\033[0;96m'
DEF_COLOR='\033[0;39m'

printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};
printf ${YELLOW}"\n\t\tCOMPREHENSIVE STRESS TEST\n"${DEF_COLOR};
printf ${BLUE}"\n-------------------------------------------------------------\n"${DEF_COLOR};

bash push_swap_test_linux.sh

exit $?
