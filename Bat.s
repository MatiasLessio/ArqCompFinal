.text
.global Bateria
Bateria:
				STMFD	SP!, {r0,r4, r5, r6, LR} 
				LDR		r5, =tabla 
				MOV		r6, #0 
				
ForCargadeBateria:
				LDRB		r4, [r5, r6] 
				MOV		r0, r4
				BL		Binario
				ADD		r6, r6, #1  
				CMP		r6, #9     
				BNE		ForCargadeBateria	
				BL		Termino
				
				
Termino:
				LDMFD	SP!, {r0,r4, r5, r6, LR} 
				MOV	PC, LR
tabla:
	.byte 0x0
	.byte 0x80
	.byte 0xC0
	.byte 0xE0
	.byte 0xF0
	.byte 0xF8
	.byte 0xFC
	.byte 0xFE
	.byte 0xFF				
