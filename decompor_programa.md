-Refeição
-Dimensão de cantina(quantidade)
-Mesa(n da mesa, quantidade/mesa, as pessoas dentro (Pessoas)
-Pessoas(Nome, estudante/staff, curso(aluno)/Departamento(staff),Grupo(aluno),N_unico(5 para aluno e 4 para staff))
-Fila de espera(Pessoas)


Início:
->De forma a facilitar o funcionamento do programa, assumimos que antes de qualquer aluno/staff entrar na cantina a fila está completa.



Função geral
->Ciclos:
*avançam com seguinte por 1 (usando 's'+'enter');
*Cada 10: mudar refeição;
->Remover pessoas que acabaram a refeição (ciclos restantes:0),
->Cobrar a refeição a alunos e staff(plafont):
(Caso um indivíduo não tenha plafond suficiente para pagar a refeição:
-Deverá ser removido antes de entrar na cantina(remover da fila de espera,pode-se remover apenas o aluno ou o grupo inteiro);
-Devem ser guardados no programa;
-1ªentrega: máximo de 100 elementos;);
->Mover alunos/staff da fila de espera para cantina (caso existam);
->Gerar novos alunos/staff para colocar na fila;

