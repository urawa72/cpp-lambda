# cpp_lambda

## Build image

```
docker build -t cpp-lambda .
```

## Build C++ code & create zip file

```
# build sample codes
docker run --rm -v $(pwd)/sample:/src cpp-lambda aws-lambda-package-sample
```
