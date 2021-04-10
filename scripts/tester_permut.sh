mkdir -p /tmp/push_swap
rm /tmp/push_swap/*.cnt
python3 -c "from itertools import permutations as p ; print('\n'.join([ ' '.join(x) for x in p('12345', 5)]))" | while read -r line; do
	echo -n '`'$line'`: '
	operation=$(./push_swap $line)
	ops_count=$(echo  "$operation" | wc -l)
	echo -n "$line|"$(echo $operation | tr '\n' ',')"\n" >> /tmp/push_swap/$ops_count.cnt
	echo -n "$ops_count ops: "
	echo "$operation" | ./checker $line
done
