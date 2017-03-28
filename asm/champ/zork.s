.name "zork"
.comment "I'M ALIIIIVE"

l2:
	and r1,%0,r1
	add r1,r2,r5
	lld 455, r4
	sti r1,455,%1

live: live %1
	zjmp %:live
	
