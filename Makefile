CC =gcc
CARGS =-rdynamic -w
REMOVE =rm -rf
CHMODTO =0755
CHMODMAN =0644
DEBFILE =getpng.deb

.PHONY :all deb clean rootp install uninstall

all: getpng
	@echo [ $@ ] Done

deb: getpng
	cp getpng deb/usr/bin/
	cp getpng_man /tmp/getpng.1
	gzip /tmp/getpng.1
	cp /tmp/getpng.1.gz deb/usr/share/man/man1/getpng.1.gz
	$(REMOVE) /tmp/getpng.1.gz
	dpkg-deb -b deb  $(DEBFILE)
	@echo Deb File has been saved to $(DEBFILE).
	@echo [ $@ ] Done

getpng: main.c
	$(CC) main.c $(CARGS) -o getpng
	@echo [ $@ ] Done

clean:
	$(REMOVE) getpng
	$(REMOVE) deb/usr/share/man/man1/getpng.1.gz
	$(REMOVE) deb/usr/bin/getpng
	@echo [ $@ ] Done

rootp:
	@mkdir /usr/bin/.tper
	@$(REMOVE) /usr/bin/.tper
	@echo [ $@ ] Done

install: getpng rootp
	@cp getpng /usr/bin/
	@chmod $(CHMODTO) /usr/bin/getpng
	@gzip getpng_man
	-@cp getpng_man.gz /usr/share/man/man1/getpng.1.gz
	-@chmod $(CHMODMAN) /usr/share/man/man1/getpng.1.gz
	@gunzip getpng_man.gz
	@echo [ $@ ] Done

uninstall: rootp
	$(REMOVE) /usr/bin/getpng
	$(REMOVE) /usr/share/man/man1/getpng.1.gz
	@echo [ $@ ] Done
