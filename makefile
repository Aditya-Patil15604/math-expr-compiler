exp2mc : main.c
	gcc main.c -o exp2mc

run : exp2mc
	./exp2mc

clean:
	rm exp2mc 
