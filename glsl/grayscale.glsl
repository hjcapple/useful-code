vec4 grayscale(vec4 color) {
    vec3 scale = vec3(0.299, 0.587, 0.114);
    float gray = dot(color.rgb, scale);
    return vec4(gray, gray, gray, color.a);
}

// shadertoy test
void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    vec2 uv = fragCoord/iResolution.xy;
    vec4 color = texture(iChannel0, uv);
    fragColor = grayscale(color);
}
