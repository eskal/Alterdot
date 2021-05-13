FROM debian:stretch
LABEL maintainer="Bitcreds Developers <dev@bitcreds.org>"
LABEL description="Dockerised BitcredsCore, built from Travis"

RUN apt-get update && apt-get -y upgrade && apt-get clean && rm -fr /var/cache/apt/*

COPY bin/* /usr/bin/
