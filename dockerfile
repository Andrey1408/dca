FROM ubuntu:14.04

LABEL name="dc"
LABEL lab.number="1"

RUN apt-get update
RUN apt-get -y --allow-unauthenticated install clang-3.5 \
make

RUN mkdir /app
WORKDIR /app
COPY ./ /app
RUN make all