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

#sending
wget --load-cookies /tmp/.cookPie --post-data="HiddenAction=instantsms&catnamedis=Birthday&Action=sa65sdf656fdfd&chkall=on&MobNo=$rcmob&textArea=$msgg" http://site1.way2sms.com/quicksms.action






