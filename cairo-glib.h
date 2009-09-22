#include <cairo.h>
#include <glib-object.h>

GType kairo_surface_get_type (void);
GType kairo_image_surface_get_type (void);
GType kairo_context_get_type (void);

typedef struct cairo_t KairoContext;
typedef struct cairo_surface_t KairoSurface;
typedef struct kairo_context_image_surface_t KairoImageSurface;
typedef struct kairo_context_pattern_t KairoPattern;

KairoSurface* kairo_image_surface_get_surface (KairoImageSurface *image_surface);

typedef enum {
    KAIRO_STATUS_SUCCESS = 0,
    KAIRO_STATUS_NO_MEMORY,
    KAIRO_STATUS_INVALID_RESTORE,
    KAIRO_STATUS_INVALID_POP_GROUP,
    KAIRO_STATUS_NO_CURRENT_POINT,
    KAIRO_STATUS_INVALID_MATRIX,
    KAIRO_STATUS_INVALID_STATUS,
    KAIRO_STATUS_NULL_POINTER,
    KAIRO_STATUS_INVALID_STRING,
    KAIRO_STATUS_INVALID_PATH_DATA,
    KAIRO_STATUS_READ_ERROR,
    KAIRO_STATUS_WRITE_ERROR,
    KAIRO_STATUS_SURFACE_FINISHED,
    KAIRO_STATUS_SURFACE_TYPE_MISMATCH,
    KAIRO_STATUS_PATTERN_TYPE_MISMATCH,
    KAIRO_STATUS_INVALID_CONTENT,
    KAIRO_STATUS_INVALID_FORMAT,
    KAIRO_STATUS_INVALID_VISUAL,
    KAIRO_STATUS_FILE_NOT_FOUND,
    KAIRO_STATUS_INVALID_DASH,
    KAIRO_STATUS_INVALID_DSC_COMMENT,
    KAIRO_STATUS_INVALID_INDEX,
    KAIRO_STATUS_CLIP_NOT_REPRESENTABLE,
    KAIRO_STATUS_TEMP_FILE_ERROR,
    KAIRO_STATUS_INVALID_STRIDE,
    KAIRO_STATUS_FONT_TYPE_MISMATCH,
    KAIRO_STATUS_USER_FONT_IMMUTABLE,
    KAIRO_STATUS_USER_FONT_ERROR,
    KAIRO_STATUS_NEGATIVE_COUNT,
    KAIRO_STATUS_INVALID_CLUSTERS,
    KAIRO_STATUS_INVALID_SLANT,
    KAIRO_STATUS_INVALID_WEIGHT
} KairoStatus;

typedef enum {
    KAIRO_CONTENT_COLOR		= 0x1000,
    KAIRO_CONTENT_ALPHA		= 0x2000,
    KAIRO_CONTENT_COLOR_ALPHA	= 0x3000
} KairoContent;

typedef enum {
    KAIRO_SURFACE_TYPE_IMAGE,
    KAIRO_SURFACE_TYPE_PDF,
    KAIRO_SURFACE_TYPE_PS,
    KAIRO_SURFACE_TYPE_XLIB,
    KAIRO_SURFACE_TYPE_XCB,
    KAIRO_SURFACE_TYPE_GLITZ,
    KAIRO_SURFACE_TYPE_QUARTZ,
    KAIRO_SURFACE_TYPE_WIN32,
    KAIRO_SURFACE_TYPE_BEOS,
    KAIRO_SURFACE_TYPE_DIRECTFB,
    KAIRO_SURFACE_TYPE_SVG,
    KAIRO_SURFACE_TYPE_OS2,
    KAIRO_SURFACE_TYPE_WIN32_PRINTING,
    KAIRO_SURFACE_TYPE_QUARTZ_IMAGE
} KairoSurfaceType;

typedef enum {
    KAIRO_FORMAT_ARGB32,
    KAIRO_FORMAT_RGB24,
    KAIRO_FORMAT_A8,
    KAIRO_FORMAT_A1
} KairoFormat;

typedef enum {
    KAIRO_OPERATOR_CLEAR,

    KAIRO_OPERATOR_SOURCE,
    KAIRO_OPERATOR_OVER,
    KAIRO_OPERATOR_IN,
    KAIRO_OPERATOR_OUT,
    KAIRO_OPERATOR_ATOP,

    KAIRO_OPERATOR_DEST,
    KAIRO_OPERATOR_DEST_OVER,
    KAIRO_OPERATOR_DEST_IN,
    KAIRO_OPERATOR_DEST_OUT,
    KAIRO_OPERATOR_DEST_ATOP,

    KAIRO_OPERATOR_XOR,
    KAIRO_OPERATOR_ADD,
    KAIRO_OPERATOR_SATURATE
} KairoOperator;

typedef enum {
    KAIRO_ANTIALIAS_DEFAULT,
    KAIRO_ANTIALIAS_NONE,
    KAIRO_ANTIALIAS_GRAY,
    KAIRO_ANTIALIAS_SUBPIXEL
} KairoAntiAlias;

typedef enum {
    KAIRO_FILL_RULE_WINDING,
    KAIRO_FILL_RULE_EVEN_ODD
} KairoFillRule;


typedef enum {
    KAIRO_LINE_CAP_BUTT,
    KAIRO_LINE_CAP_ROUND,
    KAIRO_LINE_CAP_SQUARE
} KairoLineCap;

typedef enum {
    KAIRO_LINE_JOIN_MITER,
    KAIRO_LINE_JOIN_ROUND,
    KAIRO_LINE_JOIN_BEVEL
} KairoLineJoin;

/* Surface */
KairoSurfaceType kairo_surface_get_surface_type (KairoSurface *surface);
KairoStatus kairo_surface_get_status (KairoSurface *surface);
KairoStatus kairo_surface_write_to_png (KairoSurface *surface,
                                        const char *filename);

/* ImageSurface */
KairoImageSurface* kairo_image_surface_create (KairoFormat format, int width, int height);
int kairo_image_surface_get_height (KairoImageSurface *image_surface);
int kairo_image_surface_get_width (KairoImageSurface *image_surface);

/* Context */
KairoContext* kairo_context_create (KairoSurface *target);
KairoStatus kairo_context_get_status (KairoContext *context);
void kairo_context_set_surface (KairoContext *context, KairoSurface *surface, double x, double y);

void             kairo_context_save                          (KairoContext *cr);
void             kairo_context_restore                       (KairoContext *cr);
KairoSurface *   kairo_context_get_target                    (KairoContext *cr);
void             kairo_context_push_group                    (KairoContext *cr);
void             kairo_context_push_group_with_content       (KairoContext *cr,
                                                              KairoContent content);
KairoPattern *   kairo_context_pop_group                     (KairoContext *cr);
void             kairo_context_pop_group_to_source           (KairoContext *cr);
KairoSurface *   kairo_context_get_group_target              (KairoContext *cr);
void             kairo_context_set_source_rgb                (KairoContext *cr,
                                                              double red,
                                                              double green,
                                                              double blue);
void             kairo_context_set_source_rgba               (KairoContext *cr,
                                                              double red,
                                                              double green,
                                                              double blue,
                                                              double alpha);
void             kairo_context_set_source                    (KairoContext *cr,
                                                              KairoPattern *source);
void             kairo_context_set_source_surface            (KairoContext *cr,
                                                              KairoSurface *surface,
                                                              double x,
                                                              double y);
KairoPattern *   kairo_context_get_source                    (KairoContext *cr);
void             kairo_context_set_antialias                 (KairoContext *cr,
                                                              KairoAntiAlias antialias);
KairoAntiAlias   kairo_context_get_antialias                 (KairoContext *cr);
void             kairo_context_set_dash                      (KairoContext *cr,
                                                              const double *dashes,
                                                              int num_dashes,
                                                              double offset);
int              kairo_context_get_dash_count                (KairoContext *cr);
void             kairo_context_get_dash                      (KairoContext *cr,
                                                              double *dashes,
                                                              double *offset);
void             kairo_context_set_fill_rule                 (KairoContext *cr,
                                                              KairoFillRule  fill_rule);
KairoFillRule    kairo_context_get_fill_rule                 (KairoContext *cr);
void             kairo_context_set_line_cap                  (KairoContext *cr,
                                                              KairoLineCap line_cap);
KairoLineCap     kairo_context_get_line_cap                  (KairoContext *cr);
void             kairo_context_set_line_join                 (KairoContext *cr,
                                                              KairoLineJoin  line_join);
KairoLineJoin    kairo_context_get_line_join                 (KairoContext *cr);
void             kairo_context_set_line_width                (KairoContext *cr,
                                                              double width);
double           kairo_context_get_line_width                (KairoContext *cr);
void             kairo_context_set_miter_limit               (KairoContext *cr,
                                                              double limit);
double           kairo_context_get_miter_limit               (KairoContext *cr);
void             kairo_context_set_operator                  (KairoContext *cr,
                                                              KairoOperator  op);
KairoOperator    kairo_context_get_operator                  (KairoContext *cr);
void             kairo_context_set_tolerance                 (KairoContext *cr,
                                                              double tolerance);
double           kairo_context_get_tolerance                 (KairoContext *cr);
void             kairo_context_clip                          (KairoContext *cr);
void             kairo_context_clip_preserve                 (KairoContext *cr);
void             kairo_context_clip_extents                  (KairoContext *cr,
                                                              double *x1,
                                                              double *y1,
                                                              double *x2,
                                                              double *y2);
void             kairo_context_reset_clip                    (KairoContext *cr);

#if 0
void             kairo_context_rectangle_list_destroy        (KairoRectangleList* rectangle_list);
KairoRectangleList* kairo_context_copy_clip_rectangle_list   (KairoContext *cr);
#endif
void             kairo_context_fill                          (KairoContext *cr);
void             kairo_context_fill_preserve                 (KairoContext *cr);
void             kairo_context_fill_extents                  (KairoContext *cr,
                                                              double *x1,
                                                              double *y1,
                                                              double *x2,
                                                              double *y2);
gboolean         kairo_context_in_fill                       (KairoContext *cr,
                                                              double x,
                                                              double y);
void             kairo_context_mask                          (KairoContext *cr,
                                                              KairoPattern *pattern);
void             kairo_context_mask_surface                  (KairoContext *cr,
                                                              KairoSurface *surface,
                                                              double surface_x,
                                                              double surface_y);
void             kairo_context_paint                         (KairoContext *cr);
void             kairo_context_paint_with_alpha              (KairoContext *cr,
                                                              double alpha);
void             kairo_context_stroke                        (KairoContext *cr);
void             kairo_context_stroke_preserve               (KairoContext *cr);
void             kairo_context_stroke_extents                (KairoContext *cr,
                                                              double *x1,
                                                              double *y1,
                                                              double *x2,
                                                              double *y2);
gboolean         kairo_context_in_stroke                     (KairoContext *cr,
                                                              double x,
                                                              double y);
void             kairo_context_copy_page                     (KairoContext *cr);
void             kairo_context_show_page                     (KairoContext *cr);
unsigned int     kairo_context_get_reference_count           (KairoContext *cr);
#if 0
kairo_context_status_t      kairo_context_set_user_data     (KairoContext *cr,
                                                         const kairo_context_user_data_key_t *key,
                                                         void *user_data,
                                                         kairo_context_destroy_func_t destroy);
void *              kairo_context_get_user_data          (KairoContext *cr,
                                                         const kairo_context_user_data_key_t *key);
#endif

/* Path */
#if 0
GList * context_copy_path (KairoContext *cr);

cairo_path_t *      cairo_copy_path                     (KairoContext *cr);
cairo_path_t *      cairo_copy_path_flat                (KairoContext *cr);
void                cairo_path_destroy                  (cairo_path_t *path);
void                cairo_append_path                   (KairoContext *cr,
                                                         const cairo_path_t *path);
#endif

gboolean            kairo_context_has_current_point     (KairoContext *cr);
void                kairo_context_get_current_point     (KairoContext *cr,
                                                         double *x,
                                                         double *y);
void                kairo_context_new_path              (KairoContext *cr);
void                kairo_context_new_sub_path          (KairoContext *cr);
void                kairo_context_close_path            (KairoContext *cr);
void                kairo_context_arc                   (KairoContext *cr,
                                                         double xc,
                                                         double yc,
                                                         double radius,
                                                         double angle1,
                                                         double angle2);
void                kairo_context_arc_negative          (KairoContext *cr,
                                                         double xc,
                                                         double yc,
                                                         double radius,
                                                         double angle1,
                                                         double angle2);
void                kairo_context_curve_to              (KairoContext *cr,
                                                         double x1,
                                                         double y1,
                                                         double x2,
                                                         double y2,
                                                         double x3,
                                                         double y3);
void                kairo_context_line_to               (KairoContext *cr,
                                                         double x,
                                                         double y);
void                kairo_context_move_to               (KairoContext *cr,
                                                         double x,
                                                         double y);
void                kairo_context_rectangle             (KairoContext *cr,
                                                         double x,
                                                         double y,
                                                         double width,
                                                         double height);
#if 0
void                kairo_context_glyph_path            (KairoContext *cr,
                                                         const kairo_context_glyph_t *glyphs,
                                                         int num_glyphs);
#endif
void                kairo_context_text_path             (KairoContext *cr,
                                                         const char *utf8);
void                kairo_context_rel_curve_to          (KairoContext *cr,
                                                         double dx1,
                                                         double dy1,
                                                         double dx2,
                                                         double dy2,
                                                         double dx3,
                                                         double dy3);
void                kairo_context_rel_line_to           (KairoContext *cr,
                                                         double dx,
                                                         double dy);
void                kairo_context_rel_move_to           (KairoContext *cr,
                                                         double dx,
                                                         double dy);
void                kairo_context_path_extents          (KairoContext *cr,
                                                         double *x1,
                                                         double *y1,
                                                         double *x2,
                                                         double *y2);                                                         
                                                         
