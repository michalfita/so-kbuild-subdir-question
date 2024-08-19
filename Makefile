ifneq ($(KERNELRELEASE),)
# legacy compatible kbuild part of makefile
  include Kbuild
else
# local normal makefile for external module

KERNELDIR ?= /lib/modules/$(shell uname -r)/build
BUILDDIR ?= $(shell pwd)/build
SRCDIR ?= $(shell pwd)

all default: modules
install: modules_install

modules modules_install help clean:
	$(MAKE) -C $(KERNELDIR) M=$(BUILDDIR) src=$(SRCDIR) $@

endif
