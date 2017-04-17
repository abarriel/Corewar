.name "zork"
# !
.comment "I'M ALIIIIVE"

l2:		
		lld :live, r2
		and r4,%0         , r3	
		ld		%-6, r3   
		sti	r1, %:live, %1	
		ld		%150994953, r4
		st		r3, -1

live:	live %1
		zjmp %:live
