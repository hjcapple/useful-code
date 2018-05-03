mat2 rotate2(float rad) {
	float s = sin(rad);
	float c = cos(rad);
	return mat2(
        c, -s,
        s, c
    );
}

mat3 rotate3x(float rad) {
    float c = cos(rad);
    float s = sin(rad);
    return mat3(
        1.0, 0.0, 0.0,
        0.0, c, s,
        0.0, -s, c
   );
}

mat3 rotate3y(float rad) {
    float c = cos(rad);
    float s = sin(rad);
    return mat3(
        c, 0.0, -s,
        0.0, 1.0, 0.0,
        s, 0.0, c
    );
}

mat3 rotate3z(float rad) {
    float c = cos(rad);
    float s = sin(rad);
    return mat3(
        c, s, 0.0,
        -s, c, 0.0,
        0.0, 0.0, 1.0
    );
}

mat3 translate3(float x, float y) {
    mat3 m = mat3(1.0);
    m[2][0] = x;
    m[2][1] = y;
    return m;
}


// shadertoy test
void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    vec2 uv = fragCoord / iResolution.xy;
    
    float angle = 3.1215926 * iTime * 0.1;
    float cx = 0.5;
    float cy = 0.5;
    mat3 m = translate3(cx, cy);
    m *= rotate3z(angle);
    m *= translate3(-cx, -cy);
    
    uv = (m * vec3(uv, 1.0)).xy;
    
    fragColor = texture(iChannel0, uv);
}


