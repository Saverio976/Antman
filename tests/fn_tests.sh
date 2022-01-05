#!/bin/bash

ERROR=0

TESTS="html/fn_tests.sh ppm/fn_tests.sh txt/fn_tests.sh"

echo
echo start tests
echo

for EXE in $TESTS; do
	./tests/$EXE $1 $2
	if [[ $? != 0 ]]; then
		ERROR=1
	fi
done

echo

exit $ERROR
