FROM ubuntu:20.04
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y git cmake make g++ libcurl4-openssl-dev zip

WORKDIR /tmp
RUN git clone https://github.com/awslabs/aws-lambda-cpp-runtime.git && \
  cd aws-lambda-cpp-runtime && \
  mkdir build && \
  cd build && \
  cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=~/lambda-install && \
  make && make install

COPY ./run.sh /usr/local/bin/run.sh
RUN chmod +x /usr/local/bin/run.sh

WORKDIR /src
ENTRYPOINT ["run.sh"]
