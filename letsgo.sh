#!/bin/sh

cd binary_tree && gcc main.c ../libs/tiempo.c
echo "Iniciando Ordenamiento con arbol binario de busqueda..."
./a.out 10000000 < "../nums.txt" > "../results/binary_tree.txt"
echo "Finalizo Ordenamiento con arbol binario de busqueda | Regresando a carpeta de algoritmos"
cd ..

cd shell_sort && gcc main.c ../libs/tiempo.c
echo "Iniciando Shell sort..."
./a.out 10000000 < "../nums.txt" > "../results/shell_sort.txt"
echo "Finalizo shell sort | Regresando a carpeta de algoritmos"
cd ..

cd bubble_sort && gcc main.c ../libs/tiempo.c
echo "Iniciando Bubble Sort..."
./a.out 200000 < "../nums.txt" > "../results/bubble_sort.txt"
echo "Finalizo Bubble Sort | Regresando a carpeta de algoritmos"
cd ..

cd improved_bubble && gcc main.c ../libs/tiempo.c
echo "Iniciando Burbuuja mejorada..."
./a.out 200000 < "../nums.txt" > "../results/improved_bubble.txt"
echo "Finalizo Burbuja mejorada | Regresando a carpeta de algoritmos"
cd ..

cd insertion_sort && gcc main.c ../libs/tiempo.c
echo "Iniciando Insertion Sort..."
./a.out 200000 < "../nums.txt" > "../results/insertion_sort.txt"
echo "Finalizo Insertion Sort | Regresando a carpeta de algoritmos"
cd ..


cd selection_sort && gcc main.c ../libs/tiempo.c
echo "Iniciando Selection Sort..."
./a.out 200000 < "../nums.txt" > "../results/selection_sort.txt"
echo "Finalizo Selection Sort | Regresando a carpeta de algoritmos"
cd ..
