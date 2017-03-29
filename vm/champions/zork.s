.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		add r2,r3,r5
		and r1, %0, r1

live:	live %1
		zjmp %:live
