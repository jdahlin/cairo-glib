const Cairo = imports.gi.cairo;
const Clutter = imports.gi.Clutter;

Clutter.init(0, null);

let stage = Clutter.Stage.get_default();

let texture = new Clutter.CairoTexture({surface_width: 500, surface_height: 500});
stage.add_actor(texture);

let cr = texture.create();
if (cr.status() != 0) {
   throw Error(cr.status());
}
cr.translate(130, 30);
let matrix = new Cairo.Matrix();
matrix.init(1.0, 0.5, 0.0, 1.0, 0.0, 0.0);
cr.transform(matrix);
cr.set_line_width(10.0);
cr.set_source_rgba(1, 0.2, 0.2, 0.6);
cr.arc(128, 128, 100, 45*(Math.PI/180.0), 180*(Math.PI/180.0));
cr.fill();

cr.destroy();

stage.show_all();

Clutter.main();
