#shader vertex
#version 330 core

//layout (location = 0) in vec4 position;
//layout (location = 1) in vec2 texCoord;

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoords;

out vec2 v_TexCoord;

uniform mat4 u_MVP;

void main()
{
	v_TexCoord = aTexCoords;
	gl_Position = u_MVP * vec4(aPos, 1.0);
};

#shader fragment
#version 330 core

//layout (location = 0) out vec4 color;

out vec4 FragColor;

in vec2 v_TexCoord;

uniform sampler2D texture_diffuse1;

void main()
{
	FragColor = texture(texture_diffuse1, v_TexCoord);
	//vec4 texColor = vec4(v_TexCoord.x, v_TexCoord.y, 0.0f, 1.0f);
	//color = texColor;
};