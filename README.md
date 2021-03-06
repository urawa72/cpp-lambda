# cpp_lambda

## Build image

```
docker build -t cpp-lambda .
```

## Build C++ code & create zip file

```
docker run --rm -v $(pwd)/sample:/src cpp-lambda aws-lambda-package-sample
```

## Build C++ code at local.

Build aws-sdk-cpp into specified directory
```
git clone https://github.com/aws/aws-sdk-cpp.git
cd aws-sdk-cpp
mkdir build
cd build
cmake .. -DBUILD_ONLY="dynamodb" \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX=/path/to/sdk-install-dir \
  -DENABLE_TESTING=OFF \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
make -j 4
make install
```

Build C++ code
```
cd dynamodb_test
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX=/path/to/sdk-install-dir \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
make

# execute
./create_table
Table SampleTable created!
* Closing connection 0
```
