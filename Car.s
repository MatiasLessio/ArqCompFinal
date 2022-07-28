.text
.global Carrera
Carrera:
				STMFD	SP!, {r0,r4, r5, r6, LR} 
				LDR		r5, =tabla 
				MOV		r6, #0 
				
ForCargadeCarrera:
				LDRB		r4, [r5, r6] 
				MOV		r0, r4
				BL		IntToBinario
				ADD		r6, r6, #1  
				CMP		r6, #6     
				BNE		ForCargadeCarrera	
				BL		Termino
				
				
Termino:
				LDMFD	SP!, {r0,r4, r5, r6, LR} 
				MOV	PC, LR
tabla:
	.byte 0xA0
	.byte 0x30
	.byte 0x08
	.byte 0x06
	.byte 0x03
	.byte 0x01