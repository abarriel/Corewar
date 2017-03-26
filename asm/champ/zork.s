.name "zork"
.comment "I'M ALIIIIVE"

l2:

	or r1,%400,r4
	and r1,%:live,r4
	xor r1,%-44,r4
	# ld %100,r1

live: live %1
	# zjmp %:live
	