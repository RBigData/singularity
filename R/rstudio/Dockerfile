FROM r

ENV VERSION="1.1.456"

RUN cd /tmp \
  && wget https://download1.rstudio.org/rstudio-xenial-${VERSION}-amd64.deb

RUN apt-get update
RUN apt-get install -y libedit2 libssl-dev libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev
RUN apt-get install -y libssl1.0.2
RUN apt-get install -y libxcomposite-dev libxslt1-dev
RUN apt-get install -y libqt5core5a libqt5gui5 libqt5widgets5 libqt5network5 libqt5webkit5 libqt5printsupport5 libqt5dbus5

RUN dpkg -i /tmp/rstudio-xenial-${VERSION}-amd64.deb

#CMD ["/bin/bash"]
CMD ["rstudio"]
