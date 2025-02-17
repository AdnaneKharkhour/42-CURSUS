#!/bin/bash

OUTFILE="outfile"
LIMITER="END"

echo "🔹 Test 1: Basic here_doc (cat | wc -l)"
./pipex_bonus here_doc $LIMITER "cat" "wc -l" $OUTFILE <<EOF
line 1
line 2
line 3
$LIMITER
EOF
RESULT=$(cat $OUTFILE)
echo "Result: $RESULT"
echo "Expected: 3"
echo "----------------------------------------"

echo "🔹 Test 2: here_doc with grep"
./pipex_bonus here_doc $LIMITER "cat" "grep line" $OUTFILE <<EOF
line 1
another line
no match here
$LIMITER
EOF
RESULT=$(cat $OUTFILE | wc -l)
echo "Result: $RESULT"
echo "Expected: 2"
echo "----------------------------------------"

echo "🔹 Test 3: here_doc with empty input"
./pipex_bonus here_doc $LIMITER "cat" "wc -l" $OUTFILE <<EOF
$LIMITER
EOF
RESULT=$(cat $OUTFILE)
echo "Result: $RESULT"
echo "Expected: 0"
echo "----------------------------------------"

echo "🔹 Test 4: here_doc with output appending (>>)"
echo "old content" > $OUTFILE
./pipex_bonus here_doc $LIMITER "cat" "tee -a" $OUTFILE <<EOF
new content
$LIMITER
EOF
RESULT=$(cat $OUTFILE)
echo "Result: $RESULT"
echo "Expected: old content\nnew content"
echo "----------------------------------------"

echo "✅ All tests completed!"
