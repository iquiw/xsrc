"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"__fixed_input vec4 gl_FragCoord;\n"
"__fixed_input bool gl_FrontFacing;\n"
"__fixed_output vec4 gl_FragColor;\n"
"__fixed_output vec4 gl_FragData[gl_MaxDrawBuffers];\n"
"__fixed_output float gl_FragDepth;\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"varying vec4 gl_Color;\n"
"varying vec4 gl_SecondaryColor;\n"
"varying vec4 gl_TexCoord[];\n"
"varying float gl_FogFragCoord;\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"vec4 texture1D (sampler1D sampler, float coord, float bias) {\n"
"    return vec4 (0.0);\n"
"}\n"
"vec4 texture1DProj (sampler1D sampler, vec2 coord, float bias) {\n"
"    return texture1D (sampler, coord.s / coord.t, bias);\n"
"}\n"
"vec4 texture1DProj (sampler1D sampler, vec4 coord, float bias) {\n"
"    return texture1D (sampler, coord.s / coord.q, bias);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"vec4 texture2D (sampler2D sampler, vec2 coord, float bias) {\n"
"    return vec4 (0.0);\n"
"}\n"
"vec4 texture2DProj (sampler2D sampler, vec3 coord, float bias) {\n"
"    return texture2D (sampler, vec2 (coord.s / coord.p, coord.t / coord.p), bias);\n"
"}\n"
"vec4 texture2DProj (sampler2D sampler, vec4 coord, float bias) {\n"
"    return texture2D (sampler, vec2 (coord.s / coord.q, coord.s / coord.q), bias);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"vec4 texture3D (sampler3D sampler, vec3 coord, float bias) {\n"
"    return vec4 (0.0);\n"
"}\n"
"vec4 texture3DProj (sampler3D sampler, vec4 coord, float bias) {\n"
"    return texture3DProj (sampler, vec3 (coord.s / coord.q, coord.t / coord.q, coord.p / coord.q),\n"
"        bias);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"vec4 textureCube (samplerCube sampler, vec3 coord, float bias) {\n"
"    return vec4 (0.0);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"vec4 shadow1D (sampler1DShadow sampler, vec3 coord, float bias) {\n"
"    return vec4 (0.0);\n"
"}\n"
"\n"
"vec4 shadow2D (sampler2DShadow sampler, vec3 coord, float bias) {\n"
"    return vec4 (0.0);\n"
"}\n"
"vec4 shadow1DProj (sampler1DShadow sampler, vec4 coord, float bias) {\n"
"    return shadow1D (sampler, vec3 (coord.s / coord.q, 0.0, coord.p / coord.q), bias);\n"
"}\n"
"vec4 shadow2DProj (sampler2DShadow sampler, vec4 coord, float bias) {\n"
"    return shadow2D (sampler, vec3 (coord.s / coord.q, coord.t / coord.q, coord.p / coord.q), bias);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"float dFdx (float p) {\n"
"    return 0.0;\n"
"}\n"
"\n"
"vec2 dFdx (vec2 p) {\n"
"    return vec2 (0.0);\n"
"}\n"
"\n"
"vec3 dFdx (vec3 p) {\n"
"    return vec3 (0.0);\n"
"}\n"
"\n"
"vec4 dFdx (vec4 p) {\n"
"    return vec4 (0.0);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"float dFdy (float p) {\n"
"    return 0.0;\n"
"}\n"
"\n"
"vec2 dFdy (vec2 p) {\n"
"    return vec2 (0.0);\n"
"}\n"
"\n"
"vec3 dFdy (vec3 p) {\n"
"    return vec3 (0.0);\n"
"}\n"
"\n"
"vec4 dFdy (vec4 p) {\n"
"    return vec4 (0.0);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"float fwidth (float p) {\n"
"    return abs (dFdx (p)) + abs (dFdy (p));\n"
"}\n"
"vec2 fwidth (vec2 p) {\n"
"    return abs (dFdx (p)) + abs (dFdy (p));\n"
"}\n"
"vec3 fwidth (vec3 p) {\n"
"    return abs (dFdx (p)) + abs (dFdy (p));\n"
"}\n"
"vec4 fwidth (vec4 p) {\n"
"    return abs (dFdx (p)) + abs (dFdy (p));\n"
"}\n"
"\n"
