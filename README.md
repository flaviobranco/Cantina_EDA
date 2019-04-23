Objetivos:
O objetivo do projeto é o desenvolvimento de um programa em C++ que simule o funcionamento da “Cantina
EDA”. O sistema deverá implementar/simular todas as funcionalidades relativas ao funcionamento de uma
cantina. De uma forma sumarizada espera-se que o programa implemente funcionalidades para:
● Organização por grupos
● Fila de entrada na cantina
● Criação de refeições
● Faturação
● Movimentação de utilizadores da cantina

Descrição:
As principais entidades do programa são a fila de espera, mesa, aluno, refeição e staff.
A Fila de entrada é representada por o número de alunos presente, e pelo conjunto de alunos presentes.
A entidade mesa representa uma mesa na cantina, o tamanho da mesa varia entre os 2 e os 5 lugares, cada
mesa tem um número de alunos associado e um número de mesa. A cada inicialização do programa são
criadas um conjunto de mesas com tamanhos aleatórios até preencher a capacidade máxima da cantina.
O aluno representa um aluno da universidade, e é representado pelo primeiro e último nome, número de
aluno, número de grupo, curso e plafond. A entidade staff é identificada pelo primeiro e último nome, número
de funcionário, pelo número do departamento a que pertence e plafond.
A entidade refeição (ou menu) representa as refeições na cantina EDA cada refeição tem uma entrada, prato
principal e custo.

Funcionamento geral:
A simulação da cantina desenvolve-se por ciclos desencadeados pelo utilizador. Cada vez que o utilizador
pressionar a tecla ‘s’ + ‘enter’ um novo ciclo começa. Em cada ciclo o sistema deve (por esta ordem):
a. Remover os alunos e staff que já finalizaram a refeição
b. Cobrar a refeição a alunos e staff na saída
c. Mover alunos/staff da fila de espera para cantina (caso existam)
d. Gerar novos alunos/staff para colocar na fila
e. Na primeira iteração, deverá ser criada uma refeição. A cada 10 ciclos as refeições devem ser
alteradas e neste caso é pedido ao utilizador para introduzir os dados necessários para as novas
refeições.

Membros do projeto:
Maria Adão 2043318(Github:datworfa), 
Flávio Freitas 2048018(GitHub: ), 
Pedro Freitas 2043618(GitHub: ), 
Carlos Gomes 2044318 (GitHub:DerfStein)
