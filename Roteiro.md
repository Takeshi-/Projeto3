MC723 - Laboratório de Projetos de Sistemas Computacionais
====
###### Campinas, 10 de junho de 2016
#### Professor: Lucas Wanner
#### RA: &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; Alunos:
#### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;145539 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; Bruno Takeshi Hori
#### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;145574 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; Caio Vinícius Piologo Veras Fernandes
#### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;148914 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; Pedro Elias Lucas Ramos Meireles
#### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;150547 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; André Tsuyoshi Sakiyama

Projeto 3 - Multicore e Aceleração em Hardware
====

### Software Usado: Problema do ProjectEuler.net de divisão de pares

 [**Divisor Pairs**] (https://projecteuler.net/problem=561)

### Blocos/Funções a otimizar:

O problema se divide em 4 funções principais.

1. Calcular todos os divisores de n, e dividí-los em pares (a,b) tal que a divide b e retorna o tamanho do conjunto S(n).
2. Calcular o produto dos m primeiros primos pm.
3. Calcular o maior inteiro E(m,n) = k tal que 2^k divide S(pm^n).
4. Calcular o somatório de E(904961,i) de 1 até n, Q(n).

### Ganho de desempenho:

Em tese, as funções são todas paralelizáveis, ou seja, cada parte pode ser dividida pelo número de cores estabelecidos. Porém como cada bloco necessita que o bloco anterior esteja finalizado por todos os processadores, o ganho dependerá da otimização de cada bloco.

### Experimentos:

De acordo com o ProjectEuler.net, o experimento principal sugerido é o cálculo de Q(10^12). Porém como não é sabido que a memória estabelecida seja suficiente para tal número faremos em relação a números menores.

Dessa forma, serão realizados três experimentos:

- Um executado sem paralelismo e aceleração
- Um executado com paralelismo e sem aceleração
- Um executado com paralelismo e com aceleração

### Aceleração:

Iremos acelerar o cálculo dos m primeiros primos ao calcular uma tabela previamente em hardware.
