.text
.global entrada2
.type entrada2 function	
			MOV		SP, #pilaptr
			BL		Piedrita ;se va a la funcion
			end
			
Piedrita
			STMFD	SP!, {r4, r5, r6, LR} ; pone los registro y los actualiza
			MOV		r5, #tabla ; Inicializo los datos de la tabla
			MOV		r6, #0 ; contador
			
ForPiedrita
			LDRB		r4, [r5, r6] ;registra los bytes
			MOV		r0, r4 ; siempre se devuelve o muestra en r0 (Concepto)
			ADD		r6, r6, #1  ; Aumento mi contador
			CMP		r6, #4    ; Compara el contador y ve y si llego al final
			BNE		ForPiedrita	; si no llegue a mostrar todo repito el proceso
			BL		Termino
			
			
Termino
			LDMFD	SP!, {r4, r5, r6, LR} ; recupero valores
			MOV		PC, LR
			
			
tabla		DCB		0x80,0x20,0x08,0x02
			
			
pila			FILL		40 ; Espacio para 10 registros
pilaptr		DCB		1
