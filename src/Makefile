all: ../index.html ../lua.html ../assembly.html ../save.html ../random.html

../%.html: %.markdown make-html
	./make-html $< > $@
