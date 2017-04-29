#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>

void *hiloPadre (void *arg);	// Prototipo de la función del hilo padre
void *hiloHijo (void *arg);	// Prototipo de la función del hilo hijo
void *hiloFinal (void *arg);	// Prototipo de la función del hilo final

int
main (void)
{
  pthread_t idHilo[15];    // Arreglo de identificadores de Hilos
  int idProc;			// Variable de identificador de proceso
  int status;			// Argumento para wait()
  idProc = fork ();		// Creamos un proceso
  if (idProc == 0)		// Si se creo con éxito el proceso
    {
        for (int i = 0; i < 15; i++)
      {
        pthread_create (&idHilo[i], NULL, hiloPadre, NULL);	// Se crean los hilos
        printf ("Soy el hilo padre: %d y mi id es: %lu\n", i + 1, idHilo[i]);	// Impresión de los datos del hilo
      }
      for (int i = 0; i < 15; i++)
      {
        pthread_join (idHilo[i], NULL);	// Se espera a que concluya la ejecución de los hilos
      }
    }
  else
    {
      wait (&status);		// El proceso padre espera a que su hijo termine
    }

  return 0;
}

void *
hiloPadre (void *arg)
{
  pthread_t idHilo[10];		// Creamos un arreglo de identificadores para cada hilo a crear
  for (int i = 0; i < 10; i++)
    {
      pthread_create (&idHilo[i], NULL, hiloHijo, NULL);	// Se crean los hilos
      printf ("Soy el hilo hijo: %d y mi id es: %lu\n", i + 1, idHilo[i]);	// Impresión de los datos del hilo
    }
  for (int i = 0; i < 10; i++)
    {
      pthread_join (idHilo[i], NULL);	// Se espera a que concluya la ejecución de los hilos
    }
  return NULL;
}

void *
hiloHijo (void *arg)
{
  pthread_t idHilo[5];		// Creamos un arreglo de identificadores para cada hilo a crear
  for (int i = 0; i < 5; i++)
    {
      pthread_create (&idHilo[i], NULL, hiloFinal, NULL);	// Se crean los hilos
      printf ("Soy el hilo nieto %d y mi id es: %lu\n", i + 1, idHilo[i]);	// Impresión de los datos del hilo
    }
  for (int i = 0; i < 5; i++)
    {
      pthread_join (idHilo[i], NULL);	// Se espera a que concluya la ejecución de los hilos
    }
  return NULL;
}

void *
hiloFinal (void *arg)
{
  printf ("Practica 5\n");	// Impersión del mensaje del los hilos hoja del árbol de hilos
  return NULL;
}
