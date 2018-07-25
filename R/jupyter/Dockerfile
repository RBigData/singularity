FROM r

RUN apt-get update
RUN apt-get install -y python3 python3-pip libcairo2-dev

RUN python3 -m pip install --upgrade pip
RUN python3 -m pip install numpy
RUN python3 -m pip install matplotlib
RUN python3 -m pip install pandas
RUN python3 -m pip install jupyter

RUN install.packages JuniperKernel
RUN Rscript -e "JuniperKernel::installJuniper(useJupyterDefault = TRUE)"

ENV JUPYTER_PORT=8765

RUN mkdir -p /jupyter

#CMD ["/bin/bash"]
CMD jupyter notebook --port=$JUPYTER_PORT --allow-root --no-browser --ip=0.0.0.0 --notebook-dir=/jupyter

