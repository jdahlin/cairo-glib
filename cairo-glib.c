#include "cairo-glib.h"

#define _DEFINE_BOXED_TYPE(cname, name, copyfunc, freefunc) \
GType \
cairo_glib_##cname##_get_type (void) \
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

_DEFINE_BOXED_TYPE(surface, "CairoGlibSurface", cairo_surface_reference, cairo_surface_destroy)
         
_DEFINE_BOXED_TYPE(image_surface, "CairoGlibImageSurface", cairo_surface_reference, cairo_surface_destroy)

CairoGlibSurface* 
cairo_glib_image_surface_get_surface (CairoGlibImageSurface *image_surface)
{
    return (CairoGlibSurface*)image_surface;
}

_DEFINE_BOXED_TYPE(context, "CairoGlibContext", cairo_reference, cairo_destroy)

