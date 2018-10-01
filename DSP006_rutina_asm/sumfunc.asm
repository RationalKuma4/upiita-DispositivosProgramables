				.def_sumcuartica	A4	A1	A3	num	p
_sumcuartica:	MV		A4,A1		4	4	0
				MPY		A4,A4,A3	4	4	16	4	2
				NOP		5
				MPY		A3,A4,A3	4	4	32	4	3
				NOP		5
				MPY		A3,A4,A3	4	4	128	4	4
				NOP		5
LOOP:			SUB     A1,1,A1		4	3	128	-	-
				MPY		A1,A1,A4	9	3	16	4	2
				NOP		5
				MPY		A4,A1,A4	27	4	32	4	3
				NOP		5
				MPY		A4,A1,A4	54	4	128	4	4
				NOP		5
				ADD		A4,A3,A3
		[A1]	B		LOOP
