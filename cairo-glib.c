#include <dlfcn.h>
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

#define WRAP1(alias,symbol,retval,p1,c1) \
retval alias(p1 arg1) \
{ return (retval)symbol((c1)arg1); }

#define WRAP2(alias,symbol,retval,p1,c1,p2,c2) \
retval alias(p1 arg1, p2 arg2) \
{ return (retval)symbol((c1)arg1,(c2)arg2); }

#define WRAP3(alias,symbol,retval,p1,c1,p2,c2,p3,c3) \
retval alias(p1 arg1, p2 arg2, p3 arg3) \
{ return (retval)symbol((c1)arg1,(c2)arg2,(c3)arg3); }

#define WRAP4(alias,symbol,retval,p1,c1,p2,c2,p3,c3,p4,c4) \
retval alias(p1 arg1, p2 arg2, p3 arg3, p4 arg4) \
{ return (retval)symbol((c1)arg1,(c2)arg2,(c3)arg3,(c4)arg4); }

#define WRAP5(alias,symbol,retval,p1,c1,p2,c2,p3,c3,p4,c4,p5,c5) \
retval alias(p1 arg1, p2 arg2, p3 arg3, p4 arg4, p5 arg5) \
{ return (retval)symbol((c1)arg1,(c2)arg2,(c3)arg3,(c4)arg4,(c5)arg5); }

#define WRAP6(alias,symbol,retval,p1,c1,p2,c2,p3,c3,p4,c4,p5,c5,p6,c6) \
retval alias(p1 arg1, p2 arg2, p3 arg3, p4 arg4, p5 arg5, p6 arg6) \
{ return (retval)symbol((c1)arg1,(c2)arg2,(c3)arg3,(c4)arg4,(c5)arg5,(c6)arg6); }

/* Surface */
_DEFINE_BOXED_TYPE(surface, "KairoSurface", cairo_surface_reference, cairo_surface_destroy)
WRAP1(kairo_surface_get_surface_type, cairo_surface_get_type, 
    KairoSurfaceType, KairoSurface*, cairo_surface_t*) 
WRAP1(kairo_surface_get_status, cairo_surface_status, 
    KairoStatus, KairoSurface*, cairo_surface_t*)
WRAP2(kairo_surface_write_to_png, cairo_surface_write_to_png, 
    KairoStatus, KairoSurface*, cairo_surface_t*, const char *, const char*)
         
/* ImageSurface */
_DEFINE_BOXED_TYPE(image_surface, "KairoImageSurface", cairo_surface_reference, cairo_surface_destroy)
WRAP3(kairo_image_surface_new, cairo_image_surface_create,
    KairoImageSurface*, KairoFormat, cairo_format_t, int, int, int, int)
WRAP3(kairo_image_surface_create, cairo_image_surface_create, // FIXME: Remove, GJS is broken.
    KairoImageSurface*, KairoFormat, cairo_format_t, int, int, int, int)
WRAP1(kairo_image_surface_get_width, cairo_image_surface_get_width, 
    int, KairoImageSurface*, cairo_surface_t*) 
WRAP1(kairo_image_surface_get_height, cairo_image_surface_get_height, 
    int, KairoImageSurface*, cairo_surface_t*) 

KairoSurface *
kairo_image_surface_get_surface(KairoImageSurface *image_surface)
{
    return (KairoSurface*)image_surface;
}

/* Context */
_DEFINE_BOXED_TYPE(context, "KairoContext", cairo_reference, cairo_destroy)
WRAP1(kairo_context_new, cairo_create, 
    KairoContext*, KairoSurface*, cairo_surface_t*) 
WRAP1(kairo_context_create, cairo_create, // FIXME: Remove, GJS is broken.
    KairoContext*, KairoSurface*, cairo_surface_t*) 
WRAP1(kairo_context_get_status, cairo_status, 
    KairoStatus, KairoContext*, cairo_t*)
WRAP1(kairo_context_save, cairo_save, 
    void, KairoContext*, cairo_t*)
WRAP1(kairo_context_restore, cairo_restore, 
    void, KairoContext*, cairo_t*)
WRAP1(kairo_context_get_target, cairo_get_target, 
    KairoSurface*, KairoContext*, cairo_t*)
WRAP1(kairo_context_push_group, cairo_push_group, 
    void, KairoContext*, cairo_t*)
WRAP2(kairo_context_push_group_with_content, cairo_push_group_with_content, 
    void, KairoContext*, cairo_t*, KairoContent, cairo_content_t)
WRAP1(kairo_context_pop_group, cairo_pop_group, 
    KairoPattern*, KairoContext*, cairo_t*)
WRAP1(kairo_context_pop_group_to_source, cairo_pop_group_to_source, 
    void, KairoContext*, cairo_t*)
WRAP1(kairo_context_get_group_target, cairo_get_group_target, 
    KairoSurface*, KairoContext*, cairo_t*)
WRAP4(kairo_context_set_source_rgb, cairo_set_source_rgb, 
    void, KairoContext*, cairo_t*, double, double, double, double, double, double) 
WRAP5(kairo_context_set_source_rgba, cairo_set_source_rgba, 
    void, KairoContext*, cairo_t*, double, double, double, double, double, double, double, double) 
WRAP2(kairo_context_set_source, cairo_set_source, 
    void, KairoContext*, cairo_t*, KairoPattern*, cairo_pattern_t*) 
WRAP4(kairo_context_set_source_surface, cairo_set_source_surface, 
    void, KairoContext*, cairo_t*, KairoSurface*, cairo_surface_t*, double, double, double, double) 
WRAP1(kairo_context_get_source, cairo_get_source, 
    KairoPattern*, KairoContext*, cairo_t*)
    
WRAP2(kairo_context_set_fill_rule, cairo_set_fill_rule, 
    void, KairoContext*, cairo_t*, KairoFillRule, cairo_fill_rule_t)
WRAP1(kairo_context_get_fill_rule, cairo_get_fill_rule, 
    KairoFillRule, KairoContext*, cairo_t*)
    
WRAP2(kairo_context_set_line_cap, cairo_set_line_cap, 
    void, KairoContext*, cairo_t*, KairoLineCap, cairo_line_cap_t)
WRAP1(kairo_context_get_line_cap, cairo_get_line_cap, 
    KairoLineCap, KairoContext*, cairo_t*)

WRAP2(kairo_context_set_line_join, cairo_set_line_join, 
    void, KairoContext*, cairo_t*, KairoLineJoin, cairo_line_join_t)
WRAP1(kairo_context_get_line_join, cairo_get_line_join, 
    KairoLineJoin, KairoContext*, cairo_t*)
    
WRAP2(kairo_context_set_line_width, cairo_set_line_width, 
    void, KairoContext*, cairo_t*, double, double)
WRAP1(kairo_context_get_line_width, cairo_get_line_width, 
    double, KairoContext*, cairo_t*)

WRAP2(kairo_context_set_miter_limit, cairo_set_miter_limit, 
    void, KairoContext*, cairo_t*, double, double)
WRAP1(kairo_context_get_miter_limit, cairo_get_miter_limit, 
    double, KairoContext*, cairo_t*)
    
WRAP2(kairo_context_set_operator, cairo_set_operator, 
    void, KairoContext*, cairo_t*, KairoOperator, cairo_operator_t)
WRAP1(kairo_context_get_operator, cairo_get_operator, 
    KairoOperator, KairoContext*, cairo_t*)
    
WRAP1(kairo_context_paint, cairo_paint, 
    void, KairoContext*, cairo_t*)
WRAP1(kairo_context_fill, cairo_fill, 
    void, KairoContext*, cairo_t*)
WRAP1(kairo_context_stroke, cairo_stroke, 
    void, KairoContext*, cairo_t*)
    
/* Path */
WRAP6(kairo_context_arc, cairo_arc, 
    void, KairoContext*, cairo_t*, double, double, double, double,
    double, double, double, double, double, double)
WRAP3(kairo_context_line_to, cairo_line_to, 
    void, KairoContext*, cairo_t*, double, double, double, double)

