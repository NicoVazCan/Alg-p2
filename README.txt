Práctica 2 Algoritmos Ingeniería Informática 2020/2021

Autor:
(QUITAR LOS DEMAS NOMBRES)
-Diego Saavedra
-Nicolás Vázquez
-Pedro Peón


En este informe queda reflejado la complejidad computacional de los algoritmos
de ordenación por inserción y shell para vectores inicializadosde con un orden 
ascendente, descendente y aleatorio.
En las tablas quedan represantados el tamaño de los vectores y los tiempos de 
ejecución, asi como las cotas ajustada, subestimada y sobreestimada.
(CAMBIAR POR VUESTROS PCs)
Estos cálculos se han realizado en un hp pavilion notebook con un procesador 
Intel corei7-6700HQ, CPU con 2.6 GHz y con una Memoria Ram de 15.6Gb DDR4.

Todos los tiempos indicados en las tablas estan en microsengundos.

Todas las tablas han sido ejecutadas 3 veces y con nueve filas (salvo cuando el 
tiempo de ejecución supere los 1000000 microsegundos) para mayor precisión y con 
el objetivo de evitar el mayor número de valores anómalos.

* Estes tiempos son inferiores a 500 microsegundos por lo que entraron en un 
bucle de 1000 interacciones y se calculó su tiempo medio.
** Valores anómalos.

--------------------------------------------------------------------------------

Cotas en el algoritmo de ordenación por inserción con inicialización ascendente:
    f(n)=n^0.8	        (cota subestimada)
    g(n)=n              (cota ajustada)
    h(n)=n^1.1	        (cota sobreestimada)

Inicializacion ascendente
Ordenacion por insercion

            n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*         500          1.702      0.0070912      0.0034040      0.0018285
*        1000          3.435      0.0104212      0.0034350      0.0017216
*        2000          7.883      0.0179513      0.0039415**    0.0018431**
*        4000         15.202      0.0266441      0.0036005      0.0016582
*        8000         28.235      0.0388969      0.0035294      0.0014368
*       16000         58.187      0.0641436      0.0036367      0.0013813
*       32000        113.164      0.1013756      0.0035364      0.0012533
*       64000        224.241      0.1654504      0.0035038      0.0011586
*      128000        445.163      0.2737290      0.0034778      0.0010730

La constante a la que tiende T(n)/g(n) es: 0.0035



Cotas en el algoritmo de ordenación por inserción con inicialización descendente:
    f(n)=n^1.8          (cota subestimada)
    g(n)=n^2            (cota ajustada)
    h(n)=n^2.2          (cota sobreestimada)

Inicializacion descendente
Ordenacion por insercion
            n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*         500        323.858      0.0044896      0.0012954      0.0003738
         1000       1316.000      0.0052391      0.0013160      0.0003306
         2000       5066.000      0.0057918      0.0012665      0.0002769
         4000      22590.000      0.0074167      0.0014119      0.0002688
         8000      87439.000      0.0082441      0.0013662      0.0002264
        16000     329853.000      0.0089311      0.0012885      0.0001859
        32000    1328141.000      0.0103270      0.0012970      0.0001629

La constante a la que tiende T(n)/g(n) es: 0.0013



Cotas en el algoritmo de ordenación por inserción con inicialización aleatoria:
    f(n)=n^1.8          (cota subestimada)
    g(n)=n^2            (cota ajustada)
    h(n)=n^2.2          (cota sobreestimada)

Inicializacion aleatoria
Ordenacion por insercion
            n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*         500        177.290      0.0024578      0.0007092      0.0002046
         1000        700.000      0.0027868      0.0007000      0.0001758
         2000       2638.000      0.0030159      0.0006595      0.0001442
         4000      11697.000      0.0038403      0.0006911      0.0001392
         8000      47140.000      0.0044445      0.0006766      0.0001221
        16000     175892.000      0.0047624      0.0006871      0.0000991
        32000     680784.000      0.0052935      0.0006648      0.0000835
        64000    2714983.000      0.0060624      0.0006628      0.0000725


La constante a la que tiende T(n)/g(n) es: 0.00066



Cotas en el algoritmo de ordenación por shell con inicialización ascendente:
    f(n)=n^1.1          (cota subestimada)
    g(n)=n*log(n)       (cota ajustada)
    h(n)=n^1.3          (cota sobreestimada)

Inicializacion ascendente
Ordenacion por shell
           n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*        500         16.576      0.0331520      0.0053345      0.0014826
*       1000         36.167      0.0361670      0.0052357      0.0011437
*       2000         78.765      0.0393825      0.0051813      0.0008806
*       4000        175.853      0.0439633      0.0053006      0.0006951
*       8000        380.965      0.0476206      0.0052987      0.0005324
       16000        866.000      0.0541250      0.0055912      0.0004279
       32000       1724.000      0.0548750      0.0051935      0.0003012
       64000       3752.000      0.0586250      0.0052975      0.0002317

La constante a la que tiende T(n)/g(n) es: 0.0052



Cotas en el algoritmo de ordenación por shell con inicialización descendente:
    f(n)=n^1.05         (cota subestimada)
    g(n)=n*log(n)       (cota ajustada)
    h(n)=n^1.3          (cota sobreestimada)

Inicializacion descendente
Ordenacion por shell
            n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*         500         23.316      0.0341771      0.0075036      0.0072276
*        1000         49.689      0.0351771      0.0073932      0.0062555
*        2000        112.809      0.0385711      0.0074208      0.0057677
*        4000        245.802      0.0405903      0.0074090      0.0051040
         8000        579.000      0.0461779      0.0080531**    0.0048827
        16000       1177.000      0.0463368      0.0075992      0.0040311
        32000       2547.000      0.0473829      0.0076728      0.0035427
        64000       5399.000      0.0485092      0.0076229      0.0030499

La constante a la que tiende T(n)/g(n) es: 0.0076



Cotas en el algoritmo de ordenación por shell con inicialización aleatoria:
    f(n)=n^1.1          (cota subestimada)
    g(n)=n^1.2          (cota ajustada)
    h(n)=n^1.3          (cota sobreestimada)

Inicializacion aleatoria
Ordenacion por shell
            n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*         500         61.478      0.0660469      0.0354777      0.0190572
*        1000        141.982      0.0711596      0.0356643      0.0178745
         2000        504.000      0.1178413**    0.0551054**    0.0257686**
         4000        866.000      0.0944609      0.0412141      0.0179821
         8000       1909.000      0.0971420      0.0395456      0.0160986
        16000       3866.000      0.0983762      0.0348592      0.0132405
        32000       8902.000      0.0985877      0.0349388      0.0123821
        64000      20098.000      0.1038377      0.0343350      0.0113532
       128000      46214.000      0.1113891      0.0343654      0.0106023

La constante a la que tiende T(n)/g(n) es: 0.0343


--------------------------------------------------------------------------------

Concluímos que, aunque para el mejor caso (el vector ordenado ascendente), el
algoritmo de inserción es mejor, con una complejidad de n, para el resto de 
casos esto no es así, teniendo para estos una complejidad de n^2, ya que para
todos los casos el algoritmo de ordenación por shell es más eficiente con una 
complejidad de n*log(n) para vectores ordenados de forma ascendente y descendente
y una complejidad de n^1.2 para vectores aleatorios, aunque nos resulta extraño
porque creemos que debería tener la misma complejidad para todos los casos, lo
hemos ejecutado varias veces con ambas complejidades y, finalmente, hemos decidido
dejar esta última porque es la que nos da la cota más ajustada. En vistas al 
código, aunque la ordenación por inserción es mucho más simple, los resultados,
exceptuando el caso en el que el vector es ascendiente, como ya hemos dicho, este
algoritmo es mucho menos eficiente, por lo que creemos que vale la pena el trabajo
de desarrollar el código de la ordenación por shell ya que conseguiremos tiempos
de ejecución mucho más óptimos para la mayoría de casos.
