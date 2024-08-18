#!/bin/bash
base_str=""
echo -n "" > test.txt
for (( i=0; i<100; i++ )) do
	base_str+="_";
done

arr_str=()

read -r level

recursive () {
	local cur_level=$1
	local cur_row=$2
	local pos=$3
	local height=$4

	if [ "$cur_level" -eq "$level" ]; then
		return
	fi

	for (( i=1; i<=height; i++ )) do
	    arr_str[cur_row]="${arr_str[cur_row]:0:$(( pos-1 ))}1${arr_str[cur_row]:$pos}"
		# echo "${arr_str[cur_row]}" >> test.txt
		(( cur_row+=1 ))
	done
	
	for (( i=1; i<=height; i++ )) do
		arr_str[cur_row]="${arr_str[cur_row]:0:$(( pos-i-1 ))}1${arr_str[cur_row]:$(( pos-i ))}"
		arr_str[cur_row]="${arr_str[cur_row]:0:$(( pos+i-1 ))}1${arr_str[cur_row]:$(( pos+i ))}"
		# echo "${arr_str[cur_row]}" >> test.txt
		(( cur_row+=1 ))
	done

	recursive "$(( cur_level+1 ))" "$cur_row" $(( pos-height )) $(( height/2 ))
	recursive "$(( cur_level+1 ))" "$cur_row" $(( pos+height )) $(( height/2 ))
}

for (( i=1; i<64; i++ )) do
	arr_str[i]=$base_str;
done

recursive 0 1 50 16

for (( i=63; i>0; i-- )) do
	echo "${arr_str[i]}" >> test.txt
done