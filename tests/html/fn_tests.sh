#!/bin/bash

ERROR=0

GREEN='\033[0;32m'
RED='\033[0;31m'
RESET='\033[0m'

function process_file () {
	FILE_TEST=$3

	echo process : $FILE_TEST ...

	$1 "$FILE_TEST" 1 > "$FILE_TEST.antman"

	if [[ $? != 0 ]]; then
		echo ICI
		exit 1
	fi

	$2 "$FILE_TEST.antman" 1 > "$FILE_TEST.giantman"

	if [[ $? != 0 ]];then
		echo ET ICI
		exit 1
	fi

	ORIG=`/usr/bin/du $FILE_TEST -b | cut -f1`
	NEW=`/usr/bin/du $FILE_TEST.antman -b | cut -f1`

	MAT=$(($NEW*100))
	MAT=$(($MAT/$ORIG))

	echo The file was compressed and reduced to $MAT% of its original size

	DIFF=`diff $FILE_TEST $FILE_TEST.giantman`
	if [[ $? != 0 ]]; then
		echo -e $RED [x] $FILE $RESET
		echo $DIFF
		ERROR=1
	else
		echo -e $GREEN [v] $FILE $RESET
	fi
	echo
}

for FILE in `find . -name '*.html' -type f -print`; do
	process_file $1 $2 $FILE
done
exit $ERROR
