#!/bin/bash

ERROR="Error"

INPUT1="1 2 3 4"
INPUT2="a b c d"
INPUT3="0 1 0 1 f"
INPUT4=""
INPUT5="F"
INPUT6="0"
INPUT7="1 12 123 1234 12345 12345123451234512345"
INPUT8="-55"
INPUT9="67 -1 0 -2 99 -27 102 -99 -100 -101 4"
INPUT=("$INPUT1" "$INPUT2" "$INPUT3")

if (./checker $INPUT7);
then
	echo OK
else
	echo KO
fi

# for i in "${INPUT[@]}";
# do
# 	if (./checker "$i");
# 	then
# 		echo OK
# 	else
# 		echo KO
# 	fi
# done
#if [ "$RET" = $ERROR ];
#then
#	echo OK;
#else
#	echo KO;
#fi
