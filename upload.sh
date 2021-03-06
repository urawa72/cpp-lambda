#!/usr/bin/env bash

arn=$(aws iam get-role --role-name lambda-cpp-sample --query 'Role.Arn' | xargs -I{} echo {})

aws lambda create-function --function-name $1 \
  --role $arn \
  --runtime provided.al2 --timeout 15 --memory-size 128 \
  --handler $1 --zip-file fileb://$1.zip
