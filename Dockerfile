FROM debian:buster

RUN apt update && \
    apt install make g++ libgtest-dev -y

COPY . /src

CMD cd /src && make && make test && /src/tests/testMain