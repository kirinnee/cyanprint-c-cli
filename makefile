build:
	gcc -o var__name__ main.c

run: build
	./var__name__

clean:
	rm var__name__

docker:
	docker build --load -t var__name__ .