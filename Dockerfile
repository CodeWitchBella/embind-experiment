FROM emscripten/emsdk:3.1.31
WORKDIR /app
COPY . /app
RUN em++ -lembind -flto -s MODULARIZE=1  main.cpp  && node test.mjs
