str=`grep -iR "$1" .`

if [[ -z "$str" ]]
then
	echo "Contact not found"
else
	for i in $str
	do
		if ! [[ "$i" =~ ^[0-9]+$ ]] ; then
			continue 
		else
			num=$i
		fi
	done
	if [[ -z "$num" ]]
	then
		echo "Number not found"
	else
		echo "NUMBER IS : $num"
	fi		


fi






#read yournumber1
#yournumber=""

#if ! [[ "$yournumber" =~ ^[0-9]+$ ]] ; then
#	echo "error: Not a number"
#else
#	echo "yes number"
#fi
