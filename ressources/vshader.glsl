#version 130

uniform mat4 mvp; // model view * projection

in vec3 position;
in vec3 color;

out vec3 fColor;

//! [0]
void main()
{
    // Calculate vertex final position in screen space
    gl_Position = mvp * vec4( position, 1.0 );

    // send color to fragment shader
    fColor = color;
}
//! [0]
