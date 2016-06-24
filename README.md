# Projeto 3: Multicore e aceleração em Hardware.

##Membros do grupo:
###RA: &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; Alunos:
###&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;145539 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; Bruno Takeshi Hori
###&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;145574 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; Caio Vinícius Piologo Veras Fernandes
###&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;148914 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; Pedro Elias Lucas Ramos Meireles
###&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;150547 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; André Tsuyoshi Sakiyama
###&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;987654 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; Titouan Thibaud


###Software Usado: Problema do ProjectEuler.net de divisão de pares, adaptado (adaptações descritas em Blocos/Funções a Otimizar):

 [**Divisor Pairs**] (https://projecteuler.net/problem=561)

###Blocos/Funções a otimizar:

O problema se divide em 4 funções principais.

1. Calcular todos os divisores de n, e dividí-los em pares (a,b) tal que a divide b e retorna o tamanho do conjunto S(n).
2. Calcular o **somatório** dos m primeiros primos pm.
3. Calcular o maior inteiro E(m,n) = k tal que 2^k divide S(pm^n).
4. Calcular o somatório de E(m,i) de 1 até n, através da função Q(n), **sendo m = XX.**

###Problemas enfrentados na implementação do problema original:

Dado o enunciado original descrito no link acima, percebe-se que foram feitas mudanças no bloco 2 (de um produtório, foi adaptado a um somatorio)
e 4 (Não se calcula o Q(n) empregando o primeiro valor de E(m,n) para m = 904961.)
Os problemas se devem ao fato de que:

*O produtório dos primeiros 15 primos bastam para estourar o valor do inteiro.*

Para tentar mudar essa condição, tentamos gerar as seguintes mudanças no programa, sem exito:

* **Decompor os números primos em seus fatores, e dado um número fatorado, encontrar um padrão para definir
 o número de pares de divisores de S(n)**. Desta maneira, seria possivel trabalhar com números que extrapolam os limites numéricos de um 
 inteiro, sem necessariamente computar o produtório dos n primeiros primos. No entanto, não conseguimos determinar, nem localizar,
 um padrão matemático para gerar essa implementação, e abonamos a ideia.
 
 Por conta disso, achamos pertinente reformular o problema para ao invés de calcular o produtório dos n primeiros primos, substituir a 
 formula para o somatório dos n primeiros primos.
 
 Usar um double ao invés de um inteiro também causa a extrapolação dos produtorios, o que faz com que não insistissemos na ideia. 
 

###Ganho de desempenho:

O ganho de desempenho ocorre através de duas maneiras:

####1. Acelerador:

O acelerador implementado é um registro dos primeiros 10000 números primos que estão armazenados em um vetor no periférico do simulador 
do archC. Por conta dessa modificação do problema, não é mais necessário computar se um número é primo ou não o tempo todo, e o programa
é executado mais rapidamente através dessa mudança. 

####2. Paralelismo:

Avaliando as principais funçoes do programa, as funções que são paralelizáveis são:
* S: S(n) corresponde a soma do número de termos do conjunto o qual possui os pares (a,b) tal que a divide b e b divide n. A função pode ser paralelizável, por conta de que é possivel dividir o intervalo (1, n) pelo número de processadores empregado no nosso programa (no nosso caso, aplicaremos a paralelização empregando 4 processadores mips), e desta maneira, cada processador calcula um subconjunto dos divisores de n. 

Não foi paralelizada as outras funções pois elas possuem um segmento linear em relação as demais.

###Experimentos:

De acordo com o ProjectEuler.net, o experimento principal sugerido é o cálculo de Q(10^12). Porém como não é sabido que a memória estabelecida seja suficiente para tal número faremos em relação a números menores.

Dessa forma, serão realizados três experimentos:

- Um executado sem paralelismo e aceleração      : 
- Um executado com paralelismo e sem aceleração  : **148975814** instruções.
- Um executado com paralelismo e com aceleração  : **148948232** instruções.
