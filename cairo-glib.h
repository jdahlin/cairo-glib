#include <cairo.h>
#include <glib-object.h>

GType cairo_glib_surface_get_type (void);
GType cairo_glib_image_surface_get_type (void);
GType cairo_glib_context_get_type (void);
GType cairo_glib_matrix_get_type (void);
GType cairo_glib_font_face_get_type (void);
GType cairo_glib_scaled_font_get_type (void);
GType cairo_glib_font_options_get_type (void);

typedef struct cairo_surface_t CairoGlibSurface;
typedef struct cairo_image_surface_t CairoGlibImageSurface;
typedef enum cairo_format_t CairoGlibFormat;

CairoGlibSurface* cairo_glib_image_surface_get_surface (CairoGlibImageSurface *image_surface);

CairoGlibImageSurface* cairo_glib_image_surface_create (CairoGlibFormat format, int width, int height);
CairoGlibImageSurface* cairo_glib_image_surface_create_for_data (unsigned char* data, CairoGlibFormat format, 
                                                                 int width, int height, int stride);
int cairo_glib_image_surface_get_height (CairoGlibImageSurface *image_surface);
int cairo_glib_image_surface_get_width (CairoGlibImageSurface *image_surface);

