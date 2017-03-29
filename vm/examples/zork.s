.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, 9, %2
		and r4, %0, r3

live:	live %1
		zjmp %:live
