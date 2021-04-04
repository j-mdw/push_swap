#!/bin/bash

for file in *.c; do
	[ -f "$file" ] || continue
	vim $file -c 'retab!' -c 'Stdheader' -c 'wq'
done

#ex stack_len_bk.c <<EOF
#	:Stdheader
#	:retab!
#	:wq
#EOF

#vim -E stack_len_bk.c <<EOF
#	:retab!
#	:Stdheader
#	:wq
#EOF
