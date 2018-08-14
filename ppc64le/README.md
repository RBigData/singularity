To build ppc64le images on x86:

1. First run this on the builder machine:

```
docker run --rm --privileged multiarch/qemu-user-static:register
```

2. On the builder machine, download the ppc64le qemu static binary:

```
wget https://github.com/multiarch/qemu-user-static/releases/download/v2.7.0/qemu-ppc64le-static.tar.gz
tar zxf qemu-ppc64le-static.tar.gz
```

3. Put `qemu-ppc64le-static` in the directory containing the Dockerfile, and make sure you have a line in the Dockerfile near the top like this:

```
COPY qemu-ppc64le-static /usr/bin/qemu-ppc64le-static
```

4. Build the docker image

5. Use [docker2singularity](https://github.com/singularityhub/docker/tree/master/docker2singularity)
