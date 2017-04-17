#!/bin/bash 
if [ $2 = "rm" ]
then
{
	rm -rf diff.diff $1.cor $1_mon.cor;
	rm -rf hex_diff.diff;
	rm -rf $1_dump $1_my_dump;
}
else
make;
./asm $1.s;
mv $1.cor $1_mon.cor;
echo "\n\nMon Joeur =  $1_mon.cor\n\n";
./zaz $1.s;
echo "\n\nLe Joeur de zaz = $1.cor\n\n";
hexdump $1.cor > $1_dump;
hexdump $1_mon.cor > $1_my_dump;
diff $1_dump $1_my_dump > hex_diff.diff;
cat hex_diff.diff;
vi hex_diff.diff;
fi
