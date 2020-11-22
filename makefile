all:
	echo "run, build, clear"
run:
	./primary $(ARGS)
build:
	gcc primary.c -o primary
	gcc is_real_prime.c -o is_real_prime -lm
clear:
	rm ./primary
	rm ./is_real_prime