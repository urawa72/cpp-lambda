# cpp_lambda

## Build image

```
docker build -t cpp-lambda .
```

## Build C++ code & create zip file

```
docker run -it --rm -v $(pwd)/sample:/src cpp-lambda aws-lambda-package-sample
```
