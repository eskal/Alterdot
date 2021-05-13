#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR/..

DOCKER_IMAGE=${DOCKER_IMAGE:-dashpay/bitcredsd-develop}
DOCKER_TAG=${DOCKER_TAG:-latest}

BUILD_DIR=${BUILD_DIR:-.}

rm docker/bin/*
mkdir docker/bin
cp $BUILD_DIR/src/bitcredsd docker/bin/
cp $BUILD_DIR/src/bitcreds-cli docker/bin/
cp $BUILD_DIR/src/bitcreds-tx docker/bin/
strip docker/bin/bitcredsd
strip docker/bin/bitcreds-cli
strip docker/bin/bitcreds-tx

docker build --pull -t $DOCKER_IMAGE:$DOCKER_TAG -f docker/Dockerfile docker
