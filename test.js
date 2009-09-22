const Cairo = imports.gi.CairoGLib;
let imageSurface = Cairo.image_surface_create(Cairo.Format.RGB24, 1000, 1000);
let surface = imageSurface.get_surface();

let xc = 128.0;
let yc = 128.0;
let radius = 100.0;
let angle1 = 45.0  * (Math.PI/180.0);
let angle2 = 180.0 * (Math.PI/180.0);

let cr = Cairo.context_create(surface);

cr.set_line_width(10.0);
cr.arc(xc, yc, radius, angle1, angle2);
cr.stroke();

cr.set_source_rgba(1, 0.2, 0.2, 0.6);
cr.set_line_width(6.0);

cr.arc(xc, yc, 10.0, 0, 2.0*Math.PI);
cr.fill(cr);

cr.arc(xc, yc, radius, angle1, angle1);
cr.line_to(xc, yc);
cr.arc(xc, yc, radius, angle2, angle2);
cr.line_to(xc, yc);
cr.stroke(cr);
cr.paint();

surface.write_to_png("test.png");
