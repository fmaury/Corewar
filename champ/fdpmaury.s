.name "fdpmaury"
.comment "cc"

zjmp %:preload 


preload:	sti r1, %:cc, %1
			sti r1, %:cc, %10
			sti r1, %:cc, %100
			sti r1, %:cc, %500

cc:			live %1
