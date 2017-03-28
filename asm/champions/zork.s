.name "zork"
.comment "I'M ALIIIIVE"

entry_l1:
	live		%42
	ld			%439025904, r2
	ld			%0, r16

test:
testp:
test3:
test4:

l2:		sti r1, %:live, %1
		and r1, %0, r1
			and r1, %0, r1
				and r1, %0, r1
					and r1, %0, r1
						and r1, %0, r1
							and r1, %0, r1

live:	live %1
		zjmp %:test
