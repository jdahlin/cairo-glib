#include <cairo.h>
#include <glib-object.h>

GType kairo_surface_get_type (void);
GType kairo_image_surface_get_type (void);
GType kairo_context_get_type (void);

typedef struct cairo_surface_t KairoSurface;
typedef struct cairo_image_surface_t KairoImageSurface;
typedef enum cairo_format_t KairoFormat;

KairoSurface* kairo_image_surface_get_surface (KairoImageSurface *image_surface);

KairoImageSurface* kairo_image_surface_create (KairoFormat format, int width, int height);
KairoImageSurface* kairo_image_surface_create_for_data (unsigned char* data, KairoFormat format, 
                                                        int width, int height, int stride);
int kairo_image_surface_get_height (KairoImageSurface *image_surface);
int kairo_image_surface_get_width (KairoImageSurface *image_surface);

