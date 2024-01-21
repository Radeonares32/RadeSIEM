#! /bin/bash

lang=$1

protoc -I=. --${lang}_out=. network.proto

protoc -I=. --grpc_out=. --plugin=protoc-gen-grpc=/usr/bin/grpc_${lang}_plugin network.proto
