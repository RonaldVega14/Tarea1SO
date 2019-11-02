// C program to illustrate factorial calculation 
// using fork() in C for Linux 
#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/types.h>  
#include <string.h> 
#include <stdlib.h>  
#include <sys/ipc.h>  
#include <sys/shm.h> 

int main(int argc , char *argv[] ){ 

	//Declaracion de variables para las pipes
	int fd1[2];  // Used to store two ends of first pipe 
    	int fd2[2];  // Used to store two ends of second pipe 

	int resultado = 1;
	//Verificando que se crean las pipes
	if (pipe(fd1)==-1){ 
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	} 
	if (pipe(fd2)==-1){ 
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	} 

	//Declaracion de variables generales	
	pid_t pid;
	int n; 
	
	//Verificando la cantidad de argumentos
	if (argc != 2) { 
		printf("arg missing or exceeding\n"); 
		exit(0); 
	} 

	// Verificamos que el numero sea mayor a 0 
	if ( atoi ( argv[1] ) <0 ){ 
		printf("negative number entered %d\n", atoi(argv[1])); 
		exit(0); 
	} 

	// Convertimos el valor a entero y lo guardamos en n 
	n = atoi(argv[1]);
	
	
	//Creamos procesos 
	for(int i=0;i<n;i++){ // loop will run n times (n=5) 
        	if(fork() == 0){ 
            		printf("SOY EL PROCESO HIJO NUMERO: %d\n", n);
            		exit(0); 
        	} 
    	} 
	for(int i=0;i<5;i++){
	    wait(NULL);
	} // loop will run n times (n=5) 
		 	

	 return 0;
} 
