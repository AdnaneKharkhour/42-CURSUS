#!/bin/bash

OUTFILE1="outfile1"
OUTFILE2="outfile2"
OUTFILE3="outfile3"
OUTFILE4="outfile4"
LIMITER="END"

echo "🔹 Test 1: Basic here_doc (cat | wc -l)"
./pipex here_doc $LIMITER "cat" "wc -l" $OUTFILE1 <<EOF
line 1
line 2
line 3
$LIMITER
EOF
RESULT=$(cat $OUTFILE1)
echo "Result: $RESULT"
echo "Expected: 3"
echo "----------------------------------------"

echo "🔹 Test 2: here_doc with grep"
./pipex here_doc $LIMITER "cat" "grep line" $OUTFILE2 <<EOF
line 1
another line
no match here
$LIMITER
EOF
RESULT=$(cat $OUTFILE2 | wc -l)
echo "Result: $RESULT"
echo "Expected: 2"
echo "----------------------------------------"

echo "🔹 Test 3: here_doc with empty input"
./pipex here_doc $LIMITER "cat" "wc -l" $OUTFILE3 <<EOF
$LIMITER
EOF
RESULT=$(cat $OUTFILE3)
echo "Result: $RESULT"
echo "Expected: 0"
echo "----------------------------------------"

echo "🔹 Test 4: here_doc with output appending (>>)"
echo "old content" > $OUTFILE4
./pipex here_doc $LIMITER "cat" "tee -a" $OUTFILE4 <<EOF
new content
$LIMITER
EOF
RESULT=$(cat $OUTFILE4)
echo "Result: $RESULT"
echo "Expected: old content\nnew content"
echo "----------------------------------------"

echo "✅ All tests completed!"
