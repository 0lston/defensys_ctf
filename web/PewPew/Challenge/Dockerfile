FROM ubuntu:latest
RUN apt-get update && \
    apt-get install -y python3 python3-pip && \
    apt-get clean && \
    ln -sf /bin/bash /bin/sh

WORKDIR /app
COPY . /app
# Set file permissions for flag.txt
RUN chmod 444 /app/flag.txt
RUN pip3 install --no-cache-dir -r requirements.txt
RUN useradd ctf
USER ctf
EXPOSE 1337
SHELL ["source /bin/bash", "-c"]
ENV PATH=""
CMD ["/usr/bin/python3", "app.py"]
