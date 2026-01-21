#!/bin/bash

# Wrapper para rodar o tester oficial do Push-Swap-Tester

cd "$(dirname "$0")/Push-Swap-Tester" || exit 1

# Criar symlink se não existir
if [ ! -L "push_swap" ]; then
    ln -sf ../push_swap push_swap
fi

# Converter para LF se necessário
if file push_swap_test_linux.sh | grep -q CRLF; then
    sed -i 's/\r$//' push_swap_test_linux.sh
fi

echo "🚀 Iniciando Push-Swap Tester Oficial..."
echo "========================================"
echo ""

# Rodar o teste
bash push_swap_test_linux.sh

exit $?
