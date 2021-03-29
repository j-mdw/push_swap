#!/bin/bash
function do_check()
{
	input="$1"

	if (./checker $input);
	then
		echo OK
	else
		echo KO
	fi
}

do_check "1 2 3 4"
do_check "a b c d"
do_check "0 1 0 1 f"
do_check ""
do_check "F"
do_check "0"
do_check "1 12 123 1234 12345 12345123451234512345"
do_check "-55"
do_check "67 -1 0 -2 99 -27 102 -99 -100 -101 4"
