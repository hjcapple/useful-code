#define texture2D texture

vec4 colordrift(sampler2D tex, vec2 uv, vec2 offset)
{
    vec4 src1 = texture2D(tex, uv);
    vec4 src2 = texture2D(tex, uv + offset);
    return vec4(src1.r, src2.g, src1.b, src1.a);
}

// shadertoy test
void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    vec2 uv = fragCoord/iResolution.xy;
    fragColor = colordrift(iChannel0, uv, vec2(0.01, 0.0));
}