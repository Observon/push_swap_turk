#!/bin/bash

# Script de teste básico para push_swap
# Testa o programa com vários cenários

PUSH_SWAP="../push_swap"
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo "========================================"
echo "  TESTE BÁSICO - PUSH_SWAP"
echo "========================================"

# Teste 1: Números já ordenados
echo ""
echo -e "${YELLOW}Teste 1: Números já ordenados${NC}"
result=$($PUSH_SWAP 1 2 3 4 5 2>&1)
if [ -z "$result" ]; then
    echo -e "${GREEN}✓ PASS${NC} - Nenhuma operação necessária"
else
    echo -e "${RED}✗ FAIL${NC} - Deveriam ser 0 operações"
fi

# Teste 2: Apenas 2 números
echo ""
echo -e "${YELLOW}Teste 2: Apenas 2 números${NC}"
result=$($PUSH_SWAP 2 1 2>&1)
if [ ! -z "$result" ]; then
    echo -e "${GREEN}✓ PASS${NC} - Operação: $result"
else
    echo -e "${RED}✗ FAIL${NC} - Deveria gerar operação"
fi

# Teste 3: 3 números
echo ""
echo -e "${YELLOW}Teste 3: 3 números${NC}"
ops=$($PUSH_SWAP 3 2 1 2>&1 | wc -l)
if [ $ops -le 3 ]; then
    echo -e "${GREEN}✓ PASS${NC} - $ops operações (limite: 3)"
else
    echo -e "${RED}✗ FAIL${NC} - $ops operações (limite: 3)"
fi

# Teste 4: 5 números
echo ""
echo -e "${YELLOW}Teste 4: 5 números${NC}"
ops=$($PUSH_SWAP 5 4 3 2 1 2>&1 | wc -l)
if [ $ops -le 12 ]; then
    echo -e "${GREEN}✓ PASS${NC} - $ops operações (limite: 12)"
else
    echo -e "${RED}✗ FAIL${NC} - $ops operações (limite: 12)"
fi

# Teste 5: Números negativos
echo ""
echo -e "${YELLOW}Teste 5: Números negativos${NC}"
ops=$($PUSH_SWAP -5 -3 -1 -4 -2 2>&1 | wc -l)
if [ $ops -gt 0 ]; then
    echo -e "${GREEN}✓ PASS${NC} - $ops operações"
else
    echo -e "${RED}✗ FAIL${NC} - Falha ao processar negativos"
fi

# Teste 6: Mistos (negativos e positivos)
echo ""
echo -e "${YELLOW}Teste 6: Números mistos${NC}"
ops=$($PUSH_SWAP 5 -3 10 -1 0 2>&1 | wc -l)
if [ $ops -gt 0 ]; then
    echo -e "${GREEN}✓ PASS${NC} - $ops operações"
else
    echo -e "${RED}✗ FAIL${NC} - Falha com números mistos"
fi

# Teste 7: Duplicados (deve falhar)
echo ""
echo -e "${YELLOW}Teste 7: Números duplicados (deve rejeitar)${NC}"
result=$($PUSH_SWAP 1 2 2 3 2>&1)
if [[ $result == *"Error"* ]]; then
    echo -e "${GREEN}✓ PASS${NC} - Duplicados rejeitados corretamente"
else
    echo -e "${RED}✗ FAIL${NC} - Deveria rejeitar duplicados"
fi

# Teste 8: 10 números aleatórios
echo ""
echo -e "${YELLOW}Teste 8: 10 números aleatórios${NC}"
nums=$(python3 -c "
import random
random.seed(42)
nums = random.sample(range(-1000, 1001), 10)
print(' '.join(map(str, nums)))
")
ops=$(echo "$nums" | xargs $PUSH_SWAP 2>&1 | wc -l)
if [ $ops -le 150 ]; then
    echo -e "${GREEN}✓ PASS${NC} - $ops operações (limite: 150)"
else
    echo -e "${RED}✗ FAIL${NC} - $ops operações (limite: 150)"
fi

# Teste 9: 100 números aleatórios
echo ""
echo -e "${YELLOW}Teste 9: 100 números aleatórios${NC}"
nums=$(python3 -c "
import random
random.seed(42)
nums = random.sample(range(-5000, 5001), 100)
print(' '.join(map(str, nums)))
")
ops=$(echo "$nums" | xargs $PUSH_SWAP 2>&1 | wc -l)
if [ $ops -le 1200 ]; then
    echo -e "${GREEN}✓ PASS${NC} - $ops operações (limite: 1200)"
else
    echo -e "${RED}✗ FAIL${NC} - $ops operações (limite: 1200)"
fi

echo ""
echo "========================================"
echo "Testes Básicos Concluídos!"
echo "========================================"
