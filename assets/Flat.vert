#version 330

in vec4 ciPosition;
in vec3 ciNormal;

uniform mat4 ciModelView;
uniform mat3 ciNormalMatrix;
uniform mat4 ciModelViewProjection;


uniform float ciElapsedSeconds;


out vec3 vNormal;
out vec4 vPosition;


void main(){
    
    
    vPosition = ciModelView * ciPosition;
    vNormal = ciNormalMatrix * ciNormal;
    
    vec4 pos = ciPosition;
    pos.x = sin(ciElapsedSeconds);
    
    //gl_Position = ciModelViewProjection * ciPosition;
    gl_Position = ciModelViewProjection * pos;
    
    
}