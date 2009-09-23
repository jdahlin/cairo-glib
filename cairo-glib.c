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

_DEFINE_BOXED_TYPE(font_face, "CairoGlibFontFace", cairo_font_face_reference, cairo_font_face_destroy)

_DEFINE_BOXED_TYPE(scaled_font, "CairoGlibScaledFont", cairo_scaled_font_reference, cairo_scaled_font_destroy)

_DEFINE_BOXED_TYPE(font_options, "CairoGlibFontOptions", cairo_font_options_copy, cairo_font_options_destroy)

static cairo_matrix_t *
cairo_glib_matrix_copy(cairo_matrix_t *matrix)
{
   return g_memdup(matrix, sizeof(cairo_matrix_t));
}

static void
cairo_glib_matrix_free(cairo_matrix_t *matrix)
{
   g_free(matrix);
}

_DEFINE_BOXED_TYPE(matrix, "CairoGlibMatrix", cairo_glib_matrix_copy, cairo_glib_matrix_free)

static cairo_path_t *
cairo_glib_path_copy(cairo_path_t *path)
{
   return g_memdup(path, sizeof(cairo_path_t));
}

static void
cairo_glib_path_free(cairo_path_t *path)
{
   g_free(path);
}

_DEFINE_BOXED_TYPE(path	, "CairoGlibPath", cairo_glib_path_copy, cairo_glib_path_free)

