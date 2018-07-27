FROM r-base

ENV VERSION="1.1.456"

RUN apt-get update && apt-get install -y gdebi-core
RUN cd /tmp \
  && wget https://download2.rstudio.org/rstudio-server-${VERSION}-amd64.deb
RUN gdebi -n /tmp/rstudio-server-${VERSION}-amd64.deb

RUN rm -rf /tmp/*

CMD ["/bin/bash"]
#CMD ["rstudio-server"]
