#!/bin/bash

test_ps()
{
	input="$1"

#	echo "Instruction count: "
	opcount="$(./push_swap $input | wc -l)"
	echo $opcount
#	echo "Is sorted?"
#	./push_swap $input | ./checker $input
#	if	$filename
#	then
#		echo $opcount > $filename
#	fi
}

test_ps "1 2 3 4 5"
test_ps "1 2 3 4 5 0"
test_ps "1 21 2 19 3 17 4 15 5 11"
test_ps "2 1"
test_ps "1 2 0"
test_ps " 12 21 23 32 34 43 45 54 56 65 67 76 78 87 89 98 90 -123 321 234 432 345 543 456 654 567 765 678 -867 789 -9870 9 8 7 6 5 4 3 2 1"
test_ps " -12 9999 19283112 98782913 -312873 77889 99887 -99887 -77889 2134432 -1232323 12 21 23 32 34 43 45 54 56 65 67 76 78 87 89 98 90 -123 321 234 432 345 543 456 654 567 765 678 -867 789 -9870 9 8 7 6 5 4 3 2 1"
# do_check "1 2 3 4"
# do_check "a b c d"
# do_check "0 1 0 1 f"
# do_check ""
# do_check "F"
# do_check "0"
# do_check "1 12 123 1234 12345 12345123451234512345"
# do_check "-55"
# do_check "67 -1 0 -2 99 -27 102 -99 -100 -101 4"
