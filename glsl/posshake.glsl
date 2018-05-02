#define texture2D texture

vec4 pos_shake(sampler2D tex, vec2 uv, vec2 offset)
{
    vec2 pos = fract(uv + offset);
    return texture2D(tex, pos);
}

float rand2(float n) {
    return fract(sin(n) * 43758.5453123);
}

// shadertoy test
void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    vec2 uv = fragCoord/iResolution.xy;
    float offsetX = (rand2(iTime) - 0.5) * 0.01;
    fragColor = pos_shake(iChannel0, uv, vec2(offsetX, 0.0));
}