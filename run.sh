docker build . --tag test
docker run --name test --rm -it --volume $PWD:/app test
