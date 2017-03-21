#ld
#d
#d
#d
                       									# .name "j"
                        .name            "zork" # fsrfrs
.comment "I'M ALIIIIVE"
#d
#d
#d
#d
#d
l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
