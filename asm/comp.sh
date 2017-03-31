#!/bin/bash 
if [ $3 = "rm" ]
then
	rm -rf diff.diff $1.cor $2.cor
else

rm -rf diff.diff;
rm -rf $1.cor $2.cor;
make;
./asm $1.s;
mv $1.cor $2.cor;
./zaz $1.s;
diff  $1.cor $2.cor > diff.diff
cat diff.diff
fi
