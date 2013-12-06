Macaco-Louco
============

Memória de dados = Matriz de 32 linhas e 16 colunas.

Memória de instruções = Matriz de 32 linhas e 18 colunas.

TABELA DE OPCODE:
	   [2] [1] [0]
ADD  - 	0 	0 	0
SUB  - 	0   0   1
AND  -	0   1   0
OR   - 	0   1   1
LWI  - 	1   0   0
BNE  -	1   0   1
J    - 	1   1   0
JR   - 	1   1   1

FORMATO DAS INSTRUÇÕES;

ADD M0 M1 M2 - M0 = M1 + M2
AND M0 M1 M2 - M0 = M1 & M2
SUB M0 M1 M2 - M0 = M1 - M2
OR M0 M1 M2 - M0 = M1 | M2

LWI M0 100 - Carrega em M0 a constante 100

BNE M0 M1 LABEL - Faz PC = LABEL se M0 != M1

J 100 - Faz PC = 100

JR M0 - Faz PC = M0