echo "Hello world - Send sms"
echo "Enter your message:"
read msgg

for i in $msgg
do
	now="$now+$i"
done

now=${now:1}
echo $now

#len=awk{length(now)}
#echo $len
echo ""
echo -n "Enter receiver mobile number:"
read rcmob

if ! [[ "$rcmob" =~ ^[0-9]+$ ]] ; then
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
			rcmob=$num
		fi		
	fi
fi

echo "$msgg"
echo ""
echo "$rcmob"

#sending
#wget --load-cookies cookie --post-data="HiddenAction=instantsms&catnamedis=Birthday&Action=sa65sdf656fdfd&chkall=on&MobNo=$rcmob&textArea=$msgg" http://site4.way2sms.com/quicksms.action


