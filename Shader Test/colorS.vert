#version 130 // version del lenguaje de GLSL
in vec2 vertexPos;

void main(){
	
	gl_Position.xy = vertexPos;	//donde esta el vertex.  gl_position es un vec4
	gl_Position.z = 0;
	gl_Position.w = 1;
}