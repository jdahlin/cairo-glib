# All enum members should go into our namespace

s/CAIRO_/CAIRO_GLIB_/g

# But do not rename CAIRO_HAS_FEATURE_* macros

s/CAIRO_GLIB_HAS_/CAIRO_HAS_/g

# Rename enums

s/cairo_anti_alias_t/CairoGlibAntiAlias/g
s/cairo_content_t/CairoGlibContent/g
s/cairo_fill_rule_t/CairoGlibFillRule/g
s/cairo_font_t/CairoGlibFont/g
s/cairo_format_t/CairoGlibFormat/g
s/cairo_line_cap_t/CairoGlibLineCap/g
s/cairo_line_join_t/CairoGlibLineJoin/g
s/cairo_operator_t/CairoGlibOperator/g
s/cairo_status_t/CairoGlibStatus/g

# Cairo Pattern
s/cairo_pattern_t/CairoGlibPattern/g
s/cairo_pattern_/cairo_glib_pattern_/g

# Cairo Context
s/cairo_t/CairoGlibContext/g
s/cairo_create/cairo_glib_context_create/g
s/cairo_reference/cairo_glib_context_reference/g
s/cairo_destroy/cairo_glib_context_destroy/g
s/cairo_status/cairo_glib_context_status/g
s/cairo_save/cairo_glib_context_save/g
s/cairo_restore/cairo_glib_context_restore/g
s/cairo_get_target/cairo_glib_context_get_target/g
s/cairo_push_group/cairo_glib_context_push_group/g
s/cairo_push_group_with_content/cairo_glib_context_push_group_with_content/g
s/cairo_pop_group/cairo_glib_context_pop_group/g
s/cairo_pop_group_to_source/cairo_glib_context_pop_group_to_source/g
s/cairo_get_group_target/cairo_glib_context_get_group_target/g
s/cairo_set_source_rgb/cairo_glib_context_set_source_rgb/g
s/cairo_set_source_rgba/cairo_glib_context_set_source_rgba/g
s/cairo_set_source/cairo_glib_context_set_source/g
s/cairo_set_source_surface/cairo_glib_context_set_source_surface/g
s/cairo_get_source/cairo_glib_context_get_source/g
s/cairo_set_antialias/cairo_glib_context_set_antialias/g
s/cairo_get_antialias/cairo_glib_context_get_antialias/g
s/cairo_set_dash/cairo_glib_context_set_dash/g
s/cairo_get_dash_count/cairo_glib_context_get_dash_count/g
s/cairo_get_dash/cairo_glib_context_get_dash/g
s/cairo_set_fill_rule/cairo_glib_context_set_fill_rule/g
s/cairo_get_fill_rule/cairo_glib_context_get_fill_rule/g
s/cairo_set_line_cap/cairo_glib_context_set_line_cap/g
s/cairo_get_line_cap/cairo_glib_context_get_line_cap/g
s/cairo_set_line_join/cairo_glib_context_set_line_join/g
s/cairo_get_line_join/cairo_glib_context_get_line_join/g
s/cairo_set_line_width/cairo_glib_context_set_line_width/g
s/cairo_get_line_width/cairo_glib_context_get_line_width/g
s/cairo_set_miter_limit/cairo_glib_context_set_miter_limit/g
s/cairo_get_miter_limit/cairo_glib_context_get_miter_limit/g
s/cairo_set_operator/cairo_glib_context_set_operator/g
s/cairo_get_operator/cairo_glib_context_get_operator/g
s/cairo_set_tolerance/cairo_glib_context_set_tolerance/g
s/cairo_get_tolerance/cairo_glib_context_get_tolerance/g
s/cairo_clip/cairo_glib_context_clip/g
s/cairo_clip_preserve/cairo_glib_context_clip_preserve/g
s/cairo_clip_extents/cairo_glib_context_clip_extents/g
s/cairo_reset_clip/cairo_glib_context_reset_clip/g
s/cairo_rectangle_list_destroy/cairo_glib_context_rectangle_list_destroy/g
s/cairo_copy_clip_rectangle_list/cairo_glib_context_copy_clip_rectangle_list/g
s/cairo_fill/cairo_glib_context_fill/g
s/cairo_fill_preserve/cairo_glib_context_fill_preserve/g
s/cairo_fill_extents/cairo_glib_context_fill_extents/g
s/cairo_in_fill/cairo_glib_context_in_fill/g
s/cairo_mask/cairo_glib_context_mask/g
s/cairo_mask_surface/cairo_glib_context_mask_surface/g
s/cairo_paint/cairo_glib_context_paint/g
s/cairo_paint_with_alpha/cairo_glib_context_paint_with_alpha/g
s/cairo_stroke/cairo_glib_context_stroke/g
s/cairo_stroke_preserve/cairo_glib_context_stroke_preserve/g
s/cairo_stroke_extents/cairo_glib_context_stroke_extents/g
s/cairo_in_stroke/cairo_glib_context_in_stroke/g
s/cairo_copy_page/cairo_glib_context_copy_page/g
s/cairo_show_page/cairo_glib_context_show_page/g
s/cairo_get_reference_count/cairo_glib_context_get_reference_count/g
s/cairo_set_user_data/cairo_glib_context_set_user_data/g
s/cairo_get_user_data/cairo_glib_context_get_user_data/g
s/cairo_translate/cairo_glib_context_translate/g
s/cairo_scale/cairo_glib_context_scale/g
s/cairo_rotate/cairo_glib_context_rotate/g
s/cairo_transform/cairo_glib_context_transform/g
s/cairo_set_matrix/cairo_glib_context_set_matrix/g
s/cairo_get_matrix/cairo_glib_context_get_matrix/g
s/cairo_identity_matrix/cairo_glib_context_identity_matrix/g
s/cairo_user_to_device/cairo_glib_context_user_to_device/g
s/cairo_user_to_device_distance/cairo_glib_context_user_to_device_distance/g
s/cairo_device_to_user/cairo_glib_context_device_to_user/g
s/cairo_device_to_user_distance/cairo_glib_context_device_to_user_distance/g
s/cairo_copy_path/cairo_glib_context_copy_path/g
s/cairo_copy_path_flat/cairo_glib_context_copy_path_flat/g
s/cairo_path_destroy/cairo_glib_context_path_destroy/g
s/cairo_append_path/cairo_glib_context_append_path/g
s/cairo_has_current_point/cairo_glib_context_has_current_point/g
s/cairo_get_current_point/cairo_glib_context_get_current_point/g
s/cairo_new_path/cairo_glib_context_new_path/g
s/cairo_new_sub_path/cairo_glib_context_new_sub_path/g
s/cairo_close_path/cairo_glib_context_close_path/g
s/cairo_arc/cairo_glib_context_arc/g
s/cairo_arc_negative/cairo_glib_context_arc_negative/g
s/cairo_curve_to/cairo_glib_context_curve_to/g
s/cairo_line_to/cairo_glib_context_line_to/g
s/cairo_move_to/cairo_glib_context_move_to/g
s/cairo_rectangle/cairo_glib_context_rectangle/g
s/cairo_glyph_path/cairo_glib_context_glyph_path/g
s/cairo_text_path/cairo_glib_context_text_path/g
s/cairo_rel_curve_to/cairo_glib_context_rel_curve_to/g
s/cairo_rel_line_to/cairo_glib_context_rel_line_to/g
s/cairo_rel_move_to/cairo_glib_context_rel_move_to/g
s/cairo_path_extents/cairo_glib_context_path_extents/g

# Image Surface
s/cairo_image_surface_t/CairoGlibImageSurface/g
s/cairo_image_surface_create/_cairo_image_surface_create/g
s/cairo_image_surface/cairo_glib_image_surface/g

# Surface
s/cairo_surface_t/CairoGlibSurface/g
s/cairo_surface/cairo_glib_surface/g

# Matrix
s/cairo_matrix_t/CairoGlibMatrix/g
s/cairo_matrix_/cairo_glib_matrix_/g

# FontFace
s/cairo_font_face_t/CairoGlibFontFace/g
s/cairo_font_face_/cairo_glib_font_face_/g

# ScaledFace
s/cairo_scaled_font_t/CairoGlibScaledFont/g
s/cairo_scaled_font_/cairo_glib_scaled_font_/g

# FontOptions
s/cairo_font_options_t/CairoGlibFontOptions/g
s/cairo_font_options_/cairo_glib_font_options_/g

# Path
s/cairo_path_t/CairoGlibPath/g


