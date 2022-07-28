.text
.global Choque
Choque:
				STMFD	SP!, {r0,r4, r5, r6, LR} 
				LDR		r5, =tabla 
				MOV		r6, #0 
				
ForCargadeChoque:
				LDRB		r4, [r5, r6] 
				MOV		r0, r4
				BL		IntToBinario
				ADD		r6, r6, #1  
				CMP		r6, #7     
				BNE		ForCargadeChoque	
				BL		Termino
				
				
Termino:
				LDMFD	SP!, {r0,r4, r5, r6, LR} 
				MOV	PC, LR
tabla:
	.byte 0x81
	.byte 0x42
	.byte 0x24
	.byte 0x18
	.byte 0x24
	.byte 0x42
	.byte 0x81