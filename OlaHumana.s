.text
.global entrada3
.type entrada3 function	
			MOV		SP, #pilaptr
			BL		OlaHumana
			end
			
OlaHumana
			STMFD	SP!, {r4, r5, r6, r7, LR} ; Se salvan los valores
			MOV		r4, #0xE0 ; 1110 0000
			MOV		r5, #6 ; contador
			
ForOlaHumana1
			MOV		r0, r4 ; siempre se devuelve o muestra en r0 (Concepto)
			MOV		r4, r4, LSR #1 ; Divido en 2 r4 (desplazo logico )
			SUBS		r5, r5, #1
			;CMP		r5,#0
			BNE		ForOlaHumana1
			
			MOV		r4, #0xE0 ; 0000 0111
			MOV		r5, #6 ; contador
			
ForOlaHumana2
			MOV		r0, r4 ; siempre se devuelve o muestra en r0 (Concepto)
			MOV		r4, r4, LSL #1 ; Multiplico en 2 r4 (desplazo logico )
			SUBS		r5, r5, #1
			;CMP		r5,#0
			BNE		ForOlaHumana2
			BEQ		Termino
			
Termino
			LDMFD	SP!, {r4, r5, r6, r7, LR} ; recupero valores
			MOV		PC, LR
			
			
pila			FILL		40
pilaptr		DCB		1
