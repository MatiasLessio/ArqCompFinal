.text
.global Piedrita
Piedrita:
			STMFD	SP!, {r0,r4, r5, r6, LR}
			LDR		r5, =tabla 
			MOV		r6, #0
			
ForPiedrita:
			LDRB	r4, [r5, r6]
			MOV		r0, r4
			BL		Binario
			ADD		r6, r6, #1
			CMP		r6, #4
			BNE		ForPiedrita
			BL		Termino
			
			
Termino:
			LDMFD	SP!, {r0,r4, r5, r6, LR}
			MOV		PC, LR
			
tabla:
	.byte 0x80
	.byte 0x20
	.byte 0x08
	.byte 0x02
