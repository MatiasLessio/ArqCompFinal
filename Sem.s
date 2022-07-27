.text
.global Semaforo 
Semaforo:
			STMFD	SP!, {r0,r4, r5, r6, r7, LR}
			MOV		r4, #0x80
			MOV		r5, #3
			
ForSemaforo1:
			MOV		r0, r4
			BL 		Binario
			MOV		r4, r4, LSR #2 
			ADD		r4,r4,#0x80
			SUBS		r5, r5, #1
			;CMP		R5,#0
			BNE		ForSemaforo1
			
			MOV		r4, #0x80 
			MOV		r5, #8
			
ForSemaforo2:
			MOV		r0, r4
			BL 		Binario
			MOV		r4, r4, LSR #1 
			ADD		r4,r4,#0x80 
			SUBS		r5, r5, #1
			;CMP		R5,#0
			BNE		ForSemaforo2
			BEQ		Termino
			
			
Termino:
			LDMFD	SP!, {r0,r4, r5, r6, r7, LR}
			MOV		PC, LR
