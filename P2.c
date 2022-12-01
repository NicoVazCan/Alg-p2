/*
-Diego Saavedra
-Nicolás Vázquez
-Pedro Peón
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <stdbool.h>

struct mediciones{
	double tiempo;
	double subestimada;
	double ajustada;
	double sobrestimada;
};

double microsegundos(){
/* obtiene la hora del sistema en microsegundos */
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

void inicializar_semilla(){
    srand(time(NULL));
}

void aleatorio(int v [], int n){
/* se generan números pseudoaleatorio entre -n y +n */
    int i, m=2*n+1;
    for (i=0; i < n; i++)
        v[i] = (rand() % m) - n;
}

void ascendente(int v [], int n){
    int i;
    for (i=0; i < n; i++)
        v[i] = i;
}

void descendente(int v [], int n){
	int i;

	for (i=0; i < n ; i++)
		v[i] = n-i;
}

void ord_ins(int v[], int n){
    int i, j, x;

    for (i=1; i<n; i++){
        x = v[i];
        j = i-1;
        while (j>=0 && v[j]>x){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
    }
}

void ord_shell(int v[], int n){
    int i, j, tmp, seguir, incremento = n;

    do{
        incremento = incremento/2;
        for (i = incremento; i<n; i++){
            tmp = v[i];
            j = i;
            seguir = true;
            while ( ((j-incremento) >= 0) && seguir) {
                if (tmp < v[j-incremento]){
                    v[j] = v[j-incremento];
                    j = j-incremento;
                }else seguir = false;
            }
            v[j] = tmp;
        }
    } while (incremento != 1) ;
}

void imp_vector(int v[], int n){
    int i;    

    for (i=0; i<n; i++)
        printf("%d%s", v[i], " ");
    printf("\n");
}

void comp_ordenado(int v[], int n){
    int i;
    int ordenado = true;

    for (i=0; i<n-1; i++){
        if (v[i] > v[i+1])
            ordenado = false;
    }
    printf("%s%d\n", "Ordenado? ", ordenado);
}

void cabecera_ini(void (*inicializar)(int v[], int n)){
    if (inicializar == descendente)
        printf("\n%s\n", "Inicializacion descendente");
    else if (inicializar == ascendente)
        printf("\n%s\n", "Inicializacion ascendente");
    else
        printf("\n%s\n", "Inicializacion aleatoria");
}

void cabecera_ord(void (*ordenar)(int v[], int n)){
    if (ordenar == ord_shell)
        printf("%s\n", "Ordenacion por shell");
    else if (ordenar == ord_ins)
        printf("%s\n", "Ordenacion por insercion");
}

void test(void (*inicializar)(int v[], int n),
          void (*ordenar)(int v[], int n)){
    int tam_vector = 10;
    int v[tam_vector];

    cabecera_ini(inicializar);
    inicializar(v,tam_vector);
    imp_vector(v,tam_vector);
    comp_ordenado(v,tam_vector);
    cabecera_ord(ordenar);
    ordenar(v,tam_vector);
    imp_vector(v,tam_vector);
    comp_ordenado(v,tam_vector);
}

void repetir_test(){
    test(ascendente, ord_ins);
    test(descendente, ord_ins);
    test(aleatorio, ord_ins);
    test(ascendente, ord_shell);
    test(descendente, ord_shell);
    test(aleatorio, ord_shell);
}

double medir_tiempo(int n, void (*inicializar)(int v[], int n),
                    void (*ordenar)(int v[], int n)){

    double tiempo,instante_inicial,instante_final,tiempo_ord_con_init,
           tiempo_de_init;
    int v[n], i;
    int repeticiones = 1000;
    int umbral = 500;

    inicializar(v, n);
    instante_inicial = microsegundos();
    ordenar(v, n);
    instante_final = microsegundos();
    tiempo = instante_final - instante_inicial;

    if (tiempo < umbral){
            instante_inicial = microsegundos();
            for(i=0; i < repeticiones; i++){
                inicializar(v, n);
                ordenar(v, n);
            }
            instante_final = microsegundos();
            tiempo_ord_con_init = (instante_final - instante_inicial)
                                  / repeticiones;
            instante_inicial = microsegundos();
            for(i=0; i < repeticiones; i++){
                inicializar(v, n);
            }
            instante_final = microsegundos();
            tiempo_de_init =(instante_final - instante_inicial)/repeticiones;
            tiempo = tiempo_ord_con_init - tiempo_de_init;
            printf("%s", "*");
    }
    else printf(" ");
    return tiempo;
}

struct mediciones calcular_cota(int n, void (*inicializar)(int v[], int n),
                                void (*ordenar)(int v[], int n)){
	struct mediciones cotas;
	
    cotas.tiempo = medir_tiempo(n, inicializar, ordenar);
    if (inicializar == ascendente){
        if (ordenar == ord_ins){
            cotas.subestimada = cotas.tiempo/pow(n, 0.8);
            cotas.ajustada = cotas.tiempo/n;
            cotas.sobrestimada = cotas.tiempo/pow(n, 1.1);
        }else if (ordenar == ord_shell){
            cotas.subestimada = cotas.tiempo/pow(n, 1.1);;
            cotas.ajustada = cotas.tiempo/(n*log(n));
            cotas.sobrestimada = cotas.tiempo/pow(n,1.3);
        } 
    }else if (inicializar == descendente){
        if (ordenar == ord_ins){
            cotas.subestimada = cotas.tiempo/pow(n, 1.8);
            cotas.ajustada = cotas.tiempo/pow(n, 2);
            cotas.sobrestimada = cotas.tiempo/pow(n, 2.2);
        }else if (ordenar == ord_shell){
            cotas.subestimada = cotas.tiempo/pow(n, 1.05);
            cotas.ajustada = cotas.tiempo/(n*log(n));
            cotas.sobrestimada = cotas.tiempo/pow(n,1.3);
        } 
    }else if (inicializar == aleatorio){
        if (ordenar == ord_ins){
            cotas.subestimada = cotas.tiempo/pow(n, 1.8);
            cotas.ajustada = cotas.tiempo/pow(n, 2);
            cotas.sobrestimada = cotas.tiempo/pow(n, 2.2);
        }else if (ordenar == ord_shell){
            cotas.subestimada = cotas.tiempo/pow(n, 1.1);
            cotas.ajustada = cotas.tiempo/pow(n, 1.2);
            cotas.sobrestimada = cotas.tiempo/pow(n, 1.3);
        }
    } 
    return cotas;	
}

void crear_tabla(void (*inicializar)(int v[], int n),
                 void (*ordenar)(int v[], int n)){                                
    int n=500;
    int *v, i, tiempoMax = 0;
    struct mediciones cotas;

    cabecera_ini(inicializar);
    cabecera_ord(ordenar);
    printf("%13s%15.4s%15.9s%15.9s%15.9s\n","n","T(n)","T(n)/f(n)",
            "T(n)/g(n)","T(n)/h(n)");
	for(i = 0 ; (i < 9) && tiempoMax < 1000000 ; i++){
        v=(int*)malloc(n*sizeof(int));
        cotas = calcular_cota(n, inicializar, ordenar);
        printf("%12d%15.3f%15.7f%15.7f%15.7f\n", n, cotas.tiempo,
                cotas.subestimada, cotas.ajustada, cotas.sobrestimada);
        tiempoMax = cotas.tiempo;
        n *= 2;
        free(v);
	}
}

void repetir_tablas(){
    int i;

    for(i = 0; i < 3; i++)
        crear_tabla(ascendente, ord_ins);
    for(i = 0; i < 3; i++)
        crear_tabla(descendente, ord_ins);
    for(i = 0; i < 3; i++)
        crear_tabla(aleatorio, ord_ins);
    for(i = 0; i < 3; i++)
        crear_tabla(ascendente, ord_shell);
    for(i = 0; i < 3; i++)
        crear_tabla(descendente, ord_shell);
    for(i = 0; i < 3; i++)
        crear_tabla(aleatorio, ord_shell);  
    
}

int main(){
    inicializar_semilla();
    repetir_test();
    repetir_tablas();
    return 0;
}
