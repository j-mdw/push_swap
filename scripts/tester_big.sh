mkdir -p /tmp/push_swap
rm /tmp/push_swap/*.cnt
python3 -c "from itertools import permutations as p ; print('\n'.join([ ' '.join(x) for x in p('0123456789', 10)]))" | while read -r line; do
	echo -n '`'$line'`: '
	echo $(./push_swap $line)
#	echo $operation
	#ops_count=$(echo  "$operation" | wc -l)
#	echo -n "$line|"$(echo $operation | tr '\n' ',')"\n" >> /tmp/push_swap/$ops_count.cnt
#	echo -n "$ops_count ops: "
#	echo "$operation" | ./checker $line
done
echo
echo "Distribution: "
for x in $(seq 0 20); do
	file=/tmp/push_swap/$x.cnt
	if [[ ! -f "$file" ]]; then continue; fi
	echo "$x ops: $(cat $file | wc -l)"
done
