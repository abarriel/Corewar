.name "zork"
.comment "I'M ALIIIIVE"

l:		sti r1, %:live, %1
		and r1, %0, r1
# zjmp %:live

		live:	live %1
zjmp %:live
zjmp:
	sti		r1, %:live, %1
	sti     r1, %:live, %1
	fork    %:live
