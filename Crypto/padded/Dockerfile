FROM python:3.8


RUN mkdir chall

WORKDIR /chall
COPY . /chall
RUN pip3 install pycryptodome
EXPOSE 8000
RUN apt-get update && apt-get install -y socat

CMD socat TCP-LISTEN:8000,reuseaddr,fork EXEC:"python3 chall.py"
