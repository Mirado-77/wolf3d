uniform sampler2D texture;
uniform float distance;
uniform float maxDist;
uniform bool torchOn;
uniform float torchRange;

void main()
{
    vec2 uv = gl_TexCoord[0].xy;
    vec4 col = texture2D(texture, uv);

    float dNorm = clamp(distance / maxDist, 0.2, 1.0);
    float fog = dNorm;

    if (torchOn) {
        fog = clamp((distance - torchRange) / (maxDist - torchRange), 0.0, 0.9);
    }
    gl_FragColor = mix(col, vec4(0.0,0.0,0.0,col.a), fog);
}
