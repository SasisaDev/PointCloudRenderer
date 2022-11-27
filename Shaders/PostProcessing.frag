#version 330
uniform sampler2D fbo_texture;
in vec2 f_texcoord;

void main(void) {
  gl_FragColor = texture2D(fbo_texture, f_texcoord);
}