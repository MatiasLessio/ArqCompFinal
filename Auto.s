.text
.global AutoFantastico
AutoFantastico:
			STMFD	SP!, {r0,r4, r5, r6, r7, LR}
			MOV		r4, #0x80 
			MOV		r5, #8 
			
ForAuto1:
			MOV		r0, r4
			BL		IntToBinario
			MOV		r4, r4, LSR #1
			SUBS		r5, r5, #1
			;CMP		r5,#0
			BNE		ForAuto1
			
			MOV		r4, #0x02
			MOV		r5, #7
			
ForAuto2:
			MOV		r0, r4
			BL		IntToBinario
			MOV		r4, r4, LSL #1
			SUBS		r5, r5, #1
			;CMP		r5,#0
			BNE		ForAuto2
			BEQ		Termino
			
Termino:
			LDMFD	SP!, {r0,r4, r5, r6, r7, LR}
			MOV		PC, LR