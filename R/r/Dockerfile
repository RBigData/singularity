FROM r-base

RUN echo "options(repos=structure(c(CRAN='https://cran.rstudio.com/'))) ; \
  utils::rc.settings(ipck=TRUE); \
  " > /usr/local/lib/R/etc/Rprofile.site

RUN apt-get update
RUN apt-get install -y libssl-dev libxml2-dev libhdf5-dev libgit2-dev

ENV MAKE="make -j 17 -s"

RUN Rscript -e "install.packages('littler')"

RUN ln -s /usr/local/lib/R/library/littler/bin/r /usr/bin/r
RUN mkdir -p /usr/local/lib/R/site-library
ADD install.packages /usr/bin/

RUN install.packages \
  bit64 \
  csvy \
  curl \
  data.table \
  devtools \
  doParallel \
  feather \
  foreach \
  fst \
  getPass \
  hdf5r \
  jsonlite \
  knitr \
  mclust \
  memuse \
  mlbench \
  openssl \
  randomForest \
  Rcpp \
  RcppArmadillo \
  readODS \
  remotes \
  reshape2 \
  rio \
  rmarkdown \
  rmatio \
  roxygen2 \
  scales \
  testthat \
  tidyverse \
  xml2

RUN cd /tmp && wget https://github.com/jalvesaq/colorout/releases/download/v1.2-0/colorout_1.2-0.tar.gz
RUN R CMD INSTALL /tmp/colorout_1.2-0.tar.gz

RUN rm -rf /tmp/*
RUN apt-get autoclean


#CMD ["R"]
CMD ["/bin/bash"]
