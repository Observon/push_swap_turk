#!/bin/bash

# Script para testar push_swap com o checker

PUSH_SWAP="../push_swap"
CHECKER="../checker"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# Verificar se push_swap existe
if [ ! -f "$PUSH_SWAP" ]; then
    echo -e "${RED}Erro: $PUSH_SWAP não encontrado${NC}"
    exit 1
fi

# Verificar se checker existe
if [ ! -f "$CHECKER" ]; then
    echo -e "${RED}Erro: $CHECKER não encontrado${NC}"
    exit 1
fi

echo "=========================================="
echo "  TESTE COM CHECKER"
echo "=========================================="
echo ""

# Função para testar
test_checker() {
    local desc=$1
    local nums=$2
    local expected_max_ops=$3
    
    echo -e "${BLUE}$desc${NC}"
    
    # Rodar push_swap
    output=$($PUSH_SWAP $nums 2>&1)
    
    if [ $? -ne 0 ]; then
        echo -e "${RED}✗ FAIL${NC} - Erro ao executar push_swap"
        return
    fi
    
    # Contar operações
    ops=$(echo "$output" | wc -l)
    
    # Testar com checker
    result=$(echo "$output" | $CHECKER $nums)
    
    if [[ $result == "OK" ]]; then
        if [ -z "$expected_max_ops" ] || [ $ops -le $expected_max_ops ]; then
            echo -e "${GREEN}✓ PASS${NC} - $ops operações"
        else
            echo -e "${YELLOW}⚠ WARNING${NC} - $ops operações (limite: $expected_max_ops)"
        fi
    else
        echo -e "${RED}✗ FAIL${NC} - Checker: $result"
    fi
    echo ""
}

# Teste 1: Pequeno (3 números)
test_checker "Teste 1: 3 números" "3 2 1" "3"

# Teste 2: Pequeno (5 números)
test_checker "Teste 2: 5 números" "5 4 3 2 1" "12"

# Teste 3: Números negativos
test_checker "Teste 3: Números negativos" "-5 -3 -1 -4 -2" ""

# Teste 4: Mistos
test_checker "Teste 4: Mistos (negativos e positivos)" "5 -3 10 -1 0" ""

# Teste 5: 10 números aleatórios
nums=$(python3 -c "
import random
random.seed(1)
nums = random.sample(range(-1000, 1001), 10)
print(' '.join(map(str, nums)))
")
test_checker "Teste 5: 10 números aleatórios" "$nums" "150"

# Teste 6: 20 números aleatórios
nums=$(python3 -c "
import random
random.seed(2)
nums = random.sample(range(-5000, 5001), 20)
print(' '.join(map(str, nums)))
")
test_checker "Teste 6: 20 números aleatórios" "$nums" "400"

# Teste 7: 50 números aleatórios
nums=$(python3 -c "
import random
random.seed(3)
nums = random.sample(range(-10000, 10001), 50)
print(' '.join(map(str, nums)))
")
test_checker "Teste 7: 50 números aleatórios" "$nums" ""

# Teste 8: 100 números aleatórios
nums=$(python3 -c "
import random
random.seed(4)
nums = random.sample(range(-50000, 50001), 100)
print(' '.join(map(str, nums)))
")
test_checker "Teste 8: 100 números aleatórios" "$nums" "1200"

echo "=========================================="
echo "Testes Concluídos!"
echo "=========================================="
