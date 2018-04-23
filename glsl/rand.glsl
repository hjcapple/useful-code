// https://stackoverflow.com/questions/4200224/random-noise-functions-for-glsl

float rand(vec2 co) {
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453123);
}

float rand2(float n) {
    return fract(sin(n) * 43758.5453123);
}

// shadertoy test
void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    // Normalized pixel coordinates (from 0 to 1)
    vec2 uv = fragCoord/iResolution.xy;
    float r = rand(uv);
    fragColor = vec4(r, r, r, 1.0);
}
