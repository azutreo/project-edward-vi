#version 330 core

layout(location = 0) out vec4 color;

in vec3 v_Position;
in vec4 v_Color;

uniform mat4 u_ViewProjection;

void main() {
	color = v_Color;
}