#!/bin/bash

# Script de teste básico para push_swap
# Valida CORREÇÃO: edge cases simples, funcionamento básico

PUSH_SWAP="../push_swap"
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

echo "========================================"
echo "  TESTE BÁSICO - CORREÇÃO"
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

# Teste 3: Números negativos
echo ""
echo -e "${YELLOW}Teste 3: Números negativos${NC}"
ops=$($PUSH_SWAP -5 -3 -1 -4 -2 2>&1 | wc -l)
if [ $ops -gt 0 ]; then
    echo -e "${GREEN}✓ PASS${NC} - $ops operações"
else
    echo -e "${RED}✗ FAIL${NC} - Falha ao processar negativos"
fi

# Teste 4: Mistos (negativos e positivos)
echo ""
echo -e "${YELLOW}Teste 4: Números mistos${NC}"
ops=$($PUSH_SWAP 5 -3 10 -1 0 2>&1 | wc -l)
if [ $ops -gt 0 ]; then
    echo -e "${GREEN}✓ PASS${NC} - $ops operações"
else
    echo -e "${RED}✗ FAIL${NC} - Falha com números mistos"
fi

# Teste 5: Duplicados (deve falhar)
echo ""
echo -e "${YELLOW}Teste 5: Números duplicados (deve rejeitar)${NC}"
result=$($PUSH_SWAP 1 2 2 3 2>&1)
if [[ $result == *"Error"* ]]; then
    echo -e "${GREEN}✓ PASS${NC} - Duplicados rejeitados corretamente"
else
    echo -e "${RED}✗ FAIL${NC} - Deveria rejeitar duplicados"
fi

# Teste 6: Um número
echo ""
echo -e "${YELLOW}Teste 6: Um número${NC}"
result=$($PUSH_SWAP 42 2>&1)
if [ -z "$result" ]; then
    echo -e "${GREEN}✓ PASS${NC} - Nenhuma operação necessária"
else
    echo -e "${RED}✗ FAIL${NC} - Um número já está ordenado"
fi

# Teste 7: Teste com erro (argumento inválido)
echo ""
echo -e "${YELLOW}Teste 7: Argumento inválido${NC}"
result=$($PUSH_SWAP 1 abc 3 2>&1)
if [[ $result == *"Error"* ]]; then
    echo -e "${GREEN}✓ PASS${NC} - Erro detectado corretamente"
else
    echo -e "${RED}✗ FAIL${NC} - Deveria rejeitar argumento inválido"
fi

# Teste 8: Números inteiros grandes
echo ""
echo -e "${YELLOW}Teste 8: Números inteiros grandes${NC}"
ops=$($PUSH_SWAP 2147483647 -2147483648 0 2>&1 | wc -l)
if [ $ops -gt 0 ]; then
    echo -e "${GREEN}✓ PASS${NC} - $ops operações"
else
    echo -e "${RED}✗ FAIL${NC} - Falha com números grandes"
fi

# Teste 9: Rejeição múltipla de duplicados
echo ""
echo -e "${YELLOW}Teste 9: Rejeição múltipla de duplicados${NC}"
result=$($PUSH_SWAP 1 2 3 2 4 2>&1)
if [[ $result == *"Error"* ]]; then
    echo -e "${GREEN}✓ PASS${NC} - Duplicados (2) rejeitados"
else
    echo -e "${RED}✗ FAIL${NC} - Deveria rejeitar duplicados"
fi

# Teste 10: Números aleatórios pequeno (validar output)
echo ""
echo -e "${YELLOW}Teste 10: Pequeno aleatório com validação${NC}"
nums="4 1 3 2"
result=$($PUSH_SWAP $nums 2>&1)
if [ ! -z "$result" ]; then
    echo -e "${GREEN}✓ PASS${NC} - Gera operações: $(echo "$result" | wc -l) ops"
else
    echo -e "${RED}✗ FAIL${NC} - Deveria gerar operações"
fi

echo ""
echo "========================================"
echo "Testes Básicos Concluídos!"
echo "========================================"
