#!/bin/bash

# Input files
INPUT=${1}
REFERECE="tests/ref/"
OUTPUT="tests/out/"
rm -rf "$OUTPUT"
mkdir "$OUTPUT"

if [ -z "$INPUT" ]
then
      INPUT="wearhouse"
fi

# Build
echo "************* Building targets *************"
# make > /dev/null 2>&1
make all

# Generate reference
# echo "************* Generating reference *************"
# rm -rf "$REFERECE"
# mkdir "$REFERECE"

# for i in {0..33}
# do
# 	timeout 20 ./Test "wearhouse" "tests/ref/ref" "$i" > /dev/null 2>&1
# done


# Test
echo "************* Testing *************"
TEST_SOCORES=(2 2 2 2 2 \
	2 5 2 2 2 \
	2 5 5 5 2 \
	2 3 2 3 2 \
	4 3 4 4 2 \
	2 2 2 5 5 \
	3 5 5)

SCORE=0
TOTAL_SCORE=0
for i in {0..32}; do TOTAL_SCORE=$(($TOTAL_SCORE + ${TEST_SOCORES[$i]})); done
# TESTS_FAILED=
FAIL_COUNT=0


for i in {0..32}
do

	timeout 20 ./Test $INPUT $OUTPUT"out" $i> /dev/null 2>&1
	fileOut=$OUTPUT"out"$i
	fileRef=$REFERECE"ref"$i
	diff $fileOut $fileRef > /dev/null
	EXIT_CODE=$?

	if (( i < 10 )); then
		idx=" $i"
	else
		idx=$i
	fi
	if [ $EXIT_CODE -eq 0 ]; 
	then
		echo "Test $idx ................................................. PASS"
		SCORE=$(($SCORE + ${TEST_SOCORES[$i]}))		
	else
		echo "Test $idx ................................................. FAIL"
		FAIL_COUNT=$(($FAIL_COUNT + 1))
		TESTS_FAILED[$i]="Test-$i:File-"$OUTPUT"out"$i
	fi
	echo "Score: "$SCORE"/"$TOTAL_SCORE
	echo 
done

if [[ ${TESTS_FAILED[@]:+${TESTS_FAILED[@]}} ]]; then
 	echo "Failed tests summary:"
 	echo "Failed TestsCount: "$FAIL_COUNT
	for fail in ${TESTS_FAILED[@]}; 
	do 
		echo $fail; 
	done
else
	echo "Congrats! All tests passed."
fi
