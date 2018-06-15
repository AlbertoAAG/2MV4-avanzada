all:a.out

a.out:Main_simplex.cpp Polinomio.cpp Rac.cpp
	g++ Main_simplex.cpp Polinomio.cpp Rac.cpp

# Despu\'es podemos ver la salida del preprocesador en el archivo
# MSimplex.i, por ejemplo con: vim MSimplex.i
MSimplex.i:Main_simplex.cpp
	gcc -E Main_simplex.cpp > MSimplex.i
	@echo "Despu\'es podemos ver la salida del preprocesador en el archivo"
	@echo "MSimplex.i, por ejemplo con: vim MSimplex.i"

clean:
	rm -v a.out MSimplex.i
