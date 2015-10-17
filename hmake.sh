MY_PATH="`dirname \"$0\"`"
MY_PATH="`( cd \"$MY_PATH\" && pwd )`"
TMP_FILE=`mktemp XXXXXXXXX.tmp`
$MY_PATH/./hmake $1 > $TMP_FILE
cat $TMP_FILE >> $1
rm $TMP_FILE
