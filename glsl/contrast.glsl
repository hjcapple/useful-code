vec3 contrast(vec3 color, float contrast) {
	return (color - vec3(0.5)) * contrast + vec3(0.5);
}

// shadertoy test
void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    vec2 uv = fragCoord/iResolution.xy;
    vec4 color = texture(iChannel0, uv);
    color.rgb = contrast(color.rgb, 2.0);
    fragColor = color;
}
