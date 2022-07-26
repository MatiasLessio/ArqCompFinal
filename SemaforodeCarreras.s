.text
.global entrada4
.type entrada4 function	
			MOV		SP, #pilaptr
			BL		Semaforo
			end
			
Semaforo
			STMFD	SP!, {r4, r5, r6, r7, LR}
			MOV		r4, #0x80 ; 1000 0000
			MOV		r5, #3 ; contador
			
ForSemaforo1
			MOV		r0, r4 ; siempre se devuelve o muestra en r0 (Concepto)
			MOV		r4, r4, LSR #2 ; Divide en 4 r4 (desplazo logico)
			ADD		r4,r4,#0x80 ;Sumo el el valor inicial
			SUBS		r5, r5, #1 ;Resto el contador
			;CMP		R5,#0
			BNE		ForSemaforo1
			
			MOV		r4, #0x80 ; 1000 0000
			MOV		r5, #8 ; contador
			
ForSemaforo2
			MOV		r0, r4 ; siempre se devuelve o muestra en r0 (Concepto)
			MOV		r4, r4, LSR #1 ; Divide en 2 r4 (desplazo logico)
			ADD		r4,r4,#0x80 ;Sumo el el valor inicial
			SUBS		r5, r5, #1 ;Resto el contador
			;CMP		R5,#0
			BNE		ForSemaforo2
			BEQ		Termino
			
			
Termino
			LDMFD	SP!, {r4, r5, r6, r7, LR} ; recupero valores
			MOV		PC, LR
			
			
pila			FILL		40
pilaptr		DCB		1
