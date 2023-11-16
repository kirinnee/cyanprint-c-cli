FROM debian:buster

RUN apt-get update && apt-get install -y gcc

WORKDIR /app

COPY . .

RUN gcc -o var__name__ main.c

ENTRYPOINT ["./var__name__"]