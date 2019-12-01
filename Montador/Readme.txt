/*###################################################################
# Universidade de Brasilia                                          #
#      Disciplina de Software Basico - Trabalho 2                   #
#                                                                   #
#           Alunos                                  Matriculas      #
#                                                                   #
#   Fernando Sobral Nobrega                         15/0034911      #
#   Matheus Bawden Silverio Castro                  15/0141017      #
#                                                                   #
#            Compilador e Sistema Operacional usados                #
#           g++ (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0               #
#                                                                   #
###################################################################*/

O trabalho foi em c++ para rodar o LINUX, Ubuntu 7.4.0-1ubuntu1~18.04.1, consiste de um Programa montador e um Programa simulador que recebem por argumento os arquivos .asm e um arquivo .obj respectivamente.
Os comandos necessários são:
g++ main.cpp Assembler.cpp TabelaDeSimbolos.cpp -o montador
./montador exemplo.asm ou ./montador exemplo1.asm exemplo2.asm
g++ ligador.cpp -o ligador
./ligador exemplo.obj ou ./ligador exemplo1.obj exemplo2.obj
g++ simulador.cpp -o simulador
./simulador ArquivoDeSaida.obj

ATENCAO O NOME DO ARGUMENTO DO SIMULADOR NAO FOI ESPECIFICADO EM ROTEIRO, COLOCAMOS 'ArquivoDeSaida.obj' !!!!!
