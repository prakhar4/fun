echo "Hello World--Welcome"
echo -n "Enter the login mob no.:"
read lgmob
echo ""
echo -n "Enter login password:"
read paswd

#login
wget  --save-cookies /tmp/.cookPie --keep-session-cookies --post-data="username=$lgmob&password=$paswd&userLogin=no&button=Login" http://site1.way2sms.com/Login1.action
