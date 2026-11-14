uniform sampler2D texture;
uniform float maxDist;
uniform float posZ;
uniform float screenH;
uniform bool  torchOn;
uniform float torchRange;

void main()
{
    vec2 uv = gl_TexCoord[0].xy;
    vec4 col = texture2D(texture, uv);
    float horizon = screenH * 0.5;

    if (gl_FragCoord.y < horizon) {
        float p = horizon - gl_FragCoord.y;
        float rowDist = posZ / p;
        float dNorm = clamp(rowDist / maxDist, 0.3, 1.0);
        float fog = dNorm;
        if (torchOn) {
            fog = clamp((rowDist - torchRange) / (maxDist - torchRange), 0.0, 0.9);
        }
        col = mix(col, vec4(0.0,0.0,0.0,col.a), fog);
    }
    gl_FragColor = col;
}
