.text
.global OlaHumana
OlaHumana:
			STMFD	SP!, {r0,r4, r5, r6, r7, LR}
			MOV		r4, #0xE0 
			MOV		r5, #6 
			
ForOlaHumana1:
			MOV		r0, r4
			BL		IntToBinario
			MOV		r4, r4, LSR #1
			SUBS		r5, r5, #1
			;CMP		r5,#0
			BNE		ForOlaHumana1
			
			MOV		r4, #0x07
			MOV		r5, #6
			
ForOlaHumana2:
			MOV		r0, r4
			BL		IntToBinario
			MOV		r4, r4, LSL #1
			SUBS		r5, r5, #1
			;CMP		r5,#0
			BNE		ForOlaHumana2
			BEQ		Termino
			
Termino:
			LDMFD	SP!, {r0,r4, r5, r6, r7, LR}
			MOV		PC, LR
