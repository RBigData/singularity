FROM ibmcom/powerai
COPY qemu-ppc64le-static /usr/bin/qemu-ppc64le-static
USER root

RUN rm -rf /opt/anaconda2
RUN mv /opt/DL/mldl-spectrum /opt/spectrum
RUN rm -rf /opt/DL

RUN apt-get update && apt-get install -y wget build-essential gfortran
RUN apt-get autoremove
RUN apt-get autoclean

ENV SPECTRUM_PATH="/opt/spectrum"
ENV PATH="${SPECTRUM_PATH}/bin:${PATH}"
ENV LD_LIBRARY_PATH="${SPECTRUM_PATH}/lib:${LD_LIBRARY_PATH}"

RUN mkdir /opt/hello
COPY mpi-hello.c /opt/hello
RUN mpicc /opt/hello/mpi-hello.c -o /opt/hello/mpi-hello

ENV PATH="/opt/hello/:${PATH}"

CMD bash

