FROM ibmcom/powerai
COPY qemu-ppc64le-static /usr/bin/qemu-ppc64le-static
USER root

RUN rm -rf /opt/anaconda2
RUN mv /opt/DL/mldl-spectrum /opt/spectrum
RUN rm -rf /opt/DL

RUN apt-get update && apt-get install -y wget build-essential gfortran
RUN apt-get autoremove
RUN apt-get autoclean

CMD bash
