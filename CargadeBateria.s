.text
.global entrada1
.type entrada1 function				
				MOV		SP, #pilaptr
				BL		CargadeBateria ;se va a la funcion
				end
				
CargadeBateria
				STMFD	SP!, {r4, r5, r6, LR} ; pone los registro y los actualiza
				MOV		r5, #tabla ; Inicializo los datos de la tabla
				MOV		r6, #0 ; contador
				
ForCargadeBateria
				LDRB		r4, [r5, r6] ;registra los bytes
				MOV		r0, r4 ; siempre se devuelve o muestra en r0 (Concepto)
				ADD		r6, r6, #1  ; Aumento mi contador
				CMP		r6, #9     ; Compara el contador y ve y si llego al final
				BNE		ForCargadeBateria	; si no llegue a mostrar todo repito el proceso
				BL		Termino
				
				
Termino
				LDMFD	SP!, {r4, r5, r6, LR} ; recupero valores
				MOV		PC, LR
				
				
tabla			DCB		0x0,0x80, 0xC0, 0xE0, 0xF0, 0xFC, 0xFE, 0xFF
				
				
pila				FILL		40 ; Espacio para 10 registros
pilaptr			DCB		1
