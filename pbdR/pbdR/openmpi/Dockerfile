FROM r

ENV MAKE="make -j 16"
ENV VERSION="1.0-1"

RUN apt-get update && apt-get install -y libopenmpi-dev ssh

RUN cd /tmp \
  && wget -q https://pbdr.org/releases/pbdR_${VERSION}.tar.gz \
  && tar zxf pbdR_${VERSION}.tar.gz

RUN echo "options(repos=structure(c(CRAN='https://cran.rstudio.com/'))) ; \
  utils::rc.settings(ipck=TRUE); \
  " > /usr/local/lib/R/etc/Rprofile.site
RUN Rscript -e "install.packages('remotes')"

RUN cd /tmp/pbdR_${VERSION} && make MPI
RUN Rscript -e "remotes::install_github('wrathematics/getip')"
RUN cd /tmp/pbdR_${VERSION} && make COMM

RUN echo "options(bitmapType='cairo')" >> /usr/local/lib/R/etc/Rprofile.site

RUN rm -rf /tmp/*

CMD ["/bin/bash"]
