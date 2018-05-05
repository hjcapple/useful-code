vec3 gramma(vec3 color, float gramma, float c) {
    vec3 result;
    result.r = pow(color.r, gramma) * c;
    result.g = pow(color.g, gramma) * c;
    result.b = pow(color.b, gramma) * c;
    return result;
}

// shadertoy test
void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    vec2 uv = fragCoord/iResolution.xy;
    vec4 color = texture(iChannel0, uv);
    color.rgb = gramma(color.rgb, 2.5, 1.0);
    fragColor = color;
}