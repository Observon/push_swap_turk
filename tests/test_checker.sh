#!/bin/bash

# Script para testar checker: validação de erros e comportamento

PUSH_SWAP="../push_swap"
CHECKER="../checker"

echo "Testando Checker - Validação de Erros e Comportamento"
echo "====================================================="

# Casos de erro esperados
echo ""
echo "Testando Casos de Erro..."
echo "========================="

echo -n "Duplicados: "
$CHECKER 1 2 3 1 2>/dev/null
if [ $? -ne 0 ]; then echo "✅ Error detectado"; else echo "❌ FALHOU"; fi

echo -n "Não numérico: "
$CHECKER 1 a 3 2>/dev/null
if [ $? -ne 0 ]; then echo "✅ Error detectado"; else echo "❌ FALHOU"; fi

echo -n "Instrução inválida: "
echo "invalid" | $CHECKER 2 1 2>/dev/null
if [ $? -ne 0 ]; then echo "✅ Error detectado"; else echo "❌ FALHOU"; fi

echo -n "Overflow: "
$CHECKER 2147483648 1 2>/dev/null
if [ $? -ne 0 ]; then echo "✅ Error detectado"; else echo "❌ FALHOU"; fi

# Casos válidos
echo ""
echo "Testando Casos Válidos..."
echo "========================="

echo -n "Já ordenado: "
result=$(echo "" | $CHECKER 1 2 3)
echo "$result"

echo -n "3 números: "
result=$($PUSH_SWAP 3 2 1 | $CHECKER 3 2 1)
echo "$result"

echo -n "5 números: "
result=$($PUSH_SWAP 5 4 3 2 1 | $CHECKER 5 4 3 2 1)
echo "$result"

echo -n "10 números aleatórios: "
nums=$(python3 -c "
import random
random.seed(99)
nums = random.sample(range(0, 100), 10)
print(' '.join(map(str, nums)))
")
result=$($PUSH_SWAP $nums | $CHECKER $nums)
echo "$result"

echo ""
echo "====================================================="
echo "Testes de Checker Concluídos!"
echo "====================================================="
