SRCS=$(wildcard *.markdown)
DSTS=$(patsubst %.markdown,../%.html,$(SRCS))

all: $(DSTS)

clean:
	rm -f $(DSTS)

../%.html: %.markdown make-html
	./make-html $< > $@
