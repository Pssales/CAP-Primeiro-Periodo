-- 01) Em	um	modelo	relacional,	o	que	é	restrição	de	integridade	referencial?

-- 02) Indique	quais	são	as	chaves	estrangeiras	(Foreign	Keys)	do	diagrama	da	
-- Figura	1	e	quais	colunas	e	tabelas	elas	associam.	
-- 03) A	 tabela	Matricula pode	 conter	matrículas	 de	 um	mesmo	 aluno	 em	 um	
-- mesmo	curso	mais	de	uma	vez?	Por	que?

-- Sim, desde que sejam em anos diferentes, uma vez que o identificador da tabela é formado pela combinação das chaves estrangeiras Aluno_id(originária da tabela aluno) e Curso_id(originária da tabela curso) e do atributo Ano_matricula. 	

-- 04) Se	 todas	 as	 chaves	 estrangeiras	 do	 diagrama	 forem	 criadas	 com	 a	 ação	
-- “ON	DELETE	CASCADE”	e	“ON	UPDATE	CASCADE”,	o	que	acontece	se:
-- a. Eu	remover	o	curso	“XXX”	da	tabela	Curso?
-- b. Eu	alterar	o	nome	do	curso	“XXX”	para	“YYY”	na	tabela	Curso?
-- c. Eu	remover	o	aluno	“ZZZZ”	da	tabela	Aluno?
-- d. Eu	remover	a	escola	“EEEE”	da	tabela	Escola?
-- e. Eu	 alterar	 o	 ano	 de	 uma	 matricula	 (Ano_matricula)	 da	 tabela	
-- Matricula?
-- f. Eu	alterar	o	id	do	curso	de	um	aluno	(Curso_id)	da	tabela	Matricula?