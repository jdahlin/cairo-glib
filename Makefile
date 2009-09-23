SOURCES = cairo-glib.c cairo-glib.h

CAIRO_INCLUDEDIR=`pkg-config --variable=includedir cairo`/cairo

all: cairo-1.0.typelib cairo-1.0.gir libcairo-glib.so

libcairo-glib.so: $(SOURCES)
	gcc -g -shared -o libcairo-glib.so cairo-glib.c `pkg-config --cflags --libs gobject-2.0 cairo`

cairo.h:
	cat $(CAIRO_INCLUDEDIR)/cairo.h  | sed -r -f cairo.h.sed > cairo.h

cairo-1.0.gir: libcairo-glib.so cairo.h
	g-ir-scanner --strip-prefix=CairoGlib \
		-L. -n cairo \
		cairo.h cairo-glib.c cairo-glib.h \
		--library=cairo \
		--library=cairo-glib \
		--pkg glib-2.0 \
		--pkg cairo \
		--nsversion=1.0 | sed -r -f cairo-1.0.gir.sed > cairo-1.0.gir

cairo-1.0.typelib: cairo-1.0.gir
	g-ir-compiler -o cairo-1.0.typelib cairo-1.0.gir

clean:
	rm -fr cairo-1.0.gir cairo-1.0.typelib libcairo-glib.so

.PHONY: libcairo-glib.so cairo-1.0.gir cairo-1.0.typelib cairo.h test.png cairo.h
