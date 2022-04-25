build mandelbrot.o:
	gcc $^ -o $@

clean:
	rm -f *.o build

run:
	./build

.PHONY: clean