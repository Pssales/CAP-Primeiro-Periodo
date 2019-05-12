-- 1)	Usando os scripts SQL do arquivo “2018_lista_02_sql.sql”, crie as tabelas Instrutor, Aluno, Escola e Curso.
CREATE TABLE Instrutor ( 
    InstrutorID   	INT   			NOT NULL,
    CPF				INT				NOT NULL  UNIQUE,
    Nome  			VARCHAR( 30 )  	NOT NULL,
    Endereco   		VARCHAR( 60 ),
    CONSTRAINT InstrutorPK PRIMARY KEY (InstrutorID) 
);

CREATE TABLE Aluno ( 
    AlunoID   		INT   			NOT NULL,
    CPF				INT				NOT NULL  UNIQUE,
    Nome  			VARCHAR( 30 )  	NOT NULL,
    Endereco   		VARCHAR( 60 ),
    CONSTRAINT AlunoPK PRIMARY KEY (AlunoID) 
);

CREATE TABLE Escola ( 
    EscolaID   		INT   			NOT NULL,
    CNPJ			INT				NOT NULL  UNIQUE,
    Nome  			VARCHAR( 30 )  	NOT NULL,
    Endereco   		VARCHAR( 60 ),
    CONSTRAINT EscolaPK PRIMARY KEY (EscolaID) 
);

CREATE TABLE Curso ( 
    CursoID   		INT   			NOT NULL,
    Nome  			VARCHAR( 30 )  	NOT NULL,
    Carga_horaria	INT 			NOT NULL,
    Ementa			VARCHAR( 500 )	,
    EscolaID        INT 			NOT NULL,
    
    CONSTRAINT CursoPK PRIMARY KEY (CursoID), 
    
    CONSTRAINT CursoEscolaFK 	FOREIGN KEY (EscolaID) 
        REFERENCES Escola(EscolaID) 
        ON DELETE CASCADE 
        ON UPDATE CASCADE
);
-- 2)	Crie as tabelas Turma e Matricula. Use as ações ‘ON DELETE CASCADE’ e ‘ON UPDATE CASCADE‘ para todas as chaves estrangeiras criadas. Crie os atributos nessa ordem: 
-- (1) Turma: TurmaID, Data_inicio, Data_termino, CursoID, InstrutorID. 
CREATE TABLE Turma ( 
    TurmaID   		INT   			NOT NULL,
    Data_inicio  	DATE          	NOT NULL,
    Data_termino	DATE 			NOT NULL,
    CursoID			INT	            NOT NULL,
    InstrutorID     INT 			NOT NULL,
    
    CONSTRAINT TurmaPK PRIMARY KEY (TurmaID), 
    
    CONSTRAINT TurmaCursoFK 	FOREIGN KEY (CursoID) 
        REFERENCES Curso(CursoID) 
        ON DELETE CASCADE 
        ON UPDATE CASCADE,
    CONSTRAINT TurmaInstrutorFK 	FOREIGN KEY (InstrutorID) 
        REFERENCES Instrutor(InstrutorID) 
        ON DELETE CASCADE 
        ON UPDATE CASCADE
);

-- (2) Matricula: TurmaID, AlunoID, Nota_final, Presenca.
CREATE TABLE Matricula ( 
    TurmaID   		INT   			NOT NULL,
    AlunoID			INT	            NOT NULL,
    Nota_final      NUMERIC(4,2)    NOT NULL,
    Presenca        INT             NOT NULL,
    
    CONSTRAINT MatriculaTurmaFK 	FOREIGN KEY (TurmaID) 
        REFERENCES Turma(TurmaID) 
        ON DELETE CASCADE 
        ON UPDATE CASCADE,
    CONSTRAINT MatriculaAlunoFK 	FOREIGN KEY (AlunoID) 
        REFERENCES Aluno(AlunoID) 
        ON DELETE CASCADE 
        ON UPDATE CASCADE
);

-- 3)	Usando os scripts SQL do arquivo “2018_lista_02_sql.sql”, insira os registros da tabela Instrutor.  Ocorreu algum erro? Por que? Como resolver?

INSERT INTO Instrutor VALUES(1, 11111, 'Rodrigo Carvalho', 'Rua Alfa, num 50, Centro');
INSERT INTO Instrutor VALUES(2, 22222, 'Jacqueline França', 'Rua Sete de Setembro, num 620, Alvorada');
INSERT INTO Instrutor VALUES(3, 33333, 'Leandro Siqueira', 'Rua Nelson Davila, num 120, Centro');
INSERT INTO Instrutor VALUES(4, 33334, 'Diego Faria', 'Rua Siqueira Campos, num 80, Jd Apolo');

-- Não Ocorreu nenhum erro.


-- 4)	Usando os scripts SQL do arquivo “2018_lista_02_sql.sql”, insira os registros da tabela Aluno.  Ocorreu algum erro? Por que? Como resolver? Mostre o comando SQL para resolver o problema encontrado.

INSERT INTO Aluno VALUES(1, 12222, 'Jose Vitor Ferreira Fernandes Gomes Dias', 'Rua Alfa, num 100, Centro');
INSERT INTO Aluno VALUES(2, 32222, 'Rodrigo Gomes Dias', 'Rua Sete de Setembro, num 200, Alvorada');
INSERT INTO Aluno VALUES(3, 42222, 'Daniel Ribeiro Alvarenga', 'Rua Nelson Davila, num 150, Centro');
INSERT INTO Aluno VALUES(4, 52222, 'Gustavo Ferreira', 'Rua Lumem, num 140, Jd Apolo');
INSERT INTO Aluno VALUES(5, 62222, 'Marcelo Reis Fernandes', 'Rua Siqueira Campos, num 80, Jd Apolo');
INSERT INTO Aluno VALUES(6, 72222, 'Renata Fernandes Carvalho', 'Rua Sete de Setembro, num 620, Alvorada');
INSERT INTO Aluno VALUES(7, 82222, 'Debora Ribeiro Reis', 'Rua Lumem, num 140, Jd Apolo');
INSERT INTO Aluno VALUES(8, 92222, 'Daniela Reis Barbosa', 'Rua Nelson Davila, num 120, Centro');
INSERT INTO Aluno VALUES(9, 13333, 'Luciane Cardoso', 'Rua Siqueira Campos, num 80, Jd Apolo');
INSERT INTO Aluno VALUES(10, 91919, 'Claudio Cardoso', 'Rua Lumem, num 140, Jd Apolo');
INSERT INTO Aluno VALUES(11, 81818, 'Marina Reis Alvarenga', 'Rua Sete de Setembro, num 620, Alvorada');
INSERT INTO Aluno VALUES(12, 71717, 'Sabrina Carvalho', 'Rua Nelson Davila, num 120, Centro');
INSERT INTO Aluno VALUES(13, 61616, 'Julio Cesar Dias', 'Rua Siqueira Campos, num 80, Jd Apolo');
INSERT INTO Aluno VALUES(14, 51515, 'Regiane Limeira', 'Rua Sete de Setembro, num 620, Alvorada');
INSERT INTO Aluno VALUES(15, 41414, 'Augusto Dias Gomes', 'Rua Nelson Davila, num 120, Centro');

-- Ocorreu o erro "ERROR:  value too long for type character varying(30) SQL state: 22001" para resolver é necessário aumentar o tamanho do campo;
ALTER TABLE Aluno COLUMN nome TYPE VARCHAR(100);

-- Re-inserindo

INSERT INTO Aluno VALUES(1, 12222, 'Jose Vitor Ferreira Fernandes Gomes Dias', 'Rua Alfa, num 100, Centro');
INSERT INTO Aluno VALUES(2, 32222, 'Rodrigo Gomes Dias', 'Rua Sete de Setembro, num 200, Alvorada');
INSERT INTO Aluno VALUES(3, 42222, 'Daniel Ribeiro Alvarenga', 'Rua Nelson Davila, num 150, Centro');
INSERT INTO Aluno VALUES(4, 52222, 'Gustavo Ferreira', 'Rua Lumem, num 140, Jd Apolo');
INSERT INTO Aluno VALUES(5, 62222, 'Marcelo Reis Fernandes', 'Rua Siqueira Campos, num 80, Jd Apolo');
INSERT INTO Aluno VALUES(6, 72222, 'Renata Fernandes Carvalho', 'Rua Sete de Setembro, num 620, Alvorada');
INSERT INTO Aluno VALUES(7, 82222, 'Debora Ribeiro Reis', 'Rua Lumem, num 140, Jd Apolo');
INSERT INTO Aluno VALUES(8, 92222, 'Daniela Reis Barbosa', 'Rua Nelson Davila, num 120, Centro');
INSERT INTO Aluno VALUES(9, 13333, 'Luciane Cardoso', 'Rua Siqueira Campos, num 80, Jd Apolo');
INSERT INTO Aluno VALUES(10, 91919, 'Claudio Cardoso', 'Rua Lumem, num 140, Jd Apolo');
INSERT INTO Aluno VALUES(11, 81818, 'Marina Reis Alvarenga', 'Rua Sete de Setembro, num 620, Alvorada');
INSERT INTO Aluno VALUES(12, 71717, 'Sabrina Carvalho', 'Rua Nelson Davila, num 120, Centro');
INSERT INTO Aluno VALUES(13, 61616, 'Julio Cesar Dias', 'Rua Siqueira Campos, num 80, Jd Apolo');
INSERT INTO Aluno VALUES(14, 51515, 'Regiane Limeira', 'Rua Sete de Setembro, num 620, Alvorada');
INSERT INTO Aluno VALUES(15, 41414, 'Augusto Dias Gomes', 'Rua Nelson Davila, num 120, Centro');

-- 5)	Usando os scripts SQL do arquivo “2018_lista_02_sql.sql”, insira os registros de todas as outras tabelas.  
INSERT INTO Escola VALUES(1, 11111, 'InfoSys', 'Rua Nelson Davila, num 400, Centro');
INSERT INTO Escola VALUES(2, 22222, 'Inova', 'Rua Sete de Setembro, num 800, Alvorada');
INSERT INTO Escola VALUES(3, 33333, 'CodSys', 'Rua Alfa, num 1030, Apolo');

INSERT INTO Curso VALUES(1, 'Linux - Introduction', 120, '', 1);
INSERT INTO Curso VALUES(2, 'Linux - Advanced', 120, '', 1);
INSERT INTO Curso VALUES(3, 'Windows - Introduction', 120, '', 1);
INSERT INTO Curso VALUES(4, 'Windows - Advanced', 120, '', 1);
INSERT INTO Curso VALUES(5, 'C++ Programming Language', 240, '', 3);
INSERT INTO Curso VALUES(6, 'Java Programming Language', 240, '', 3);
INSERT INTO Curso VALUES(7, 'Python', 120, '', 3);
INSERT INTO Curso VALUES(8, 'Database System and SQL', 240, '', 2);
INSERT INTO Curso VALUES(9, 'Data Science', 240, '', 2);
INSERT INTO Curso VALUES(10, 'Geoinformatics', 240, '', 2);

INSERT INTO Turma VALUES(1, to_date('2015-02-15', 'YYYY-MM-DD'), to_date('2015-06-15', 'YYYY-MM-DD'), 1, 1);
INSERT INTO Turma VALUES(2, to_date('2015-08-15', 'YYYY-MM-DD'), to_date('2015-12-15', 'YYYY-MM-DD'), 2, 1);
INSERT INTO Turma VALUES(3, to_date('2016-02-15', 'YYYY-MM-DD'), to_date('2016-06-15', 'YYYY-MM-DD'), 1, 1);
INSERT INTO Turma VALUES(4, to_date('2016-08-15', 'YYYY-MM-DD'), to_date('2016-12-15', 'YYYY-MM-DD'), 2, 1);
INSERT INTO Turma VALUES(5, to_date('2015-02-15', 'YYYY-MM-DD'), to_date('2015-06-15', 'YYYY-MM-DD'), 3, 2);
INSERT INTO Turma VALUES(6, to_date('2015-08-15', 'YYYY-MM-DD'), to_date('2015-12-15', 'YYYY-MM-DD'), 4, 2);
INSERT INTO Turma VALUES(7, to_date('2016-02-15', 'YYYY-MM-DD'), to_date('2016-06-15', 'YYYY-MM-DD'), 3, 2);
INSERT INTO Turma VALUES(8, to_date('2016-08-15', 'YYYY-MM-DD'), to_date('2016-12-15', 'YYYY-MM-DD'), 4, 2);
INSERT INTO Turma VALUES(9, to_date('2016-02-15', 'YYYY-MM-DD'), to_date('2016-06-15', 'YYYY-MM-DD'), 7, 3);
INSERT INTO Turma VALUES(10, to_date('2016-08-15', 'YYYY-MM-DD'), to_date('2016-11-15', 'YYYY-MM-DD'), 7, 3);
INSERT INTO Turma VALUES(11, to_date('2017-02-15', 'YYYY-MM-DD'), to_date('2017-06-15', 'YYYY-MM-DD'), 7, 3);
INSERT INTO Turma VALUES(12, to_date('2016-02-15', 'YYYY-MM-DD'), to_date('2016-11-15', 'YYYY-MM-DD'), 5, 4);
INSERT INTO Turma VALUES(13, to_date('2017-02-15', 'YYYY-MM-DD'), to_date('2017-11-15', 'YYYY-MM-DD'), 5, 4);
INSERT INTO Turma VALUES(14, to_date('2016-02-15', 'YYYY-MM-DD'), to_date('2016-11-15', 'YYYY-MM-DD'), 6, 3);
INSERT INTO Turma VALUES(15, to_date('2017-02-15', 'YYYY-MM-DD'), to_date('2017-11-15', 'YYYY-MM-DD'), 6, 3);
INSERT INTO Turma VALUES(16, to_date('2015-02-15', 'YYYY-MM-DD'), to_date('2015-11-15', 'YYYY-MM-DD'), 8, 1);
INSERT INTO Turma VALUES(17, to_date('2016-02-15', 'YYYY-MM-DD'), to_date('2016-11-15', 'YYYY-MM-DD'), 8, 1);
INSERT INTO Turma VALUES(18, to_date('2015-02-15', 'YYYY-MM-DD'), to_date('2015-11-15', 'YYYY-MM-DD'), 10, 4);
INSERT INTO Turma VALUES(19, to_date('2016-02-15', 'YYYY-MM-DD'), to_date('2016-11-15', 'YYYY-MM-DD'), 10, 4);

-- TurmaID, AlunoID, Nota e Presenca
INSERT INTO Matricula VALUES(1, 1, '8.4', 80);   
INSERT INTO Matricula VALUES(1, 2, '6.4', 85);   
INSERT INTO Matricula VALUES(1, 3, '5.0', 67);   
INSERT INTO Matricula VALUES(1, 4, '9.4', 100);   
INSERT INTO Matricula VALUES(1, 5, '8.7', 100); 
  
INSERT INTO Matricula VALUES(2, 1, '7.4', 80);   
INSERT INTO Matricula VALUES(2, 2, '7.4', 85);   
INSERT INTO Matricula VALUES(2, 3, '8.0', 80);   
INSERT INTO Matricula VALUES(2, 4, '7.4', 70);   
INSERT INTO Matricula VALUES(2, 5, '9.7', 100);   

INSERT INTO Matricula VALUES(3, 6, '8.4', 80);   
INSERT INTO Matricula VALUES(3, 7, '6.4', 85);   
INSERT INTO Matricula VALUES(3, 8, '5.0', 67);   
INSERT INTO Matricula VALUES(3, 9, '9.4', 100);   
INSERT INTO Matricula VALUES(3, 10, '8.7', 100); 
  
INSERT INTO Matricula VALUES(4, 6, '7.4', 80);   
INSERT INTO Matricula VALUES(4, 7, '9.4', 85);   
INSERT INTO Matricula VALUES(4, 8, '8.0', 80);   
INSERT INTO Matricula VALUES(4, 9, '7.4', 70);   
INSERT INTO Matricula VALUES(4, 10, '9.7', 100); 

INSERT INTO Matricula VALUES(9, 11, '7.4', 80);   
INSERT INTO Matricula VALUES(9, 12, '9.4', 85);   
INSERT INTO Matricula VALUES(9, 13, '8.0', 70);  

INSERT INTO Matricula VALUES(10, 14, '7.4', 80);   
INSERT INTO Matricula VALUES(10, 15, '9.4', 85);   
INSERT INTO Matricula VALUES(10, 1, '8.0', 70);  

INSERT INTO Matricula VALUES(11, 2, '7.4', 80);   
INSERT INTO Matricula VALUES(11, 3, '9.4', 85);   
INSERT INTO Matricula VALUES(11, 4, '8.0', 70);  

-- 6)	Recupere as informações do catálogo:
-- a.	Quais esquemas existem nesse banco de dados?
    SELECT DISTINCT table_schema FROM information_schema.tables;

    --"information_schema"
    --"pg_catalog"
    --"public"

-- b.	Recupere as informações sobre as tabelas do esquema “public“.
    SELECT table_name FROM information_schema.tables WHERE table_schema = 'public';

    --"escola"
    --"curso"
    --"instrutor"
    --"turma"
    --"aluno"
    --"matricula"
-- c.	Recupere as informações sobre todas as colunas de todas as tabelas do esquema “public”.
    SELECT DISTINCT column_name FROM information_schema.columns WHERE table_schema = 'public';

--"cpf"
--"alunoid"
--"nota_final"
--"carga_horaria"
--"turmaid"
--"data_termino"
--"presenca"
--"escolaid"
--"cursoid"
--"ementa"
--"data_inicio"
--"endereco"
--"nome"
--"cnpj"
--"instrutorid"

-- d.	Recupere as informações sobre todas as restrições (constraints) de todas as tabelas do esquema “public”.
    SELECT * FROM information_schema.table_constraints WHERE table_schema = 'public';
    --A pesquisa retornou 35 resultados.

-- 7)	Selecione todos alunos ordenados pelo nome.
    SELECT * FROM Aluno ORDER BY nome;

-- 8)	Quantos cursos estão cadastrados no banco de dados?
    SELECT COUNT(*) FROM Curso; 

-- 9)	Quantos cursos foram ministrados pelo instrutor 'Leandro Siqueira'?
-- 10)	Quantas horas de curso foram ministradas pelo instrutor 'Leandro Siqueira'?
-- 11)	Quantas turmas foram ministradas por cada instrutor?  

-- 12)	Quantas horas de curso foram ministradas por cada instrutor ?
-- 13)	Se os cursos pagam 100,00 por hora ministrada, quanto cada instrutor recebeu por ano?
-- 14)	Quais instrutores deram mais que 850 horas de curso?
-- 15)	Quantas turmas cada curso teve por ano?
-- 16)	Quais cursos o aluno 'Rodrigo Gomes Dias' cursou e qual foi a nota dele em cada um?
-- 17)	Crie uma view que contenha o histórico dos alunos contendo as seguintes informações: nome do aluno, CPF do aluno, endereço do aluno, curso ministrado, data de inicio e termino do curso, nome do instrutor do curso, carga horaria, nota final, presença.
-- 18)	Insira uma nova turma na tabela Turma
-- 19)	Altere o nome do instrutor "Diego Faria" para "Diego Garcia Faria"
-- 20)	Aumente a nota de todos alunos em 10%
-- 21)	Remova o instrutor "Rodrigo Carvalho" da tabela instrutor. OBS: Observe o que acontece com as turmas associadas ao instrutor "Rodrigo Carvalho".
-- 22)	Mude o atributo "CNPJ" da tabela "Escola" para um tipo textual.
-- 23)	Renomeie o atributo "CNPJ" para "CNPJ_Escola".
-- 24)	Remova o atributo "CNPJ_Escola".
-- 25)	Remova todos os registros da tabela "Instrutor”. OBS: Observe o que acontece com os registros das tabelas que recebem o atributo "InstrutorID" como foreign key.
-- 26)	Remova o atributo "InstrutorID" da tabela "Instrutor".
-- 27)	Remova a tabela "Instrutor".
    drop table Instrutor;
-- 28)	Remova todas as tabelas do banco (esquema e conteúdo).
    drop schema public;
-- 29)	Crie novamente as tabelas do banco de dados usando os scripts acima. 
-- 30)	Adicione um atributo "valor_hora" na tabela "Curso" tipo REAL.
-- 31)	Preencha o novo atributo “valor_hora” da tabela “Curso” com o valor 50 (cada curso paga R$ 50,00 por hora ministrada).
-- 32)	Crie uma nova tabela chamada “instrutor_pagamento” que contenha os seguintes atributos:  (1) o id do instrutor ( PK - FK da tabela instrutor), (2) ano (PK - tipo INT) e (3) valor_pagamento (tipo REAL).
-- 33)	Insira na tabela "instrutor_pagamento" o valor que cada instrutor recebeu por ano.
-- 34)	Faça uma trigger que atualiza o valor do pagamento do instrutor toda vez que inserirmos uma nova turma no sistema.
-- 35)	Insira 3 turmas novas em 2018 para alguns instrutores e confira se sua trigger está funcionando e atualizando a tabela "instrutor_pagamento" corretamente.

