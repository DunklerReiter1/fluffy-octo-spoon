#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    /*Leyendo archivo*/
    FILE *file =fopen("archivo.csv", "r");
    if (file == NULL){
        perror("No se puede abrir el archivo");
        exit(1);
    }   
    /*Longitudes de la matriz (Maximo 60 variables, 50 valores)*/ 
    int filas = 0;
    int columnas = 0;
    char line [200]; /*Longitud de caracteres */
    while (fgets(line, sizeof(line), file) != NULL) {
        filas++;
        char *token = strtok(line, ",");
        while (token != NULL) {
            columnas++;
            token = strtok(NULL, ",");
        }
    }

    // Rebobinar el archivo para volver a leer desde el principio
    rewind(file);

    // Crear una matriz dinámica del tamaño adecuado
    int **matriz = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas / filas * sizeof(int));
    }
    printf("Matriz de entrada: \n");
    // Leer los valores del archivo CSV y almacenarlos en la matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas / filas; j++) {
            fscanf(file, "%d,", &matriz[i][j]);
            printf("%d ", matriz[i][j]);
            
        }
        printf("\n"); 
        
    }
    
    


















    // Cerrar el archivo
    fclose(file);
    // Liberar la memoria de la matriz cuando hayas terminado
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}