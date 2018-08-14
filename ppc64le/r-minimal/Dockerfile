FROM ppc64le/ubuntu:16.04
COPY qemu-ppc64le-static /usr/bin/qemu-ppc64le-static

ENV MAKE="make -j 5"
ENV VERSION="3.5.1"

RUN apt-get update && apt-get install -y wget libopenblas-dev build-essential gfortran libreadline-dev libbz2-dev zlib1g-dev libpng-dev libjpeg-dev liblzma-dev libpcre3-dev libcurl4-openssl-dev



RUN cd /tmp \
  && wget https://cran.r-project.org/src/base/R-3/R-${VERSION}.tar.gz \
  && tar zxf R-${VERSION}.tar.gz

RUN apt-get install -y libcairo2-dev
RUN cd /tmp/R-${VERSION} \
  && ./configure --with-cairo=yes --with-x=no --enable-R-shlib=yes --enable-memory-profiling=no --with-blas="-lopenblas" --with-lapack \
  && make && make install

RUN echo "options(bitmapType='cairo')" >> /usr/local/lib/R/etc/Rprofile.site

RUN rm -rf /tmp/*
RUN apt-get autoclean

CMD R --no-save --quiet --no-restore

