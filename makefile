run: build
	./primary $(ARGS)
build: 
	gcc primary.c -o primary
	gcc is_real_prime.c -o is_real_prime -lm
clean:
	rm primary
	rm is_real_prime