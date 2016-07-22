/*************************************************************************
** GLSL.io Transition License (v1): 
** The MIT License (MIT)
**
** Copyright (C) 2014 contact@glsl.io
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
** THE SOFTWARE.
*************************************************************************/

#ifdef GL_ES
    precision highp float;
#endif

uniform sampler2D from;
uniform sampler2D to;
uniform float progress;
uniform vec2 resolution;

uniform float smoothness;
uniform bool opening;

const vec2 center = vec2(0.5, 0.5);
const float SQRT_2 = 1.414213562373;

void main()
{
    vec2 p = gl_FragCoord.xy / resolution.xy;
    float x = opening ? progress : 1.-progress;
    float m = smoothstep
    (
        -smoothness, 0.0, SQRT_2*distance(center, p) - x*(1.+smoothness)
    );
    gl_FragColor = mix
    (
        texture2D(from, p), texture2D(to, p), opening ? 1.-m : m
    );
}
