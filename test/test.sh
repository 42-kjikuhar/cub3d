#!/bin/bash

PASS=0
FAIL=0
PROGRAM=./cub3D
TIMEOUT=2
ERROR_LOG=test/error.log

# 色
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'


# ビルド
echo "=== Building ==="
make re CFLAGS="-g -fsanitize=address,undefined" CPPFLAGS="-DDEBUG"

if [ $? -ne 0 ]; then
	echo -e "${RED}Build failed${NC}"
	exit 1
fi

echo ""

# タイムアウト
run_with_timeout() {
	"$@" &
	PID=$!
	(sleep $TIMEOUT; kill $PID 2>/dev/null) &
	WATCHER=$!
	wait $PID
	actual_code=$?
	kill $WATCHER 2>/dev/null
	wait $WATCHER 2>/dev/null
	echo $actual_code
}

# テスト
run_test() {
	local map=$1
	local expected_code=$2

	"$PROGRAM" "$map" 2> $ERROR_LOG &
	PID=$!
	(sleep $TIMEOUT; kill $PID 2>/dev/null) &
	WATCHER=$!
	wait $PID 2>/dev/null
	actual_code=$?
	kill $WATCHER 2>/dev/null
	wait $WATCHER 2>/dev/null

	# タイムアウト判定（killされた場合は143 or 137）
	if [ $actual_code -eq 143 ] || [ $actual_code -eq 137 ]; then
		echo -e "${RED}FAIL${NC}: ./cub3D $map (timeout)"
		((FAIL++))
		echo ""
		return
	fi

	if grep -q "ERROR: AddressSanitizer\|ERROR: LeakSanitizer\|runtime error:" $ERROR_LOG; then
		echo -e "${RED}FAIL${NC}: ./cub3D $map (sanitizer error)"
		cat $ERROR_LOG
		echo ""
		((FAIL++))
		return
	fi

	if [ $actual_code -eq 139 ]; then
		echo -e "${RED}FAIL${NC}: ./cub3D $map (segfault)"
		cat $ERROR_LOG
		echo ""
		((FAIL++))
		return
	fi

	if [ "$actual_code" -ne "$expected_code" ]; then
		echo -e "${RED}FAIL${NC}: ./cub3D $map (exit code: expected=$expected_code, actual=$actual_code)"
		cat $ERROR_LOG
		echo ""
		((FAIL++))
		return
	fi

	echo -e "${GREEN}PASS${NC}: ./cub3D $map"
	if [ "$actual_code" -eq "1" ]; then
		cat $ERROR_LOG
	fi
	echo ""
	((PASS++))
}

# valid: exit 0を期待
echo "=== Valid TEST ==="
PASS=0
FAIL=0
for file in test/map/valid/*; do
	[ -f "$file" ] || continue
	run_test "$file" 0
done

echo -e "${GREEN}$PASS passed${NC}, ${RED}$FAIL failed${NC}"
echo ""

# invalid: exit 1を期待
echo "=== Invalid TEST ==="
PASS=0
FAIL=0

run_test "" 1
run_test "no_exist_map.cub" 1
run_test "1.cub 2.cub" 1

rm -f test/map/invalid/read.cub
cp test/map/valid/simple.cub test/map/invalid/read.cub
chmod -r test/map/invalid/read.cub
run_test "test/map/invalid/read.cub" 1
rm -f test/map/invalid/read.cub

for case_dir in test/map/invalid/*/; do
	[ -d "$case_dir" ] || continue
	for file in "$case_dir"*; do
		[ -f "$file" ] || continue
		run_test "$file" 1
	done
done

echo -e "${GREEN}$PASS passed${NC}, ${RED}$FAIL failed${NC}"

rm -f $ERROR_LOG
