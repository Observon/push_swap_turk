#!/bin/bash

# Script para testar checker com vários casos

PUSH_SWAP="../push_swap"
CHECKER="../checker"

echo "Testando checker com casos aleatórios..."
echo "========================================"

for i in {1..5}; do
    ARG=$(seq 1 100 | shuf | head -100 | tr '\n' ' ')
    result=$($PUSH_SWAP $ARG | $CHECKER $ARG)
    echo "Test $i: $result"
done

echo ""
echo "Testando casos de erro..."
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

echo ""
echo "Testando casos válidos..."
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
