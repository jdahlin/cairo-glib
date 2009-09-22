#include "cairo-glib.h"

#define _DEFINE_BOXED_TYPE(cname, name, copyfunc, freefunc) \
GType \
kairo_##cname##_get_type (void) \
{ \
	static volatile gsize type_volatile = 0; \
\
	if (g_once_init_enter (&type_volatile)) { \
		GType type = g_boxed_type_register_static ( \
			g_intern_static_string (name), \
			(GBoxedCopyFunc) copyfunc, \
			(GBoxedFreeFunc) freefunc); \
		g_once_init_leave (&type_volatile, type); \
	} \
   return type_volatile; \
}

_DEFINE_BOXED_TYPE(surface, "KairoSurface", cairo_surface_reference, cairo_surface_destroy)
         
_DEFINE_BOXED_TYPE(image_surface, "KairoImageSurface", cairo_surface_reference, cairo_surface_destroy)

cairo_surface_t *
cairo_glib_image_surface_get_surface(cairo_surface_t *image_surface)
{
    return image_surface;
}

_DEFINE_BOXED_TYPE(context, "KairoContext", cairo_reference, cairo_destroy)

