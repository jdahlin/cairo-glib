SOURCES = cairo-glib.c cairo-glib.h


all: CairoGLib.typelib CairoGLib.gir libcairo-glib.so

libcairo-glib.so: $(SOURCES)
	gcc -g -ldl -shared -o libcairo-glib.so cairo-glib.c `pkg-config --cflags --libs gobject-2.0 cairo`

CairoGLib.gir: libcairo-glib.so
	g-ir-scanner -DSCANNER --strip-prefix=Kairo -L. -n CairoGLib cairo-glib.c cairo-glib.h --library=cairo-glib --pkg glib-2.0 --pkg cairo --nsversion=1.0 > CairoGLib.gir

CairoGLib.typelib: CairoGLib.gir
	g-ir-compiler -o CairoGLib.typelib CairoGLib.gir

clean:
	rm -fr CairoGLib.gir CairoGLib.typelib libcairo-glib.so

.PHONY: libcairo-glib.so CairoGLib.gir CairoGLib.typelib
