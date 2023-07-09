#!/bin/bash

ERROR=0

GREEN='\033[0;32m'
RED='\033[0;31m'
RESET='\033[0m'

GLOBAL_MAT=0
NB_TESTS=0
ALL_TESTS_NB=0

function process_file () {
	FILE_TEST="$3"

	echo -n "process : $FILE_TEST ... "

	ALL_TESTS_NB=$(($ALL_TESTS_NB+1))

	"$1" "$FILE_TEST" 1 > "$FILE_TEST.antman"

	if [[ $? != 0 ]]; then
		echo "error executing::" "$1" "$FILE_TEST" 1 > "$FILE_TEST.antman"
		ERROR=1
		return
	fi

	"$2" "$FILE_TEST.antman" 1 > "$FILE_TEST.giantman"

	if [[ $? != 0 ]];then
		echo "error executing::" "$2" "$FILE_TEST.antman" 1 > "$FILE_TEST.giantman"
		ERROR=1
		return
	fi

	DIFF=`diff $FILE_TEST $FILE_TEST.giantman`
	if [[ $? != 0 ]]; then
		echo -e $RED [x] $FILE $RESET
		#echo $DIFF
		ERROR=1
	else
		ORIG=`/usr/bin/du $FILE_TEST -b | cut -f1`
		NEW=`/usr/bin/du $FILE_TEST.antman -b | cut -f1`

		MAT=$(($NEW*100))
		MAT=$(($MAT/$ORIG))
		echo -n "The file is now $MAT% of its original size"
		GLOBAL_MAT=$(($GLOBAL_MAT+$MAT))
		NB_TESTS=$(($NB_TESTS+1))

		echo -e "$GREEN [v] $FILE $RESET"
	fi
}

for FILE in `find . -name '*.ppm' -type f -print`; do
	process_file $1 $2 $FILE
done

echo ""
echo "::: => __Stats For PPM files__:"
echo -e "Number of tests passed: $GREEN$NB_TESTS$RESET/$ALL_TESTS_NB"
_TMP=$(($GLOBAL_MAT/$NB_TESTS))
_TMP=$((100-$_TMP))
echo -e "Compression ratio: $GREEN -$_TMP% $RESET"
echo ""

exit $ERROR
