s/CAIRO_GLIB_/CAIRO_/g
s/CairoGlibAntiAlias/cairo_anti_alias_t/g
s/CairoGlibContent/cairo_content_t/g
s/CairoGlibFillRule/cairo_fill_rule_t/g
s/CairoGlibFormat/cairo_format_t/g
s/CairoGlibLineCap/cairo_line_cap_t/g
s/CairoGlibLineJoin/cairo_line_join_t/g
s/CairoGlibOperator/cairo_operator_t/g
s/CairoGlibPattern/cairo_pattern_t/g
s/CairoGlibStatus/cairo_status_t/g

# Context
s/CairoGlibContext/cairo_t/g
s/glib:type-name=\"cairo_t\"/glib:type-name=\"CairoGLibContext\"/g
s/\"glib_context/\"cairo/g
s/cairo_get_type/cairo_glib_context_get_type/g
s/cairo_glib_context_/cairo_/g
s/cairo_get_type/cairo_glib_context_get_type/g
s/function\ name=\"cairo_create/function name=\"context_create/g

# Surface
s/CairoGlibSurface/cairo_surface_t/g
s/\"glib_surface/\"surface/g
s/cairo_surface_get_type/cairo_glib_surface_get_type/g
s/cairo_glib_surface_/cairo_surface_/g
s/glib:type-name=\"cairo_surface_t\"/glib:type-name=\"CairoGlibSurface\"/g
s/glib:get-type=\"cairo_surface_get_type\"/glib:get-type=\"cairo_glib_surface_get_type\"/g

# ImageSurface
s/CairoGlibImageSurface/cairo_image_surface_t/g
s/glib:type-name=\"cairo_image_surface_t\"/glib:type-name=\"CairoGlibImageSurface\"/g
s/\"glib_image_surface/\"image_surface/g
s/cairo_glib_image_surface/cairo_image_surface/g
s/cairo_image_surface_get_type/cairo_glib_image_surface_get_type/g
s/cairo_image_surface_get_surface/cairo_glib_image_surface_get_surface/g

# GLib API changes
s/cairo_get_status/cairo_status/g
