// http://gamedev.stackexchange.com/questions/59797/glsl-shader-change-hue-saturation-brightness
// hsv range is [0, 1]
// rgb ragne is [0, 1]

vec3 rgb2hsv(vec3 c)
{
    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz), vec4(c.gb, K.xy), step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r), vec4(c.r, p.yzx), step(p.x, c.r));

    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)), d / (q.x + e), q.x);
}

vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

// shadertoy test
void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    vec2 uv = fragCoord/iResolution.xy;
    vec4 rgba = texture(iChannel0, uv);
    vec3 hsv = rgb2hsv(rgba.rgb);
    hsv.r = 0.6;  					// change h
    hsv.g = clamp(hsv.g, 0.4, 0.6);	// change s
   	
    rgba.rgb = hsv2rgb(hsv);
    fragColor = rgba;
}